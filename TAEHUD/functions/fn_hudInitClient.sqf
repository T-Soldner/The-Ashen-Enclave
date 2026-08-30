if (missionNamespace getVariable ["TAE_HUD_initialized", false]) exitWith {};
missionNamespace setVariable ["TAE_HUD_initialized", true];

uiNamespace setVariable ["TAE_HUD_userEnabled", missionNamespace getVariable ["TAE_HUD_autoEnable", true]];
uiNamespace setVariable ["TAE_HUD_suspended", false];
uiNamespace setVariable ["TAE_HUD_auxiliaryMode", 0];
uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", 0];

[] call TAE_fnc_hudPublishIdentityColor;
player addEventHandler ["Respawn", {[] call TAE_fnc_hudPublishIdentityColor;}];

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

[{[] call TAE_fnc_hudMonitor;}, 0.25] call CBA_fnc_addPerFrameHandler;
[{[] call TAE_fnc_hudUpdate;}, 0.10] call CBA_fnc_addPerFrameHandler;
[{[] call TAE_fnc_hudUpdateAuxiliary;}, 0] call CBA_fnc_addPerFrameHandler;
[{[] call TAE_fnc_hudUpdateCompass;}, 0] call CBA_fnc_addPerFrameHandler;

[] call TAE_fnc_hudMonitor;
