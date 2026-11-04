import unittest
from urllib.parse import unquote

from sheets_read_test import READ_SCOPE, TRACKER_ID, read_tracker


class Response:
    status_code = 200

    def __init__(self, data):
        self.data = data

    def json(self):
        return self.data


class Session:
    def __init__(self, tab="operations tracker", headers=None, tracker_id=TRACKER_ID):
        self.calls = []
        self.tab = tab
        self.tracker_id = tracker_id
        self.headers = headers or ["Member Name", "Operations Attended"]

    def get(self, url, **kwargs):
        self.calls.append((url, kwargs))
        if "/values/" not in url:
            return Response({"properties": {"title": "TAE"}, "sheets": [{"properties": {
                "sheetId": self.tracker_id, "title": self.tab,
                "gridProperties": {"rowCount": 981, "columnCount": 26}}}]})
        return Response({"values": [self.headers, ["[RM] Edonn", "39"], [], ["Someone", "2"]]})


class SheetsReadTests(unittest.TestCase):
    def test_metadata_then_bounded_get_only(self):
        session = Session()
        result = read_tracker(session)
        self.assertEqual(len(session.calls), 2)
        self.assertTrue(unquote(session.calls[1][0]).endswith("'operations tracker'!A1:B981"))
        self.assertEqual(result["entries"][0]["ops"], "39")
        self.assertEqual(result["entries"][1]["row"], 4)
        self.assertTrue(READ_SCOPE.endswith("spreadsheets.readonly"))
        self.assertFalse(session.calls[0][1]["allow_redirects"])

    def test_tab_id_missing_does_not_read_another_tab(self):
        session = Session(tracker_id=123)
        with self.assertRaises(ValueError):
            read_tracker(session)
        self.assertEqual(len(session.calls), 1)

    def test_tab_title_escaping(self):
        result = read_tracker(Session(tab=" team's tracker"))
        self.assertEqual(result["range"], "' team''s tracker'!A1:B981")

    def test_unexpected_headers_fail(self):
        with self.assertRaises(ValueError):
            read_tracker(Session(headers=["Different", "Headers"]))

    def test_access_error(self):
        session = Session()
        session.get = lambda *args, **kwargs: type("Denied", (), {"status_code": 403})()
        with self.assertRaisesRegex(ValueError, "Viewer"):
            read_tracker(session)


if __name__ == "__main__":
    unittest.main()
