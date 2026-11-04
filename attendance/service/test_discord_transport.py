from types import SimpleNamespace as NS
import unittest

from discord_transport import Transport
import promotions

DID = 123456789012345678
BOT = 123456789012345679


class Role:
    def __init__(self, identifier, position=0, name="role"):
        self.id, self.position, self.name, self.managed = identifier, position, name, False

    def __ge__(self, other):
        return self.position >= other.position


class Member:
    def __init__(self, identifier, roles, guild):
        self.id, self.roles, self.guild = identifier, roles, guild
        self.bot = identifier == BOT
        self.display_name = "[FD] Character"
        self.guild_permissions = NS(manage_roles=True, manage_nicknames=True)
        self.calls = []

    @property
    def top_role(self):
        return max(self.roles, key=lambda role: role.position)

    async def add_roles(self, role, **kwargs):
        self.calls.append(("add", role.id))
        self.roles.append(self.guild.roles[role.id])

    async def remove_roles(self, role, **kwargs):
        self.calls.append(("remove", role.id))
        self.roles = [item for item in self.roles if item.id != role.id]

    async def edit(self, nick, **kwargs):
        self.calls.append(("nick", nick))
        self.display_name = nick


class Channel:
    def __init__(self, guild):
        self.guild = guild
        self.calls = []

    def permissions_for(self, member):
        return NS(view_channel=True, send_messages=True)

    async def send(self, text, **kwargs):
        self.calls.append((text, kwargs))
        return NS(id=42)


class Mentions:
    def __init__(self, **kwargs):
        self.settings = kwargs

    @classmethod
    def none(cls):
        return cls(everyone=False, roles=False, users=False)


class TransportTests(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.guild = NS(id=promotions.GUILD_ID, owner_id=999)
        self.guild.roles = {rank["role"]: Role(rank["role"], index+1, rank["name"])
                            for index, rank in enumerate(promotions.RANKS)}
        self.guild.roles.update({identifier: Role(identifier, 99, "War Chief") for identifier in promotions.PROTECTED_ROLE_IDS})
        self.guild.roles[111] = Role(111, 0, "Unrelated")
        self.me = Member(BOT, [Role(222, 10)], self.guild)
        self.member = Member(DID, [self.guild.roles[111], self.guild.roles[promotions.RANKS[0]["role"]]], self.guild)

        async def fetch_member(identifier):
            return self.me if identifier == BOT else self.member

        async def fetch_roles():
            return list(self.guild.roles.values())

        self.guild.fetch_member, self.guild.fetch_roles = fetch_member, fetch_roles
        self.channel = Channel(self.guild)

        async def fetch_channel(identifier):
            return self.channel

        self.client = NS(user=NS(id=BOT), get_guild=lambda identifier: self.guild, fetch_channel=fetch_channel)
        self.discord = NS(TextChannel=Channel, Object=lambda **kwargs: NS(**kwargs), AllowedMentions=Mentions,
                          utils=NS(escape_mentions=lambda text: text, escape_markdown=lambda text: text))
        self.transport = Transport(self.discord, self.client, self.guild.id, 123)
        self.plan = {"add_role": promotions.RANKS[1]["role"], "remove_roles": [promotions.RANKS[0]["role"]], "nickname": "[MR] Character"}

    async def test_apply_preserves_unrelated_roles(self):
        await self.transport.preflight()
        before = await self.transport.member(DID)
        await self.transport.apply(str(DID), before, self.plan)
        self.assertEqual({role.id for role in self.member.roles}, {111, promotions.RANKS[1]["role"]})
        self.assertEqual(self.member.display_name, "[MR] Character")

    async def test_missing_permission_stops_preflight(self):
        self.me.guild_permissions.manage_roles = False
        with self.assertRaises(ValueError):
            await self.transport.preflight()
        self.assertEqual(self.member.calls, [])

    async def test_high_role_blocks_changes(self):
        self.member.roles.append(Role(333, 20))
        before = await self.transport.member(DID)
        with self.assertRaises(ValueError):
            await self.transport.apply(str(DID), before, self.plan)
        self.assertEqual(self.member.calls, [])

    async def test_new_appointed_role_between_plan_and_apply_stops_changes(self):
        before = await self.transport.member(DID)
        self.member.roles.append(self.guild.roles[1477486340080799946])
        with self.assertRaises(ValueError):
            await self.transport.apply(str(DID), before, self.plan)
        self.assertEqual(self.member.calls, [])

    async def test_unmanaged_role_plan_is_rejected(self):
        before = await self.transport.member(DID)
        self.plan["remove_roles"] = [111]
        with self.assertRaises(ValueError):
            await self.transport.apply(str(DID), before, self.plan)
        self.assertEqual(self.member.calls, [])

    async def test_announcement_allows_only_target_member_mention(self):
        await self.transport.preflight()
        await self.transport.send("promotion", "Congratulations", str(DID))
        settings = self.channel.calls[-1][1]["allowed_mentions"].settings
        self.assertFalse(settings["everyone"])
        self.assertFalse(settings["roles"])
        self.assertEqual(settings["users"][0].id, DID)


if __name__ == "__main__":
    unittest.main()
