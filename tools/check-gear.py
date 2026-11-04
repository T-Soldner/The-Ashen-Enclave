"""Check gear configs with CfgConvert and audit local gear/menu references."""
import argparse
from pathlib import Path
import re
import subprocess
import tempfile


TOKEN = re.compile(r'"(?:""|[^"])*"|[A-Za-z_][\w]*|[-+]?\d+(?:\.\d+)?|[^\s]')


def parse(text):
    tokens = TOKEN.findall(text)
    index = 0

    def body():
        nonlocal index
        node = {"classes": {}, "props": {}, "bases": {}}
        while index < len(tokens) and tokens[index] != "}":
            if tokens[index].lower() == "class":
                index += 1
                name = tokens[index]
                index += 1
                base = None
                if tokens[index] == ":":
                    base = tokens[index + 1]
                    index += 2
                if tokens[index] == "{":
                    index += 1
                    node["classes"][name] = body()
                    node["bases"][name] = base
                    index += 1
                else:
                    index += 1
            elif index + 1 < len(tokens) and tokens[index + 1] in ("=", "["):
                name = tokens[index]
                index += 1
                while index < len(tokens) and tokens[index] != "=":
                    index += 1
                index += 1
                value = []
                while index < len(tokens) and tokens[index] != ";":
                    value.append(tokens[index])
                    index += 1
                node["props"][name] = value
            else:
                index += 1
        return node

    return body()


def strings(tokens):
    return [t[1:-1] for t in tokens if t.startswith('"')]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", type=Path, required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    errors = []
    trees = []
    configs = sorted((root / "TAEGear").rglob("config.cpp"))
    with tempfile.TemporaryDirectory(prefix="tae-gear-check-") as temporary:
        for number, config in enumerate(configs):
            output = Path(temporary) / f"{number}.cpp"
            result = subprocess.run(
                [str(args.compiler), "-pcpp", "-dst", str(output), str(config)],
                capture_output=True, text=True,
            )
            if result.returncode or not output.exists():
                errors.append(f"Compiler failed: {config}: {result.stdout} {result.stderr}")
                continue
            trees.append((config, parse(output.read_text(encoding="utf-8-sig"))))

    weapons = {}
    vehicles = {}
    glasses = {}
    models = {}
    infos = {}
    for config, tree in trees:
        classes = tree["classes"]
        for group, target in (("CfgWeapons", weapons), ("CfgVehicles", vehicles), ("CfgGlasses", glasses)):
            section = classes.get(group, {"classes": {}, "bases": {}})
            for name, node in section["classes"].items():
                if name in target:
                    errors.append(f"Duplicate {group} definition: {name}")
                target[name] = (config, node, section["bases"].get(name))
        for group, target in (("XtdGearModels", models), ("XtdGearInfos", infos)):
            section = classes.get(group, {}).get("classes", {}).get("CfgWeapons", {})
            target.update(section.get("classes", {}))

    for group, definitions in (("CfgWeapons", weapons), ("CfgVehicles", vehicles)):
        for name, (config, node, base) in definitions.items():
            if base and base.lower().startswith("tae_") and base not in definitions:
                errors.append(f"Missing {group} base {base} for {name}: {config}")

    for name, (_, node, _) in weapons.items():
        item = node["classes"].get("ItemInfo", {})
        for unit in strings(item.get("props", {}).get("uniformClass", [])):
            if unit.lower().startswith("tae_") and unit not in vehicles:
                errors.append(f"Uniform {name} refers to missing unit: {unit}")
    for config, tree in trees:
        patches = tree["classes"].get("CfgPatches", {}).get("classes", {})
        for patch in patches.values():
            for prop, definitions in (("weapons", weapons | glasses), ("units", vehicles)):
                for name in strings(patch["props"].get(prop, [])):
                    if name not in definitions:
                        errors.append(f"Patch {prop} lists undefined class {name}: {config}")

    for name, info in infos.items():
        if name not in weapons:
            errors.append(f"XTD item is not a gear weapon: {name}")
        model_names = strings(info["props"].get("model", []))
        if not model_names or model_names[0] not in models:
            errors.append(f"Missing XTD model for {name}: {model_names}")
            continue
        model = models[model_names[0]]
        for option in strings(model["props"].get("options", [])):
            values = strings(model["classes"].get(option, {}).get("props", {}).get("values", []))
            selected = strings(info["props"].get(option, []))
            if len(selected) != 1 or selected[0] not in values:
                errors.append(f"Invalid XTD option {name}.{option}: {selected}, expected {values}")

    references = 0
    for file in (root / "TAEGear").rglob("*"):
        if file.suffix.lower() not in (".cpp", ".hpp", ".rvmat", ".sqf"):
            continue
        text = file.read_text(encoding="utf-8-sig")
        for asset in re.findall(r'"(\\?TAE[^"\r\n]*\.(?:paa|rvmat|p3d|sqf|hpp))"', text, re.I):
            references += 1
            if not (root / asset.lstrip("\\").replace("\\", "/")).is_file():
                errors.append(f"Missing asset in {file}: {asset}")

    wearable = (root / "TAEObjects/config.cpp").read_text(encoding="utf-8-sig")
    for statement in re.findall(r'statement\s*=\s*"([^"\n]*applyWearableLoadout[^"\n]*)"', wearable):
        for name in re.findall(r"'(tae_[^']+)'", statement, re.I):
            if name not in weapons and name not in glasses:
                errors.append(f"Wearable refers to missing gear: {name}")

    arsenal = (root / "TAEObjects/functions/fn_getArsenalItems.sqf").read_text(encoding="utf-8-sig")
    for name in ("tae_samantha_helmet", "tae_rook_niteowl_armor", "tae_keira_armor"):
        if f'"{name}"' not in arsenal:
            errors.append(f"New PR gear missing from restricted arsenal: {name}")

    print(f"Checked {len(trees)}/{len(configs)} gear configs; {len(weapons)} weapon classes; "
          f"{len(vehicles)} vehicle classes; {len(infos)} XTD items; {references} local asset references.")
    for error in sorted(set(errors)):
        print(f"ERROR: {error}")
    print("PASS" if not errors else "FAIL")
    return int(bool(errors))


if __name__ == "__main__":
    raise SystemExit(main())
