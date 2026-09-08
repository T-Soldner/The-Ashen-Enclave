if (!hasInterface) exitWith {};

private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display) exitWith {};

if ((uiNamespace getVariable ["TAE_HUD_updatePFH", -1]) < 0) then
{
	private _updatePFH = [{[] call TAE_fnc_hudUpdate;}, 0.10] call CBA_fnc_addPerFrameHandler;
	uiNamespace setVariable ["TAE_HUD_updatePFH", _updatePFH];
};

private _compassEnabled = missionNamespace getVariable ["TAE_HUD_showCompass", true];
private _existingCompass = uiNamespace getVariable ["TAE_HUD_compassPFH", -1];
if (!_compassEnabled && {_existingCompass >= 0}) then
{
	[_existingCompass] call CBA_fnc_removePerFrameHandler;
	uiNamespace setVariable ["TAE_HUD_compassPFH", -1];
};
if (_compassEnabled && {_existingCompass < 0}) then
{
	private _compassPFH = [{[] call TAE_fnc_hudUpdateCompass;}, 0] call CBA_fnc_addPerFrameHandler;
	uiNamespace setVariable ["TAE_HUD_compassPFH", _compassPFH];
};

[] call TAE_fnc_hudSyncAuxiliaryHandler;
