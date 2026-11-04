import asyncio
import ast
import datetime as dt
import json
from pathlib import Path
import sqlite3
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch
from attendance import UTC

import clan_training as policy
from collector import connect
from discord_store import Store
from personnel_workflow import Workflow
import personnel_sheets as sheets
from personnel_ui import check_error

GUILD = "1477486339984199932"


class PolicyTests(unittest.TestCase):
    def test_training_notice_omits_redundant_timestamp(self):
        tree = ast.parse(Path(__file__).with_name("personnel_ui.py").read_text(encoding="utf-8-sig"))
        notice = next(node for node in ast.walk(tree)
                      if isinstance(node, ast.AsyncFunctionDef) and node.name == "training_notice")
        send = next(node for node in ast.walk(notice)
                    if isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute)
                    and node.func.attr == "send")
        text = "".join(node.value for node in ast.walk(send.args[0])
                       if isinstance(node, ast.Constant) and isinstance(node.value, str))
        self.assertNotIn("UTC:", text)
        self.assertIn("Record:", text)

    def test_read_only_check_error_names_stage_and_http_details(self):
        error = Exception("Do not expose arbitrary remote payloads")
        error.status,error.code = 403,50001
        text = check_error("checking Acklay barracks",error)
        self.assertIn("Acklay barracks",text)
        self.assertIn("403",text)
        self.assertIn("50001",text)
        self.assertNotIn("remote payloads",text)
        self.assertIn("No roles",text)

    def test_read_only_runtime_error_is_actionable(self):
        text = check_error("fetching roster",RuntimeError("Intents.members must be enabled"))
        self.assertIn("Intents.members",text)

    def test_exact_roles_channels_and_caps(self):
        self.assertEqual([(x["role"],x["channel"],x["limit"]) for x in policy.CLANS.values()],
            [(1477486340080799945,1549895011401728030,8),(1477486340080799943,1477486341469241555,8),(1510404359228362934,1510405139746525184,4)])

    def test_own_clan_leaders_only(self):
        for clan,config in policy.CLANS.items():
            self.assertTrue(policy.clan_reviewer(False,{policy.LEADER,config["role"]},clan))
            self.assertFalse(policy.clan_reviewer(False,{config["role"]},clan))
            self.assertFalse(policy.clan_reviewer(False,{policy.LEADER},clan))
            self.assertTrue(policy.clan_reviewer(True,set(),clan))

    def test_all_trainer_roles_but_not_recruiter(self):
        for role in (policy.LEADER,policy.SECOND,policy.ADVISOR):
            self.assertTrue(policy.trainer_allowed(False,{role}))
        self.assertFalse(policy.trainer_allowed(False,{1477486340101902517}))

    def test_nine_points_inclusive_and_unlimited_certifications(self):
        certs = set(policy.SPECIALIZATIONS)-policy.PILOTS
        self.assertEqual(policy.validate_training(certs,{"phoenix","marksman","communications"}),9)
        self.assertEqual(policy.validate_training(certs,{"rifleman"}),0)
        with self.assertRaises(ValueError):
            policy.validate_training(certs,{"medic","sniper"})

    def test_primaries_require_certification(self):
        with self.assertRaises(ValueError):
            policy.validate_training(set(),{"medic"})

    def test_pilot_certification_and_primary_restrictions(self):
        self.assertTrue(policy.pilot_allowed(False,{policy.LEADER,policy.CLANS["shyyyo"]["role"]}))
        self.assertFalse(policy.pilot_allowed(False,{policy.SECOND,policy.CLANS["shyyyo"]["role"]}))
        for pilot in policy.PILOTS:
            self.assertEqual(policy.validate_training({pilot},{pilot},allow_pilot=True),9)
            with self.assertRaises(ValueError):
                policy.validate_training({pilot},set())
            with self.assertRaises(ValueError):
                policy.validate_training({pilot,"medic"},{pilot,"medic"},allow_pilot=True)
        # An ordinary trainer may edit other qualifications without changing pilot status.
        self.assertEqual(policy.validate_training({"dropship","medic"},{"dropship"},{"dropship"},{"dropship"}),9)

    def test_command_limits_and_descriptions_remain_valid(self):
        counts = {}
        root = Path(__file__).parent
        for name in ("discord_bot.py","application_ui.py","personnel_ui.py"):
            for node in ast.walk(ast.parse((root/name).read_text())):
                if isinstance(node,ast.Call) and isinstance(node.func,ast.Attribute) and node.func.attr == "command":
                    key = ast.unparse(node.func.value)
                    counts[key] = counts.get(key,0)+1
                    for keyword in node.keywords:
                        if keyword.arg == "description" and isinstance(keyword.value,ast.Constant):
                            self.assertLessEqual(len(keyword.value.value),100)
        self.assertLessEqual(counts["staff"],25)
        self.assertLessEqual(counts["public"]+1,25)  # includes training subgroup

    def test_new_database_tables_do_not_modify_existing_attendance(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        db.execute("CREATE TABLE members(name TEXT,total INTEGER)")
        db.execute("INSERT INTO members VALUES ('Edonn',39)")
        policy.initialize(db)
        policy.initialize(db)
        self.assertEqual(db.execute("SELECT * FROM members").fetchall(),[("Edonn",39)])


class FakeRoles:
    def __init__(self):
        self.people = {"1":{"id":"1","name":"Applicant","roles":{policy.HOUSE,policy.FREELANCER,999},"bot":False}}
        self.admin = True
        self.actor_roles = set()
        self.calls = 0
        self.fail = False
        self.fail_after = False

    async def actor(self,actor):
        return self.admin,self.actor_roles

    async def member(self,member):
        return self.people[str(member)]

    async def roster(self):
        await asyncio.sleep(0)
        return list(self.people.values())

    async def preflight(self,*args):
        pass

    async def apply(self,member,desired):
        self.calls += 1
        if self.fail:
            raise ValueError("API unavailable")
        self.people[str(member)]["roles"].difference_update(desired["remove"])
        self.people[str(member)]["roles"].update(desired["add"])
        if self.fail_after:
            raise ValueError("Response lost after role update")


class WorkflowTests(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        self.addCleanup(self.root.cleanup)
        path = Path(self.root.name)/"test.db"
        connect(path).close()
        self.store = Store(path)
        self.roles = FakeRoles()
        self.workflow = Workflow(self.store,self.roles,GUILD,True)

    def request(self,identifier="app",member="1",clan="acklay"):
        return self.store.run(lambda db: policy.submit_clan(db,identifier,GUILD,member,clan,"Why I want to join"))

    def state(self,identifier="app"):
        return self.store.run(lambda db: policy.clan_request(db,identifier,GUILD))["status"]

    async def test_admin_transfer_to_freelancers_clears_leadership_not_other_roles(self):
        self.roles.people["1"]["roles"].update({policy.CLANS["rook"]["role"],policy.LEADER,policy.SECOND,
                                              policy.SPECIALIZATIONS["medic"][2]})
        await self.workflow.transfer("admin","1","freelancers","Taking a break from clan duties")
        actual = self.roles.people["1"]["roles"]
        self.assertEqual(actual,{policy.HOUSE,policy.FREELANCER,999,policy.SPECIALIZATIONS["medic"][2]})
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT state FROM clan_transfers").fetchone())[0],"complete")
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT action FROM clan_training_audit").fetchone())[0],"admin-clan-transfer")

    async def test_transfer_requires_admin_reason_and_feature_flag(self):
        self.roles.admin = False
        self.roles.actor_roles = {policy.LEADER}
        with self.assertRaises(ValueError):
            await self.workflow.transfer("leader","1","rook","Transfer requested")
        self.roles.admin = True
        with self.assertRaises(ValueError):
            await self.workflow.transfer("admin","1","rook"," ")
        self.workflow.enabled = False
        with self.assertRaises(ValueError):
            await self.workflow.transfer("admin","1","rook","Transfer requested")
        self.assertEqual(self.roles.calls,0)

    async def test_full_destination_blocks_transfer(self):
        for i in range(8):
            self.roles.people[str(i+10)] = dict(id=str(i+10),name="Existing",roles={policy.CLANS["rook"]["role"]},bot=False)
        with self.assertRaises(ValueError):
            await self.workflow.transfer("admin","1","rook","Transfer requested")
        self.assertEqual(self.roles.calls,0)

    async def test_transfer_response_loss_is_verified_not_repeated(self):
        self.roles.fail_after = True
        with self.assertRaises(ValueError):
            await self.workflow.transfer("admin","1","rook","Transfer requested")
        await self.workflow.transfer("admin","1","rook","Transfer requested")
        self.assertEqual(self.roles.calls,1)

    async def test_failed_transfer_reserves_space_for_clan_applications(self):
        for i in range(7):
            self.roles.people[str(i+10)] = dict(id=str(i+10),name="Existing",roles={policy.CLANS["rook"]["role"]},bot=False)
        self.roles.fail = True
        with self.assertRaises(ValueError):
            await self.workflow.transfer("admin","1","rook","Transfer requested")
        self.roles.fail = False
        self.roles.people["2"] = dict(id="2",name="Other",roles={policy.HOUSE,policy.FREELANCER},bot=False)
        self.request("other","2","rook")
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","other")
        self.assertEqual(self.roles.calls,1)

    async def test_same_clan_does_not_strip_leadership(self):
        self.roles.people["1"]["roles"] = {policy.HOUSE,policy.CLANS["rook"]["role"],policy.LEADER,999}
        await self.workflow.transfer("admin","1","rook","No move needed")
        self.assertIn(policy.LEADER,self.roles.people["1"]["roles"])
        self.assertEqual(self.roles.calls,0)

    async def test_verified_transfer_closes_old_pending_application(self):
        self.request()
        await self.workflow.transfer("admin","1","rook","Assigned to Rook")
        self.assertEqual(self.state(),"denied")
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")

    async def test_clan_accept_replaces_other_groups_not_unrelated_roles(self):
        self.roles.people["1"]["roles"].add(policy.CLANS["rook"]["role"])
        self.request()
        await self.workflow.approve("admin","app")
        actual = self.roles.people["1"]["roles"]
        self.assertEqual(actual,{policy.HOUSE,policy.CLANS["acklay"]["role"],999})
        self.assertEqual(self.state(),"approved")
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        self.assertEqual(self.roles.calls,1)

    async def test_full_clan_and_cross_clan_reviewer_rejected(self):
        self.request()
        for i in range(8):
            self.roles.people[str(i+10)] = dict(id=str(i+10),name="Existing",roles={policy.CLANS["acklay"]["role"]},bot=False)
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        self.roles.admin = False
        self.roles.actor_roles = {policy.LEADER,policy.CLANS["rook"]["role"]}
        with self.assertRaises(ValueError):
            await self.workflow.approve("leader","app")
        self.assertEqual(self.roles.calls,0)

    async def test_concurrent_acceptances_cannot_take_same_last_slot(self):
        self.roles.people["2"] = dict(id="2",name="Other",roles={policy.HOUSE,policy.FREELANCER},bot=False)
        self.request("a","1")
        self.request("b","2")
        for i in range(7):
            self.roles.people[str(i+10)] = dict(id=str(i+10),name="Existing",roles={policy.CLANS["acklay"]["role"]},bot=False)
        results = await asyncio.gather(self.workflow.approve("admin","a"),self.workflow.approve("admin","b"),return_exceptions=True)
        self.assertEqual(sum(isinstance(result,ValueError) for result in results),1)
        self.assertEqual(sum(policy.CLANS["acklay"]["role"] in person["roles"] for person in self.roles.people.values()),8)

    async def test_shyyyo_limit_four_including_leader(self):
        self.request(clan="shyyyo")
        for i in range(4):
            self.roles.people[str(i+10)] = dict(id=str(i+10),name="Existing",roles={policy.CLANS["shyyyo"]["role"],policy.LEADER},bot=False)
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")

    async def test_uncertain_application_reserves_the_last_slot(self):
        self.roles.people["2"] = dict(id="2",name="Other",roles={policy.HOUSE,policy.FREELANCER},bot=False)
        for i in range(7):
            self.roles.people[str(i+10)] = dict(id=str(i+10),name="Existing",roles={policy.CLANS["acklay"]["role"]},bot=False)
        self.request("a","1")
        self.request("b","2")
        self.roles.fail = True
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","a")
        self.roles.fail = False
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","b")
        self.assertEqual(self.roles.calls,1)

    async def test_clan_transfer_cannot_carry_leadership_authority(self):
        self.roles.people["1"]["roles"].update({policy.LEADER,policy.CLANS["rook"]["role"]})
        self.request()
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        self.assertEqual(self.roles.calls,0)

    async def test_uncertain_clan_never_blindly_retried_or_denied(self):
        self.request()
        self.roles.fail = True
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        self.roles.fail = False
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        with self.assertRaises(ValueError):
            await self.workflow.deny("admin","app","No")
        self.assertEqual(self.roles.calls,1)
        self.assertEqual(self.state(),"uncertain")

    async def test_response_loss_recovery_verifies_without_repeating(self):
        self.request()
        self.roles.fail_after = True
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        await self.workflow.approve("admin","app")
        self.assertEqual(self.state(),"approved")
        self.assertEqual(self.roles.calls,1)

    async def test_denial_requires_reason_no_role_changes(self):
        self.request()
        with self.assertRaises(ValueError):
            await self.workflow.deny("admin","app","")
        await self.workflow.deny("admin","app","Not yet")
        self.assertEqual(self.state(),"denied")
        self.assertEqual(self.roles.calls,0)

    async def test_disabled_never_changes_roles(self):
        self.workflow.enabled = False
        self.request()
        with self.assertRaises(ValueError):
            await self.workflow.approve("admin","app")
        with self.assertRaises(ValueError):
            await self.workflow.save_training("admin","1",{"medic"},{"medic"},0)
        self.assertEqual(self.roles.calls,0)

    async def test_training_only_grants_primary_roles_not_certifications(self):
        certs = {"phoenix","marksman","communications","medic","demo"}
        primary = {"phoenix","marksman","communications"}
        await self.workflow.save_training("admin","1",certs,primary,0)
        held = self.roles.people["1"]["roles"]
        self.assertIn(policy.SPECIALIZATIONS["phoenix"][2],held)
        self.assertNotIn(policy.SPECIALIZATIONS["medic"][2],held)
        self.assertIn(999,held)
        record = self.store.run(lambda db: policy.training_record(db,GUILD,"1"))
        self.assertEqual(set(record["certified"]),certs)
        self.assertEqual(record["revision"],1)

    async def test_stale_training_editor_and_manual_role_drift(self):
        await self.workflow.save_training("admin","1",{"medic"},{"medic"},0)
        with self.assertRaises(ValueError):
            await self.workflow.save_training("admin","1",{"demo"},{"demo"},0)
        self.roles.people["1"]["roles"].add(policy.SPECIALIZATIONS["marksman"][2])
        with self.assertRaises(ValueError):
            await self.workflow.save_training("admin","1",{"demo"},{"demo"},1)

    async def test_training_recovery_after_lost_response(self):
        self.roles.fail_after = True
        with self.assertRaises(ValueError):
            await self.workflow.save_training("admin","1",{"medic"},{"medic"},0)
        await self.workflow.save_training("admin","1",{"medic"},{"medic"},0)
        self.assertEqual(self.roles.calls,1)

    async def test_second_can_update_other_clan_but_not_pilots(self):
        self.roles.admin = False
        self.roles.actor_roles = {policy.SECOND,policy.CLANS["rook"]["role"]}
        self.roles.people["1"]["roles"].add(policy.CLANS["acklay"]["role"])
        await self.workflow.save_training("second","1",{"medic"},{"medic"},0)
        with self.assertRaises(ValueError):
            await self.workflow.save_training("second","1",{"medic","dropship"},{"dropship"},1)


def roster_values():
    rows = [[""]*17 for _ in range(47)]
    for row,col,value in [(10,2,"Clan Acklay"),(10,5,"Clan Rook"),(34,2,"Flight Lead"),(36,2,"Shyyyo Flight"),
                          (2,14,"Freelancers"),(7,7,"[WC] Hondo"),(9,7,"[RM] Edonn"),(38,8,"RADIO DO NOT TOUCH")]:
        rows[row-1][col-1] = value
    return rows


class SheetTests(unittest.TestCase):
    def test_renamed_tracker_uses_its_fixed_id_and_current_title(self):
        for title in ("Specialization Tracker","Training Tracker","Unit's Qualifications"):
            metadata = {"sheets":[
                {"properties":{"sheetId":sheets.ROSTER_ID,"title":"Unit Roster","gridProperties":{"rowCount":47,"columnCount":17}}},
                {"properties":{"sheetId":sheets.TRAINING_ID,"title":title,"gridProperties":{"rowCount":1000,"columnCount":21}}}]}
            with patch.object(sheets,"get_json",return_value=metadata),patch.object(sheets,"roster_plan",return_value={"after":{}}),patch.object(sheets,"training_plan",return_value={"kind":"training"}) as build:
                sheets.prepare(None,SimpleNamespace(session=None),GUILD,[])
                self.assertEqual(build.call_args.args[-1],title)

    def test_training_range_quotes_apostrophes(self):
        self.assertEqual(sheets.training_range("Unit's Qualifications"),"'Unit''s Qualifications'!A1:U1000")

    def test_same_title_wrong_id_is_not_adopted(self):
        metadata = {"sheets":[
            {"properties":{"sheetId":sheets.ROSTER_ID,"title":"Unit Roster","gridProperties":{"rowCount":47,"columnCount":17}}},
            {"properties":{"sheetId":999,"title":sheets.TRAINING_TITLE}}]}
        with patch.object(sheets,"get_json",return_value=metadata):
            with self.assertRaisesRegex(ValueError,"unexpected ID"):
                sheets.prepare(None,SimpleNamespace(session=None),GUILD,[])

    def test_shyyyo_members_do_not_target_two_row_heading(self):
        members = [dict(id="lead",name="Teka",roles={policy.HOUSE,policy.CLANS["shyyyo"]["role"],policy.LEADER},bot=False),
                   dict(id="jet",name="Jet",roles={policy.HOUSE,policy.CLANS["shyyyo"]["role"]},bot=False),
                   dict(id="loki",name="Loki",roles={policy.HOUSE,policy.CLANS["shyyyo"]["role"]},bot=False)]
        desired = sheets.roster_cells(members,roster_values())
        self.assertNotIn((37,2),desired)
        self.assertEqual(desired[(35,2)],"Teka")
        self.assertEqual(desired[(38,2)],"Jet")
        self.assertEqual(desired[(39,2)],"Loki")

    def test_header_recovery_requires_exact_old_receipt_and_merged_header(self):
        previous = {"after":{"37,2":"Jet","38,2":"Loki","39,2":""}}
        plan = {"kind":"roster","before":{"38,2":"Loki","39,2":""},"after":{"38,2":"Jet","39,2":"Loki"},
                "legacy_header_cell":"","legacy_header_merged":True}
        self.assertTrue(sheets.legacy_header_recovery(plan,previous))
        self.assertFalse(sheets.legacy_header_recovery({**plan,"legacy_header_merged":False},previous))
        self.assertFalse(sheets.legacy_header_recovery({**plan,"legacy_header_cell":"Unexpected"},previous))
        self.assertFalse(sheets.legacy_header_recovery({**plan,"before":{"38,2":"Manual edit","39,2":""}},previous))

    def test_confirmed_header_recovery_writes_and_verifies_without_clearing_receipts(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        previous = {"after":{"37,2":"Jet","38,2":"Loki","39,2":""}}
        db.execute("INSERT INTO personnel_sheet_state VALUES ('roster','uncertain',?)",(json.dumps(previous),))
        db.commit()
        plan = {"kind":"roster","before":{"38,2":"Loki","39,2":""},"after":{"38,2":"Jet","39,2":"Loki"},
                "legacy_header_cell":"","legacy_header_merged":True,"requests":[]}
        calls = []
        google = SimpleNamespace(writable=True,session=SimpleNamespace(post=lambda *a,**k: calls.append(k) or SimpleNamespace(status_code=200)))
        with self.assertRaises(ValueError):
            sheets.apply(db,google,[plan])
        self.assertEqual(calls,[])
        actual = roster_values()
        actual[37][1],actual[38][1] = "Jet","Loki"
        with patch.object(sheets,"read",return_value=actual):
            sheets.apply(db,google,[plan],initialize=True)
        self.assertEqual(db.execute("SELECT state FROM personnel_sheet_state").fetchone()[0],"complete")

    def test_merged_non_anchor_targets_fail_before_writing(self):
        metadata = {"sheets":[{"properties":{"sheetId":sheets.ROSTER_ID,"title":"Unit Roster","gridProperties":{"rowCount":47,"columnCount":17}},
            "merges":[{"startRowIndex":35,"endRowIndex":37,"startColumnIndex":1,"endColumnIndex":4}]}]}
        bad_plan = {"kind":"roster","before":{},"after":{"37,2":"Jet"}}
        with patch.object(sheets,"get_json",return_value=metadata),patch.object(sheets,"roster_plan",return_value=bad_plan):
            with self.assertRaisesRegex(ValueError,"merged"):
                sheets.prepare(None,SimpleNamespace(session=None),GUILD,[])

    def test_preview_required_for_same_actor_unchanged_and_recent(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        plans = [{"before":[],"after":["new"],"requests":[]}]
        sheets.remember_preview(db,GUILD,"trainer",plans)
        sheets.require_preview(db,GUILD,"trainer",plans)
        with self.assertRaises(ValueError):
            sheets.require_preview(db,GUILD,"someone else",plans)
        with self.assertRaises(ValueError):
            sheets.require_preview(db,GUILD,"trainer",[{"after":["changed"]}])
        db.execute("UPDATE personnel_sheet_previews SET utc=?",((dt.datetime.now(UTC)-dt.timedelta(minutes=16)).isoformat(),))
        db.commit()
        with self.assertRaises(ValueError):
            sheets.require_preview(db,GUILD,"trainer",plans)

    def test_atomic_sheet_batch_and_verified_receipts(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        calls = []
        def post(*args,**kwargs):
            calls.append(kwargs["json"])
            return SimpleNamespace(status_code=200)
        google = SimpleNamespace(writable=True,session=SimpleNamespace(post=post))
        values = roster_values()
        plans = [{"kind":"roster","before":{"7,7":"old"},"after":{"7,7":"[WC] Hondo"},"requests":[{"test":"roster"}]},
                 {"kind":"training","before":[],"after":[sheets.HEADERS],"requests":[{"test":"training"}]}]
        with patch.object(sheets,"read",side_effect=[values,[sheets.HEADERS]]):
            sheets.apply(db,google,plans,initialize=True)
        self.assertEqual(len(calls),1)
        self.assertEqual(len(calls[0]["requests"]),2)
        self.assertEqual(db.execute("SELECT DISTINCT state FROM personnel_sheet_state").fetchall(),[("complete",)])

    def test_failed_sheet_write_is_durable_and_not_blindly_retried(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        google = SimpleNamespace(writable=True,session=SimpleNamespace(post=lambda *a,**k: SimpleNamespace(status_code=503)))
        plan = {"kind":"roster","before":{"7,7":"old"},"after":{"7,7":"new"},"requests":[]}
        with self.assertRaises(ValueError):
            sheets.apply(db,google,[plan],initialize=True)
        self.assertEqual(db.execute("SELECT state FROM personnel_sheet_state").fetchone()[0],"uncertain")
        with self.assertRaises(ValueError):
            sheets.apply(db,google,[plan],initialize=True)

    def test_only_allowed_roster_cells_managed_and_leadership_preserved(self):
        values = roster_values()
        members = [dict(id="1",name="Acklay Leader",roles={policy.HOUSE,policy.CLANS["acklay"]["role"],policy.LEADER},bot=False),
                   dict(id="2",name="Rook",roles={policy.HOUSE,policy.CLANS["rook"]["role"]},bot=False),
                   dict(id="3",name="Freelancer",roles={policy.HOUSE,policy.FREELANCER},bot=False)]
        desired = sheets.roster_cells(members,values)
        self.assertEqual(desired[(12,2)],"Acklay Leader")
        self.assertEqual(desired[(12,5)],"Rook")
        self.assertEqual(desired[(4,14)],"Freelancer")
        self.assertEqual(desired[(7,7)],"[WC] Hondo")
        self.assertNotIn((38,8),desired)
        self.assertNotIn((36,2),desired)

    def test_clan_leader_then_second_then_alphabetical_members(self):
        for clan, column in (("acklay", 2), ("rook", 5), ("shyyyo", 2)):
            with self.subTest(clan=clan):
                members = [
                    dict(id=str(index), name=name,
                         roles={policy.HOUSE, policy.CLANS[clan]["role"]} | extra, bot=False)
                    for index, (name, extra) in enumerate([
                        ("Alpha Member", set()), ("Zulu Second", {policy.SECOND}),
                        ("Zulu Leader", {policy.LEADER}), ("Beta Member", set()),
                    ])
                ]
                desired = sheets.roster_cells(members, roster_values())
                rows = (35, 38, 39, 40) if clan == "shyyyo" else (12, 13, 14, 15)
                self.assertEqual([desired[(row, column)] for row in rows],
                                 ["Zulu Leader", "Zulu Second", "Alpha Member", "Beta Member"])

    def test_wrong_layout_capacity_and_multi_clan_refused(self):
        values = roster_values()
        values[9][1] = "Renamed"
        with self.assertRaises(ValueError):
            sheets.roster_cells([],values)
        members = [dict(id=str(i),name="X",roles={policy.HOUSE,policy.CLANS["rook"]["role"]},bot=False) for i in range(9)]
        with self.assertRaises(ValueError):
            sheets.roster_cells(members,roster_values())
        with self.assertRaises(ValueError):
            sheets.roster_cells([dict(id="1",name="X",roles={policy.HOUSE,*policy.CLAN_ROLES},bot=False)],roster_values())

    def test_unadopted_and_manually_changed_sheets_block_writes(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        google = SimpleNamespace(writable=True,session=None)
        plan = {"kind":"roster","before":{"cell":"old"},"after":{"cell":"new"},"requests":[]}
        with self.assertRaises(ValueError):
            sheets.apply(db,google,[plan])
        db.execute("INSERT INTO personnel_sheet_state VALUES ('roster','complete',?)",(json.dumps({"after":{"cell":"different"}}),))
        db.commit()
        with self.assertRaises(ValueError):
            sheets.apply(db,google,[plan],initialize=True)

    def test_training_headers_include_pilots_but_legacy_is_not_written(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        with patch.object(sheets,"read",return_value=[]):
            plan = sheets.training_plan(db,SimpleNamespace(),GUILD,[],False)
        self.assertEqual(len(plan["after"][0]),21)
        self.assertIn("Dropship Pilot",plan["after"][0])
        self.assertIn("Starfighter Pilot",plan["after"][0])
        for request in plan["requests"]:
            if "updateCells" in request:
                self.assertEqual(request["updateCells"]["range"]["sheetId"],sheets.TRAINING_ID)

    def test_training_primary_yellow_certified_green(self):
        db = sqlite3.connect(":memory:")
        self.addCleanup(db.close)
        policy.initialize(db)
        db.execute("INSERT INTO training_records VALUES (?,?,?,?,?,1,?,?)",(GUILD,"1","Name",json.dumps(["medic","marksman"]),json.dumps(["medic"]),"trainer","2026-11-02"))
        plan = sheets.training_plan(db,SimpleNamespace(),GUILD,[],False)
        request = next(request["updateCells"] for request in plan["requests"] if "updateCells" in request)
        cells = request["rows"][1]["values"]
        primary = cells[3+sheets.SPECS.index("medic")]
        certified = cells[3+sheets.SPECS.index("marksman")]
        self.assertIn("Primary",primary["note"])
        self.assertIn("Certified",certified["note"])
        self.assertNotEqual(primary["userEnteredFormat"]["backgroundColor"],certified["userEnteredFormat"]["backgroundColor"])
