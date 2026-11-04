"""Durable operation ledger and opt-in Discord workflow with injectable transport."""
import asyncio
import datetime as dt
import hashlib
import json

from attendance import UTC, report, windows
from absence import complete_coverage
import promotions
import absence


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS finalized_operations (
            guild_id TEXT NOT NULL, operation TEXT NOT NULL, finalized_utc TEXT NOT NULL,
            evidence_hash TEXT NOT NULL, review_note TEXT NOT NULL,
            PRIMARY KEY (guild_id, operation)
        );
        CREATE TABLE IF NOT EXISTS operation_credits (
            guild_id TEXT NOT NULL, operation TEXT NOT NULL, steam_id TEXT NOT NULL,
            discord_id TEXT NOT NULL, name TEXT NOT NULL, status TEXT NOT NULL,
            confirmed_seconds REAL NOT NULL,
            PRIMARY KEY (guild_id, operation, steam_id)
        );
        CREATE TABLE IF NOT EXISTS promotion_jobs (
            guild_id TEXT NOT NULL, discord_id TEXT NOT NULL, target_role INTEGER NOT NULL,
            operation TEXT NOT NULL, plan_json TEXT NOT NULL, state TEXT NOT NULL,
            PRIMARY KEY (guild_id, discord_id, target_role)
        );
        CREATE TABLE IF NOT EXISTS workflow_posts (
            guild_id TEXT NOT NULL, kind TEXT NOT NULL, post_key TEXT NOT NULL,
            state TEXT NOT NULL, message_id TEXT,
            PRIMARY KEY (guild_id, kind, post_key)
        );
    """)


def finalize(db, guild_id, day, session, now=None, reviewed_evidence=False):
    now = now or dt.datetime.now(UTC)
    if session not in ("main", "fun") or day.weekday() != 5:
        raise ValueError("Choose a Saturday and main or fun.")
    identifier = f"{day}:{session}"
    begin, end = next((a, b) for key, a, b in windows(day) if key == identifier)
    if now < end + dt.timedelta(minutes=15):
        raise ValueError("Wait until 15 minutes after the operation window ends.")
    with db:
        db.execute("BEGIN IMMEDIATE")
        if db.execute("SELECT 1 FROM finalized_operations WHERE guild_id=? AND operation=?", (str(guild_id), identifier)).fetchone():
            return identifier
        data = report(db, day, day, now)
        operation = next((op for op in data["operations"] if op["operation"] == identifier), None)
        if not operation:
            raise ValueError("No linked member qualified; this window is not an operation.")
        pending = db.execute("SELECT 1 FROM loa_messages WHERE status='pending' AND (start_date IS NULL OR end_date IS NULL OR (start_date<=? AND end_date>=?)) LIMIT 1", (str(day), str(day))).fetchone()
        if pending:
            raise ValueError("Resolve relevant pending LOAs before finalization.")
        coverage = complete_coverage(db, begin, end)
        if (data["warnings"] or not coverage) and not reviewed_evidence:
            raise ValueError("Incomplete evidence/coverage. Credits remain in preview; staff must review before explicit finalization.")
        snapshot = []
        for member in data["members"]:
            if member["steam_id"] not in operation["seconds"]:
                continue
            op = next(item for item in member["last_four"] if item["operation"] == identifier)
            status = op["status"]
            if status == "review-no-credit":
                status = "missed" if coverage and not data["warnings"] else "review"
            snapshot.append((str(guild_id), identifier, member["steam_id"], member["discord_id"],
                             member["name"], status, op["confirmed_seconds"]))
        digest = hashlib.sha256(json.dumps(snapshot, sort_keys=True).encode()).hexdigest()
        note = "Staff reviewed incomplete evidence; uncertain absences remain review." if data["warnings"] or not coverage else ""
        db.execute("INSERT INTO finalized_operations VALUES (?,?,?,?,?)", (str(guild_id), identifier, now.isoformat(), digest, note))
        db.executemany("INSERT INTO operation_credits VALUES (?,?,?,?,?,?,?)", snapshot)
    return identifier


def ledger_totals(db, guild_id):
    return db.execute("""SELECT m.discord_id,m.display_name,m.baseline_ops,
        (SELECT count(*) FROM operation_credits c WHERE c.guild_id=? AND c.steam_id=m.steam_id AND c.status='attended')
        FROM members m WHERE m.active=1 ORDER BY m.display_name""", (str(guild_id),)).fetchall()


class Workflow:
    def __init__(self, store, transport, guild_id, enabled=False, protected_roles=()):
        self.store, self.transport = store, transport
        self.guild_id = str(guild_id)
        self.enabled = enabled
        self.protected_roles = protected_roles
        self.lock = asyncio.Lock()
        self.sheet_export = None
        self.automatic_absence_alerts = False

    async def post_absence_alerts(self):
        if not self.enabled or not self.automatic_absence_alerts:
            return
        candidates = await self.db(lambda db: absence.ledger_candidates(db,self.guild_id))
        for candidate in candidates:
            current = await self.db(lambda db: absence.reserve_ledger(db,self.guild_id,candidate['discord_id']))
            if current is None:
                continue
            try:
                text = (f"Attendance check: {current['name']} has missed {current['consecutive_misses']} consecutive finalized operations without a recorded LOA. "
                        "Staff follow-up requested. No roles or clan membership changed.")
                message = await self.transport.send('absence',text)
            except BaseException:
                await self.db(lambda db: absence.finish(db,self.guild_id,current['discord_id'],current['episode']))
                raise
            await self.db(lambda db: absence.finish(db,self.guild_id,current['discord_id'],current['episode'],message))

    async def db(self, callback):
        return await asyncio.to_thread(self.store.run, callback)

    async def send_once(self, kind, key, text, mention_id=None):
        def reserve(db):
            with db:
                return db.execute("INSERT OR IGNORE INTO workflow_posts VALUES (?,?,?,'sending',NULL)",
                                  (self.guild_id, kind, key)).rowcount == 1
        if not await self.db(reserve):
            return False
        try:
            message_id = await self.transport.send(kind, text, mention_id)
        except BaseException:
            await self.db(lambda db: self._post_result(db, kind, key, "uncertain", None))
            raise
        await self.db(lambda db: self._post_result(db, kind, key, "sent", str(message_id)))
        return True

    def _post_result(self, db, kind, key, state, message_id):
        with db:
            db.execute("UPDATE workflow_posts SET state=?,message_id=? WHERE guild_id=? AND kind=? AND post_key=?",
                       (state, message_id, self.guild_id, kind, key))

    async def process_member(self, operation, discord_id):
        active = await self.db(lambda db: db.execute("SELECT active FROM members WHERE discord_id=?", (discord_id,)).fetchone())
        if not active or not active[0]:
            return "inactive"
        current = await self.transport.member(discord_id)
        if current["protected"]:
            return "protected"
        total = await self.db(lambda db: db.execute("SELECT count(*) FROM operation_credits WHERE guild_id=? AND discord_id=? AND status='attended'",
                                                   (self.guild_id, discord_id)).fetchone()[0])
        plan = await self.db(lambda db: promotions.plan(db, discord_id, current["nickname"], current["roles"],
                            current["role_names"], self.protected_roles, credited_ops=total))
        # Resume announcements for previously completed jobs, not uncertain role edits.
        completed = await self.db(lambda db: db.execute("SELECT target_role,plan_json FROM promotion_jobs WHERE guild_id=? AND discord_id=? AND operation=? AND state='applied'",
                                                       (self.guild_id, discord_id, operation)).fetchall())
        for role, payload in completed:
            old = json.loads(payload)
            await self.send_once("promotion", f"{discord_id}:{role}", old["announcement"], discord_id)
        if plan["state"] != "proposed":
            return plan["state"]
        await self.transport.check_promotion(current, plan)
        def reserve(db):
            with db:
                return db.execute("INSERT OR IGNORE INTO promotion_jobs VALUES (?,?,?,?,?,'applying')",
                    (self.guild_id, discord_id, plan["add_role"], operation, json.dumps(plan))).rowcount == 1
        if not await self.db(reserve):
            return "existing-job; inspect receipt before retry"
        try:
            # Transport rechecks protection/current state before the first mutation.
            await self.transport.apply(discord_id, current, plan)
        except BaseException:
            await self.db(lambda db: self._job_result(db, discord_id, plan["add_role"], "uncertain"))
            raise
        await self.db(lambda db: self._job_result(db, discord_id, plan["add_role"], "applied"))
        await self.send_once("promotion", f"{discord_id}:{plan['add_role']}", plan["announcement"], discord_id)
        return "applied"

    def _job_result(self, db, discord_id, role, state):
        with db:
            db.execute("UPDATE promotion_jobs SET state=? WHERE guild_id=? AND discord_id=? AND target_role=?",
                       (state, self.guild_id, discord_id, role))

    async def run(self, day, session, reviewed_evidence=False, now=None):
        if not self.enabled:
            raise ValueError("Live workflow disabled. Start with --enable-live-workflow only after permission checks and testing.")
        async with self.lock:
            await self.transport.preflight()
            if self.transport.reconcile_loas is not None:
                await self.transport.reconcile_loas()
            operation = await self.db(lambda db: finalize(db, self.guild_id, day, session, now, reviewed_evidence))
            rows = await self.db(lambda db: db.execute("SELECT discord_id,name FROM operation_credits WHERE guild_id=? AND operation=? AND status='attended' ORDER BY name",
                                                      (self.guild_id, operation)).fetchall())
            problems = []
            for discord_id, name in rows:
                try:
                    outcome = await self.process_member(operation, discord_id)
                    if outcome not in ("protected", "unchanged", "applied", "inactive"):
                        problems.append(f"{name}: {outcome}")
                except Exception:
                    problems.append(f"{name}: promotion/announcement needs staff review")
            applied = await self.db(lambda db: db.execute("SELECT discord_id,plan_json FROM promotion_jobs WHERE guild_id=? AND operation=? AND state='applied'", (self.guild_id, operation)).fetchall())
            names = dict(rows)
            lines = [f"Operation complete: {operation} (Eastern)", f"Attended ({len(rows)}):"]
            lines += ["- " + name for _, name in rows]
            lines.append("Promotions completed:")
            lines += ["- " + names.get(who, who) + ": " + json.loads(payload)["target"] for who, payload in applied]
            if not applied:
                lines.append("None.")
            if problems:
                lines.append(f"Staff review required for {len(problems)} promotion/announcement results.")
            page = ""
            pages = []
            for line in lines:
                if len(page) + len(line) + 1 > 1700:
                    pages.append(page)
                    page = "Operation recap (continued)\n"
                page += line + "\n"
            pages.append(page)
            for index, text in enumerate(pages):
                await self.send_once("recap", f"{operation}:{index}", text)
            await self.post_absence_alerts()
            sheet_status = ""
            if self.sheet_export is not None:
                try:
                    await self.sheet_export()
                    sheet_status = " Sheet export verified."
                except Exception:
                    sheet_status = " Sheet export needs staff review; finalized credits and completed Discord actions are retained."
            return f"Finalized {operation}: {len(rows)} attendance credits; {len(applied)} completed promotions; {len(problems)} results need review. Repeat runs do not add credits again." + sheet_status
