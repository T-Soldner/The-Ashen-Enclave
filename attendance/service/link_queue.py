"""Staff-approved account detection. Names suggest matches, never prove identity."""
import datetime as dt
import json
import re

from attendance import UTC, eastern_offset
import clan_training as policy
import sheets_sync


def initialize(db):
    db.execute("""CREATE TABLE IF NOT EXISTS detected_links (
        steam_id TEXT PRIMARY KEY, name TEXT NOT NULL, state TEXT NOT NULL DEFAULT 'pending',
        delivery TEXT NOT NULL DEFAULT 'pending', message TEXT, payload TEXT)""")
    db.commit()


def identity(name):
    return re.sub(r"^\[[^]]+\]\s*", "", name).strip().casefold()


def discover(db):
    initialize(db)
    with db:
        db.execute("""UPDATE detected_links SET state='resolved'
            WHERE state='pending' AND EXISTS (SELECT 1 FROM members m WHERE m.steam_id=detected_links.steam_id)""")
        db.execute("""INSERT OR IGNORE INTO detected_links (steam_id,name)
            SELECT o.steam_id,o.name FROM observed_players o
            WHERE NOT EXISTS (SELECT 1 FROM members m WHERE m.steam_id=o.steam_id)""")
        db.execute("""INSERT OR IGNORE INTO detected_links (steam_id,name)
            SELECT r.steam_id,'Registration request' FROM link_requests r
            WHERE r.status='pending' AND NOT EXISTS (SELECT 1 FROM members m WHERE m.steam_id=r.steam_id)""")
    return db.execute("SELECT steam_id,name FROM detected_links WHERE state='pending' AND delivery='pending' LIMIT 5").fetchall()


def suggestions(db, steam, members):
    row = db.execute("SELECT name FROM detected_links WHERE steam_id=?", (steam,)).fetchone()
    if not row:
        return []
    claims = {r[0] for r in db.execute("SELECT discord_id FROM link_requests WHERE steam_id=? AND status='pending'", (steam,))}
    linked = {r[0] for r in db.execute("SELECT discord_id FROM members")}
    return [m for m in members if not m["bot"] and policy.HOUSE in m["roles"]
            and str(m["id"]) not in linked and (str(m["id"]) in claims or identity(m["name"]) == identity(row[0]))]


def conflicts(db, steam, did):
    if db.execute("SELECT 1 FROM members WHERE steam_id=? OR discord_id=?", (steam,did)).fetchone():
        raise ValueError("An account is already linked or archived. Existing links and totals were not changed.")
    if db.execute("SELECT 1 FROM link_requests WHERE status='pending' AND (steam_id=? OR discord_id=?) AND NOT (steam_id=? AND discord_id=?)", (steam,did,steam,did)).fetchone():
        raise ValueError("Conflicting registration claim. Resolve it before approval.")


def plan(db, google, steam, member, row=None):
    initialize(db)
    did = str(member["id"])
    if member["bot"] or policy.HOUSE not in member["roles"]:
        raise ValueError("Choose a current House Karr member, not a bot.")
    state = db.execute("SELECT state FROM detected_links WHERE steam_id=?", (steam,)).fetchone()
    if state != ("pending",):
        raise ValueError("Detection is no longer pending; inspect its existing receipt.")
    conflicts(db,steam,did)
    snapshot = google.snapshot()
    matches = [e for e in snapshot["entries"] if (e["row"] == row if row is not None
               else identity(e["name"]) == identity(member["name"]))]
    if (row is not None and not matches) or len(matches) > 1:
        raise ValueError("Tracker row missing or ambiguous. Choose the exact existing row before approval.")
    if matches:
        entry = matches[0]
        if entry["row"] in snapshot["formula_rows"] or entry["row"] < 2:
            raise ValueError("Calculated/header rows cannot be linked.")
        baseline = sheets_sync.number(entry["ops"])
        selected_row, label, create = entry["row"], entry["name"], False
    else:
        selected_row, label, baseline, create = google.new_member_row(), member["name"], 0, True
    if db.execute("SELECT 1 FROM sheet_bindings WHERE sheet_row=?", (selected_row,)).fetchone():
        raise ValueError("Tracker row already belongs to another linked member.")
    now = dt.datetime.now(UTC)
    since = (now + dt.timedelta(hours=eastern_offset(now))).date().isoformat()
    return dict(steam=steam,discord=did,row=selected_row,label=label,baseline=baseline,create=create,
                since=since,expires=(now+dt.timedelta(minutes=10)).isoformat())


def approve(db, google, payload, actor, member):
    if dt.datetime.now(UTC) > dt.datetime.fromisoformat(payload["expires"]):
        raise ValueError("Preview expired. Review the link again.")
    if str(member["id"]) != payload["discord"] or member["bot"] or policy.HOUSE not in member["roles"]:
        raise ValueError("Member no longer eligible. Review again.")
    conflicts(db,payload["steam"],payload["discord"])
    fresh = plan(db,google,payload["steam"],member,None if payload["create"] else payload["row"])
    if any(fresh[k] != payload[k] for k in ("steam","discord","row","label","baseline","create","since")):
        raise ValueError("Tracker/member changed since preview. Review again; no changes made.")
    with db:
        db.execute("BEGIN IMMEDIATE")
        conflicts(db,payload["steam"],payload["discord"])
        changed = db.execute("UPDATE detected_links SET state='applying',payload=? WHERE steam_id=? AND state='pending'",
                             (json.dumps(payload),payload["steam"])).rowcount
        if changed != 1:
            raise ValueError("Another reviewer already processed this detection.")
    try:
        if payload["create"]:
            google.add_member(payload["row"],payload["label"])
        with db:
            conflicts(db,payload["steam"],payload["discord"])
            db.execute("INSERT INTO members (steam_id,discord_id,display_name,baseline_ops,tracking_since) VALUES (?,?,?,?,?)",
                       (payload["steam"],payload["discord"],payload["label"],payload["baseline"],payload["since"]))
            db.execute("INSERT INTO sheet_bindings VALUES (?,?,?,?)", (payload["steam"],payload["row"],payload["label"],payload["baseline"]))
            db.execute("UPDATE link_requests SET status='approved' WHERE steam_id=? AND discord_id=?", (payload["steam"],payload["discord"]))
            db.execute("UPDATE detected_links SET state='approved' WHERE steam_id=?", (payload["steam"],))
            db.execute("INSERT INTO bot_audit (utc,actor_id,action,target_id,details) VALUES (?,?,?,?,?)",
                       (dt.datetime.now(UTC).isoformat(),str(actor),"approve-detected-link",payload["discord"],json.dumps(payload)))
    except BaseException:
        with db:
            db.execute("UPDATE detected_links SET state='uncertain' WHERE steam_id=? AND state='applying'", (payload["steam"],))
        raise
    return "Account linked and tracker row mapped. Starting total preserved: " + str(payload["baseline"]) + "."
