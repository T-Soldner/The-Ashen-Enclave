import json
from pathlib import Path
import tempfile
import unittest

import applications
import application_roles
from collector import connect
from discord_store import Store
import promotions

DID = "123456789012345678"
ACTIVE = {"source":"reddit","hours":"330","record":"no","about":"Hello","steam":"76561198000000001"}
LIAISON = {"unit":"Test unit","source":"friend","discord":"https://discord.com/invite/test"}


class PlanTests(unittest.TestCase):
    def test_exact_active_roles(self):
        expected = {1477486340072276115,1477486340101902512,1477486340080799940,
                    1477486340101902513,1477486340080799947,1477486340080799939,
                    1477486340051570795,1477486340030333095,1477486339984199938}
        desired = application_roles.plan(applications.CATEGORIES[0],ACTIVE)
        self.assertEqual(set(desired["add_roles"]),expected)
        self.assertEqual(desired["remove_role"],1477486339984199936)
        self.assertFalse(expected.intersection(promotions.PROTECTED_ROLE_IDS))

    def test_streamer_only_when_yes(self):
        yes = application_roles.plan(applications.CATEGORIES[0],{**ACTIVE,"record":"yes"})
        no = application_roles.plan(applications.CATEGORIES[0],ACTIVE)
        self.assertEqual(set(yes["add_roles"])-set(no["add_roles"]),{1477486340022206602})

    def test_friend_and_liaison_not_active_member_roles(self):
        self.assertEqual(application_roles.plan(applications.CATEGORIES[2],{})["add_roles"],[1477486340022206599])
        self.assertEqual(application_roles.plan(applications.CATEGORIES[1],LIAISON)["add_roles"],[1477486340022206603])


class FakeRoles:
    def __init__(self):
        self.roles = {applications.UNASSIGNED_ROLE,999}
        self.calls = 0
        self.fail = False
        self.fail_after_complete = False

    async def current(self,discord_id):
        return set(self.roles)

    async def preflight(self,desired,discord_id=None):
        pass

    async def apply(self,discord_id,desired):
        self.calls += 1
        if self.fail:
            raise RuntimeError("simulated failure")
        self.roles.update(desired["add_roles"])
        self.roles.discard(desired["remove_role"])
        if self.fail_after_complete:
            raise RuntimeError("simulated response loss")


class AdmissionsTests(unittest.IsolatedAsyncioTestCase):
    def setUp(self):
        self.root = tempfile.TemporaryDirectory()
        path = Path(self.root.name)/"test.sqlite3"
        connect(path).close()
        self.store = Store(path)
        self.store.run(lambda db: applications.submit(db,"1",DID,applications.CATEGORIES[0],ACTIVE))
        self.transport = FakeRoles()
        self.admissions = application_roles.Admissions(self.store,self.transport,True)

    def tearDown(self):
        self.root.cleanup()

    def status(self):
        return self.store.run(lambda db: db.execute("SELECT status FROM applications").fetchone()[0])

    async def test_accept_roles_then_approval_and_pending_attendance_claim(self):
        result = await self.admissions.approve(DID,"1")
        self.assertIn("verified",result)
        self.assertEqual(self.status(),"approved")
        self.assertNotIn(applications.UNASSIGNED_ROLE,self.transport.roles)
        self.assertIn(999,self.transport.roles)
        self.assertTrue(applications.ACTIVE_ROLES.issubset(self.transport.roles))
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT status FROM link_requests").fetchone()[0]),"pending")
        self.assertEqual(self.store.run(lambda db: db.execute("SELECT count(*) FROM members").fetchone()[0]),0)

    async def test_onboarding_failure_pending_then_resume_without_roles_repeated(self):
        async def fail(*args):
            raise ValueError("Sheet unavailable")
        self.admissions.onboard = fail
        with self.assertRaises(ValueError):
            await self.admissions.approve(DID,"1")
        self.assertEqual(self.status(),"pending")
        async def succeed(*args):
            return "Attendance registration verified."
        self.admissions.onboard = succeed
        result = await self.admissions.approve(DID,"1")
        self.assertIn("registration verified",result)
        self.assertEqual(self.status(),"approved")
        self.assertEqual(self.transport.calls,1)

    async def test_only_unassigned_applicants_can_be_accepted(self):
        self.transport.roles.discard(applications.UNASSIGNED_ROLE)
        with self.assertRaises(ValueError):
            await self.admissions.approve(DID,"1")
        self.assertEqual(self.status(),"pending")
        self.assertEqual(self.transport.calls,0)

    async def test_disabled_no_roles_or_decision(self):
        self.admissions.enabled = False
        with self.assertRaises(ValueError):
            await self.admissions.approve(DID,"1")
        self.assertEqual(self.transport.calls,0)
        self.assertEqual(self.status(),"pending")

    async def test_failure_keeps_unassigned_and_pending(self):
        self.transport.fail = True
        with self.assertRaises(RuntimeError):
            await self.admissions.approve(DID,"1")
        self.assertEqual(self.status(),"pending")
        self.assertIn(applications.UNASSIGNED_ROLE,self.transport.roles)
        self.transport.fail = False
        with self.assertRaises(ValueError):
            await self.admissions.approve(DID,"1")
        self.assertEqual(self.transport.calls,1)

    async def test_partial_assignment_cannot_be_denied_without_reconciliation(self):
        self.transport.fail = True
        with self.assertRaises(RuntimeError):
            await self.admissions.approve(DID,"1")
        with self.assertRaises(ValueError):
            self.store.run(lambda db: applications.review(db,DID,"1",False,"Reject after partial roles"))
        self.assertEqual(self.status(),"pending")

    async def test_verified_response_loss_can_complete_without_repeating_role_edits(self):
        self.transport.fail_after_complete = True
        with self.assertRaises(RuntimeError):
            await self.admissions.approve(DID,"1")
        await self.admissions.approve(DID,"1")
        self.assertEqual(self.transport.calls,1)
        self.assertEqual(self.status(),"approved")

    async def test_duplicate_accept_not_applied_twice(self):
        await self.admissions.approve(DID,"1")
        with self.assertRaises(ValueError):
            await self.admissions.approve(DID,"1")
        self.assertEqual(self.transport.calls,1)


if __name__ == "__main__":
    unittest.main()
