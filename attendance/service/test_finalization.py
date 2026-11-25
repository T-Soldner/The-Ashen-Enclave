import copy
import datetime as dt
import json
from pathlib import Path
import tempfile
import unittest

from attendance import UTC, link, report, windows
from collector import connect
from discord_store import Store
from discord_bot import scheduled_preview_slot
from finalization import Workflow, finalize, ledger_totals, set_holiday
import promotions

DID = "123456789012345678"
UID = "76561198000000001"
GUILD = promotions.GUILD_ID
DAY = dt.date(2026, 11, 7)
NOW = dt.datetime(2026, 11, 9, tzinfo=UTC)


class FakeTransport:
    def __init__(self):
        self.current = {"id": DID, "nickname": "[FD] Character", "roles": [111, promotions.RANKS[0]["role"]],
                        "role_names": ["Member", "Foundling"], "protected": False}
        self.calls = []
        self.apply_fails = False
        self.send_fails = False
        self.check_fails = False
        self.reconcile_loas = None

    async def preflight(self):
        self.calls.append("preflight")

    async def member(self, discord_id):
        return copy.deepcopy(self.current)

    async def check_promotion(self, current, plan):
        if self.check_fails:
            raise ValueError("permissions")

    async def apply(self, discord_id, current, plan):
        self.calls.append("apply")
        if self.apply_fails:
            raise RuntimeError("simulated partial/failed request")
        self.current["roles"] = [role for role in self.current["roles"] if role not in plan["remove_roles"]] + [plan["add_role"]]
        self.current["nickname"] = plan["nickname"]

    async def send(self, kind, text, mention_id=None):
        self.calls.append((kind, text, mention_id))
        if self.send_fails:
            raise RuntimeError("simulated uncertain network delivery")
        return len(self.calls)


class WorkflowTests(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        path = Path(self.temp.name) / "test.sqlite3"
        connect(path).close()
        self.store = Store(path)
        self.store.run(lambda db: link(db, UID, DID, "Character", "2026-11-07", 0))
        self.transport = FakeTransport()
        self.workflow = Workflow(self.store, self.transport, GUILD, enabled=True)

    def tearDown(self):
        self.temp.cleanup()

    def events(self, full=True):
        begin = windows(DAY)[0][1]
        def insert(db):
            with db:
                for minute in range(181 if full else 7):
                    stamp = (begin + dt.timedelta(minutes=minute)).isoformat()
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("s", minute + 1, stamp, "PRESENCE", json.dumps([UID] if minute <= 6 else []), "test"))
                db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("s", minute + 2, stamp, "END", "[]", "test"))
        self.store.run(insert)

    def rows(self, table):
        self.assertIn(table, {"operation_credits", "promotion_jobs", "workflow_posts", "finalized_operations"})
        return self.store.run(lambda db: db.execute("SELECT * FROM " + table).fetchall())

    async def test_disabled_is_noop(self):
        self.workflow.enabled = False
        with self.assertRaises(ValueError):
            await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(self.transport.calls, [])
        self.assertEqual(self.rows("operation_credits"), [])

    async def test_holiday_awards_credit_without_misses_and_can_be_cleared(self):
        self.events()
        self.store.run(lambda db: link(db, "76561198000000002", "123456789012345679", "Absent", DAY.isoformat(), 0))
        self.assertTrue(self.store.run(lambda db: set_holiday(db, DAY, DID)))
        self.assertFalse(self.store.run(lambda db: set_holiday(db, DAY, DID)))
        preview = self.store.run(lambda db: report(db, DAY, DAY, NOW))
        self.assertEqual(set(preview["operations"][0]["seconds"]), {UID})
        self.assertTrue(all(not member["last_four"] for member in preview["members"]))
        for kind in ("planning", "recap-preview"):
            await self.workflow.scheduled_preview(kind, DAY, NOW)
        self.assertEqual(self.transport.calls, [])
        self.assertEqual(self.rows("operation_credits"), [])
        self.assertTrue(self.store.run(lambda db: set_holiday(db, DAY, DID, enabled=False)))
        self.store.run(lambda db: set_holiday(db, DAY, DID))
        self.store.run(lambda db: finalize(db, GUILD, DAY, "main", NOW))
        self.assertEqual([(row[3], row[5]) for row in self.rows("operation_credits")], [(DID, "attended")])
        self.assertIn((DID, "Character", 0, 1), self.store.run(lambda db: ledger_totals(db, GUILD)))
        with self.assertRaisesRegex(ValueError, "already has finalized attendance"):
            self.store.run(lambda db: set_holiday(db, DAY, DID, enabled=False))

    def test_preview_slots_follow_eastern_daylight_time(self):
        for day, utc_hour in ((DAY, 21), (dt.date(2026, 7, 4), 20)):
            start = dt.datetime.combine(day, dt.time(utc_hour), UTC)
            self.assertIsNone(scheduled_preview_slot(start - dt.timedelta(minutes=1)))
            self.assertEqual(scheduled_preview_slot(start), (day, "planning"))
            self.assertEqual(scheduled_preview_slot(start + dt.timedelta(hours=1)), (day, "recap-preview"))
            self.assertIsNone(scheduled_preview_slot(start + dt.timedelta(hours=2)))
            self.assertIsNone(scheduled_preview_slot(start + dt.timedelta(days=1)))

    async def test_previews_are_read_only_and_deduplicated(self):
        planning = windows(DAY)[0][2] - dt.timedelta(hours=1)
        self.events()
        for workflow in (self.workflow, Workflow(self.store, self.transport, GUILD, enabled=True)):
            await workflow.scheduled_preview("planning", DAY, planning)
            await workflow.scheduled_preview("recap-preview", DAY, planning + dt.timedelta(hours=1))
        forecast, recap = self.transport.calls
        self.assertEqual(forecast[0], "planning-ping")
        self.assertIn("[FD] Character -> Mandalorian Recruit (1 ops)", forecast[1])
        self.assertEqual(recap[0], "recap-preview")
        self.assertIn("Attended (1 linked members)", recap[1])
        for table in ("operation_credits", "promotion_jobs", "finalized_operations"):
            self.assertEqual(self.rows(table), [])

    async def test_old_and_fun_session_warnings_do_not_block_main(self):
        self.events()
        def insert(db):
            with db:
                for session, stamp in (
                    ("last-week", "2026-10-31T19:00:00+00:00"),
                    ("fun", windows(DAY)[1][1].isoformat()),
                ):
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)",
                               (session, 1, stamp, "PRESENCE", "[]", "other"))
        self.store.run(insert)
        await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(len(self.rows("finalized_operations")), 1)

    async def test_overlapping_unclosed_session_still_requires_review(self):
        self.events()
        def insert(db):
            with db:
                start = windows(DAY)[0][1]
                for sequence, offset in enumerate((-1, 1), 1):
                    stamp = (start + dt.timedelta(minutes=offset)).isoformat()
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)",
                               ("overlap", sequence, stamp, "PRESENCE", "[]", "other"))
        self.store.run(insert)
        with self.assertRaisesRegex(ValueError, "overlap has no closing record"):
            await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(self.rows("finalized_operations"), [])

    async def test_full_success_and_repeat_are_idempotent(self):
        self.events()
        await self.workflow.run(DAY, "main", now=NOW)
        await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(len(self.rows("operation_credits")), 1)
        self.assertEqual(self.transport.calls.count("apply"), 1)
        promotions_sent = [row for row in self.transport.calls if isinstance(row, tuple) and row[0] == "promotion"]
        recaps = [row for row in self.transport.calls if isinstance(row, tuple) and row[0] == "recap"]
        self.assertEqual(len(promotions_sent), 1)
        self.assertEqual(len(recaps), 1)
        self.assertIn("Congratulations to", promotions_sent[0][1])
        self.assertIn("Character: Mandalorian Recruit", recaps[0][1])
        self.assertIn(111, self.transport.current["roles"])
        self.assertEqual(self.transport.current["nickname"], "[MR] Character")
        self.assertEqual(self.store.run(lambda db: ledger_totals(db, GUILD))[0][2:], (0, 1))

    async def test_failures_do_not_announce_promotions(self):
        self.events()
        self.transport.apply_fails = True
        await self.workflow.run(DAY, "main", now=NOW)
        await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(self.transport.calls.count("apply"), 1)
        self.assertFalse(any(isinstance(row, tuple) and row[0] == "promotion" for row in self.transport.calls))
        self.assertEqual(self.rows("promotion_jobs")[0][-1], "uncertain")

    async def test_protected_member_gets_credit_but_no_role_mutation(self):
        self.events()
        self.transport.current["protected"] = True
        await self.workflow.run(DAY, "main", now=NOW)
        self.assertNotIn("apply", self.transport.calls)
        self.assertEqual(len(self.rows("operation_credits")), 1)

    async def test_archived_member_is_not_promoted_on_repeat_processing(self):
        self.events()
        self.store.run(lambda db: finalize(db,GUILD,DAY,"main",NOW))
        import membership
        self.store.run(lambda db: membership.archive(db,GUILD,DID,DID))
        self.assertEqual(await self.workflow.process_member("2026-11-07:main",DID),"inactive")
        self.assertNotIn("apply",self.transport.calls)

    async def test_uncertain_message_not_resent(self):
        self.transport.send_fails = True
        with self.assertRaises(RuntimeError):
            await self.workflow.send_once("recap", "key", "text")
        self.transport.send_fails = False
        self.assertFalse(await self.workflow.send_once("recap", "key", "text"))
        self.assertEqual(self.rows("workflow_posts")[0][3], "uncertain")

    async def test_incomplete_evidence_held_without_writing(self):
        self.events(full=False)
        with self.assertRaises(ValueError):
            await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(self.rows("operation_credits"), [])

    async def test_explicit_review_preserves_earned_credit_not_guessed_absence(self):
        self.events(full=False)
        self.store.run(lambda db: link(db, "76561198000000002", "123456789012345679", "Other", "2026-11-07", 0))
        self.store.run(lambda db: finalize(db, GUILD, DAY, "main", NOW, reviewed_evidence=True))
        states = {row[4]: row[5] for row in self.rows("operation_credits")}
        self.assertEqual(states, {"Character": "attended", "Other": "review"})

    async def test_grace_period(self):
        self.events()
        with self.assertRaises(ValueError):
            self.store.run(lambda db: finalize(db, GUILD, DAY, "main", windows(DAY)[0][2]))

    async def test_empty_window_does_not_finalize(self):
        with self.assertRaises(ValueError):
            await self.workflow.run(DAY, "main", now=NOW)
        self.assertEqual(self.rows("finalized_operations"), [])

    async def test_loa_pending_blocks_finalization(self):
        self.events()
        import loa
        self.store.run(lambda db: loa.save(db, "555555555555555555", GUILD, "2", "123456789012345679",
            f"Name: <@{DID}>\nDuration: 11/07/2026", NOW))
        with self.assertRaisesRegex(ValueError, "Blocking message IDs: 555555555555555555"):
            await self.workflow.run(DAY, "main", now=NOW)

    async def test_blocker_listing_filters_and_pages_pending_rows(self):
        import loa

        def check(db):
            records = [(str(i), str(GUILD), "pending", None) for i in range(1, 13)]
            records += [("accepted", str(GUILD), "accepted", None),
                        ("other-date", str(GUILD), "pending", "2026-11-14"),
                        ("other-guild", "other", "pending", None)]
            with db:
                db.executemany("INSERT INTO loa_messages VALUES (?,?, 'channel','author','member',?,?,?,'','digest','now')",
                               [(mid, guild, date, date, status) for mid, guild, status, date in records])
            first = loa.list_entries(db, GUILD, day=DAY)
            second = loa.list_entries(db, GUILD, day=DAY, offset=10)
            self.assertEqual((len(first), len(second)), (10, 2))
            self.assertEqual({row[0] for row in first + second}, {str(i) for i in range(1, 13)})
            pending = loa.list_entries(db, GUILD, pending_only=True, limit=20)
            self.assertEqual(len(pending), 13)

        self.store.run(check)

    async def test_recap_names_member_and_explains_rank_mismatch(self):
        self.events()
        self.transport.current["nickname"] = "[MR] Character"
        await self.workflow.run(DAY, "main", now=NOW)
        recap = next(call[1] for call in self.transport.calls if isinstance(call, tuple) and call[0] == "recap")
        self.assertIn("Promotion review needed (1)", recap)
        self.assertIn("[MR] Character: Discord role is Foundling ([FD])", recap)
        self.assertIn("/tae-admin review", recap)
        self.assertNotIn("apply", self.transport.calls)

    async def test_check_failure_preserves_roles_and_reports_review(self):
        self.events()
        self.transport.check_fails = True
        text = await self.workflow.run(DAY, "main", now=NOW)
        self.assertIn("1 results need review", text)
        self.assertNotIn("apply", self.transport.calls)
        self.assertEqual(self.rows("promotion_jobs"), [])

    async def test_new_process_keeps_deduplication(self):
        self.events()
        await self.workflow.run(DAY, "main", now=NOW)
        restarted = Workflow(self.store, self.transport, GUILD, enabled=True)
        await restarted.run(DAY, "main", now=NOW)
        self.assertEqual(self.transport.calls.count("apply"), 1)

    async def test_live_promotion_uses_ledger_not_other_unfinalized_evidence(self):
        self.events()
        self.store.run(lambda db: db.execute("UPDATE members SET baseline_ops=3").connection.commit())
        self.transport.current["nickname"] = "[MR] Character"
        self.transport.current["roles"] = [111, promotions.RANKS[1]["role"]]
        def extra(db):
            with db:
                for minute in range(7):
                    stamp = dt.datetime(2026,11,8,0,minute,tzinfo=UTC).isoformat()
                    db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("fun", minute+1, stamp, "PRESENCE", json.dumps([UID]), "test"))
                db.execute("INSERT INTO events VALUES (?,?,?,?,?,?)", ("fun", 8, stamp, "END", "[]", "test"))
        self.store.run(extra)
        await self.workflow.run(DAY, "main", now=NOW)
        self.assertNotIn("apply", self.transport.calls)
        self.assertEqual(self.store.run(lambda db: ledger_totals(db,GUILD))[0][2:], (3,1))


if __name__ == "__main__":
    unittest.main()
