import sqlite3
import unittest

from membership import HOUSE_KARR_ROLE, roster_report


class RosterTests(unittest.TestCase):
    def test_categories_and_no_writes(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        db.executescript("""
            CREATE TABLE members(discord_id TEXT,display_name TEXT,active INTEGER);
            CREATE TABLE link_requests(discord_id TEXT,status TEXT);
            INSERT INTO members VALUES ('1','Present',1),('2','Departed',1),
                ('3','Without role',1),('4','Archived',0);
            INSERT INTO link_requests VALUES ('5','pending');
        """)
        before = db.total_changes
        result = roster_report(db, [(1, "Present", [HOUSE_KARR_ROLE]),
                                   (3, "Without role", []),
                                   (5, "Applicant", [HOUSE_KARR_ROLE])])
        self.assertIn("House Karr members missing active tracking: 1", result)
        self.assertIn("Tracked members no longer in Discord: 1", result)
        self.assertIn("Tracked members still in Discord without House Karr: 1", result)
        self.assertIn("registration pending", result)
        self.assertNotIn("Archived", result)
        self.assertEqual(before, db.total_changes)

