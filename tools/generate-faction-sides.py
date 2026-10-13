"""Generate side-only overrides from locally extracted installed mod configs."""
import importlib.util
from pathlib import Path
import re
import sys

root = Path(__file__).resolve().parents[1]
sys.dont_write_bytecode = True
spec = importlib.util.spec_from_file_location('eden', root / 'tools/import-mining-guild.py')
eden = importlib.util.module_from_spec(spec)
spec.loader.exec_module(eden)

class Parser(eden.Parser):
    def __init__(self, text):
        text = re.sub(r'//[^\n]*', '', text)
        self.tokens = re.findall(r'"(?:""|[^"])*"|-?\d+(?:\.\d+)?[eE][+-]?\d+|-?\d+\.\d+|[0-9]*[A-Za-z_$][\w$]*|-?\d+|[{}\[\]=;,:]', text)
        self.i = 0

    def value(self):
        if self.tokens[self.i] not in ('{',) and not self.tokens[self.i].startswith('"'):
            token = self.pop()
            try:
                return float(token) if any(c in token for c in '.eE') else int(token)
            except ValueError:
                return token
        return super().value()

    def node(self):
        result = {}
        while self.i < len(self.tokens) and self.tokens[self.i] != '}':
            key = self.pop()
            if key == 'class':
                key = self.pop()
                if self.tokens[self.i] == ';':
                    self.pop(';')
                    continue
                parent = None
                if self.tokens[self.i] == ':':
                    self.pop(':')
                    parent = self.pop()
                self.pop('{')
                result[key] = self.node()
                if parent:
                    result[key]['__parent'] = parent
                self.pop('}')
            else:
                if self.tokens[self.i] == '[':
                    self.pop('['); self.pop(']')
                self.pop('=')
                result[key] = self.value()
            self.pop(';')
        return result

def quote(value):
    if isinstance(value, list):
        return '{' + ', '.join(quote(x) for x in value) + '}'
    if isinstance(value, str):
        return '"' + value.replace('"', '""') + '"'
    return str(value)

def emit(name, node, level=0):
    indent = '\t' * level
    parent = ': ' + node['__parent'] if '__parent' in node else ''
    lines = [f'{indent}class {name}{parent} {{']
    for key, value in node.items():
        if key == '__parent':
            continue
        if isinstance(value, dict):
            lines.extend(emit(key, value, level + 1))
        else:
            if key == 'side':
                value = destination
            suffix = '[]' if isinstance(value, list) else ''
            lines.append(f'{indent}\t{key}{suffix} = {quote(value)};')
    return lines + [indent + '};']

configs = []
for path in (root / 'docs/local-assets/faction-side-reference').rglob('config.bin.cpp'):
    configs.append((path, Parser(path.read_text()).node()))
vehicles = {}
owners = {}
for path, cfg in configs:
    patches = list(cfg.get('CfgPatches', {}))
    for name, node in cfg.get('CfgVehicles', {}).items():
        vehicles[name] = node
        owners[name] = patches

def faction(name, seen=None):
    seen = set() if seen is None else seen
    if name in seen or name not in vehicles:
        return None
    seen.add(name)
    node = vehicles[name]
    return node.get('faction') or faction(node.get('__parent'), seen)

targets = {'JMSLLTE_hutt_fact': 1, 'JMSLLTE_Jinata_fact': 1, 'mti_factions_mando': 0}
selected = {n: targets[faction(n)] for n in vehicles if faction(n) in targets}
dependencies = sorted({p for n in selected for p in owners[n]} | {'JMSLLTE_Faction_name', 'mti_factions_mando'})
lines = ['// Generated from installed JMSLLTE and SOB configs; preserve original inheritance.',
         'class CfgPatches {', '\tclass TAE_FactionSideOverrides {',
         '\t\trequiredAddons[] = ' + quote(dependencies) + ';',
         '\t\tunits[] = {};', '\t\tweapons[] = {};', '\t};', '};',
         'class CfgFactionClasses {']
for name, destination in targets.items():
    lines.append(f'\tclass {name} {{ side = {destination}; }};')
lines += ['};', 'class CfgVehicles {']
ordered = []
def order(name):
    if name in ordered:
        return
    parent = vehicles[name].get('__parent')
    if parent in selected:
        order(parent)
    ordered.append(name)
for name in sorted(selected):
    order(name)
source_config = (root / 'TAEUnits/config.cpp').read_text()
declared = set(re.findall(r'\bclass\s+([\w]+)', source_config))
for name in ordered:
    destination = selected[name]
    parent = vehicles[name].get('__parent')
    if parent and parent not in declared:
        lines.append(f'\tclass {parent};')
        declared.add(parent)
    inherit = ': ' + parent if parent else ''
    lines.append(f'\tclass {name}{inherit} {{ side = {destination}; }};')
    declared.add(name)
lines += ['};', 'class CfgGroups {', '\tclass Indep {']
for name in targets:
    lines.append(f'\t\tdelete {name};')
lines += ['\t};']
for destination in (1, 0):
    lines.append('\tclass ' + ('West' if destination == 1 else 'East') + ' {')
    for name, side in targets.items():
        if side != destination:
            continue
        groups = next((cfg['CfgGroups']['Indep'][name] for _, cfg in configs
                       if name in cfg.get('CfgGroups', {}).get('Indep', {})), None)
        if groups:
            lines.extend(emit(name, groups, 2))
    lines.append('\t};')
lines += ['};', '']
text = '\n'.join(lines)
for section in ('CfgPatches', 'CfgFactionClasses', 'CfgVehicles'):
    start = text.index('class ' + section + ' {')
    begin = text.index('{', start) + 1
    depth = 1
    end = begin
    quoted = False
    while depth:
        char = text[end]
        if char == '"':
            quoted = not quoted
        if not quoted:
            if char == '{': depth += 1
            if char == '}': depth -= 1
        end += 1
    (root / f'TAEUnits/faction_sides_{section}.hpp').write_text(text[begin:end - 1].strip() + '\n')
for side in ('West', 'East'):
    output = []
    destination = 1 if side == 'West' else 0
    for name, target_side in targets.items():
        if target_side != destination:
            continue
        node = next((cfg['CfgGroups']['Indep'][name] for _, cfg in configs
                     if name in cfg.get('CfgGroups', {}).get('Indep', {})), None)
        if node:
            output.extend(emit(name, node))
    (root / f'TAEUnits/faction_sides_groups_{side}.hpp').write_text('\n'.join(output) + '\n')
(root / 'TAEUnits/faction_sides_groups_Indep.hpp').write_text(
    '\n'.join('delete ' + name + ';' for name in targets) + '\n')
for name, destination in targets.items():
    print(name, 'side', destination, 'classes', sum(faction(n) == name for n in selected))
print('Required addons:', dependencies)
