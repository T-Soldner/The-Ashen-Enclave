import unittest
import promotions
from rank_review import inspect, correction


class RankReviewTests(unittest.TestCase):
    def current(self, rank=0, nickname='[FD] Name', protected=False):
        return {'roles': [promotions.RANKS[rank]['role']], 'nickname': nickname, 'protected': protected}

    def test_matching(self):
        self.assertTrue(inspect(self.current(), 0, 0).endswith('OK'))

    def test_promotable(self):
        self.assertIn('staff promotion review needed', inspect(self.current(), 0, 1))

    def test_no_demotion(self):
        self.assertIn('do NOT automatically demote', inspect(self.current(4, '[MV] Name'), 0, 0))

    def test_wrong_prefix(self):
        self.assertIn('prefix should be [MV]', inspect(self.current(4), 20, 0))

    def test_missing_roles(self):
        current = self.current()
        current['roles'] = []
        self.assertIn('Missing/conflicting', inspect(current, 0, 0))

    def test_protection(self):
        self.assertIn('PROTECTED', inspect(self.current(protected=True), 0, 2))

    def test_seven_ops_corrects_recruit_to_apprentice(self):
        plan = correction(self.current(1, '[MR] Shogun Foxx'), 6, 1)
        self.assertEqual(plan['nickname'], '[MA] Shogun Foxx')
        self.assertEqual(plan['add_role'], promotions.RANKS[2]['role'])
        self.assertEqual(plan['remove_roles'], [promotions.RANKS[1]['role']])
        self.assertEqual(plan['expected_total'], 7)

    def test_correction_never_demotes(self):
        with self.assertRaises(ValueError):
            correction(self.current(4, '[MV] Name'), 0, 1)

    def test_correction_protects_appointed_members(self):
        with self.assertRaises(ValueError):
            correction(self.current(protected=True), 20, 1)
