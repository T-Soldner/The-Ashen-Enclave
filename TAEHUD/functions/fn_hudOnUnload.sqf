uiNamespace setVariable ["TAE_HUD_display", displayNull];
uiNamespace setVariable ["TAE_HUD_visible", false];
[true] call TAE_fnc_hudSetVanillaWeaponInfo;
[true] call TAE_fnc_hudSetVanillaStanceInfo;
uiNamespace setVariable ["TAE_HUD_savedVanillaInfo", nil];
[] call TAE_fnc_hudDestroyCamera;
