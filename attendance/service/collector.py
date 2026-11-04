"""Local RPT evidence archive. No network requests or automatic promotions."""
import argparse
import datetime as dt
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import sys
import time
from attendance import link, report

MARKER = "TAE_ATTENDANCE_V1|"
RECORD_START = re.compile(r'^\s*(?:(?:\d{4}/\d{1,2}/\d{1,2},?\s+)?\d{1,2}:\d{2}:\d{2}(?:\.\d+)?\s+)?"TAE_ATTENDANCE_V1\|')


def connect(path):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(path, timeout=30)
    db.execute("PRAGMA journal_mode=WAL")
    db.executescript("""
        CREATE TABLE IF NOT EXISTS members (
            steam_id TEXT PRIMARY KEY, discord_id TEXT UNIQUE,
            display_name TEXT, baseline_ops INTEGER NOT NULL DEFAULT 0,
            active INTEGER NOT NULL DEFAULT 1
        );
        CREATE TABLE IF NOT EXISTS events (
            session TEXT NOT NULL, sequence INTEGER NOT NULL,
            utc TEXT NOT NULL, kind TEXT NOT NULL, uids TEXT NOT NULL,
            source TEXT NOT NULL, PRIMARY KEY (session, sequence)
        );
        CREATE TABLE IF NOT EXISTS cursors (
            source TEXT PRIMARY KEY, offset INTEGER NOT NULL,
            prefix_hash TEXT NOT NULL
        );
        CREATE TABLE IF NOT EXISTS observed_players (
            steam_id TEXT PRIMARY KEY, name TEXT NOT NULL, source TEXT NOT NULL
        );
        CREATE TABLE IF NOT EXISTS rejected_events (
            source TEXT NOT NULL, offset INTEGER NOT NULL,
            line_hash TEXT NOT NULL, raw_line TEXT NOT NULL, error TEXT NOT NULL,
            PRIMARY KEY (source, offset, line_hash)
        );
    """)
    if "tracking_since" not in {row[1] for row in db.execute("PRAGMA table_info(members)")}:
        db.execute("ALTER TABLE members ADD COLUMN tracking_since TEXT")
        db.commit()
    return db


def parse(line):
    if not RECORD_START.match(line):
        return None
    # Only accept the marker at the start of an engine-quoted message.
    payload = line.split(MARKER, 1)[1].rstrip()
    if not payload.endswith('END"'):
        raise ValueError("Incomplete attendance record")
    parts = payload[:-1].split("|")
    if len(parts) != 6 or parts[5] != "END":
        raise ValueError("Invalid attendance record")
    session, sequence, stamp, kind, uids, _ = parts
    if kind not in {"JOIN", "LEAVE", "PRESENCE", "END"} or not session or not sequence.isdecimal():
        raise ValueError("Invalid attendance header")
    values = [int(x) for x in stamp.split(",")]
    if len(values) != 7:
        raise ValueError("Expected UTC year through milliseconds")
    utc = dt.datetime(*values[:6], microsecond=values[6] * 1000,
                      tzinfo=dt.timezone.utc).isoformat()
    identities = uids.split(",") if uids else []
    if any(not re.fullmatch(r"[0-9]{17}", uid) for uid in identities):
        raise ValueError("Invalid SteamID64")
    return session, int(sequence), utc, kind, json.dumps(identities)


def ingest(db, path):
    source = str(Path(path).resolve())
    inserted = 0
    # Event inserts and cursor advancement commit together.
    with db, open(path, "rb") as stream:
        size = stream.seek(0, 2)
        cursor = db.execute("SELECT offset,prefix_hash FROM cursors WHERE source=?", (source,)).fetchone()
        offset = cursor[0] if cursor else 0
        stream.seek(0)
        prefix = hashlib.sha256(stream.read(min(offset, 512))).hexdigest()
        if offset > size or (cursor and prefix != cursor[1]):
            offset = 0
        stream.seek(offset)
        while True:
            start = stream.tell()
            raw = stream.readline()
            if not raw:
                break
            if not raw.endswith(b"\n"):
                stream.seek(start)
                break
            line = raw.decode("utf-8", errors="replace")
            identity = re.fullmatch(r'\s*(?:(?:\d{4}/\d{1,2}/\d{1,2},?\s+)?\d{1,2}:\d{2}:\d{2}(?:\.\d+)?\s+)?"TAE_IDENTITY_V1\|([0-9]{17})\|([0-9,]{1,800})\|END"\s*', line)
            if identity:
                try:
                    codes = [int(value) for value in identity[2].split(",")]
                    name = "".join(chr(value) for value in codes)
                    if not 1 <= len(name) <= 100 or any(ord(c) < 32 or 0xD800 <= ord(c) <= 0xDFFF for c in name):
                        raise ValueError("Invalid player name")
                    db.execute("INSERT OR REPLACE INTO observed_players VALUES (?,?,?)", (identity[1],name,source))
                except (ValueError, OverflowError):
                    pass
                continue
            try:
                event = parse(line)
            except ValueError as error:
                db.execute("INSERT OR IGNORE INTO rejected_events VALUES (?,?,?,?,?)",
                           (source, start, hashlib.sha256(raw).hexdigest(), line, str(error)))
                print(f"WARNING: quarantined attendance record {source}:{start}: {error}",
                      file=sys.stderr, flush=True)
                continue
            if event:
                result = db.execute("INSERT OR IGNORE INTO events VALUES (?,?,?,?,?,?)", (*event, source))
                inserted += result.rowcount
        offset = stream.tell()
        stream.seek(0)
        prefix = hashlib.sha256(stream.read(min(offset, 512))).hexdigest()
        db.execute("INSERT OR REPLACE INTO cursors VALUES (?,?,?)", (source, offset, prefix))
    return inserted


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--db", required=True, type=Path)
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("init")
    sub.add_parser("status")
    sub.add_parser("members")
    member = sub.add_parser("link-member")
    member.add_argument("--steam-id", required=True)
    member.add_argument("--discord-id", required=True)
    member.add_argument("--name", required=True)
    member.add_argument("--since", required=True, help="Eastern date when new counting begins, YYYY-MM-DD")
    member.add_argument("--baseline", type=int, default=0, help="Existing total before --since")
    preview = sub.add_parser("report")
    preview.add_argument("--from", dest="start", required=True, type=dt.date.fromisoformat)
    preview.add_argument("--through", required=True, type=dt.date.fromisoformat)
    for name in ("import", "watch"):
        command = sub.add_parser(name)
        command.add_argument("--rpt-dir", required=True, type=Path)
    backup = sub.add_parser("backup")
    backup.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    db = connect(args.db)
    try:
        if args.command == "init":
            print(f"Database ready: {args.db.resolve()}")
        elif args.command == "link-member":
            try:
                link(db, args.steam_id, args.discord_id, args.name, args.since, args.baseline)
            except (ValueError, sqlite3.IntegrityError) as error:
                parser.error(str(error))
            print("Member linked locally. No Discord or Sheet changes made.")
        elif args.command == "members":
            for row in db.execute("SELECT display_name,steam_id,discord_id,baseline_ops,tracking_since FROM members ORDER BY display_name"):
                print(row)
        elif args.command == "report":
            try:
                print(json.dumps(report(db, args.start, args.through), indent=2))
            except ValueError as error:
                parser.error(str(error))
        elif args.command == "status":
            print("Recorded events:", db.execute("SELECT count(*) FROM events").fetchone()[0])
            print("Latest UTC event:", db.execute("SELECT max(utc) FROM events").fetchone()[0])
            print("Rejected records requiring review:", db.execute("SELECT count(*) FROM rejected_events").fetchone()[0])
        elif args.command == "backup":
            if args.output.resolve() == args.db.resolve():
                parser.error("Backup must be a different file")
            args.output.parent.mkdir(parents=True, exist_ok=True)
            with sqlite3.connect(args.output) as target:
                db.backup(target)
            print(f"Backup saved: {args.output}")
        else:
            if not args.rpt_dir.is_dir():
                parser.error("RPT directory does not exist")
            try:
                print(f"Reading RPTs in {args.rpt_dir.resolve()}; database {args.db.resolve()}", flush=True)
                while True:
                    for path in sorted(args.rpt_dir.glob("*.rpt")):
                        count = ingest(db, path)
                        if count:
                            print(f"{path.name}: imported {count} events", flush=True)
                    if args.command == "import":
                        break
                    time.sleep(5)
            except KeyboardInterrupt:
                pass
    finally:
        db.close()


if __name__ == "__main__":
    main()
