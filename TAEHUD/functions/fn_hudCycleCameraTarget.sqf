if (!hasInterface || {isNull player}) exitWith {};

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
	uiNamespace setVariable ["TAE_HUD_auxiliaryMode", 2];
	uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", 0];
	[] call TAE_fnc_hudDestroyCamera;
	[] call TAE_fnc_hudUpdateAuxiliary;
	hintSilent "No living squadmates are available for helmet camera link.";
};

private _index = uiNamespace getVariable ["TAE_HUD_cameraTargetIndex", 0];
if ((uiNamespace getVariable ["TAE_HUD_auxiliaryMode", 0]) isEqualTo 2) then
{
	_index = (_index + 1) mod (count _targets);
};

uiNamespace setVariable ["TAE_HUD_auxiliaryMode", 2];
uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", _index];
[] call TAE_fnc_hudUpdateAuxiliary;
