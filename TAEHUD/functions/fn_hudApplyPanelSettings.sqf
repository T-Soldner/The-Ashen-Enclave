private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display) exitWith {};

private _showSystem = missionNamespace getVariable ["TAE_HUD_showSystem", true];
{(_display displayCtrl _x) ctrlShow _showSystem;} forEach [1100, 1101];
private _showAccents = missionNamespace getVariable ["TAE_HUD_showAccents", true];
{(_display displayCtrl _x) ctrlShow _showAccents;} forEach [1204, 1205];

private _showCompass = missionNamespace getVariable ["TAE_HUD_showCompass", true];
{(_display displayCtrl _x) ctrlShow _showCompass;} forEach [1200, 1201, 1110, 1111, 1490];
for "_index" from 0 to 8 do
{
	(_display displayCtrl (1400 + _index)) ctrlShow _showCompass;
	(_display displayCtrl (1500 + _index)) ctrlShow _showCompass;
};
// Dynamic markers decide their own visibility only when the compass is enabled.
if (!_showCompass) then
{
	for "_index" from 0 to 14 do {(_display displayCtrl (1600 + _index)) ctrlShow false;};
	(_display displayCtrl 1690) ctrlShow false;
};
[] call TAE_fnc_hudStartHandlers;
[] call TAE_fnc_hudUpdate;
[] call TAE_fnc_hudUpdateCompass;
