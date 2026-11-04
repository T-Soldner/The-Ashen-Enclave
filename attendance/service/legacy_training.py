"""Read-only legacy Sheet parsing and explicitly previewed, records-only imports."""
import hashlib
import json
import re
from difflib import SequenceMatcher
from os.path import commonprefix
from urllib.parse import quote

import clan_training as policy
import personnel_sheets
from sheets_read_test import BASE, SPREADSHEET_ID, get_json

SOURCE_ID = 193478047
HEADERS = ["Name","Rising Phoenix","Medic","Marksman","AT/AA","Grenadier","CQC","Demolitions",
           "Communications","Heavy Weapons","Sniper","Lancer","SUAS","CSW","Rifleman"]
KEYS = ["phoenix","medic","marksman","at_aa","grenadier","cqc","demo","communications","heavy","sniper","lancer","suas","csw","rifleman"]
# User confirmed these four historical roster identities left on November 3, 2026.
# Preserve their source marks in the snapshot; never assign them to a new namesake.
CONFIRMED_DEPARTURES = {"bean","oracle","lanval","the_sam","jerry","wendigo","sora","postal",
                        "carolina","jester","shepard","wax","eliza"}
CONFIRMED_ALIASES = {"jimbo":"jimothy","bauer":"baur"}
CONFIRMED_MEMBERS = {"knight":"1352461545501757480"}


def normalized(name):
    return re.sub(r"^\[[^]]+\]\s*","",name).strip().casefold()


def canonical(name):
    name = normalized(name)
    return CONFIRMED_ALIASES.get(name,name)


def mark_kind(value):
    text = str(value.get("formattedValue","")).strip()
    if not text:
        return None
    if text.casefold() != "x" or "formulaValue" in value.get("userEnteredValue",{}):
        raise ValueError("Unexpected mark/formula; expected an X or an empty cell.")
    style = value.get("effectiveFormat",{}).get("textFormat",{})
    rgb = style.get("foregroundColorStyle",{}).get("rgbColor",style.get("foregroundColor"))
    if rgb is None:
        raise ValueError("X has no resolved font color; manual review required.")
    red,green,blue = (rgb.get(key,0) for key in ("red","green","blue"))
    if red >= .75 and green >= .75 and blue <= .35:
        return "primary"
    if red <= .4 and green >= .65 and blue <= .4:
        return "certified"
    raise ValueError("X is not recognizably yellow or green; manual review required.")


def parse(rows,start_row=22):
    if not rows or [cell.get("formattedValue","").strip() for cell in rows[0].get("values",[])][:15] != HEADERS:
        raise ValueError("Legacy Specializations headers changed. No marks imported.")
    result = []
    for offset,row in enumerate(rows[1:],start_row+2):
        values = row.get("values",[])
        name = str(values[0].get("formattedValue","")).strip() if values else ""
        if not name:
            continue
        entry = {"row":offset,"name":name,"certified":[],"primaries":[],"issues":[],"source":values[:15]}
        for column,key in enumerate(KEYS,1):
            try:
                kind = mark_kind(values[column] if column < len(values) else {})
                if kind:
                    entry["certified"].append(key)
                if kind == "primary":
                    entry["primaries"].append(key)
            except ValueError as error:
                entry["issues"].append(f"Column {column+1}: {error}")
        entry["points"] = sum(policy.SPECIALIZATIONS[key][1] for key in entry["primaries"])
        result.append(entry)
    return result


def fetch(google):
    metadata = get_json(google.session,BASE+SPREADSHEET_ID,{"fields":"sheets(properties(sheetId,title,gridProperties))"})
    tab = next((sheet["properties"] for sheet in metadata["sheets"] if sheet["properties"]["sheetId"] == SOURCE_ID),None)
    if not tab or not 24 <= tab["gridProperties"]["rowCount"] <= 1000:
        raise ValueError("Legacy specialization tab is missing or outside the bounded import limit.")
    title = "'"+tab["title"].replace("'","''")+"'"
    data = get_json(google.session,BASE+SPREADSHEET_ID,{
        "ranges":f"{title}!A23:O{tab['gridProperties']['rowCount']}","includeGridData":"true",
        "fields":"sheets(properties(sheetId),data(startRow,rowData(values(formattedValue,userEnteredValue,effectiveFormat(textFormat)))))"})
    sheet = next((sheet for sheet in data["sheets"] if sheet["properties"]["sheetId"] == SOURCE_ID),None)
    if not sheet or len(sheet.get("data",[])) != 1:
        raise ValueError("Legacy grid read incomplete; no import prepared.")
    block = sheet["data"][0]
    if block.get("startRow",0) != 22:
        raise ValueError("Unexpected legacy source start row.")
    return parse(block.get("rowData",[]))


def plan(db,guild,entries,members):
    active = {str(member["id"]):member for member in members if not member["bot"] and policy.HOUSE in member["roles"]}
    aliases = {identifier:{normalized(member["name"])} for identifier,member in active.items()}
    # Only previously explicit attendance bindings provide additional trusted aliases.
    for identifier,label in db.execute("SELECT m.discord_id,b.expected_name FROM members m JOIN sheet_bindings b ON b.steam_id=m.steam_id WHERE m.active=1"):
        if str(identifier) in aliases:
            aliases[str(identifier)].add(normalized(label))
    mappings = {row:(name,identifier) for row,name,identifier in db.execute("SELECT source_row,source_name,member FROM legacy_training_maps WHERE guild=?",(str(guild),))}
    output = []
    for entry in entries:
        item = dict(entry)
        item["source_hash"] = hashlib.sha256(json.dumps(entry,sort_keys=True).encode()).hexdigest()
        name = canonical(entry["name"])
        explicit = mappings.get(entry["row"])
        candidates = [identifier for identifier,names in aliases.items() if name in names]
        if name in CONFIRMED_MEMBERS:
            identifier = CONFIRMED_MEMBERS[name]
            candidates = [identifier] if identifier in active and (not explicit or explicit[1] == identifier) else []
        elif explicit:
            candidates = [explicit[1]] if canonical(explicit[0]) == name and explicit[1] in active else []
        item["member"] = candidates[0] if len(candidates) == 1 else None
        item["discord_name"] = active[candidates[0]]["name"] if len(candidates) == 1 else None
        if name in CONFIRMED_DEPARTURES:
            item["status"] = "confirmed-departure-preserved-in-source"
            item["member"] = None
            item["archive_action"] = "Preserve historical qualification evidence in the local archive on confirmation; no active training record."
        elif entry["issues"]:
            item["status"] = "blocked-mark-color"
        elif len(candidates) != 1:
            item["status"] = "needs-explicit-member-map"
        elif policy.training_record(db,guild,candidates[0]):
            item["status"] = "existing-record-not-overwritten"
        else:
            item["status"] = "ready-primary-review-needed" if entry["points"] > 9 else "ready"
        output.append(item)
    for item in output:
        if item["member"] and sum(other["member"] == item["member"] for other in output) > 1:
            item["status"] = "blocked-duplicate-member-rows"
    baur = [item for item in output if item["row"] in (40,68) and canonical(item["name"]) == "baur"]
    if len(baur) == 2 and baur[0]["member"] and baur[0]["member"] == baur[1]["member"] and not any(item["issues"] for item in baur):
        leader,duplicate = sorted(baur,key=lambda item:item["row"])
        evidence = json.loads(json.dumps(baur))
        combined = set().union(*(set(item["certified"]) for item in baur))
        if {"phoenix","medic"}.issubset(combined):
            leader["certified"] = sorted(combined)
            leader["primaries"] = ["phoenix","medic"]  # Explicit user confirmation, Nov 3.
            leader["points"] = 9
            leader["merged_sources"] = evidence
            leader["source_hash"] = personnel_sheets.digest(evidence)
            leader["status"] = "existing-record-not-overwritten" if policy.training_record(db,guild,leader["member"]) else "ready"
            duplicate["member"] = None
            duplicate["status"] = "merged-into-row-40"
    return {"kind":"legacy-import","rows":output,"roles_changed":False,"source_sheet_changed":False}


def suggestion_score(source,label):
    source,label = canonical(source),normalized(label)
    if not source or not label:
        return 0,""
    if source == label:
        return 100,"exact name or confirmed alias"
    tokens = re.findall(r"[\w']+",label)
    if source in tokens and len(source) >= 3:
        return 90,"distinctive whole name part"
    if len(source) >= 4 and (label.startswith(source) or label.endswith(source)):
        return 85,"name prefix/suffix; review"
    if len(label) >= 4 and len(source) >= 4 and (source.startswith(label) or source.endswith(label)):
        return 75,"expanded historical name; review"
    if len(source) >= 4:
        for token in tokens:
            if len(token) >= 4 and SequenceMatcher(None,source,token).ratio() >= .8:
                return 72,"similar spelling; review"
            if len(source) >= 5 and len(commonprefix([source,token])) >= 4:
                return 68,"distinctive shared prefix; review"
    return 0,""


def suggestions(db,guild,entries,members):
    current = plan(db,guild,entries,members)
    active = [member for member in members if not member["bot"] and policy.HOUSE in member["roles"]]
    existing_maps = {row[0] for row in db.execute("SELECT source_row FROM legacy_training_maps WHERE guild=?",(str(guild),))}
    proposed,unresolved = [],[]
    for entry in current["rows"]:
        if entry["status"] != "needs-explicit-member-map" or entry["row"] in existing_maps:
            continue
        ranked = []
        for member in active:
            score,basis = max((suggestion_score(entry["name"],label) for label in
                               (member["name"],member.get("username",""))),key=lambda result:result[0])
            if score:
                ranked.append({"member":str(member["id"]),"discord_name":member["name"],"score":score,"basis":basis})
        ranked.sort(key=lambda result:(-result["score"],result["member"]))
        row = {"row":entry["row"],"name":entry["name"]}
        if ranked and (len(ranked) == 1 or ranked[0]["score"]-ranked[1]["score"] >= 15):
            proposed.append({**row,**ranked[0]})
        else:
            unresolved.append({**row,"candidates":ranked[:5]})
    duplicated = {entry["member"] for entry in proposed if sum(other["member"] == entry["member"] for other in proposed) > 1}
    unresolved.extend({"row":entry["row"],"name":entry["name"],"reason":"Multiple source rows suggest the same member; review before mapping.","candidates":[entry]}
                      for entry in proposed if entry["member"] in duplicated)
    proposed = [entry for entry in proposed if entry["member"] not in duplicated]
    return {"kind":"legacy-bulk-map","proposed":proposed,"unresolved":unresolved,
            "source_digest":personnel_sheets.digest(entries),"qualifications_changed":False,"roles_changed":False}


def apply_suggestions(db,guild,actor,prepared):
    personnel_sheets.require_preview(db,guild,actor,[prepared])
    with db:
        db.execute("BEGIN IMMEDIATE")
        for entry in prepared["proposed"]:
            old = db.execute("SELECT source_name,member FROM legacy_training_maps WHERE guild=? AND source_row=?",(str(guild),entry["row"])).fetchone()
            if old:
                raise ValueError("A mapping changed after preview. No mappings overwritten; preview again.")
            db.execute("INSERT INTO legacy_training_maps VALUES (?,?,?,?)",(str(guild),entry["row"],entry["name"],entry["member"]))
            policy.audit(db,actor,entry["member"],"legacy-bulk-map",json.dumps(entry))
    return len(prepared["proposed"])


def bind(db,guild,entry,member):
    if normalized(entry["name"]) in CONFIRMED_DEPARTURES:
        raise ValueError("That historical identity is a confirmed departure; do not map it to a namesake.")
    if member["bot"] or policy.HOUSE not in member["roles"]:
        raise ValueError("Choose a current human House Karr member.")
    approved = CONFIRMED_MEMBERS.get(canonical(entry["name"]))
    if approved and str(member["id"]) != approved:
        raise ValueError("The user confirmed a different Discord identity for this historical name.")
    with db:
        old = db.execute("SELECT source_name,member FROM legacy_training_maps WHERE guild=? AND source_row=?",(str(guild),entry["row"])).fetchone()
        if old and (canonical(old[0]) != canonical(entry["name"]) or old[1] != str(member["id"])):
            raise ValueError("An explicit source mapping already exists; staff reconciliation is required.")
        db.execute("INSERT OR IGNORE INTO legacy_training_maps VALUES (?,?,?,?)",(str(guild),entry["row"],entry["name"],str(member["id"])))


def apply(db,guild,actor,prepared):
    personnel_sheets.require_preview(db,guild,actor,[prepared])
    eligible = [item for item in prepared["rows"] if item["status"] in ("ready","ready-primary-review-needed")]
    with db:
        db.execute("BEGIN IMMEDIATE")
        for entry in eligible:
            if policy.training_record(db,guild,entry["member"]):
                raise ValueError("A training record changed since preview; no records overwritten.")
            db.execute("INSERT INTO training_records VALUES (?,?,?,?,?,1,?,?)",(str(guild),entry["member"],entry["discord_name"],
                json.dumps(entry["certified"]),json.dumps(entry["primaries"]),str(actor),policy.now()))
            db.execute("INSERT INTO legacy_training_imports VALUES (?,?,?,?,'pending-review',?,?,?)",(str(guild),entry["member"],entry["row"],entry["source_hash"],str(actor),policy.now(),json.dumps(entry)))
            policy.audit(db,actor,entry["member"],"legacy-training-import",json.dumps({"source_row":entry["row"],"points":entry["points"],"roles_changed":False}))
        for entry in prepared["rows"]:
            if entry["status"] == "confirmed-departure-preserved-in-source":
                db.execute("INSERT OR IGNORE INTO legacy_training_archives VALUES (?,?,?,?,?,?)",
                    (str(guild),entry["row"],entry["name"],str(actor),policy.now(),json.dumps(entry)))
        snapshot_hash = personnel_sheets.digest([prepared])
        db.execute("INSERT OR IGNORE INTO legacy_training_snapshots VALUES (?,?,?,?)",(str(guild),snapshot_hash,policy.now(),json.dumps(prepared)))
    return len(eligible)
