"""Private application records. Submission never grants roles or attendance links."""
import datetime as dt
import json
import re
from urllib.parse import urlparse

from attendance import UTC

PUBLIC_CHANNEL = 1477486340625924214
REVIEW_CHANNEL = 1477486342471680236
RECRUITMENT_OFFICER_ROLE = 1477486340101902517
UNASSIGNED_ROLE = 1477486339984199936
STREAMER_ROLE = 1477486340022206602
FRIEND_ROLE = 1477486340022206599
LIAISON_ROLE = 1477486340022206603
ACTIVE_ROLES = {1477486340072276115,1477486340101902512,1477486340080799940,
                1477486340101902513,1477486340080799947,1477486340080799939,
                1477486340051570795,1477486340030333095,1477486339984199938}
CATEGORIES = ("Active member", "Other Unit Liaison", "Friend of the unit")
FIELDS = (("source", "How did you find out about the unit?", 400),
          ("hours", "How many Arma hours do you have?", 12),
          ("record", "Do you stream or record?", 400),
          ("about", "Tell us about yourself", 1500),
          ("steam", "SteamID64 (17 digits)", 17))
LIAISON_FIELDS = (("unit","Unit name",100),("source","How did you find us?",400),("discord","Link to your unit Discord",400))


def fields_for(category):
    return FIELDS if category == CATEGORIES[0] else LIAISON_FIELDS if category == CATEGORIES[1] else ()


def validate_answers(category, answers):
    if category not in CATEGORIES:
        raise ValueError("Choose one of the three participation options.")
    cleaned = {}
    for key,label,limit in fields_for(category):
        value = str(answers.get(key,"")).strip()
        if not value or len(value) > limit:
            raise ValueError(f"Please answer: {label} (maximum {limit} characters).")
        cleaned[key] = value
    if category == CATEGORIES[0]:
        if not re.fullmatch(r"[0-9]{17}",cleaned["steam"]):
            raise ValueError("SteamID64 must be exactly 17 digits, not a username/email.")
        if not re.fullmatch(r"[0-9]+(?:\.[0-9]+)?",cleaned["hours"]) or float(cleaned["hours"]) > 100000:
            raise ValueError("Enter Arma hours as a number between 0 and 100000.")
        cleaned["record"] = cleaned["record"].lower()
        if cleaned["record"] not in ("yes","no"):
            raise ValueError("Choose Yes or No for streaming/recording.")
    if category == CATEGORIES[1]:
        url = urlparse(cleaned["discord"])
        valid = ((url.netloc.lower() == "discord.gg" and re.fullmatch(r"/[A-Za-z0-9-]+/?",url.path)) or
                 (url.netloc.lower() in ("discord.com","www.discord.com") and re.fullmatch(r"/invite/[A-Za-z0-9-]+/?",url.path)))
        if url.scheme != "https" or not valid or url.query or url.fragment:
            raise ValueError("Use a valid https://discord.gg/... or https://discord.com/invite/... invitation for your unit.")
    return cleaned


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS applications (
            application_id TEXT PRIMARY KEY, discord_id TEXT NOT NULL,
            category TEXT NOT NULL, answers TEXT NOT NULL, submitted_utc TEXT NOT NULL,
            status TEXT NOT NULL DEFAULT 'pending', delivery TEXT NOT NULL DEFAULT 'pending',
            review_message_id TEXT
        );
        CREATE UNIQUE INDEX IF NOT EXISTS one_open_application ON applications(discord_id) WHERE status='pending';
        CREATE TABLE IF NOT EXISTS application_panels (
            guild_id TEXT PRIMARY KEY, state TEXT NOT NULL, message_id TEXT
        );
    """)
    columns = {row[1] for row in db.execute("PRAGMA table_info(applications)")}
    for name in ("reviewed_by", "reviewed_utc", "denial_reason"):
        if name not in columns:
            db.execute(f"ALTER TABLE applications ADD COLUMN {name} TEXT")
    db.commit()


def submit(db, application_id, discord_id, category, answers):
    cleaned = validate_answers(category,answers)
    with db:
        db.execute("BEGIN IMMEDIATE")
        old = db.execute("SELECT application_id FROM applications WHERE discord_id=? AND status='pending'", (str(discord_id),)).fetchone()
        if old:
            raise ValueError("You already have an application awaiting staff review.")
        db.execute("INSERT INTO applications (application_id,discord_id,category,answers,submitted_utc) VALUES (?,?,?,?,?)",
                   (str(application_id), str(discord_id), category, json.dumps(cleaned), dt.datetime.now(UTC).isoformat()))
    return str(application_id)


def reserve_delivery(db, application_id):
    with db:
        changed = db.execute("UPDATE applications SET delivery='sending' WHERE application_id=? AND delivery='pending'",
                             (str(application_id),)).rowcount
        if not changed:
            raise ValueError("Already delivered or delivery result needs staff review; no duplicate was sent.")
        row = db.execute("SELECT discord_id,category,answers FROM applications WHERE application_id=?", (str(application_id),)).fetchone()
    return row[0], row[1], json.loads(row[2])


def finish_delivery(db, application_id, message_id=None):
    with db:
        db.execute("UPDATE applications SET delivery=?,review_message_id=? WHERE application_id=?",
                   ("sent" if message_id else "uncertain", str(message_id) if message_id else None, str(application_id)))


def review(db, actor, application_id, accept, reason=None):
    reason = str(reason or "").strip()
    if not accept and not 1 <= len(reason) <= 800:
        raise ValueError("A denial reason of 1-800 characters is required.")
    with db:
        db.execute("BEGIN IMMEDIATE")
        entry = db.execute("SELECT discord_id,category,answers FROM applications WHERE application_id=? AND status='pending'", (str(application_id),)).fetchone()
        if not entry:
            raise ValueError("No pending application with that ID.")
        if db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='application_admissions'").fetchone():
            job = db.execute("SELECT state FROM application_admissions WHERE application_id=?",(str(application_id),)).fetchone()
            if job and (job[0] != "applied" or not accept):
                raise ValueError("Role assignment was started; reconcile its result before changing the application decision.")
        changed = db.execute("UPDATE applications SET status=?,reviewed_by=?,reviewed_utc=?,denial_reason=? WHERE application_id=? AND status='pending'",
                             ("approved" if accept else "rejected",str(actor),dt.datetime.now(UTC).isoformat(),reason if not accept else None,str(application_id))).rowcount
        if not changed:
            raise ValueError("No pending application with that ID.")
        db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                   (dt.datetime.now(UTC).isoformat(), str(actor), "application-approved" if accept else "application-rejected", str(application_id), "No roles or attendance links assigned"))
        queued = False
        if accept and entry[1] == CATEGORIES[0]:
            steam = json.loads(entry[2])["steam"]
            existing = db.execute("SELECT 1 FROM members WHERE discord_id=? OR steam_id=?", (entry[0],steam)).fetchone()
            claim = db.execute("SELECT 1 FROM link_requests WHERE status='pending' AND (discord_id=? OR steam_id=?)", (entry[0],steam)).fetchone()
            if not existing and not claim:
                db.execute("INSERT OR REPLACE INTO link_requests VALUES (?,?,?,'pending')", (entry[0],steam,dt.datetime.now(UTC).isoformat()))
                queued = True
    return "Application decision saved. No nickname, roster entry or attendance credit was assigned." + (
        " Steam ID queued in /tae-admin pending; verify and approve it there with the correct counting date/baseline." if queued else "")
