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
