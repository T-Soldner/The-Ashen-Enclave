"""One-shot, read-only Google Sheets connection test. Never opens SQLite."""
import argparse
import json
from pathlib import Path
import sys
from urllib.parse import quote

SPREADSHEET_ID = "1OFlOed_yWqLgfKsokPMsRdl3dGChbDx8GB_9fk0Wb74"
TRACKER_ID = 1178516523
READ_SCOPE = "https://www.googleapis.com/auth/spreadsheets.readonly"
BASE = "https://sheets.googleapis.com/v4/spreadsheets/"


def get_json(session, url, params):
    response = session.get(url, params=params, timeout=30, allow_redirects=False)
    if response.status_code != 200:
        hints = {
            400: "Google rejected the request; confirm the sheet layout and API configuration.",
            401: "Authentication failed; check the credential and the server clock.",
            403: "Enable Google Sheets API in the credential's project and share the sheet with its service-account email as Viewer.",
            404: "Sheet not found or not shared with this service account.",
            429: "Google rate limit reached; wait before trying again.",
        }
        raise ValueError(f"Google HTTP {response.status_code}: " + hints.get(response.status_code, "Google request failed; try again later."))
    return response.json()


def read_tracker(session):
    url = BASE + SPREADSHEET_ID
    metadata = get_json(session, url, {
        "fields": "properties(title,timeZone),sheets(properties(sheetId,title,gridProperties(rowCount,columnCount)))"
    })
    matches = [sheet["properties"] for sheet in metadata.get("sheets", [])
               if sheet.get("properties", {}).get("sheetId") == TRACKER_ID]
    if len(matches) != 1:
        raise ValueError("The configured operations tracker tab was not found. No other tab was read.")
    tab = matches[0]
    grid = tab.get("gridProperties", {})
    if grid.get("columnCount", 0) < 2:
        raise ValueError("Operations tracker needs at least two columns.")
    rows = min(grid.get("rowCount", 0), 1000)
    if rows < 1:
        raise ValueError("Operations tracker has no readable grid rows.")
    cell_range = "'" + tab["title"].replace("'", "''") + f"'!A1:B{rows}"
    values = get_json(session, url + "/values/" + quote(cell_range, safe=""), {
        "valueRenderOption": "FORMATTED_VALUE", "majorDimension": "ROWS"
    }).get("values", [])
    expected = ["Member Name", "Operations Attended"]
    if not values or [str(x).strip() for x in values[0][:2]] != expected:
        raise ValueError("Unexpected tracker headers. Expected Member Name / Operations Attended; no data was imported.")
    entries = [{"row": number, "name": str(row[0]).strip(),
                "ops": str(row[1]).strip() if len(row) > 1 else ""}
               for number, row in enumerate(values[1:], 2) if row and str(row[0]).strip()]
    return {"title": metadata.get("properties", {}).get("title", ""),
            "tab": tab["title"], "range": cell_range, "entries": entries,
            "truncated": grid.get("rowCount", 0) > rows}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--credentials", type=Path,
                        default=Path("D:/TAEAttendance/secrets/google-service-account.json"))
    args = parser.parse_args()
    if not args.credentials.is_file():
        parser.exit(1, "Credential file not found. Pass its actual filename with --credentials. Do not paste its contents.\n")
    try:
        from google.auth.transport.requests import AuthorizedSession
        from google.oauth2 import service_account
        from google.auth.exceptions import GoogleAuthError
        from requests.exceptions import RequestException
    except ImportError:
        parser.exit(1, "Missing dependencies. Use the approved google-auth and requests installation in this Python environment.\n")
    try:
        # Pin OAuth endpoint; never print the credential JSON or authentication errors.
        with args.credentials.open(encoding="utf-8-sig") as stream:
            info = json.load(stream)
        if info.get("type") != "service_account":
            raise ValueError("Expected a service-account JSON credential.")
        info["token_uri"] = "https://oauth2.googleapis.com/token"
        credentials = service_account.Credentials.from_service_account_info(info, scopes=[READ_SCOPE])
        with AuthorizedSession(credentials) as session:
            result = read_tracker(session)
    except (GoogleAuthError, RequestException):
        parser.exit(1, "Authentication/network request failed. Check server clock, outbound HTTPS, API enablement and credential validity. Credential details were not printed.\n")
    except (ValueError, KeyError, OSError) as error:
        # Our validation errors contain no credential fields; suppress other details.
        message = str(error) if isinstance(error, ValueError) and str(error).startswith(
            ("Google HTTP", "The configured", "Operations tracker", "Unexpected tracker", "Expected a service-account")) else "Unable to read credential or Google response; check file format and access permissions."
        parser.exit(1, message + "\n")
    print("READ-ONLY CONNECTION SUCCESSFUL")
    print("Spreadsheet:", result["title"])
    print("Tab:", result["tab"])
    print("Named rows read:", len(result["entries"]))
    print("First 10 named rows:")
    for entry in result["entries"][:10]:
        print(f"  Row {entry['row']}: {entry['name']} | ops: {entry['ops']}")
    candidates = [entry for entry in result["entries"] if "edonn" in entry["name"].casefold()]
    print("Edonn name matches (display only, not identity verification):")
    for entry in candidates:
        print(f"  Row {entry['row']}: {entry['name']} | sheet ops: {entry['ops']} | expected baseline: 39")
    if not candidates:
        print("  No matching name found; review the sheet manually.")
    if result["truncated"]:
        print("WARNING: Read capped at 1000 rows.")
    print("No sheet or attendance database changes made.")


if __name__ == "__main__":
    main()
