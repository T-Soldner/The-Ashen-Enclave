"""Discord clan applications, training editors and explicit roster synchronization."""
import asyncio
import io
import json

import clan_training as policy
from personnel_workflow import Workflow
import personnel_sheets
import legacy_training


def check_error(stage,error):
    """Read-only diagnostics: report the failed step, not a mutation warning."""
    if isinstance(error,(ValueError,AttributeError,TypeError,RuntimeError)):
        detail = f"{type(error).__name__}: {error}"
    else:
        detail = type(error).__name__
        if getattr(error,"status",None) is not None:
            detail += f"; Discord HTTP {error.status}, code {getattr(error,'code','unknown')}"
    return f"Read-only check failed while {stage}.\n{detail[:600]}\nNo roles, applications, posts or Sheet cells changed."


def configure(discord,app_commands,client,store,guild_id,public,sheet_action,enabled=False,refresh_clans=None):
    async def db(callback):
        return await asyncio.to_thread(store.run,callback)

    def server():
        guild = client.get_guild(guild_id)
        if guild is None:
            raise ValueError("Configured Discord server unavailable.")
        return guild

    def escape(value):
        return discord.utils.escape_mentions(discord.utils.escape_markdown(str(value)))

    class Roles:
        async def actor(self,identifier):
            member = await server().fetch_member(int(identifier))
            return member.guild_permissions.administrator,{role.id for role in member.roles}

        async def member(self,identifier):
            member = await server().fetch_member(int(identifier))
            return {"id":str(member.id),"name":member.display_name,"username":member.name,"roles":{role.id for role in member.roles},"bot":member.bot}

        async def roster(self):
            members = [{"id":str(member.id),"name":member.display_name,"username":member.name,"roles":{role.id for role in member.roles},"bot":member.bot}
                       async for member in server().fetch_members(limit=None)]
            if not members:
                raise ValueError("Empty/incomplete Discord roster; no capacity or Sheet decision made.")
            return members

        async def preflight(self,identifier,role_ids):
            bot = await server().fetch_member(client.user.id)
            target = await server().fetch_member(int(identifier)) if identifier is not None else None
            if not bot.guild_permissions.manage_roles:
                raise ValueError("Bot needs Manage Roles.")
            if role_ids and target is not None and (target.id == server().owner_id or target.top_role >= bot.top_role):
                raise ValueError("Discord hierarchy prevents updating this member's roles.")
            roles = {role.id:role for role in await server().fetch_roles()}
            for identifier in role_ids:
                role = roles.get(identifier)
                if not role or role.managed or role.is_default() or role >= bot.top_role:
                    raise ValueError(f"Role {identifier} is missing, managed or above the bot.")
                if any(getattr(role.permissions,key,False) for key in ("administrator","manage_roles","manage_guild","manage_channels","ban_members","kick_members")):
                    raise ValueError(f"Role {identifier} grants staff powers; review before automated assignment.")

        async def apply(self,identifier,desired):
            member = await server().fetch_member(int(identifier))
            current = {role.id for role in member.roles}
            async def remove():
                for role in desired["remove"]:
                    if role in current:
                        await member.remove_roles(discord.Object(id=role),atomic=True,reason="TAE clan/training update")
            async def add():
                for role in desired["add"]:
                    if role not in current:
                        await member.add_roles(discord.Object(id=role),atomic=True,reason="TAE clan/training update")
            if desired.get("remove_first"):
                await remove()
                await add()
            else:
                await add()
                actual = (await self.member(identifier))["roles"]
                if not set(desired["add"]).issubset(actual):
                    raise ValueError("Destination role not verified; previous clan roles preserved.")
                await remove()

    roles = Roles()
    workflow = Workflow(store,roles,guild_id,enabled)

    async def trainer(interaction):
        if interaction.guild_id != guild_id:
            raise ValueError("Use the configured Discord server.")
        admin,held = await roles.actor(interaction.user.id)
        if not policy.trainer_allowed(admin,held):
            raise ValueError("Only administrators, Clan Leaders, Seconds and Combat Advisors can use this command.")
        return admin,held

    async def destination(identifier,clan=None):
        channel = await client.fetch_channel(identifier)
        if not isinstance(channel,discord.TextChannel) or channel.guild.id != guild_id:
            raise ValueError("Destination must be a text channel in this server.")
        me = await channel.guild.fetch_member(client.user.id)
        access = channel.permissions_for(me)
        if not access.view_channel or not access.send_messages or not access.embed_links:
            raise ValueError("Bot needs View Channel, Send Messages and Embed Links in the destination.")
        if clan:
            role = discord.utils.get(await server().fetch_roles(),id=policy.CLANS[clan]["role"])
            if role is None or not channel.permissions_for(role).view_channel or channel.permissions_for(channel.guild.default_role).view_channel:
                raise ValueError("Barracks must be visible to its clan, not @everyone. Review channel access before applying.")
        return channel

    async def failure(interaction,error):
        text = str(error) if isinstance(error,ValueError) else "Action was not confirmed. Inspect clan/training status and receipts before retrying; partial role/post changes are not blindly repeated."
        if interaction.response.is_done():
            await interaction.followup.send(escape(text)[:1900],ephemeral=True,allowed_mentions=discord.AllowedMentions.none())
        else:
            await interaction.response.send_message(escape(text)[:1900],ephemeral=True,allowed_mentions=discord.AllowedMentions.none())

    async def sheet_refresh(initialize=False,actor=None):
        async with workflow.lock:
            members = await roles.roster()
            def synchronize(connection,google):
                plans = personnel_sheets.prepare(connection,google,guild_id,members)
                if initialize:
                    personnel_sheets.require_preview(connection,guild_id,actor,plans)
                return personnel_sheets.apply(connection,google,plans,initialize)
            return await asyncio.to_thread(sheet_action,synchronize,True)

    async def after_change():
        notes = []
        try:
            if refresh_clans:
                await refresh_clans()
        except Exception:
            notes.append("Attendance clan grouping refresh pending.")
        try:
            await sheet_refresh()
        except Exception:
            notes.append("Roster/training Sheet refresh pending; staff can preview with /tae-maintenance roster-sync.")
        return " ".join(notes)

    async def update_clan_post(identifier,message=None):
        row = await db(lambda connection: policy.clan_request(connection,identifier,guild_id))
        if row["status"] not in ("approved","denied") or not row["message"]:
            return
        channel = await destination(policy.CLANS[row["clan"]]["channel"],row["clan"])
        message = message or await channel.fetch_message(int(row["message"]))
        if str(message.id) != row["message"] or message.author.id != client.user.id:
            raise ValueError("Clan decision post could not be matched.")
        content = f"{'Accepted' if row['status']=='approved' else 'Denied'} by <@{row['reviewer']}>."
        if row["reason"]:
            content += "\nReason: " + escape(row["reason"])
        await message.edit(content=content,view=None,allowed_mentions=discord.AllowedMentions.none())

    async def decide(interaction,identifier,accept,reason=None,message=None):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            row = await db(lambda connection: policy.clan_request(connection,identifier,guild_id))
            await destination(policy.CLANS[row["clan"]]["channel"],row["clan"])
            if accept:
                name = await workflow.approve(interaction.user.id,identifier)
                text = f"Accepted into {name}; destination role verified and previous clan/Freelancer roles removed. " + await after_change()
            else:
                await workflow.deny(interaction.user.id,identifier,reason or "")
                text = "Application denied; no roles changed."
            try:
                await update_clan_post(identifier,message)
            except Exception:
                text += " Decision saved, but barracks post update was not confirmed."
            await interaction.followup.send(text[:1900],ephemeral=True,allowed_mentions=discord.AllowedMentions.none())
        except Exception as error:
            await failure(interaction,error)

    async def resolve_button(interaction):
        if interaction.guild_id != guild_id or not interaction.message or interaction.message.author.id != client.user.id:
            raise ValueError("Unrecognized clan application post.")
        found = await db(lambda connection: connection.execute("SELECT id,clan FROM clan_requests WHERE guild=? AND message=?",(str(guild_id),str(interaction.message.id))).fetchone())
        if not found or interaction.channel_id != policy.CLANS[found[1]]["channel"]:
            raise ValueError("This post does not match a stored clan application.")
        await workflow.clan_authorize(interaction.user.id,found[1])
        return found[0]

    class Denial(discord.ui.Modal):
        def __init__(self,identifier,actor,message):
            super().__init__(title="Deny clan application",timeout=600)
            self.identifier,self.actor,self.message = identifier,actor,message
            self.reason = discord.ui.TextInput(label="Reason (visible to the clan)",style=discord.TextStyle.paragraph,min_length=1,max_length=800)
            self.add_item(self.reason)

        async def on_submit(self,interaction):
            if interaction.user.id != self.actor:
                await failure(interaction,ValueError("This form belongs to another reviewer."))
                return
            await decide(interaction,self.identifier,False,self.reason.value,self.message)

    class Reviews(discord.ui.View):
        def __init__(self):
            super().__init__(timeout=None)

        @discord.ui.button(label="Accept",style=discord.ButtonStyle.success,custom_id="tae:clan:accept:v1")
        async def accept(self,interaction: discord.Interaction,button: discord.ui.Button):
            try:
                identifier = await resolve_button(interaction)
                await decide(interaction,identifier,True,message=interaction.message)
            except Exception as error:
                await failure(interaction,error)

        @discord.ui.button(label="Deny",style=discord.ButtonStyle.danger,custom_id="tae:clan:deny:v1")
        async def deny(self,interaction: discord.Interaction,button: discord.ui.Button):
            try:
                identifier = await resolve_button(interaction)
                await interaction.response.send_modal(Denial(identifier,interaction.user.id,interaction.message))
            except Exception as error:
                await failure(interaction,error)

    class Application(discord.ui.Modal):
        def __init__(self,member,clan):
            super().__init__(title=f"Apply to {policy.CLANS[clan]['name']} (clan-visible)",timeout=600)
            self.member,self.clan = member,clan
            self.why = discord.ui.TextInput(label="Why do you want to join?",style=discord.TextStyle.paragraph,
                placeholder="The entire clan will see this application and your answer.",min_length=1,max_length=1800)
            self.add_item(self.why)

        async def on_submit(self,interaction):
            await interaction.response.defer(ephemeral=True,thinking=True)
            try:
                workflow.require_enabled()
                if interaction.user.id != self.member:
                    raise ValueError("This application belongs to another member.")
                member = await roles.member(self.member)
                if member["bot"] or policy.HOUSE not in member["roles"]:
                    raise ValueError("Only House Karr members can apply to clans.")
                if policy.CLANS[self.clan]["role"] in member["roles"]:
                    raise ValueError("You already belong to that group.")
                channel = await destination(policy.CLANS[self.clan]["channel"],self.clan)
                identifier = await db(lambda connection: policy.submit_clan(connection,interaction.id,guild_id,self.member,self.clan,self.why.value))
                def reserve(connection):
                    with connection:
                        connection.execute("UPDATE clan_requests SET delivery='sending' WHERE id=?",(identifier,))
                await db(reserve)
                try:
                    embed = discord.Embed(title=f"{policy.CLANS[self.clan]['name']} application",description=f"Applicant: <@{self.member}>\nApplication ID: {identifier}\nVisible to the entire clan.")
                    text = escape(self.why.value)
                    for offset in range(0,len(text),950):
                        embed.add_field(name="Why they want to join" if not offset else "Continued",value=text[offset:offset+950],inline=False)
                    message = await channel.send(embed=embed,view=Reviews(),allowed_mentions=discord.AllowedMentions.none())
                except BaseException:
                    def uncertain(connection):
                        with connection:
                            connection.execute("UPDATE clan_requests SET delivery='uncertain' WHERE id=?",(identifier,))
                    await db(uncertain)
                    raise
                def delivered(connection):
                    with connection:
                        connection.execute("UPDATE clan_requests SET delivery='sent',message=? WHERE id=?",(str(message.id),identifier))
                await db(delivered)
                await interaction.followup.send("Submitted to the barracks. The entire clan can read your application; no roles changed yet.",ephemeral=True)
            except Exception as error:
                await failure(interaction,error)

    class ClanChoice(discord.ui.View):
        def __init__(self,member):
            super().__init__(timeout=300)
            self.member = member
            select = discord.ui.Select(placeholder="Which clan/flight would you like to join?",
                options=[discord.SelectOption(label=clan["name"],value=key) for key,clan in policy.CLANS.items()])
            async def choose(interaction):
                if interaction.user.id != self.member:
                    await failure(interaction,ValueError("Open your own clan application."))
                    return
                await interaction.response.send_modal(Application(self.member,select.values[0]))
            select.callback = choose
            self.add_item(select)

    @public.command(name="transfer",description="Administrators: transfer a member; clan changes clear Clan Leader/2IC; reason required")
    @app_commands.choices(destination=[app_commands.Choice(name=config["name"],value=key) for key,config in policy.CLANS.items()]
                          + [app_commands.Choice(name="Freelancers",value="freelancers")])
    async def transfer(interaction: discord.Interaction,member: discord.Member,destination: str,reason: str):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            result = await workflow.transfer(interaction.user.id,member.id,destination,reason)
            notes = await after_change()
            await interaction.followup.send(result + (" " + notes if notes else " Roster updated automatically."),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    @public.command(name="clan-apply",description="Apply to Acklay, Rook or Shyyyo; the entire destination clan will see your answer")
    @app_commands.checks.cooldown(1,60,key=lambda interaction: interaction.user.id)
    async def clan_apply(interaction: discord.Interaction):
        try:
            workflow.require_enabled()
            member = await roles.member(interaction.user.id)
            if policy.HOUSE not in member["roles"] or member["bot"]:
                raise ValueError("Only House Karr members may apply.")
            await interaction.response.send_message("Your application and answer will be visible to the ENTIRE destination clan. Select a group to continue.",view=ClanChoice(interaction.user.id),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    @public.command(name="clan-review",description="Administrators/own-clan leaders: decide a stored clan application by ID")
    async def clan_review(interaction: discord.Interaction,application_id: str,accept: bool,reason: str = None):
        if not accept and not reason:
            try:
                row = await db(lambda connection: policy.clan_request(connection,application_id,guild_id))
                await workflow.clan_authorize(interaction.user.id,row["clan"])
                await interaction.response.send_modal(Denial(application_id,interaction.user.id,None))
            except Exception as error:
                await failure(interaction,error)
        else:
            await decide(interaction,application_id,accept,reason)

    @public.command(name="clan-pending",description="Administrators/own-clan leaders: inspect open clan applications and delivery problems")
    async def clan_pending(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            admin,held = await roles.actor(interaction.user.id)
            if not admin and policy.LEADER not in held:
                raise ValueError("Administrator or Clan Leader permission is required.")
            rows = await db(lambda connection: connection.execute("SELECT id,member,clan,status,delivery FROM clan_requests WHERE guild=? AND status IN ('pending','applying','uncertain') ORDER BY updated",(str(guild_id),)).fetchall())
            lines = [f"{identifier} | <@{member}> | {policy.CLANS[clan]['name']} | {status} | delivery {delivery}"
                     for identifier,member,clan,status,delivery in rows if policy.clan_reviewer(admin,held,clan)]
            await interaction.followup.send("\n".join(lines[:15]) or "No pending applications for your groups.",ephemeral=True,allowed_mentions=discord.AllowedMentions.none())
        except Exception as error:
            await failure(interaction,error)

    async def training_notice(event_id,member,certified,primaries):
        channel = await destination(policy.PLANNING_CHANNEL)
        event = await db(lambda connection: connection.execute("SELECT actor,utc FROM clan_training_audit WHERE id=?",(event_id,)).fetchone())
        def reserve(connection):
            with connection:
                changed = connection.execute("UPDATE clan_training_audit SET delivery='sending' WHERE id=? AND delivery='pending'",(event_id,)).rowcount
                if changed != 1:
                    raise ValueError("Training notice is already sent or uncertain; no duplicate posted.")
        await db(reserve)
        try:
            summary = lambda keys: ", ".join(policy.SPECIALIZATIONS[key][0] for key in sorted(keys)) or "None"
            message = await channel.send(f"Training updated for <@{member}> by <@{event[0]}>.\nPrimary: {summary(primaries)}\nCertified: {summary(certified)}\nRecord: {event_id}",allowed_mentions=discord.AllowedMentions.none())
        except BaseException:
            def uncertain(connection):
                with connection:
                    connection.execute("UPDATE clan_training_audit SET delivery='uncertain' WHERE id=?",(event_id,))
            await db(uncertain)
            raise
        def delivered(connection):
            with connection:
                connection.execute("UPDATE clan_training_audit SET delivery='sent',message=? WHERE id=?",(str(message.id),event_id))
        await db(delivered)

    class TrainingEditor(discord.ui.View):
        def __init__(self,actor,member,record):
            super().__init__(timeout=900)
            self.actor,self.member,self.revision = actor,member,record["revision"]
            self.certified,self.primaries = set(record["certified"]),set(record["primaries"])
            for field,title in [("certified","Certified specializations (unlimited)"),("primaries","Primary specializations (maximum 9 points)")]:
                select = discord.ui.Select(placeholder=title,min_values=0,max_values=len(policy.SPECIALIZATIONS),
                    options=[discord.SelectOption(label=f"{name} ({cost} pts)",value=key,default=key in getattr(self,field))
                             for key,(name,cost,role) in policy.SPECIALIZATIONS.items()])
                async def choose(interaction,field=field,select=select):
                    if interaction.user.id != self.actor:
                        await failure(interaction,ValueError("This editor belongs to another trainer."))
                        return
                    setattr(self,field,set(select.values))
                    for option in select.options:
                        option.default = option.value in getattr(self,field)
                    points = sum(policy.SPECIALIZATIONS[key][1] for key in self.primaries)
                    await interaction.response.edit_message(content=f"Editing <@{self.member}>. Primary points: {points}/9. Every primary must be certified. Changes are not applied until Save. Pilot changes require an administrator or Shyyyo Clan Leader.",view=self)
                select.callback = choose
                self.add_item(select)

        @discord.ui.button(label="Save training",style=discord.ButtonStyle.success,row=2)
        async def save(self,interaction: discord.Interaction,button: discord.ui.Button):
            await interaction.response.defer(ephemeral=True,thinking=True)
            try:
                if interaction.user.id != self.actor:
                    raise ValueError("This editor belongs to another trainer.")
                await trainer(interaction)
                await destination(policy.PLANNING_CHANNEL)
                event_id = await workflow.save_training(self.actor,self.member,self.certified,self.primaries,self.revision)
                self.stop()
                notes = ["Training saved; Discord has primary roles only. Certifications remain in the tracker."]
                try:
                    await training_notice(event_id,self.member,self.certified,self.primaries)
                except Exception:
                    notes.append("Operation-planning notice pending/uncertain; inspect training status before retrying.")
                notes.append(await after_change())
                await interaction.followup.send(" ".join(notes),ephemeral=True)
            except Exception as error:
                await failure(interaction,error)

    training = app_commands.Group(name="training",description="Training records and primary roles; authorized trainers only")

    @training.command(name="edit",description="Authorized trainers: edit certifications and primary specializations")
    async def training_edit(interaction: discord.Interaction,member: discord.Member):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            workflow.require_enabled()
            await trainer(interaction)
            current = await roles.member(member.id)
            if current["bot"] or policy.HOUSE not in current["roles"]:
                raise ValueError("Choose a human House Karr member.")
            record = await db(lambda connection: policy.training_record(connection,guild_id,member.id))
            first = record is None
            if first:
                primary = [key for key,value in policy.SPECIALIZATIONS.items() if value[2] in current["roles"]]
                record = {"revision":0,"certified":primary,"primaries":primary}
            text = "Select certifications and primaries, then Save. Discord receives primary roles only; primary point limit is 9 inclusive."
            if first:
                text += " FIRST RECORD: existing Discord primary roles are prefilled as certified. Review them and enter any legacy Sheet certifications; the old Specializations tab is not imported automatically."
            legacy = await db(lambda connection: connection.execute("SELECT role_state FROM legacy_training_imports WHERE guild=? AND member=?",(str(guild_id),str(member.id))).fetchone())
            if legacy and legacy[0] == "pending-review":
                text += " LEGACY IMPORT: historical marks are preserved. No roles were changed by import. Review all selections; Save will reconcile Discord primary roles and enforce the 9-point limit."
            await interaction.followup.send(text,view=TrainingEditor(interaction.user.id,member.id,record),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    @training.command(name="status",description="Authorized trainers: inspect a record and outstanding role/post/Sheet receipts")
    async def training_status(interaction: discord.Interaction,member: discord.Member):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            await trainer(interaction)
            def inspect(connection):
                return {"record":policy.training_record(connection,guild_id,member.id),
                        "job":connection.execute("SELECT state FROM training_jobs WHERE guild=? AND member=?",(str(guild_id),str(member.id))).fetchone(),
                        "notices":connection.execute("SELECT id,delivery FROM clan_training_audit WHERE member=? AND action='training-updated' ORDER BY id DESC LIMIT 5",(str(member.id),)).fetchall(),
                        "sheets":connection.execute("SELECT kind,state FROM personnel_sheet_state").fetchall()}
            data = await db(inspect)
            content = json.dumps(data,indent=2)
            await interaction.followup.send(file=discord.File(io.BytesIO(content.encode("utf-8")),filename="training-status.json"),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    @training.command(name="legacy-auto-map",description="Administrators: preview suggested member matches and confirm mappings in one batch")
    async def legacy_auto_map(interaction: discord.Interaction,confirm: bool = False):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            workflow.require_enabled()
            admin,held = await roles.actor(interaction.user.id)
            if not admin:
                raise ValueError("Administrator permission is required for bulk identity mapping.")
            async with workflow.lock:
                members = await roles.roster()
                entries = await asyncio.to_thread(sheet_action,lambda connection,google: legacy_training.fetch(google))
                prepared = await db(lambda connection: legacy_training.suggestions(connection,guild_id,entries,members))
                if confirm:
                    count = await db(lambda connection: legacy_training.apply_suggestions(connection,guild_id,interaction.user.id,prepared))
                    await interaction.followup.send(f"Saved {count} reviewed identity mappings. No qualifications, roles or Sheet cells changed. Run legacy-import again to preview the historical marks with these mappings.",ephemeral=True)
                else:
                    await db(lambda connection: personnel_sheets.remember_preview(connection,guild_id,interaction.user.id,[prepared]))
                    await interaction.followup.send("SUGGESTIONS ONLY. Inspect EVERY old-name to Discord-member pairing in the attachment. Confirming saves ALL proposed mappings, not qualifications or roles. Ambiguous/unmatched rows remain unresolved. Confirm within 15 minutes with legacy-auto-map confirm:True.",
                        file=discord.File(io.BytesIO(json.dumps(prepared,indent=2).encode("utf-8")),filename="legacy-mapping-preview.json"),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    @training.command(name="legacy-map",description="Administrators: explicitly match a historical specialization row to a current member")
    async def legacy_map(interaction: discord.Interaction,legacy_row: app_commands.Range[int,24,1000],member: discord.Member):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            workflow.require_enabled()
            admin,held = await roles.actor(interaction.user.id)
            if not admin:
                raise ValueError("Administrator permission is required for legacy import mappings.")
            entries = await asyncio.to_thread(sheet_action,lambda connection,google: legacy_training.fetch(google))
            entry = next((entry for entry in entries if entry["row"] == legacy_row),None)
            if entry is None:
                raise ValueError("No named historical row at that number.")
            current = await roles.member(member.id)
            await db(lambda connection: legacy_training.bind(connection,guild_id,entry,current))
            await interaction.followup.send(f"Explicitly mapped legacy row {legacy_row} ({escape(entry['name'])}) to <@{member.id}> locally. No qualifications or Discord roles changed. Run legacy-import again to preview.",ephemeral=True,allowed_mentions=discord.AllowedMentions.none())
        except Exception as error:
            await failure(interaction,error)

    @training.command(name="legacy-import",description="Administrators: preview/import old yellow and green Xs as records only; no Discord roles changed")
    async def legacy_import(interaction: discord.Interaction,confirm: bool = False):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            workflow.require_enabled()
            admin,held = await roles.actor(interaction.user.id)
            if not admin:
                raise ValueError("Administrator permission is required for historical imports.")
            async with workflow.lock:
                members = await roles.roster()
                entries = await asyncio.to_thread(sheet_action,lambda connection,google: legacy_training.fetch(google))
                prepared = await db(lambda connection: legacy_training.plan(connection,guild_id,entries,members))
                if confirm:
                    count = await db(lambda connection: legacy_training.apply(connection,guild_id,interaction.user.id,prepared))
                    archived = sum(row["status"] == "confirmed-departure-preserved-in-source" for row in prepared["rows"])
                    await interaction.followup.send(f"Imported {count} active historical training records; {archived} confirmed-departure rows preserved in the local training archive. No Discord roles or source Sheet cells changed. Unmatched/ambiguous rows and existing records were not overwritten. Use training edit and Save to reconcile primary roles, then a NEW roster-sync preview to refresh the managed Sheet.",ephemeral=True)
                else:
                    await db(lambda connection: personnel_sheets.remember_preview(connection,guild_id,interaction.user.id,[prepared]))
                    # Raw grid evidence is retained in the import receipt, not the chat attachment.
                    report = {"rows":[{key:value for key,value in entry.items() if key != "source"} for entry in prepared["rows"]],
                              "roles_changed":False,"source_sheet_changed":False}
                    await interaction.followup.send("PREVIEW ONLY. Ready rows can be imported as records; ambiguous identities need legacy-map. Existing records are preserved. Primary totals above 9 are retained for staff review, never granted automatically. Confirm within 15 minutes with legacy-import confirm:True.",
                        file=discord.File(io.BytesIO(json.dumps(report,indent=2).encode("utf-8")),filename="legacy-training-preview.json"),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    public.add_command(training)

    @public.command(name="roster-sync",description="Authorized trainers: preview or explicitly confirm managed roster and training Sheet writes")
    async def roster_sync(interaction: discord.Interaction,confirm: bool = False):
        await interaction.response.defer(ephemeral=True,thinking=True)
        try:
            workflow.require_enabled()
            await trainer(interaction)
            if confirm:
                text = await sheet_refresh(initialize=True,actor=interaction.user.id)
                await interaction.followup.send(text,ephemeral=True)
            else:
                members = await roles.roster()
                plans = await asyncio.to_thread(sheet_action,lambda connection,google: personnel_sheets.prepare(connection,google,guild_id,members))
                await db(lambda connection: personnel_sheets.remember_preview(connection,guild_id,interaction.user.id,plans))
                summary = {plan["kind"]:{"before":plan["before"],"after":plan["after"]} for plan in plans}
                summary["roster"]["layout_check"] = {"shyyyo_members":"B38:B40; Flight Lead B35",
                    "two_row_shyyyo_heading":plans[0].get("legacy_header_merged",False)}
                await interaction.followup.send("PREVIEW ONLY. Inspect the proposed names/cells before running again with confirm:True. Legacy Specializations and radio frequencies are untouched.",
                    file=discord.File(io.BytesIO(json.dumps(summary,indent=2).encode("utf-8")),filename="roster-training-preview.json"),ephemeral=True)
        except Exception as error:
            await failure(interaction,error)

    @public.command(name="personnel-check",description="Administrators: read-only check of clan/training roles, capacities and destinations")
    async def personnel_check(interaction: discord.Interaction):
        await interaction.response.defer(ephemeral=True,thinking=True)
        stage = "checking your administrator permission"
        try:
            admin,held = await roles.actor(interaction.user.id)
            if not admin:
                raise ValueError("Administrator permission is required for the full setup check.")
            stage = "checking the bot's role permissions and hierarchy"
            await roles.preflight(None,policy.CLAN_ROLES | {policy.FREELANCER} | policy.PRIMARY_ROLES)
            stage = "fetching the complete Discord member list"
            roster = await roles.roster()
            lines = []
            for key,clan in policy.CLANS.items():
                stage = f"checking {clan['name']} barracks ({clan['channel']})"
                await destination(clan["channel"],key)
                count = sum(clan["role"] in entry["roles"] for entry in roster)
                if count > clan["limit"]:
                    raise ValueError(f"{clan['name']} already exceeds its {clan['limit']}-member limit; reconcile before enabling.")
                lines.append(f"{clan['name']}: {count}/{clan['limit']}")
            stage = f"checking operation-planning ({policy.PLANNING_CHANNEL})"
            await destination(policy.PLANNING_CHANNEL)
            lines.append("Checks passed. No role, application, message or Sheet changes made. Feature writes " + ("ENABLED." if enabled else "DISABLED."))
            await interaction.followup.send("\n".join(lines),ephemeral=True)
        except Exception as error:
            await interaction.followup.send(escape(check_error(stage,error)),ephemeral=True,allowed_mentions=discord.AllowedMentions.none())

    client.personnel_review_factory = Reviews
