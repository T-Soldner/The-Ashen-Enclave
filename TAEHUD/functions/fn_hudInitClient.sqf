if (missionNamespace getVariable ["TAE_HUD_initialized", false]) exitWith {};
missionNamespace setVariable ["TAE_HUD_initialized", true];

uiNamespace setVariable ["TAE_HUD_userEnabled", missionNamespace getVariable ["TAE_HUD_autoEnable", true]];
uiNamespace setVariable ["TAE_HUD_suspended", false];
uiNamespace setVariable ["TAE_HUD_auxiliaryMode", missionNamespace getVariable ["TAE_HUD_auxiliaryDisplay", 0]];
uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", 0];
uiNamespace setVariable ["TAE_HUD_updatePFH", -1];
uiNamespace setVariable ["TAE_HUD_compassPFH", -1];
uiNamespace setVariable ["TAE_HUD_auxiliaryPFH", -1];
uiNamespace setVariable ["TAE_HUD_auxiliaryPFHMode", 0];

private _playerEventHandler = [
	"unit",
	{
		params ["_unit"];
		[_unit] call TAE_fnc_hudBindPlayerEvents;
		[] call TAE_fnc_hudPublishIdentityColor;
		[] call TAE_fnc_hudMonitor;
	},
	true
] call CBA_fnc_addPlayerEventHandler;
uiNamespace setVariable ["TAE_HUD_playerEventHandler", _playerEventHandler];

[
	missionNamespace,
	"arsenalOpened",
	{
		uiNamespace setVariable ["TAE_HUD_suspended", true];
		[] call TAE_fnc_hudHide;
	}
] call BIS_fnc_addScriptedEventHandler;

[
	missionNamespace,
	"arsenalClosed",
	{
		uiNamespace setVariable ["TAE_HUD_suspended", false];
		[] call TAE_fnc_hudMonitor;
	}
] call BIS_fnc_addScriptedEventHandler;

[
	"ace_arsenal_displayOpened",
	{
		uiNamespace setVariable ["TAE_HUD_suspended", true];
		[] call TAE_fnc_hudHide;
	}
] call CBA_fnc_addEventHandler;

[
	"ace_arsenal_displayClosed",
	{
		uiNamespace setVariable ["TAE_HUD_suspended", false];
		[] call TAE_fnc_hudMonitor;
	}
] call CBA_fnc_addEventHandler;

private _monitorPFH = [{[] call TAE_fnc_hudMonitor;}, 2] call CBA_fnc_addPerFrameHandler;
uiNamespace setVariable ["TAE_HUD_monitorPFH", _monitorPFH];

[] call TAE_fnc_hudMonitor;
