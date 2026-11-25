"""Read-only attendance previews from confirmed RPT evidence; no external APIs."""
import datetime as dt
import json
import re
from collections import defaultdict

UTC = dt.timezone.utc
MAX_GAP = 90
MONTHS = ('January February March April May June July August September October November December').lower().split()
MONTH = r'[A-Za-z]{3,9}'
YEAR = r'(?:[0-9]{4}|[0-9]{2})'
DATE_PATTERN = rf'(?:\d{{4}}-\d{{1,2}}-\d{{1,2}}|\d{{1,2}}/\d{{1,2}}(?:/{YEAR})?|{MONTH}\s+\d{{1,2}},?\s+{YEAR}|\d{{1,2}}\s+{MONTH}\s+{YEAR})'
DATE_HELP = 'Use YYYY-MM-DD, MM/DD/YYYY, MM/DD/YY, or a written date like Nov 14, 26. Two-digit years mean 2000-2099.'


def expand_year(value):
    return int(value) + (2000 if len(value) == 2 else 0)


def parse_date(value, reference=None):
    """Parse user input without guessing the order of numeric dates."""
    value = value.strip()
    if not re.fullmatch(DATE_PATTERN, value):
        raise ValueError(DATE_HELP)
    try:
        if '-' in value:
            year, month, day = map(int, value.split('-'))
        elif '/' in value:
            month_text, day_text, *years = value.split('/')
            month, day = int(month_text), int(day_text)
            if not years and reference is None:
                raise ValueError
            year = expand_year(years[0]) if years else reference.year
            date = dt.date(year, month, day)
            if not years and abs((date - reference).days) > 183:
                raise ValueError
        else:
            first, second, year = value.lower().replace(',', '').split()
            day, name = (first, second) if first.isdigit() else (second, first)
            month = next((i for i, full in enumerate(MONTHS, 1) if name in (full, full[:3])), 0)
            year, day = expand_year(year), int(day)
        return dt.date(year, month, day)
    except ValueError:
        raise ValueError('Invalid or ambiguous date. ' + DATE_HELP) from None


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


def _evidence(db):
    intervals = defaultdict(list)
    warnings = []
    sessions = defaultdict(list)
    sources = {}
    for session, sequence, stamp, kind, uids, source in db.execute(
            "SELECT session,sequence,utc,kind,uids,source FROM events ORDER BY session,sequence"):
        stamp = dt.datetime.fromisoformat(stamp)
        sessions[session].append((sequence, stamp, kind, json.loads(uids)))
        first, last = sources.get(source, (stamp, stamp))
        sources[source] = min(first, stamp), max(last, stamp)
    for session, events in sessions.items():
        anchors = {}
        previous_sequence = None
        previous_time = None
        ended = False
        for sequence, stamp, kind, uids in events:
            if previous_sequence is not None and (sequence != previous_sequence + 1 or stamp < previous_time):
                warnings.append((f"Missing/out-of-order records in session {session}", previous_time, stamp))
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
                            warnings.append((f"Unconfirmed presence gap in session {session}", anchors[uid], stamp))
                if kind == "PRESENCE":
                    anchors = {uid: stamp for uid in uids}
                elif kind == "LEAVE":
                    for uid in uids:
                        anchors.pop(uid, None)
                elif kind == "END":
                    anchors.clear()
        if not ended:
            stamps = [event[1] for event in events]
            warnings.append((f"Session {session} has no closing record (live or interrupted)", min(stamps), max(stamps)))
    for source, line in db.execute("SELECT source,raw_line FROM rejected_events"):
        # The timestamp may still be valid even if the rest of the record was rejected.
        try:
            stamp_text = line.split("TAE_ATTENDANCE_V1|", 1)[1].split("|")[2]
            year, month, day, hour, minute, second, millis = map(int, stamp_text.split(","))
            stamp = dt.datetime(year, month, day, hour, minute, second, millis * 1000, tzinfo=UTC)
            first, last = stamp, stamp
        except (IndexError, ValueError, OverflowError):
            first, last = sources.get(source, (None, None))
        warnings.append(("Quarantined records require review", first, last))
    return intervals, warnings


def warning_messages(warnings, begin=None, end=None):
    return sorted({message for message, first, last in warnings
                   if begin is None or first is None or
                   (min(first, last) <= end and max(first, last) >= begin)})


def evidence(db):
    """Return all warnings for diagnostics, independent of any operation window."""
    intervals, warnings = _evidence(db)
    return intervals, warning_messages(warnings)


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


def holiday_dates(db, start_day, end_day):
    if not db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='attendance_holidays'").fetchone():
        return set()
    return {dt.date.fromisoformat(row[0]) for row in db.execute(
        "SELECT day FROM attendance_holidays WHERE day BETWEEN ? AND ?",
        (start_day.isoformat(), end_day.isoformat()))}


def report(db, start_day, end_day, now=None):
    now = now or dt.datetime.now(UTC)
    if start_day > end_day or (end_day - start_day).days > 366:
        raise ValueError("Use an ordered range of at most 367 days")
    intervals, warnings = _evidence(db)
    members = db.execute("SELECT steam_id,discord_id,display_name,baseline_ops,tracking_since FROM members WHERE active=1 ORDER BY display_name").fetchall()
    operations = []
    holidays = holiday_dates(db, start_day, end_day)
    day = start_day
    while day <= end_day:
        for identifier, begin, end in windows(day):
            seconds = {uid: seconds_in(intervals.get(uid, []), begin, end)
                       for uid, _, _, _, since in members if since and day.isoformat() >= since}
            if day in holidays:
                seconds = {uid: value for uid, value in seconds.items() if value > 300}
            if any(value > 300 for value in seconds.values()):
                operations.append({"operation": identifier, "closed": end <= now, "seconds": seconds,
                                   "holiday": day in holidays,
                                   "warnings": warning_messages(warnings, begin, end)})
        day += dt.timedelta(days=1)
    results = []
    excuses = []
    if db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='loa_messages'").fetchone():
        excuses = db.execute("SELECT member_id,start_date,end_date FROM loa_messages WHERE status='accepted'").fetchall()
    for uid, discord, name, baseline, since in members:
        recent = [op for op in operations if op["closed"] and uid in op["seconds"]]
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
        results[-1]['operation_history'] = results[-1]['last_four']
        results[-1]['last_four'] = [entry for entry, op in zip(results[-1]['operation_history'], recent)
                                   if entry['operation'].endswith(':main') and not op['holiday']][-4:]
    return {"mode": "PREVIEW ONLY", "from": str(start_day), "through": str(end_day),
            "warnings": sorted({warning for op in operations for warning in op["warnings"]}), "members": results,
            "operations": operations,
            "note": "Range counts are not lifetime totals. Accepted LOAs excuse recent results without adding credit. Final absence decisions and rank changes are disabled."}
