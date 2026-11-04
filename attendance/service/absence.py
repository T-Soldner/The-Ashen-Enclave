"""Conservative absence previews and durable, staff-triggered alert receipts."""
import datetime as dt

from attendance import UTC, report, windows


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS absence_alerts (
            guild_id TEXT NOT NULL, discord_id TEXT NOT NULL, episode TEXT NOT NULL,
            state TEXT NOT NULL, created_utc TEXT NOT NULL, message_id TEXT,
            PRIMARY KEY (guild_id, discord_id, episode)
        );
    """)


def complete_coverage(db, begin, end):
    stamps = [dt.datetime.fromisoformat(row[0]) for row in db.execute(
        "SELECT utc FROM events WHERE kind='PRESENCE' ORDER BY utc")]
    stamps = sorted(set(stamp for stamp in stamps if begin <= stamp <= end))
    return bool(stamps) and (stamps[0] - begin).total_seconds() <= 90 and (
        end - stamps[-1]).total_seconds() <= 90 and all(
        (right - left).total_seconds() <= 90 for left, right in zip(stamps, stamps[1:]))


def preview(db, now=None):
    now = now or dt.datetime.now(UTC)
    # UTC date may include next local day; report still only includes closed windows.
    today = now.date()
    starts = [row[0] for row in db.execute("SELECT tracking_since FROM members WHERE active=1 AND tracking_since IS NOT NULL")]
    if not starts or min(starts) > today.isoformat():
        return {"members": [], "warnings": [], "note": "No completed tracked operations yet."}
    start = dt.date.fromisoformat(min(starts))
    data = report(db, start, today, now)
    accepted = db.execute("SELECT member_id,start_date,end_date FROM loa_messages WHERE status='accepted'").fetchall()
    pending = db.execute("SELECT member_id,start_date,end_date FROM loa_messages WHERE status='pending'").fetchall()
    coverage = {}
    result = []
    for member in data["members"]:
        history = []
        for op in data["operations"]:
            if not op["closed"] or member["steam_id"] not in op["seconds"]:
                continue
            day = op["operation"][:10]
            begin, end = next((a, b) for name, a, b in windows(dt.date.fromisoformat(day)) if name == op["operation"])
            seconds = op["seconds"][member["steam_id"]]
            if seconds > 300:
                status = "attended"
            elif any(who == member["discord_id"] and first <= day <= last for who, first, last in accepted):
                status = "excused"
            else:
                needs_loa_review = any((who is None or who == member["discord_id"]) and
                                       (not first or not last or first <= day <= last)
                                       for who, first, last in pending)
                if op["operation"] not in coverage:
                    coverage[op["operation"]] = complete_coverage(db, begin, end)
                status = "review" if (data["warnings"] or needs_loa_review or not coverage[op["operation"]]
                                      or now < end + dt.timedelta(minutes=15)) else "missed"
            history.append({"operation": op["operation"], "status": status})
        streak = []
        for op in reversed(history):
            if op["status"] != "missed":
                break
            streak.insert(0, op["operation"])
        result.append({"discord_id": member["discord_id"], "name": member["name"],
                       "consecutive_misses": len(streak), "episode": streak[0] if streak else None,
                       "eligible": len(streak) >= 4, "last_four": history[-4:]})
    return {"members": result, "warnings": data["warnings"],
            "note": "PREVIEW. Review LOA history and evidence before posting. No automatic posts."}


def reserve(db, guild_id, discord_id, now=None):
    # Reserve BEFORE sending. A crash/ambiguous network failure must not auto-retry.
    with db:
        db.execute("BEGIN IMMEDIATE")
        current = next((row for row in preview(db, now)["members"] if row["discord_id"] == str(discord_id)), None)
        if not current or not current["eligible"]:
            raise ValueError("Member does not currently have four confirmed consecutive unexcused misses.")
        if db.execute("SELECT 1 FROM absence_alerts WHERE guild_id=? AND discord_id=? AND episode=?",
                      (str(guild_id), str(discord_id), current["episode"])).fetchone():
            raise ValueError("This absence streak already has a sent or reserved alert. No duplicate will be posted.")
        db.execute("INSERT INTO absence_alerts VALUES (?,?,?,'reserved',?,NULL)",
                   (str(guild_id), str(discord_id), current["episode"], (now or dt.datetime.now(UTC)).isoformat()))
    return current


def finish(db, guild_id, discord_id, episode, message_id=None):
    with db:
        db.execute("UPDATE absence_alerts SET state=?,message_id=? WHERE guild_id=? AND discord_id=? AND episode=? AND state='reserved'",
                   ("sent" if message_id else "uncertain", str(message_id) if message_id else None,
                    str(guild_id), str(discord_id), episode))


def ledger_candidates(db, guild_id):
    """Only finalized misses count; current LOAs and gaps suppress automatic alerts."""
    operations = [r[0] for r in db.execute("SELECT operation FROM finalized_operations WHERE guild_id=? ORDER BY substr(operation,1,10),CASE WHEN operation LIKE '%:fun' THEN 1 ELSE 0 END",(str(guild_id),))]
    result = []
    for steam,did,name,since in db.execute("SELECT steam_id,discord_id,display_name,tracking_since FROM members WHERE active=1"):
        if not did or not since:
            continue
        credits = dict(db.execute("SELECT operation,status FROM operation_credits WHERE guild_id=? AND steam_id=?",(str(guild_id),steam)))
        loas = db.execute("SELECT status,start_date,end_date FROM loa_messages WHERE member_id=? OR member_id IS NULL",(did,)).fetchall()
        streak = []
        for op in operations:
            if op[:10] < since:
                continue
            status = credits.get(op)
            for state,first,last in loas:
                overlaps = not first or not last or first <= op[:10] <= last
                if overlaps and state in ('accepted','pending') and status != 'attended':
                    status = 'review'
            if status == 'missed':
                streak.append(op)
            else:
                streak = []
        if len(streak) >= 4:
            result.append(dict(discord_id=did,name=name,episode=streak[0],consecutive_misses=len(streak)))
    return result


def reserve_ledger(db,guild_id,discord_id):
    with db:
        db.execute("BEGIN IMMEDIATE")
        current = next((r for r in ledger_candidates(db,guild_id) if r['discord_id'] == str(discord_id)),None)
        if not current:
            return None
        changed = db.execute("INSERT OR IGNORE INTO absence_alerts VALUES (?,?,?,'reserved',?,NULL)",
            (str(guild_id),str(discord_id),current['episode'],dt.datetime.now(UTC).isoformat())).rowcount
        return current if changed else None


def format_preview(data):
    lines = [data["note"], f"Evidence warnings: {len(data['warnings'])}"]
    for row in data["members"][:12]:
        recent = ", ".join(op["operation"] + "=" + op["status"] for op in row["last_four"]) or "no completed ops"
        lines.append(f"{row['name']}: {row['consecutive_misses']} consecutive confirmed misses; {recent}")
    if len(data["members"]) > 12:
        lines.append("Showing first 12 members. Use the member option to inspect someone else.")
    return "\n".join(lines)


def recap_preview(db, day, session="main", now=None):
    now = now or dt.datetime.now(UTC)
    if session not in ("main", "fun"):
        raise ValueError("Choose main or fun.")
    if day.weekday() != 5:
        raise ValueError("Automatic operation recaps apply to Saturdays only.")
    data = report(db, day, day, now)
    identifier = f"{day}:{session}"
    operation = next((op for op in data["operations"] if op["operation"] == identifier), None)
    if not operation:
        return f"PREVIEW ONLY - {identifier}\nNo qualifying tracked operation recorded. No recap should be posted."
    names = [member["name"] for member in data["members"] if operation["seconds"].get(member["steam_id"], 0) > 300]
    lines = [f"PREVIEW ONLY - {day} {'Main operation' if session == 'main' else 'Fun operation'} (Eastern)",
             "Window complete: " + ("yes" if operation["closed"] else "no; attendance can still change"),
             f"Attended ({len(names)} linked members):"]
    lines += ["- " + name for name in names]
    lines += ["Promotions: not enabled; no ranks have been changed by this bot.",
              f"Evidence warnings: {len(data['warnings'])}. This recap has not been finalized or posted.",
              "Unlinked players are not included. Attendance does not grant credit until the window closes."]
    return "\n".join(lines)
