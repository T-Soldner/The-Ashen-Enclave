params [["_display", displayNull, [displayNull]]];

private _currentDisplay = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (!isNull _currentDisplay && {_display isNotEqualTo _currentDisplay}) exitWith {};

[] call TAE_fnc_hudStopHandlers;
uiNamespace setVariable ["TAE_HUD_display", displayNull];
uiNamespace setVariable ["TAE_HUD_visible", false];
[true] call TAE_fnc_hudSetVanillaWeaponInfo;
[true] call TAE_fnc_hudSetVanillaStanceInfo;
uiNamespace setVariable ["TAE_HUD_savedVanillaInfo", nil];
