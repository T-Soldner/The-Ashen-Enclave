# Temporary Tatooine Grid Fix

Retired September 16, 2026 after inspecting the updated installed 3AS PBOs.
This is the same patch tested in the Ashen Enclave Missions task on September 14, 2026.

`3AS_Main_Intro` changes Tatooine's parent from `Stratis` to `CAWorld`, losing
inherited grid settings and producing missing Grid.offsetX/Grid.offsetY errors.
The separate `tae_tatooine_grid_fix.pbo` restores `Stratis` after both addons load.
It does not modify Workshop files, terrain assets, or mission files.

The updated `3AS_Main.pbo` / `intro/config.bin` no longer declares Tatooine
in CfgWorlds. `map_tatooine.pbo` still declares `3as_Tatooine: Stratis`.
The offending parent override is therefore absent. The temporary source config
and all three build-list entries have been removed. This was a config inspection,
not a live Arma map/GPS test.

## Retirement

With updated 3AS and this patch disabled, check Tatooine map/GPS grids and the
RPT once more in-game. Remove the old
`tae_tatooine_grid_fix.pbo` and matching `.bisign` files from deployed Addons
folders too: the build scripts do not purge addons removed from their lists.
