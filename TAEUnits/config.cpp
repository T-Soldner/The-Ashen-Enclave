class CfgPatches {
	class TAEUnits_HouseKarr {
		name = "House Karr";
		author = "TAE Mod Team";
		requiredVersion = 1.0;
		requiredAddons[] = {
			"A3_Characters_F",
			"ace_common",
			"ace_medical_treatment",
			"cba_xeh",
			"TAEUniforms",
			"TAEGear_Armors_Customs",
			"TAEGear_Helmets_Customs",
			"TAEGear_Backpacks",
			"TAEWeapons"
		};
		units[] = {
			"TAE_Unit_Veteran",
			"TAE_Unit_Engineer",
			"TAE_Unit_Medic",
			"TAE_Unit_Marksman",
			"TAE_Unit_AT_AA",
			"TAE_Unit_Grenadier",
			"TAE_Unit_CQC_Specialist",
			"TAE_Unit_Heavy_Weapons",
			"TAE_Unit_Sniper",
			"TAE_Unit_Player_Acklay",
			"TAE_Unit_Player_Foxx",
			"TAE_Unit_Player_Rook",
			"TAE_Unit_Player_Varen",
			"TAE_Unit_Player_Foundling",
			"TAE_Unit_Player_Freelancer",
			"TAE_Unit_BSC_Rifleman",
			"TAE_Unit_BSC_Heavy_Gunner",
			"TAE_Unit_BSC_Grenadier",
			"TAE_Unit_BSC_Missile_Specialist"
		};
		weapons[] = {};
	};
};

class CBA_Extended_EventHandlers_base;

class CfgFactionClasses {
	class TAE_Faction_HouseKarr {
		displayName = "House Karr";
		side = 2;
		priority = 2;
	};

	class TAE_Faction_Criminals {
		displayName = "[TAE] Criminals";
		side = 2;
		priority = 2;
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Infantry {
		displayName = "Infantry";
	};

	class TAE_EdSubcat_HouseKarr_Players {
		displayName = "Mandalorians";
	};

	class TAE_EdSubcat_BlackSpireCartel {
		displayName = "Black Spire Cartel";
	};
};

class CfgWorlds {
	class GenericNames {
		class TAE_GenericNames_HouseKarr {
			class FirstNames {
				tae_karr_first_01 = "Edonn";
				tae_karr_first_02 = "Nox";
				tae_karr_first_03 = "Varik";
				tae_karr_first_04 = "Tor";
				tae_karr_first_05 = "Vesh";
				tae_karr_first_06 = "Rook";
				tae_karr_first_07 = "Cev";
				tae_karr_first_08 = "Drayk";
				tae_karr_first_09 = "Jaro";
				tae_karr_first_10 = "Renn";
				tae_karr_first_11 = "Keth";
				tae_karr_first_12 = "Vorr";
				tae_karr_first_13 = "Talon";
				tae_karr_first_14 = "Drenn";
				tae_karr_first_15 = "Mavik";
				tae_karr_first_16 = "Zev";
				tae_karr_first_17 = "Aren";
				tae_karr_first_18 = "Kodan";
				tae_karr_first_19 = "Ravik";
				tae_karr_first_20 = "Jax";
			};

			class LastNames {
				tae_karr_last_01 = "Karr";
				tae_karr_last_02 = "Ordo";
				tae_karr_last_03 = "Vhett";
				tae_karr_last_04 = "Krayt";
				tae_karr_last_05 = "Solus";
				tae_karr_last_06 = "Rancor";
				tae_karr_last_07 = "Vorn";
				tae_karr_last_08 = "Tal";
				tae_karr_last_09 = "Mereel";
				tae_karr_last_10 = "Skirata";
				tae_karr_last_11 = "Kelborn";
				tae_karr_last_12 = "Tavos";
				tae_karr_last_13 = "Dral";
				tae_karr_last_14 = "Kast";
				tae_karr_last_15 = "Vizla";
				tae_karr_last_16 = "Veshok";
				tae_karr_last_17 = "Cadera";
				tae_karr_last_18 = "Rau";
				tae_karr_last_19 = "Akaan";
				tae_karr_last_20 = "Besk";
			};
		};
	};
};

class CfgVehicles {
	class I_Soldier_F;

	class TAE_Unit_HitPoint_Base: I_Soldier_F {
		scope = 0;
		scopeCurator = 0;

		ALiVE_orbatCreator_loadout[] = {};
		ALiVE_orbatCreator_owned = 1;

		class EventHandlers {
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			class ALiVE_orbatCreator {
				init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0; sleep 0.2; _backpack = getText (configFile >> 'CfgVehicles' >> (typeOf _this) >> 'backpack'); waitUntil {sleep 0.2; backpack _this == _backpack}; if !(_this getVariable ['ALiVE_OverrideLoadout', false]) then {_loadout = getArray (configFile >> 'CfgVehicles' >> (typeOf _this) >> 'ALiVE_orbatCreator_loadout'); if (count _loadout > 0) then {_this setUnitLoadout _loadout; reload _this};}; _this setSpeaker 'ACE_NoVoice';}; _this spawn _onSpawn; (_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
			};
		};

		class HitPoints {
			class HitFace {
				armor = 5;
				material = -1;
				name = "face_hub";
				passThrough = 0.8;
				radius = 0.08;
				explosionShielding = 0.1;
				minimalHit = 0.01;
			};
			class HitNeck {
				armor = 5;
				material = -1;
				name = "neck";
				passThrough = 0.8;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0.01;
			};
			class HitHead {
				armor = 5;
				material = -1;
				name = "head";
				passThrough = 0.8;
				radius = 0.2;
				explosionShielding = 0.5;
				minimalHit = 0.01;
				depends = "HitFace max HitNeck";
			};
			class ACE_HDBracket {
				armor = 1;
				material = -1;
				name = "head";
				passThrough = 0;
				radius = 1;
				explosionShielding = 1;
				visual = "";
				minimalHit = 0;
				depends = "HitHead";
			};
			class HitPelvis {
				armor = 6;
				material = -1;
				name = "pelvis";
				passThrough = 0.8;
				radius = 0.24;
				explosionShielding = 0.1;
				visual = "injury_body";
				minimalHit = 0.01;
				depends = "0";
			};
			class HitAbdomen {
				armor = 6;
				material = -1;
				name = "spine1";
				passThrough = 0.8;
				radius = 0.16;
				explosionShielding = 0.1;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitDiaphragm {
				armor = 6;
				material = -1;
				name = "spine2";
				passThrough = 0.8;
				radius = 0.18;
				explosionShielding = 0.25;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitChest {
				armor = 6;
				material = -1;
				name = "spine3";
				passThrough = 0.8;
				radius = 0.18;
				explosionShielding = 0.25;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitBody {
				armor = 1000;
				material = -1;
				name = "body";
				passThrough = 1;
				radius = 0;
				explosionShielding = 0.25;
				visual = "injury_body";
				minimalHit = 0.01;
				depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms {
				armor = 6;
				material = -1;
				name = "arms";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.3;
				visual = "injury_hands";
				minimalHit = 0.01;
				depends = "0";
			};
			class HitHands {
				armor = 6;
				material = -1;
				name = "hands";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.3;
				visual = "injury_hands";
				minimalHit = 0.01;
				depends = "HitArms";
			};
			class HitLegs {
				armor = 6;
				material = -1;
				name = "legs";
				passThrough = 1;
				radius = 0.14;
				explosionShielding = 0.3;
				visual = "injury_legs";
				minimalHit = 0.01;
				depends = "0";
			};
			class Incapacitated {
				armor = 1000;
				material = -1;
				name = "body";
				passThrough = 1;
				radius = 0;
				explosionShielding = 0.1;
				visual = "";
				minimalHit = 0;
				depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm {
				armor = 6;
				material = -1;
				name = "hand_l";
				passThrough = 1;
				radius = 0.08;
				explosionShielding = 0.1;
				visual = "injury_hands";
				minimalHit = 0.01;
			};
			class HitRightArm {
				armor = 6;
				material = -1;
				name = "hand_r";
				passThrough = 1;
				radius = 0.08;
				explosionShielding = 0.1;
				visual = "injury_hands";
				minimalHit = 0.01;
			};
			class HitLeftLeg {
				armor = 6;
				material = -1;
				name = "leg_l";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.1;
				visual = "injury_legs";
				minimalHit = 0.01;
			};
			class HitRightLeg {
				armor = 6;
				material = -1;
				name = "leg_r";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.1;
				visual = "injury_legs";
				minimalHit = 0.01;
			};
		};
		armor = 2;
		armorStructural = 4;
		explosionShielding = 0.4;
		minTotalDamageThreshold = 0.001;
		impactDamageMultiplier = 0.5;
	};

	class TAE_Unit_Base: TAE_Unit_HitPoint_Base {
		scope = 0;
		scopeCurator = 0;
		author = "TAE Mod Team";
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Infantry";
		editorPreview = "\TAEUnits\data\previews\Karr.paa";
		side = 2;
		genericNames = "TAE_GenericNames_HouseKarr";

		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"G_NATO_default"
		};

		icon = "iconMan";
		uniformClass = "tae_uniform_grey_seal";
		goggles = "tgf_facewear_medium_belt";

		weapons[] = {
			"LFP_westarcarabine",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"LFP_westarcarabine",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mv",
			"tae_karr_helmet_mv",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mv",
			"tae_karr_helmet_mv",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		items[] = {
			"MineDetector",
			"ACE_MapTools",
			"ACE_Flashlight_XL50",
			"ACE_EntrenchingTool",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"MTI_catTab_tablet",
			"ACE_IR_Strobe_Item"
		};

		respawnItems[] = {
			"MineDetector",
			"ACE_MapTools",
			"ACE_Flashlight_XL50",
			"ACE_EntrenchingTool",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"MTI_catTab_tablet",
			"ACE_IR_Strobe_Item"
		};
	};

	class TAE_Unit_Player_Base: TAE_Unit_Base {
		scope = 0;
		scopeCurator = 0;
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Players";
		displayName = "Mandalorian";
		uniformClass = "tae_uniform_grey_seal";
		backpack = "";
		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"NoGlasses"
		};

		weapons[] = {};
		respawnWeapons[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		items[] = {};
		respawnItems[] = {};
		goggles = "";

		linkedItems[] = {
			"ItemMap"
		};
		respawnLinkedItems[] = {
			"ItemMap"
		};

		ALiVE_orbatCreator_loadout[] = {{},{},{},{"tae_uniform_grey_seal",{}},{},{},"","",{},{"ItemMap","","ls_radios_hush98","","",""}};
	};

	class TAE_Unit_Player_Acklay: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Acklay Member";
		uniformClass = "tae_uniform_ls_mandalorian";

		ALiVE_orbatCreator_loadout[] = {{},{},{},{"tae_uniform_ls_mandalorian",{}},{},{},"","",{},{"ItemMap","","ls_radios_hush98","","",""}};
	};

	class TAE_Unit_Player_Foxx: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Foxx Member";
		uniformClass = "tae_uniform_grey_seal";
	};

	class TAE_Unit_Player_Rook: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Rook Member";
		uniformClass = "tae_uniform_grey_seal";
	};

	class TAE_Unit_Player_Varen: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Varen Member";
		uniformClass = "tae_uniform_black_seal";

		ALiVE_orbatCreator_loadout[] = {{},{},{},{"tae_uniform_black_seal",{}},{},{},"","",{},{"ItemMap","","ls_radios_hush98","","",""}};
	};

	class TAE_Unit_Player_Foundling: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 0;
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Players";
		displayName = "Foundling";
		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack";
		weapons[] = {
			"LFP_westarcarabine",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"LFP_westarcarabine",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};
		magazines[] = {
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag"
		};
		respawnMagazines[] = {
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag"
		};
		linkedItems[] = {
			"tae_karr_armor_medium_fd",
			"tae_karr_helmet_fd",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};
		respawnLinkedItems[] = {
			"tae_karr_armor_medium_fd",
			"tae_karr_helmet_fd",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};
		goggles = "";

		ALiVE_orbatCreator_loadout[] = {{{"LFP_westarcarabine","","","LFP_westarcarabine_scopesn",{"LFP_westarcarabine_Mag",60},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_fd",{{"LFP_westarcarabine_Mag",20,60},{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_fd","",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Player_Freelancer: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Freelancer";
		uniformClass = "tae_uniform_grey_seal";
	};

	class TAE_Unit_Veteran: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Veteran";
		backpack = "tae_modular_pack_lr";

		ALiVE_orbatCreator_loadout[] = {{{"LFP_westarcarabine","","","",{"LFP_westarcarabine_Mag",60},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mv",{{"LFP_westarcarabine_Mag",20,60},{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1}}},{"tae_modular_pack_lr",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mv","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Engineer: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Engineer";
		icon = "iconManEngineer";
		backpack = "tae_modular_pack_engi";

		engineer = 1;
		canDeactivateMines = 1;
		detectSkill = 80;
		explosiveSpecialist = 1;
		ACE_IsEngineer = 1;
		ACE_isEOD = 1;

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"LFP_westarcarabine","","","",{"LFP_westarcarabine_Mag",60},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1},{"ACE_M26_Clacker",1}}},{"tae_karr_armor_medium_mm",{{"LFP_westarcarabine_Mag",20,60},{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1}}},{"tae_modular_pack_engi",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ToolKit",1},{"ACE_painkillers",2,10},{"RTX_RemoteMagazine",3,1}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Medic: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Medic";
		icon = "iconManMedic";
		backpack = "tae_modular_pack";

		attendant = 1;
		ace_medical_medicClass = 1;

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"LFP_westarcarabine","","","",{"LFP_westarcarabine_Mag",60},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mm",{{"LFP_westarcarabine_Mag",20,60},{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",5},{"ACE_splint",6},{"ACE_salineIV_500",5},{"ACE_salineIV",5},{"ACE_morphine",10},{"ACE_epinephrine",10},{"ACE_adenosine",10},{"MTI_BactaPatch",30},{"MTI_BactaSpray",30},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Marksman: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Marksman";
		icon = "iconManRecon";
		backpack = "tae_modular_pack";

		weapons[] = {
			"JMSLLTE_T21BBlasterRifle",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"JMSLLTE_T21BBlasterRifle",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"JMSLLTE_T21B_7rnd_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"JLTS_DW32S","","","",{"JLTS_DW32S_mag",10},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mm",{{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1},{"JLTS_DW32S_mag",10,10},{"LFP_Westar35_Mag",5,20}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_AT_AA: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "AT/AA";
		icon = "iconManAT";
		backpack = "tae_modular_pack";

		weapons[] = {
			"LFP_westarcarabine",
			"JMSLLTE_HH12_launcher",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"LFP_westarcarabine",
			"JMSLLTE_HH12_launcher",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AA_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AA_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"LFP_westarcarabine","","","",{"LFP_westarcarabine_Mag",60},{},""},{"JMSLLTE_HH12_launcher","","","",{"JMSLLTE_HH12_AT_Mag",1},{},""},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1},{"LFP_westarcarabine_Mag",14,60},{"3AS_ThermalDetonator",4,1}}},{"tae_karr_armor_medium_mm",{{"MTI_BactaSpray",20},{"MTI_BactaPatch",20},{"ACE_adenosine",5},{"ACE_epinephrine",5},{"ACE_morphine",5},{"ACE_salineIV",3},{"ACE_salineIV_500",3},{"ACE_splint",4},{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"LFP_westarcarabine_Mag",6,60},{"3AS_ThermalDetonator",1,1},{"3AS_SmokeWhite",5,1},{"ACE_painkillers",2,10}}},{"tae_modular_pack",{{"JMSLLTE_HH12_AT_Mag",3,1},{"JMSLLTE_HH12_AA_Mag",1,1}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Grenadier: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Grenadier";
		icon = "iconManExplosive";
		backpack = "tae_modular_pack";

		weapons[] = {
			"IDA_E10_UGL",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"IDA_E10_UGL",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"IDA_HE_LauncherGrenade",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"IDA_E10_UGL","","acc_flashlight","IDA_E11_scope",{"IDA_Blaster_Cell_Power3_40Rnd_Red",40},{"IDA_HE_LauncherGrenade",1},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mm",{{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1},{"IDA_HE_LauncherGrenade",5,1},{"IDA_Blaster_Cell_Power3_40Rnd_Red",10,40},{"LFP_Westar35_Mag",4,20}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_CQC_Specialist: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "CQC Specialist";
		icon = "iconMan";
		backpack = "tae_modular_pack";

		weapons[] = {
			"3AS_DP23_F",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"3AS_DP23_F",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_ESlug_Mag",
			"3AS_10Rnd_ESlug_Mag",
			"3AS_10Rnd_ESlug_Mag",
			"3AS_10Rnd_ESlug_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_ESlug_Mag",
			"3AS_10Rnd_ESlug_Mag",
			"3AS_10Rnd_ESlug_Mag",
			"3AS_10Rnd_ESlug_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"3AS_DP23_F","","","",{"3AS_10Rnd_EC30_Pellets",10},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mm",{{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1},{"LFP_Westar35_Mag",4,20},{"3AS_10Rnd_EC30_Pellets",10,10}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Heavy_Weapons: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Heavy Weapons";
		icon = "iconManMG";
		backpack = "tae_modular_pack";

		weapons[] = {
			"3AS_DLT19",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"3AS_DLT19",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"3AS_DLT19","","","3AS_Imp_Optic_2",{"3AS_200Rnd_EM40_DLT19_Mag",200},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mm",{{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1},{"LFP_Westar35_Mag",4,20},{"3AS_200Rnd_EM40_DLT19_Mag",10,200}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};

	class TAE_Unit_Sniper: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Sniper";
		icon = "iconManRecon";
		backpack = "tae_modular_pack";

		weapons[] = {
			"IDA_Galaar90",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		respawnWeapons[] = {
			"IDA_Galaar90",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};

		magazines[] = {
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		respawnMagazines[] = {
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"IDA_Blaster_Cell_Power5_5Rnd_Yellow",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite"
		};

		linkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		respawnLinkedItems[] = {
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_rangefinder_r"
		};

		ALiVE_orbatCreator_loadout[] = {{{"tae_IQA12","","","tae_TargetingScope_FP2",{"IDA_Blaster_Cell_Power5_5Rnd_Yellow",5},{},""},{},{"LFP_Westar_35","","","",{"LFP_Westar35_Mag",20},{},""}},{"tae_uniform_grey_seal",{{"MineDetector",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_EntrenchingTool",1},{"ACE_CableTie",5},{"MTI_catTab_tablet",1},{"ACE_IR_Strobe_Item",1}}},{"tae_karr_armor_medium_mm",{{"3AS_ThermalDetonator",5,1},{"3AS_SmokeWhite",5,1},{"LFP_Westar35_Mag",4,20},{"IDA_Blaster_Cell_Power5_5Rnd_Yellow",10,5}}},{"tae_modular_pack",{{"ACE_surgicalKit",1},{"ACE_tourniquet",4},{"ACE_splint",4},{"ACE_salineIV_500",3},{"ACE_salineIV",3},{"ACE_morphine",5},{"ACE_epinephrine",5},{"ACE_adenosine",5},{"MTI_BactaPatch",20},{"MTI_BactaSpray",20},{"ACE_painkillers",2,10}}},"tae_karr_helmet_mm","tgf_facewear_medium_belt",{"JMSLLTE_W_TD23_white_F","","","",{},{},""},{"ItemMap","ItemGPS","ls_radios_hush98","ItemCompass","ItemWatch","tgf_nvg_rangefinder_r"}};
	};
	class TAE_Unit_BSC_Base: TAE_Unit_HitPoint_Base {
		scope = 0;
		scopeCurator = 0;
		author = "TAE Mod Team";
		faction = "TAE_Faction_Criminals";
		editorSubcategory = "TAE_EdSubcat_BlackSpireCartel";
		editorPreview = "\TAEUnits\data\previews\Karr.paa";
		side = 2;
		genericNames = "TAE_GenericNames_HouseKarr";
		identityTypes[] = {"LanguageENG_F","Head_NATO","NoGlasses"};
		icon = "iconMan";
		uniformClass = "ls_imperialUniform_army_r_black";
		backpack = "JMSLLTE_back_rebpack_v1_black";
		weapons[] = {"3AS_DC15S_F","JMSLLTE_dt12pistol","Throw","Put"};
		respawnWeapons[] = {"3AS_DC15S_F","JMSLLTE_dt12pistol","Throw","Put"};
		magazines[] = {"3AS_60Rnd_EC30_mag","JMSLLTE_DT12_50rnd_Mag"};
		respawnMagazines[] = {"3AS_60Rnd_EC30_mag","JMSLLTE_DT12_50rnd_Mag"};
		linkedItems[] = {"ls_imperialVest_army_light_black_h","IDA_Clone_Elite_Trooper_P2_Helmet","ItemMap","TFAR_anprc148jem","ItemCompass","ItemWatch"};
		respawnLinkedItems[] = {"ls_imperialVest_army_light_black_h","IDA_Clone_Elite_Trooper_P2_Helmet","ItemMap","TFAR_anprc148jem","ItemCompass","ItemWatch"};
		items[] = {"ACE_fieldDressing","ACE_packingBandage","ACE_morphine","ACE_tourniquet"};
		respawnItems[] = {"ACE_fieldDressing","ACE_packingBandage","ACE_morphine","ACE_tourniquet"};
	};

	class TAE_Unit_BSC_Rifleman: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Rifleman";
		role = "Rifleman";

		ALiVE_orbatCreator_loadout[] = {{{"3AS_DC15S_F","","","",{"3AS_60Rnd_EC30_mag",60},{},""},{},{"JMSLLTE_dt12pistol","","","",{"JMSLLTE_DT12_50rnd_Mag",50},{},""}},{"ls_imperialUniform_army_r_black",{{"ACE_fieldDressing",1},{"ACE_packingBandage",1},{"ACE_morphine",1},{"ACE_tourniquet",1},{"JMSLLTE_thermaldetonator_HandGrenade",2,1}}},{"ls_imperialVest_army_light_black_h",{{"3AS_ThermalDetonator",2,1},{"3AS_SmokeWhite",3,1},{"JMSLLTE_DT12_50rnd_Mag",2,50},{"3AS_5Rnd_Stun_Mag",2,5},{"3AS_60Rnd_EC30_mag",10,60}}},{"JMSLLTE_back_rebpack_v1_black",{{"FirstAidKit",10}}},"IDA_Clone_Elite_Trooper_P2_Helmet","",{},{"ItemMap","","TFAR_anprc148jem","ItemCompass","ItemWatch",""}};
	};

	class TAE_Unit_BSC_Heavy_Gunner: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Heavy Gunner";
		role = "MachineGunner";
		weapons[] = {"3AS_Z6_F","JMSLLTE_dt12pistol","Throw","Put"};
		respawnWeapons[] = {"3AS_Z6_F","JMSLLTE_dt12pistol","Throw","Put"};
		magazines[] = {"3AS_300Rnd_EC60_Mag","JMSLLTE_DT12_50rnd_Mag"};
		respawnMagazines[] = {"3AS_300Rnd_EC60_Mag","JMSLLTE_DT12_50rnd_Mag"};

		ALiVE_orbatCreator_loadout[] = {{{"3AS_Z6_F","","","",{"3AS_300Rnd_EC60_Mag",300},{},""},{},{"JMSLLTE_dt12pistol","","","",{"JMSLLTE_DT12_50rnd_Mag",50},{},""}},{"ls_imperialUniform_army_r_black",{{"ACE_fieldDressing",1},{"ACE_packingBandage",1},{"ACE_morphine",1},{"ACE_tourniquet",1},{"JMSLLTE_thermaldetonator_HandGrenade",2,1}}},{"ls_imperialVest_army_light_black_h",{{"3AS_ThermalDetonator",2,1},{"3AS_SmokeWhite",3,1},{"JMSLLTE_DT12_50rnd_Mag",2,50},{"3AS_5Rnd_Stun_Mag",2,5},{"3AS_300Rnd_EC60_Mag",2,300}}},{"JMSLLTE_back_rebpack_v1_black",{{"FirstAidKit",10}}},"IDA_Clone_Elite_Trooper_P2_Helmet","",{},{"ItemMap","","TFAR_anprc148jem","ItemCompass","ItemWatch",""}};
	};

	class TAE_Unit_BSC_Grenadier: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Grenadier";
		role = "Grenadier";
		weapons[] = {"3AS_DC15S_GL","JMSLLTE_dt12pistol","Throw","Put"};
		respawnWeapons[] = {"3AS_DC15S_GL","JMSLLTE_dt12pistol","Throw","Put"};

		ALiVE_orbatCreator_loadout[] = {{{"3AS_DC15S_GL","","","",{"3AS_60Rnd_EC30_mag",60},{"3AS_3Rnd_HE_Grenade_shell",3},""},{},{"JMSLLTE_dt12pistol","","","",{"JMSLLTE_DT12_50rnd_Mag",50},{},""}},{"ls_imperialUniform_army_r_black",{{"ACE_fieldDressing",1},{"ACE_packingBandage",1},{"ACE_morphine",1},{"ACE_tourniquet",1},{"JMSLLTE_thermaldetonator_HandGrenade",2,1}}},{"ls_imperialVest_army_light_black_h",{{"3AS_ThermalDetonator",2,1},{"3AS_SmokeWhite",3,1},{"JMSLLTE_DT12_50rnd_Mag",2,50},{"3AS_5Rnd_Stun_Mag",2,5},{"3AS_60Rnd_EC30_mag",8,60},{"3AS_3Rnd_HE_Grenade_shell",4,3}}},{"JMSLLTE_back_rebpack_v1_black",{{"FirstAidKit",10}}},"IDA_Clone_Elite_Trooper_P2_Helmet","",{},{"ItemMap","","TFAR_anprc148jem","ItemCompass","ItemWatch",""}};
	};

	class TAE_Unit_BSC_Missile_Specialist: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Missile Specialist";
		role = "MissileSpecialist";
		weapons[] = {"3AS_DC15S_F","3AS_PLX1_F","JMSLLTE_dt12pistol","Throw","Put"};
		respawnWeapons[] = {"3AS_DC15S_F","3AS_PLX1_F","JMSLLTE_dt12pistol","Throw","Put"};
		magazines[] = {"3AS_60Rnd_EC30_mag","3AS_JLTS_MK43_AT","JMSLLTE_DT12_50rnd_Mag"};
		respawnMagazines[] = {"3AS_60Rnd_EC30_mag","3AS_JLTS_MK43_AT","JMSLLTE_DT12_50rnd_Mag"};

		ALiVE_orbatCreator_loadout[] = {{{"3AS_DC15S_F","","","",{"3AS_60Rnd_EC30_mag",60},{},""},{"3AS_PLX1_F","","","",{"3AS_JLTS_MK43_AT",1},{},""},{"JMSLLTE_dt12pistol","","","",{"JMSLLTE_DT12_50rnd_Mag",50},{},""}},{"ls_imperialUniform_army_r_black",{{"ACE_fieldDressing",1},{"ACE_packingBandage",1},{"ACE_morphine",1},{"ACE_tourniquet",1},{"JMSLLTE_thermaldetonator_HandGrenade",2,1}}},{"ls_imperialVest_army_light_black_h",{{"3AS_ThermalDetonator",2,1},{"3AS_SmokeWhite",3,1},{"JMSLLTE_DT12_50rnd_Mag",2,50},{"3AS_5Rnd_Stun_Mag",2,5},{"3AS_60Rnd_EC30_mag",10,60}}},{"JMSLLTE_back_rebpack_v1_black",{{"FirstAidKit",10},{"3AS_JLTS_MK43_AT",1,1}}},"IDA_Clone_Elite_Trooper_P2_Helmet","",{},{"ItemMap","","TFAR_anprc148jem","ItemCompass","ItemWatch",""}};
	};
};

class CfgGroups {
	class Indep {
		name = "Independent";

		class TAE_Faction_HouseKarr {
			name = "House Karr";

			class Infantry {
				name = "Infantry";

				class TAE_Group_Squad {
					name = "Squad";
					side = 2;
					faction = "TAE_Faction_HouseKarr";
					icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";

					class Unit0 {
						side = 2;
						vehicle = "TAE_Unit_Veteran";
						rank = "SERGEANT";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 2;
						vehicle = "TAE_Unit_Engineer";
						rank = "CORPORAL";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 2;
						vehicle = "TAE_Unit_Medic";
						rank = "CORPORAL";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 2;
						vehicle = "TAE_Unit_Marksman";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};

					class Unit4 {
						side = 2;
						vehicle = "TAE_Unit_AT_AA";
						rank = "PRIVATE";
						position[] = {-10, -10, 0};
					};

					class Unit5 {
						side = 2;
						vehicle = "TAE_Unit_Grenadier";
						rank = "PRIVATE";
						position[] = {15, -15, 0};
					};

					class Unit6 {
						side = 2;
						vehicle = "TAE_Unit_CQC_Specialist";
						rank = "PRIVATE";
						position[] = {-15, -15, 0};
					};

					class Unit7 {
						side = 2;
						vehicle = "TAE_Unit_Heavy_Weapons";
						rank = "PRIVATE";
						position[] = {20, -20, 0};
					};

					class Unit8 {
						side = 2;
						vehicle = "TAE_Unit_Sniper";
						rank = "PRIVATE";
						position[] = {-20, -20, 0};
					};
				};

				class TAE_Group_Fireteam {
					name = "Fireteam";
					side = 2;
					faction = "TAE_Faction_HouseKarr";
					icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";

					class Unit0 {
						side = 2;
						vehicle = "TAE_Unit_Veteran";
						rank = "SERGEANT";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 2;
						vehicle = "TAE_Unit_Medic";
						rank = "CORPORAL";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 2;
						vehicle = "TAE_Unit_Marksman";
						rank = "PRIVATE";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 2;
						vehicle = "TAE_Unit_AT_AA";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};
				};

				class TAE_Group_Sentry {
					name = "Sentry";
					side = 2;
					faction = "TAE_Faction_HouseKarr";
					icon = "\A3\ui_f\data\map\markers\nato\n_recon.paa";

					class Unit0 {
						side = 2;
						vehicle = "TAE_Unit_Marksman";
						rank = "CORPORAL";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 2;
						vehicle = "TAE_Unit_Grenadier";
						rank = "PRIVATE";
						position[] = {5, -5, 0};
					};
				};
			};

			class Players {
				name = "Mandalorians";

				class TAE_Group_Mandalorians {
					name = "Mandalorians";
					side = 2;
					faction = "TAE_Faction_HouseKarr";
					icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";

					class Unit0 {
						side = 2;
						vehicle = "TAE_Unit_Player_Acklay";
						rank = "PRIVATE";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 2;
						vehicle = "TAE_Unit_Player_Foxx";
						rank = "PRIVATE";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 2;
						vehicle = "TAE_Unit_Player_Rook";
						rank = "PRIVATE";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 2;
						vehicle = "TAE_Unit_Player_Varen";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};

					class Unit4 {
						side = 2;
						vehicle = "TAE_Unit_Player_Foundling";
						rank = "PRIVATE";
						position[] = {-10, -10, 0};
					};

					class Unit5 {
						side = 2;
						vehicle = "TAE_Unit_Player_Freelancer";
						rank = "PRIVATE";
						position[] = {-15, -15, 0};
					};
				};
			};
		};

		class TAE_Faction_Criminals {
			name = "[TAE] Criminals";

			class BlackSpireCartel {
				name = "Black Spire Cartel";

				class TAE_Group_BSC_Team {
					name = "Cartel Team";
					side = 2;
					faction = "TAE_Faction_Criminals";
					icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";

					class Unit0 {
						side = 2;
						vehicle = "TAE_Unit_BSC_Rifleman";
						rank = "SERGEANT";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 2;
						vehicle = "TAE_Unit_BSC_Heavy_Gunner";
						rank = "PRIVATE";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 2;
						vehicle = "TAE_Unit_BSC_Grenadier";
						rank = "PRIVATE";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 2;
						vehicle = "TAE_Unit_BSC_Missile_Specialist";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};
				};
			};
		};
	};
};
