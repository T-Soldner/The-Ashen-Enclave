from pathlib import Path
import tempfile
import unittest

from attendance import link
from collector import connect
from discord_store import Store
from finalization import Workflow
from test_finalization import FakeTransport, GUILD, UID, DID
import absence


class AutomaticAbsenceTests(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        path = Path(self.temp.name)/"test.sqlite3"
        connect(path).close()
        self.store = Store(path)
        self.store.run(lambda db: link(db,UID,DID,"Character","2026-11-07",0))
        self.transport = FakeTransport()
        self.workflow = Workflow(self.store,self.transport,GUILD,enabled=True)
        self.workflow.automatic_absence_alerts = True
        self.operations = ['2026-11-07:main','2026-11-07:fun','2026-11-14:main','2026-11-14:fun']
        def seed(db):
            with db:
                for op in self.operations:
                    db.execute("INSERT INTO finalized_operations VALUES (?,?,?,'hash','')",(str(GUILD),op,'2026-11-15T00:00:00+00:00'))
                    db.execute("INSERT INTO operation_credits VALUES (?,?,?,?,?,'missed',0)",(str(GUILD),op,UID,DID,'Character'))
        self.store.run(seed)

    async def test_one_alert_per_streak_and_no_role_changes(self):
        await self.workflow.post_absence_alerts()
        await self.workflow.post_absence_alerts()
        self.assertEqual(len(self.transport.calls),1)
        self.assertEqual(self.transport.calls[0][0],'absence')
        self.assertIn('4 consecutive',self.transport.calls[0][1])
        self.assertNotIn('apply',self.transport.calls)

    async def test_attendance_excuse_review_and_missing_credit_break_streak(self):
        for status in ('attended','excused','review',None):
            def change(db):
                with db:
                    db.execute("UPDATE operation_credits SET status='missed'")
                    if status is None:
                        db.execute("DELETE FROM operation_credits WHERE operation=?",(self.operations[-1],))
                    else:
                        db.execute("UPDATE operation_credits SET status=? WHERE operation=?",(status,self.operations[-1]))
            self.store.run(change)
            self.assertEqual(self.store.run(lambda db: absence.ledger_candidates(db,GUILD)),[])

    async def test_failure_is_uncertain_and_not_reposted(self):
        self.transport.send_fails = True
        with self.assertRaises(RuntimeError):
            await self.workflow.post_absence_alerts()
        self.transport.send_fails = False
        await self.workflow.post_absence_alerts()
        self.assertEqual(len(self.transport.calls),1)
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT state FROM absence_alerts").fetchone())[0],'uncertain')

    async def test_current_loa_blocks_alert_even_if_ledger_has_old_misses(self):
        for status in ('accepted','pending'):
            def save(db):
                with db:
                    db.execute("INSERT OR REPLACE INTO loa_messages VALUES ('loa',?,'channel',?,?, '2026-11-14','2026-11-14',?,'','hash','now')",(str(GUILD),DID,DID,status))
            self.store.run(save)
            await self.workflow.post_absence_alerts()
        self.assertEqual(self.transport.calls,[])

    async def test_disabled_or_archived_member_does_not_post(self):
        self.workflow.automatic_absence_alerts = False
        await self.workflow.post_absence_alerts()
        self.workflow.automatic_absence_alerts = True
        def archive(db):
            with db:
                db.execute("UPDATE members SET active=0")
        self.store.run(archive)
        await self.workflow.post_absence_alerts()
        self.assertEqual(self.transport.calls,[])
