private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display) exitWith {};

private _font = missionNamespace getVariable ["TAE_HUD_font", "ls_republic"];
{
	if (ctrlType _x isEqualTo 0) then {_x ctrlSetFont _font;};
} forEach allControls _display;
