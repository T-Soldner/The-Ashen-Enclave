"""Serialized, recoverable Discord role changes for clans and training."""
import asyncio
import json

import clan_training as policy


class Workflow:
    def __init__(self,store,transport,guild,enabled=False):
        self.store,self.transport,self.guild,self.enabled = store,transport,str(guild),enabled
        self.lock = asyncio.Lock()

    async def db(self,callback):
        return await asyncio.to_thread(self.store.run,callback)

    def require_enabled(self):
        if not self.enabled:
            raise ValueError("Clan/training writes are disabled; enable --enable-clan-training after deployment checks.")

    async def clan_authorize(self,actor,clan):
        admin,roles = await self.transport.actor(actor)
        if not policy.clan_reviewer(admin,roles,clan):
            raise ValueError("Only administrators or this clan's Clan Leaders may decide its applications.")

    async def deny(self,actor,identifier,reason):
        self.require_enabled()
        async with self.lock:
            row = await self.db(lambda db: policy.clan_request(db,identifier,self.guild))
            await self.clan_authorize(actor,row["clan"])
            await self.db(lambda db: policy.deny_clan(db,identifier,self.guild,actor,reason))

    async def approve(self,actor,identifier):
        self.require_enabled()
        async with self.lock:
            row = await self.db(lambda db: policy.clan_request(db,identifier,self.guild))
            await self.clan_authorize(actor,row["clan"])
            if row["status"] not in ("pending","applying","uncertain"):
                raise ValueError("Application was already decided.")
            if await self.db(lambda db: db.execute("SELECT 1 FROM clan_transfers WHERE guild=? AND member=? AND state<>'complete'",(self.guild,row["member"])).fetchone()):
                raise ValueError("An administrator transfer needs reconciliation before accepting a clan application.")
            target = policy.CLANS[row["clan"]]
            member = await self.transport.member(row["member"])
            roles = set(member["roles"])
            if member["bot"] or policy.HOUSE not in roles:
                raise ValueError("Applicant must still be a human House Karr member.")
            desired = {"add":[target["role"]],"remove":sorted((policy.CLAN_ROLES | {policy.FREELANCER}) - {target["role"]})}
            complete = target["role"] in roles and not (set(desired["remove"]) & roles)
            if row["plan"]:
                if not complete:
                    raise ValueError("Earlier role changes are uncertain. Staff must reconcile them; no blind retry.")
                roster = await self.transport.roster()
                if sum(target["role"] in entry["roles"] for entry in roster) > target["limit"]:
                    raise ValueError("The clan is over capacity after an external change. Reconcile membership before completing this decision.")
            else:
                if target["role"] in roles:
                    raise ValueError("Applicant already belongs to this group; no duplicate decision saved.")
                if roles & {policy.LEADER,policy.SECOND}:
                    raise ValueError("Leadership duties must be reviewed and removed by an administrator before changing clans; the bot will not transfer leadership authority.")
                # Full fetch, not a partial Discord cache, while holding the acceptance lock.
                roster = await self.transport.roster()
                holders = {str(entry["id"]) for entry in roster if target["role"] in entry["roles"]}
                reserved = await self.db(lambda db: db.execute("SELECT member FROM clan_requests WHERE guild=? AND clan=? AND status IN ('applying','uncertain') AND plan IS NOT NULL AND id<>?",
                    (self.guild,row["clan"],str(identifier))).fetchall())
                reserved_members = {entry[0] for entry in reserved} - holders
                transfers = await self.db(lambda db: db.execute("SELECT member FROM clan_transfers WHERE guild=? AND target=? AND state<>'complete'",(self.guild,row["clan"])).fetchall())
                reserved_members |= {entry[0] for entry in transfers} - holders
                if len(holders) + len(reserved_members) >= target["limit"]:
                    raise ValueError(f"{target['name']} is full or remaining places are reserved by uncertain role updates ({target['limit']} total including leaders).")
                if not any(str(entry["id"]) == row["member"] for entry in roster):
                    raise ValueError("Applicant missing from full roster; no role changes made.")
                await self.transport.preflight(row["member"],set(desired["add"])|set(desired["remove"]))
                def reserve(db):
                    with db:
                        changed = db.execute("UPDATE clan_requests SET status='applying',plan=?,reviewer=?,updated=? WHERE id=? AND status='pending' AND plan IS NULL",
                            (json.dumps(desired),str(actor),policy.now(),str(identifier))).rowcount
                        if changed != 1:
                            raise ValueError("Another decision is already in progress.")
                await self.db(reserve)
                try:
                    await self.clan_authorize(actor,row["clan"])
                    await self.transport.apply(row["member"],desired)
                    actual = set((await self.transport.member(row["member"]))["roles"])
                    if target["role"] not in actual or actual & set(desired["remove"]):
                        raise ValueError("Clan role change was not fully verified.")
                except BaseException:
                    def uncertain(db):
                        with db:
                            db.execute("UPDATE clan_requests SET status='uncertain' WHERE id=?",(str(identifier),))
                    await self.db(uncertain)
                    raise
            def finish(db):
                with db:
                    db.execute("UPDATE clan_requests SET status='approved',reviewer=?,updated=? WHERE id=?",(str(actor),policy.now(),str(identifier)))
                    policy.audit(db,actor,row["member"],"clan-approved",target["name"])
            await self.db(finish)
            return target["name"]

    async def transfer(self,actor,member_id,target,reason):
        """Explicit administrator action only; no attendance or training mutations."""
        self.require_enabled()
        reason = reason.strip()
        if target not in {*policy.CLANS,"freelancers"} or not 1 <= len(reason) <= 800:
            raise ValueError("Choose a valid destination and give a reason of 1-800 characters.")
        member_id = str(member_id)
        async with self.lock:
            admin,_ = await self.transport.actor(actor)
            if not admin:
                raise ValueError("Only Discord administrators can transfer members.")
            member = await self.transport.member(member_id)
            held = set(member["roles"])
            if member["bot"] or policy.HOUSE not in held:
                raise ValueError("Transfers are for human House Karr members.")
            if await self.db(lambda db: db.execute("SELECT 1 FROM clan_requests WHERE guild=? AND member=? AND status IN ('applying','uncertain')",(self.guild,member_id)).fetchone()):
                raise ValueError("An earlier clan application has uncertain role changes. Reconcile it before transferring.")
            destination = policy.FREELANCER if target == "freelancers" else policy.CLANS[target]["role"]
            label = "Freelancers" if target == "freelancers" else policy.CLANS[target]["name"]
            remove = ((policy.CLAN_ROLES | {policy.FREELANCER}) - {destination}) & held
            switching = held & (policy.CLAN_ROLES | {policy.FREELANCER}) != {destination}
            if switching:
                remove |= held & {policy.LEADER,policy.SECOND}
            desired = {"add":[destination] if destination not in held else [],"remove":sorted(remove)}
            payload = dict(target=target,actor=str(actor),reason=reason,roles=desired)
            previous = await self.db(lambda db: db.execute("SELECT target,actor,reason,payload,state FROM clan_transfers WHERE guild=? AND member=?",(self.guild,member_id)).fetchone())
            recovery = previous and previous[4] != "complete"
            if recovery:
                saved = json.loads(previous[3])
                if previous[:3] != (target,str(actor),reason):
                    raise ValueError("An earlier transfer needs reconciliation; use the same destination, reviewer and reason after checking Discord roles.")
                desired = saved["roles"]
                if destination not in held or set(desired["remove"]) & held:
                    raise ValueError("Earlier transfer role changes are uncertain. Reconcile Discord roles; no blind retry.")
            elif not desired["add"] and not desired["remove"]:
                return f"Already in {label}; no roles changed. Leadership roles preserved."

            roster = await self.transport.roster()
            if not any(str(entry["id"]) == member_id for entry in roster):
                raise ValueError("Member missing from full roster; no role changes made.")
            if target != "freelancers":
                holders = {str(entry["id"]) for entry in roster if destination in entry["roles"]}
                applications = await self.db(lambda db: db.execute("SELECT member FROM clan_requests WHERE guild=? AND clan=? AND status IN ('applying','uncertain') AND plan IS NOT NULL",(self.guild,target)).fetchall())
                transfers = await self.db(lambda db: db.execute("SELECT member FROM clan_transfers WHERE guild=? AND target=? AND state<>'complete'",(self.guild,target)).fetchall())
                occupied = holders | {entry[0] for entry in applications + transfers} | {member_id}
                if len(occupied) > policy.CLANS[target]["limit"]:
                    raise ValueError(f"{label} is full or remaining places are reserved. No roles changed.")
            if not recovery:
                await self.transport.preflight(member_id,set(desired["add"])|set(desired["remove"]))
                def reserve(db):
                    with db:
                        db.execute("INSERT OR REPLACE INTO clan_transfers VALUES (?,?,?,?,?,?,'applying')",(self.guild,member_id,target,str(actor),reason,json.dumps(payload)))
                await self.db(reserve)
                try:
                    fresh_admin,_ = await self.transport.actor(actor)
                    if not fresh_admin:
                        raise ValueError("Administrator permission changed before transfer.")
                    await self.transport.apply(member_id,desired)
                    actual = set((await self.transport.member(member_id))["roles"])
                    if destination not in actual or set(desired["remove"]) & actual:
                        raise ValueError("Transfer roles could not be fully verified.")
                except BaseException:
                    def uncertain(db):
                        with db:
                            db.execute("UPDATE clan_transfers SET state='uncertain' WHERE guild=? AND member=?",(self.guild,member_id))
                    await self.db(uncertain)
                    raise
            def finish(db):
                with db:
                    db.execute("UPDATE clan_transfers SET state='complete' WHERE guild=? AND member=?",(self.guild,member_id))
                    db.execute("UPDATE clan_requests SET status='denied',reviewer=?,reason=?,updated=? WHERE guild=? AND member=? AND status='pending'",(str(actor),"Superseded by administrator transfer: "+reason,policy.now(),self.guild,member_id))
                    policy.audit(db,actor,member_id,"admin-clan-transfer",json.dumps(dict(destination=label,reason=reason,roles=desired)))
            await self.db(finish)
            return f"Transferred to {label}. Previous clan/Freelancer and applicable Clan Leader/2IC roles removed. Attendance and qualifications preserved."

    async def save_training(self,actor,member_id,certified,primaries,revision):
        self.require_enabled()
        async with self.lock:
            admin,actor_roles = await self.transport.actor(actor)
            if not policy.trainer_allowed(admin,actor_roles):
                raise ValueError("Administrator, Clan Leader, Second or Combat Advisor permission is required.")
            member = await self.transport.member(member_id)
            if member["bot"] or policy.HOUSE not in member["roles"]:
                raise ValueError("Training records are for human House Karr members.")
            old = await self.db(lambda db: policy.training_record(db,self.guild,member_id))
            if (old["revision"] if old else 0) != revision:
                raise ValueError("Another trainer updated this member. Reopen the editor.")
            actual = set(member["roles"]) & policy.PRIMARY_ROLES
            legacy = await self.db(lambda db: db.execute("SELECT role_state FROM legacy_training_imports WHERE guild=? AND member=?",(self.guild,str(member_id))).fetchone())
            legacy_pending = legacy and legacy[0] == "pending-review"
            # The first explicitly reviewed save adopts current primary roles only;
            # legacy Sheet certifications remain untouched and must be entered by staff.
            old_primary = set(old["primaries"]) if old else {key for key,value in policy.SPECIALIZATIONS.items() if value[2] in actual}
            old_certified = set(old["certified"]) if old else old_primary
            points = policy.validate_training(certified,primaries,old_certified,old_primary,
                                               policy.pilot_allowed(admin,actor_roles))
            changing_pilot_roles = any((policy.SPECIALIZATIONS[key][2] in actual) != (key in primaries) for key in policy.PILOTS)
            if changing_pilot_roles and not policy.pilot_allowed(admin,actor_roles):
                raise ValueError("Only administrators or Shyyyo Clan Leaders may change pilot Discord roles.")
            desired_roles = {policy.SPECIALIZATIONS[key][2] for key in primaries if policy.SPECIALIZATIONS[key][2]}
            expected_roles = {policy.SPECIALIZATIONS[key][2] for key in old_primary if policy.SPECIALIZATIONS[key][2]}
            payload = {"name":member["name"],"certified":sorted(certified),"primaries":sorted(primaries),
                       "actor":str(actor),"revision":revision,"points":points}
            job = await self.db(lambda db: db.execute("SELECT payload,state FROM training_jobs WHERE guild=? AND member=?",(self.guild,str(member_id))).fetchone())
            if job and job[1] != "complete":
                previous = json.loads(job[0])
                if previous != payload or actual != desired_roles:
                    raise ValueError("Earlier training role changes need reconciliation; no blind retry.")
            else:
                if actual != expected_roles and not legacy_pending:
                    raise ValueError("Discord primary roles changed outside the tracker. Staff must reconcile before saving.")
                # Removing obsolete primaries first avoids temporarily granting >9 points.
                desired = {"add":sorted(desired_roles-actual),"remove":sorted(actual-desired_roles),"remove_first":True}
                await self.transport.preflight(member_id,set(desired["add"])|set(desired["remove"]))
                def reserve(db):
                    with db:
                        db.execute("INSERT OR REPLACE INTO training_jobs VALUES (?,?,?,'applying')",(self.guild,str(member_id),json.dumps(payload)))
                await self.db(reserve)
                try:
                    fresh_admin,fresh_roles = await self.transport.actor(actor)
                    if not policy.trainer_allowed(fresh_admin,fresh_roles):
                        raise ValueError("Trainer permissions changed before saving.")
                    policy.validate_training(certified,primaries,old_certified,old_primary,policy.pilot_allowed(fresh_admin,fresh_roles))
                    if changing_pilot_roles and not policy.pilot_allowed(fresh_admin,fresh_roles):
                        raise ValueError("Pilot approval permissions changed before saving.")
                    await self.transport.apply(member_id,desired)
                    if set((await self.transport.member(member_id))["roles"]) & policy.PRIMARY_ROLES != desired_roles:
                        raise ValueError("Primary roles could not be verified.")
                except BaseException:
                    def uncertain(db):
                        with db:
                            db.execute("UPDATE training_jobs SET state='uncertain' WHERE guild=? AND member=?",(self.guild,str(member_id)))
                    await self.db(uncertain)
                    raise
            return await self.db(lambda db: policy.commit_training(db,self.guild,member_id,payload))
