"""Parse LOA messages without retaining optional private reasons."""
import datetime as dt
import hashlib
import re

from attendance import UTC, eastern_offset

DATE = r"(?:\d{4}-\d{1,2}-\d{1,2}|\d{1,2}/\d{1,2}(?:/\d{4})?)"


def acknowledgement(outcome):
    if outcome["status"] == "accepted":
        start, end = outcome["start"], outcome["end"]
        dates = start if start == end else f"{start} through {end}"
        return f"LOA accepted for the dates: {dates}. Excused absence logged."
    if outcome["status"] == "cancelled":
        return "LOA cancelled."
    return "LOA needs staff review. " + outcome["detail"]


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS loa_messages (
            message_id TEXT PRIMARY KEY, guild_id TEXT NOT NULL,
            channel_id TEXT NOT NULL, author_id TEXT NOT NULL,
            member_id TEXT, start_date TEXT, end_date TEXT,
            status TEXT NOT NULL, detail TEXT NOT NULL,
            digest TEXT NOT NULL, updated_utc TEXT NOT NULL
        );
    """)


def parse_message(content, created_utc, author_id):
    # Markdown is allowed around the supplied mention and field labels.
    text = content.replace("**", "").replace("__", "")
    fields = {}
    for match in re.finditer(r"(?im)^\s*(Name|Duration|Reason)\s*:\s*([^\r\n]*)", text):
        label = match[1].lower()
        if label in fields:
            return {"member": None, "start": None, "end": None,
                    "detail": "Duplicate fields; staff review required."}
        fields[label] = match[2].strip()
    if not fields:
        return None
    result = {"member": None, "start": None, "end": None, "detail": ""}
    mentions = re.findall(r"<@!?(\d{17,20})>", fields.get("name", ""))
    if len(mentions) != 1:
        result["detail"] = "Name must contain exactly one Discord member mention."
        return result
    result["member"] = mentions[0]
    duration = fields.get("duration", "")
    dates = re.fullmatch(fr"\s*({DATE})(?:\s*(?:to|through|[-\u2013\u2014])\s*({DATE}))?\s*", duration, re.I)
    if not dates:
        result["detail"] = "Duration needs a date or inclusive date range; use MM/DD/YYYY or YYYY-MM-DD."
        return result
    local_day = (created_utc + dt.timedelta(hours=eastern_offset(created_utc))).date()

    def read_date(value):
        if "-" in value:
            year, month, day = map(int, value.split("-"))
        else:
            pieces = list(map(int, value.split("/")))
            month, day = pieces[:2]
            year = pieces[2] if len(pieces) == 3 else local_day.year
        date = dt.date(year, month, day)
        if value.count("/") == 1 and abs((date - local_day).days) > 183:
            raise ValueError("Year is ambiguous; include a four-digit year.")
        return date

    try:
        start = read_date(dates[1])
        end = read_date(dates[2]) if dates[2] else start
        if end < start or (end - start).days > 366:
            raise ValueError("Use an ordered range no longer than 367 days; include years across New Year.")
    except ValueError:
        result["detail"] = "Invalid or ambiguous dates. Include four-digit years and an ordered range of at most 367 days."
        return result
    result.update(start=start.isoformat(), end=end.isoformat())
    if str(author_id) != result["member"]:
        result["detail"] = "Posted for another member; staff approval required."
    return result


def save(db, message_id, guild_id, channel_id, author_id, content, created_utc):
    parsed = parse_message(content, created_utc, author_id)
    # Hash the parsed fields, never the optional reason or full message text.
    digest = hashlib.sha256(repr(parsed).encode()).hexdigest()
    with db:
        db.execute("BEGIN IMMEDIATE")
        old = db.execute("SELECT digest,status FROM loa_messages WHERE message_id=?", (str(message_id),)).fetchone()
        if parsed is None and not old:
            return None
        if old and old[0] == digest:
            return None
        if parsed is None:
            parsed = {"member": None, "start": None, "end": None,
                      "detail": "LOA fields removed; previous excuse cancelled."}
            status = "cancelled"
        else:
            status = "pending" if parsed["detail"] else "accepted"
        now = dt.datetime.now(UTC).isoformat()
        db.execute("INSERT OR REPLACE INTO loa_messages VALUES (?,?,?,?,?,?,?,?,?,?,?)",
                   (str(message_id), str(guild_id), str(channel_id), str(author_id), parsed["member"],
                    parsed["start"], parsed["end"], status, parsed["detail"], digest, now))
        db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                   (now, str(author_id), "loa-" + status, parsed["member"] or "", str(message_id)))
    return {**parsed, "status": status, "message_id": str(message_id)}


def cancel(db, message_id):
    with db:
        db.execute("BEGIN IMMEDIATE")
        old = db.execute("SELECT member_id FROM loa_messages WHERE message_id=? AND status!='cancelled'", (str(message_id),)).fetchone()
        if not old:
            return False
        db.execute("UPDATE loa_messages SET status='cancelled',detail='Source message deleted',updated_utc=? WHERE message_id=?",
                   (dt.datetime.now(UTC).isoformat(), str(message_id)))
        db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                   (dt.datetime.now(UTC).isoformat(), "discord-event", "loa-deleted", old[0] or "", str(message_id)))
    return True


def review(db, actor_id, message_id, approve):
    with db:
        db.execute("BEGIN IMMEDIATE")
        row = db.execute("SELECT member_id,start_date,end_date FROM loa_messages WHERE message_id=? AND status='pending'", (str(message_id),)).fetchone()
        if not row:
            raise ValueError("No pending LOA for that message. Refresh the source message first if needed.")
        if approve and not all(row):
            raise ValueError("Ask the author to correct the mention/dates first; incomplete LOAs cannot be approved.")
        status = "accepted" if approve else "rejected"
        db.execute("UPDATE loa_messages SET status=?,detail='Reviewed by staff',updated_utc=? WHERE message_id=?",
                   (status, dt.datetime.now(UTC).isoformat(), str(message_id)))
        db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                   (dt.datetime.now(UTC).isoformat(), str(actor_id), "loa-review-" + status, row[0] or "", str(message_id)))
    return "LOA " + status + ". No attended-op credit was added."
