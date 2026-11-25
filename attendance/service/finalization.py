"""Durable operation ledger and opt-in Discord workflow with injectable transport."""
import asyncio
import datetime as dt
import hashlib
import json

from attendance import UTC, holiday_dates, report, windows
from absence import coverage_issue
import promotions
import absence
import loa


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS attendance_holidays (
            day TEXT PRIMARY KEY, marked_by TEXT NOT NULL
        );
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


class ReviewRequired(ValueError):
    """A qualifying operation is held for a staff decision."""


def set_holiday(db, day, actor_id, enabled=True):
    with db:
        db.execute("BEGIN IMMEDIATE")
        if db.execute("SELECT 1 FROM finalized_operations WHERE operation IN (?, ?)",
                      (f"{day}:main", f"{day}:fun")).fetchone():
            raise ValueError("That date already has finalized attendance. No credits or records were changed.")
        if enabled:
            return db.execute("INSERT OR IGNORE INTO attendance_holidays VALUES (?, ?)",
                              (day.isoformat(), str(actor_id))).rowcount == 1
        else:
            return db.execute("DELETE FROM attendance_holidays WHERE day=?", (day.isoformat(),)).rowcount == 1


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
        holiday = bool(holiday_dates(db, day, day))
        if db.execute("SELECT 1 FROM finalized_operations WHERE guild_id=? AND operation=?", (str(guild_id), identifier)).fetchone():
            return identifier
        data = report(db, day, day, now)
        operation = next((op for op in data["operations"] if op["operation"] == identifier), None)
        if not operation:
            raise ValueError("No linked member qualified; this window is not an operation.")
        pending = [] if holiday else loa.list_entries(db, guild_id, day=day, limit=11)
        if pending:
            ids = ", ".join(row[0] for row in pending[:10])
            more = " (more on page 2)" if len(pending) > 10 else ""
            raise ReviewRequired(f"Resolve relevant pending LOAs before finalization. "
                                 f"Blocking message IDs: {ids}{more}. Run /tae-maintenance loa-list "
                                 f"day:{day.isoformat()} to inspect them.")
        issue = coverage_issue(db, begin, end)
        warnings = operation["warnings"]
        if (warnings or issue) and not reviewed_evidence:
            detail = issue or warnings[0]
            raise ReviewRequired(f"Incomplete evidence/coverage: {detail} Credits remain in preview; staff must review before explicit finalization.")
        snapshot = []
        for member in data["members"]:
            if member["steam_id"] not in operation["seconds"]:
                continue
            op = next(item for item in member["operation_history"] if item["operation"] == identifier)
            status = op["status"]
            if status == "review-no-credit":
                status = "missed" if not issue and not warnings else "review"
            snapshot.append((str(guild_id), identifier, member["steam_id"], member["discord_id"],
                             member["name"], status, op["confirmed_seconds"]))
        digest = hashlib.sha256(json.dumps(snapshot, sort_keys=True).encode()).hexdigest()
        note = "Staff reviewed incomplete evidence; uncertain absences remain review." if warnings or issue else ""
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

    async def scheduled_preview(self, kind, day, now):
        if await self.db(lambda db: holiday_dates(db, day, day)):
            return
        key = f"{day}:main"
        primary = "planning-ping" if kind == "planning" else "recap-preview"
        if await self.db(lambda db: db.execute(
                "SELECT 1 FROM workflow_posts WHERE guild_id=? AND kind=? AND post_key=?",
                (self.guild_id, primary, f"{key}:0")).fetchone()):
            return
        if kind == "planning":
            lines = [f"Expected promotions - {day} Main operation (Eastern)",
                     "Conditional on qualifying attendance and final staff checks. No Discord ranks changed."]
            thresholds = {rank["ops"] for rank in promotions.RANKS[1:]}
            skipped = 0
            candidates = []
            for who, _, baseline, earned in await self.db(lambda db: ledger_totals(db, self.guild_id)):
                if baseline + earned + 1 not in thresholds:
                    continue
                try:
                    current = await self.transport.member(who)
                except Exception:
                    skipped += 1
                    continue
                if current["protected"]:
                    continue
                plan = await self.db(lambda db: promotions.plan(
                    db, who, current["nickname"], current["roles"], current["role_names"],
                    self.protected_roles, now=now, credited_ops=earned + 1))
                if plan["state"] == "proposed":
                    candidates.append(f"- {current['nickname']} -> {plan['target']} ({plan['total_ops']} ops)")
            lines.extend(candidates or ["No automatic promotions forecast."])
            if skipped:
                lines.append(f"Could not verify Discord roles for {skipped} possible candidate(s).")
        else:
            lines = (await self.db(lambda db: absence.recap_preview(
                db, day, now=now, scheduled=True))).splitlines()
        pages = [""]
        for line in lines:
            if len(pages[-1]) + len(line) + 1 > 1500:
                pages.append("Preview (continued)\n")
            pages[-1] += line + "\n"
        for index, text in enumerate(pages):
            await self.send_once(primary if index == 0 else kind, f"{key}:{index}", text)

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
            return plan["reason"] if plan["state"] == "review" else plan["state"]
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
            operation = await self.db(lambda db: finalize(db, self.guild_id, day, session, now, reviewed_evidence))
            rows = await self.db(lambda db: db.execute("SELECT discord_id,name FROM operation_credits WHERE guild_id=? AND operation=? AND status='attended' ORDER BY name",
                                                      (self.guild_id, operation)).fetchall())
            problems = []
            for discord_id, name in rows:
                try:
                    outcome = await self.process_member(operation, discord_id)
                    if outcome not in ("protected", "unchanged", "applied", "inactive"):
                        problems.append((discord_id, outcome))
                except Exception:
                    problems.append((discord_id, "Discord promotion or announcement could not be verified. Check /tae-maintenance workflow-status before retrying."))
            applied = await self.db(lambda db: db.execute("SELECT discord_id,plan_json FROM promotion_jobs WHERE guild_id=? AND operation=? AND state='applied'", (self.guild_id, operation)).fetchall())
            names = dict(rows)
            # Display current Discord names without rewriting immutable attendance evidence.
            for who, _ in rows:
                try:
                    names[who] = (await self.transport.member(who))['nickname']
                except Exception:
                    pass
            lines = [f"Operation complete: {operation} (Eastern)", f"Attended ({len(rows)}):"]
            lines += ["- " + names[who] for who, _ in rows]
            lines.append("Promotions completed:")
            lines += ["- " + names.get(who, who) + ": " + json.loads(payload)["target"] for who, payload in applied]
            if not applied:
                lines.append("None.")
            if problems:
                lines.append(f"Promotion review needed ({len(problems)}):")
                lines += [f"- {names[who]}: {reason}" for who, reason in problems]
                lines.append("To inspect a member, run /tae-admin review and select them in the member field.")
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
            if getattr(self.transport, 'name_review_factory', None):
                await self.send_once('name-review', operation,
                    f'Rank/name review for {operation}: admins can approve or deny attendance-based rank and nickname corrections, or fix a specific attendee. '
                    'No changes occur until approved; appointed ranks remain protected. '
                    'Corrections preserve attendance totals and unrelated roles; historical corrections do not send promotion announcements.')
            await self.post_absence_alerts()
            sheet_status = ""
            if self.sheet_export is not None:
                try:
                    await self.sheet_export()
                    sheet_status = " Sheet export verified."
                except Exception:
                    sheet_status = " Sheet export needs staff review; finalized credits and completed Discord actions are retained."
            return f"Finalized {operation}: {len(rows)} attendance credits; {len(applied)} completed promotions; {len(problems)} results need review. Repeat runs do not add credits again." + sheet_status
