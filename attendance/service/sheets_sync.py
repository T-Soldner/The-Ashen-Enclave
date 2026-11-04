"""Explicit row bindings and finalized-ledger exports. Writes require opt-in."""
import json
from pathlib import Path
import re
from urllib.parse import quote

from sheets_read_test import BASE, SPREADSHEET_ID, TRACKER_ID, READ_SCOPE, get_json, read_tracker

HISTORY_TITLE = "Attendance last four"
HISTORY_HEADERS = ["Member", "Most recent op", "Previous op", "3rd most recent", "4th most recent", "Last four satisfied"]
ARCHIVE_TITLE = "Archived Members"
ARCHIVE_HEADERS = ["Member", "Operations attended", "Archived UTC", "Counting from", "Recent finalized results"]


def initialize(db):
    db.executescript("""
        CREATE TABLE IF NOT EXISTS sheet_bindings (
            steam_id TEXT PRIMARY KEY, sheet_row INTEGER NOT NULL UNIQUE,
            expected_name TEXT NOT NULL, last_total INTEGER NOT NULL
        );
        CREATE TABLE IF NOT EXISTS sheet_exports (
            id INTEGER PRIMARY KEY, utc TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
            state TEXT NOT NULL, payload TEXT NOT NULL
        );
    """)


def number(value):
    if not re.fullmatch(r"[0-9]+", str(value)):
        raise ValueError("Tracker totals must be plain nonnegative integers; formulas/blank totals require staff review.")
    return int(value)


class Google:
    def __init__(self, credential_path, writable=False):
        self.credential_path = Path(credential_path)
        self.writable = writable
        self.session = None

    def __enter__(self):
        from google.auth.transport.requests import AuthorizedSession
        from google.oauth2 import service_account
        with self.credential_path.open(encoding="utf-8-sig") as stream:
            info = json.load(stream)
        if info.get("type") != "service_account":
            raise ValueError("Expected a service-account credential.")
        info["token_uri"] = "https://oauth2.googleapis.com/token"
        scope = "https://www.googleapis.com/auth/spreadsheets" if self.writable else READ_SCOPE
        self.session = AuthorizedSession(service_account.Credentials.from_service_account_info(info, scopes=[scope]))
        return self

    def __exit__(self, *args):
        if self.session:
            self.session.close()

    def snapshot(self):
        tracker = read_tracker(self.session)
        if tracker["truncated"]:
            raise ValueError("Tracker exceeds the safe read limit; refusing export.")
        # Formula rendering prevents overwriting a calculated total with a number.
        formulas = get_json(self.session, BASE + SPREADSHEET_ID + "/values/" + quote(tracker["range"], safe=""),
                            {"valueRenderOption": "FORMULA"}).get("values", [])
        tracker["formula_rows"] = {index for index, row in enumerate(formulas, 1)
                                   if len(row) > 1 and str(row[1]).startswith("=")}
        return tracker

    def history(self):
        metadata = get_json(self.session, BASE + SPREADSHEET_ID,
                            {"fields": "sheets(properties(sheetId,title,gridProperties(rowCount,columnCount)))"})
        tab = next((sheet["properties"] for sheet in metadata["sheets"] if sheet["properties"]["title"] == HISTORY_TITLE), None)
        if tab is None:
            return None
        data = get_json(self.session, BASE + SPREADSHEET_ID + "/values/" + quote(f"'{HISTORY_TITLE}'!A1:F1000", safe=""),
                        {"valueRenderOption": "FORMULA"}).get("values", [])
        if data and data[0] != HISTORY_HEADERS:
            raise ValueError("History tab has unexpected headers. Existing contents were not changed.")
        if not data:
            raise ValueError("Existing history tab is empty/unclaimed; review it before using the bot-owned title.")
        return data

    def create_history(self):
        if not self.writable:
            raise ValueError("Sheet writes disabled.")
        if self.history() is not None:
            return "History tab already initialized."
        response = self.session.post(BASE + SPREADSHEET_ID + ":batchUpdate", json={"requests": [
            {"addSheet": {"properties": {"sheetId": 1483591827, "title": HISTORY_TITLE, "gridProperties": {
                "rowCount": 1000, "columnCount": 6, "frozenRowCount": 1}}}},
            {"updateCells": {"start": {"sheetId": 1483591827, "rowIndex": 0, "columnIndex": 0},
                              "rows": [{"values": [{"userEnteredValue": {"stringValue": header},
                                                      "userEnteredFormat": {"textFormat": {"bold": True}}}
                                                     for header in HISTORY_HEADERS]}],
                              "fields": "userEnteredValue,userEnteredFormat.textFormat"}}]}, timeout=30, allow_redirects=False)
        if response.status_code != 200:
            raise ValueError("Could not create history tab; check Editor access. No tracker totals were changed.")
        return "Created Attendance last four. Original tracker columns untouched."

    def write(self, changes):
        if not self.writable:
            raise ValueError("Sheet writes disabled.")
        response = self.session.post(BASE + SPREADSHEET_ID + "/values:batchUpdate", json={
            "valueInputOption": "RAW", "data": changes}, timeout=30, allow_redirects=False)
        if response.status_code != 200:
            raise ValueError("Sheet export failed; check permissions and inspect the sheet before retrying.")

    def new_member_row(self):
        snapshot = self.snapshot()
        cell_range = "'" + snapshot["tab"].replace("'", "''") + "'!A1:ZZ1000"
        rows = get_json(self.session, BASE+SPREADSHEET_ID+"/values/"+quote(cell_range,safe=""),
                        {"valueRenderOption":"FORMULA"}).get("values", [])
        row = max((i for i, values in enumerate(rows,1) if any(value != "" for value in values)), default=1) + 1
        if row > 1000:
            raise ValueError("Tracker is full for safe onboarding; staff review required.")
        return row

    def add_member(self, row, label):
        if row != self.new_member_row():
            raise ValueError("Tracker changed during onboarding. No write repeated; inspect receipt.")
        snapshot = self.snapshot()
        tab = "'" + snapshot["tab"].replace("'", "''") + "'"
        self.write([{"range":f"{tab}!A{row}:B{row}","values":[[label,0]]}])
        entry = next((entry for entry in self.snapshot()["entries"] if entry["row"] == row),None)
        if not entry or entry["name"] != label or str(entry["ops"]) != "0":
            raise ValueError("New tracker row could not be verified. Inspect receipt before retrying.")

    def plan_archive(self, payload):
        if not self.writable:
            raise ValueError("Sheet writes disabled; member is archived locally only.")
        row, label, last_total = payload["binding"]
        snapshot = self.snapshot()
        source = next((entry for entry in snapshot["entries"] if entry["row"] == row), None)
        if not source or source["name"] != label or row in snapshot["formula_rows"]:
            raise ValueError("Archived member's mapped row changed; no sheet cells cleared.")
        if number(source["ops"]) not in (last_total,payload["total"]):
            raise ValueError("Archived member's tracker total was manually edited; reconcile before clearing it.")
        history = self.history()
        if history is not None and row <= len(history) and history[row-1] and history[row-1][0] not in ("",label):
            raise ValueError("Recent-op row belongs to someone else; no cells cleared.")
        metadata = get_json(self.session, BASE+SPREADSHEET_ID, {"fields":"sheets(properties(sheetId,title,gridProperties(rowCount,columnCount)))"})
        archive = next((item["properties"] for item in metadata["sheets"] if item["properties"]["title"] == ARCHIVE_TITLE), None)
        requests = []
        sheet_id, archive_row = 1483591828, 1
        if archive:
            data = get_json(self.session, BASE+SPREADSHEET_ID+"/values/"+quote(f"'{ARCHIVE_TITLE}'!A1:E1000",safe=""), {"valueRenderOption":"FORMULA"}).get("values",[])
            if not data or data[0] != ARCHIVE_HEADERS or len(data) >= 1000:
                raise ValueError("Archive tab has unexpected headers or is full; original rows remain untouched.")
            sheet_id, archive_row = archive["sheetId"], len(data)
        else:
            requests += [{"addSheet":{"properties":{"sheetId":sheet_id,"title":ARCHIVE_TITLE,"gridProperties":{"rowCount":1000,"columnCount":5,"frozenRowCount":1}}}},
                         {"updateCells":{"start":{"sheetId":sheet_id,"rowIndex":0,"columnIndex":0},"rows":[{"values":[{"userEnteredValue":{"stringValue":header}} for header in ARCHIVE_HEADERS]}],"fields":"userEnteredValue"}}]
        values = [label,payload["total"],payload["archived_utc"],payload["since"], "; ".join(op+": "+status for op,status in payload["recent"])]
        requests.append({"updateCells":{"start":{"sheetId":sheet_id,"rowIndex":archive_row,"columnIndex":0},"rows":[{"values":[{"userEnteredValue": {"numberValue":value} if isinstance(value,int) else {"stringValue":value}} for value in values]}],"fields":"userEnteredValue"}})
        requests.append({"repeatCell":{"range":{"sheetId":TRACKER_ID,"startRowIndex":row-1,"endRowIndex":row,"startColumnIndex":0,"endColumnIndex":2},"cell":{},"fields":"userEnteredValue"}})
        if history is not None:
            history_id = next(item["properties"]["sheetId"] for item in metadata["sheets"] if item["properties"]["title"] == HISTORY_TITLE)
            requests.append({"repeatCell":{"range":{"sheetId":history_id,"startRowIndex":row-1,"endRowIndex":row,"startColumnIndex":0,"endColumnIndex":6},"cell":{},"fields":"userEnteredValue"}})
        return {"requests":requests, "archive_row":archive_row+1, "source_row":row, "values":values}

    def apply_archive(self, plan):
        if not self.writable:
            raise ValueError("Sheet writes disabled.")
        response = self.session.post(BASE+SPREADSHEET_ID+":batchUpdate",json={"requests":plan["requests"]},timeout=30,allow_redirects=False)
        if response.status_code != 200:
            raise ValueError("Sheet archive failed; inspect the receipt and sheet before retrying.")
        data = get_json(self.session,BASE+SPREADSHEET_ID+"/values/"+quote(f"'{ARCHIVE_TITLE}'!A{plan['archive_row']}:E{plan['archive_row']}",safe=""),
                        {"valueRenderOption":"UNFORMATTED_VALUE"}).get("values",[])
        values = (data[0] if data else [])
        values += [""] * (5-len(values))
        if values != plan["values"] or any(entry["row"] == plan["source_row"] for entry in self.snapshot()["entries"]):
            raise ValueError("Archive read-back differs; inspect the sheet before retrying.")


def bind(db, google, discord_id, row, expected_name, guild_id):
    snapshot = google.snapshot()
    source = next((entry for entry in snapshot["entries"] if entry["row"] == row), None)
    member = db.execute("SELECT steam_id,baseline_ops FROM members WHERE discord_id=? AND active=1", (str(discord_id),)).fetchone()
    if not member or not source or row < 2 or source["name"] != expected_name or row in snapshot["formula_rows"]:
        raise ValueError("Binding refused. Use an active linked member, exact sheet name and a non-formula data row.")
    current = number(source["ops"])
    finalized = db.execute("SELECT count(*) FROM operation_credits WHERE guild_id=? AND steam_id=? AND status='attended'",
                           (str(guild_id), member[0])).fetchone()[0]
    if current not in (member[1], member[1] + finalized):
        raise ValueError("Sheet total does not match the member's baseline or finalized total. Reconcile before binding.")
    with db:
        db.execute("INSERT INTO sheet_bindings VALUES (?,?,?,?)", (member[0], row, expected_name, current))
    return f"Bound sheet row {row} to this member locally. No sheet values changed."


def prepare(db, google, guild_id):
    snapshot = google.snapshot()
    history = google.history()
    source_rows = {row["row"]: row for row in snapshot["entries"]}
    bindings = db.execute("SELECT b.steam_id,b.sheet_row,b.expected_name,b.last_total,m.discord_id,m.baseline_ops FROM sheet_bindings b JOIN members m ON m.steam_id=b.steam_id WHERE m.active=1").fetchall()
    if not bindings:
        raise ValueError("No explicit sheet row bindings yet.")
    changes, targets, descriptions = [], [], []
    for steam, row, label, last, discord, baseline in bindings:
        source = source_rows.get(row)
        if not source or source["name"] != label or row in snapshot["formula_rows"]:
            raise ValueError(f"Row {row} moved, was renamed or now contains a formula. No export was performed.")
        count = db.execute("SELECT count(*) FROM operation_credits WHERE guild_id=? AND steam_id=? AND status='attended'", (str(guild_id), steam)).fetchone()[0]
        desired = baseline + count
        current = number(source["ops"])
        if current not in (last, desired):
            raise ValueError(f"Row {row} was manually changed; reconcile before exporting.")
        targets.append((steam, desired))
        descriptions.append(f"Row {row} {label}: {current} -> {desired} ({baseline} starting + {count} finalized)")
        if current != desired:
            title = snapshot["tab"].replace("'", "''")
            changes.append({"range": f"'{title}'!B{row}", "values": [[desired]]})
        recent = db.execute("SELECT operation,status FROM operation_credits WHERE guild_id=? AND steam_id=? ORDER BY substr(operation,1,10) DESC, CASE WHEN operation LIKE '%:fun' THEN 1 ELSE 0 END DESC LIMIT 4", (str(guild_id), steam)).fetchall()
        statuses = [f"{op}: {status}" for op, status in recent]
        values = [label] + statuses + [""] * (4 - len(statuses)) + [f"{sum(status in ('attended','excused') for _,status in recent)}/{len(recent)}"]
        if history is not None:
            previous = history[row-1] if row <= len(history) else []
            if previous and previous[0] not in ("", label):
                raise ValueError(f"History row {row} belongs to a different name. Review before export.")
            padded = previous + [""] * (6 - len(previous))
            if padded != values:
                changes.append({"range": f"'{HISTORY_TITLE}'!A{row}:F{row}", "values": [values]})
    unmapped = db.execute("SELECT count(*) FROM members m WHERE active=1 AND NOT EXISTS (SELECT 1 FROM sheet_bindings b WHERE b.steam_id=m.steam_id)").fetchone()[0]
    return {"changes": changes, "targets": targets, "description": descriptions,
            "history_ready": history is not None, "unmapped": unmapped}


def export(db, google, guild_id, enabled=False):
    if not enabled:
        raise ValueError("Sheet writes disabled; use sheet-preview first.")
    plan = prepare(db, google, guild_id)
    if not plan["history_ready"]:
        raise ValueError("Initialize the separate history tab before exporting.")
    if plan["unmapped"]:
        raise ValueError("Some active linked members are not mapped. Bind them before exporting.")
    if db.execute("SELECT 1 FROM sheet_exports WHERE state IN ('sending','uncertain') LIMIT 1").fetchone():
        raise ValueError("An earlier export has an uncertain result. Staff must inspect the sheet/receipt before retrying.")
    if plan["changes"]:
        with db:
            job = db.execute("INSERT INTO sheet_exports (state,payload) VALUES ('sending',?)", (json.dumps(plan["changes"]),)).lastrowid
        try:
            google.write(plan["changes"])
            verified = prepare(db, google, guild_id)
            if verified["changes"]:
                raise ValueError("Sheet read-back did not match the planned export.")
        except BaseException:
            with db:
                db.execute("UPDATE sheet_exports SET state='uncertain' WHERE id=?", (job,))
            raise
        with db:
            db.execute("UPDATE sheet_exports SET state='sent' WHERE id=?", (job,))
    with db:
        db.executemany("UPDATE sheet_bindings SET last_total=? WHERE steam_id=?", [(total, steam) for steam,total in plan["targets"]])
    return "Sheet export verified. Only finalized totals and the separate last-four tab were updated."
