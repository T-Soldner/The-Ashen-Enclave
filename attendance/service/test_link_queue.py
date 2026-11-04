import datetime as dt
import json
from pathlib import Path
import tempfile
import unittest

from collector import ingest
from discord_store import Store
import clan_training as policy
import link_queue as queue


STEAM = "76561197964773063"
DID = "248567812203872257"


class Google:
    def __init__(self):
        self.entries = [{"row":3,"name":"[RM] Edonn Houcai","ops":"39"}]
        self.formulas = set()
        self.adds = []
        self.fail = False

    def snapshot(self):
        return {"entries":self.entries,"formula_rows":self.formulas}

    def new_member_row(self):
        return 4

    def add_member(self,row,label):
        self.adds.append((row,label))
        if self.fail:
            raise ValueError("Uncertain remote result")
        self.entries.append({"row":row,"name":label,"ops":"0"})


class QueueTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.path = Path(self.temp.name)/"attendance.sqlite3"
        from collector import connect
        db = connect(self.path)
        db.close()
        self.store = Store(self.path)
        self.db = connect(self.path)
        self.addCleanup(self.db.close)
        self.google = Google()
        self.member = dict(id=DID,name="[RM] Edonn Houcai",roles={policy.HOUSE},bot=False)
        self.observe("Edonn Houcai")

    def observe(self,name):
        with self.db:
            self.db.execute("INSERT OR REPLACE INTO observed_players VALUES (?,?,?)",(STEAM,name,"test.rpt"))
        queue.discover(self.db)

    def test_detection_deduplicates_and_only_suggests(self):
        queue.discover(self.db)
        self.assertEqual(self.db.execute("SELECT count(*) FROM detected_links").fetchone()[0],1)
        self.assertEqual(queue.suggestions(self.db,STEAM,[self.member]),[self.member])
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0],0)

    def test_existing_total_and_row_automatically_bound_without_write(self):
        plan = queue.plan(self.db,self.google,STEAM,self.member)
        self.assertEqual(plan["baseline"],39)
        queue.approve(self.db,self.google,plan,DID,self.member)
        self.assertEqual(self.google.adds,[])
        self.assertEqual(self.db.execute("SELECT baseline_ops FROM members").fetchone(),(39,))
        self.assertEqual(self.db.execute("SELECT sheet_row,last_total FROM sheet_bindings").fetchone(),(3,39))
        with self.assertRaises(ValueError):
            queue.approve(self.db,self.google,plan,DID,self.member)

    def test_stale_total_is_rejected_before_link(self):
        plan = queue.plan(self.db,self.google,STEAM,self.member)
        self.google.entries[0]["ops"] = "40"
        with self.assertRaises(ValueError):
            queue.approve(self.db,self.google,plan,DID,self.member)
        self.assertEqual(self.db.execute("SELECT count(*) FROM members").fetchone()[0],0)

    def test_ambiguous_names_require_exact_row(self):
        self.google.entries.append({"row":7,"name":"Edonn Houcai","ops":50})
        with self.assertRaises(ValueError):
            queue.plan(self.db,self.google,STEAM,self.member)
        self.assertEqual(queue.plan(self.db,self.google,STEAM,self.member,row=7)["baseline"],50)

    def test_new_member_explicit_preview_creates_zero_row_once(self):
        self.member["name"] = "New Person"
        plan = queue.plan(self.db,self.google,STEAM,self.member)
        self.assertTrue(plan["create"])
        queue.approve(self.db,self.google,plan,DID,self.member)
        self.assertEqual(self.google.adds,[(4,"New Person")])

    def test_failed_new_row_is_uncertain_and_not_repeated(self):
        self.member["name"] = "New Person"
        plan = queue.plan(self.db,self.google,STEAM,self.member)
        self.google.fail = True
        with self.assertRaises(ValueError):
            queue.approve(self.db,self.google,plan,DID,self.member)
        self.assertEqual(self.db.execute("SELECT state FROM detected_links").fetchone(),("uncertain",))
        with self.assertRaises(ValueError):
            queue.approve(self.db,self.google,plan,DID,self.member)
        self.assertEqual(len(self.google.adds),1)

    def test_formula_and_reserved_rows_refused(self):
        self.google.formulas.add(3)
        with self.assertRaises(ValueError):
            queue.plan(self.db,self.google,STEAM,self.member)
        self.google.formulas.clear()
        with self.db:
            self.db.execute("INSERT INTO sheet_bindings VALUES ('other',3,'Someone',0)")
        with self.assertRaises(ValueError):
            queue.plan(self.db,self.google,STEAM,self.member)

    def test_conflicting_registration_refused(self):
        with self.db:
            self.db.execute("INSERT INTO link_requests VALUES ('111111111111111111',?,'now','pending')",(STEAM,))
        with self.assertRaises(ValueError):
            queue.plan(self.db,self.google,STEAM,self.member)

    def test_non_house_and_archived_members_refused(self):
        self.member["roles"] = set()
        with self.assertRaises(ValueError):
            queue.plan(self.db,self.google,STEAM,self.member)
        self.member["roles"] = {policy.HOUSE}
        with self.db:
            self.db.execute("INSERT INTO members (steam_id,discord_id,active) VALUES (?,?,0)",(STEAM,DID))
        with self.assertRaises(ValueError):
            queue.plan(self.db,self.google,STEAM,self.member)

    def test_expired_preview_refused(self):
        plan = queue.plan(self.db,self.google,STEAM,self.member)
        plan["expires"] = "2020-01-01T00:00:00+00:00"
        with self.assertRaises(ValueError):
            queue.approve(self.db,self.google,plan,DID,self.member)

    def test_registration_requests_also_enter_button_queue(self):
        with self.db:
            self.db.execute("DELETE FROM detected_links")
            self.db.execute("DELETE FROM observed_players")
        self.store.request(DID,STEAM)
        self.assertEqual(queue.discover(self.db),[(STEAM,"Registration request")])
        self.assertEqual(queue.suggestions(self.db,STEAM,[self.member]),[self.member])

    def test_rpt_identity_does_not_count_as_attendance(self):
        path = Path(self.temp.name)/"server.rpt"
        codes = ",".join(str(ord(c)) for c in "Edonn | Houcai")
        path.write_text(f'12:30:00 "TAE_IDENTITY_V1|{STEAM}|{codes}|END"\n',encoding="utf-8")
        self.assertEqual(ingest(self.db,path),0)
        self.assertEqual(self.db.execute("SELECT name FROM observed_players").fetchone(),("Edonn | Houcai",))
        self.assertEqual(self.db.execute("SELECT count(*) FROM events").fetchone()[0],0)
        self.assertEqual(ingest(self.db,path),0)

    def test_malformed_names_not_ingested(self):
        path = Path(self.temp.name)/"server.rpt"
        path.write_text(f'12:30:00 "TAE_IDENTITY_V1|{STEAM}|10|END"\n',encoding="utf-8")
        ingest(self.db,path)
        self.assertEqual(self.db.execute("SELECT name FROM observed_players").fetchone(),("Edonn Houcai",))
