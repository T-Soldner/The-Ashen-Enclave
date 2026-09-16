# TAE Acclamators and Sci-fi Support Plus

## Ships

- `TAE_Acclamator`: `[TAE] Acclamator`, based on `ls_staticShip_acclamator`.
- `TAE_Acclamator_Landed`: `[TAE] Acclamator (Landed)`, based on `ls_staticShip_acclamator_landed`.

Both appear in Eden/Zeus under `[TAE] House Karr Objects` -> `Capital Ships`.
They are static ships, not pilotable aircraft. They inherit LS's model, materials,
selection names and original paint. LS remains required; its models are not copied.
Paint references and slot mapping are in `Reference Textures/Acclamator/README.md`.

## FTL Integration

Inspected the locally installed Sci-fi Support Plus, whose PHAN_ScifiSupportPlus
config reports version 1.1.3. Its preInit constructs explicit class/display lists;
derived classes do not automatically appear in the Zeus ship selector.

`TAE_fnc_initAcclamatorFTL` optionally adds both TAE classes to its all-ships and
Star Wars class/display lists, and Republic classification list, during postInit
on each machine. Registration is idempotent and does nothing without the mod.
No upstream functions, Workshop files or hard dependency are introduced.

The installed `PHAN_ScifiSupportPlus_fnc_getShipSettings` has no special case for
the modern LS Acclamator class. Both it and these TAE classes use the same default
settings (zero direction offset, no portal-ring effect). The jump system still
provides the movement and jump/ambient sounds. No custom flight physics are needed.

## Zeus Test

1. Repack TAEObjects and restart Arma with TAE, LS, Sci-fi Support Plus and its dependencies.
2. Under `[Sci-Fi+] FTL Systems`, place `Jump Ship in` at the arrival location.
3. Choose `[TAE] Acclamator`, the appropriate side, approach direction and altitude.
4. Leave Support Ship disabled for a visual arrival without automatic combat.
5. Use the mod's Move Ship / Jump Ship Out controls for subsequent movement/departure.

If the module is absent, check the mod's Jump Ship In addon setting. The Eden
`[Sci-Fi+] Jump Ship In` module also has a Ship classname field accepting
`TAE_Acclamator` (or `TAE_Acclamator_Landed`).

Prefer the standard ship for arrivals. The landed class has its feet, legs and
ramp already visible; the module does not turn it into an animated landing sequence.
FTL builds a core object with locally created ship visuals, rather than flying
the original static object. Do not assume passengers, objects placed inside it,
or per-instance texture edits will be transported/preserved. Put future custom
textures in the TAE class defaults so freshly created FTL visuals inherit them.

## Validation

Config compiled with Arma Tools CfgConvert; exported 15 PAA/PNG color-map pairs.
FTL registration and upstream call paths were source-reviewed. Still requires
in-game testing of arrival direction/altitude, dedicated-server clients and JIP.
Nothing has been pushed as part of this change.
