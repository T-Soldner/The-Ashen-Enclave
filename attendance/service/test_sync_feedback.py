import unittest
from sync_feedback import SyncFailure, instructions, run_step


class SyncFeedbackTests(unittest.IsolatedAsyncioTestCase):
    def test_roster_error_has_exact_commands(self):
        text = instructions(SyncFailure('Unit Roster', ValueError('Managed cells changed')))
        for command in ('/tae-maintenance sheets preview', '/tae-maintenance roster-sync', '/tae-maintenance roster-sync confirm:True'):
            self.assertIn(command, text)
        self.assertIn('already verified', text)

    def test_unknown_exception_does_not_leak_details(self):
        text = instructions(SyncFailure('Attendance export', RuntimeError('private token')))
        self.assertNotIn('private token', text)
        self.assertNotIn('already verified', text)

    async def test_inner_stage_is_preserved(self):
        async def bad():
            raise SyncFailure('Unit Roster', ValueError('Layout changed'))
        with self.assertRaises(SyncFailure) as result:
            await run_step('Discord name lookup', bad)
        self.assertEqual(result.exception.stage, 'Unit Roster')
