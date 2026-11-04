"""Read-only attendance previews from confirmed RPT evidence; no external APIs."""
import datetime as dt
import json
import re
from collections import defaultdict

UTC = dt.timezone.utc
MAX_GAP = 90


def eastern_offset(utc):
    """US Eastern rules since 2007, computed in UTC without a Windows tzdata install."""
    year = utc.year
    march = dt.date(year, 3, 1)
    november = dt.date(year, 11, 1)
    start = dt.datetime(year, 3, 8 + (6 - march.weekday()) % 7, 7, tzinfo=UTC)
    end = dt.datetime(year, 11, 1 + (6 - november.weekday()) % 7, 6, tzinfo=UTC)
    return -4 if start <= utc < end else -5


def windows(day):
    if day.year < 2007:
        raise ValueError("Dates before 2007 are not supported")
    if day.weekday() != 5:
        return []
    result = []
    for label, start, end in (("main", 14, 17), ("fun", 19, 22)):
        probe = dt.datetime.combine(day, dt.time(12), UTC)
        offset = eastern_offset(probe)
        begin = dt.datetime.combine(day, dt.time(start), UTC) - dt.timedelta(hours=offset)
        finish = dt.datetime.combine(day, dt.time(end), UTC) - dt.timedelta(hours=offset)
        result.append((f"{day}:{label}", begin, finish))
    return result


def evidence(db):
    intervals = defaultdict(list)
    warnings = set()
    sessions = defaultdict(list)
    for session, sequence, stamp, kind, uids in db.execute(
            "SELECT session,sequence,utc,kind,uids FROM events ORDER BY session,sequence"):
        sessions[session].append((sequence, dt.datetime.fromisoformat(stamp), kind, json.loads(uids)))
    for session, events in sessions.items():
        anchors = {}
        previous_sequence = None
        previous_time = None
        ended = False
        for sequence, stamp, kind, uids in events:
            if previous_sequence is not None and (sequence != previous_sequence + 1 or stamp < previous_time):
                warnings.add(f"Missing/out-of-order records in session {session}")
                anchors.clear()
            previous_sequence, previous_time = sequence, stamp
            ended = kind == "END"
            if kind == "JOIN":
                for uid in uids:
                    anchors[uid] = stamp
            else:
                confirmed = set(uids) if kind != "END" else set(anchors)
                for uid in confirmed:
                    if uid in anchors:
                        seconds = (stamp - anchors[uid]).total_seconds()
                        if 0 <= seconds <= MAX_GAP:
                            intervals[uid].append((anchors[uid], stamp))
                        else:
                            warnings.add(f"Unconfirmed presence gap in session {session}")
                if kind == "PRESENCE":
                    anchors = {uid: stamp for uid in uids}
                elif kind == "LEAVE":
                    for uid in uids:
                        anchors.pop(uid, None)
                elif kind == "END":
                    anchors.clear()
        if not ended:
            warnings.add(f"Session {session} has no closing record (live or interrupted)")
    if db.execute("SELECT count(*) FROM rejected_events").fetchone()[0]:
        warnings.add("Quarantined records require review")
    return intervals, sorted(warnings)


def seconds_in(intervals, start, end):
    """Union overlapping intervals so duplicate/multiple server sessions cannot double-count."""
    clipped = sorted((max(a, start), min(b, end)) for a, b in intervals if a < end and b > start)
    total = 0.0
    finish = start
    for a, b in clipped:
        a = max(a, finish)
        if b > a:
            total += (b - a).total_seconds()
            finish = b
    return total


def link(db, steam_id, discord_id, name, since, baseline):
    if not re.fullmatch(r"[0-9]{17}", steam_id):
        raise ValueError("SteamID64 must be 17 digits")
    if not re.fullmatch(r"[0-9]{17,20}", discord_id):
        raise ValueError("Discord ID must be 17-20 digits, not a username")
    since = dt.date.fromisoformat(since).isoformat()
    if baseline < 0 or not name.strip():
        raise ValueError("Use a nonnegative baseline and a nonempty name")
    with db:
        # Never silently overwrite identity links or historical baselines.
        db.execute("INSERT INTO members (steam_id,discord_id,display_name,baseline_ops,tracking_since) VALUES (?,?,?,?,?)",
                   (steam_id, discord_id, name.strip(), baseline, since))


def report(db, start_day, end_day, now=None):
    now = now or dt.datetime.now(UTC)
    if start_day > end_day or (end_day - start_day).days > 366:
        raise ValueError("Use an ordered range of at most 367 days")
    intervals, warnings = evidence(db)
    members = db.execute("SELECT steam_id,discord_id,display_name,baseline_ops,tracking_since FROM members WHERE active=1 ORDER BY display_name").fetchall()
    operations = []
    day = start_day
    while day <= end_day:
        for identifier, begin, end in windows(day):
            seconds = {uid: seconds_in(intervals.get(uid, []), begin, end)
                       for uid, _, _, _, since in members if since and day.isoformat() >= since}
            if any(value > 300 for value in seconds.values()):
                operations.append({"operation": identifier, "closed": end <= now, "seconds": seconds})
        day += dt.timedelta(days=1)
    results = []
    excuses = []
    if db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='loa_messages'").fetchone():
        excuses = db.execute("SELECT member_id,start_date,end_date FROM loa_messages WHERE status='accepted'").fetchall()
    for uid, discord, name, baseline, since in members:
        recent = [op for op in operations if op["closed"] and uid in op["seconds"]][-4:]
        earned = sum(op["closed"] and op["seconds"].get(uid, 0) > 300 for op in operations)
        # Actual attendance wins over an overlapping LOA, without cancelling other excused dates.
        results.append({"name": name, "steam_id": uid, "discord_id": discord,
                        "baseline_ops": baseline, "earned_in_report_range": earned,
                        "tracking_since": since,
                        "last_four": [{"operation": op["operation"],
                                       "status": "attended" if op["seconds"][uid] > 300 else (
                                           "excused" if any(member == discord and start <= op["operation"][:10] <= end
                                                            for member, start, end in excuses) else "review-no-credit"),
                                       "confirmed_seconds": op["seconds"][uid]} for op in recent]})
    return {"mode": "PREVIEW ONLY", "from": str(start_day), "through": str(end_day),
            "warnings": warnings, "members": results,
            "operations": operations,
            "note": "Range counts are not lifetime totals. Accepted LOAs excuse recent results without adding credit. Final absence decisions and rank changes are disabled."}
