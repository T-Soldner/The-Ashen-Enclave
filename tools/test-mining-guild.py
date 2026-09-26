"""Offline regression checks for the generated faction and Eden inventory conversion."""
import runpy
import unittest
from pathlib import Path

importer = runpy.run_path(str(Path(__file__).with_name('import-mining-guild.py')))
Parser = importer['Parser']


class MiningGuildTests(unittest.TestCase):
    def test_inventory_preserves_ammunition_and_attachments(self):
        inventory = {'primaryWeapon': {'name': 'rifle', 'optics': 'scope',
                     'primaryMuzzleMag': {'name': 'mag', 'ammoLeft': 17},
                     'secondaryMuzzleMag': {'name': 'grenade', 'ammoLeft': 1}},
                     'uniform': {'typeName': 'uniform', 'MagazineCargo': {
                         'Item0': {'name': 'mag', 'count': 3, 'ammoLeft': 20}}}}
        result = importer['loadout'](inventory)
        self.assertEqual(len(result), 10)
        self.assertEqual(result[0][3:6], ['scope', ['mag', 17], ['grenade', 1]])
        self.assertEqual(result[3], ['uniform', [['mag', 3, 20]]])
        self.assertEqual(result[1], [])

    def test_generated_roster(self):
        config = Parser((Path(__file__).resolve().parents[1] / 'TAEUnits/MiningGuild/config.cpp').read_text()).node()
        self.assertEqual(config['CfgFunctions']['TAE']['MiningGuild']['file'], 'TAEUnits\\MiningGuild\\functions')
        roster = config['CfgPatches']['TAEMiningGuild']['units']
        self.assertEqual(len(roster), 20)
        self.assertEqual(len(set(roster)), 20)
        self.assertIn('SFA_sith_Equipment', config['CfgPatches']['TAEMiningGuild']['requiredAddons'])
        for cls in roster:
            unit = config['CfgVehicles'][cls]
            self.assertEqual(unit['side'], 0)
            self.assertEqual(unit['scopeCurator'], 2)
            self.assertEqual(unit['faction'], 'TAE_Faction_MiningGuild')
            self.assertEqual(unit['editorCategory'], 'TAE_EdCat_MiningGuild')
            self.assertIn(cls, config['Extended_Init_EventHandlers'])
        self.assertEqual(sum('TAE_loadout' in config['CfgVehicles'][c] for c in roster), 7)
        groups = config['CfgGroups']['East']['TAE_Faction_MiningGuild']['Infantry']
        self.assertEqual(len(importer['children'](groups)), 3)


if __name__ == '__main__':
    unittest.main()
