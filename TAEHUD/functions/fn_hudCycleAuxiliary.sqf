if (!hasInterface || {isNull player}) exitWith {};

private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display) exitWith
{
	hintSilent "The helmet HUD must be active.";
};

private _mode = ((uiNamespace getVariable ["TAE_HUD_auxiliaryMode", 0]) + 1) mod 3;
uiNamespace setVariable ["TAE_HUD_auxiliaryMode", _mode];

if (_mode isNotEqualTo 2) then
{
	[] call TAE_fnc_hudDestroyCamera;
};

[] call TAE_fnc_hudUpdateAuxiliary;
