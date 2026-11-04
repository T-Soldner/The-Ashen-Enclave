"""Discord attendance/application bot. Writes and live promotions require explicit flags."""
import argparse
import asyncio
import datetime as dt
import getpass
import io
import os
import re
from pathlib import Path
import sqlite3
import threading

from discord_store import Store, authorize
import loa
import absence
import promotions
import finalization
from discord_transport import Transport
import applications
import application_ui
import sheets_sync
import membership
import onboarding
import clan_tracker
import personnel_ui
import clan_training as personnel_policy
import link_queue_ui


def arrange_commands(app_commands, public, staff):
    """Move existing handlers, preserving their checks, callbacks and parameters."""
    maintenance = type(public)(name="tae-maintenance", description="Recovery and setup tools; each command retains its staff permission checks", guild_only=True)
    links = app_commands.Group(name="links", description="Manual account-link recovery")
    sheets = app_commands.Group(name="sheets", description="Attendance tracker setup, binding and recovery")
    legacy = app_commands.Group(name="training", description="Historical training import and identity mapping")

    def move(source, target, name, new_name=None):
        command = source.get_command(name)
        if command is None:
            available = ", ".join(item.name for item in source.commands)
            raise ValueError(f"Expected command missing during registration: {name}; available: {available}")
        source.remove_command(name)
        command.parent = None
        if new_name:
            command.name = new_name
        target.add_command(command)

    training = public.get_command("training")
    if training is None:
        available = ", ".join(item.name for item in public.commands)
        raise ValueError("Training command group missing during registration; available: " + available)
    public.remove_command("training")
    training.parent = None
    for name in ("legacy-auto-map", "legacy-map", "legacy-import"):
        move(training, legacy, name)
    for name in ("pending", "approve", "reject"):
        move(staff, links, name)
    for name in ("sheet-bind", "sheet-preview", "sheet-init", "sheet-sync"):
        move(staff, sheets, name, name.removeprefix("sheet-"))
    for name in ("clan-review", "clan-pending", "roster-sync", "personnel-check"):
        move(public, maintenance, name)
    for command in list(staff.commands):
        if command.name not in {"help", "health", "member", "training"}:
            move(staff, maintenance, command.name)
    staff.add_command(training)
    move(public, staff, "transfer")
    for group in (links, sheets, legacy):
        maintenance.add_command(group)
    return maintenance


def command_help(public, staff, administrator=False, roles=(), maintenance=None, staff_only=False):
    """Use registered descriptions so the private guide follows the actual commands."""
    roles = set(roles)
    trainer = personnel_policy.trainer_allowed(administrator, roles)
    leader = administrator or personnel_policy.LEADER in roles
    recruiter = administrator or 1477486340101902517 in roles
    lines = ["TAE command guide", "Only you can see this guide. Staff commands still enforce their normal permissions."]

    def add(command, prefix):
        lines.append(f"`/{prefix} {command.name}` - {command.description}")

    if not staff_only:
        for command in public.commands:
            add(command, "tae")
    if trainer or recruiter:
        lines.append("Staff commands")
        if administrator:
            lines.append("If the automatic link queue is enabled, use its staff-channel Review and Approve buttons for routine linking and tracker updates.")
        for command in staff.commands:
            if command.name == "training" and trainer:
                for child in command.commands:
                    add(child, "tae-admin training")
            elif administrator or command.name == "help":
                add(command, "tae-admin")
    if maintenance is not None:
        recovery = []
        for command in maintenance.commands:
            allowed = (administrator or command.name in {"clan-review", "clan-pending"} and leader
                       or command.name == "roster-sync" and trainer
                       or command.name in {"application-review", "application-role-check"} and recruiter)
            if allowed:
                recovery.append(command)
        if recovery:
            lines.append("Maintenance: recovery/setup only; routine approvals use buttons.")
        for command in recovery:
            children = getattr(command, "commands", None)
            if children:
                for child in children:
                    add(child, f"tae-maintenance {command.name}")
            else:
                add(command, "tae-maintenance")
    page = ""
    pages = []
    for line in lines:
        if len(page) + len(line) + 1 > 1900:
            pages.append(page)
            page = ""
        page += line + "\n"
    if page:
        pages.append(page)
    return pages


def validate_token(value):
    # Reject paste artifacts instead of silently modifying a secret credential.
    value = value.strip(" ")
    if not value:
        raise ValueError("A bot token is required.")
    if not re.fullmatch(r"[A-Za-z0-9_.-]+", value):
        raise ValueError("The token contains whitespace, a control character or another invalid character. Copy only the token again using the Developer Portal Copy button; do not include quotes or a Bot prefix.")
    return value


def pending_entry(row, display_name=None, username=None):
    discord_id, steam_id, submitted = row
    identity = f"{display_name} (@{username})" if display_name and username else "Member lookup unavailable"
    return f"Member: {identity}\nDiscord ID: {discord_id}\nSteamID64: {steam_id}\nSubmitted UTC: {submitted}"


def pending_pages(blocks, limit=1900):
    page = "Pending account-link requests:\n"
    for block in blocks:
        if len(page) + len(block) + 2 > limit:
            yield page
            page = "Pending requests (continued):\n"
        page += "\n" + block + "\n"
    yield page


def build_client(discord, app_commands, store, guild_id, loa_channel_id=None, bot_spam_channel_id=None, allow_absence_posts=False, protected_rank_role_ids=(), enable_live_workflow=False, auto_from=None, sheets_credentials=None, enable_sheet_writes=False, applications_review_channel_id=None, enable_application_roles=False, enable_roster_scan=False, enable_auto_onboarding=False, enable_clan_training=False, enable_link_queue=False):
    guild = discord.Object(id=guild_id)

    class Client(discord.Client):
        def __init__(self):
            # Only LOA processing needs message events/content; slash-only mode does not.
            intents = discord.Intents.none()
            intents.guilds = True
            intents.members = enable_roster_scan
            intents.guild_messages = loa_channel_id is not None
            intents.message_content = loa_channel_id is not None
            super().__init__(intents=intents, allowed_mentions=discord.AllowedMentions.none())
            self.tree = app_commands.CommandTree(self)
            self.loa_lock = asyncio.Lock()
            self.automatic_task = None
            self.link_task = None

        async def setup_hook(self):
            self.add_view(self.personnel_review_factory())
            if enable_link_queue:
                self.add_view(link_review())
            if applications_review_channel_id:
                self.add_view(application_panel_class())
                self.add_view(self.application_review_view_factory())
            if loa_channel_id:
                channel = await self.fetch_channel(loa_channel_id)
                if not isinstance(channel, discord.TextChannel) or channel.guild.id != guild_id:
                    raise ValueError("LOA channel must be a text channel in the configured server.")
            if bot_spam_channel_id:
                channel = await self.fetch_channel(bot_spam_channel_id)
                if not isinstance(channel, discord.TextChannel) or channel.guild.id != guild_id:
                    raise ValueError("Bot-spam channel must be in the configured server.")
            await self.tree.sync(guild=guild)
            print("Attendance commands registered for the configured server. " + ("LIVE workflow enabled." if enable_live_workflow else "PREVIEW mode."), flush=True)
            if enable_live_workflow and auto_from:
                self.automatic_task = asyncio.create_task(self.automatic_operations())
            if enable_link_queue:
                self.link_task = asyncio.create_task(link_poll())

        async def on_ready(self):
            print("Attendance bot connected. " + ("LIVE workflow enabled. " if enable_live_workflow else "Automatic promotions disabled. ")
                  + ("Sheet writes ENABLED." if enable_sheet_writes else "Sheet writes disabled."), flush=True)
            if loa_channel_id:
                print("LOA listening enabled for the configured channel only. Use loa-refresh for older posts; no automatic history scan.", flush=True)

        async def close(self):
            if self.link_task:
                self.link_task.cancel()
                try:
                    await self.link_task
                except asyncio.CancelledError:
                    pass
            if self.automatic_task:
                self.automatic_task.cancel()
                try:
                    await self.automatic_task
                except asyncio.CancelledError:
                    pass
            await super().close()

        async def automatic_operations(self):
            await self.wait_until_ready()
            reported = set()
            while not self.is_closed():
                try:
                    now = dt.datetime.now(dt.timezone.utc)
                    dates = await asyncio.to_thread(store.run, lambda db: db.execute("SELECT DISTINCT substr(utc,1,10) FROM events").fetchall())
                    candidates = set()
                    for (stamp,) in dates:
                        day = dt.date.fromisoformat(stamp)
                        for local_day in (day, day - dt.timedelta(days=1)):
                            if max(auto_from, now.date() - dt.timedelta(days=7)) <= local_day <= now.date():
                                candidates.add(local_day)
                    from attendance import windows
                    for day in sorted(candidates):
                        for key, begin, end in windows(day):
                            if now < end + dt.timedelta(minutes=15):
                                continue
                            try:
                                await workflow.run(day, key.split(":")[1])
                            except Exception:
                                if key not in reported:
                                    print(f"Automatic finalization held for {key}; use workflow-status/preview and resolve evidence, LOAs or permissions.", flush=True)
                                    reported.add(key)
                except Exception:
                    print("Automatic operation check failed; no blind retry of reserved external actions.", flush=True)
                await asyncio.sleep(300)

        async def reconcile_loa_history(self):
            # Before live processing, reconcile offline edits/deletions and old LOAs.
            # Refuse an incomplete scan instead of assuming an unseen post does not exist.
            async with self.loa_lock:
                channel = await self.fetch_channel(loa_channel_id)
                posts = [message async for message in channel.history(limit=1001)]
                if len(posts) > 1000:
                    raise ValueError("LOA history exceeds the safe scan limit; staff must reconcile history before live finalization.")
                inputs = [(message.id, message.author.id, message.content, message.created_at)
                          for message in posts if not message.author.bot]
                seen = {str(message.id) for message in posts}
                def reconcile(db):
                    for mid, author, content, created in inputs:
                        loa.save(db, mid, guild_id, loa_channel_id, author, content, created)
                    known = db.execute("SELECT message_id FROM loa_messages WHERE guild_id=? AND channel_id=? AND status!='cancelled'",
                                       (str(guild_id), str(loa_channel_id))).fetchall()
                    for (mid,) in known:
                        if mid not in seen:
                            loa.cancel(db, mid)
                await asyncio.to_thread(store.run, reconcile)

        async def process_loa(self, channel_id, message_id):
            if not loa_channel_id or channel_id != loa_channel_id:
                return "LOA listener is disabled or this is a different channel."
            # Fetch the latest version rather than trusting an old queued edit payload.
            async with self.loa_lock:
                try:
                    channel = await self.fetch_channel(channel_id)
                    message = await channel.fetch_message(message_id)
                    if not message.guild or message.guild.id != guild_id or message.author.bot:
                        return "Not a member LOA in the configured server."
                    outcome = await asyncio.to_thread(store.run, lambda db: loa.save(
                        db, message.id, guild_id, channel_id, message.author.id, message.content, message.created_at))
                    if not outcome:
                        return "Already current, or no LOA fields found."
                    text = loa.acknowledgement(outcome)
                    try:
                        await channel.send(text, allowed_mentions=discord.AllowedMentions.none())
                    except discord.HTTPException:
                        print("LOA saved but its channel acknowledgement failed; use loa-list to review.", flush=True)
                    return text
                except discord.NotFound:
                    await asyncio.to_thread(store.run, lambda db: loa.cancel(db, message_id))
                    return "Source message no longer exists; any stored LOA was cancelled."

        async def on_message(self, message):
            if not message.author.bot and message.channel.id == loa_channel_id:
                await self.safe_loa(message.channel.id, message.id)

        async def safe_loa(self, channel_id, message_id):
            try:
                await self.process_loa(channel_id, message_id)
            except Exception:
                print("LOA processing failed; staff should refresh/review the source post. No exception contents or reasons printed.", flush=True)

        async def on_raw_message_edit(self, payload):
            if payload.guild_id == guild_id and payload.channel_id == loa_channel_id and "content" in payload.data:
                await self.safe_loa(payload.channel_id, payload.message_id)

        async def on_raw_message_delete(self, payload):
            if payload.guild_id == guild_id and payload.channel_id == loa_channel_id:
                async with self.loa_lock:
                    await asyncio.to_thread(store.run, lambda db: loa.cancel(db, payload.message_id))

        async def on_raw_bulk_message_delete(self, payload):
            if payload.guild_id == guild_id and payload.channel_id == loa_channel_id:
                async with self.loa_lock:
                    for message_id in payload.message_ids:
                        await asyncio.to_thread(store.run, lambda db: loa.cancel(db, message_id))

    client = Client()
    transport = Transport(discord, client, guild_id, bot_spam_channel_id, protected_rank_role_ids)
    if enable_live_workflow:
        transport.reconcile_loas = client.reconcile_loa_history
    workflow = finalization.Workflow(store, transport, guild_id, enable_live_workflow, protected_rank_role_ids)
    workflow.automatic_absence_alerts = allow_absence_posts
    sheet_lock = threading.Lock()

    def sheet_action(callback, writable=False):
        if not sheets_credentials:
            raise ValueError("Google integration is disabled; supply --sheets-credentials on startup.")
        if writable and not enable_sheet_writes:
            raise ValueError("Sheet writes disabled. Use sheet-preview; do not change Viewer access yet.")
        with sheet_lock, sheets_sync.Google(sheets_credentials, writable=writable) as google:
            return store.run(lambda db: callback(db, google))

    if enable_sheet_writes:
        async def export_after_operation():
            result = await asyncio.to_thread(sheet_action, lambda db, google: sheets_sync.export(db, google, guild_id, enabled=True), True)
            if enable_roster_scan:
                await refresh_clans()
            return result
        workflow.sheet_export = export_after_operation

    async def refresh_clans():
        server = client.get_guild(guild_id)
        if not enable_roster_scan or server is None:
            raise ValueError("Clan refresh requires --enable-roster-scan and Server Members Intent.")
        members = {}
        async for member in server.fetch_members(limit=None):
            if not member.bot:
                members[str(member.id)] = [role.id for role in member.roles]
        if not members:
            raise ValueError("Empty Discord roster; clan mappings were not replaced.")
        return await asyncio.to_thread(sheet_action,lambda db,google: clan_tracker.sync(db,google,members),True)

    class AttendanceGroup(app_commands.Group):
        async def interaction_check(self, interaction):
            try:
                authorize(interaction.guild_id, guild_id)
            except PermissionError:
                raise app_commands.CheckFailure("Wrong Discord server or private message.")
            return True

    public = AttendanceGroup(name="tae", description="Submit an account link or view your attendance preview", guild_only=True)
    # Trainers need this root without Administrator; individual handlers enforce authorization.
    staff = AttendanceGroup(name="tae-admin", description="Staff help, health, member attendance and authorized training tools", guild_only=True)
    async def onboard_application(application_id, discord_id, answers):
        member = await client.get_guild(guild_id).fetch_member(int(discord_id))
        result = await asyncio.to_thread(sheet_action, lambda db, google: onboarding.enroll(
            db, google, application_id, discord_id, member.display_name, answers), True)
        if enable_roster_scan:
            try:
                await refresh_clans()
            except Exception:
                result += " Clan display refresh pending; run sheet-sync after checking Discord access."
        return result

    application_panel_class = application_ui.configure(discord, app_commands, client, store, guild_id, staff, applications_review_channel_id, enable_application_roles,
        onboard_application if enable_auto_onboarding else None)
    personnel_ui.configure(discord,app_commands,client,store,guild_id,public,sheet_action,enable_clan_training,refresh_clans)
    if enable_link_queue:
        link_review,link_poll = link_queue_ui.configure(discord,client,store,guild_id,
            applications_review_channel_id,sheet_action,refresh_clans)

    async def execute(interaction, callback, *args):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            text = await asyncio.to_thread(callback, *args)
        except ValueError as error:
            text = str(error)
        except sqlite3.IntegrityError:
            text = "Account-link conflict. Nothing was overwritten. Check the existing roster link."
        except Exception:
            # Never send traceback/database paths or secrets to a Discord channel.
            print("Attendance command failed; inspect local configuration/database availability.", flush=True)
            text = "Command failed. Ask staff to check the bot and database. No external updates were made."
        text = discord.utils.escape_mentions(discord.utils.escape_markdown(str(text)))
        await interaction.followup.send(text[:1950], ephemeral=True,
                                        allowed_mentions=discord.AllowedMentions.none())

    @public.command(name="help", description="Privately show member commands and the staff tools available to your roles")
    @app_commands.checks.cooldown(1, 10, key=lambda interaction: interaction.user.id)
    async def help_command(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True, thinking=True)
        member = await interaction.guild.fetch_member(interaction.user.id)
        pages = command_help(public, staff, member.guild_permissions.administrator,
                             {role.id for role in member.roles}, maintenance)
        for page in pages:
            await interaction.followup.send(page, ephemeral=True,
                                            allowed_mentions=discord.AllowedMentions.none())

    @app_commands.checks.cooldown(1, 10, key=lambda interaction: interaction.user.id)
    async def staff_help(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True, thinking=True)
        member = await interaction.guild.fetch_member(interaction.user.id)
        roles = {role.id for role in member.roles}
        administrator = member.guild_permissions.administrator
        if not (personnel_policy.trainer_allowed(administrator, roles) or 1477486340101902517 in roles):
            await interaction.followup.send("Staff help requires Administrator, an authorized trainer role, or Recruitment Officer.", ephemeral=True)
            return
        for page in command_help(public, staff, administrator, roles, maintenance, staff_only=True):
            await interaction.followup.send(page, ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @public.command(name="register", description="Submit your SteamID64/profile link for staff approval")
    @app_commands.checks.cooldown(1, 60, key=lambda interaction: interaction.user.id)
    async def register(interaction: discord.Interaction, steam: str):
        await execute(interaction, store.request, str(interaction.user.id), steam)

    @public.command(name="status", description="Show your own linked account and attendance preview privately")
    @app_commands.checks.cooldown(1, 10, key=lambda interaction: interaction.user.id)
    async def status(interaction: discord.Interaction):
        await execute(interaction, store.status, str(interaction.user.id))

    @staff.command(name="pending", description="Show up to 20 pending account links for staff verification")
    @app_commands.checks.has_permissions(administrator=True)
    @app_commands.checks.cooldown(1, 15, key=lambda interaction: interaction.user.id)
    async def pending(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            rows = await asyncio.to_thread(store.pending)
        except sqlite3.Error:
            await interaction.followup.send("Unable to read pending requests; check the local database.", ephemeral=True)
            return
        if not rows:
            await interaction.followup.send("No pending requests.", ephemeral=True)
            return
        blocks = []
        for row in rows:
            try:
                # REST lookup works without enabling the privileged Server Members intent.
                member = await interaction.guild.fetch_member(int(row[0]))
                block = pending_entry(row, member.display_name, member.name)
            except discord.HTTPException:
                block = pending_entry(row)
            blocks.append(discord.utils.escape_mentions(discord.utils.escape_markdown(block)))
        for page in pending_pages(blocks):
            await interaction.followup.send(page, ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="approve", description="Approve a verified pending link with starting ops and counting date")
    @app_commands.checks.has_permissions(administrator=True)
    async def approve(interaction: discord.Interaction, member: discord.Member, name: str,
                      since: str, baseline: app_commands.Range[int, 0], joined: str = None):
        if member.bot:
            await interaction.response.send_message("Bot accounts cannot receive attendance.", ephemeral=True)
            return
        await execute(interaction, store.approve, str(interaction.user.id), str(member.id), name, since, baseline, joined)

    @staff.command(name="reject", description="Reject a pending link without changing existing member links")
    @app_commands.checks.has_permissions(administrator=True)
    async def reject(interaction: discord.Interaction, member: discord.Member):
        await execute(interaction, store.reject, str(interaction.user.id), str(member.id))

    @staff.command(name="member", description="Privately inspect one member's attendance preview")
    @app_commands.checks.has_permissions(administrator=True)
    async def member_status(interaction: discord.Interaction, member: discord.Member):
        await execute(interaction, store.status, str(member.id))

    @staff.command(name="health", description="Show collector evidence counts and pending link count")
    @app_commands.checks.has_permissions(administrator=True)
    async def health(interaction: discord.Interaction):
        await execute(interaction, store.health)

    @staff.command(name="loa-refresh", description="Read or refresh one existing LOA post by its message ID")
    @app_commands.checks.has_permissions(administrator=True)
    async def loa_refresh(interaction: discord.Interaction, message_id: str):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            if not re.fullmatch(r"[0-9]{17,20}", message_id):
                raise ValueError("Use Copy Message ID on the LOA source post.")
            text = await client.process_loa(loa_channel_id, int(message_id))
        except (ValueError, discord.HTTPException, sqlite3.Error):
            text = "Unable to refresh LOA. Check message ID, channel configuration, Message Content intent and Read Message History permission."
        await interaction.followup.send(text[:1950], ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="loa-list", description="Show up to 10 stored LOAs, most recently updated first")
    @app_commands.checks.has_permissions(administrator=True)
    async def loa_list(interaction: discord.Interaction):
        def display():
            rows = store.run(lambda db: db.execute("SELECT message_id,member_id,start_date,end_date,status FROM loa_messages ORDER BY updated_utc DESC LIMIT 10").fetchall())
            return "\n".join(" | ".join(str(field or "?") for field in row) for row in rows) if rows else "No stored LOAs."
        await execute(interaction, display)

    @staff.command(name="loa-review", description="Accept or reject a pending, completely parsed LOA")
    @app_commands.checks.has_permissions(administrator=True)
    async def loa_review(interaction: discord.Interaction, message_id: str, accept: bool):
        def review():
            if not re.fullmatch(r"[0-9]{17,20}", message_id):
                raise ValueError("Use the source post's numeric message ID.")
            return store.run(lambda db: loa.review(db, interaction.user.id, message_id, accept))
        await execute(interaction, review)

    @staff.command(name="missed", description="Privately preview consecutive unexcused misses; never posts an alert")
    @app_commands.checks.has_permissions(administrator=True)
    async def missed(interaction: discord.Interaction, member: discord.Member = None):
        def display():
            data = store.run(absence.preview)
            if member:
                data["members"] = [row for row in data["members"] if row["discord_id"] == str(member.id)]
            return absence.format_preview(data)
        await execute(interaction, display)

    @staff.command(name="absence-post", description="Staff-confirmed alert after reviewing LOA history; disabled by default")
    @app_commands.checks.has_permissions(administrator=True)
    async def absence_post(interaction: discord.Interaction, member: discord.Member, reviewed_loa_history: bool):
        await interaction.response.defer(ephemeral=True, thinking=True)
        if not allow_absence_posts or not bot_spam_channel_id or not loa_channel_id:
            await interaction.followup.send("Posting disabled. Use /tae-admin missed for previews.", ephemeral=True)
            return
        if not reviewed_loa_history:
            await interaction.followup.send("Review relevant LOA posts, refresh missed edits/deletions and resolve pending entries first.", ephemeral=True)
            return
        current = None
        try:
            channel = await client.fetch_channel(bot_spam_channel_id)
            current = await asyncio.to_thread(store.run, lambda db: absence.reserve(db, guild_id, member.id))
            name = discord.utils.escape_mentions(discord.utils.escape_markdown(current["name"]))
            sent = await channel.send(f"Attendance check: {name} has missed {current['consecutive_misses']} consecutive operations without a recorded LOA. Staff follow-up requested.",
                                      allowed_mentions=discord.AllowedMentions.none())
            await asyncio.to_thread(store.run, lambda db: absence.finish(db, guild_id, member.id, current["episode"], sent.id))
            text = "Alert posted once in the configured bot-spam channel. No rank or Sheet changes."
        except ValueError as error:
            text = str(error)
        except Exception:
            if current:
                try:
                    await asyncio.to_thread(store.run, lambda db: absence.finish(db, guild_id, member.id, current["episode"]))
                except Exception:
                    pass
            text = "Posting failed or its result is uncertain. Check bot-spam and local receipts before retrying; reserved alerts are not automatically resent."
        await interaction.followup.send(text[:1950], ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="recap", description="Privately preview everyone recorded attending one Saturday operation")
    @app_commands.checks.has_permissions(administrator=True)
    @app_commands.choices(session=[app_commands.Choice(name="Main operation", value="main"),
                                  app_commands.Choice(name="Fun operation", value="fun")])
    async def recap(interaction: discord.Interaction, day: str, session: str = "main"):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            date = dt.date.fromisoformat(day)
            text = await asyncio.to_thread(store.run, lambda db: absence.recap_preview(db, date, session))
        except ValueError:
            await interaction.followup.send("Use a Saturday date in YYYY-MM-DD format and select main or fun.", ephemeral=True)
            return
        except Exception:
            await interaction.followup.send("Unable to build recap; ask staff to check the local database.", ephemeral=True)
            return
        # A file preserves the entire roster instead of truncating larger groups.
        safe = discord.utils.escape_mentions(discord.utils.escape_markdown(text))
        if len(safe) <= 1900:
            await interaction.followup.send(safe, ephemeral=True, allowed_mentions=discord.AllowedMentions.none())
        else:
            await interaction.followup.send("Private recap preview attached; no public post or rank changes made.",
                file=discord.File(io.BytesIO(text.encode("utf-8")), filename=f"attendance-{date}-{session}.txt"), ephemeral=True,
                allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="promotion-preview", description="Inspect a proposed rank/nickname change without applying or announcing it")
    @app_commands.checks.has_permissions(administrator=True)
    async def promotion_preview(interaction: discord.Interaction, member: discord.Member):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            # Read current roles/nickname from Discord, not a potentially stale member cache.
            current = await interaction.guild.fetch_member(member.id)
            if current.bot or current.id == interaction.guild.owner_id:
                text = "Protected: bot accounts and the server owner are never automatically modified."
            else:
                result = await asyncio.to_thread(store.run, lambda db: promotions.plan(
                    db, current.id, current.display_name, [role.id for role in current.roles],
                    [role.name for role in current.roles], protected_rank_role_ids))
                text = promotions.format_plan(result)
        except Exception:
            text = "Unable to build promotion preview. Check roster link, current roles and evidence; no changes made."
        await interaction.followup.send(discord.utils.escape_mentions(discord.utils.escape_markdown(text))[:1950],
                                        ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="finalize", description="LIVE opt-in: finalize a completed op, process promotions and post its recap")
    @app_commands.checks.has_permissions(administrator=True)
    @app_commands.choices(session=[app_commands.Choice(name="Main operation", value="main"), app_commands.Choice(name="Fun operation", value="fun")])
    async def finalize_op(interaction: discord.Interaction, day: str, session: str = "main", reviewed_evidence: bool = False):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            text = await workflow.run(dt.date.fromisoformat(day), session, reviewed_evidence)
        except ValueError as error:
            text = str(error)
        except Exception:
            text = "Workflow stopped. Check workflow-status and Discord before retrying; uncertain changes/posts are never blindly repeated."
        await interaction.followup.send(text[:1950], ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="workflow-status", description="Inspect finalized ledger counts and uncertain external actions")
    @app_commands.checks.has_permissions(administrator=True)
    async def workflow_status(interaction: discord.Interaction):
        def display():
            def query(db):
                ops = db.execute("SELECT count(*) FROM finalized_operations WHERE guild_id=?", (str(guild_id),)).fetchone()[0]
                jobs = db.execute("SELECT discord_id,state FROM promotion_jobs WHERE guild_id=? AND state!='applied' LIMIT 10", (str(guild_id),)).fetchall()
                posts = db.execute("SELECT kind,post_key,state FROM workflow_posts WHERE guild_id=? AND state!='sent' LIMIT 10", (str(guild_id),)).fetchall()
                totals = finalization.ledger_totals(db, guild_id)
                return ops, jobs, posts, totals
            ops, jobs, posts, totals = store.run(query)
            lines = ["Live workflow: " + ("enabled" if enable_live_workflow else "disabled"), f"Finalized operations: {ops}",
                     "Uncertain/in-flight promotions: " + str(jobs), "Uncertain/in-flight posts: " + str(posts), "Ledger totals (first 8):"]
            lines += [f"{name}: {baseline} starting + {new} finalized = {baseline + new}" for _, name, baseline, new in totals[:8]]
            return "\n".join(lines)
        await execute(interaction, display)

    @staff.command(name="live-check", description="Read-only check of permissions, role hierarchy and announcement destinations")
    @app_commands.checks.has_permissions(administrator=True)
    async def live_check(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            await transport.preflight()
            text = "Permission/hierarchy/channel checks passed. No roles, nicknames, attendance totals or public messages changed. Live mode still requires its explicit startup flag."
        except ValueError as error:
            text = str(error)
        except Exception:
            text = "Unable to read live configuration. Check bot permissions, role hierarchy and channel access. No changes made."
        await interaction.followup.send(text[:1950], ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="sheet-bind", description="Explicitly map a linked member to an existing tracker row; never writes the sheet")
    @app_commands.checks.has_permissions(administrator=True)
    async def sheet_bind(interaction: discord.Interaction, member: discord.Member, row: app_commands.Range[int, 2, 1000], exact_sheet_name: str):
        await execute(interaction, sheet_action, lambda db, google: sheets_sync.bind(db, google, member.id, row, exact_sheet_name, guild_id))

    @staff.command(name="sheet-preview", description="Read Google totals and show proposed finalized-ledger updates without writing")
    @app_commands.checks.has_permissions(administrator=True)
    async def sheet_preview(interaction: discord.Interaction):
        def display(db, google):
            plan = sheets_sync.prepare(db, google, guild_id)
            uncertain = db.execute("SELECT count(*) FROM sheet_exports WHERE state IN ('sending','uncertain')").fetchone()[0]
            return "SHEET PREVIEW - NO WRITES\n" + "\n".join(plan["description"][:12]) + f"\nHistory tab ready: {plan['history_ready']}. Unmapped linked members: {plan['unmapped']}. Proposed changed ranges: {len(plan['changes'])}. Export receipts needing review: {uncertain}."
        await execute(interaction, sheet_action, display)

    @staff.command(name="sheet-init", description="Explicit write opt-in: create only the separate Attendance last four tab")
    @app_commands.checks.has_permissions(administrator=True)
    async def sheet_init(interaction: discord.Interaction, confirm: bool):
        if not confirm:
            await interaction.response.send_message("No changes made.", ephemeral=True)
            return
        await execute(interaction, sheet_action, lambda db, google: google.create_history(), True)

    @staff.command(name="sheet-sync", description="Explicit write opt-in: export finalized totals and last-four results")
    @app_commands.checks.has_permissions(administrator=True)
    async def sheet_sync(interaction: discord.Interaction, confirm: bool):
        if not confirm:
            await interaction.response.send_message("No changes made.", ephemeral=True)
            return
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            result = await asyncio.to_thread(sheet_action,lambda db,google: sheets_sync.export(db,google,guild_id,enabled=True),True)
            if enable_roster_scan:
                try:
                    result += " " + await refresh_clans()
                except Exception:
                    result += " Attendance export completed, but clan grouping refresh was not confirmed. Check Server Members Intent and the helper tab."
        except Exception:
            result = "Sheet export was not confirmed. Inspect sheet-preview and export receipts before retrying."
        await interaction.followup.send(result,ephemeral=True,allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="roster-check", description="Compare House Karr members and linked attendance without changing anything")
    @app_commands.checks.has_permissions(administrator=True)
    async def roster_check(interaction: discord.Interaction):
        authorize(interaction.guild_id, guild_id, interaction.user.guild_permissions.administrator, staff=True)
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            if not enable_roster_scan:
                raise ValueError("Enable Server Members Intent in the Developer Portal, then restart with --enable-roster-scan.")
            server = client.get_guild(guild_id)
            if server is None:
                raise ValueError("Configured server unavailable. No comparison performed.")
            roles = await server.fetch_roles()
            if not any(role.id == membership.HOUSE_KARR_ROLE for role in roles):
                raise ValueError("House Karr role was not found. No comparison performed.")
            snapshot = []
            async for member in server.fetch_members(limit=None):
                if not member.bot:
                    snapshot.append((member.id, f"{member.display_name} (@{member.name})", [role.id for role in member.roles]))
            if not snapshot:
                raise ValueError("Empty member list; refusing to label anyone as departed.")
            result = await asyncio.to_thread(store.run, lambda db: membership.roster_report(db, snapshot))
            await interaction.followup.send("Roster check complete. Full private report attached. No changes made.",
                file=discord.File(io.BytesIO(result.encode("utf-8")), filename="tae-roster-check.txt"), ephemeral=True)
            return
        except ValueError as error:
            message = str(error)
        except Exception:
            message = "Could not fetch the complete roster. Check Server Members Intent and bot access. No comparison or changes made."
        await interaction.followup.send(message, ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="archive-member", description="Deactivate attendance and preserve history; optionally move the mapped tracker entry")
    @app_commands.checks.has_permissions(administrator=True)
    async def archive_member(interaction: discord.Interaction, confirm: bool, member: discord.Member = None, discord_id: str = None, update_sheet: bool = True):
        if not confirm:
            await interaction.response.send_message("No changes made.",ephemeral=True)
            return
        if (member is None) == (discord_id is None):
            await interaction.response.send_message("Choose either a member OR their Discord ID (for someone who already left).",ephemeral=True)
            return
        target = str(member.id) if member else discord_id
        if not re.fullmatch(r"[0-9]{17,20}",target):
            await interaction.response.send_message("Use the numeric Discord user ID, not a username.",ephemeral=True)
            return
        await interaction.response.defer(ephemeral=True,thinking=True)
        async with workflow.lock:
            try:
                payload = await asyncio.to_thread(store.run,lambda db: membership.archive(db,guild_id,target,interaction.user.id))
                text = f"{payload['name']} archived locally. Future attendance, promotions, exports and absence checks disabled; history and Discord roles preserved."
                if update_sheet:
                    try:
                        result = await asyncio.to_thread(sheet_action,lambda db,google: membership.export_archive(db,google,guild_id,target),True)
                        text += " " + result
                    except Exception:
                        text += " Sheet archive was not confirmed. Local deactivation is complete; inspect configuration/row binding and archive receipt before retrying. ORBAT remains manual."
            except ValueError as error:
                text = str(error)
            except Exception:
                text = "Archive failed; inspect local records. No Discord roles were changed."
        await interaction.followup.send(discord.utils.escape_mentions(discord.utils.escape_markdown(text))[:1950],ephemeral=True,allowed_mentions=discord.AllowedMentions.none())

    @client.tree.error
    async def command_error(interaction, error):
        text = "You do not have permission to use this command. Training allows authorized trainers; clan reviews allow the destination clan's leader; application reviews allow Recruitment Officers. Other recovery tools require Administrator."
        if isinstance(error, app_commands.CommandOnCooldown):
            text = "Please wait briefly before repeating that command."
        if interaction.response.is_done():
            await interaction.followup.send(text, ephemeral=True)
        else:
            await interaction.response.send_message(text, ephemeral=True)

    maintenance = arrange_commands(app_commands, public, staff)
    staff.add_command(app_commands.command(name="help", description="Privately show staff commands available to your roles and recovery guidance")(staff_help))
    client.tree.add_command(public, guild=guild)
    client.tree.add_command(staff, guild=guild)
    client.tree.add_command(maintenance, guild=guild)
    return client


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--db", type=Path, default=Path("D:/TAEAttendance/data/attendance.sqlite3"))
    parser.add_argument("--guild-id", type=int, required=True, help="Discord server ID, not a channel ID")
    parser.add_argument("--loa-channel-id", type=int, help="Enable existing-format LOA listening in this text channel")
    parser.add_argument("--bot-spam-channel-id", type=int, help="Destination for optional staff-confirmed absence alerts")
    parser.add_argument("--allow-absence-posts", action="store_true", help="Enable absence posts; in live workflow, automatically alert bot-spam after four finalized unexcused misses")
    parser.add_argument("--protected-rank-role-id", action="append", type=int, default=[], help="Appointed rank role to protect; repeat for each role")
    parser.add_argument("--enable-live-workflow", action="store_true", help="Explicitly enable real role/nickname changes, announcements and recaps")
    parser.add_argument("--auto-from", type=dt.date.fromisoformat, help="Opt-in automatic finalization from this Eastern date; requires live workflow")
    parser.add_argument("--sheets-credentials", type=Path, help="Path to private Google service-account key; read-only unless separately enabled")
    parser.add_argument("--enable-sheet-writes", action="store_true", help="Explicitly enable finalized exports to Google; requires Editor sharing")
    parser.add_argument("--applications-review-channel-id", type=int, help="Enable the Apply panel workflow; destination must be staff-only")
    parser.add_argument("--enable-application-roles",action="store_true",help="Explicitly allow verified role assignment when staff accepts an application")
    parser.add_argument("--enable-roster-scan",action="store_true",help="Enable Server Members Intent for read-only roster checks")
    parser.add_argument("--enable-auto-onboarding",action="store_true",help="Automatically link accepted active members and create zero-total tracker entries")
    parser.add_argument("--enable-clan-training",action="store_true",help="Enable clan applications, training roles and explicit managed personnel Sheet synchronization")
    parser.add_argument("--enable-link-queue",action="store_true",help="Post detected Steam identities and registration requests to the staff application channel for button approval")
    parser.add_argument("--check", action="store_true", help="Validate local setup/command construction without connecting")
    args = parser.parse_args()
    if args.enable_link_queue and not (args.guild_id == promotions.GUILD_ID and args.enable_roster_scan and args.enable_sheet_writes and args.sheets_credentials and args.applications_review_channel_id):
        parser.error("Automatic link queue requires the TAE guild, roster scan, Sheet writes, credentials and a staff application review channel.")
    if args.enable_auto_onboarding and not (args.enable_application_roles and args.enable_sheet_writes and args.sheets_credentials and args.applications_review_channel_id):
        parser.error("Automatic onboarding requires application roles, Sheet writes, credentials and an application review channel.")
    if args.enable_clan_training and not (args.guild_id == promotions.GUILD_ID and args.enable_roster_scan and args.enable_sheet_writes and args.sheets_credentials):
        parser.error("Clan/training writes require the TAE guild, --enable-roster-scan, Sheet writes and credentials.")
    if not 10**16 <= args.guild_id < 10**20:
        parser.error("Invalid Discord server ID")
    if args.loa_channel_id is not None and not 10**16 <= args.loa_channel_id < 10**20:
        parser.error("Invalid LOA channel ID")
    if args.bot_spam_channel_id is not None and not 10**16 <= args.bot_spam_channel_id < 10**20:
        parser.error("Invalid bot-spam channel ID")
    if args.allow_absence_posts and (not args.loa_channel_id or not args.bot_spam_channel_id):
        parser.error("Absence posting requires both LOA and bot-spam channel IDs")
    if any(not 10**16 <= role < 10**20 for role in args.protected_rank_role_id):
        parser.error("Invalid protected rank role ID")
    if args.enable_live_workflow and (args.guild_id != promotions.GUILD_ID or not args.bot_spam_channel_id or not args.loa_channel_id):
        parser.error("Live workflow requires the configured TAE guild, LOA channel and bot-spam channel")
    if args.auto_from and not args.enable_live_workflow:
        parser.error("--auto-from requires --enable-live-workflow")
    if args.enable_sheet_writes and not args.sheets_credentials:
        parser.error("--enable-sheet-writes requires --sheets-credentials")
    if args.sheets_credentials and not args.sheets_credentials.is_file():
        parser.error("Google credential file not found; do not paste its contents")
    if args.applications_review_channel_id is not None and not 10**16 <= args.applications_review_channel_id < 10**20:
        parser.error("Invalid staff application review channel ID")
    if args.enable_application_roles and not args.applications_review_channel_id:
        parser.error("--enable-application-roles requires --applications-review-channel-id")
    try:
        import discord
        from discord import app_commands
    except ImportError:
        parser.exit(1, "discord.py is not installed. Obtain approval before installing requirements-discord.txt.\n")
    try:
        store = Store(args.db)
    except (ValueError, sqlite3.Error):
        parser.exit(1, "Unable to open the existing attendance database or initialize bot tables. Check --db and file permissions.\n")
    try:
        client = build_client(discord, app_commands, store, args.guild_id, args.loa_channel_id,
                              args.bot_spam_channel_id, args.allow_absence_posts, args.protected_rank_role_id,
                              args.enable_live_workflow, args.auto_from, args.sheets_credentials,
                              args.enable_sheet_writes, args.applications_review_channel_id,args.enable_application_roles,args.enable_roster_scan,args.enable_auto_onboarding,args.enable_clan_training,args.enable_link_queue)
    except ValueError as error:
        detail = str(error).replace(os.environ.get("TAE_DISCORD_TOKEN") or "\x00", "[REDACTED]")
        parser.exit(1, "Discord command construction failed: " + detail[:500] + "\nNo Discord connection made; do not reset the database or credentials.\n")
    if args.check:
        print("Local bot setup valid. Commands constructed; no Discord connection made.")
        return
    try:
        token = validate_token(os.environ.get("TAE_DISCORD_TOKEN") or getpass.getpass("Discord bot token (hidden; never paste into chat): "))
    except ValueError as error:
        parser.exit(1, str(error) + " Token contents were not printed.\n")
    except (EOFError, KeyboardInterrupt):
        parser.exit(1, "Token entry cancelled.\n")
    try:
        # Disable SDK default logging to avoid verbose HTTP/authentication output.
        client.run(token, log_handler=None)
    except discord.LoginFailure:
        parser.exit(1, "Discord rejected the token. Reset it in the Developer Portal if needed; do not share it.\n")
    except discord.PrivilegedIntentsRequired:
        parser.exit(1, "Enable Message Content Intent on the app's Bot page before using --loa-channel-id.\n")
    except ValueError:
        parser.exit(1, "Bot configuration invalid. Check the LOA channel belongs to the configured Discord server.\n")
    except (discord.HTTPException, OSError):
        parser.exit(1, "Discord connection/command registration failed. Check internet access, the bot invitation and server ID.\n")


if __name__ == "__main__":
    main()
