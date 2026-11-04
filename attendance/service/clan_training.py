"""Clan/training policy and durable records; no Discord or Google SDK required."""
import datetime as dt
import json

from attendance import UTC

HOUSE = 1477486340101902512
FREELANCER = 1477486340080799940
LEADER = 1477486340051570794
SECOND = 1477486340051570793
ADVISOR = 1477486340030333094
PLANNING_CHANNEL = 1477486341691408487
CLANS = {
    "acklay": {"name":"Acklay", "role":1477486340080799945, "channel":1549895011401728030, "limit":8},
    "rook": {"name":"Rook", "role":1477486340080799943, "channel":1477486341469241555, "limit":8},
    "shyyyo": {"name":"Shyyyo", "role":1510404359228362934, "channel":1510405139746525184, "limit":4},
}
# key: (display name, primary point cost, Discord primary-role ID)
SPECIALIZATIONS = {
    "phoenix":("Rising Phoenix",4,1477486340051570792),
    "lancer":("Lancer",8,1505320345807229109),
    "medic":("Medic",5,1477486340051570791),
    "marksman":("Marksman",3,1477486340051570790),
    "at_aa":("AT/AA",6,1477486340038856904),
    "grenadier":("Grenadier",3,1477486340038856903),
    "cqc":("CQC",3,1477486340038856902),
    "demo":("Demolitions",5,1477486340038856901),
    "sniper":("Sniper",5,1477486340038856900),
    "communications":("Communications",2,1477486340038856899),
    "heavy":("Heavy Weapons",5,1477486340038856898),
    "suas":("SUAS",3,1541884796144459807),
    "csw":("CSW",9,1541884859473993789),
    "rifleman":("Rifleman",0,None),
    "dropship":("Dropship Pilot",9,1477486340030333099),
    "starfighter":("Starfighter Pilot",9,1477486340030333098),
}
PILOTS = {"dropship", "starfighter"}
PRIMARY_ROLES = {value[2] for value in SPECIALIZATIONS.values() if value[2]}
CLAN_ROLES = {value["role"] for value in CLANS.values()}


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS clan_requests (
            id TEXT PRIMARY KEY, guild TEXT NOT NULL, member TEXT NOT NULL,
            clan TEXT NOT NULL, why TEXT NOT NULL, status TEXT NOT NULL DEFAULT 'pending',
            delivery TEXT NOT NULL DEFAULT 'pending', message TEXT UNIQUE,
            reviewer TEXT, reason TEXT, plan TEXT, updated TEXT NOT NULL);
        CREATE UNIQUE INDEX IF NOT EXISTS one_open_clan_application ON clan_requests(guild,member)
            WHERE status IN ('pending','applying','uncertain');
        CREATE TABLE IF NOT EXISTS training_records (
            guild TEXT NOT NULL, member TEXT NOT NULL, name TEXT NOT NULL,
            certified TEXT NOT NULL, primaries TEXT NOT NULL, revision INTEGER NOT NULL,
            trainer TEXT NOT NULL, updated TEXT NOT NULL, PRIMARY KEY(guild,member));
        CREATE TABLE IF NOT EXISTS training_jobs (
            guild TEXT NOT NULL, member TEXT NOT NULL, payload TEXT NOT NULL,
            state TEXT NOT NULL, PRIMARY KEY(guild,member));
        CREATE TABLE IF NOT EXISTS clan_transfers (
            guild TEXT NOT NULL, member TEXT NOT NULL, target TEXT NOT NULL,
            actor TEXT NOT NULL, reason TEXT NOT NULL, payload TEXT NOT NULL,
            state TEXT NOT NULL, PRIMARY KEY(guild,member));
        CREATE TABLE IF NOT EXISTS clan_training_audit (
            id INTEGER PRIMARY KEY, utc TEXT NOT NULL, actor TEXT NOT NULL,
            member TEXT NOT NULL, action TEXT NOT NULL, details TEXT NOT NULL,
            delivery TEXT NOT NULL DEFAULT 'pending', message TEXT);
        CREATE TABLE IF NOT EXISTS personnel_sheet_state (
            kind TEXT PRIMARY KEY, state TEXT NOT NULL, payload TEXT NOT NULL);
        CREATE TABLE IF NOT EXISTS personnel_sheet_previews (
            guild TEXT NOT NULL, actor TEXT NOT NULL, digest TEXT NOT NULL,
            utc TEXT NOT NULL, PRIMARY KEY(guild,actor));
        CREATE TABLE IF NOT EXISTS legacy_training_maps (
            guild TEXT NOT NULL, source_row INTEGER NOT NULL, source_name TEXT NOT NULL,
            member TEXT NOT NULL, PRIMARY KEY(guild,source_row));
        CREATE TABLE IF NOT EXISTS legacy_training_imports (
            guild TEXT NOT NULL, member TEXT NOT NULL, source_row INTEGER NOT NULL,
            source_hash TEXT NOT NULL, role_state TEXT NOT NULL, actor TEXT NOT NULL,
            utc TEXT NOT NULL, source_json TEXT NOT NULL, PRIMARY KEY(guild,member));
        CREATE TABLE IF NOT EXISTS legacy_training_snapshots (
            guild TEXT NOT NULL, digest TEXT NOT NULL, utc TEXT NOT NULL,
            payload TEXT NOT NULL, PRIMARY KEY(guild,digest));
        CREATE TABLE IF NOT EXISTS legacy_training_archives (
            guild TEXT NOT NULL, source_row INTEGER NOT NULL, source_name TEXT NOT NULL,
            actor TEXT NOT NULL, utc TEXT NOT NULL, payload TEXT NOT NULL,
            PRIMARY KEY(guild,source_row));
    """)


def now():
    return dt.datetime.now(UTC).isoformat()


def clan_reviewer(admin, roles, clan):
    return bool(admin or (LEADER in roles and CLANS[clan]["role"] in roles))


def trainer_allowed(admin, roles):
    return bool(admin or set(roles) & {LEADER, SECOND, ADVISOR})


def pilot_allowed(admin, roles):
    return bool(admin or (LEADER in roles and CLANS["shyyyo"]["role"] in roles))


def validate_training(certified, primaries, old_certified=(), old_primaries=(), allow_pilot=False):
    certified, primaries = set(certified), set(primaries)
    if not (certified | primaries).issubset(SPECIALIZATIONS):
        raise ValueError("Unknown specialization.")
    if not primaries.issubset(certified):
        raise ValueError("Every primary must also be certified.")
    points = sum(SPECIALIZATIONS[key][1] for key in primaries)
    if points > 9:
        raise ValueError(f"Primary selections cost {points}; the maximum is 9 points.")
    pilot_changes = ((certified ^ set(old_certified)) | (primaries ^ set(old_primaries))) & PILOTS
    if pilot_changes and not allow_pilot:
        raise ValueError("Only administrators or Shyyyo Clan Leaders may change pilot certifications or primaries.")
    return points


def submit_clan(db, identifier, guild, member, clan, why):
    if clan not in CLANS or not 1 <= len(why.strip()) <= 1800:
        raise ValueError("Choose a configured clan and give a reason of 1-1800 characters.")
    with db:
        if db.execute("SELECT 1 FROM clan_requests WHERE guild=? AND member=? AND status IN ('pending','applying','uncertain')", (str(guild),str(member))).fetchone():
            raise ValueError("You already have an open clan application.")
        db.execute("INSERT INTO clan_requests(id,guild,member,clan,why,updated) VALUES (?,?,?,?,?,?)",
                   (str(identifier),str(guild),str(member),clan,why.strip(),now()))
    return str(identifier)


def clan_request(db, identifier, guild):
    row = db.execute("SELECT member,clan,why,status,delivery,message,reviewer,reason,plan FROM clan_requests WHERE id=? AND guild=?", (str(identifier),str(guild))).fetchone()
    if not row:
        raise ValueError("Clan application not found in this server.")
    return dict(zip(("member","clan","why","status","delivery","message","reviewer","reason","plan"),row))


def audit(db, actor, member, action, details):
    return db.execute("INSERT INTO clan_training_audit(utc,actor,member,action,details) VALUES (?,?,?,?,?)",
                      (now(),str(actor),str(member),action,details)).lastrowid


def deny_clan(db, identifier, guild, actor, reason):
    if not 1 <= len(reason.strip()) <= 800:
        raise ValueError("A denial reason of 1-800 characters is required.")
    with db:
        row = clan_request(db,identifier,guild)
        changed = db.execute("UPDATE clan_requests SET status='denied',reviewer=?,reason=?,updated=? WHERE id=? AND status='pending' AND plan IS NULL",
                              (str(actor),reason.strip(),now(),str(identifier))).rowcount
        if changed != 1:
            raise ValueError("Application already decided or role changes need reconciliation.")
        audit(db,actor,row["member"],"clan-denied",reason.strip())


def training_record(db, guild, member):
    row = db.execute("SELECT name,certified,primaries,revision,trainer,updated FROM training_records WHERE guild=? AND member=?", (str(guild),str(member))).fetchone()
    if row is None:
        return None
    return {"name":row[0],"certified":json.loads(row[1]),"primaries":json.loads(row[2]),
            "revision":row[3],"trainer":row[4],"updated":row[5]}


def commit_training(db, guild, member, payload):
    with db:
        current = training_record(db,guild,member)
        if (current["revision"] if current else 0) != payload["revision"]:
            raise ValueError("Training record changed; reopen the editor.")
        db.execute("INSERT OR REPLACE INTO training_records VALUES (?,?,?,?,?,?,?,?)",
                   (str(guild),str(member),payload["name"],json.dumps(payload["certified"]),json.dumps(payload["primaries"]),
                    payload["revision"]+1,payload["actor"],now()))
        db.execute("UPDATE training_jobs SET state='complete' WHERE guild=? AND member=?", (str(guild),str(member)))
        db.execute("UPDATE legacy_training_imports SET role_state='reconciled' WHERE guild=? AND member=?", (str(guild),str(member)))
        return audit(db,payload["actor"],member,"training-updated",json.dumps(payload))
