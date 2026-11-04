from pathlib import Path
from contextlib import closing
import sqlite3
import tempfile
import unittest
from unittest.mock import patch

from backup_database import backup


class BackupTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        (self.root / "data").mkdir()
        self.source = self.root / "data/attendance.sqlite3"

    def populate(self):
        db = sqlite3.connect(self.source)
        self.addCleanup(db.close)
        db.execute("PRAGMA journal_mode=WAL")
        db.execute("CREATE TABLE members (name TEXT)")
        db.execute("INSERT INTO members VALUES ('Test Member')")
        db.commit()
        return db

    def test_live_wal_backup_is_verified_and_source_unchanged(self):
        source = self.populate()
        path = backup(self.root)
        with closing(sqlite3.connect(path)) as saved:
            self.assertEqual(saved.execute("SELECT * FROM members").fetchall(), [("Test Member",)])
            self.assertEqual(saved.execute("PRAGMA quick_check").fetchone(), ("ok",))
        self.assertEqual(source.execute("SELECT * FROM members").fetchall(), [("Test Member",)])

    def test_retention_only_removes_matching_automatic_snapshots(self):
        self.populate()
        directory = self.root / "backups"
        directory.mkdir()
        manual = directory / "before-training.sqlite3"
        manual.write_bytes(b"preserve")
        unrelated = directory / "auto-not-a-backup.sqlite3"
        unrelated.write_bytes(b"preserve")
        for day in range(1, 5):
            (directory / f"auto-202601{day:02}T000000000000Z.sqlite3").write_bytes(b"old")
        current = backup(self.root, keep=2)
        self.assertTrue(current.is_file())
        self.assertTrue(manual.is_file())
        self.assertTrue(unrelated.is_file())
        self.assertEqual(len(list(directory.glob("auto-202601*.sqlite3"))), 1)

    def test_missing_database_does_not_create_one(self):
        with self.assertRaises(ValueError):
            backup(self.root)
        self.assertFalse(self.source.exists())

    def test_failed_backup_preserves_existing_and_cleans_partial(self):
        self.source.write_bytes(b"not a database")
        directory = self.root / "backups"
        directory.mkdir()
        old = directory / "auto-20260101T000000000000Z.sqlite3"
        old.write_bytes(b"preserve")
        with self.assertRaises(sqlite3.DatabaseError):
            backup(self.root, keep=1)
        self.assertEqual(old.read_bytes(), b"preserve")
        self.assertEqual(list(directory.iterdir()), [old])

    def test_empty_database_is_refused(self):
        sqlite3.connect(self.source).close()
        with self.assertRaises(ValueError):
            backup(self.root)

    def test_invalid_retention_refused(self):
        with self.assertRaises(ValueError):
            backup(self.root, 0)

    def test_reparse_path_is_refused(self):
        self.populate()
        with patch("backup_database.Path.is_symlink", return_value=True):
            with self.assertRaises(ValueError):
                backup(self.root)
