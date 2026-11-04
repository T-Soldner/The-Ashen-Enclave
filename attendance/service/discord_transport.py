"""Discord mutation boundary. Only constructed for the explicitly enabled workflow."""
import promotions


class Transport:
    def __init__(self, discord, client, guild_id, recap_channel_id, protected_roles=()):
        self.discord, self.client = discord, client
        self.guild_id, self.recap_channel_id = guild_id, recap_channel_id
        self.protected_roles = protected_roles
        self.channels = {}
        self.reconcile_loas = None

    def guild(self):
        guild = self.client.get_guild(self.guild_id)
        if guild is None:
            raise ValueError("Configured server is not available to the bot.")
        return guild

    async def preflight(self):
        guild = self.guild()
        me = await guild.fetch_member(self.client.user.id)
        if not me.guild_permissions.manage_roles or not me.guild_permissions.manage_nicknames:
            raise ValueError("Live mode needs Manage Roles and Manage Nicknames, not Administrator.")
        roles = {role.id: role for role in await guild.fetch_roles()}
        for rank in promotions.RANKS:
            role = roles.get(rank["role"])
            if role is None or role.managed or role >= me.top_role:
                raise ValueError("Every managed progression role must exist, be editable, and sit below the bot's highest role.")
        if not promotions.PROTECTED_ROLE_IDS.issubset(roles):
            raise ValueError("Protected appointed rank roles were not found; refusing live processing.")
        for kind, channel_id in (("promotion", promotions.ANNOUNCEMENTS_CHANNEL), ("recap", self.recap_channel_id)):
            channel = await self.client.fetch_channel(channel_id)
            if not isinstance(channel, self.discord.TextChannel) or channel.guild.id != self.guild_id:
                raise ValueError("Workflow channels must belong to the configured Discord server.")
            permissions = channel.permissions_for(me)
            if not permissions.view_channel or not permissions.send_messages:
                raise ValueError("Bot needs View Channel and Send Messages in announcements and bot-spam.")
            self.channels[kind] = channel
        self.channels['absence'] = self.channels['recap']

    async def member(self, discord_id):
        guild = self.guild()
        member = await guild.fetch_member(int(discord_id))
        roles = [role.id for role in member.roles]
        names = [role.name for role in member.roles]
        return {"id": str(member.id), "nickname": member.display_name,
                "roles": roles, "role_names": names,
                "protected": member.bot or member.id == guild.owner_id or promotions.is_protected(
                    member.id, member.display_name, roles, names, self.protected_roles)}

    async def check_promotion(self, current, plan):
        if current["protected"]:
            raise ValueError("Protected member.")
        me = await self.guild().fetch_member(self.client.user.id)
        target = await self.guild().fetch_member(int(current["id"]))
        if target.top_role >= me.top_role:
            raise ValueError("Member hierarchy prevents a nickname/role update.")
        managed = {rank["role"] for rank in promotions.RANKS}
        if plan["add_role"] not in managed or not set(plan["remove_roles"]).issubset(managed):
            raise ValueError("Refusing to mutate an unmanaged role.")

    async def apply(self, discord_id, previous, plan):
        current = await self.member(discord_id)
        if current["protected"] or current["nickname"] != previous["nickname"] or set(current["roles"]) != set(previous["roles"]):
            raise ValueError("Member changed since planning; staff review required.")
        await self.check_promotion(current, plan)
        member = await self.guild().fetch_member(int(discord_id))
        reason = "TAE finalized operation attendance promotion"
        # Per-role endpoints preserve unrelated roles, including concurrently added roles.
        await member.add_roles(self.discord.Object(id=plan["add_role"]), reason=reason, atomic=True)
        for role in plan["remove_roles"]:
            await member.remove_roles(self.discord.Object(id=role), reason=reason, atomic=True)
        await member.edit(nick=plan["nickname"], reason=reason)
        after = await self.member(discord_id)
        managed = {rank["role"] for rank in promotions.RANKS}
        if (after["protected"] or set(after["roles"]).intersection(managed) != {plan["add_role"]}
                or after["nickname"] != plan["nickname"]
                or not (set(previous["roles"]) - managed).issubset(after["roles"])):
            raise ValueError("Could not verify the entire promotion; do not announce success.")

    async def send(self, kind, text, mention_id=None):
        channel = self.channels[kind]
        if mention_id:
            mentions = self.discord.AllowedMentions(everyone=False, roles=False,
                users=[self.discord.Object(id=int(mention_id))], replied_user=False)
        else:
            mentions = self.discord.AllowedMentions.none()
            text = self.discord.utils.escape_mentions(self.discord.utils.escape_markdown(text))
        message = await channel.send(text, allowed_mentions=mentions)
        return message.id
