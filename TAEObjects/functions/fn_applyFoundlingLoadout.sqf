params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {
	[_unit] remoteExecCall ["TAE_fnc_applyFoundlingLoadout", _unit];
};

private _loadout = [
	["LFP_westarcarabine", "", "", "LFP_westarcarabine_scopesn", ["LFP_westarcarabine_Mag", 60], [], ""],
	[],
	["LFP_Westar_35", "", "", "", ["LFP_Westar35_Mag", 20], [], ""],
	["tae_uniform_grey_seal", [
		["MineDetector", 1],
		["ACE_MapTools", 1],
		["ACE_Flashlight_XL50", 1],
		["ACE_EntrenchingTool", 1],
		["ACE_CableTie", 5],
		["ACE_IR_Strobe_Item", 1]
	]],
	["tae_karr_armor_medium_fd", [
		["LFP_westarcarabine_Mag", 20, 60],
		["3AS_ThermalDetonator", 5, 1],
		["3AS_SmokeWhite", 5, 1]
	]],
	["tae_modular_pack", [
		["ACE_surgicalKit", 1],
		["ACE_tourniquet", 4],
		["ACE_splint", 4],
		["ACE_salineIV_500", 3],
		["ACE_salineIV", 3],
		["ACE_morphine", 5],
		["ACE_epinephrine", 5],
		["ACE_adenosine", 5],
		["MTI_BactaPatch", 20],
		["MTI_BactaSpray", 20],
		["ACE_painkillers", 2, 10]
	]],
	"tae_karr_helmet_fd",
	"",
	["JMSLLTE_W_TD23_white_F", "", "", "", [], [], ""],
	["ItemMap", "ItemGPS", "ls_radios_hush98", "ItemCompass", "ItemWatch", "tgf_nvg_rangefinder_r"]
];

_unit setUnitLoadout _loadout;
if (uniform _unit == "") then {
	_unit forceAddUniform "tae_uniform_grey_seal";
};
removeGoggles _unit;
