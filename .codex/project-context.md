# The Ashen Enclave Local Context

Useful local paths for this project:

- Steam library: `D:\SteamLibrary`
- Arma 3 install: `D:\SteamLibrary\steamapps\common\Arma 3`
- Arma 3 Tools: `D:\SteamLibrary\steamapps\common\Arma 3 Tools`
- Arma 3 Workshop content: `D:\SteamLibrary\steamapps\workshop\content\107410`

MokTech drone reference:

- Mod: `MokTech Industries - Armoury`
- Workshop ID: `2853198944`
- PBO: `D:\SteamLibrary\steamapps\workshop\content\107410\2853198944\addons\mti_armoury_drones.pbo`
- Addon root/class prefix: `mti_armoury_drones`

TAE drone convention:

- Custom TAE drones should spawn as Independent (`side = 2`, `crew = "I_UAV_AI"`).

Build workflow preference:

- Update source files in the GitHub workspace only.
- Do not write directly to packed `.pbo` files or the Arma 3 mod Addons directory unless explicitly requested.
- The user will pack workspace changes into the Arma directory with the project build script.

Release workflow preference:

- Before every merge and push to `main`, update `TAE_VERSION_STR` and `TAE_VERSION_AR` in `TAECore/config.cpp` so CBA can detect client/server version mismatches.
- Use `MAJOR.MINOR.FEATURE.REVISION` versioning:
  - `MAJOR`: breaking compatibility, broad class changes, or dependency restructuring.
  - `MINOR`: a new PBO or major subsystem. Reset `FEATURE` and `REVISION` to `0`.
  - `FEATURE`: substantial content in an existing PBO, such as a new vehicle, faction, or system. Reset `REVISION` to `0`.
  - `REVISION`: routine arsenal changes, textures, custom armor or helmets, balance adjustments, and config fixes.
- When a release contains several change types, increment only the highest applicable component and reset all components to its right.
- Keep `main` and `dev` synchronized after a live merge, then switch the local workspace back to `dev`.
- Provide a short Steam Workshop-ready changelog after each merge to `main`.
