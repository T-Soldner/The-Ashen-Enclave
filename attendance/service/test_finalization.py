import copy
import datetime as dt
import json
from pathlib import Path
import tempfile
import unittest

from attendance import UTC, link, windows
from collector import connect
from discord_store import Store
from finalization import Workflow, finalize, ledger_totals
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
        with self.assertRaises(ValueError):
            await self.workflow.run(DAY, "main", now=NOW)

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
