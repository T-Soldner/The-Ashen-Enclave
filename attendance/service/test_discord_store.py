import ast
import datetime as dt
from pathlib import Path
import sqlite3
import tempfile
import unittest

from attendance import link
from collector import connect
from discord_store import Store, authorize, steam_identity
from discord_bot import pending_entry, pending_pages, validate_token

UID = "76561198000000001"
DID = "248567812203872257"
ADMIN = "123456789012345678"


class DiscordStoreTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.path = Path(self.temp.name) / "attendance.sqlite3"
        connect(self.path).close()
        self.store = Store(self.path)

    def tearDown(self):
        self.temp.cleanup()

    def test_missing_database_refused(self):
        with self.assertRaises(ValueError):
            Store(Path(self.temp.name) / "missing.sqlite3")

    def test_parse_identity(self):
        self.assertEqual(steam_identity(UID), UID)
        self.assertEqual(steam_identity(f"https://steamcommunity.com/profiles/{UID}/"), UID)
        for invalid in ("HC123", "https://steamcommunity.com/id/person", f"https://evil.com/profiles/{UID}"):
            with self.assertRaises(ValueError):
                steam_identity(invalid)

    def test_permissions(self):
        authorize(1, 1)
        authorize(1, 1, is_admin=True, staff=True)
        for guild, admin in ((None, True), (2, True), (1, False)):
            with self.assertRaises(PermissionError):
                authorize(guild, 1, is_admin=admin, staff=True)

    def test_submission_is_not_a_link(self):
        self.store.request(DID, UID)
        self.assertEqual(len(self.store.pending()), 1)
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT count(*) FROM members").fetchone()[0]), 0)
        self.assertIn("pending", self.store.status(DID))

    def test_approval_and_audit(self):
        self.store.request(DID, UID)
        self.store.approve(ADMIN, DID, "Edonn", "2026-11-07", 39, "2026-03-10")
        row = self.store.run(lambda db: db.execute("SELECT steam_id,baseline_ops,tracking_since FROM members").fetchone())
        self.assertEqual(row, (UID, 39, "2026-11-07"))
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT joined_date FROM member_dates").fetchone()[0]), "2026-03-10")
        self.assertEqual(self.store.pending(), [])
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT count(*) FROM bot_audit").fetchone()[0]), 2)

    def test_duplicate_and_existing_link_protection(self):
        self.store.request(DID, UID)
        with self.assertRaises(ValueError):
            self.store.request(DID, UID)
        with self.assertRaises(ValueError):
            self.store.request(ADMIN, UID)
        self.store.approve(ADMIN, DID, "Edonn", "2026-11-07", 39)
        with self.assertRaises(ValueError):
            self.store.request(DID, "76561198000000002")

    def test_reject_and_resubmit(self):
        self.store.request(DID, UID)
        self.store.reject(ADMIN, DID)
        self.assertEqual(self.store.pending(), [])
        self.store.request(DID, UID)
        self.assertEqual(len(self.store.pending()), 1)

    def test_conflict_approval_rolls_back(self):
        self.store.request(DID, UID)
        self.store.run(lambda db: link(db, UID, ADMIN, "Existing", "2026-11-07", 5))
        with self.assertRaises(sqlite3.IntegrityError):
            self.store.approve(ADMIN, DID, "Conflict", "2026-11-07", 39)
        self.assertEqual(len(self.store.pending()), 1)

    def test_existing_cli_link_is_readable(self):
        self.store.run(lambda db: link(db, UID, DID, "Edonn", "2099-11-07", 39))
        self.assertIn("39", self.store.status(DID))
        self.assertIn("starts", self.store.status(DID))
        self.assertIn("Recorded events: 0", self.store.health())

    def test_bot_source_syntax(self):
        ast.parse(Path(__file__).with_name("discord_bot.py").read_text())

    def test_command_group_names(self):
        tree = ast.parse(Path(__file__).with_name("discord_bot.py").read_text())
        names = {keyword.value.value for node in ast.walk(tree)
                 if isinstance(node, ast.Call) and isinstance(node.func, ast.Name) and node.func.id == "AttendanceGroup"
                 for keyword in node.keywords if keyword.arg == "name"}
        self.assertEqual(names, {"tae", "tae-admin"})

    def test_pending_lists_nickname_username_and_ids(self):
        row = (DID, UID, "2026-11-02T12:00:00+00:00")
        text = pending_entry(row, "[MR] Character Name", "discord_username")
        for value in ("[MR] Character Name", "@discord_username", DID, UID, row[2]):
            self.assertIn(value, text)
        fallback = pending_entry(row)
        self.assertIn("lookup unavailable", fallback)
        self.assertIn(DID, fallback)

    def test_pending_pages_preserve_all_twenty_requests(self):
        blocks = [pending_entry((str(100000000000000000 + i), UID, "2026-11-02"), "x" * 100, "u" * 32) for i in range(20)]
        pages = list(pending_pages(blocks))
        self.assertGreater(len(pages), 1)
        self.assertTrue(all(len(page) <= 1900 for page in pages))
        for block in blocks:
            self.assertTrue(any(block in page for page in pages))

    def test_token_paste_validation(self):
        self.assertEqual(validate_token(" abc.DEF_ghi-jkl "), "abc.DEF_ghi-jkl")
        for invalid in ("", "abc\r\ndef", "abc\x16def", "abc\x00def", "Bot abc", '"abc"', "abc\tdef", "abc\u200bdef"):
            with self.subTest(character_case=repr(invalid)):
                with self.assertRaises(ValueError) as error:
                    validate_token(invalid)
                if invalid:
                    self.assertNotIn(invalid, str(error.exception))


if __name__ == "__main__":
    unittest.main()
