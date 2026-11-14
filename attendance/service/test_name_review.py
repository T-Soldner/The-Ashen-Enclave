import sqlite3
import unittest

import name_review
import promotions


class NameReviewTests(unittest.TestCase):
    def current(self, **values):
        return {'protected': False, 'roles': [promotions.RANKS[4]['role']],
                'nickname': 'Jimothy', **values}

    def test_prefix_from_role(self):
        self.assertEqual(name_review.proposal(self.current()), '[MV] Jimothy')

    def test_wrong_prefix_replaced_not_stacked(self):
        self.assertEqual(name_review.proposal(self.current(nickname='[MA] Jimothy')), '[MV] Jimothy')

    def test_protected_refused(self):
        with self.assertRaises(ValueError):
            name_review.proposal(self.current(protected=True))

    def test_conflicting_roles_refused(self):
        with self.assertRaises(ValueError):
            name_review.proposal(self.current(roles=[rank['role'] for rank in promotions.RANKS]))

    def test_invalid_names(self):
        for name in ('', '[MV] Name', 'a\nb', 'x' * 32):
            with self.assertRaises(ValueError):
                name_review.nickname('MV', name)

    def test_receipt_preserves_attendance(self):
        db = sqlite3.connect(':memory:')
        name_review.initialize(db)
        name_review.save(db, 1, '2026-11-07:main', 2, 'denied', {'nickname': 'Name'}, 3)
        self.assertEqual(db.execute('SELECT state,actor_id FROM name_reviews').fetchone(), ('denied', '3'))
        db.close()
