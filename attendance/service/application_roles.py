"""Verified application role provisioning, separate from operation promotions."""
import asyncio
import datetime as dt
import json

import applications
from attendance import UTC


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS application_admissions (
            application_id TEXT PRIMARY KEY, actor_id TEXT NOT NULL,
            plan_json TEXT NOT NULL, state TEXT NOT NULL, updated_utc TEXT NOT NULL
        );
    """)


def plan(category,answers):
    answers = applications.validate_answers(category,answers)
    if category == applications.CATEGORIES[0]:
        roles = set(applications.ACTIVE_ROLES)
        if answers["record"] == "yes":
            roles.add(applications.STREAMER_ROLE)
    elif category == applications.CATEGORIES[1]:
        roles = {applications.LIAISON_ROLE}
    else:
        roles = {applications.FRIEND_ROLE}
    return {"add_roles":sorted(roles),"remove_role":applications.UNASSIGNED_ROLE}


class Admissions:
    def __init__(self,store,transport,enabled=False,onboard=None):
        self.store,self.transport,self.enabled = store,transport,enabled
        self.onboard = onboard
        self.lock = asyncio.Lock()

    async def db(self,callback):
        return await asyncio.to_thread(self.store.run,callback)

    async def approve(self,actor,application_id):
        if not self.enabled:
            raise ValueError("Application role assignment is disabled. Staff must complete application-role-check and enable --enable-application-roles first.")
        async with self.lock:
            record = await self.db(lambda db: db.execute("SELECT discord_id,category,answers,status FROM applications WHERE application_id=?",(str(application_id),)).fetchone())
            if not record or record[3] != "pending":
                raise ValueError("Application is no longer pending.")
            job = await self.db(lambda db: db.execute("SELECT plan_json,state FROM application_admissions WHERE application_id=?",(str(application_id),)).fetchone())
            desired = json.loads(job[0]) if job else plan(record[1],json.loads(record[2]))
            current = await self.transport.current(record[0])
            complete = set(desired["add_roles"]).issubset(current) and desired["remove_role"] not in current
            if job:
                if not complete:
                    raise ValueError("Earlier role changes need staff reconciliation; they will not be blindly repeated. Unassigned may remain until all required roles are verified.")
            else:
                if applications.UNASSIGNED_ROLE not in current:
                    raise ValueError("Only members with Unassigned can be accepted through this application workflow.")
                await self.transport.preflight(desired,record[0])
                def reserve(db):
                    with db:
                        db.execute("BEGIN IMMEDIATE")
                        pending = db.execute("SELECT status FROM applications WHERE application_id=?",(str(application_id),)).fetchone()
                        if not pending or pending[0] != "pending":
                            raise ValueError("Another reviewer already decided this application.")
                        db.execute("INSERT INTO application_admissions VALUES (?,?,?,'applying',?)",
                            (str(application_id),str(actor),json.dumps(desired),dt.datetime.now(UTC).isoformat()))
                await self.db(reserve)
                try:
                    await self.transport.apply(record[0],desired)
                    actual = await self.transport.current(record[0])
                    if not set(desired["add_roles"]).issubset(actual) or desired["remove_role"] in actual:
                        raise ValueError("Role assignment could not be fully verified.")
                except BaseException:
                    await self.db(lambda db: self.set_state(db,application_id,"uncertain"))
                    raise
            await self.db(lambda db: self.set_state(db,application_id,"applied"))
            onboarding_result = ""
            if self.onboard and record[1] == applications.CATEGORIES[0]:
                onboarding_result = await self.onboard(application_id,record[0],json.loads(record[2]))
            result = await self.db(lambda db: applications.review(db,actor,application_id,True))
            if onboarding_result:
                return "Accepted: required roles verified and Unassigned removed. " + onboarding_result
            return "Accepted: required roles verified and Unassigned removed. " + result

    @staticmethod
    def set_state(db,application_id,state):
        with db:
            db.execute("UPDATE application_admissions SET state=?,updated_utc=? WHERE application_id=?",
                       (state,dt.datetime.now(UTC).isoformat(),str(application_id)))


class DiscordRoles:
    def __init__(self,discord,client,guild_id):
        self.discord,self.client,self.guild_id = discord,client,guild_id

    def guild(self):
        guild = self.client.get_guild(self.guild_id)
        if guild is None:
            raise ValueError("Configured Discord server unavailable.")
        return guild

    async def current(self,discord_id):
        member = await self.guild().fetch_member(int(discord_id))
        if member.bot:
            raise ValueError("Bot accounts cannot apply.")
        return {role.id for role in member.roles}

    async def preflight(self,desired,discord_id=None):
        guild = self.guild()
        me = await guild.fetch_member(self.client.user.id)
        if not me.guild_permissions.manage_roles:
            raise ValueError("The bot needs Manage Roles, not Administrator.")
        roles = {role.id:role for role in await guild.fetch_roles()}
        for identifier in set(desired["add_roles"]) | {desired["remove_role"]}:
            role = roles.get(identifier)
            if not role or role.managed or role.is_default() or role >= me.top_role:
                raise ValueError(f"Application role {identifier} is missing, managed or above the bot. No assignment started.")
            if identifier != applications.UNASSIGNED_ROLE:
                risky = ("administrator","manage_guild","manage_roles","manage_channels","kick_members","ban_members")
                if any(getattr(role.permissions,name,False) for name in risky):
                    raise ValueError(f"Application role {identifier} grants staff powers. Review its ID/permissions before automatic assignment.")
        if discord_id:
            member = await guild.fetch_member(int(discord_id))
            if member.id == guild.owner_id or member.top_role >= me.top_role:
                raise ValueError("Discord hierarchy prevents assigning roles to this member.")

    async def apply(self,discord_id,desired):
        await self.preflight(desired,discord_id)
        before = await self.current(discord_id)
        if applications.UNASSIGNED_ROLE not in before:
            raise ValueError("Unassigned changed before role assignment. Review required.")
        member = await self.guild().fetch_member(int(discord_id))
        for role in desired["add_roles"]:
            if role not in before:
                await member.add_roles(self.discord.Object(id=role),atomic=True,reason="TAE application accepted")
        after_add = await self.current(discord_id)
        if not set(desired["add_roles"]).issubset(after_add):
            raise ValueError("Required roles not verified; Unassigned was not removed.")
        if applications.UNASSIGNED_ROLE in after_add:
            await member.remove_roles(self.discord.Object(id=applications.UNASSIGNED_ROLE),atomic=True,reason="TAE application accepted; destination roles verified")
