import tempfile
from pathlib import Path
import unittest

from collector import connect
from discord_store import Store
import onboarding


class Google:
    def __init__(self):
        self.entries = []
        self.writes = 0
        self.fail = False

    def snapshot(self):
        return {"entries": self.entries}

    def new_member_row(self):
        return 2

    def add_member(self, row, label):
        self.writes += 1
        self.entries.append({"row":row,"name":label,"ops":"0"})
        if self.fail:
            raise ValueError("Response lost")


class OnboardingTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        self.addCleanup(self.root.cleanup)
        path = Path(self.root.name)/"test.db"
        connect(path).close()
        Store(path)
        self.db = connect(path)
        self.addCleanup(self.db.close)
        self.google = Google()
        self.answers = dict(source="friend",hours="100.123",record="no",about="hello",steam="76561198000000001")

    def enroll(self):
        return onboarding.enroll(self.db,self.google,"app","123456789012345678","New Member",self.answers)

    def test_creates_link_binding_zero_and_idempotent(self):
        self.enroll()
        row = self.db.execute("SELECT baseline_ops,active,tracking_since FROM members").fetchone()
        self.assertEqual(row[:2], (0,1))
        self.assertTrue(row[2])
        self.assertEqual(self.db.execute("SELECT expected_name FROM sheet_bindings").fetchone()[0],"[FD] New Member")
        self.enroll()
        self.assertEqual(self.google.writes,1)

    def test_duplicate_name_preserves_existing_sheet(self):
        self.google.entries = [{"row":2,"name":"[MV] NEW MEMBER","ops":"29"}]
        with self.assertRaises(ValueError):
            self.enroll()
        self.assertEqual(self.google.writes,0)
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0],0)

    def test_lost_response_never_repeats_write(self):
        self.google.fail = True
        with self.assertRaises(ValueError):
            self.enroll()
        with self.assertRaises(ValueError):
            self.enroll()
        self.assertEqual(self.google.writes,1)

    def test_existing_total_preserved(self):
        self.enroll()
        with self.db:
            self.db.execute("UPDATE members SET baseline_ops=39")
        self.enroll()
        self.assertEqual(self.db.execute("SELECT baseline_ops FROM members").fetchone()[0],39)

    def test_conflicting_account_rejected(self):
        with self.db:
            self.db.execute("INSERT INTO members(steam_id,discord_id,display_name) VALUES (?,?,?)",(self.answers["steam"],"999999999999999999","Existing"))
        with self.assertRaises(ValueError):
            self.enroll()
        self.assertEqual(self.google.writes,0)
