#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Discover loaded fonts with the same exclusions used by DUI.
private _hudFonts = ('!(configName _x in ["EtelkaMonospaceProBold", "EtelkaNarrowMediumPro", "TahomaB", "PixelSplitterBold"])' configClasses (configFile >> "CfgFontFamilies")) apply {configName _x};
private _defaultFont = _hudFonts find "ls_republic";
if (_defaultFont < 0) then {_defaultFont = (_hudFonts find "RobotoCondensed") max 0;};

[
	"TAE_HUD_font", "LIST",
	["HUD Font", "Choose the font for all helmet HUD labels."],
	["The Ashen Enclave", "Helmet HUD"],
	[_hudFonts, _hudFonts, _defaultFont],
	2,
	{[] call TAE_fnc_hudApplyFont;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_enabled",
	"CHECKBOX",
	["Helmet HUD Enabled", "Enables the Ashen Enclave helmet HUD."],
	["The Ashen Enclave", "Helmet HUD"],
	true,
	0,
	{[] call TAE_fnc_hudMonitor;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_autoEnable",
	"CHECKBOX",
	["Enable When Equipped", "Automatically restores the HUD when a supported helmet is equipped."],
	["The Ashen Enclave", "Helmet HUD"],
	true,
	0,
	{[] call TAE_fnc_hudMonitor;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_color",
	"COLOR",
	["HUD Color", "Controls the color of the helmet HUD."],
	["The Ashen Enclave", "Helmet HUD"],
	[0.95, 0.72, 0.14, 0.90],
	2,
	{[] call TAE_fnc_hudApplyColor;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_identityColor",
	"COLOR",
	["Clan/House Link Personal Color", "Controls the color teammates see for your name or number and direction marker."],
	["The Ashen Enclave", "Helmet HUD"],
	[0.95, 0.72, 0.14, 0.95],
	2,
	{[] call TAE_fnc_hudPublishIdentityColor;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_squadDisplay",
	"LIST",
	["Clan/House Link Display", "Choose full names or a narrower numbered layout on your HUD only."],
	["The Ashen Enclave", "Helmet HUD"],
	[[0, 1], ["Full names", "Compact numbers"], 0],
	2,
	{[uiNamespace getVariable ["TAE_HUD_display", displayNull]] call TAE_fnc_hudUpdateSquad;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_squadNumber",
	"LIST",
	["Clan/House Link Personal Number", "Your number shown to teammates using Compact numbers. Coordinate numbers with your squad; duplicates are allowed."],
	["The Ashen Enclave", "Helmet HUD"],
	[[1, 2, 3, 4, 5, 6, 7, 8], ["1", "2", "3", "4", "5", "6", "7", "8"], 0],
	2,
	{[] call TAE_fnc_hudPublishIdentityColor;}
] call CBA_fnc_addSetting;

[
	"The Ashen Enclave",
	"TAE_HUD_Toggle",
	["Toggle Helmet HUD", "Toggles the Ashen Enclave helmet HUD."],
	{[] call TAE_fnc_hudToggle;},
	{},
	[DIK_TAB, [false, false, false]]
] call CBA_fnc_addKeybind;

{
	_x params ["_setting", "_label", "_description"];
	[
		_setting, "CHECKBOX", [_label, _description],
		["The Ashen Enclave", "Helmet HUD"], true, 2,
		{[] call TAE_fnc_hudApplyPanelSettings;}
	] call CBA_fnc_addSetting;
} forEach
[
	["TAE_HUD_showSystem", "Show System Labels", "Show the upper-left visor link and system status labels."],
	["TAE_HUD_showCompass", "Show Compass", "Show the compass, heading, squad markers and waypoint marker."],
	["TAE_HUD_showWeapon", "Show Weapon Panel", "Show the TAE weapon, ammunition, stance and equipment panel. When hidden, restore the native information displays."],
	["TAE_HUD_showSquad", "Show Clan/House Link", "Show the lower-left link list using your chosen name or number layout."],
	["TAE_HUD_showAccents", "Show Decorative Accents", "Show the upper-left and lower-left decorative lines."]
];

{
	_x params ["_setting", "_label"];
	[
		_setting, "LIST",
		[_label, "Choose a panel location. Panels sharing a location stack. Off stops this panel's processing."],
		["The Ashen Enclave", "Helmet HUD"],
		[[0, 1, 2, 3], ["Off", "Bottom Right", "Bottom Center", "Top Left"], 0],
		2,
		{[] call TAE_fnc_hudSyncAuxiliaryHandler;}
	] call CBA_fnc_addSetting;
} forEach [
	["TAE_HUD_mapLocation", "Map Location"],
	["TAE_HUD_cameraLocation", "Helmet Camera Location"],
	["TAE_HUD_trackerLocation", "Motion Tracker Location"]
];

[
	"TAE_HUD_linkView", "LIST",
	["Link View", "House Link shows other living same-side players designated as Clan Leaders while you are designated as one; otherwise Clan Link shows your own group."],
	["The Ashen Enclave", "Helmet HUD"],
	[[0, 1], ["Clan Link", "House Link (clan leaders)"], 0],
	2,
	{[] call TAE_fnc_hudUpdate;}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_clanLeader", "CHECKBOX",
	["Clan Leader", "Designate yourself as a Clan Leader for same-side House Link tracking and access. Does not change your Arma group leader."],
	["The Ashen Enclave", "Helmet HUD"],
	false,
	2,
	{
		[] call TAE_fnc_hudPublishIdentityColor;
		[] call TAE_fnc_hudUpdate;
	}
] call CBA_fnc_addSetting;

[
	"TAE_HUD_radarRange",
	"LIST",
	["Motion Tracker Range", "Detection radius of the motion tracker. Moving contacts and recent unsuppressed gunfire are shown."],
	["The Ashen Enclave", "Helmet HUD"],
	[[50, 100], ["50 m", "100 m"], 0],
	2,
	{[] call TAE_fnc_hudUpdateAuxiliary;}
] call CBA_fnc_addSetting;

[
	"The Ashen Enclave",
	"TAE_HUD_CycleCameraTarget",
	["Next Helmet Camera", "Selects the next living squad member for the helmet camera feed."],
	{[] call TAE_fnc_hudCycleCameraTarget;},
	{},
	[DIK_COMMA, [false, true, true]]
] call CBA_fnc_addKeybind;
