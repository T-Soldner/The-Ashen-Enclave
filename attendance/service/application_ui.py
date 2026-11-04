"""Persistent Apply panel and private form flow; Discord SDK injected at runtime."""
import asyncio
import sqlite3

import applications
import application_roles


def is_application_panel(message, bot_id):
    return message.author.id == bot_id and any(
        getattr(child, "custom_id", None) == "tae:application:open:v1"
        for row in message.components for child in getattr(row, "children", ()))


async def find_application_panel(channel, bot_id, limit=100):
    count = 0
    async for message in channel.history(limit=limit):
        count += 1
        if is_application_panel(message, bot_id):
            return message
    if count >= limit:
        raise ValueError("Recovery could not inspect the entire channel within 100 messages. No receipt was cleared; staff review required.")
    return None


def review_authorized(guild_id, configured_guild, administrator, channel_id=None, configured_channel=None, role_ids=()):
    reviewer = bool(administrator) or applications.RECRUITMENT_OFFICER_ROLE in set(role_ids)
    return guild_id == configured_guild and reviewer and (
        configured_channel is None or channel_id == configured_channel)


def configure(discord, app_commands, client, store, guild_id, staff, review_channel_id, enable_application_roles=False, onboard=None):
    panel_lock = asyncio.Lock()
    role_transport = application_roles.DiscordRoles(discord,client,guild_id)
    admissions = application_roles.Admissions(store,role_transport,enabled=enable_application_roles,onboard=onboard)

    def can_review(interaction, source_channel=False):
        return review_authorized(interaction.guild_id,guild_id,interaction.permissions.administrator,
            interaction.channel_id,review_channel_id if source_channel else None,
            [role.id for role in getattr(interaction.user,"roles",())])

    async def require_unassigned(interaction):
        if interaction.guild_id != guild_id:
            raise ValueError("Use the application panel in the configured server.")
        roles = await role_transport.current(interaction.user.id)
        if applications.UNASSIGNED_ROLE not in roles:
            raise ValueError("Only members with the Unassigned role can use Apply.")
    async def review_channel():
        if not review_channel_id:
            raise ValueError("Applications are not configured yet.")
        channel = await client.fetch_channel(review_channel_id)
        if not isinstance(channel, discord.TextChannel) or channel.guild.id != guild_id:
            raise ValueError("Application review destination must be a text channel in this server.")
        if channel.permissions_for(channel.guild.default_role).view_channel:
            raise ValueError("Application review channel is visible to everyone. Make it staff-only first.")
        me = await channel.guild.fetch_member(client.user.id)
        permissions = channel.permissions_for(me)
        if not permissions.view_channel or not permissions.send_messages or not permissions.embed_links:
            raise ValueError("The bot needs View Channel, Send Messages and Embed Links in submitted-applications.")
        return channel

    async def deliver(application_id):
        channel = await review_channel()
        who, category, answers = await asyncio.to_thread(store.run, lambda db: applications.reserve_delivery(db, application_id))
        try:
            embed = discord.Embed(title="Ashen Enclave application", description=f"Applicant: <@{who}>\nApplication ID: {application_id}")
            embed.add_field(name="Participation", value=category, inline=False)
            for key, label, limit in applications.fields_for(category):
                if key in answers:
                    # Field values cap at 1024; long introductions use two fields.
                    text = discord.utils.escape_mentions(discord.utils.escape_markdown(answers[key]))
                    for index in range(0, len(text), 1000):
                        embed.add_field(name=label if index == 0 else label + " (continued)", value=text[index:index+1000], inline=False)
            sent = await channel.send(embed=embed, view=ReviewButtons(), allowed_mentions=discord.AllowedMentions.none())
        except BaseException:
            await asyncio.to_thread(store.run, lambda db: applications.finish_delivery(db, application_id))
            raise
        await asyncio.to_thread(store.run, lambda db: applications.finish_delivery(db, application_id, sent.id))

    async def submit(interaction, category, answers):
        await interaction.response.defer(ephemeral=True, thinking=True)
        try:
            if interaction.guild_id != guild_id or interaction.user.bot:
                raise ValueError("Apply from the configured Discord server with your own member account.")
            await require_unassigned(interaction)
            await review_channel()  # Check privacy before collecting answers in SQLite.
            identifier = await asyncio.to_thread(store.run, lambda db: applications.submit(
                db, interaction.id, interaction.user.id, category, answers))
        except (ValueError, sqlite3.IntegrityError) as error:
            text = str(error) if isinstance(error, ValueError) else "An application is already pending for your account."
            await interaction.followup.send(text[:1500], ephemeral=True)
            return
        except Exception:
            await interaction.followup.send("Applications are temporarily unavailable. Contact staff; no roles or attendance were assigned.", ephemeral=True)
            return
        try:
            await deliver(identifier)
            text = "Application submitted for staff review. No roles or attendance link have been assigned."
        except Exception:
            text = f"Application {identifier} was saved locally, but staff-channel delivery needs review. Please contact staff rather than submitting again."
        await interaction.followup.send(text, ephemeral=True)

    class ActiveForm(discord.ui.Modal):
        def __init__(self, user_id, record):
            super().__init__(title="Ashen Enclave Member Submission", timeout=600)
            self.user_id = user_id
            self.record = record
            self.inputs = {}
            for key, label, limit in applications.FIELDS:
                if key == "record":
                    continue
                item = discord.ui.TextInput(label=label, max_length=limit, required=True,
                    style=discord.TextStyle.paragraph if key == "about" else discord.TextStyle.short)
                self.inputs[key] = item
                self.add_item(item)

        async def on_submit(self, interaction):
            if interaction.user.id != self.user_id:
                await interaction.response.send_message("This form belongs to another member.", ephemeral=True)
                return
            await submit(interaction, applications.CATEGORIES[0], {**{key:item.value for key,item in self.inputs.items()},"record":self.record})

    class LiaisonForm(discord.ui.Modal):
        def __init__(self,user_id):
            super().__init__(title="Unit Liaison application",timeout=600)
            self.user_id = user_id
            self.inputs = {}
            for key,label,limit in applications.LIAISON_FIELDS:
                item = discord.ui.TextInput(label=label,max_length=limit,required=True)
                self.inputs[key] = item
                self.add_item(item)

        async def on_submit(self,interaction):
            if interaction.user.id != self.user_id:
                await interaction.response.send_message("This form belongs to another member.",ephemeral=True)
                return
            await submit(interaction,applications.CATEGORIES[1],{key:item.value for key,item in self.inputs.items()})

    class StreamChoice(discord.ui.View):
        def __init__(self,user_id):
            super().__init__(timeout=300)
            self.user_id = user_id

        @discord.ui.select(placeholder="Do you stream or record?",options=[discord.SelectOption(label="Yes",value="yes"),discord.SelectOption(label="No",value="no")])
        async def choose(self,interaction: discord.Interaction,select: discord.ui.Select):
            if interaction.user.id != self.user_id:
                await interaction.response.send_message("Open your own application using Apply.",ephemeral=True)
                return
            try:
                await require_unassigned(interaction)
            except Exception:
                await interaction.response.send_message("Only members with Unassigned can continue applying.",ephemeral=True)
                return
            await interaction.response.send_modal(ActiveForm(self.user_id,select.values[0]))

    class Confirm(discord.ui.View):
        def __init__(self, user_id, category):
            super().__init__(timeout=300)
            self.user_id, self.category = user_id, category

        @discord.ui.button(label="Submit application", style=discord.ButtonStyle.success)
        async def confirm(self, interaction: discord.Interaction, button: discord.ui.Button):
            if interaction.user.id != self.user_id:
                await interaction.response.send_message("Open your own application using Apply.", ephemeral=True)
                return
            await submit(interaction, self.category, {})
            self.stop()

    class Participation(discord.ui.View):
        def __init__(self, user_id):
            super().__init__(timeout=300)
            self.user_id = user_id

        @discord.ui.select(placeholder="How would you like to participate?", options=[discord.SelectOption(label=label, value=label) for label in applications.CATEGORIES])
        async def choose(self, interaction: discord.Interaction, select: discord.ui.Select):
            if interaction.user.id != self.user_id:
                await interaction.response.send_message("Open your own application using Apply.", ephemeral=True)
                return
            try:
                await require_unassigned(interaction)
            except Exception:
                await interaction.response.send_message("Only members with Unassigned can continue applying.",ephemeral=True)
                return
            category = select.values[0]
            if category == applications.CATEGORIES[0]:
                await interaction.response.edit_message(content="Do you stream or record?",view=StreamChoice(self.user_id))
            elif category == applications.CATEGORIES[1]:
                await interaction.response.send_modal(LiaisonForm(self.user_id))
            else:
                await interaction.response.edit_message(content=f"Apply as {category}? No additional questions are required.", view=Confirm(self.user_id, category))

    class Panel(discord.ui.View):
        def __init__(self):
            super().__init__(timeout=None)

        @discord.ui.button(label="Apply", style=discord.ButtonStyle.primary, custom_id="tae:application:open:v1")
        async def apply(self, interaction: discord.Interaction, button: discord.ui.Button):
            if not review_channel_id or interaction.guild_id != guild_id or interaction.channel_id != applications.PUBLIC_CHANNEL:
                await interaction.response.send_message("Applications are not available from this panel.", ephemeral=True)
                return
            try:
                await require_unassigned(interaction)
            except Exception:
                await interaction.response.send_message("Only members with the Unassigned role can use Apply.",ephemeral=True)
                return
            await interaction.response.send_message("How would you like to participate in the unit?", view=Participation(interaction.user.id), ephemeral=True)

    async def resolve_button(interaction):
        if not can_review(interaction,source_channel=True):
            raise ValueError("Only Discord administrators or Recruitment Officers can review applications in the configured staff channel.")
        if not interaction.message or interaction.message.author.id != client.user.id:
            raise ValueError("This is not one of this bot's application posts.")
        row = await asyncio.to_thread(store.run,lambda db: db.execute(
            "SELECT application_id,status FROM applications WHERE review_message_id=?",(str(interaction.message.id),)).fetchone())
        if not row or row[1] != "pending":
            raise ValueError("Application was already reviewed or could not be matched. No duplicate decision was saved.")
        return row[0]

    async def update_review_post(application_id, message=None):
        row = await asyncio.to_thread(store.run,lambda db: db.execute(
            "SELECT status,reviewed_by,denial_reason,review_message_id FROM applications WHERE application_id=?",(str(application_id),)).fetchone())
        if not row or not row[3]:
            return False
        if message is None:
            channel = await review_channel()
            message = await channel.fetch_message(int(row[3]))
        if str(message.id) != row[3] or message.author.id != client.user.id or message.channel.id != review_channel_id:
            return False
        text = f"Decision: {'Accepted' if row[0] == 'approved' else 'Denied'} by <@{row[1]}>."
        if row[2]:
            text += "\nReason: " + discord.utils.escape_mentions(discord.utils.escape_markdown(row[2]))
        await message.edit(content=text,view=None,allowed_mentions=discord.AllowedMentions.none())
        return True

    async def decide(interaction, application_id, accept, reason=None, message=None):
        await interaction.response.defer(ephemeral=True,thinking=True)
        if not can_review(interaction):
            await interaction.followup.send("Administrator permission or the Recruitment Officer role is required.",ephemeral=True)
            return
        try:
            await review_channel()  # Recheck privacy before saving/publishing a decision reason.
            if accept:
                text = await admissions.approve(interaction.user.id,application_id)
            else:
                text = await asyncio.to_thread(store.run,lambda db: applications.review(db,interaction.user.id,application_id,False,reason))
        except ValueError as error:
            await interaction.followup.send(str(error),ephemeral=True)
            return
        except Exception:
            await interaction.followup.send("Decision/role assignment was not confirmed. Inspect the application and admission receipt before retrying; partial role changes are not blindly repeated.",ephemeral=True)
            return
        try:
            updated = await update_review_post(application_id,message)
        except Exception:
            updated = False
        if not updated:
            text += " Decision saved, but the staff post could not be updated. Existing buttons cannot save a second decision."
        await interaction.followup.send(text,ephemeral=True)

    class DenialForm(discord.ui.Modal):
        def __init__(self, application_id, actor_id, source_message=None):
            super().__init__(title="Deny application",timeout=600)
            self.application_id,self.actor_id,self.source_message = application_id,actor_id,source_message
            self.reason = discord.ui.TextInput(label="Reason for denial",style=discord.TextStyle.paragraph,
                                               required=True,min_length=1,max_length=800)
            self.add_item(self.reason)

        async def on_submit(self,interaction):
            if interaction.user.id != self.actor_id or not can_review(interaction):
                await interaction.response.send_message("Only the authorized reviewer who opened this form may submit it.",ephemeral=True)
                return
            if self.source_message is not None and interaction.channel_id != review_channel_id:
                await interaction.response.send_message("Use the configured staff review channel.",ephemeral=True)
                return
            await decide(interaction,self.application_id,False,self.reason.value,self.source_message)

    class ReviewButtons(discord.ui.View):
        def __init__(self):
            super().__init__(timeout=None)

        @discord.ui.button(label="Accept",style=discord.ButtonStyle.success,custom_id="tae:application:accept:v1")
        async def accept(self,interaction: discord.Interaction,button: discord.ui.Button):
            try:
                application_id = await resolve_button(interaction)
            except ValueError as error:
                await interaction.response.send_message(str(error),ephemeral=True)
                return
            await decide(interaction,application_id,True,message=interaction.message)

        @discord.ui.button(label="Deny",style=discord.ButtonStyle.danger,custom_id="tae:application:deny:v1")
        async def deny(self,interaction: discord.Interaction,button: discord.ui.Button):
            try:
                application_id = await resolve_button(interaction)
            except ValueError as error:
                await interaction.response.send_message(str(error),ephemeral=True)
                return
            await interaction.response.send_modal(DenialForm(application_id,interaction.user.id,interaction.message))

    client.application_review_view_factory = ReviewButtons

    @staff.command(name="application-panel", description="Post the persistent Apply button in the configured applications channel")
    @app_commands.checks.has_permissions(administrator=True)
    async def application_panel(interaction: discord.Interaction, recover_failed: bool = False):
        await interaction.response.defer(ephemeral=True, thinking=True)
        async with panel_lock:
            await post_panel(interaction, recover_failed)

    async def post_panel(interaction, recover_failed):
        reserved = False
        try:
            await review_channel()
            channel = await client.fetch_channel(applications.PUBLIC_CHANNEL)
            if not isinstance(channel, discord.TextChannel) or channel.guild.id != guild_id:
                raise ValueError("Invalid public application channel.")
            me = await channel.guild.fetch_member(client.user.id)
            permissions = channel.permissions_for(me)
            if not permissions.view_channel or not permissions.send_messages:
                raise ValueError("Allow the bot View Channel and Send Messages in tickets-applications-feedback first.")
            previous = await asyncio.to_thread(store.run, lambda db: db.execute(
                "SELECT state,message_id FROM application_panels WHERE guild_id=?", (str(guild_id),)).fetchone())
            if previous:
                existing = None
                if previous[1]:
                    try:
                        candidate = await channel.fetch_message(int(previous[1]))
                        if is_application_panel(candidate, client.user.id):
                            existing = candidate
                    except discord.NotFound:
                        pass
                if existing:
                    raise ValueError("Your Apply panel is already here: " + existing.jump_url)
                if not recover_failed:
                    raise ValueError("A previous panel attempt is reserved but no saved panel could be confirmed. After fixing permissions, rerun application-panel with recover_failed:True. The bot will check history before replacing it.")
                if not permissions.read_message_history:
                    raise ValueError("Recovery requires Read Message History in tickets-applications-feedback.")
                existing = await find_application_panel(channel, client.user.id)
                def reconcile(db):
                    with db:
                        db.execute("BEGIN IMMEDIATE")
                        current = db.execute("SELECT state,message_id FROM application_panels WHERE guild_id=?", (str(guild_id),)).fetchone()
                        if current != previous:
                            raise ValueError("Panel receipt changed during recovery. No replacement posted.")
                        if existing:
                            db.execute("UPDATE application_panels SET state='sent',message_id=? WHERE guild_id=?", (str(existing.id),str(guild_id)))
                        else:
                            db.execute("DELETE FROM application_panels WHERE guild_id=?", (str(guild_id),))
                await asyncio.to_thread(store.run, reconcile)
                if existing:
                    raise ValueError("Recovered your existing Apply panel without posting a duplicate: " + existing.jump_url)
            def reserve(db):
                with db:
                    return db.execute("INSERT OR IGNORE INTO application_panels VALUES (?,'sending',NULL)", (str(guild_id),)).rowcount == 1
            reserved = await asyncio.to_thread(store.run, reserve)
            if not reserved:
                raise ValueError("An application panel is already posted or reserved. Check the channel before creating another.")
            sent = await channel.send("**The Ashen Enclave applications**\nChoose Apply to submit an application privately to staff.",
                                      view=Panel(), allowed_mentions=discord.AllowedMentions.none())
            def finish(db):
                with db:
                    db.execute("UPDATE application_panels SET state='sent',message_id=? WHERE guild_id=?", (str(sent.id), str(guild_id)))
            await asyncio.to_thread(store.run, finish)
            text = "Apply panel posted. Form replies are private; submissions go only to the staff review channel."
        except discord.Forbidden:
            text = "Discord denied channel access. Check View Channel/Send Messages in the public channel and View Channel/Send Messages/Embed Links in the staff channel. Recovery also needs Read Message History."
        except ValueError as error:
            text = str(error)
        except Exception:
            text = "Panel posting failed or its result is uncertain. Inspect the channel/local receipt before retrying."
        await interaction.followup.send(text[:1900], ephemeral=True)

    @staff.command(name="application-review", description="Accept with configured roles, or deny with a reason; attendance linking remains separate")
    @app_commands.check(can_review)
    async def application_review(interaction: discord.Interaction, application_id: str, accept: bool, reason: str = None):
        if not accept and not reason:
            await interaction.response.send_modal(DenialForm(application_id,interaction.user.id))
            return
        await decide(interaction,application_id,accept,reason)

    @staff.command(name="application-pending", description="Show pending application IDs and delivery status privately")
    @app_commands.checks.has_permissions(administrator=True)
    async def application_pending(interaction: discord.Interaction, attach_buttons: bool = False):
        await interaction.response.defer(ephemeral=True, thinking=True)
        rows = await asyncio.to_thread(store.run, lambda db: db.execute("SELECT application_id,discord_id,category,delivery FROM applications WHERE status='pending' ORDER BY submitted_utc LIMIT 10").fetchall())
        text = "\n".join(" | ".join(row) for row in rows) if rows else "No pending applications."
        if attach_buttons:
            attached = 0
            for application_id,_,_,_ in rows:
                try:
                    source = await asyncio.to_thread(store.run,lambda db: db.execute("SELECT review_message_id FROM applications WHERE application_id=?",(application_id,)).fetchone())
                    if source and source[0]:
                        channel = await review_channel()
                        message = await channel.fetch_message(int(source[0]))
                        if message.author.id == client.user.id:
                            await message.edit(view=ReviewButtons())
                            attached += 1
                except Exception:
                    pass
            text += f"\nAdded/refreshed review buttons on {attached} of these pending posts. Missing posts or permissions were left unchanged."
        await interaction.followup.send(text[:1900], ephemeral=True, allowed_mentions=discord.AllowedMentions.none())

    @staff.command(name="application-role-check",description="Read-only check that every application role exists below the bot and is safe to grant")
    @app_commands.check(can_review)
    async def application_role_check(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True,thinking=True)
        desired = {"add_roles":sorted(applications.ACTIVE_ROLES | {applications.STREAMER_ROLE,applications.FRIEND_ROLE,applications.LIAISON_ROLE}),"remove_role":applications.UNASSIGNED_ROLE}
        try:
            await role_transport.preflight(desired)
            text = "Application role checks passed. No roles changed. Assignment is " + ("ENABLED on staff acceptance." if enable_application_roles else "disabled until --enable-application-roles is supplied.")
        except ValueError as error:
            text = str(error)
        except Exception:
            text = "Could not read application role permissions/hierarchy. No roles changed."
        await interaction.followup.send(text,ephemeral=True)

    return Panel
