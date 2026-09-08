params ["_display"];

uiNamespace setVariable ["TAE_HUD_display", _display];
uiNamespace setVariable ["TAE_HUD_visible", true];

[_display] call TAE_fnc_hudInitCompassControls;
[_display] call TAE_fnc_hudInitSquadControls;
[] call TAE_fnc_hudApplyFont;
[] call TAE_fnc_hudApplyColor;
[] call TAE_fnc_hudApplyPanelSettings;
[] call TAE_fnc_hudUpdate;
[] call TAE_fnc_hudUpdateCompass;
