import ast
from pathlib import Path
import tempfile
import unittest
from types import SimpleNamespace as NS

import applications
from collector import connect
from discord_store import Store
from application_ui import find_application_panel, is_application_panel, review_authorized

DID = "123456789012345678"


class ApplicationTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        path = Path(self.root.name) / "test.sqlite3"
        connect(path).close()
        Store(path)
        self.db = connect(path)
        self.answers = {"source": "reddit", "hours": "330", "record": "no", "about": "Hello there", "steam": "76561198000000001"}

    def tearDown(self):
        self.db.close()
        self.root.cleanup()

    def test_active_member_questions_and_steam(self):
        applications.submit(self.db, "1", DID, applications.CATEGORIES[0], self.answers)
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0], 0)
        who, category, answers = applications.reserve_delivery(self.db, "1")
        self.assertEqual(answers, self.answers)
        self.assertEqual(who, DID)

    def test_friend_skips_all_followups(self):
        applications.submit(self.db,"1",DID,applications.CATEGORIES[2],{"about":"must not retain skipped answer"})
        self.assertEqual(self.db.execute("SELECT answers FROM applications").fetchone()[0],"{}")

    def test_liaison_requires_unit_source_and_invite(self):
        answers = {"unit":"Other unit","source":"a friend","discord":"https://discord.gg/example"}
        applications.submit(self.db,"1",DID,applications.CATEGORIES[1],answers)
        import json
        self.assertEqual(json.loads(self.db.execute("SELECT answers FROM applications").fetchone()[0]),answers)

    def test_invalid_liaison_invite_is_rejected(self):
        with self.assertRaises(ValueError):
            applications.submit(self.db,"1",DID,applications.CATEGORIES[1],{"unit":"Unit","source":"friend","discord":"https://example.com"})

    def test_stream_choice_only_yes_or_no(self):
        with self.assertRaises(ValueError):
            applications.submit(self.db,"1",DID,applications.CATEGORIES[0],{**self.answers,"record":"sometimes"})

    def test_duplicate_open_application_blocked(self):
        applications.submit(self.db, "1", DID, applications.CATEGORIES[2], {})
        with self.assertRaises(ValueError):
            applications.submit(self.db, "2", DID, applications.CATEGORIES[0], self.answers)

    def test_fractional_hours_preserved(self):
        for hours in ("100.123", "0.001", "100000.000"):
            cleaned = applications.validate_answers(applications.CATEGORIES[0], {**self.answers, "hours": hours})
            self.assertEqual(cleaned["hours"], hours)

    def test_invalid_fractional_hours_rejected(self):
        for hours in ("100000.001", "-0.1", "NaN", "1e3", "100..123"):
            with self.assertRaises(ValueError):
                applications.validate_answers(applications.CATEGORIES[0], {**self.answers, "hours": hours})

    def test_invalid_steam_hours_or_missing_answers_rejected(self):
        for changed in ({"steam": "username"}, {"hours": "lots"}, {"about": ""}):
            with self.assertRaises(ValueError):
                applications.submit(self.db, "1", DID, applications.CATEGORIES[0], {**self.answers, **changed})

    def test_delivery_receipt_blocks_duplicate(self):
        applications.submit(self.db, "1", DID, applications.CATEGORIES[2], {})
        applications.reserve_delivery(self.db, "1")
        applications.finish_delivery(self.db, "1", "99")
        with self.assertRaises(ValueError):
            applications.reserve_delivery(self.db, "1")

    def test_uncertain_delivery_does_not_retry(self):
        applications.submit(self.db, "1", DID, applications.CATEGORIES[2], {})
        applications.reserve_delivery(self.db, "1")
        applications.finish_delivery(self.db, "1")
        with self.assertRaises(ValueError):
            applications.reserve_delivery(self.db, "1")

    def test_review_does_not_assign_roles_or_attendance(self):
        applications.submit(self.db, "1", DID, applications.CATEGORIES[2], {})
        applications.review(self.db, DID, "1", True)
        self.assertEqual(self.db.execute("SELECT status FROM applications").fetchone()[0], "approved")
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0], 0)
        self.assertEqual(self.db.execute("SELECT count(*) FROM operation_credits").fetchone()[0], 0)

    def test_approved_active_application_only_prepares_pending_claim(self):
        applications.submit(self.db, "1", DID, applications.CATEGORIES[0], self.answers)
        text = applications.review(self.db, DID, "1", True)
        self.assertIn("queued", text)
        self.assertEqual(self.db.execute("SELECT status FROM link_requests").fetchone()[0], "pending")
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0], 0)

    def test_ui_syntax_and_modal_limits(self):
        ast.parse(Path(__file__).with_name("application_ui.py").read_text())
        self.assertEqual(len(applications.FIELDS), 5)
        self.assertTrue(all(len(label) <= 45 for _,label,_ in applications.FIELDS))

    def test_deny_requires_nonblank_reason(self):
        applications.submit(self.db,"1",DID,applications.CATEGORIES[2],{})
        for reason in (None,"","   ","x"*801):
            with self.assertRaises(ValueError):
                applications.review(self.db,DID,"1",False,reason)
        self.assertEqual(self.db.execute("SELECT status FROM applications").fetchone()[0],"pending")

    def test_deny_preserves_reason_and_reviewer(self):
        applications.submit(self.db,"1",DID,applications.CATEGORIES[2],{})
        applications.review(self.db,DID,"1",False,"  Test application only  ")
        row = self.db.execute("SELECT status,reviewed_by,reviewed_utc,denial_reason FROM applications").fetchone()
        self.assertEqual((row[0],row[1],row[3]),("rejected",DID,"Test application only"))
        self.assertIsNotNone(row[2])
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0],0)

    def test_second_decision_does_not_overwrite_first(self):
        applications.submit(self.db,"1",DID,applications.CATEGORIES[2],{})
        applications.review(self.db,DID,"1",True)
        with self.assertRaises(ValueError):
            applications.review(self.db,DID,"1",False,"Second reviewer")
        self.assertEqual(self.db.execute("SELECT status FROM applications").fetchone()[0],"approved")
        self.assertEqual(self.db.execute("SELECT count(*) FROM bot_audit WHERE action LIKE 'application-%'").fetchone()[0],1)

    def test_review_buttons_require_admin_and_correct_channel(self):
        self.assertTrue(review_authorized(1,1,True,2,2))
        self.assertFalse(review_authorized(1,1,False,2,2))
        self.assertFalse(review_authorized(3,1,True,2,2))
        self.assertFalse(review_authorized(1,1,True,3,2))
        self.assertFalse(review_authorized(None,1,True,2,2))

    def test_recruitment_officer_can_review_without_admin(self):
        role = applications.RECRUITMENT_OFFICER_ROLE
        self.assertEqual(role,1477486340101902517)
        self.assertTrue(review_authorized(1,1,False,2,2,role_ids=[role]))
        self.assertFalse(review_authorized(1,1,False,3,2,role_ids=[role]))
        self.assertFalse(review_authorized(3,1,False,2,2,role_ids=[role]))
        self.assertFalse(review_authorized(None,1,False,2,2,role_ids=[role]))
        self.assertFalse(review_authorized(1,1,False,2,2,role_ids=[role+1]))

    def test_review_permission_exception_does_not_open_other_admin_actions(self):
        tree = ast.parse(Path(__file__).with_name("application_ui.py").read_text())
        for node in ast.walk(tree):
            if isinstance(node,ast.AsyncFunctionDef) and node.name in {"application_pending","application_panel"}:
                decorators = [ast.unparse(item) for item in node.decorator_list]
                self.assertIn("app_commands.checks.has_permissions(administrator=True)",decorators)

    def test_legacy_application_schema_migrates(self):
        import sqlite3
        path = Path(self.root.name)/"legacy.sqlite3"
        old = sqlite3.connect(path)
        old.execute("CREATE TABLE applications (application_id TEXT PRIMARY KEY,discord_id TEXT NOT NULL,category TEXT NOT NULL,answers TEXT NOT NULL,submitted_utc TEXT NOT NULL,status TEXT NOT NULL DEFAULT 'pending',delivery TEXT NOT NULL DEFAULT 'pending',review_message_id TEXT)")
        old.execute("INSERT INTO applications VALUES ('old',?,'Friend of the unit','{}','2026-11-02','pending','sent','555555555555555555')",(DID,))
        old.commit()
        old.close()
        Store(path)
        migrated = connect(path)
        try:
            row = migrated.execute("SELECT application_id,status,denial_reason FROM applications").fetchone()
            self.assertEqual(row,("old","pending",None))
        finally:
            migrated.close()


class PanelRecoveryTests(unittest.IsolatedAsyncioTestCase):
    def message(self, author, custom_id):
        return NS(author=NS(id=author), components=[NS(children=[NS(custom_id=custom_id)])])

    def channel(self, messages):
        class Channel:
            async def history(self, limit):
                for message in messages[:limit]:
                    yield message
        return Channel()

    async def test_appy_panel_does_not_count_as_our_panel(self):
        self.assertFalse(is_application_panel(self.message(2, "tae:application:open:v1"), 1))
        self.assertIsNone(await find_application_panel(self.channel([self.message(2, "appy")]), 1))

    async def test_existing_own_panel_is_reused(self):
        own = self.message(1, "tae:application:open:v1")
        self.assertIs(await find_application_panel(self.channel([self.message(2, "appy"), own]), 1), own)

    async def test_incomplete_scan_does_not_allow_repost(self):
        with self.assertRaises(ValueError):
            await find_application_panel(self.channel([self.message(2, "appy")] * 100), 1)


if __name__ == "__main__":
    unittest.main()
