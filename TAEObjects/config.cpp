#include "cargo_macros.hpp"

#include "wearable_macros.hpp"

class CfgFactionClasses {
	class NO_CATEGORY;
	class TAE_Modules: NO_CATEGORY {
		displayName = "[TAE] Modules";
	};
};

class CfgPatches {
	class TAEObjects {
		name = "TAE Objects";
		author = "TAE Mod Team";
		requiredAddons[] = {
			"A3_Modules_F",
			"A3_Weapons_F",
			"A3_Misc_F_Helpers",
			"OPTRE_BW_Locker",
			"ace_interaction",
			"ace_interact_menu",
			"ace_arsenal",
			"ace_medical_treatment",
			"knd_medical",
			"ace_dragging",
			"ace_cargo",
			"TAEWeapons",
			"ls_compat_ace_flags",
			"ls_props",
			"cba_xeh",
			"JLTS_weapons_crates",
			"3AS_Props",
			"3AS_Prop_Droids",
			"3as_GNK_Prop",
			"3AS_Prop_Flags",
			"ls_characters_mandalorian",
			"ls_weapons_westar",
			"ls_weapons_zh73",
			"tgf_helmets",
			"TAEGear_Helmets_Customs",
			"TAEGear_Armors_Customs",
			"TAEDrones",
			"mti_armoury_props_locker",
			"SFA_Structure_Bed",
			"knd_crates",
			"knd_mortar"
		};
		units[] = {
			"TAE_AircraftTerminal",
			"TAE_Poster_HangInThere",
			"TAE_Restricted_Arsenal_Box",
			"TAE_Restricted_Arsenal_Locker",
			"TAE_Specialization_Gonk_Droid",
			"TAE_Medical_Droid",
			"TAE_Ammo_Crate",
			"TAE_AT_Crate",
			"TAE_GL_Crate",
			"TAE_Mortar_Crate",
			"TAE_JetpackFuel_Crate",
			"TAE_Demo_Crate",
			"TAE_Medical_Crate",
			"TAE_Bed_Acklay",
			"TAE_Bed_Foxx",
			"TAE_Bed_Varen",
			"TAE_Bed_Rook",
			"TAE_Bed_HouseKarr",
			"TAE_Bed_Shyyyo",
			"TAE_Bed_Kyram",
			"TAE_Vexillum_Acklay",
			"TAE_Vexillum_Foxx",
			"TAE_Vexillum_Varen",
			"TAE_Vexillum_Rook",
			"TAE_Vexillum_HouseKarr",
			"TAE_Vexillum_Shyyyo",
			"TAE_Vexillum_Kyram",
			"TAE_ClanFlag_Acklay",
			"TAE_ClanFlag_Foxx",
			"TAE_ClanFlag_HouseKarr",
			"TAE_ClanFlag_Kyram",
			"TAE_ClanFlag_Rook",
			"TAE_ClanFlag_Shyyyo",
			"TAE_ClanFlag_Varen",
			"TAE_MokTech_Locker",
			"TAE_Wearable_Acklay_Helmet",
			"TAE_Wearable_Foxx_Helmet",
			"TAE_Wearable_Varen_Helmet",
			"TAE_Wearable_Kyram_Helmet",
			"TAE_Wearable_Rook_Helmet",
			"TAE_Wearable_Freelancer_Helmet",
			"TAE_Wearable_Nox_Helmet",
			"TAE_Wearable_Hondo_Helmet",
			"TAE_Wearable_Edonn_Helmet",
			"TAE_Wearable_Shyyyo_Helmet"
		};
		weapons[] = {
			"TAE_BactaPatch_Box",
			"TAE_BactaSpray_Box",
			"TAE_ClanFlag_Acklay_Item",
			"TAE_ClanFlag_Foxx_Item",
			"TAE_ClanFlag_HouseKarr_Item",
			"TAE_ClanFlag_Kyram_Item",
			"TAE_ClanFlag_Rook_Item",
			"TAE_ClanFlag_Shyyyo_Item",
			"TAE_ClanFlag_Varen_Item"
		};
	};
};

class CfgEditorCategories {
	class TAE_EdCat_HouseKarr {
		displayName = "[TAE] House Karr Objects";
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_CapitalShips {
		displayName = "Capital Ships";
	};
	class TAE_EdSubcat_HouseKarr_ArsenalServices {
		displayName = "Arsenal and Services";
	};

	class TAE_EdSubcat_HouseKarr_Supplies {
		displayName = "Supplies";
	};

	class TAE_EdSubcat_HouseKarr_Vexillums {
		displayName = "Vexillums";
	};

	class TAE_EdSubcat_HouseKarr_Furniture {
		displayName = "Furniture";
	};

	class TAE_EdSubcat_HouseKarr_WearableItems {
		displayName = "Wearable Items";
	};
};

class CfgFunctions {
	class TAE {
		class Objects {
			file = "TAEObjects\functions";
			class moduleAircraftRequisition {};
			class isQualifiedAircraftPilot {};
			class initAircraftRequisition { postInit = 1; };
			class aircraftRequisitionRequest {};
			class repairAircraftOnPad {};
			class serviceAircraftOnPad {};
			class aircraftPylonMenu {};
			class aircraftStorageRequest {};
			class aircraftCrateMenu {};
			class aircraftCrateRequest {};
			class getResupplyCrateClasses {};
			class applyWearableLoadout {};
			class fullHealPlayer {};
			class initRestrictedArsenal {};
			class getArsenalItems {};
			class initAmmoCrate {};
			class setPlayerPermissions {};
		};
	};
};

class Extended_Init_EventHandlers {
	class TAE_GL_Crate {
		class TAEObjects_initAmmoCrate {
			init = "_this call TAE_fnc_initAmmoCrate";
		};
	};
	class TAE_AT_Crate {
		class TAEObjects_initAmmoCrate {
			init = "_this call TAE_fnc_initAmmoCrate";
		};
	};
	class TAE_Demo_Crate {
		class TAEObjects_initAmmoCrate {
			init = "_this call TAE_fnc_initAmmoCrate";
		};
	};
	class TAE_AircraftTerminal {
		class TAEObjects_aircraftTerminal {
			init = "if (!is3DEN) then {_this spawn {waitUntil {sleep 0.1; time > 0}; _this call TAE_fnc_moduleAircraftRequisition;};};";
		};
	};
	class TAE_Restricted_Arsenal_Locker {
		class TAEObjects_initRestrictedArsenal {
			init = "_this call TAE_fnc_initRestrictedArsenal";
		};
	};
	class TAE_Restricted_Arsenal_Box {
		class TAEObjects_initRestrictedArsenal {
			init = "_this call TAE_fnc_initRestrictedArsenal";
		};
	};

};

class ace_medical_replacementItems {
	TAE_BactaPatch_Box[] = {{"MTI_BactaPatch", 10}};
	TAE_BactaSpray_Box[] = {{"MTI_BactaSpray", 10}};
};

class CfgWeapons {
	class knd_medical_supplybox_more_bandages;
	class knd_medical_supplybox_more_bacta;
	class TAE_BactaPatch_Box: knd_medical_supplybox_more_bandages {
		picture = "\knd_medical\tex\supplybox\more_bacta_icon_co.paa";
		displayName = "Box of Bacta Patches (10)";
		descriptionShort = "Contains 10 MTI Bacta Patches. Unpacks automatically when taken.";
	};
	class TAE_BactaSpray_Box: knd_medical_supplybox_more_bacta {
		picture = "\TAEObjects\data\medical\bacta_spray_box_icon_co.paa";
		displayName = "Box of Bacta Sprays (10)";
		descriptionShort = "Contains 10 MTI Bacta Sprays. Unpacks automatically when taken.";
	};
	class ls_carrierFlag_mandalorian_item;

	class TAE_ClanFlag_Acklay_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (Clan Acklay)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_acklay_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_Acklay";
	};

	class TAE_ClanFlag_Foxx_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (Clan Foxx)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_foxx_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_Foxx";
	};


	class TAE_ClanFlag_HouseKarr_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (House Karr)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_house_karr_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_HouseKarr";
	};

	class TAE_ClanFlag_Kyram_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (Clan Kyr'am)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_kyram_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_Kyram";
	};

	class TAE_ClanFlag_Rook_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (Clan Rook)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_rook_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_Rook";
	};

	class TAE_ClanFlag_Shyyyo_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (Shyyyo)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_shyyyo_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_Shyyyo";
	};

	class TAE_ClanFlag_Varen_Item: ls_carrierFlag_mandalorian_item {
		author = "Legion Studios and Jimothy";
		displayName = "Flag (Clan Varen)";
		ace_flags_texture = "\TAEObjects\data\flags\flag_varen_ca.paa";
		ace_flags_carrier = "TAE_ClanFlag_Varen";
	};
};

class CfgVehicles {
	class ls_terminal_base;
	class Land_ls_terminal_01: ls_terminal_base { class Attributes; };
	class TAE_AircraftTerminal: Land_ls_terminal_01 {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Aircraft Terminal";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		class Attributes: Attributes {
			class TAE_TerminalMode {
				property = "TAE_TerminalMode";
				displayName = "Aircraft terminal mode";
				tooltip = "Pilot-only scroll actions. Aircraft spawn in front of this terminal; no pad or module is needed.";
				control = "Combo";
				typeName = "NUMBER";
				defaultValue = "1";
				expression = "_this setVariable ['TAE_terminalMode', _value];";
				class Values {
					class Disabled {name = "Off"; value = 0;};
					class Full {name = "Aircraft requisition and service"; value = 1;};
					class Service {name = "Service only"; value = 2;};
				};
			};
			class TAE_TerminalDistance {
				property = "TAE_TerminalDistance";
				displayName = "Spawn distance in front (metres)";
				tooltip = "Defaults to 40 metres. Automatically kept at least 6 metres beyond the clearance radius so the requesting pilot does not block spawning.";
				control = "Edit";
				typeName = "NUMBER";
				validate = "number";
				defaultValue = "40";
				expression = "_this setVariable ['TAE_spawnDistance', _value];";
			};
			class TAE_TerminalFacing {
				property = "TAE_TerminalFacing";
				displayName = "Aircraft facing";
				tooltip = "Aircraft heading relative to the terminal's Eden direction. Spawn position is always in front of the terminal.";
				control = "Combo";
				typeName = "NUMBER";
				defaultValue = "0";
				expression = "_this setVariable ['TAE_spawnFacing', _value];";
				class Values {
					class Forward {name = "Forward"; value = 0;};
					class Left {name = "Left"; value = 270;};
					class Right {name = "Right"; value = 90;};
					class Backwards {name = "Backwards"; value = 180;};
				};
			};
			class TAE_TerminalAircraft {
				property = "TAE_TerminalAircraft";
				displayName = "Aircraft classnames";
				tooltip = "Array of quoted classnames. [] uses House Karr aircraft. A supplied array replaces the defaults.";
				control = "Edit";
				typeName = "STRING";
                defaultValue = "'[""TAE_VWing"",""TAE_Delta7_Interceptor"",""TAE_KomrkFighter_Transport"",""TAE_Skycat_Transport"",""TAE_Z98_Headhunter""]'";
				expression = "_this setVariable ['Aircraft', _value];";
			};
			class TAE_TerminalRadius {
				property = "TAE_TerminalRadius";
				displayName = "Pad clearance radius (metres)";
				control = "Edit";
				typeName = "NUMBER";
				validate = "number";
				defaultValue = "30";
				expression = "_this setVariable ['Radius', _value];";
			};
			class TAE_TerminalRepairSeconds {
				property = "TAE_TerminalRepairSeconds";
				displayName = "Full repair duration (seconds)";
				control = "Edit";
				typeName = "NUMBER";
				validate = "number";
				defaultValue = "60";
				expression = "_this setVariable ['RepairSeconds', _value];";
			};
		};
	};
	class UserTexture1m_F;
	class TAE_Poster_HangInThere: UserTexture1m_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Poster (Hang In There)";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Furniture";
		hiddenSelectionsTextures[] = {"\TAEObjects\data\posters\hang_in_there_ca.paa"};
	};

	class JLTS_Ammobox_weapons_GAR;
	class JLTS_Ammobox_explosives_GAR;
	class JLTS_Ammobox_ammo_GAR;
	class 3AS_Small_Mando_Stand;
	class SFA_Bed_Single;
	class ThingX;
	class mti_armoury_props_locker_base;
	class 3as_GNK;
	class Land_3AS_Medical_Droid;
	class ls_carrierFlag_mandalorian;

	class TAE_ClanFlag_Acklay: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "Clan Acklay Flag";
	};

	class TAE_ClanFlag_Foxx: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "Clan Foxx Flag";
	};


	class TAE_ClanFlag_HouseKarr: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "House Karr Flag";
	};

	class TAE_ClanFlag_Kyram: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "Clan Kyr'am Flag";
	};

	class TAE_ClanFlag_Rook: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "Clan Rook Flag";
	};

	class TAE_ClanFlag_Shyyyo: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "Shyyyo Flag";
	};

	class TAE_ClanFlag_Varen: ls_carrierFlag_mandalorian {
		scope = 1;
		scopeCurator = 0;
		author = "Legion Studios and Jimothy";
		displayName = "Clan Varen Flag";
	};

	class TAE_Specialization_Gonk_Droid: 3as_GNK {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Specialization Gonk Droid";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;
		ace_interaction_canInteract = 1;

		class UserActions {
			class TAE_GrantEngineerPermissions {
				displayName = "<t color='#FF9F1A'>Receive Engineer and Explosives Permissions</t>";
				position = "";
				radius = 4;
				onlyForPlayer = 1;
				condition = "alive player";
				statement = "[player, 'engineer'] call TAE_fnc_setPlayerPermissions";
			};
			class TAE_GrantPilotPermissions {
				displayName = "<t color='#8877EE'>Receive Pilot and Engineer Permissions</t>";
				position = "";
				radius = 4;
				onlyForPlayer = 1;
				condition = "alive player";
				statement = "[player, 'pilot'] call TAE_fnc_setPlayerPermissions";
			};

			class TAE_GrantMedicalPermissions {
				displayName = "<t color='#4DA6FF'>Receive Medical Permissions</t>";
				position = "";
				radius = 4;
				onlyForPlayer = 1;
				condition = "alive player";
				statement = "[player, 'medic'] call TAE_fnc_setPlayerPermissions";
			};

			class TAE_RemoveAllPermissions {
				displayName = "<t color='#CCCCCC'>Remove All Permissions</t>";
				position = "";
				radius = 4;
				onlyForPlayer = 1;
				condition = "alive player";
				statement = "[player, 'none'] call TAE_fnc_setPlayerPermissions";
			};
		};

	};

	class TAE_Medical_Droid: Land_3AS_Medical_Droid {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Medical Droid";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;
		ace_interaction_canInteract = 1;

		class UserActions {
			class TAE_FullHeal {
				displayName = "<t color='#00FF66'>Full Heal</t>";
				position = "";
				radius = 4;
				onlyForPlayer = 1;
				condition = "alive player";
				statement = "[player] call TAE_fnc_fullHealPlayer";
			};
		};

	};

	class TAE_Bed_Base: SFA_Bed_Single {
		scope = 0;
		scopeCurator = 0;
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Furniture";
		hiddenSelections[] = {"camo1"};
	};

	class TAE_Bed_Acklay: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Acklay Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_acklay_co.paa"
		};
	};

	class TAE_Bed_Foxx: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Foxx Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_foxx_co.paa"
		};
	};

	class TAE_Bed_Varen: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Varen Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_varen_co.paa"
		};
	};

	class TAE_Bed_Rook: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Rook Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_rook_co.paa"
		};
	};

	class TAE_Bed_HouseKarr: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_karr_co.paa"
		};
	};

	class TAE_Bed_Shyyyo: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Shyyyo Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_shyyyo_co.paa"
		};
	};

	class TAE_Wearable_Helmet_Base: ThingX {
		scope = 0;
		scopeCurator = 0;
		displayName = "Wearable Helmet";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_WearableItems";
		model = "\ls\core\addons\characters_mandalorian\helmets\traditional\ls_helmet_mandalorian_traditional.p3d";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Acklay\LS_TRAD_Helmet_Acklay_co.paa",
			"\TAEGear\data\Acklay\LS_TRAD_Visor_Acklay_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		simulation = "thingX";
		armor = 50;

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_cargo_canLoad = 0;
		ace_cargo_size = -1;
		ace_cargo_noRename = 1;
	};

	class TAE_Wearable_Acklay_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Clan Acklay Helmet";

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnAcklayArmor, "Put On Acklay's Armor")
                    statement = "[_player,'tae_acklay_armor','tae_acklay_helmet','tae_ls_grey_rangefinder','','tae_uniform_ls_mandalorian'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnStasikArmor, "Put On Stasik's Armor")
                    statement = "[_player,'tae_stasik_armor','tae_stasik_helmet','tgf_nvg_rangefinder_r','','tae_uniform_black_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnJimothyArmor, "Put On Jimothy's Armor")
                    statement = "[_player,'tae_jimothy_armor','tae_jimothy_helmet','tae_jimothy_rangefinder','','tae_uniform_vau'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnFrenkArmor, "Put On Frenk's Armor")
                    statement = "[_player,'tae_frenk_armor','tae_frenk_helmet','tae_dark_grey_rangefinder','','tae_uniform_dark_green_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnTowiArmor, "Put On Towi's Armor")
                    statement = "[_player,'tae_towi_armor','tae_towi_helmet','tae_ls_grey_rangefinder','tae_facewear_ls_neck_lining','tae_uniform_black_female'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnBingoArmor, "Put On Bingo's Armor")
                    statement = "[_player,'tae_bingo_armor','tae_bingo_helmet','tgf_nvg_rangefinder_r','tae_facewear_ls_neck_lining','tae_uniform_ls_mandalorian'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNiteOwlArmor, "Put On Nite Owl's Armor")
                    statement = "[_player,'tae_acklay_niteowl_armor','tae_acklay_niteowl_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_black_female'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Foxx_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Clan Foxx Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Foxx\TRAD_Helmet_Foxx_co.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnFoxxArmor, "Put On Foxx's Armor")
                    statement = "[_player,'tae_foxx_armor','tae_foxx_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnJunoArmor, "Put On Juno's Armor")
                    statement = "[_player,'tae_juno_armor','tae_juno_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnBeanArmor, "Put On Bean's Armor")
                    statement = "[_player,'tae_foxx_armor','tae_bean_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnGreyArmor, "Put On Grey's Armor")
                    statement = "[_player,'tae_foxx_armor','tae_grey_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnGalaxyArmor, "Put On Galaxy's Armor")
                    statement = "[_player,'tae_galaxy_armor','tae_galaxy_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Varen_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Clan Varen Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Varen\TRAD_Helmet_Varen_co.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnVarenArmor, "Put On Varen's Armor")
                    statement = "[_player,'tae_varen_recon_armor','tae_varen_helmet','tae_dark_red_rangefinder','','tae_uniform_dark_red_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnVarenNiteOwlArmor, "Put On Varen's Nite Owl Armor")
                    statement = "[_player,'tae_varen_niteowl_armor','tae_varen_helmet','tae_dark_red_rangefinder','','tae_uniform_dark_red_female'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnValeriaArmor, "Put On Valeria's Armor")
                    statement = "[_player,'tae_varen_niteowl_armor','tae_valeria_helmet','tae_dark_red_rangefinder','','tae_uniform_dark_red_female'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnKeiraArmor, "Put On Keira's Armor")
                    statement = "[_player,'tae_varen_niteowl_armor','tae_keira_helmet','tae_dark_red_rangefinder','ls_glasses_scarf','tae_uniform_dark_red_female'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};


	class TAE_Bed_Kyram: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Kyr'am Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_kyram_co.paa"
		};
	};


	class TAE_Wearable_Kyram_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Clan Kyr'am Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Kyram\TRAD_Helmet_Kyram_co.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

                TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnKyramArmor, "Put On Clan Kyr'am Armor")
                    statement = "[_player,'tae_kyram_armor','tae_kyram_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };
                TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNovaArmor, "Put On Nova's Armor")
                    statement = "[_player,'tae_karr_armor_niteowl_ma','tae_nova_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_white_female'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Rook_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Clan Rook Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Rook\TRAD_Helmet_Rook_co.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnRookArmor, "Put On Rook's Armor")
                    statement = "[_player,'tae_rook_armor','tae_rook_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnHadesArmor, "Put On Hades' Armor")
                    statement = "[_player,'tae_hades_armor','tae_hades_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnVarioArmor, "Put On Vario's Armor")
                    statement = "[_player,'tae_vario_armor','tae_vario_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnAndoraArmor, "Put On Andora's Armor")
                    statement = "[_player,'tae_andora_armor','tae_andora_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_black_female'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnGoostivoolArmor, "Put On Goostivool's Armor")
                    statement = "[_player,'tae_goostivool_armor','tae_goostivool_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnShenArmor, "Put On Shen's Armor")
                    statement = "[_player,'tae_shen_armor','tae_shen_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Freelancer_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Freelancer Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Mando_co.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnRecruitArmor, "Put On Mandalorian Recruit's Armor")
                    statement = "[_player,'tae_karr_armor_medium_mr','tae_karr_helmet_mr','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnApprenticeArmor, "Put On Mandalorian Apprentice's Armor")
                    statement = "[_player,'tae_karr_armor_medium_ma','tae_karr_helmet_ma','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnMandalorianArmor, "Put On Mandalorian's Armor")
                    statement = "[_player,'tae_karr_armor_medium_mm','tae_karr_helmet_mm','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnVeteranArmor, "Put On Mandalorian Veteran's Armor")
                    statement = "[_player,'tae_karr_armor_medium_mv','tae_karr_helmet_mv','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNiteOwlRecruitArmor, "Put On Nite Owl Recruit's Armor")
                    statement = "[_player,'tae_karr_armor_niteowl_mr','tae_karr_helmet_niteowl_mr','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNiteOwlApprenticeArmor, "Put On Nite Owl Apprentice's Armor")
                    statement = "[_player,'tae_karr_armor_niteowl_ma','tae_karr_helmet_niteowl_ma','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
                };


				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNiteOwlMandalorianArmor, "Put On Nite Owl's Armor")
                    statement = "[_player,'tae_karr_armor_niteowl_mm','tae_karr_helmet_niteowl_mm','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNiteOwlVeteranArmor, "Put On Nite Owl Veteran's Armor")
                    statement = "[_player,'tae_karr_armor_niteowl_mv','tae_karr_helmet_niteowl_mv','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Nox_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nox Helmet";
		model = "\z\tgf\addons\helmets\warlord\warlord_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Nox\WAR_Helmet_Nox_co.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnNoxArmor, "Put On Nox's Armor")
                    statement = "[_player,'tae_nox_armor','tae_nox_helmet','','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Hondo_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Hondo Helmet";
		model = "\z\tgf\addons\helmets\battle_master\battle_master.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Hondo\BM_Helmet_Hondo_co.paa",
			"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnHondoArmor, "Put On Hondo's Armor")
                    statement = "[_player,'tae_hondo_armor','tae_hondo_helmet','','','tae_uniform_forgemaster_seal'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Edonn_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Edonn Helmet";
		model = "\ls\core\addons\characters_mandalorian\helmets\dinDjarin\ls_helmet_mandalorian_dinDjarin.p3d";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Edonn\LS_DIN_Helmet_Edonn_co.paa",
			"\TAEGear\data\Edonn\LS_DIN_Visor_Edonn_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		hiddenSelectionsMaterials[] = {
			"\TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.rvmat",
			"\TAEGear\data\Edonn\LS_DIN_Visor_Edonn.rvmat"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnEdonnArmor, "Put On Edonn's Armor")
                    statement = "[_player,'tae_edonn_armor','tae_edonn_helmet','tgf_nvg_circuit','','tae_uniform_ls_mandalorian'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_Wearable_Shyyyo_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Shyyyo Pilot Helmet";
		model = "\z\tgf\addons\helmets\pilot\pilot_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2","camo"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Shyyyo\PLT_Helmet_Shyyyo_co.paa",
			"\TAEGear\data\Shyyyo\PLT_Visor_Shyyyo_co.paa",
			"\TAEGear\data\Shyyyo\PLT_Lights_Shyyyo_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnTekaArmor, "Put On Teka's Armor")
                    statement = "[_player,'tae_teka_armor','tae_teka_helmet','','','tae_uniform_black_seal'] call TAE_fnc_applyWearableLoadout";
                };

				TAE_WEARABLE_ACTION_BEGIN(TAE_PutOnShyyyoArmor, "Put On Shyyyo's Armor")
                    statement = "[_player,'tae_shyyyo_recon_armor','tae_shyyyo_helmet','','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
                };
			};
		};
	};

	class TAE_MokTech_Locker: mti_armoury_props_locker_base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Locker";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Furniture";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsMaterials[] = {
			"",
			"\z\mti_armoury\addons\props\locker\data\base_texture\locker.rvmat"
		};
		hiddenSelectionsTextures[] = {
			"",
			"\z\mti_armoury\addons\props\locker\data\base_texture\locker_CO.paa"
		};
		editorPreview = "\z\mti_armoury\addons\props\locker\data\editorpreviews\locker_base.jpg";

		ace_interaction_canInteract = 0;

		class UserActions {};

		class ACE_Actions {
			class ACE_MainActions {
				condition = "false";
			};
		};
		class ACE_SelfActions {};
	};

	class TAE_Vexillum_Base: 3AS_Small_Mando_Stand {
		scope = 0;
		scopeCurator = 0;
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Vexillums";
		model = "3AS\3AS_Props\Flags\models\Small_Stand\3as_Small_Stand.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsMaterials[] = {
			"\TAEObjects\data\vexillums\tae_vexillum.rvmat"
		};
	};

	class TAE_Vexillum_Acklay: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Acklay Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_acklay_co.paa"
		};
	};

	class TAE_Vexillum_Foxx: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Foxx Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_foxx_co.paa"
		};
	};

	class TAE_Vexillum_Varen: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Varen Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_varen_co.paa"
		};
	};

	class TAE_Vexillum_Rook: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Rook Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_rook_co.paa"
		};
	};

	class TAE_Vexillum_HouseKarr: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Command Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_house_karr_co.paa"
		};
	};

	class TAE_Vexillum_Shyyyo: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Shyyyo Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_shyyyo_co.paa"
		};
	};

	class TAE_Vexillum_Kyram: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Kyr'am Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_kyram_co.paa"
		};
	};


	class OPTRE_Furniture_Locker;
	class TAE_Restricted_Arsenal_Locker: OPTRE_Furniture_Locker {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Personal Arsenal Locker";
		author = "Big_Wilk (OPTRE) and Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;
		armor = 4000;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_cargo_canLoad = 0;
		ace_cargo_size = -1;
		class ACE_Actions {
			class ACE_MainActions {
				distance = 8;
				position = "[0,0,0.9]";
				selection = "";
				displayName = "Interactions";
				condition = "true";
			};
		};
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		class TransportBackpacks {};
	};

	class TAE_Restricted_Arsenal_Box: JLTS_Ammobox_weapons_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Restricted ACE Arsenal";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;
		armor = 4000;
		hiddenSelectionsTextures[] = {
			"\MRC\JLTS\weapons\Crates\data\crate_1_GAR_co.paa",
			"\TAEObjects\data\screen_karr_arsenal_co.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_cargo_canLoad = 0;
		ace_cargo_size = -1;

		class ACE_Actions {
			class ACE_MainActions {
				distance = 6;
				position = "[0,0,0.9]";
				selection = "";
				displayName = "Interactions";
				condition = "true";
			};
		};

		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		class TransportBackpacks {};
	};

	class TAE_Ammo_Crate: JLTS_Ammobox_weapons_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Ammo Crate";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Supplies";
		side = 3;
		armor = 4000;
		model = "\knd_crates\cratemodel\NewCrate.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\ammo\camo1_co.paa"};
		editorPreview = "\knd_crates\tex\crates\thumbnail.paa";

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 4000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 2000;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};

		class TransportMagazines {};

		class TransportItems {
			TAE_CARGO(_xx_knd_crates_ammoTin_verySmall, name, "knd_crates_ammoTin_verySmall", 50)
			TAE_CARGO(_xx_knd_crates_ammoTin_small, name, "knd_crates_ammoTin_small", 50)
			TAE_CARGO(_xx_knd_crates_ammoTin_large, name, "knd_crates_ammoTin_large", 50)
		};
		class TransportBackpacks {};
	};

	class TAE_Demo_Crate: JLTS_Ammobox_explosives_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Demolition Crate";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Supplies";
		side = 3;
		armor = 4000;
		model = "\knd_crates\cratemodel\NewCrate.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\demo\camo1_co.paa"};
		editorPreview = "\knd_crates\tex\crates\thumbnail.paa";

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 2000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 1200;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};

		class TransportMagazines {};

		class TransportItems {
			TAE_CARGO(_xx_mti_armoury_props_misc_clacker_item, name, "mti_armoury_props_misc_clacker_item", 5)
			TAE_CARGO(_xx_ACE_DefusalKit, name, "ACE_DefusalKit", 5)
			TAE_CARGO(_xx_ACE_wirecutter, name, "ACE_wirecutter", 4)
		};

		class TransportBackpacks {};
	};

	class TAE_Medical_Crate: JLTS_Ammobox_ammo_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Medical Crate";
		author = "Edonn";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Supplies";
		side = 3;
		armor = 4000;
		model = "\knd_crates\cratemodel\NewCrate.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\medical\camo1_co.paa"};
		editorPreview = "\knd_crates\tex\crates\thumbnail.paa";

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 2000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 1200;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};
		class TransportMagazines {};

		class TransportItems {
			TAE_CARGO(_xx_ACE_tourniquet, name, "ACE_tourniquet", 40)
			TAE_CARGO(_xx_ACE_splint, name, "ACE_splint", 30)
			TAE_CARGO(_xx_ACE_morphine, name, "ACE_morphine", 30)
			TAE_CARGO(_xx_ACE_epinephrine, name, "ACE_epinephrine", 30)
			TAE_CARGO(_xx_ACE_adenosine, name, "ACE_adenosine", 20)
			TAE_CARGO(_xx_ACE_painkillers, name, "ACE_painkillers", 30)
			TAE_CARGO(_xx_mti_armoury_props_medical_Bacta_Item_1000, name, "mti_armoury_props_medical_Bacta_Item_1000", 20)
			TAE_CARGO(_xx_mti_armoury_props_medical_Bacta_Item_500, name, "mti_armoury_props_medical_Bacta_Item_500", 30)
			TAE_CARGO(_xx_mti_armoury_props_medical_Bacta_Item_250, name, "mti_armoury_props_medical_Bacta_Item_250", 30)
			TAE_CARGO(_xx_ACE_surgicalKit, name, "ACE_surgicalKit", 4)
			TAE_CARGO(_xx_adv_aceCPR_AED, name, "adv_aceCPR_AED", 5)
			TAE_CARGO(_xx_MTI_Medisensor, name, "MTI_Medisensor", 5)
			TAE_CARGO(_xx_TAE_BactaSpray_Box, name, "TAE_BactaSpray_Box", 20)
			TAE_CARGO(_xx_TAE_BactaPatch_Box, name, "TAE_BactaPatch_Box", 20)
			TAE_CARGO(_xx_MTI_BactaPatch, name, "MTI_BactaPatch", 30)
			TAE_CARGO(_xx_MTI_BactaSpray, name, "MTI_BactaSpray", 30)
		};

		class TransportBackpacks {};
	};
	class TAE_AT_Crate: TAE_Ammo_Crate {
		displayName = "House Karr Anti-Tank Crate";
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\at\camo1_co.paa"};
		class TransportItems {};
	};
	class TAE_GL_Crate: TAE_Ammo_Crate {
		displayName = "House Karr GL Ammo Case";
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\gadgets\camo1_co.paa"};
		class TransportItems {};
	};
	class TAE_Mortar_Crate: TAE_Ammo_Crate {
		displayName = "House Karr Mortar Crate";
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\mortar\camo1_co.paa"};
		class TransportItems {};
		class TransportWeapons {
			TAE_CARGO(_xx_knd_Mortar_carry, weapon, "knd_Mortar_carry", 2)
		};
		class TransportMagazines {
			TAE_CARGO(_xx_KND_82mm_HE_Carryable, magazine, "KND_82mm_HE_Carryable", 15)
			TAE_CARGO(_xx_KND_82mm_Smoke_Carryable, magazine, "KND_82mm_Smoke_Carryable", 5)
		};
	};
	class TAE_JetpackFuel_Crate: TAE_Ammo_Crate {
		displayName = "House Karr Jetpack Fuel Crate";
		hiddenSelectionsTextures[] = {"\knd_crates\tex\crates\jetpack\camo1_co.paa"};
		class TransportItems {
			TAE_CARGO(_xx_knd_jetpacks_fuelCan, name, "knd_jetpacks_fuelCan", 50)
		};
	};
};
