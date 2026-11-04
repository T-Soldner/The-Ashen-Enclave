"""Accepted active-member registration with durable, verified Sheet receipts."""
import datetime as dt
import json
import re

import applications
from attendance import UTC, eastern_offset


def initialize(db):
    db.execute("""CREATE TABLE IF NOT EXISTS application_onboarding (
        application_id TEXT PRIMARY KEY, discord_id TEXT NOT NULL,
        steam_id TEXT NOT NULL UNIQUE, payload TEXT NOT NULL, state TEXT NOT NULL)""")
    db.commit()


def identity(name):
    return re.sub(r"^\[[^]]+\]\s*", "", name).strip().casefold()


def enroll(db, google, application_id, discord_id, name, answers):
    answers = applications.validate_answers(applications.CATEGORIES[0], answers)
    steam, did = answers["steam"], str(discord_id)
    existing = db.execute("SELECT steam_id,discord_id,active FROM members WHERE steam_id=? OR discord_id=?", (steam,did)).fetchall()
    if existing:
        if len(existing) != 1 or existing[0] != (steam,did,1):
            raise ValueError("Attendance account conflict or archived member; staff review required. Existing totals preserved.")
        if not db.execute("SELECT 1 FROM sheet_bindings WHERE steam_id=?", (steam,)).fetchone():
            raise ValueError("Existing member has no verified Sheet mapping. Staff must bind their existing row; totals were not reset.")
        return "Existing attendance link and Sheet mapping preserved; no totals reset."
    pending = db.execute("SELECT discord_id,steam_id FROM link_requests WHERE status='pending' AND (discord_id=? OR steam_id=?)", (did,steam)).fetchall()
    if any(row != (did,steam) for row in pending):
        raise ValueError("Pending account claim conflicts; staff review required.")
    job = db.execute("SELECT discord_id,steam_id,payload,state FROM application_onboarding WHERE application_id=?", (str(application_id),)).fetchone()
    if job:
        if job[:2] != (did,steam) or job[3] != "verified":
            raise ValueError("Earlier onboarding needs staff reconciliation. No Sheet write repeated.")
        payload = json.loads(job[2])
    else:
        label = "[FD] " + re.sub(r"^\[[^]]+\]\s*", "", name).strip()
        if not identity(label) or len(label) > 100:
            raise ValueError("Applicant display name needs staff review.")
        snapshot = google.snapshot()
        if any(identity(entry["name"]) == identity(label) for entry in snapshot["entries"]):
            raise ValueError("A similarly named tracker entry already exists. Staff must verify its identity and preserve its existing total.")
        row = google.new_member_row()
        if db.execute("SELECT 1 FROM sheet_bindings WHERE sheet_row=?", (row,)).fetchone():
            raise ValueError("Proposed row is reserved locally; staff review required.")
        now = dt.datetime.now(UTC)
        since = (now + dt.timedelta(hours=eastern_offset(now))).date().isoformat()
        payload = {"row":row,"label":label,"since":since}
        with db:
            db.execute("INSERT INTO application_onboarding VALUES (?,?,?,?,'sending')",
                       (str(application_id),did,steam,json.dumps(payload)))
        # A lost response must never cause a second new-member row on retry.
        google.add_member(row,label)
        with db:
            db.execute("UPDATE application_onboarding SET state='verified' WHERE application_id=?", (str(application_id),))
    source = next((entry for entry in google.snapshot()["entries"] if entry["row"] == payload["row"]), None)
    if not source or source["name"] != payload["label"] or str(source["ops"]) != "0":
        raise ValueError("New tracker entry changed before local linking; staff review required.")
    with db:
        db.execute("INSERT INTO members (steam_id,discord_id,display_name,baseline_ops,tracking_since) VALUES (?,?,?,0,?)",
                   (steam,did,payload["label"],payload["since"]))
        db.execute("INSERT INTO sheet_bindings VALUES (?,?,?,0)", (steam,payload["row"],payload["label"]))
        db.execute("UPDATE link_requests SET status='approved' WHERE discord_id=? AND steam_id=?", (did,steam))
        db.execute("UPDATE application_onboarding SET state='complete' WHERE application_id=?", (str(application_id),))
    return "Attendance linked and new tracker entry created at zero; counting starts today (Eastern)."
