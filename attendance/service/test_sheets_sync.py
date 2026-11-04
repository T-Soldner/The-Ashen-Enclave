import copy
from pathlib import Path
import re
import tempfile
import unittest

from attendance import link
from collector import connect
from discord_store import Store
from sheets_sync import Google, HISTORY_HEADERS, bind, export, prepare

UID = "76561198000000001"
DID = "248567812203872257"
GUILD = "1477486339984199932"


class GoogleFake:
    def __init__(self):
        self.data = {"tab": "operations tracker", "entries": [{"row": 3, "name": "[RM] EDONN", "ops": "39"}], "formula_rows": set()}
        self.hist = [HISTORY_HEADERS]
        self.writes = []
        self.fail = False

    def snapshot(self):
        return copy.deepcopy(self.data)

    def history(self):
        return copy.deepcopy(self.hist)

    def write(self, changes):
        self.writes.append(copy.deepcopy(changes))
        if self.fail:
            raise RuntimeError("uncertain send")
        for change in changes:
            cell = change["range"].split("!")[1]
            row = int(re.search(r"\d+", cell)[0])
            if cell.startswith("B"):
                next(entry for entry in self.data["entries"] if entry["row"] == row)["ops"] = str(change["values"][0][0])
            else:
                while len(self.hist) < row:
                    self.hist.append([])
                self.hist[row-1] = change["values"][0]


class SheetSyncTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        path = Path(self.root.name) / "test.sqlite3"
        connect(path).close()
        self.store = Store(path)
        self.db = connect(path)
        link(self.db, UID, DID, "Edonn", "2026-11-07", 39)
        self.google = GoogleFake()

    def tearDown(self):
        self.db.close()
        self.root.cleanup()

    def bind(self):
        return bind(self.db, self.google, DID, 3, "[RM] EDONN", GUILD)

    def credit(self, status="attended", operation="2026-11-07:main"):
        with self.db:
            self.db.execute("INSERT INTO operation_credits VALUES (?,?,?,?,?,?,?)", (GUILD, operation, UID, DID, "Edonn", status, 360 if status == "attended" else 0))

    def test_binding_is_explicit_and_read_only(self):
        self.bind()
        self.assertEqual(self.google.writes, [])
        self.assertEqual(self.db.execute("SELECT sheet_row FROM sheet_bindings").fetchone()[0], 3)

    def test_no_fuzzy_name_binding(self):
        with self.assertRaises(ValueError):
            bind(self.db, self.google, DID, 3, "Edonn", GUILD)

    def test_formula_never_replaced(self):
        self.google.data["formula_rows"] = {3}
        with self.assertRaises(ValueError):
            self.bind()

    def test_preview_only_finalized_total(self):
        self.bind()
        self.credit()
        data = prepare(self.db, self.google, GUILD)
        self.assertIn("39 -> 40", data["description"][0])
        self.assertEqual(self.google.writes, [])
        self.assertTrue(all("!B3" in row["range"] or "Attendance last four" in row["range"] for row in data["changes"]))

    def test_export_disabled_by_default(self):
        self.bind()
        with self.assertRaises(ValueError):
            export(self.db, self.google, GUILD)
        self.assertEqual(self.google.writes, [])

    def test_repeat_export_does_not_add_credit(self):
        self.bind()
        self.credit()
        export(self.db, self.google, GUILD, enabled=True)
        export(self.db, self.google, GUILD, enabled=True)
        self.assertEqual(len(self.google.writes), 1)
        self.assertEqual(self.google.data["entries"][0]["ops"], "40")

    def test_moved_or_renamed_row_blocks_export(self):
        self.bind()
        self.google.data["entries"][0]["name"] = "Another member"
        with self.assertRaises(ValueError):
            export(self.db, self.google, GUILD, enabled=True)
        self.assertEqual(self.google.writes, [])

    def test_human_total_edit_blocks_export(self):
        self.bind()
        self.google.data["entries"][0]["ops"] = "100"
        with self.assertRaises(ValueError):
            export(self.db, self.google, GUILD, enabled=True)

    def test_excused_satisfies_last_four_without_total_credit(self):
        self.bind()
        self.credit(status="excused")
        self.credit(status="attended", operation="2026-11-07:fun")
        data = prepare(self.db, self.google, GUILD)
        values = next(row["values"][0] for row in data["changes"] if "Attendance last four" in row["range"])
        self.assertIn("fun: attended", values[1])
        self.assertEqual(values[-1], "2/2")
        self.assertIn("39 -> 40", data["description"][0])

    def test_missing_history_blocks_live_export(self):
        self.bind()
        self.google.hist = None
        with self.assertRaises(ValueError):
            export(self.db, self.google, GUILD, enabled=True)

    def test_unmapped_active_member_blocks_export(self):
        self.bind()
        link(self.db, "76561198000000002", "123456789012345678", "Other", "2026-11-07", 0)
        with self.assertRaises(ValueError):
            export(self.db, self.google, GUILD, enabled=True)

    def test_uncertain_request_is_not_blindly_retried(self):
        self.bind()
        self.google.fail = True
        with self.assertRaises(RuntimeError):
            export(self.db, self.google, GUILD, enabled=True)
        self.google.fail = False
        with self.assertRaises(ValueError):
            export(self.db, self.google, GUILD, enabled=True)
        self.assertEqual(len(self.google.writes), 1)

    def test_history_creation_is_atomic_and_only_adds_new_tab(self):
        class Reply:
            status_code = 200
            def json(self):
                return {"sheets": []}
        class Session:
            def __init__(self):
                self.posts = []
            def get(self, *args, **kwargs):
                return Reply()
            def post(self, url, **kwargs):
                self.posts.append((url,kwargs))
                return Reply()
        google = Google("unused", writable=True)
        google.session = Session()
        google.create_history()
        self.assertEqual(len(google.session.posts), 1)
        requests = google.session.posts[0][1]["json"]["requests"]
        self.assertEqual(len(requests), 2)
        self.assertEqual(requests[0]["addSheet"]["properties"]["sheetId"], requests[1]["updateCells"]["start"]["sheetId"])
