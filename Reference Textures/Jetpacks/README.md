# Jetpack 2D Texture References

Verified 2026-09-10 against TAEGear/Backpacks/config.cpp and the installed House Kandosii Aux Mod's knd_jetpacks.pbo and knd_rotary.pbo (local file dates 2026-09-08).

These are base color references, not existing players' custom textures. All 12 PNGs are 2048 x 2048. The nine previously present PNGs matched fresh PAA conversions pixel-for-pixel; the three missing Z-4/MS-EJT4 references were added.

## Pick Your Jetpack

| TAE jetpack | PNG references | Hidden selections, in config order |
| --- | --- | --- |
| JT-12 | JT12_Rocket_co.png + JT12_Pack_co.png | rocket, pack |
| JT-12 LR | JT12_Rocket_co.png + JT12_RTO_Pack_co.png | rocket, pack |
| JT-13 | JT13_Camo1_co.png | camo1 |
| JT-13 LR | JT13_RTO_Camo1_co.png | camo1 |
| MS-EJT4 | MSEJT4_Pack_co.png | camo1, camo2 (same texture in both slots) |
| MS-EJT4 LR | MSEJT4_Pack_co.png | camo1, camo2 (same texture in both slots) |
| Z-6 | Z6_Rocket_co.png + Z6_Pack_co.png | rocket, pack |
| Z-12 | Z12_Rocket_co.png + Z12_Pack_co.png | rocket, pack |
| Z-4 | Z4_Rocket_co.png + Z4_Pack_co.png | rocket, pack |

RTO means the LR radio model's texture. JT-12 and JT-13 LR models use different color maps from their non-LR counterparts; do not substitute one for the other. MS-EJT4 uses the same model and texture for both radio variants. We have no TAE LR variants of the Z-series.

The JT-12's selection named `rocket` exists even though our JT-12 is not a rocket-launching pack. Keep that texture unless you want to recolor that part too.

MS-EJT4 is our name for the Kandosii JD-77 / KND_RotaryBackpack (previously called JT-70 in TAE). Z-4 uses Kandosii's PV model. These are not JT-12/JT-13 texture layouts.

## Existing Customs

- Hondo and Edonn: JT-13 and JT-13 LR, each with its corresponding base layout.
- Stasik: JT-12 and JT-12 LR; both currently retain the base JT-12 rocket texture.
- Nova: Z-6, with custom pack and rocket textures.

## Preparing A Custom

Permission described by the mod team covers 2D texture work only. Use these flat PNGs in a 2D image editor. This folder intentionally provides no models, SPP projects, or 3D painting resources. Do not assume permission to modify or redistribute models.

Keep the 2048 x 2048 canvas and the positions of the texture islands. Paint over the reference without rearranging it. Keep an editable 2D source locally and submit a PNG for conversion to PAA. Existing base materials, normal maps, and model geometry remain unchanged.

Match our existing custom filenames, replacing NAME with your character name:

- JT12_Pack_NAME.png / JT12_RTO_Pack_NAME.png; optional JT12_Rocket_NAME.png
- JT13_Pack_NAME.png / JT13_RTO_Pack_NAME.png (reference selection is called Camo1)
- MSEJT4_Pack_NAME.png (usable for both variants)
- Z6_Pack_NAME.png + Z6_Rocket_NAME.png
- Z12_Pack_NAME.png + Z12_Rocket_NAME.png
- Z4_Pack_NAME.png + Z4_Rocket_NAME.png

Only submit rocket textures if you changed them; unchanged parts can continue referencing Kandosii's original files. The mod team handles class registration, texture paths, and in-game verification. These files are color references, not UV wireframe templates or a guarantee that new paintwork has been tested in-game.

## Exact Source Mapping

| Reference PNG | Original PAA path |
| --- | --- |
| JT12_Pack_co.png | knd_jetpacks/data/jt12/pack_co.paa |
| JT12_Rocket_co.png | knd_jetpacks/data/jt12/rocket_co.paa |
| JT12_RTO_Pack_co.png | knd_jetpacks/data/jt12RTO/pack_co.paa |
| JT13_Camo1_co.png | knd_jetpacks/data/jt13/camo1_co.paa |
| JT13_RTO_Camo1_co.png | knd_jetpacks/data/jt13RTO/camo1_co.paa |
| Z6_Pack_co.png | knd_jetpacks/data/Z6/pack_co.paa |
| Z6_Rocket_co.png | knd_jetpacks/data/Z6/Rocket_co.paa |
| Z12_Pack_co.png | knd_jetpacks/data/Z12/pack_co.paa |
| Z12_Rocket_co.png | knd_jetpacks/data/Z12/Rocket_co.paa |
| Z4_Pack_co.png | knd_jetpacks/data/PV/pack_co.paa |
| Z4_Rocket_co.png | knd_jetpacks/data/PV/rocket_co.paa |
| MSEJT4_Pack_co.png | knd_rotary/backpack/rotarybackpack_co.paa |

Extraction and conversion do not modify the installed mod. Only PNG references and this guide are supplied here; no source model or material files are included.
