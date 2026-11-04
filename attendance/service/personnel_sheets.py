"""Guarded Unit Roster cells and a separate managed qualification tab."""
import json
import datetime as dt
import hashlib
import re
from urllib.parse import quote

import clan_training as policy
from sheets_read_test import BASE, SPREADSHEET_ID, get_json
from attendance import UTC

ROSTER_ID = 1601819345
TRAINING_ID = 1483591831
TRAINING_TITLE = "Specialization Tracker"
WC, RM = 1477486340080799938, 1477486340080799946
SPECS = list(policy.SPECIALIZATIONS)
HEADERS = ["Member","Group","Primary points"] + [policy.SPECIALIZATIONS[key][0] for key in SPECS] + ["Last trainer","Updated UTC"]


def digest(plans):
    return hashlib.sha256(json.dumps(plans,sort_keys=True).encode("utf-8")).hexdigest()


def remember_preview(db,guild,actor,plans):
    with db:
        db.execute("INSERT OR REPLACE INTO personnel_sheet_previews VALUES (?,?,?,?)",(str(guild),str(actor),digest(plans),policy.now()))


def require_preview(db,guild,actor,plans):
    row = db.execute("SELECT digest,utc FROM personnel_sheet_previews WHERE guild=? AND actor=?",(str(guild),str(actor))).fetchone()
    if not row or row[0] != digest(plans) or dt.datetime.now(UTC)-dt.datetime.fromisoformat(row[1]) > dt.timedelta(minutes=15):
        raise ValueError("Run roster-sync without confirmation first and inspect its preview. Preview must be yours, unchanged and less than 15 minutes old.")


def read(google,cell_range):
    return get_json(google.session,BASE+SPREADSHEET_ID+"/values/"+quote(cell_range,safe=""),
                    {"valueRenderOption":"FORMULA"}).get("values",[])


def training_range(title):
    return "'" + title.replace("'","''") + "'!A1:U1000"


def cell(values,row,col):
    return values[row-1][col-1] if len(values) >= row and len(values[row-1]) >= col else ""


def group(roles):
    matches = [key for key,clan in policy.CLANS.items() if clan["role"] in roles]
    if len(matches) > 1:
        raise ValueError("A member has multiple clan roles. Reconcile Discord roles before roster writes.")
    return matches[0] if matches else "freelancers"


def roster_cells(members,values):
    if set(policy.CLANS) != {"acklay","rook","shyyyo"}:
        raise ValueError("A new clan needs an explicit roster-section mapping before Sheet writes; no members will be omitted.")
    headers = {(10,2):"Clan Acklay",(10,5):"Clan Rook",(34,2):"Flight Lead",(36,2):"Shyyyo Flight",(2,14):"Freelancers"}
    if any(cell(values,r,c) != value for (r,c),value in headers.items()):
        raise ValueError("Unit Roster layout changed. Header/section mappings need review; no cells changed.")
    if len({str(member["id"]) for member in members}) != len(members):
        raise ValueError("Duplicate Discord identities in roster snapshot.")
    managed = [(r,2) for r in range(12,20)] + [(r,5) for r in range(12,20)] + [(r,14) for r in range(4,45)] + [(35,2)] + [(r,2) for r in range(38,41)]
    normalize = lambda name: re.sub(r"^\[[^]]+\]\s*","",str(name)).strip().casefold()
    old_names = {normalize(cell(values,r,c)) for r,c in managed if cell(values,r,c)}
    for member in members:
        if not member["bot"] and policy.HOUSE not in member["roles"] and normalize(member["name"]) in old_names:
            raise ValueError(f"{member['name']} is still in Discord but lacks House Karr. Reconcile their roles; missing House Karr alone is not a departure.")
    for clan in policy.CLANS.values():
        if sum(clan["role"] in member["roles"] for member in members) > clan["limit"]:
            raise ValueError(f"{clan['name']} exceeds its capacity. Roster was not truncated or overwritten.")
    buckets = {key:[] for key in [*policy.CLANS,"freelancers"]}
    leadership = {}
    for member in members:
        if member["bot"] or policy.HOUSE not in member["roles"]:
            continue
        destination = group(member["roles"])
        leader = "wc" if WC in member["roles"] else "rm" if RM in member["roles"] else None
        if leader:
            if leader in leadership:
                raise ValueError("Multiple members hold a protected leadership role; review before roster writes.")
            leadership[leader] = member["name"]
        else:
            buckets[destination].append(member)
    for entries in buckets.values():
        entries.sort(key=lambda entry:(policy.LEADER not in entry["roles"],policy.SECOND not in entry["roles"],entry["name"].casefold(),str(entry["id"])))
    flight = buckets["shyyyo"]
    flight_leaders = [entry for entry in flight if policy.LEADER in entry["roles"]]
    if len(flight_leaders) > 1:
        raise ValueError("Flight Lead cell requires one Shyyyo leader; reconcile duplicate leaders.")
    flight_others = [entry for entry in flight if entry not in flight_leaders]
    if len(flight_others) > 3:
        raise ValueError("Shyyyo has three member rows plus its Flight Lead row. Assign the leader or approve a layout expansion before writing.")
    slots = {"acklay":[(r,2) for r in range(12,20)],"rook":[(r,5) for r in range(12,20)],
             "freelancers":[(r,14) for r in range(4,45)]}
    desired = {}
    for key,positions in slots.items():
        entries = buckets[key]
        if len(entries) > len(positions):
            raise ValueError(f"{key} needs more roster cells; no names were dropped.")
        desired.update({position:entries[i]["name"] if i < len(entries) else "" for i,position in enumerate(positions)})
    desired[(35,2)] = flight_leaders[0]["name"] if flight_leaders else ""
    desired.update({(r,2):flight_others[i]["name"] if i < len(flight_others) else "" for i,r in enumerate(range(38,41))})
    # Preserve the existing leadership labels if the complete roster has no replacement.
    desired[(7,7)] = leadership.get("wc",cell(values,7,7))
    desired[(9,7)] = leadership.get("rm",cell(values,9,7))
    return desired


def roster_plan(google,members):
    values = read(google,"'Unit Roster'!A1:Q47")
    desired = roster_cells(members,values)
    before = {f"{r},{c}":cell(values,r,c) for r,c in desired}
    after = {f"{r},{c}":value for (r,c),value in desired.items()}
    if any(isinstance(value,str) and value.startswith("=") for value in before.values()):
        raise ValueError("A managed roster cell contains a formula; staff must review it before adoption.")
    requests = [{"updateCells":{"start":{"sheetId":ROSTER_ID,"rowIndex":r-1,"columnIndex":c-1},
                "rows":[{"values":[{"userEnteredValue":{"stringValue":value}}]}],"fields":"userEnteredValue"}}
                for (r,c),value in desired.items() if value != cell(values,r,c)]
    return {"kind":"roster","before":before,"after":after,"requests":requests,"legacy_header_cell":cell(values,37,2)}


def training_plan(db,google,guild,members,tab_exists,tab_title=TRAINING_TITLE):
    by_id = {str(member["id"]):member for member in members}
    rows = [HEADERS]
    formats = []
    records = db.execute("SELECT member,name,certified,primaries,trainer,updated,revision FROM training_records WHERE guild=? ORDER BY name COLLATE NOCASE",(str(guild),)).fetchall()
    legacy = {member:state for member,state in db.execute("SELECT member,role_state FROM legacy_training_imports WHERE guild=?",(str(guild),))}
    for identifier,name,certs,primaries,trainer,updated,revision in records:
        certs,primaries = set(json.loads(certs)),set(json.loads(primaries))
        member = by_id.get(identifier)
        label = policy.CLANS[group(member["roles"])]["name"] if member and group(member["roles"]) in policy.CLANS else "Freelancers" if member else "Not in Discord"
        trainer_name = by_id[trainer]["name"] if trainer in by_id else "Former/unavailable trainer"
        if identifier in legacy and revision == 1:
            trainer_name = "Legacy import; original trainer unknown"
        rows.append([member["name"] if member else name,label,sum(policy.SPECIALIZATIONS[key][1] for key in primaries)] +
                    ["X" if key in certs else "" for key in SPECS] + [trainer_name,updated])
        formats.append(["primary" if key in primaries else "certified" if key in certs else "" for key in SPECS])
    if len(rows) > 1000:
        raise ValueError("Training tracker exceeds its safe capacity.")
    before = read(google,training_range(tab_title)) if tab_exists else []
    if tab_exists and (not before or before[0] != HEADERS):
        raise ValueError("Managed specialization tracker headers differ; no legacy or unknown tab will be overwritten.")
    requests = [] if tab_exists else [{"addSheet":{"properties":{"sheetId":TRAINING_ID,"title":TRAINING_TITLE,
        "gridProperties":{"rowCount":1000,"columnCount":21,"frozenRowCount":1,"frozenColumnCount":1,"hideGridlines":True}}}}]
    native_rows = []
    for index,row in enumerate(rows):
        cells = []
        for col,value in enumerate(row):
            fmt = {"textFormat":{"fontFamily":"Arial","fontSize":10},"verticalAlignment":"MIDDLE","wrapStrategy":"WRAP"}
            if index == 0:
                fmt.update(backgroundColor={"red":.26,"green":.26,"blue":.26},textFormat={"fontFamily":"Arial","fontSize":10,"bold":True,"foregroundColor":{"red":1,"green":1,"blue":1}},wrapStrategy="WRAP")
            elif 3 <= col < 19:
                fmt["horizontalAlignment"] = "CENTER"
                mark = formats[index-1][col-3]
                if mark:
                    fmt["textFormat"]["bold"] = True
                    fmt["backgroundColor"] = {"red":1,"green":.9,"blue":.3} if mark == "primary" else {"red":.72,"green":.9,"blue":.68}
            item = {"userEnteredValue":{"numberValue":value} if isinstance(value,int) else {"stringValue":value},"userEnteredFormat":fmt}
            if index and col == 2 and value > 9:
                item["note"] = "Historical primary marks exceed 9 points. Preserved for review; not granted to Discord by import."
                item["userEnteredFormat"]["backgroundColor"] = {"red":1,"green":.65,"blue":.65}
            if 3 <= col < 19:
                item["note"] = "Primary (yellow)" if index and formats[index-1][col-3] == "primary" else "Certified (green)" if index and formats[index-1][col-3] else f"Primary cost: {policy.SPECIALIZATIONS[SPECS[col-3]][1]}"
            cells.append(item)
        native_rows.append({"values":cells})
    requests += [{"updateCells":{"range":{"sheetId":TRAINING_ID,"startRowIndex":0,"endRowIndex":1000,"startColumnIndex":0,"endColumnIndex":21},
                   "rows":native_rows,"fields":"userEnteredValue,userEnteredFormat,note"}}]
    if not tab_exists:
        for begin,end,width in [(0,1,240),(1,2,120),(2,3,90),(3,19,125),(19,21,230)]:
            requests.append({"updateDimensionProperties":{"range":{"sheetId":TRAINING_ID,"dimension":"COLUMNS","startIndex":begin,"endIndex":end},"properties":{"pixelSize":width},"fields":"pixelSize"}})
        requests.append({"updateDimensionProperties":{"range":{"sheetId":TRAINING_ID,"dimension":"ROWS","startIndex":0,"endIndex":1},"properties":{"pixelSize":52},"fields":"pixelSize"}})
    if len(rows) > 1:
        requests.append({"updateDimensionProperties":{"range":{"sheetId":TRAINING_ID,"dimension":"ROWS","startIndex":1,"endIndex":len(rows)},"properties":{"pixelSize":36},"fields":"pixelSize"}})
    return {"kind":"training","before":before,"after":rows,"requests":requests,"tab_title":tab_title}


def prepare(db,google,guild,members):
    metadata = get_json(google.session,BASE+SPREADSHEET_ID,{"fields":"sheets(properties(sheetId,title,gridProperties),merges)"})
    tabs = {sheet["properties"]["sheetId"]:sheet["properties"] for sheet in metadata["sheets"]}
    roster = tabs.get(ROSTER_ID)
    if not roster or roster["title"] != "Unit Roster" or roster["gridProperties"]["rowCount"] < 47:
        raise ValueError("Unit Roster identity/layout needs review.")
    training = tabs.get(TRAINING_ID)
    if not training and any(tab["title"] == TRAINING_TITLE for tab in tabs.values()):
        raise ValueError("Specialization Tracker exists under an unexpected ID; it will not be adopted or overwritten.")
    roster_request = roster_plan(google,members)
    merges = next(sheet.get("merges",[]) for sheet in metadata["sheets"] if sheet["properties"]["sheetId"] == ROSTER_ID)
    roster_request["legacy_header_merged"] = any(merge.get("startRowIndex",0) == 35 and merge.get("endRowIndex",0) >= 37 and
        merge.get("startColumnIndex",0) == 1 and merge.get("endColumnIndex",0) >= 2 for merge in merges)
    for coordinate in roster_request["after"]:
        row,col = (int(value)-1 for value in coordinate.split(","))
        for merge in merges:
            if merge.get("startRowIndex",0) <= row < merge["endRowIndex"] and merge.get("startColumnIndex",0) <= col < merge["endColumnIndex"]:
                if (row,col) != (merge.get("startRowIndex",0),merge.get("startColumnIndex",0)):
                    raise ValueError(f"Roster target {coordinate} is inside a merged heading/non-anchor cell. Review layout; no write performed.")
    return [roster_request,training_plan(db,google,guild,members,bool(training),training["title"] if training else TRAINING_TITLE)]


def legacy_header_recovery(plan,previous):
    old = previous["after"]
    return (plan["kind"] == "roster" and plan.get("legacy_header_merged") is True and
            plan.get("legacy_header_cell") == "" and bool(old.get("37,2")) and
            "37,2" not in plan["before"] and plan["before"] == {key:value for key,value in old.items() if key != "37,2"})


def apply(db,google,plans,initialize=False):
    if not google.writable:
        raise ValueError("Sheet writes disabled.")
    for plan in plans:
        old = db.execute("SELECT state,payload FROM personnel_sheet_state WHERE kind=?",(plan["kind"],)).fetchone()
        if not old and not initialize:
            raise ValueError("Roster/training Sheet writes need first-run preview and explicit roster-sync confirmation.")
        if old:
            previous = json.loads(old[1])
            recovery = legacy_header_recovery(plan,previous)
            if recovery and not initialize:
                raise ValueError("Shyyyo header correction requires a fresh roster-sync preview and explicit confirmation.")
            if old[0] != "complete" and plan["before"] != previous["after"] and not recovery:
                raise ValueError("Earlier Sheet result is uncertain; inspect its receipt before retrying.")
            if old[0] == "complete" and plan["before"] != previous["after"] and not recovery:
                raise ValueError("Managed Sheet cells were manually changed; reconcile before overwriting.")
    # Both plans are validated before either one is written.
    requests = [request for plan in plans for request in plan["requests"]]
    with db:
        for plan in plans:
            db.execute("INSERT OR REPLACE INTO personnel_sheet_state VALUES (?,'sending',?)",(plan["kind"],json.dumps(plan)))
    try:
        response = google.session.post(BASE+SPREADSHEET_ID+":batchUpdate",json={"requests":requests},timeout=30,allow_redirects=False)
        if response.status_code != 200:
            raise ValueError("Personnel Sheet write failed; inspect receipts before retrying.")
        for plan in plans:
            if plan["kind"] == "roster":
                values = read(google,"'Unit Roster'!A1:Q47")
                actual = {key:cell(values,*map(int,key.split(","))) for key in plan["after"]}
            else:
                actual = read(google,training_range(plan.get("tab_title",TRAINING_TITLE)))
            if actual != plan["after"]:
                if plan["kind"] == "roster":
                    changed = [key for key,value in plan["after"].items() if actual.get(key) != value]
                    raise ValueError(f"Unit Roster read-back differs at row,column {', '.join(changed[:5])}. Inspect receipts before retrying.")
                raise ValueError("Specialization tracker read-back differs. Inspect receipts before retrying.")
    except BaseException:
        with db:
            db.execute("UPDATE personnel_sheet_state SET state='uncertain' WHERE state='sending'")
        raise
    with db:
        for plan in plans:
            db.execute("UPDATE personnel_sheet_state SET state='complete' WHERE kind=?",(plan["kind"],))
    return "Unit Roster and specialization tracker verified. Attendance backend, legacy Specializations and radio frequencies untouched."
