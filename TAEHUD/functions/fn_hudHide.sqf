if !(uiNamespace getVariable ["TAE_HUD_visible", false]) exitWith
{
	[true] call TAE_fnc_hudSetVanillaWeaponInfo;
	[true] call TAE_fnc_hudSetVanillaStanceInfo;
	uiNamespace setVariable ["TAE_HUD_savedVanillaInfo", nil];
};

("TAE_HUD_LAYER" call BIS_fnc_rscLayer) cutFadeOut 0.15;
[true] call TAE_fnc_hudSetVanillaWeaponInfo;
[true] call TAE_fnc_hudSetVanillaStanceInfo;
uiNamespace setVariable ["TAE_HUD_savedVanillaInfo", nil];
uiNamespace setVariable ["TAE_HUD_visible", false];
uiNamespace setVariable ["TAE_HUD_display", displayNull];
