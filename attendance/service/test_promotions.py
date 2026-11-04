import datetime as dt
import json
from pathlib import Path
import tempfile
import unittest

from attendance import UTC, link
from collector import connect
from promotions import ANNOUNCEMENTS_CHANNEL, CUSTOM_ASSETS_URL, RANKS, announcement, plan

UID = "76561198000000001"
DID = "123456789012345678"
NOW = dt.datetime(2026, 11, 9, tzinfo=UTC)


class PromotionTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.db = connect(Path(self.temp.name) / "test.sqlite3")
        link(self.db, UID, DID, "Character Name", "2026-11-07", 4)

    def tearDown(self):
        self.db.close()
        self.temp.cleanup()

    def operation(self, fun=False):
        base = dt.datetime(2026, 11, 8, 0, tzinfo=UTC) if fun else dt.datetime(2026, 11, 7, 19, tzinfo=UTC)
        with self.db:
            for minute in range(7):
                stamp = (base + dt.timedelta(minutes=minute)).isoformat()
                self.db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("s", minute + 1, stamp, "PRESENCE", json.dumps([UID]), "test"))
            self.db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("s", 8, stamp, "END", "[]", "test"))

    def test_exact_announcement_and_rewards(self):
        self.assertEqual(announcement(DID, RANKS[1]), f"Congratulations to <@{DID}> on promoting to Mandalorian Recruit.")
        for rank, reward in ((RANKS[2], "helmet"), (RANKS[3], "armor"), (RANKS[4], "backpack")):
            text = announcement(DID, rank)
            self.assertEqual(text, f"Congratulations to <@{DID}> on promoting to {rank['name']}. You can now submit a request for custom {reward} by creating a new post in [custom-assets]({CUSTOM_ASSETS_URL}).")
        self.assertEqual(ANNOUNCEMENTS_CHANNEL, 1477486340625924209)

    def test_protect_edonn_and_appointed_prefixes(self):
        for member, nickname in (("248567812203872257", "[MV] Edonn Houcai"), (DID, "[WC] Hondo Karr"), (DID, "[RM] Anyone")):
            self.assertEqual(plan(self.db, member, nickname, [], now=NOW)["state"], "protected")

    def test_exact_appointed_role_ids_are_always_protected(self):
        for role in (1477486340080799938, 1477486340080799946):
            self.assertEqual(plan(self.db, DID, "Character", [role], now=NOW)["state"], "protected")

    def test_hc_is_not_an_appointed_prefix(self):
        self.assertNotEqual(plan(self.db, DID, "[HC] Character", [], now=NOW)["state"], "protected")

    def test_protected_role_survives_changed_prefix(self):
        result = plan(self.db, DID, "Character", [999], protected_role_ids=[999], now=NOW)
        self.assertEqual(result["state"], "protected")
        self.assertEqual(plan(self.db, DID, "Character", [], ["Rally Master"], now=NOW)["state"], "protected")

    def test_promotion_preserves_character_name(self):
        self.operation()
        result = plan(self.db, DID, "[MR] Character Name", [RANKS[1]["role"], 111], now=NOW)
        self.assertEqual(result["state"], "proposed")
        self.assertEqual(result["nickname"], "[MA] Character Name")
        self.assertEqual(result["remove_roles"], [RANKS[1]["role"]])
        self.assertEqual(result["add_role"], RANKS[2]["role"])
        self.assertEqual(self.db.execute("SELECT baseline_ops FROM members").fetchone()[0], 4)

    def test_no_historical_promotion_announcement(self):
        with self.db:
            self.db.execute("UPDATE members SET baseline_ops=20")
        result = plan(self.db, DID, "[MR] Character", [RANKS[1]["role"]], now=NOW)
        self.assertEqual(result["state"], "review")
        self.assertNotIn("announcement", result)

    def test_no_demotion(self):
        result = plan(self.db, DID, "[MV] Character", [RANKS[4]["role"]], now=NOW)
        self.assertEqual(result["state"], "unchanged")

    def test_missing_or_conflicting_roles_require_review(self):
        self.operation()
        for roles in ([], [RANKS[0]["role"], RANKS[1]["role"]]):
            self.assertEqual(plan(self.db, DID, "Character", roles, now=NOW)["state"], "review")

    def test_unknown_prefix_and_role_mismatch_preserved(self):
        self.operation()
        for nickname in ("[CL] Character", "[MM] Character"):
            self.assertEqual(plan(self.db, DID, nickname, [RANKS[1]["role"]], now=NOW)["state"], "review")

    def test_fun_op_qualifies_foundling_for_recruit(self):
        with self.db:
            self.db.execute("UPDATE members SET baseline_ops=0")
        self.operation(fun=True)
        result = plan(self.db, DID, "[FD] Character", [RANKS[0]["role"]], now=NOW)
        self.assertEqual(result["state"], "proposed")
        self.assertEqual(result["target"], "Mandalorian Recruit")
        self.assertEqual(result["add_role"], RANKS[1]["role"])

    def test_main_op_qualifies_foundling_for_recruit(self):
        with self.db:
            self.db.execute("UPDATE members SET baseline_ops=0")
        self.operation()
        result = plan(self.db, DID, "[FD] Character", [RANKS[0]["role"]], now=NOW)
        self.assertEqual(result["state"], "proposed")
        self.assertEqual(result["target"], "Mandalorian Recruit")

    def test_long_name_not_truncated(self):
        self.operation()
        result = plan(self.db, DID, "[MR] " + "x" * 32, [RANKS[1]["role"]], now=NOW)
        self.assertEqual(result["state"], "review")
        self.assertNotIn("nickname", result)


if __name__ == "__main__":
    unittest.main()
