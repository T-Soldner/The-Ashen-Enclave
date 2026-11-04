import datetime as dt
import json
from pathlib import Path
import tempfile
import unittest

import absence
import loa
from attendance import UTC, link, windows
from collector import connect
from discord_store import Store

UID = "76561198000000001"
PRESENT = "76561198000000002"
DID = "248567812203872257"
OTHER = "123456789012345678"
NOW = dt.datetime(2026, 11, 23, tzinfo=UTC)


class AbsenceTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        self.path = Path(self.root.name) / "test.sqlite3"
        connect(self.path).close()
        self.store = Store(self.path)
        self.store.run(lambda db: link(db, UID, DID, "Missing", "2026-11-07", 39))
        self.store.run(lambda db: link(db, PRESENT, OTHER, "Present", "2026-11-07", 0))

    def tearDown(self):
        self.root.cleanup()

    def operation(self, day, kind="main", full=True, target_attends=False):
        identifier, begin, end = next(row for row in windows(dt.date.fromisoformat(day)) if row[0].endswith(kind))
        def action(db):
            with db:
                for minute in range(181 if full else 7):
                    stamp = begin + dt.timedelta(minutes=minute)
                    uids = [PRESENT] if minute <= 6 else []
                    if target_attends and minute <= 6:
                        uids.append(UID)
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", (identifier, minute+1, stamp.isoformat(), "PRESENCE", json.dumps(uids), "test"))
                db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", (identifier, minute+2, stamp.isoformat(), "END", "[]", "test"))
        self.store.run(action)

    def four(self):
        for day in ("2026-11-07", "2026-11-14"):
            for kind in ("main", "fun"):
                self.operation(day, kind)

    def member(self):
        return next(row for row in self.store.run(lambda db: absence.preview(db, NOW))["members"] if row["discord_id"] == DID)

    def test_four_ops_not_four_days(self):
        self.four()
        row = self.member()
        self.assertEqual(row["consecutive_misses"], 4)
        self.assertTrue(row["eligible"])
        self.assertEqual(row["episode"], "2026-11-07:main")

    def test_empty_windows_no_absences(self):
        self.assertEqual(self.member()["consecutive_misses"], 0)

    def test_partial_server_run_requires_review(self):
        self.operation("2026-11-07", full=False)
        self.assertEqual(self.member()["last_four"][0]["status"], "review")
        self.assertFalse(self.member()["eligible"])

    def test_loa_breaks_streak_without_adding_attended_total(self):
        self.four()
        self.store.run(lambda db: loa.save(db, "555555555555555555", "1", "2", DID,
            f"Name: <@{DID}>\nDuration: 11/14/2026", NOW))
        row = self.member()
        self.assertEqual(row["consecutive_misses"], 0)
        self.assertEqual(row["last_four"][-1]["status"], "excused")
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT baseline_ops FROM members WHERE discord_id=?", (DID,)).fetchone()[0]), 39)

    def test_pending_loa_holds_result(self):
        self.four()
        self.store.run(lambda db: loa.save(db, "555555555555555555", "1", "2", OTHER,
            f"Name: <@{DID}>\nDuration: 11/14/2026", NOW))
        self.assertFalse(self.member()["eligible"])
        self.assertEqual(self.member()["last_four"][-1]["status"], "review")

    def test_attending_resets_streak(self):
        self.four()
        self.operation("2026-11-21", target_attends=True)
        self.assertEqual(self.member()["consecutive_misses"], 0)

    def test_alert_receipt_survives_rechecks_and_fifth_miss(self):
        self.four()
        row = self.store.run(lambda db: absence.reserve(db, "guild", DID, NOW))
        self.store.run(lambda db: absence.finish(db, "guild", DID, row["episode"], "message"))
        self.operation("2026-11-21")
        with self.assertRaises(ValueError):
            self.store.run(lambda db: absence.reserve(db, "guild", DID, NOW))
        state = self.store.run(lambda db: db.execute("SELECT state FROM absence_alerts").fetchone()[0])
        self.assertEqual(state, "sent")

    def test_uncertain_send_is_not_retried(self):
        self.four()
        row = self.store.run(lambda db: absence.reserve(db, "guild", DID, NOW))
        self.store.run(lambda db: absence.finish(db, "guild", DID, row["episode"]))
        with self.assertRaises(ValueError):
            self.store.run(lambda db: absence.reserve(db, "guild", DID, NOW))

    def test_review_grace_after_window(self):
        self.operation("2026-11-07")
        end = windows(dt.date(2026,11,7))[0][2]
        data = self.store.run(lambda db: absence.preview(db, end + dt.timedelta(minutes=1)))
        row = next(row for row in data["members"] if row["discord_id"] == DID)
        self.assertEqual(row["last_four"][0]["status"], "review")

    def test_recap_names_attendees_without_inventing_promotions(self):
        self.operation("2026-11-07", target_attends=True)
        text = self.store.run(lambda db: absence.recap_preview(db, dt.date(2026,11,7), now=NOW))
        self.assertIn("Attended (2 linked members)", text)
        self.assertIn("- Missing", text)
        self.assertIn("- Present", text)
        self.assertIn("Promotions: not enabled", text)

    def test_empty_recap_is_not_an_operation(self):
        text = self.store.run(lambda db: absence.recap_preview(db, dt.date(2026,11,7), now=NOW))
        self.assertIn("No qualifying tracked operation", text)

    def test_recap_separates_main_and_fun(self):
        self.operation("2026-11-07", target_attends=True)
        self.operation("2026-11-07", "fun")
        text = self.store.run(lambda db: absence.recap_preview(db, dt.date(2026,11,7), "fun", NOW))
        self.assertIn("Attended (1 linked members)", text)
        self.assertNotIn("- Missing", text)

    def test_weekday_recap_rejected(self):
        with self.assertRaises(ValueError):
            self.store.run(lambda db: absence.recap_preview(db, dt.date(2026,11,2)))


if __name__ == "__main__":
    unittest.main()
