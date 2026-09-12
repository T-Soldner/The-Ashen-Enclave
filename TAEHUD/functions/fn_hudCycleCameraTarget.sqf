if (!hasInterface || {isNull player}) exitWith {};
// Selecting a target must never override the player's panel preference.
if ((missionNamespace getVariable ["TAE_HUD_cameraLocation", 0]) isEqualTo 0) exitWith {};

private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display) exitWith
{
	hintSilent "The helmet HUD must be active.";
};

private _targets = (units group player) select
{
	_x isNotEqualTo player && {alive _x}
};

if (_targets isEqualTo []) exitWith
{
	uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", 0];
	[] call TAE_fnc_hudSyncAuxiliaryHandler;
	hintSilent "No living squadmates are available for helmet camera link.";
};

private _index = uiNamespace getVariable ["TAE_HUD_cameraTargetIndex", 0];
if ((missionNamespace getVariable ["TAE_HUD_cameraLocation", 0]) > 0) then
{
	_index = (_index + 1) mod (count _targets);
};

uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", _index];
[] call TAE_fnc_hudSyncAuxiliaryHandler;
