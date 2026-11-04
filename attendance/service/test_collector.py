import tempfile
import unittest
from pathlib import Path
from collector import connect, ingest, parse

UID = "76561198000000001"
LINE = f'12:00:00 "TAE_ATTENDANCE_V1|session-a|1|2026,10,31,18,0,0,0|PRESENCE|{UID}|END"\n'


class CollectorTests(unittest.TestCase):
    def test_identity_and_timestamp(self):
        event = parse(LINE)
        self.assertIn(UID, event[4])
        self.assertEqual(event[2], "2026-10-31T18:00:00+00:00")

    def test_ignore_and_reject(self):
        self.assertIsNone(parse("normal RPT line"))
        self.assertIsNone(parse('12:00:00 Player TAE_ATTENDANCE_V1|bad connected'))
        self.assertIsNone(parse('12:00:00 "Chat: TAE_ATTENDANCE_V1|bad"'))
        with self.assertRaises(ValueError):
            parse(LINE.replace(UID, "HC123"))

    def test_resume_partial_duplicate_and_truncation(self):
        with tempfile.TemporaryDirectory() as root:
            path = Path(root) / "server.rpt"
            db = connect(Path(root) / "attendance.sqlite3")
            try:
                path.write_bytes(LINE.encode())
                self.assertEqual(ingest(db, path), 1)
                self.assertEqual(ingest(db, path), 0)
                second = LINE.replace("|1|", "|2|")
                with path.open("ab") as stream:
                    stream.write(second[:-1].encode())
                self.assertEqual(ingest(db, path), 0)
                with path.open("ab") as stream:
                    stream.write(b"\n")
                self.assertEqual(ingest(db, path), 1)
                path.write_bytes(LINE.encode())
                self.assertEqual(ingest(db, path), 0)
                self.assertEqual(db.execute("SELECT count(*) FROM events").fetchone()[0], 2)
            finally:
                db.close()

    def test_malformed_is_preserved_without_stopping_import(self):
        with tempfile.TemporaryDirectory() as root:
            path = Path(root) / "server.rpt"
            path.write_bytes((LINE + LINE.replace("|1|", "|2|").replace(UID, "bad") + LINE.replace("|1|", "|3|")).encode())
            db = connect(Path(root) / "attendance.sqlite3")
            try:
                self.assertEqual(ingest(db, path), 2)
                self.assertEqual(db.execute("SELECT count(*) FROM rejected_events").fetchone()[0], 1)
                self.assertEqual(ingest(db, path), 0)
                self.assertEqual(db.execute("SELECT count(*) FROM events").fetchone()[0], 2)
            finally:
                db.close()


if __name__ == "__main__":
    unittest.main()
