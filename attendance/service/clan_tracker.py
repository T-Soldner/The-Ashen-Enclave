"""Discord-role grouping for the human-readable tracker; never moves backend rows."""
from urllib.parse import quote

from sheets_read_test import BASE, SPREADSHEET_ID, get_json
import clan_training

GROUP_ID = 1483591829
GROUP_TITLE = "Attendance clan groups"
HEADERS = ["Backend member label", "Discord group"]
ROLE_NAMES = {"clan acklay":"Clan Acklay", "clan rook":"Clan Rook",
              "shyyyo flight":"Shyyyo Flight", "freelance mandalorians":"Freelancers"}
ROLE_IDS = {clan["role"]:("Shyyyo Flight" if key == "shyyyo" else "Clan "+clan["name"])
            for key,clan in clan_training.CLANS.items()}
ROLE_IDS[clan_training.FREELANCER] = "Freelancers"


def classify(role_names):
    groups = set()
    for role in role_names:
        label = ROLE_IDS.get(role) if isinstance(role,int) else ROLE_NAMES.get(role.casefold())
        if label:
            groups.add(label)
    # The onboarding default Freelancer role may remain when a clan role is added.
    specific = groups - {"Freelancers"}
    if len(specific) > 1:
        return "Needs clan assignment"
    return next(iter(specific or groups), "Needs clan assignment")


def sync(db, google, members):
    if not google.writable:
        raise ValueError("Sheet writes disabled.")
    metadata = get_json(google.session, BASE+SPREADSHEET_ID,
                        {"fields":"sheets(properties(sheetId,title))"})
    tab = next((sheet["properties"] for sheet in metadata["sheets"]
                if sheet["properties"]["sheetId"] == GROUP_ID), None)
    if not tab or tab["title"] != GROUP_TITLE:
        raise ValueError("Clan display helper is not initialized. Attendance totals were not changed by grouping.")
    url = BASE+SPREADSHEET_ID+"/values/"+quote(f"'{GROUP_TITLE}'!A1:B1000",safe="")
    current = get_json(google.session,url,{"valueRenderOption":"FORMULA"}).get("values",[])
    if not current or current[0] != HEADERS:
        raise ValueError("Clan helper headers changed; no grouping overwritten.")
    labels = db.execute("SELECT b.expected_name,m.discord_id FROM sheet_bindings b JOIN members m ON m.steam_id=b.steam_id WHERE m.active=1").fetchall()
    values = [HEADERS] + [[label,classify(members.get(str(did),[]))] for label,did in labels]
    if len(values) > 1000:
        raise ValueError("Too many clan mappings for the display helper.")
    rows = [{"values":[{"userEnteredValue":{"stringValue":value}} for value in row]} for row in values]
    response = google.session.post(BASE+SPREADSHEET_ID+":batchUpdate",json={"requests":[{
        "updateCells":{"range":{"sheetId":GROUP_ID,"startRowIndex":0,"endRowIndex":1000,"startColumnIndex":0,"endColumnIndex":2},
                       "rows":rows,"fields":"userEnteredValue"}}]},timeout=30,allow_redirects=False)
    if response.status_code != 200:
        raise ValueError("Clan display refresh failed; attendance totals are unchanged by grouping.")
    actual = get_json(google.session,url,{"valueRenderOption":"FORMULA"}).get("values",[])
    if actual != values:
        raise ValueError("Clan display refresh could not be verified; retry a read-only preview before syncing again.")
    return "Clan grouping refreshed from Discord roles."
