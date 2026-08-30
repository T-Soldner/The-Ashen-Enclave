#include "\a3\editor_f\Data\Scripts\dikCodes.h"

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
	["Squad Link Personal Color", "Controls the color squadmates see for your name and direction marker."],
	["The Ashen Enclave", "Helmet HUD"],
	[0.95, 0.72, 0.14, 0.95],
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

[
	"The Ashen Enclave",
	"TAE_HUD_CycleAuxiliary",
	["Cycle Auxiliary Display", "Cycles the visor auxiliary display between off, GPS, and helmet camera modes."],
	{[] call TAE_fnc_hudCycleAuxiliary;},
	{},
	[DIK_PERIOD, [false, true, true]]
] call CBA_fnc_addKeybind;

[
	"The Ashen Enclave",
	"TAE_HUD_CycleCameraTarget",
	["Next Helmet Camera", "Selects the next living squad member for the helmet camera feed."],
	{[] call TAE_fnc_hudCycleCameraTarget;},
	{},
	[DIK_COMMA, [false, true, true]]
] call CBA_fnc_addKeybind;
