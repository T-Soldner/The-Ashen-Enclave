"""Compile and verify the OPFOR House Karr infantry mirror using local tools."""
import argparse
import importlib.util
from pathlib import Path
import subprocess
import tempfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    spec = importlib.util.spec_from_file_location('gear', root / 'tools/check-gear.py')
    gear = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(gear)
    with tempfile.TemporaryDirectory(prefix='tae-imposters-') as temporary:
        output = Path(temporary) / 'units.cpp'
        binary = Path(temporary) / 'config.bin'
        result = subprocess.run([args.compiler, '-bin', '-dst', str(binary), str(root / 'TAEUnits/config.cpp')], capture_output=True, text=True)
        if result.returncode or not binary.exists():
            raise RuntimeError(result.stdout + result.stderr)
        result = subprocess.run([args.compiler, '-txt', '-dst', str(output), str(binary)], capture_output=True, text=True)
        if result.returncode or not output.exists():
            raise RuntimeError(result.stdout + result.stderr)
        compiled = output.read_text()
        config = gear.parse(compiled)['classes']
    vehicles = config['CfgVehicles']
    faction = 'TAE_Faction_HouseKarr_Imposters'
    assert gear.strings(config['CfgFactionClasses']['classes'][faction]['props']['displayName']) == ['[TAE] House Karr Imposters']
    assert config['CfgFactionClasses']['classes'][faction]['props']['side'] == ['0']

    def prop(cls, key):
        node = vehicles['classes'][cls]
        if key in node['props']:
            return node['props'][key]
        base = vehicles['bases'].get(cls)
        return prop(base, key) if base in vehicles['classes'] else None

    roles = ['Veteran', 'RisingPhoenix', 'Engineer', 'Medic', 'Marksman', 'AT_AA', 'Grenadier', 'CQC_Specialist', 'Heavy_Weapons', 'Sniper']
    advertised = gear.strings(config['CfgPatches']['classes']['TAEUnits_HouseKarr']['props']['units'])
    for role in roles:
        source, target = 'TAE_Unit_' + role, 'TAE_Unit_Imposter_' + role
        assert vehicles['bases'][target] == source
        assert target in advertised
        assert prop(target, 'side') == ['0']
        assert gear.strings(prop(target, 'faction')) == [faction]
        for key in ('linkedItems', 'respawnLinkedItems'):
            original = gear.strings(prop(source, key))
            expected = ['tae_karr_armor_medium_mv' if item.startswith('tae_karr_armor_') else
                        'tae_karr_helmet_mv' if item.startswith('tae_karr_helmet_') else item for item in original]
            assert gear.strings(prop(target, key)) == expected, (role, key)
        assert gear.strings(prop(target, 'uniformClass')) == ['tae_uniform_dark_red_seal']
        assert gear.strings(prop(target, 'hiddenSelectionsTextures'))[0] == 'TAEGear\\Data\\Uniforms\\Undersuit_Dark_Red_co.paa'
        assert set(vehicles['classes'][target]['props']) == {'side', 'faction', 'scope', 'scopeCurator', 'linkedItems', 'respawnLinkedItems', 'uniformClass', 'hiddenSelectionsTextures'}
    group_config = gear.parse(compiled[compiled.index('class CfgGroups'):])['classes']['CfgGroups']
    groups = group_config['classes']['East']['classes'][faction]['classes']['Infantry']['classes']
    assert len(groups) == 4
    for group in groups.values():
        assert group['props']['side'] == ['0']
        assert gear.strings(group['props']['faction']) == [faction]
        for unit in group['classes'].values():
            if 'vehicle' in unit['props']:
                assert gear.strings(unit['props']['vehicle'])[0].startswith('TAE_Unit_Imposter_')
                assert unit['props']['side'] == ['0']
    print('PASS: compiled TAEUnits; 10 infantry variants, veteran gear/respawn gear, inherited roles/loadouts, Zeus registration and 4 OPFOR groups verified.')


if __name__ == '__main__':
    main()
