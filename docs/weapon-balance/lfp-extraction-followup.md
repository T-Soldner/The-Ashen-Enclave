# LFP Extraction Follow-Up

Recorded 2026-09-09. Documentation only; no gameplay changes.

PBO Manager's installed pboc.exe successfully unpacked LF_Weapon_Unit.pbo.
Earlier BankRev rejection and the config-only extraction were tooling limitations,
not proof that readable weapon definitions could not be recovered.

Source: D:/SteamLibrary/steamapps/common/Arma 3/!Workshop/@Last Force Project/addons/LF_Weapon_Unit.pbo

PBO SHA256: 7EFF054649DE9A28D28F953395DA9638F42CF9DF380E4711B3BB89A285A6A97C

Extractor: C:/Program Files/PBO Manager/pboc.exe unpack -o <temporary directory> <source PBO>

Output: C:/Users/tomso/AppData/Local/Temp/tae_lfp_pbomanager_audit/LF_Weapon_Unit

The lw7/config.cpp and westarsniper/config.cpp files point to unusually named
extensionless files containing readable CfgWeapons, CfgMagazines and CfgAmmo.
PBO Manager escaped an asterisk in the extracted filenames as %2a. Inspected the
include targets rather than assuming unrelated .bin files were authoritative.
Installed PBO was not changed. Full vendor assets remain outside the repository.

| Property | LFP_lw7 | LFP_westarsniper |
|---|---|---|
| Magazine | LFP_lw7_Mag | LFP_westarsniper_mag |
| Rounds | 12 | 14 |
| Magazine mass (config units) | 5 | 10 |
| Player fire mode | Single | Single |
| reloadTime | 0.7 s | 0.7 s |
| Nominal cycle ceiling | 85.7 RPM | 85.7 RPM |
| dispersion | 0.0000001 | 0.0000001 |
| Weapon mass (config units) | 60 | 60 |
| Ammo | LFP_ammo_lw7 | LFP_ammo_WestarSniper |
| Nominal hit | 85 | 75 |
| caliber | 3.8000002 | 3 |
| Magazine velocity | 2000 m/s | 1200 m/s |
| Weapon initSpeed | -1 (use magazine speed) | -1 (use magazine speed) |
| typicalSpeed | 1700 m/s | 1200 m/s |
| airFriction | 0 | 0 |
| Recoil class | LFP_recoil | LFP_recoil |

Both have built-in optics with the following identical fields:

- discreteFov: string expressions 0.25/3, 0.25/6, 0.25/9, 0.25/12, 0.25/15, 0.25/20.
- These describe intended approximate 3/6/9/12/15/20x zoom steps.
- opticsZoomMin=0.0625, opticsZoomMax=0.125, opticsZoomInit=0.125.
- The min/max fields instead correspond to approximately 4x/2x. They do not
  agree with the discrete zoom sequence. Do not claim observed 3-20x behavior
  solely from this file: validate which values the engine uses in the running game.
- visionMode: Normal, NVG, TI.
- discreteDistance: 100 through 1200 m in 100 m steps; initial index 1.

Source-level capacity/cadence are now resolved. Live merged config, actual zoom,
script/animation limits and practical firing rate are still not measured here.
Original dated audit/JSON intentionally remain unchanged; this document supersedes
their assertion that LFP capacity and cycle settings remain unavailable.
