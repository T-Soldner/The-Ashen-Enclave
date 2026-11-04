"""Local Discord workflow; no Discord SDK or network access in this module."""
import datetime as dt
import re
from pathlib import Path
from urllib.parse import urlparse

from attendance import UTC, eastern_offset, report
from collector import connect
import loa
import absence
import finalization
import applications
import sheets_sync
import membership
import application_roles
import onboarding
import clan_training
import link_queue


def steam_identity(value):
    value = value.strip()
    if re.fullmatch(r"[0-9]{17}", value):
        return value
    url = urlparse(value)
    match = re.fullmatch(r"/profiles/([0-9]{17})/?", url.path)
    if url.scheme == "https" and url.netloc.lower() == "steamcommunity.com" and match and not url.query and not url.fragment:
        return match[1]
    raise ValueError("Use your 17-digit SteamID64 or https://steamcommunity.com/profiles/STEAMID64. Vanity /id/ links need staff help.")


def snowflake(value):
    value = str(value)
    if not re.fullmatch(r"[0-9]{17,20}", value):
        raise ValueError("Invalid Discord ID")
    return value


def authorize(guild_id, configured_guild, is_admin=False, staff=False):
    if guild_id != configured_guild or (staff and not is_admin):
        raise PermissionError("This command is restricted to the configured server and, for staff commands, Discord administrators.")


class Store:
    def __init__(self, path):
        self.path = Path(path)
        if not self.path.is_file():
            raise ValueError("Attendance database does not exist. Check --db; the bot will not create an empty replacement.")
        db = connect(self.path)
        try:
            db.executescript("""
                CREATE TABLE IF NOT EXISTS link_requests (
                    discord_id TEXT PRIMARY KEY, steam_id TEXT NOT NULL,
                    submitted_utc TEXT NOT NULL, status TEXT NOT NULL DEFAULT 'pending'
                );
                CREATE TABLE IF NOT EXISTS bot_audit (
                    id INTEGER PRIMARY KEY, utc TEXT NOT NULL, actor_id TEXT NOT NULL,
                    action TEXT NOT NULL, target_id TEXT NOT NULL, details TEXT NOT NULL
                );
                CREATE TABLE IF NOT EXISTS member_dates (
                    discord_id TEXT PRIMARY KEY, joined_date TEXT NOT NULL
                );
            """)
            loa.initialize(db)
            absence.initialize(db)
            finalization.initialize(db)
            applications.initialize(db)
            application_roles.initialize(db)
            onboarding.initialize(db)
            clan_training.initialize(db)
            sheets_sync.initialize(db)
            membership.initialize(db)
            link_queue.initialize(db)
        finally:
            db.close()

    def run(self, callback):
        db = connect(self.path)
        try:
            return callback(db)
        finally:
            db.close()

    def request(self, discord_id, identity):
        discord_id = snowflake(discord_id)
        steam_id = steam_identity(identity)

        def action(db):
            with db:
                if db.execute("SELECT 1 FROM members WHERE discord_id=? OR steam_id=?", (discord_id, steam_id)).fetchone():
                    raise ValueError("One of these accounts is already linked. Ask an administrator; existing links are never overwritten.")
                existing = db.execute("SELECT steam_id,status FROM link_requests WHERE discord_id=?", (discord_id,)).fetchone()
                if existing and existing[1] == "pending":
                    raise ValueError("You already have a pending request. Ask an administrator to review it.")
                if db.execute("SELECT 1 FROM link_requests WHERE steam_id=? AND status='pending'", (steam_id,)).fetchone():
                    raise ValueError("That Steam ID already has a pending request. Ask an administrator to review it.")
                now = dt.datetime.now(UTC).isoformat()
                db.execute("INSERT OR REPLACE INTO link_requests VALUES (?,?,?,'pending')", (discord_id, steam_id, now))
                db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                           (now, discord_id, "request-link", discord_id, steam_id))
            return "Request saved for staff review. It does not yet link accounts or award attendance."
        return self.run(action)

    def pending(self):
        return self.run(lambda db: db.execute("SELECT discord_id,steam_id,submitted_utc FROM link_requests WHERE status='pending' ORDER BY submitted_utc LIMIT 20").fetchall())

    def approve(self, actor_id, discord_id, name, since, baseline, joined=None):
        actor_id, discord_id = snowflake(actor_id), snowflake(discord_id)
        since = dt.date.fromisoformat(since).isoformat()
        if joined:
            joined = dt.date.fromisoformat(joined).isoformat()
            if joined > since:
                raise ValueError("Membership date cannot be after the counting start date.")
        if not name.strip() or len(name.strip()) > 100 or baseline < 0:
            raise ValueError("Use a name of 1-100 characters and a nonnegative starting total.")

        def action(db):
            with db:
                db.execute("BEGIN IMMEDIATE")
                request = db.execute("SELECT steam_id FROM link_requests WHERE discord_id=? AND status='pending'", (discord_id,)).fetchone()
                if not request:
                    raise ValueError("No pending request for this member.")
                db.execute("INSERT INTO members (steam_id,discord_id,display_name,baseline_ops,tracking_since) VALUES (?,?,?,?,?)",
                           (request[0], discord_id, name.strip(), baseline, since))
                db.execute("UPDATE link_requests SET status='approved' WHERE discord_id=?", (discord_id,))
                if joined:
                    db.execute("INSERT INTO member_dates VALUES (?,?)", (discord_id, joined))
                db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                           (dt.datetime.now(UTC).isoformat(), actor_id, "approve-link", discord_id,
                            f"steam={request[0]};since={since};baseline={baseline};joined={joined or ''}"))
            return "Member linked locally. No roles, nicknames, totals in Sheets or announcements changed."
        return self.run(action)

    def reject(self, actor_id, discord_id):
        actor_id, discord_id = snowflake(actor_id), snowflake(discord_id)

        def action(db):
            with db:
                changed = db.execute("UPDATE link_requests SET status='rejected' WHERE discord_id=? AND status='pending'", (discord_id,)).rowcount
                if not changed:
                    raise ValueError("No pending request for this member.")
                db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                           (dt.datetime.now(UTC).isoformat(), actor_id, "reject-link", discord_id, ""))
            return "Request rejected. Existing links were not changed; the member can submit again."
        return self.run(action)

    def status(self, discord_id):
        discord_id = snowflake(discord_id)

        def action(db):
            row = db.execute("SELECT display_name,baseline_ops,tracking_since,active FROM members WHERE discord_id=?", (discord_id,)).fetchone()
            if not row:
                pending = db.execute("SELECT status FROM link_requests WHERE discord_id=?", (discord_id,)).fetchone()
                return "Link request: " + pending[0] if pending else "Not linked. Use /tae register to submit your SteamID64 for staff review."
            name, baseline, since, active = row
            if not active:
                return "Your attendance roster entry is inactive. Contact staff."
            if not since:
                return "Your link needs a counting start date. Contact staff."
            now = dt.datetime.now(UTC)
            today = (now + dt.timedelta(hours=eastern_offset(now))).date()
            start = dt.date.fromisoformat(since)
            if start > today:
                return f"{name}: linked. Starting total: {baseline}. Automatic counting starts {since}. Preview only."
            if (today - start).days > 366:
                return f"{name}: linked. Starting total: {baseline}. Tracking exceeds the preview's one-year limit; contact staff."
            preview = report(db, start, today, now)
            person = next(item for item in preview["members"] if item["discord_id"] == discord_id)
            lines = [f"{name} - PREVIEW ONLY", f"Starting total before {since}: {baseline}",
                     f"New qualifying ops since {since}: {person['earned_in_report_range']}",
                     "Last four completed qualifying operations:"]
            lines += [f"{op['operation']}: {op['status']} ({op['confirmed_seconds']:.0f}s confirmed)" for op in person["last_four"]]
            if not person["last_four"]:
                lines.append("None recorded yet.")
            lines.append(f"Evidence warnings: {len(preview['warnings'])}. LOAs excuse recent-op results only; final absence decisions remain disabled.")
            return "\n".join(lines)
        return self.run(action)

    def health(self):
        def action(db):
            count, latest = db.execute("SELECT count(*),max(utc) FROM events").fetchone()
            rejected = db.execute("SELECT count(*) FROM rejected_events").fetchone()[0]
            pending = db.execute("SELECT count(*) FROM link_requests WHERE status='pending'").fetchone()[0]
            pending_loas = db.execute("SELECT count(*) FROM loa_messages WHERE status='pending'").fetchone()[0]
            detections = db.execute("SELECT count(*) FROM detected_links WHERE state='pending'").fetchone()[0]
            uncertain = db.execute("SELECT count(*) FROM detected_links WHERE state IN ('applying','uncertain') OR delivery IN ('sending','uncertain')").fetchone()[0]
            return f"Recorded events: {count}. Latest UTC: {latest or 'none'}. Rejected records: {rejected}. Pending links: {pending}. Detected links awaiting review: {detections}. Link receipts needing review: {uncertain}. Pending LOAs: {pending_loas}. This health check does not change Discord or Sheets."
        return self.run(action)
