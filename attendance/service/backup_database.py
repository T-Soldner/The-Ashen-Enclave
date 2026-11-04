"""Verified local SQLite snapshots for Windows Task Scheduler; no network access."""
import argparse
from contextlib import closing
from datetime import datetime, timezone
import logging
from logging.handlers import RotatingFileHandler
import os
from pathlib import Path
import re
import sqlite3
import tempfile
import time


AUTO_NAME = re.compile(r"^auto-\d{8}T\d{12}Z\.sqlite3$")


def local_path(path):
    path = Path(os.path.abspath(path))
    if str(path).startswith("\\\\"):
        raise ValueError("Backups require local storage.")
    for part in (path, *path.parents):
        if part.is_symlink() or (hasattr(part, "is_junction") and part.is_junction()):
            raise ValueError("Backup paths must not traverse links or junctions.")
    return path


def backup(root, keep=30):
    if keep < 1:
        raise ValueError("Keep at least one backup.")
    root = local_path(root)
    source = local_path(root / "data/attendance.sqlite3")
    directory = local_path(root / "backups")
    if not source.is_file():
        raise ValueError("Attendance database not found; no empty database created.")
    directory.mkdir(exist_ok=True)
    name = "auto-" + datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ") + ".sqlite3"
    destination = directory / name
    deadline = time.monotonic() + 120

    def progress(status, remaining, total):
        if time.monotonic() > deadline:
            raise TimeoutError("Backup exceeded two minutes; previous backups preserved.")

    fd, temporary = tempfile.mkstemp(prefix=".backup-", suffix=".tmp", dir=directory)
    os.close(fd)
    temporary = Path(temporary)
    try:
        with closing(sqlite3.connect(source.as_uri() + "?mode=ro", uri=True, timeout=10)) as db:
            if not db.execute("SELECT name FROM sqlite_master WHERE type='table'").fetchone():
                raise ValueError("Source database has no tables.")
            with closing(sqlite3.connect(temporary)) as target:
                db.backup(target, pages=256, progress=progress, sleep=0.1)
                if target.execute("PRAGMA quick_check").fetchall() != [("ok",)]:
                    raise ValueError("Backup verification failed; previous backups preserved.")
        # A final filename is only published after the snapshot passes verification.
        temporary.rename(destination)
    finally:
        temporary.unlink(missing_ok=True)

    snapshots = sorted((p for p in directory.iterdir() if AUTO_NAME.fullmatch(p.name)
                        and p.is_file() and not p.is_symlink()), key=lambda p: p.name, reverse=True)
    for old in snapshots[keep:]:
        local_path(old).unlink()
    return destination


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path("D:/TAEAttendance"))
    parser.add_argument("--keep", type=int, default=30)
    args = parser.parse_args()
    root = local_path(args.root)
    logs = local_path(root / "logs")
    logs.mkdir(exist_ok=True)
    handler = RotatingFileHandler(logs / "backup.log", maxBytes=1024*1024, backupCount=3, encoding="utf-8")
    handler.setFormatter(logging.Formatter("%(asctime)s %(levelname)s %(message)s"))
    logger = logging.getLogger("tae.backup")
    logger.setLevel(logging.INFO)
    logger.addHandler(handler)
    try:
        path = backup(root, args.keep)
        logger.info("Verified backup saved: %s; keeping latest %s automatic snapshots.", path.name, args.keep)
        print(f"Verified backup saved: {path}")
        return 0
    except Exception as error:
        logger.error("Backup failed: %s", error)
        print("Backup failed. See logs/backup.log; previous verified backups preserved.")
        return 1
    finally:
        handler.close()
        logger.removeHandler(handler)


if __name__ == "__main__":
    raise SystemExit(main())
