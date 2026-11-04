"""Reversible local offboarding: preserve records, deactivate future processing."""
import datetime as dt
import json

from attendance import UTC

HOUSE_KARR_ROLE = 1477486340101902512


def roster_report(db, discord_members):
    """Compare a fully fetched Discord snapshot with active linked attendance."""
    current = {str(user_id): (name, set(roles)) for user_id, name, roles in discord_members}
    tracked = {str(user_id): name for user_id, name in db.execute(
        "SELECT discord_id,display_name FROM members WHERE active=1 AND discord_id IS NOT NULL")}
    pending = {str(row[0]) for row in db.execute(
        "SELECT discord_id FROM link_requests WHERE status='pending'")}
    sections = ["ROSTER CHECK - READ ONLY (linked attendance database, not unlinked Sheet rows)"]
    missing = [(uid, name) for uid, (name, roles) in current.items()
               if HOUSE_KARR_ROLE in roles and uid not in tracked]
    departed = [(uid, name) for uid, name in tracked.items() if uid not in current]
    no_role = [(uid, name) for uid, name in tracked.items()
               if uid in current and HOUSE_KARR_ROLE not in current[uid][1]]
    for title, entries in [("House Karr members missing active tracking", missing),
                           ("Tracked members no longer in Discord", departed),
                           ("Tracked members still in Discord without House Karr", no_role)]:
        sections.append(f"\n{title}: {len(entries)}")
        sections.extend(f"- {name} | Discord ID {uid}" +
                        (" | registration pending" if uid in pending else "")
                        for uid, name in sorted(entries, key=lambda item: (item[1] or "", item[0])))
    sections.append("\nNo members archived, roles changed or Sheet cells edited. Unlinked Sheet/ORBAT rows cannot be identified safely by name.")
    return "\n".join(sections)


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS archived_members (
            guild_id TEXT NOT NULL, discord_id TEXT NOT NULL, archived_utc TEXT NOT NULL,
            payload TEXT NOT NULL, sheet_status TEXT NOT NULL DEFAULT 'not_requested',
            PRIMARY KEY (guild_id,discord_id)
        );
    """)


def archive(db, guild_id, discord_id, actor_id):
    with db:
        db.execute("BEGIN IMMEDIATE")
        old = db.execute("SELECT payload FROM archived_members WHERE guild_id=? AND discord_id=?", (str(guild_id),str(discord_id))).fetchone()
        if old:
            return json.loads(old[0])
        member = db.execute("SELECT steam_id,display_name,baseline_ops,tracking_since,active FROM members WHERE discord_id=?", (str(discord_id),)).fetchone()
        if not member:
            raise ValueError("No linked attendance member found. Unlinked ORBAT entries require manual handling.")
        if not member[4]:
            raise ValueError("Member is already inactive; no new archive snapshot created.")
        recent = db.execute("SELECT operation,status FROM operation_credits WHERE guild_id=? AND steam_id=? ORDER BY substr(operation,1,10) DESC, CASE WHEN operation LIKE '%:fun' THEN 1 ELSE 0 END DESC LIMIT 4", (str(guild_id),member[0])).fetchall()
        count = db.execute("SELECT count(*) FROM operation_credits WHERE guild_id=? AND steam_id=? AND status='attended'", (str(guild_id),member[0])).fetchone()[0]
        binding = db.execute("SELECT sheet_row,expected_name,last_total FROM sheet_bindings WHERE steam_id=?", (member[0],)).fetchone()
        now = dt.datetime.now(UTC).isoformat()
        payload = {"name": member[1], "total": member[2]+count, "since": member[3] or "",
                   "archived_utc": now, "recent": [list(item) for item in recent], "binding": list(binding) if binding else None}
        db.execute("INSERT INTO archived_members (guild_id,discord_id,archived_utc,payload) VALUES (?,?,?,?)",
                   (str(guild_id),str(discord_id),now,json.dumps(payload)))
        db.execute("UPDATE members SET active=0 WHERE discord_id=?", (str(discord_id),))
        db.execute("UPDATE link_requests SET status='cancelled' WHERE discord_id=? AND status='pending'", (str(discord_id),))
        db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                   (now,str(actor_id),"archive-member",str(discord_id),"History and Discord roles preserved; future attendance processing disabled"))
    return payload


def export_archive(db, google, guild_id, discord_id):
    row = db.execute("SELECT payload,sheet_status FROM archived_members WHERE guild_id=? AND discord_id=?", (str(guild_id),str(discord_id))).fetchone()
    if not row:
        raise ValueError("Archive the local member first.")
    if row[1] == "sent":
        return "Sheet archive already completed; no duplicate created."
    if row[1] in ("sending", "uncertain"):
        raise ValueError("Previous sheet archive result needs staff review; it will not be blindly repeated.")
    payload = json.loads(row[0])
    if not payload["binding"]:
        raise ValueError("Member archived locally, but no verified sheet binding exists. Tracker/ORBAT remain untouched.")
    plan = google.plan_archive(payload)
    with db:
        db.execute("UPDATE archived_members SET sheet_status='sending' WHERE guild_id=? AND discord_id=?", (str(guild_id),str(discord_id)))
    try:
        google.apply_archive(plan)
    except BaseException:
        with db:
            db.execute("UPDATE archived_members SET sheet_status='uncertain' WHERE guild_id=? AND discord_id=?", (str(guild_id),str(discord_id)))
        raise
    with db:
        db.execute("UPDATE archived_members SET sheet_status='sent' WHERE guild_id=? AND discord_id=?", (str(guild_id),str(discord_id)))
    return "Mapped tracker entry moved to Archived Members; recent-op row cleared. No rows were deleted or shifted. Separate ORBAT remains manual."
