import datetime as dt
import json
from pathlib import Path
import tempfile
import unittest

from attendance import UTC, link, report
from collector import connect
from discord_store import Store
from loa import acknowledgement, cancel, parse_message, review, save

DID = "248567812203872257"
OTHER = "123456789012345678"
UID = "76561198000000001"
POSTED = dt.datetime(2026, 11, 2, 19, tzinfo=UTC)


def message(duration="11/07", member=DID, reason="private reason"):
    return f"Name: **<@{member}>**\nDuration: {duration}\nReason: {reason}"


class ParserTests(unittest.TestCase):
    def test_short_acceptance_text(self):
        outcome = {"status": "accepted", "start": "2026-11-07", "end": "2026-11-07"}
        self.assertEqual(acknowledgement(outcome), "LOA accepted for the dates: 2026-11-07. Excused absence logged.")
        outcome["end"] = "2026-11-14"
        self.assertEqual(acknowledgement(outcome), "LOA accepted for the dates: 2026-11-07 through 2026-11-14. Excused absence logged.")

    def test_existing_format_year_from_post(self):
        parsed = parse_message(message("10/17"), POSTED, DID)
        self.assertEqual(parsed["start"], "2026-10-17")
        self.assertEqual(parsed["end"], "2026-10-17")
        self.assertEqual(parsed["detail"], "")

    def test_optional_reason(self):
        parsed = parse_message(f"Name: <@!{DID}>\nDuration: 2026-11-07", POSTED, DID)
        self.assertEqual(parsed["start"], "2026-11-07")

    def test_inclusive_ranges(self):
        for duration in ("11/07-11/14", "11/07/2026 to 11/14/2026", "2026-11-07 through 2026-11-14"):
            with self.subTest(duration=duration):
                parsed = parse_message(message(duration), POSTED, DID)
                self.assertEqual((parsed["start"], parsed["end"]), ("2026-11-07", "2026-11-14"))

    def test_new_year_requires_years(self):
        parsed = parse_message(message("12/26-01/02"), POSTED, DID)
        self.assertTrue(parsed["detail"])
        parsed = parse_message(message("12/26/2026-01/02/2027"), POSTED, DID)
        self.assertEqual(parsed["end"], "2027-01-02")

    def test_ambiguous_or_invalid_dates(self):
        for duration in ("next weekend", "02/30/2026", "11/14-11/07", "01/01", "11/07/26"):
            self.assertTrue(parse_message(message(duration), POSTED, DID)["detail"])

    def test_no_name_guessing(self):
        parsed = parse_message("Name: Edonn\nDuration: 11/07", POSTED, DID)
        self.assertIsNone(parsed["member"])
        self.assertTrue(parsed["detail"])

    def test_third_party_pending(self):
        self.assertIn("another member", parse_message(message(), POSTED, OTHER)["detail"])

    def test_non_loa_and_duplicate_fields(self):
        self.assertIsNone(parse_message("hello", POSTED, DID))
        self.assertTrue(parse_message(message() + "\nDuration: 11/14", POSTED, DID)["detail"])


class WorkflowTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        path = Path(self.root.name) / "test.sqlite3"
        connect(path).close()
        self.store = Store(path)

    def tearDown(self):
        self.root.cleanup()

    def save(self, content=None, author=DID):
        return self.store.run(lambda db: save(db, "555555555555555555", "1", "2", author,
                                              content if content is not None else message(), POSTED))

    def test_save_idempotent_reason_not_stored(self):
        self.assertEqual(self.save()["status"], "accepted")
        self.assertIsNone(self.save(message(reason="changed private reason")))
        rows = self.store.run(lambda db: db.execute("SELECT * FROM loa_messages").fetchall())
        self.assertNotIn("private reason", repr(rows))

    def test_edit_replaces_excuse(self):
        self.save()
        self.save(message("11/14"))
        row = self.store.run(lambda db: db.execute("SELECT start_date,status FROM loa_messages").fetchone())
        self.assertEqual(row, ("2026-11-14", "accepted"))
        self.save(message("unclear"))
        row = self.store.run(lambda db: db.execute("SELECT start_date,status FROM loa_messages").fetchone())
        self.assertEqual(row, (None, "pending"))

    def test_delete_cancels(self):
        self.save()
        self.assertTrue(self.store.run(lambda db: cancel(db, "555555555555555555")))
        self.assertFalse(self.store.run(lambda db: cancel(db, "555555555555555555")))

    def test_removed_fields_cancel(self):
        self.save()
        self.assertEqual(self.save("post withdrawn")["status"], "cancelled")

    def test_staff_review_and_duplicate_delivery(self):
        self.assertEqual(self.save(author=OTHER)["status"], "pending")
        self.store.run(lambda db: review(db, OTHER, "555555555555555555", True))
        self.assertIsNone(self.save(author=OTHER))
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT status FROM loa_messages").fetchone()[0]), "accepted")

    def test_incomplete_cannot_be_approved(self):
        self.save(message("unclear"))
        with self.assertRaises(ValueError):
            self.store.run(lambda db: review(db, OTHER, "555555555555555555", True))

    def test_loa_excuses_without_credit_or_activating_operation(self):
        self.store.run(lambda db: link(db, UID, DID, "Excused", "2026-11-07", 39))
        self.store.run(lambda db: link(db, "76561198000000002", OTHER, "Present", "2026-11-07", 0))
        self.save()
        day = dt.date(2026, 11, 7)
        self.assertEqual(self.store.run(lambda db: report(db, day, day))["operations"], [])
        def add_events(db):
            with db:
                for minute in range(7):
                    stamp = dt.datetime(2026, 11, 7, 19, minute, tzinfo=UTC).isoformat()
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("s", minute + 1, stamp, "PRESENCE", json.dumps(["76561198000000002"]), "test"))
                db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("s", 8, stamp, "END", "[]", "test"))
        self.store.run(add_events)
        output = self.store.run(lambda db: report(db, day, day, dt.datetime(2026, 11, 9, tzinfo=UTC)))
        member = next(row for row in output["members"] if row["discord_id"] == DID)
        self.assertEqual(member["earned_in_report_range"], 0)
        self.assertEqual(member["baseline_ops"], 39)
        self.assertEqual(member["last_four"][0]["status"], "excused")

    def test_attendance_overrides_loa_only_for_attended_session(self):
        self.store.run(lambda db: link(db, UID, DID, "Attending", "2026-11-07", 39))
        self.store.run(lambda db: link(db, "76561198000000002", OTHER, "Other", "2026-11-07", 0))
        self.save(message("11/07-11/14"))
        def events(db):
            with db:
                for session, hour, identities in (("main", 19, [UID]), ("fun", 0, ["76561198000000002"])):
                    day = 7 if session == "main" else 8
                    for minute in range(7):
                        stamp = dt.datetime(2026, 11, day, hour, minute, tzinfo=UTC).isoformat()
                        db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", (session, minute + 1, stamp, "PRESENCE", json.dumps(identities), "test"))
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", (session, 8, stamp, "END", "[]", "test"))
        self.store.run(events)
        output = self.store.run(lambda db: report(db, dt.date(2026,11,7), dt.date(2026,11,7), dt.datetime(2026,11,9,tzinfo=UTC)))
        member = next(row for row in output["members"] if row["discord_id"] == DID)
        self.assertEqual(member["earned_in_report_range"], 1)
        self.assertEqual([op["status"] for op in member["last_four"]], ["attended", "excused"])
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT status,end_date FROM loa_messages").fetchone()), ("accepted", "2026-11-14"))


if __name__ == "__main__":
    unittest.main()
