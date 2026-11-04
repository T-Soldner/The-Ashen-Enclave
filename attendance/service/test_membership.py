import json
from pathlib import Path
import tempfile
import unittest

from attendance import link
from collector import connect
from discord_store import Store
from membership import archive, export_archive
from sheets_sync import Google

DID = "123456789012345678"
UID = "76561198000000001"
GUILD = "1477486339984199932"


class ArchiveTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        path = Path(self.root.name) / "test.sqlite3"
        connect(path).close()
        Store(path)
        self.db = connect(path)
        link(self.db,UID,DID,"Character","2026-11-07",39)
        with self.db:
            self.db.execute("INSERT INTO operation_credits VALUES (?,?,?,?,?,?,?)",(GUILD,"2026-11-07:main",UID,DID,"Character","attended",360))
            self.db.execute("INSERT INTO sheet_bindings VALUES (?,?,?,?)",(UID,3,"[MV] Character",39))

    def tearDown(self):
        self.db.close()
        self.root.cleanup()

    def test_deactivate_and_preserve_history(self):
        data = archive(self.db,GUILD,DID,DID)
        self.assertEqual(data["total"],40)
        self.assertEqual(self.db.execute("SELECT active FROM members").fetchone()[0],0)
        self.assertEqual(self.db.execute("SELECT count(*) FROM operation_credits").fetchone()[0],1)
        self.assertEqual(self.db.execute("SELECT count(*) FROM sheet_bindings").fetchone()[0],1)

    def test_repeat_archive_is_idempotent(self):
        first = archive(self.db,GUILD,DID,DID)
        self.assertEqual(first,archive(self.db,GUILD,DID,DID))
        self.assertEqual(self.db.execute("SELECT count(*) FROM archived_members").fetchone()[0],1)

    def test_unlinked_person_not_guessed_from_name(self):
        with self.assertRaises(ValueError):
            archive(self.db,GUILD,"99999999999999999",DID)

    def test_uncertain_sheet_request_not_repeated(self):
        class BrokenGoogle:
            def plan_archive(self,payload):
                return {}
            def apply_archive(self,plan):
                raise RuntimeError("uncertain response")
        archive(self.db,GUILD,DID,DID)
        with self.assertRaises(RuntimeError):
            export_archive(self.db,BrokenGoogle(),GUILD,DID)
        with self.assertRaises(ValueError):
            export_archive(self.db,BrokenGoogle(),GUILD,DID)
        self.assertEqual(self.db.execute("SELECT active FROM members").fetchone()[0],0)

    def test_verified_sheet_archive_not_duplicated(self):
        class GoogleFake:
            calls = 0
            def plan_archive(self,payload):
                return {}
            def apply_archive(self,plan):
                self.calls += 1
        google = GoogleFake()
        archive(self.db,GUILD,DID,DID)
        export_archive(self.db,google,GUILD,DID)
        export_archive(self.db,google,GUILD,DID)
        self.assertEqual(google.calls,1)

    def test_archive_api_plan_does_not_delete_or_shift_rows(self):
        class Response:
            status_code = 200
            def json(self):
                return {"sheets": []}
        class Session:
            def get(self,*args,**kwargs):
                return Response()
        data = archive(self.db,GUILD,DID,DID)
        google = Google("unused",writable=True)
        google.session = Session()
        google.snapshot = lambda: {"entries":[{"row":3,"name":"[MV] Character","ops":"39"}],"formula_rows":set()}
        google.history = lambda: None
        plan = google.plan_archive(data)
        self.assertFalse(any("deleteDimension" in request for request in plan["requests"]))
        cleared = next(request["repeatCell"]["range"] for request in plan["requests"] if "repeatCell" in request)
        self.assertEqual((cleared["startRowIndex"],cleared["endRowIndex"],cleared["endColumnIndex"]),(2,3,2))
        self.assertEqual(plan["values"][1],40)


if __name__ == "__main__":
    unittest.main()
