"""Persistent staff queue buttons and short-lived, explicit identity previews."""
import asyncio

import clan_training as policy
import link_queue as queue
import sheets_sync


def configure(discord, client, store, guild_id, channel_id, sheet_action, refresh_clans):
    lock = asyncio.Lock()

    async def db(callback):
        return await asyncio.to_thread(store.run,callback)

    async def administrator(interaction):
        if interaction.guild_id != guild_id:
            raise ValueError("Use the configured Discord server.")
        member = await interaction.guild.fetch_member(interaction.user.id)
        if not member.guild_permissions.administrator:
            raise ValueError("Only Discord administrators can approve identity links.")

    async def member_data(identifier):
        person = await client.get_guild(guild_id).fetch_member(int(identifier))
        return dict(id=str(person.id),name=person.display_name,roles={r.id for r in person.roles},bot=person.bot)

    async def failure(interaction,error):
        text = str(error) if isinstance(error,ValueError) else "Link action failed or is uncertain. Inspect the queue receipt before retrying."
        await interaction.followup.send(discord.utils.escape_mentions(discord.utils.escape_markdown(text))[:1900],
                                        ephemeral=True,allowed_mentions=discord.AllowedMentions.none())

    async def pending_steam(interaction):
        row = await db(lambda connection: connection.execute("SELECT steam_id FROM detected_links WHERE message=? AND state='pending'",
                                                               (str(interaction.message.id),)).fetchone())
        if not row:
            raise ValueError("This detection is no longer pending. No changes made.")
        return row[0]

    class Confirm(discord.ui.View):
        def __init__(self,payload,actor):
            super().__init__(timeout=600)
            self.payload,self.actor = payload,actor

        @discord.ui.button(label="Approve link",style=discord.ButtonStyle.success)
        async def approve(self,interaction,button):
            await interaction.response.defer(ephemeral=True,thinking=True)
            try:
                await administrator(interaction)
                if interaction.user.id != self.actor:
                    raise ValueError("Open your own review before approving.")
                async with lock:
                    member = await member_data(self.payload["discord"])
                    result = await asyncio.to_thread(sheet_action,lambda connection,google:
                        queue.approve(connection,google,self.payload,interaction.user.id,member),True)
                    try:
                        await asyncio.to_thread(sheet_action,lambda connection,google:
                            sheets_sync.export(connection,google,guild_id,enabled=True),True)
                        await refresh_clans()
                        result += " Spreadsheet refreshed automatically."
                    except Exception:
                        result += " Link saved; spreadsheet refresh needs review. Existing links were not repeated."
                button.disabled = True
                await interaction.edit_original_response(content=result,view=None)
            except Exception as error:
                await failure(interaction,error)

    class RowModal(discord.ui.Modal,title="Review attendance link"):
        row = discord.ui.TextInput(label="Existing tracker row (optional)",placeholder="Leave blank to match the member name",required=False,max_length=4)

        def __init__(self,steam,member,actor):
            super().__init__()
            self.steam,self.member,self.actor = steam,member,actor

        async def on_submit(self,interaction):
            await interaction.response.defer(ephemeral=True,thinking=True)
            try:
                await administrator(interaction)
                if interaction.user.id != self.actor:
                    raise ValueError("Open your own review.")
                row = str(self.row.value).strip()
                if row and (not row.isdecimal() or not 2 <= int(row) <= 1000):
                    raise ValueError("Use the existing master tracker row number, 2-1000.")
                member = await member_data(self.member)
                payload = await asyncio.to_thread(sheet_action,lambda connection,google:
                    queue.plan(connection,google,self.steam,member,int(row) if row else None))
                action = "CREATE A NEW ZERO-TOTAL ROW. If this is an existing member, stop and supply their old row." if payload["create"] else "Preserve the existing tracker row and total."
                label = discord.utils.escape_mentions(discord.utils.escape_markdown(payload["label"]))
                await interaction.followup.send(f"Verify identity before approval; names are suggestions, not proof.\nSteamID64: {self.steam}\nDiscord member: <@{payload['discord']}>\nTracker row: {payload['row']} ({label})\nStarting total: {payload['baseline']}\nCounting starts: {payload['since']} (Eastern). No earlier operations added.\n{action}",
                    ephemeral=True,view=Confirm(payload,interaction.user.id),allowed_mentions=discord.AllowedMentions.none())
            except Exception as error:
                await failure(interaction,error)

    class Choose(discord.ui.View):
        def __init__(self,steam,actor,suggested=None):
            super().__init__(timeout=600)
            self.steam,self.actor,self.member = steam,actor,suggested

        @discord.ui.select(cls=discord.ui.UserSelect,placeholder="Choose the correct Discord member",min_values=1,max_values=1)
        async def choose(self,interaction,select):
            if interaction.user.id != self.actor:
                await interaction.response.send_message("Open your own review.",ephemeral=True)
                return
            self.member = str(select.values[0].id)
            await interaction.response.send_message("Member selected. Click Preview link to check the existing tracker total.",ephemeral=True)

        @discord.ui.button(label="Preview link",style=discord.ButtonStyle.primary)
        async def preview(self,interaction,button):
            try:
                await administrator(interaction)
                if interaction.user.id != self.actor or not self.member:
                    raise ValueError("Choose a Discord member first.")
                await interaction.response.send_modal(RowModal(self.steam,self.member,self.actor))
            except Exception as error:
                if not interaction.response.is_done():
                    await interaction.response.defer(ephemeral=True)
                await failure(interaction,error)

    class Review(discord.ui.View):
        def __init__(self):
            super().__init__(timeout=None)

        @discord.ui.button(label="Review / choose member",style=discord.ButtonStyle.primary,custom_id="tae-link-review-v1")
        async def review(self,interaction,button):
            await interaction.response.defer(ephemeral=True,thinking=True)
            try:
                await administrator(interaction)
                steam = await pending_steam(interaction)
                people = [dict(id=str(m.id),name=m.display_name,roles={r.id for r in m.roles},bot=m.bot)
                          async for m in interaction.guild.fetch_members(limit=None)]
                matches = await db(lambda connection: queue.suggestions(connection,steam,people))
                suggestion = str(matches[0]["id"]) if len(matches) == 1 else None
                text = f"Suggested member: <@{suggestion}>. Verify before approval, or select someone else." if suggestion else "No unique match. Choose the correct House Karr member."
                await interaction.followup.send(text,ephemeral=True,view=Choose(steam,interaction.user.id,suggestion),allowed_mentions=discord.AllowedMentions.none())
            except Exception as error:
                await failure(interaction,error)

        @discord.ui.button(label="Dismiss",style=discord.ButtonStyle.secondary,custom_id="tae-link-dismiss-v1")
        async def dismiss(self,interaction,button):
            await interaction.response.defer(ephemeral=True,thinking=True)
            try:
                await administrator(interaction)
                steam = await pending_steam(interaction)
                def dismiss(connection):
                    with connection:
                        connection.execute("UPDATE detected_links SET state='dismissed' WHERE steam_id=? AND state='pending'",(steam,))
                await db(dismiss)
                await interaction.followup.send("Detection dismissed. No account, role or Sheet changes.",ephemeral=True)
            except Exception as error:
                await failure(interaction,error)

    async def poll():
        await client.wait_until_ready()
        while not client.is_closed():
            try:
                channel = await client.fetch_channel(channel_id)
                if not isinstance(channel,discord.TextChannel) or channel.guild.id != guild_id:
                    raise ValueError("Link queue requires a text channel in the configured server.")
                permissions = channel.permissions_for(channel.guild.me)
                if channel.permissions_for(channel.guild.default_role).view_channel or not (permissions.view_channel and permissions.send_messages):
                    raise ValueError("Link queue must be staff-only and writable by the bot.")
                pending = await db(queue.discover)
                if pending:
                    staff_roles = {policy.LEADER,policy.SECOND,policy.ADVISOR,1477486340101902517}
                    async for member in channel.guild.fetch_members(limit=None):
                        staff = member.guild_permissions.administrator or bool(staff_roles & {r.id for r in member.roles})
                        if not member.bot and not staff and channel.permissions_for(member).view_channel:
                            raise ValueError("Link channel is visible to a non-staff member; no identity posted.")
                for steam,name in pending:
                    def reserve(connection):
                        with connection:
                            return connection.execute("UPDATE detected_links SET delivery='sending' WHERE steam_id=? AND delivery='pending' AND state='pending'",(steam,)).rowcount == 1
                    if not await db(reserve):
                        continue
                    try:
                        label = discord.utils.escape_mentions(discord.utils.escape_markdown(name))
                        message = await channel.send(f"Attendance identity needs approval\nIn-game name: {label}\nSteamID64: {steam}\nNames are not proof of identity. An administrator must review and approve.",view=Review(),allowed_mentions=discord.AllowedMentions.none())
                        def delivered(connection):
                            with connection:
                                connection.execute("UPDATE detected_links SET delivery='sent',message=? WHERE steam_id=?",(str(message.id),steam))
                        await db(delivered)
                    except BaseException:
                        def uncertain(connection):
                            with connection:
                                connection.execute("UPDATE detected_links SET delivery='uncertain' WHERE steam_id=?",(steam,))
                        await db(uncertain)
                        raise
            except asyncio.CancelledError:
                raise
            except Exception:
                print("Attendance link queue needs review: check staff channel access and durable detected_links receipts.",flush=True)
            await asyncio.sleep(60)

    return Review,poll
