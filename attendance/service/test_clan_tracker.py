import unittest
from unittest.mock import patch
from types import SimpleNamespace

import clan_tracker


class ClanTests(unittest.TestCase):
    def test_groups_and_freelancer_default(self):
        for role, expected in [("Clan Acklay","Clan Acklay"),("Clan Rook","Clan Rook"),
                               ("Shyyyo Flight","Shyyyo Flight"),("Freelance Mandalorians","Freelancers")]:
            self.assertEqual(clan_tracker.classify([role]),expected)
        self.assertEqual(clan_tracker.classify(["Freelance Mandalorians","Clan Rook"]),"Clan Rook")

    def test_unknown_or_conflicting_groups_not_guessed(self):
        self.assertEqual(clan_tracker.classify([]),"Needs clan assignment")
        self.assertEqual(clan_tracker.classify(["Clan Rook","Clan Acklay"]),"Needs clan assignment")

    def test_verified_role_ids_do_not_depend_on_discord_role_names(self):
        self.assertEqual(clan_tracker.classify([1477486340080799943,1477486340080799940]),"Clan Rook")
        self.assertEqual(clan_tracker.classify([1510404359228362934]),"Shyyyo Flight")

    def test_requires_expected_helper_and_write_flag(self):
        with self.assertRaises(ValueError):
            clan_tracker.sync(None,SimpleNamespace(writable=False),{})
        with patch.object(clan_tracker,"get_json",return_value={"sheets":[]}):
            with self.assertRaises(ValueError):
                clan_tracker.sync(None,SimpleNamespace(writable=True,session=None),{})
