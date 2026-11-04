import json
from pathlib import Path
import tempfile
import unittest

import clan_training as policy
from collector import connect
from discord_store import Store
import legacy_training as legacy
import personnel_sheets
from personnel_workflow import Workflow
from test_personnel import FakeRoles,GUILD,roster_values


def native(value,color=None):
    result = {"formattedValue":value,"userEnteredValue":{"stringValue":value}}
    if color is not None:
        result["effectiveFormat"] = {"textFormat":{"foregroundColor":color}}
    return result


def source(name="Alice",primary=("phoenix","marksman","communications"),certified=("medic",)):
    cells = [native(name)]
    for key in legacy.KEYS:
        cells.append(native("x",{"red":1,"green":1}) if key in primary else
                     native("X",{"green":1}) if key in certified else native("",{"red":1,"green":1}))
    return {"values":cells}


class ParsingTests(unittest.TestCase):
    def parse(self,*rows):
        return legacy.parse([{"values":[native(header) for header in legacy.HEADERS]},*rows])

    def test_yellow_primary_also_certified_green_only_certified(self):
        row = self.parse(source())[0]
        self.assertEqual(row["row"],24)
        self.assertEqual(row["points"],9)
        self.assertEqual(set(row["primaries"]),{"phoenix","marksman","communications"})
        self.assertEqual(set(row["certified"]),{"phoenix","marksman","communications","medic"})
        self.assertEqual(row["issues"],[])

    def test_blank_yellow_cells_do_not_add_qualifications(self):
        row = self.parse(source(primary=(),certified=()))[0]
        self.assertEqual(row["certified"],[])

    def test_overbudget_preserved_not_truncated(self):
        row = self.parse(source(primary=("phoenix","marksman","lancer")))[0]
        self.assertEqual(row["points"],15)
        self.assertIn("lancer",row["primaries"])

    def test_unknown_color_or_formula_blocks_row(self):
        row = source()
        row["values"][1] = native("x",{"red":1})
        self.assertTrue(self.parse(row)[0]["issues"])
        row["values"][1] = native("x",{"green":1})
        row["values"][1]["userEnteredValue"] = {"formulaValue":"=\"x\""}
        self.assertTrue(self.parse(row)[0]["issues"])

    def test_wrong_headers_refused(self):
        with self.assertRaises(ValueError):
            legacy.parse([{"values":[native("Wrong header")]}])


class ImportTests(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        self.addCleanup(self.root.cleanup)
        path = Path(self.root.name)/"test.db"
        connect(path).close()
        self.store = Store(path)
        self.db = connect(path)
        self.addCleanup(self.db.close)
        self.members = [dict(id="1",name="[MR] Alice",roles={policy.HOUSE},bot=False)]

    def entries(self,*rows):
        return legacy.parse([{"values":[native(header) for header in legacy.HEADERS]},*rows])

    def preview(self,entries):
        prepared = legacy.plan(self.db,GUILD,entries,self.members)
        personnel_sheets.remember_preview(self.db,GUILD,"admin",[prepared])
        return prepared

    def test_import_is_records_only_idempotent_and_retains_original_evidence(self):
        prepared = self.preview(self.entries(source()))
        self.assertEqual(legacy.apply(self.db,GUILD,"admin",prepared),1)
        record = policy.training_record(self.db,GUILD,"1")
        self.assertEqual(set(record["primaries"]),{"phoenix","marksman","communications"})
        self.assertEqual(self.db.execute("SELECT role_state FROM legacy_training_imports").fetchone()[0],"pending-review")
        self.assertEqual(self.db.execute("SELECT count(*) FROM legacy_training_snapshots").fetchone()[0],1)
        new_plan = self.preview(self.entries(source()))
        self.assertEqual(new_plan["rows"][0]["status"],"existing-record-not-overwritten")
        self.assertEqual(legacy.apply(self.db,GUILD,"admin",new_plan),0)

    def test_ambiguous_renamed_member_requires_mapping(self):
        self.members[0]["name"] = "[MV] Newname"
        entries = self.entries(source("Oldname"))
        prepared = self.preview(entries)
        self.assertEqual(prepared["rows"][0]["status"],"needs-explicit-member-map")
        legacy.bind(self.db,GUILD,entries[0],self.members[0])
        self.assertEqual(self.preview(entries)["rows"][0]["status"],"ready")

    def test_user_confirmed_jimbo_alias_is_exact(self):
        self.members[0]["name"] = "[MV] Jimothy"
        prepared = self.preview(self.entries(source("Jimbo")))
        self.assertEqual(prepared["rows"][0]["status"],"ready")

    def test_bulk_suggestions_require_one_confirmation_and_change_no_qualifications(self):
        self.members[0]["name"] = "[MR] Alice Fullname"
        entries = self.entries(source())
        prepared = legacy.suggestions(self.db,GUILD,entries,self.members)
        self.assertEqual(len(prepared["proposed"]),1)
        with self.assertRaises(ValueError):
            legacy.apply_suggestions(self.db,GUILD,"admin",prepared)
        personnel_sheets.remember_preview(self.db,GUILD,"admin",[prepared])
        self.assertEqual(legacy.apply_suggestions(self.db,GUILD,"admin",prepared),1)
        self.assertEqual(self.db.execute("SELECT count(*) FROM training_records").fetchone()[0],0)
        self.assertEqual(legacy.plan(self.db,GUILD,entries,self.members)["rows"][0]["status"],"ready")

    def test_tied_bulk_suggestions_are_not_auto_selected(self):
        self.members[0]["name"] = "[MR] Alice One"
        self.members.append(dict(id="2",name="[MR] Alice Two",roles={policy.HOUSE},bot=False))
        prepared = legacy.suggestions(self.db,GUILD,self.entries(source()),self.members)
        self.assertEqual(prepared["proposed"],[])
        self.assertEqual(len(prepared["unresolved"]),1)

    def test_bulk_username_and_changed_name_suggestions(self):
        for old,new in [("STORY","Storyburgh"),("LOKI","ScottishLoki"),("ROUGE","Rogue"),("GOOSE","Goostivool Rook")]:
            self.members[0]["name"] = "[MR] "+new
            prepared = legacy.suggestions(self.db,GUILD,self.entries(source(old)),self.members)
            self.assertEqual(len(prepared["proposed"]),1,old)

    def test_confirmed_baur_duplicates_merge_certifications_with_approved_primaries(self):
        self.members[0]["name"] = "[MR] Baur"
        entries = self.entries(source("BAUER",primary=("phoenix","heavy"),certified=("medic",)),
                               source("BAUR",primary=("phoenix","medic"),certified=("lancer",)))
        entries[0]["row"],entries[1]["row"] = 40,68
        prepared = self.preview(entries)
        first,second = prepared["rows"]
        self.assertEqual(first["status"],"ready")
        self.assertEqual(set(first["primaries"]),{"phoenix","medic"})
        self.assertIn("heavy",first["certified"])
        self.assertIn("lancer",first["certified"])
        self.assertEqual(second["status"],"merged-into-row-40")
        self.assertEqual(legacy.apply(self.db,GUILD,"admin",prepared),1)

    def test_verified_attendance_binding_is_an_exact_trusted_alias(self):
        self.members[0]["name"] = "[MR] Alice Fullname"
        with self.db:
            self.db.execute("INSERT INTO members(steam_id,discord_id,display_name) VALUES ('steam','1','Alice Fullname')")
            self.db.execute("INSERT INTO sheet_bindings VALUES ('steam',2,'[MR] ALICE',5)")
        self.assertEqual(self.preview(self.entries(source()))["rows"][0]["member"],"1")

    def test_confirmed_departures_not_assigned_to_namesakes(self):
        for name in ("BEAN","ORACLE","LANVAL","THE_SAM"):
            self.members[0]["name"] = name
            entries = self.entries(source(name))
            prepared = self.preview(entries)
            self.assertIn("departure",prepared["rows"][0]["status"])
            self.assertIsNone(prepared["rows"][0]["member"])
            with self.assertRaises(ValueError):
                legacy.bind(self.db,GUILD,entries[0],self.members[0])

    def test_knight_uses_user_confirmed_identity_not_goldie(self):
        knight = dict(id="1352461545501757480",name="[MR] Knight Rook",roles={policy.HOUSE},bot=False)
        goldie = dict(id="181202559749324800",name="[MR] Goldie",roles={policy.HOUSE},bot=False)
        self.members = [knight,goldie]
        entries = self.entries(source("KNIGHT"))
        prepared = self.preview(entries)
        self.assertEqual(prepared["rows"][0]["member"],knight["id"])
        self.assertEqual(prepared["rows"][0]["status"],"ready")
        with self.assertRaises(ValueError):
            legacy.bind(self.db,GUILD,entries[0],goldie)

    def test_nine_new_departures_are_archived_once_without_active_records(self):
        names = ["JERRY","WENDIGO","SORA","POSTAL","CAROLINA","JESTER","SHEPARD","WAX","ELIZA"]
        entries = self.entries(*(source(name) for name in names))
        prepared = self.preview(entries)
        self.assertEqual(legacy.apply(self.db,GUILD,"admin",prepared),0)
        self.assertEqual(self.db.execute("SELECT count(*) FROM legacy_training_archives").fetchone()[0],9)
        legacy.apply(self.db,GUILD,"admin",prepared)
        self.assertEqual(self.db.execute("SELECT count(*) FROM legacy_training_archives").fetchone()[0],9)
        self.assertEqual(self.db.execute("SELECT count(*) FROM training_records").fetchone()[0],0)
        evidence = json.loads(self.db.execute("SELECT payload FROM legacy_training_archives LIMIT 1").fetchone()[0])
        self.assertIn("certified",evidence)
        self.assertIn("source",evidence)

    def test_duplicate_rows_never_overwrite_one_member(self):
        prepared = self.preview(self.entries(source(),source()))
        self.assertTrue(all(row["status"] == "blocked-duplicate-member-rows" for row in prepared["rows"]))
        self.assertEqual(legacy.apply(self.db,GUILD,"admin",prepared),0)

    def test_overbudget_historical_record_preserved_for_review(self):
        prepared = self.preview(self.entries(source(primary=("phoenix","marksman","lancer"))))
        self.assertEqual(prepared["rows"][0]["status"],"ready-primary-review-needed")
        legacy.apply(self.db,GUILD,"admin",prepared)
        record = policy.training_record(self.db,GUILD,"1")
        self.assertEqual(sum(policy.SPECIALIZATIONS[key][1] for key in record["primaries"]),15)

    def test_import_cannot_confirm_someone_elses_preview(self):
        prepared = self.preview(self.entries(source()))
        with self.assertRaises(ValueError):
            legacy.apply(self.db,GUILD,"otheradmin",prepared)

    def test_roster_missing_house_role_is_not_a_departure(self):
        values = roster_values()
        values[11][1] = "[MR] Alice"
        with self.assertRaisesRegex(ValueError,"still in Discord"):
            personnel_sheets.roster_cells([dict(id="1",name="[MR] Alice",roles=set(),bot=False)],values)


class ReconciliationTests(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        self.addCleanup(self.root.cleanup)
        path = Path(self.root.name)/"test.db"
        connect(path).close()
        self.store = Store(path)
        self.roles = FakeRoles()
        self.workflow = Workflow(self.store,self.roles,GUILD,True)
        def seed(db):
            with db:
                db.execute("INSERT INTO training_records VALUES (?,?,?,?,?,1,?,?)",(GUILD,"1","Applicant",json.dumps(["phoenix","marksman","communications","medic"]),json.dumps(["phoenix","marksman","communications"]),"admin",policy.now()))
                db.execute("INSERT INTO legacy_training_imports VALUES (?,?,24,'hash','pending-review','admin',?,'{}')",(GUILD,"1",policy.now()))
        self.store.run(seed)

    async def test_explicit_save_reconciles_roles_and_marks_import_reviewed(self):
        self.roles.people["1"]["roles"].add(policy.SPECIALIZATIONS["medic"][2])
        await self.workflow.save_training("admin","1",{"phoenix","marksman","communications","medic"},{"phoenix","marksman","communications"},1)
        self.assertNotIn(policy.SPECIALIZATIONS["medic"][2],self.roles.people["1"]["roles"])
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT role_state FROM legacy_training_imports").fetchone()[0]),"reconciled")

    async def test_reconciliation_cannot_remove_pilot_role_without_permission(self):
        self.roles.admin = False
        self.roles.actor_roles = {policy.SECOND}
        self.roles.people["1"]["roles"].add(policy.SPECIALIZATIONS["dropship"][2])
        with self.assertRaisesRegex(ValueError,"pilot"):
            await self.workflow.save_training("second","1",{"medic"},{"medic"},1)
