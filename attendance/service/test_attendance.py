import datetime as dt
import json
import sqlite3
import tempfile
import unittest
from pathlib import Path

from attendance import UTC, evidence, link, report, seconds_in, windows
from collector import connect

UID = "76561198000000001"
OTHER = "76561198000000002"
DISCORD = "123456789012345678"
SATURDAY = dt.date(2026, 11, 7)


class AttendanceTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        self.db = connect(Path(self.root.name) / "test.sqlite3")
        link(self.db, UID, DISCORD, "Test Member", "2026-11-07", 20)

    def tearDown(self):
        self.db.close()
        self.root.cleanup()

    def add(self, minute, kind="PRESENCE", uids=None, session="s", sequence=None,
            base="2026-11-07T19:00:00+00:00"):
        if sequence is None:
            sequence = self.db.execute("SELECT count(*)+1 FROM events WHERE session=?", (session,)).fetchone()[0]
        stamp = dt.datetime.fromisoformat(base) + dt.timedelta(minutes=minute)
        with self.db:
            self.db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)",
                            (session, sequence, stamp.isoformat(), kind,
                             json.dumps([UID] if uids is None else uids), "test"))

    def preview(self):
        return report(self.db, SATURDAY, SATURDAY,
                      now=dt.datetime(2026, 11, 9, tzinfo=UTC))

    def test_dst_and_saturday_only(self):
        self.assertEqual(windows(dt.date(2026, 10, 31))[0][1].hour, 18)
        self.assertEqual(windows(SATURDAY)[0][1].hour, 19)
        self.assertEqual(windows(dt.date(2027, 3, 13))[0][1].hour, 19)
        self.assertEqual(windows(dt.date(2027, 3, 20))[0][1].hour, 18)
        self.assertEqual(windows(SATURDAY)[1][2].date(), dt.date(2026, 11, 8))
        self.assertEqual(windows(dt.date(2026, 11, 2)), [])

    def test_strict_five_minute_threshold(self):
        for minute in range(6):
            self.add(minute)
        self.add(5, "END", [])
        self.assertEqual(self.preview()["operations"], [])
        self.add(6, "PRESENCE", session="second")
        # A lone observation confirms no additional duration.
        self.assertEqual(self.preview()["operations"], [])

    def test_reconnects_and_idempotent_reports(self):
        self.add(0, "JOIN")
        self.add(1)
        self.add(2)
        self.add(3, "LEAVE")
        self.add(10, "JOIN")
        self.add(11)
        self.add(12)
        self.add(13, "LEAVE")
        self.add(13, "END", [])
        first = self.preview()
        self.assertEqual(first["operations"][0]["seconds"][UID], 360)
        self.assertEqual(first["members"][0]["earned_in_report_range"], 1)
        self.assertEqual(first, self.preview())
        self.assertEqual(self.db.execute("SELECT baseline_ops FROM members").fetchone()[0], 20)

    def test_301_seconds_qualifies(self):
        for minute in range(6):
            self.add(minute)
        self.add(301 / 60, "LEAVE")
        self.add(301 / 60, "END", [])
        self.assertEqual(self.preview()["operations"][0]["seconds"][UID], 301)

    def test_main_and_fun_are_separate(self):
        for label, base in (("main", "2026-11-07T19:00:00+00:00"),
                            ("fun", "2026-11-08T00:00:00+00:00")):
            for minute in range(7):
                self.add(minute, session=label, base=base)
            self.add(6, "END", [], session=label, base=base)
        self.assertEqual(self.preview()["members"][0]["earned_in_report_range"], 2)

    def test_missing_member_is_review_not_absence(self):
        link(self.db, OTHER, "123456789012345679", "Other Member", "2026-11-07", 0)
        for minute in range(7):
            self.add(minute)
        self.add(6, "END", [])
        other = next(row for row in self.preview()["members"] if row["steam_id"] == OTHER)
        self.assertEqual(other["last_four"][0]["status"], "review-no-credit")

    def test_legacy_database_migration_preserves_data(self):
        path = Path(self.root.name) / "legacy.sqlite3"
        legacy = sqlite3.connect(path)
        legacy.execute("CREATE TABLE members (steam_id TEXT PRIMARY KEY,discord_id TEXT UNIQUE,display_name TEXT,baseline_ops INTEGER NOT NULL DEFAULT 0,active INTEGER NOT NULL DEFAULT 1)")
        legacy.execute("INSERT INTO members VALUES (?,?,?,?,?)", (UID, DISCORD, "Old", 38, 1))
        legacy.commit()
        legacy.close()
        migrated = connect(path)
        try:
            self.assertEqual(migrated.execute("SELECT baseline_ops,tracking_since FROM members").fetchone(), (38, None))
        finally:
            migrated.close()

    def test_crash_retains_credit_without_inventing_tail(self):
        for minute in range(7):
            self.add(minute)
        preview = self.preview()
        self.assertEqual(preview["operations"][0]["seconds"][UID], 360)
        self.assertTrue(any("no closing record" in item for item in preview["warnings"]))

    def test_long_gap_not_counted(self):
        self.add(0)
        self.add(30)
        intervals, warnings = evidence(self.db)
        self.assertEqual(intervals[UID], [])
        self.assertTrue(warnings)
        self.assertEqual(self.preview()["operations"], [])

    def test_sequence_gap_not_bridged(self):
        self.add(0, sequence=1)
        self.add(1, sequence=3)
        intervals, warnings = evidence(self.db)
        self.assertFalse(intervals[UID])
        self.assertTrue(any("Missing" in warning for warning in warnings))

    def test_union_and_window_clipping(self):
        start = windows(SATURDAY)[0][1]
        end = start + dt.timedelta(minutes=10)
        spans = [(start - dt.timedelta(minutes=5), end), (start, end)]
        self.assertEqual(seconds_in(spans, start, end), 600)

    def test_mission_restart_not_bridged(self):
        self.add(0, session="first")
        self.add(1, session="second")
        self.assertEqual(self.preview()["operations"], [])

    def test_unlinked_visitors_do_not_activate_operations(self):
        for minute in range(7):
            self.add(minute, uids=[OTHER])
        self.add(6, "END", [])
        self.assertEqual(self.preview()["operations"], [])

    def test_monday_manual_test_does_not_count(self):
        for minute in range(7):
            self.add(minute, base="2026-11-02T18:00:00+00:00")
        self.assertEqual(self.preview()["operations"], [])

    def test_identity_validation_and_conflicts(self):
        with self.assertRaises(ValueError):
            link(self.db, "HC123", DISCORD, "Bad", "2026-11-07", 0)
        with self.assertRaises(sqlite3.IntegrityError):
            link(self.db, OTHER, DISCORD, "Duplicate", "2026-11-07", 0)
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0], 1)

    def test_cutover_avoids_historical_credit(self):
        for minute in range(7):
            self.add(minute, base="2026-10-31T18:00:00+00:00")
        preview = report(self.db, dt.date(2026, 10, 31), SATURDAY)
        self.assertEqual(preview["operations"], [])

    def test_live_operation_not_awarded_yet(self):
        for minute in range(7):
            self.add(minute)
        preview = report(self.db, SATURDAY, SATURDAY,
                         now=dt.datetime(2026, 11, 7, 20, tzinfo=UTC))
        self.assertFalse(preview["operations"][0]["closed"])
        self.assertEqual(preview["members"][0]["earned_in_report_range"], 0)


if __name__ == "__main__":
    unittest.main()
