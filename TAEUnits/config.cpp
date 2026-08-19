class CfgPatches {
	class TAEUnits_HouseKarr {
		name = "[TAE] House Karr";
		author = "TAE Mod Team";
		requiredVersion = 1.0;
		requiredAddons[] = {
			"A3_Characters_F",
			"ace_common",
			"ace_medical_treatment",
			"cba_xeh",
			"ls_common",
			"TAEUniforms",
			"TAEGear_Armors_Customs",
			"TAEGear_Helmets_Customs",
			"TAEGear_Backpacks",
			"TAEWeapons",
			"JMSLLTE_civs_mod",
			"JMSLLTE_civ_vests_mod",
			"ls_characters",
			"ls_identities",
			"SFA_Races",
			"mti_factions_common",
			"mti_factions_civilian",
			"A3_Characters_F_Orange_Vests",
			"xs_female_xs_f_base_head",
			"JMSLLTE_Faction_name",
			"JMSLLTE_vehgr_AA2",
			"JMSLLTE_vehgr_ATST",
			"JMSLLTE_vehair_Ywing",
			"JMSLLTE_vehair_Uwing",
			"JMSLLTE_vehair_Xwing",
			"JMSLLTE_vehair_Awing"
		};
		units[] = {
			"TAE_Unit_Veteran",
			"TAE_Unit_Engineer",
			"TAE_Unit_Pilot",
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
			"TAE_Unit_Player_Shyyyo",
			"TAE_Unit_Player_Foundling",
			"TAE_Unit_Player_Freelancer",
			"TAE_Unit_BSC_Rifleman",
			"TAE_Unit_BSC_Heavy_Gunner",
			"TAE_Unit_BSC_Grenadier",
			"TAE_Unit_BSC_Missile_Specialist",
			"TAE_Unit_Nihil_Rifleman",
			"TAE_Unit_Nihil_AT_AA",
			"TAE_Unit_Nihil_Sniper",
			"TAE_Unit_Nihil_Heavy",
			"TAE_Unit_Nihil_Grenadier",
			"TAE_Unit_Nihil_Praetorian",
			"TAE_Unit_NR_Commando",
			"TAE_Unit_NR_Sergeant",
			"TAE_Unit_NR_Medic",
			"TAE_Unit_NR_AT",
			"TAE_Unit_NR_Heavy",
			"TAE_Unit_NR_Sniper",
			"TAE_Unit_NR_Marksman",
			"TAE_Unit_NR_Alien_Commando",
			"TAE_Unit_NR_Alien_Heavy",
			"TAE_Vehicle_NR_AA2",
			"TAE_Vehicle_NR_AA2_MkII",
			"TAE_Vehicle_NR_ATST",
			"TAE_Vehicle_NR_Ywing",
			"TAE_Vehicle_NR_Uwing",
			"TAE_Vehicle_NR_Xwing_CA2",
			"TAE_Vehicle_NR_Xwing_T70",
			"TAE_Vehicle_NR_Awing",
			"TAE_Unit_Civilian_Random"
		};
		weapons[] = {};
	};
};

class CfgFactionClasses {
	class TAE_Faction_HouseKarr {
		displayName = "[TAE] House Karr";
		side = 2;
		priority = 2;
	};

	class TAE_Faction_Criminals {
		displayName = "[TAE] Criminals";
		side = 2;
		priority = 2;
	};

	class TAE_Faction_NihilRaiders {
		displayName = "[TAE] Nihil Raider";
		side = 0;
		priority = 2;
	};

	class TAE_Faction_NewRepublic {
		displayName = "[TAE] New Republic";
		side = 0;
		priority = 2;
	};

	class TAE_Faction_Civilians {
		displayName = "[TAE] Civilians";
		side = 3;
		priority = 2;
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Infantry {
		displayName = "Mandalorians";
	};

	class TAE_EdSubcat_HouseKarr_Players {
		displayName = "Players";
	};

	class TAE_EdSubcat_BlackSpireCartel {
		displayName = "Black Spire Cartel";
	};

	class TAE_EdSubcat_NihilRaiders {
		displayName = "Nihil Raiders";
	};

	class TAE_EdSubcat_NewRepublic_Infantry {
		displayName = "Infantry";
	};

	class TAE_EdSubcat_NewRepublic_Speeders {
		displayName = "Speeders";
	};

	class TAE_EdSubcat_NewRepublic_Armored {
		displayName = "Walkers";
	};

	class TAE_EdSubcat_NewRepublic_Aircraft {
		displayName = "Aircraft";
	};

	class TAE_EdSubcat_Civilians {
		displayName = "Civilians";
	};
};

class CfgFunctions {
	class TAE {
		class Units {
			file = "TAEUnits\functions";
			class randomizeCivilian {};
		};
	};
};

class Extended_Init_EventHandlers {
	class TAE_Unit_Base {
		class TAE_applyMandalorianFacewear {
			init = "params ['_unit']; if (!local _unit) exitWith {}; if (getText (configOf _unit >> 'editorSubcategory') isEqualTo 'TAE_EdSubcat_HouseKarr_Infantry') then { _unit setVariable ['BIS_enableRandomization', false]; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Civilian_Random {
		class TAE_randomizeCivilian {
			init = "_this call TAE_fnc_randomizeCivilian";
		};
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

class CfgGlasses {
	class None;

	class TAE_NoFacewear: None {
		scope = 1;
		displayName = "TAE No Facewear";
		model = "";
		identityTypes[] = {"TAE_NoFacewear",1};
	};
};

class CfgVehicles {
	class tae_uniform_unit_grey_seal;
	class JMSLLTE_c_jumpsuit_blue_F;
	class JMSLLTE_scum_troop_trooper;
	class JMSLLTE_scum_troop_serg;
	class JMSLLTE_scum_troop_medic;
	class JMSLLTE_scum_troop_trooperAT;
	class JMSLLTE_scum_troop_trooperH;
	class JMSLLTE_scum_troop_snip;
	class JMSLLTE_scum_troop_marksman;
	class JMSLLTE_scum_troop_al_trooper;
	class JMSLLTE_scum_troop_al_trooperH;
	class JMSLLTE_O_veh_AA2_reb_F;
	class JMSLLTE_O_veh_AA2mk2_reb_F;
	class JMSLLTE_vehgr_ATST_reb_F;
	class JMSLLTE_YwingA4_veh_F;
	class JMSLLTE_UwingHeli_Reb_F;
	class JMSLLTE_XwingCA2_NR_veh_F;
	class JMSLLTE_XwingT70_veh_F;
	class JMSLLTE_Awing_NR_veh_F;

	class TAE_Unit_HitPoint_Base: tae_uniform_unit_grey_seal {
		scope = 0;
		scopeCurator = 0;
		goggles = "TAE_NoFacewear";

		class HitPoints {
			class HitFace {
				armor = 1;
				material = -1;
				name = "face_hub";
				passThrough = 0.8;
				radius = 0.08;
				explosionShielding = 0.1;
				minimalHit = 0.01;
			};
			class HitNeck {
				armor = 1;
				material = -1;
				name = "neck";
				passThrough = 0.8;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0.01;
			};
			class HitHead {
				armor = 1;
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
				explosionShielding = 1;
				visual = "injury_body";
				minimalHit = 0.01;
				depends = "0";
			};
			class HitAbdomen {
				armor = 1;
				material = -1;
				name = "spine1";
				passThrough = 0.8;
				radius = 0.16;
				explosionShielding = 1;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitDiaphragm {
				armor = 1;
				material = -1;
				name = "spine2";
				passThrough = 0.8;
				radius = 0.18;
				explosionShielding = 2.4;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitChest {
				armor = 1;
				material = -1;
				name = "spine3";
				passThrough = 0.8;
				radius = 0.18;
				explosionShielding = 2.4;
				visual = "injury_body";
				minimalHit = 0.01;
			};
			class HitBody {
				armor = 1000;
				material = -1;
				name = "body";
				passThrough = 1;
				radius = 0;
				explosionShielding = 2.4;
				visual = "injury_body";
				minimalHit = 0.01;
				depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms {
				armor = 5;
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
				armor = 5;
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
				armor = 5;
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
				explosionShielding = 1;
				visual = "";
				minimalHit = 0;
				depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm {
				armor = 5;
				material = -1;
				name = "hand_l";
				passThrough = 1;
				radius = 0.08;
				explosionShielding = 0.3;
				visual = "injury_hands";
				minimalHit = 0.01;
			};
			class HitRightArm: HitLeftArm {
				name = "hand_r";
			};
			class HitLeftLeg {
				armor = 5;
				material = -1;
				name = "leg_l";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.3;
				visual = "injury_legs";
				minimalHit = 0.01;
			};
			class HitRightLeg: HitLeftLeg {
				name = "leg_r";
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
			"Head_NATO"
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};



		goggles = "TAE_NoFacewear";
		uniformClass = "tae_uniform_grey_seal";
		weapons[] = {};
		respawnWeapons[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		respawnLinkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		items[] = {};
		respawnItems[] = {};
	};

	class TAE_Unit_Player_Acklay: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Acklay Member";

		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};
		goggles = "TAE_NoFacewear";
		uniformClass = "tae_uniform_ls_mandalorian";
		weapons[] = {};
		respawnWeapons[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		respawnLinkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		items[] = {};
		respawnItems[] = {};
	};

	class TAE_Unit_Player_Foxx: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Foxx Member";
		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};
		goggles = "TAE_NoFacewear";
		uniformClass = "tae_uniform_grey_seal";
		linkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		respawnLinkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
	};

	class TAE_Unit_Player_Rook: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Rook Member";
		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};
		goggles = "TAE_NoFacewear";
		uniformClass = "tae_uniform_grey_seal";
		linkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		respawnLinkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
	};

	class TAE_Unit_Player_Varen: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Varen Member";

		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};
		goggles = "TAE_NoFacewear";
		uniformClass = "tae_uniform_black_seal";
		weapons[] = {};
		respawnWeapons[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		respawnLinkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		items[] = {};
		respawnItems[] = {};
	};

	class TAE_Unit_Player_Shyyyo: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Shyyyo";
		role = "Crewman";
		icon = "ls_iconManPilot";
		nameSound = "veh_infantry_pilot_s";
		textPlural = "$STR_A3_nameSound_veh_infantry_pilot_p";
		textSingular = "$STR_A3_nameSound_veh_infantry_pilot_s";
		ls_common_pilot = 1;
		engineer = 1;
		canDeactivateMines = 1;
	};

	class TAE_Unit_Player_Foundling: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 0;
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Players";
		displayName = "Foundling";

		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};
		goggles = "TAE_NoFacewear";
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"LFP_westarcarabine_scopesn",
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
			"LFP_westarcarabine_scopesn",
			"tae_karr_armor_medium_fd",
			"tae_karr_helmet_fd",
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_Player_Freelancer: TAE_Unit_Player_Base {
		scope = 2;
		scopeCurator = 0;
		displayName = "Freelancer";
		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"TAE_NoFacewear"
		};
		goggles = "TAE_NoFacewear";
		uniformClass = "tae_uniform_grey_seal";
		linkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
		respawnLinkedItems[] = {
			"ItemMap",
			"ls_radios_hush98"
		};
	};

	class TAE_Unit_Pilot: TAE_Unit_Player_Foundling {
		scope = 2;
		scopeCurator = 2;
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Infantry";
		displayName = "Pilot";
		role = "Crewman";
		icon = "ls_iconManPilot";
		nameSound = "veh_infantry_pilot_s";
		textPlural = "$STR_A3_nameSound_veh_infantry_pilot_p";
		textSingular = "$STR_A3_nameSound_veh_infantry_pilot_s";
		ls_common_pilot = 1;
		engineer = 1;
		canDeactivateMines = 1;
		uniformClass = "tae_uniform_black_seal";
		backpack = "";
		goggles = "tgf_facewear_medium_belt";
		linkedItems[] = {
			"LFP_westarcarabine_scopesn",
			"tae_shyyyo_recon_armor",
			"tae_shyyyo_helmet",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_circuit"
		};
		respawnLinkedItems[] = {
			"LFP_westarcarabine_scopesn",
			"tae_shyyyo_recon_armor",
			"tae_shyyyo_helmet",
			"ItemMap",
			"ItemGPS",
			"ls_radios_hush98",
			"ItemCompass",
			"ItemWatch",
			"tgf_nvg_circuit"
		};
	};

	class TAE_Unit_Veteran: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Veteran";
		icon = "iconManOfficer";

		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack_lr";
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_Engineer: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Engineer";
		icon = "iconManEngineer";

		engineer = 1;
		canDeactivateMines = 1;
		detectSkill = 80;
		explosiveSpecialist = 1;
		ACE_IsEngineer = 1;
		ACE_isEOD = 1;



		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack_engi";
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"ACE_IR_Strobe_Item",
			"ACE_M26_Clacker",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ToolKit",
			"ACE_painkillers",
			"ACE_painkillers",
			"RTX_RemoteMagazine",
			"RTX_RemoteMagazine",
			"RTX_RemoteMagazine"
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
			"ACE_IR_Strobe_Item",
			"ACE_M26_Clacker",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ToolKit",
			"ACE_painkillers",
			"ACE_painkillers",
			"RTX_RemoteMagazine",
			"RTX_RemoteMagazine",
			"RTX_RemoteMagazine"
		};
	};

	class TAE_Unit_Medic: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Medic";
		icon = "iconManMedic";

		attendant = 1;
		ace_medical_medicClass = 1;



		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack_medic";
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_Marksman: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Marksman";
		icon = "iconManRecon";







		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack_marksman";
		goggles = "tgf_facewear_medium_belt";
		weapons[] = {
			"JLTS_DW32S",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"JLTS_DW32S",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};
		magazines[] = {
			"Laserbatteries",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
		};
		respawnMagazines[] = {
			"Laserbatteries",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
			"JLTS_DW32S_mag",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_AT_AA: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "AT/AA";
		icon = "iconManAT";







		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack";
		goggles = "tgf_facewear_medium_belt";
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
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AA_Mag"
		};
		respawnMagazines[] = {
			"Laserbatteries",
			"LFP_westarcarabine_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"LFP_westarcarabine_Mag",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AT_Mag",
			"JMSLLTE_HH12_AA_Mag"
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
			"ACE_IR_Strobe_Item",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_Grenadier: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Grenadier";
		icon = "iconManExplosive";







		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack_grenadier";
		goggles = "tgf_facewear_medium_belt";
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
			"Laserbatteries",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_HE_LauncherGrenade",
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
			"3AS_SmokeWhite",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
		};
		respawnMagazines[] = {
			"Laserbatteries",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_HE_LauncherGrenade",
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
			"3AS_SmokeWhite",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"IDA_Blaster_Cell_Power3_40Rnd_Red",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
		};
		linkedItems[] = {
			"acc_flashlight",
			"IDA_E11_scope",
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
			"acc_flashlight",
			"IDA_E11_scope",
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_CQC_Specialist: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "CQC Specialist";
		icon = "ls_iconManLeader";







		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack";
		goggles = "tgf_facewear_medium_belt";
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
			"Laserbatteries",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
		};
		respawnMagazines[] = {
			"Laserbatteries",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
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
			"ACE_IR_Strobe_Item",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"3AS_10Rnd_EC30_Pellets",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_Heavy_Weapons: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Heavy Weapons";
		icon = "ls_iconManSupportGunner";







		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack_heavy";
		goggles = "tgf_facewear_medium_belt";
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
			"Laserbatteries",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
		};
		respawnMagazines[] = {
			"Laserbatteries",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
			"3AS_200Rnd_EM40_DLT19_Mag",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag"
		};
		linkedItems[] = {
			"3AS_Imp_Optic_2",
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
			"3AS_Imp_Optic_2",
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
	};

	class TAE_Unit_Sniper: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Sniper";
		icon = "iconManRecon";







		uniformClass = "tae_uniform_grey_seal";
		backpack = "tae_modular_pack";
		goggles = "tgf_facewear_medium_belt";
		weapons[] = {
			"tae_IQA12",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"tae_IQA12",
			"LFP_Westar_35",
			"JMSLLTE_W_TD23_white_F",
			"Throw",
			"Put"
		};
		magazines[] = {
			"Laserbatteries",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green"
		};
		respawnMagazines[] = {
			"Laserbatteries",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
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
			"3AS_SmokeWhite",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"LFP_Westar35_Mag",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green",
			"IDA_Blaster_Cell_Power5_5Rnd_Green"
		};
		linkedItems[] = {
			"tae_TargetingScope_FP2",
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
			"tae_TargetingScope_FP2",
			"tae_karr_armor_medium_mm",
			"tae_karr_helmet_mm",
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
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
			"ACE_IR_Strobe_Item",
			"ACE_surgicalKit",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_splint",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV_500",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_salineIV",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_morphine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_epinephrine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"ACE_adenosine",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaPatch",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"MTI_BactaSpray",
			"ACE_painkillers",
			"ACE_painkillers"
		};
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
		identityTypes[] = {"LanguageENG_F","Head_NATO","TAE_NoFacewear"};
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

		uniformClass = "ls_imperialUniform_army_r_black";
		backpack = "JMSLLTE_back_rebpack_v1_black";
		weapons[] = {
			"3AS_DC15S_F",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"3AS_DC15S_F",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		magazines[] = {
			"3AS_60Rnd_EC30_mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag"
		};
		respawnMagazines[] = {
			"3AS_60Rnd_EC30_mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag"
		};
		linkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		items[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit"
		};
		respawnItems[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit"
		};
	};

	class TAE_Unit_BSC_Heavy_Gunner: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Heavy Gunner";
		role = "MachineGunner";

		uniformClass = "ls_imperialUniform_army_r_black";
		backpack = "JMSLLTE_back_rebpack_v1_black";
		weapons[] = {
			"3AS_Z6_F",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"3AS_Z6_F",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		magazines[] = {
			"3AS_300Rnd_EC60_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_300Rnd_EC60_Mag",
			"3AS_300Rnd_EC60_Mag"
		};
		respawnMagazines[] = {
			"3AS_300Rnd_EC60_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_300Rnd_EC60_Mag",
			"3AS_300Rnd_EC60_Mag"
		};
		linkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		items[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit"
		};
		respawnItems[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit"
		};
	};

	class TAE_Unit_BSC_Grenadier: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Grenadier";
		role = "Grenadier";

		uniformClass = "ls_imperialUniform_army_r_black";
		backpack = "JMSLLTE_back_rebpack_v1_black";
		weapons[] = {
			"3AS_DC15S_GL",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"3AS_DC15S_GL",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		magazines[] = {
			"3AS_60Rnd_EC30_mag",
			"3AS_3Rnd_HE_Grenade_shell",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_3Rnd_HE_Grenade_shell",
			"3AS_3Rnd_HE_Grenade_shell",
			"3AS_3Rnd_HE_Grenade_shell",
			"3AS_3Rnd_HE_Grenade_shell"
		};
		respawnMagazines[] = {
			"3AS_60Rnd_EC30_mag",
			"3AS_3Rnd_HE_Grenade_shell",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_3Rnd_HE_Grenade_shell",
			"3AS_3Rnd_HE_Grenade_shell",
			"3AS_3Rnd_HE_Grenade_shell",
			"3AS_3Rnd_HE_Grenade_shell"
		};
		linkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		items[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit"
		};
		respawnItems[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit"
		};
	};

	class TAE_Unit_BSC_Missile_Specialist: TAE_Unit_BSC_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Cartel Missile Specialist";
		role = "MissileSpecialist";

		uniformClass = "ls_imperialUniform_army_r_black";
		backpack = "JMSLLTE_back_rebpack_v1_black";
		weapons[] = {
			"3AS_DC15S_F",
			"3AS_PLX1_F",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"3AS_DC15S_F",
			"3AS_PLX1_F",
			"JMSLLTE_dt12pistol",
			"Throw",
			"Put"
		};
		magazines[] = {
			"3AS_60Rnd_EC30_mag",
			"3AS_JLTS_MK43_AT",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag"
		};
		respawnMagazines[] = {
			"3AS_60Rnd_EC30_mag",
			"3AS_JLTS_MK43_AT",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"JMSLLTE_thermaldetonator_HandGrenade",
			"3AS_ThermalDetonator",
			"3AS_ThermalDetonator",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"3AS_SmokeWhite",
			"JMSLLTE_DT12_50rnd_Mag",
			"JMSLLTE_DT12_50rnd_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_5Rnd_Stun_Mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag",
			"3AS_60Rnd_EC30_mag"
		};
		linkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[] = {
			"ls_imperialVest_army_light_black_h",
			"IDA_Clone_Elite_Trooper_P2_Helmet",
			"ItemMap",
			"TFAR_anprc148jem",
			"ItemCompass",
			"ItemWatch"
		};
		items[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"3AS_JLTS_MK43_AT"
		};
		respawnItems[] = {
			"ACE_fieldDressing",
			"ACE_packingBandage",
			"ACE_morphine",
			"ACE_tourniquet",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"FirstAidKit",
			"3AS_JLTS_MK43_AT"
		};
	};

	class TAE_Unit_Nihil_Base: TAE_Unit_HitPoint_Base {
		scope = 0;
		scopeCurator = 0;
		author = "TAE Mod Team";
		faction = "TAE_Faction_NihilRaiders";
		editorSubcategory = "TAE_EdSubcat_NihilRaiders";
		editorPreview = "\TAEUnits\data\previews\Karr.paa";
		side = 0;
		genericNames = "TAE_GenericNames_HouseKarr";
		identityTypes[] = {"LanguageENG_F","Head_NATO","TAE_NoFacewear"};
		icon = "iconMan";
		uniformClass = "JMSLLTE_ScumAlCommando_desert_F_CombatUniform";
		weapons[] = {"SFA_CZX5_Rifle","Throw","Put"};
		respawnWeapons[] = {"SFA_CZX5_Rifle","Throw","Put"};
		magazines[] = {"SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag"};
		respawnMagazines[] = {"SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag"};
		linkedItems[] = {"JMSLLTE_CommandosVest2_armor","SFA_Rep_TechMedic_Helmet","ItemMap","ItemWatch"};
		respawnLinkedItems[] = {"JMSLLTE_CommandosVest2_armor","SFA_Rep_TechMedic_Helmet","ItemMap","ItemWatch"};
		items[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
		respawnItems[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
	};

	class TAE_Unit_Nihil_Rifleman: TAE_Unit_Nihil_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nihil Rifleman";
		role = "Rifleman";
	};

	class TAE_Unit_Nihil_AT_AA: TAE_Unit_Nihil_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nihil AT/AA";
		role = "MissileSpecialist";
		uniformClass = "JMSLLTE_PirShirtS2_bg_F_CombatUniform";
		backpack = "SFA_Combat_eng_backpack";
		weapons[] = {"SFA_CZX5_Rifle","SFA_Guided_Onslaught_Launcher","Throw","Put"};
		respawnWeapons[] = {"SFA_CZX5_Rifle","SFA_Guided_Onslaught_Launcher","Throw","Put"};
		magazines[] = {"SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_Launcher_Guided_Mag","SFA_Launcher_Guided_Mag","SFA_Launcher_Guided_Mag","SFA_Launcher_Guided_Mag"};
		respawnMagazines[] = {"SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_HP_mag","SFA_Launcher_Guided_Mag","SFA_Launcher_Guided_Mag","SFA_Launcher_Guided_Mag","SFA_Launcher_Guided_Mag"};
		linkedItems[] = {"JMSLLTE_TrooperPouch_armor","SFA_Rep_Underworld_Helmet_REM","ItemMap","ItemWatch"};
		respawnLinkedItems[] = {"JMSLLTE_TrooperPouch_armor","SFA_Rep_Underworld_Helmet_REM","ItemMap","ItemWatch"};
		items[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
		respawnItems[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
	};

	class TAE_Unit_Nihil_Sniper: TAE_Unit_Nihil_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nihil Sniper";
		role = "Marksman";
		uniformClass = "JMSLLTE_PirCapt_black_F_CombatUniform";
		weapons[] = {"SFA_CZX5_Sniper","Throw","Put"};
		respawnWeapons[] = {"SFA_CZX5_Sniper","Throw","Put"};
		magazines[] = {"SFA_HP_Sniper_mag","SFA_HP_Sniper_mag","SFA_HP_Sniper_mag","SFA_HP_Sniper_mag"};
		respawnMagazines[] = {"SFA_HP_Sniper_mag","SFA_HP_Sniper_mag","SFA_HP_Sniper_mag","SFA_HP_Sniper_mag"};
		goggles = "G_JMSLLTE_Bandanna_jinata";
		linkedItems[] = {"JMSLLTE_NavytrooperHolster_armor","SFA_CZ13K_Helmet_Grenadier","ItemMap","ItemWatch","ls_nvg_goggles_orange"};
		respawnLinkedItems[] = {"JMSLLTE_NavytrooperHolster_armor","SFA_CZ13K_Helmet_Grenadier","ItemMap","ItemWatch","ls_nvg_goggles_orange"};
		items[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
		respawnItems[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
	};

	class TAE_Unit_Nihil_Heavy: TAE_Unit_Nihil_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nihil Heavy";
		role = "MachineGunner";
		uniformClass = "JMSLLTE_BHcom_hax_F_CombatUniform";
		backpack = "JMSLLTE_back_stcape";
		weapons[] = {"SFA_Heavy_Repeating_Blaster","Throw","Put"};
		respawnWeapons[] = {"SFA_Heavy_Repeating_Blaster","Throw","Put"};
		magazines[] = {"SFA_DRX40_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum"};
		respawnMagazines[] = {"SFA_DRX40_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum","SFA_V7_Drum"};
		linkedItems[] = {"JMSLLTE_BHcomArmor_red_armor","ItemMap","ItemWatch"};
		respawnLinkedItems[] = {"JMSLLTE_BHcomArmor_red_armor","ItemMap","ItemWatch"};
		items[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
		respawnItems[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
	};

	class TAE_Unit_Nihil_Grenadier: TAE_Unit_Nihil_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nihil Grenadier";
		role = "Grenadier";
		uniformClass = "JMSLLTE_HuttHeavy_brown_F_CombatUniform";
		weapons[] = {"ls_weapon_mpl57","Throw","Put"};
		respawnWeapons[] = {"ls_weapon_mpl57","Throw","Put"};
		magazines[] = {"ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF"};
		respawnMagazines[] = {"ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF","ls_magazine_3Rnd_40mw_G76_HEF"};
		linkedItems[] = {"LST_DSI_Vest_V1_Armor","SFA_Combat_Eng_Helmet","ItemMap","ItemRadio","ItemCompass","ItemWatch"};
		respawnLinkedItems[] = {"LST_DSI_Vest_V1_Armor","SFA_Combat_Eng_Helmet","ItemMap","ItemRadio","ItemCompass","ItemWatch"};
		items[] = {"FirstAidKit","JMSLLTE_thermaldetonator_HandGrenade","JMSLLTE_thermaldetonator_HandGrenade"};
		respawnItems[] = {"FirstAidKit","JMSLLTE_thermaldetonator_HandGrenade","JMSLLTE_thermaldetonator_HandGrenade"};
	};

	class TAE_Unit_Nihil_Praetorian: TAE_Unit_Nihil_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nihil Praetorian";
		role = "Rifleman";
		uniformClass = "LST_Merc_Uniform_Assasin";
		weapons[] = {"WBK_lightsaberOldRep_kyloStyle","Throw","Put"};
		respawnWeapons[] = {"WBK_lightsaberOldRep_kyloStyle","Throw","Put"};
		magazines[] = {"WBK_Cybercrystal"};
		respawnMagazines[] = {"WBK_Cybercrystal"};
		linkedItems[] = {"LST_Vest_Gray","LST_KredoSithHelmet","ItemMap","ItemWatch"};
		respawnLinkedItems[] = {"LST_Vest_Gray","LST_KredoSithHelmet","ItemMap","ItemWatch"};
		items[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
		respawnItems[] = {"JLTS_ids_rep_civ","JLTS_credits_100","JLTS_credits_100","ACE_HandFlare_Red","3AS_ThermalDetonator"};
	};

	class TAE_Unit_NR_Commando: JMSLLTE_scum_troop_trooper {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Commando";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
	};

	class TAE_Unit_NR_Sergeant: JMSLLTE_scum_troop_serg {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Sergeant";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
	};

	class TAE_Unit_NR_Medic: JMSLLTE_scum_troop_medic {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Medic";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
		magazines[] = {"JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag"};
		respawnMagazines[] = {"JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag","JMSLLTE_DH17_60Rnd_Mag"};
	};

	class TAE_Unit_NR_AT: JMSLLTE_scum_troop_trooperAT {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Commando AT";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
		magazines[] = {"JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag"};
		respawnMagazines[] = {"JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag","JMSLLTE_DH17_30Rnd_Mag"};
	};

	class TAE_Unit_NR_Heavy: JMSLLTE_scum_troop_trooperH {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Commando Heavy";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
		magazines[] = {"JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag"};
		respawnMagazines[] = {"JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag"};
	};

	class TAE_Unit_NR_Sniper: JMSLLTE_scum_troop_snip {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Sniper";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
		magazines[] = {"JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag"};
		respawnMagazines[] = {"JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DLT20a_10Rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag"};
	};

	class TAE_Unit_NR_Marksman: JMSLLTE_scum_troop_marksman {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Marksman";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
		magazines[] = {"JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag"};
		respawnMagazines[] = {"JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_A280CR_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag","JMSLLTE_DL18_20rnd_Mag"};
	};

	class TAE_Unit_NR_Alien_Commando: JMSLLTE_scum_troop_al_trooper {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Alien Commando";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
	};

	class TAE_Unit_NR_Alien_Heavy: JMSLLTE_scum_troop_al_trooperH {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic Alien Commando Heavy";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Infantry";
		magazines[] = {"JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag"};
		respawnMagazines[] = {"JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag","JMSLLTE_RT97C_150Rnd_Mag"};
	};

	class TAE_Vehicle_NR_AA2: JMSLLTE_O_veh_AA2_reb_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Speeders";
		crew = "TAE_Unit_NR_Commando";
		typicalCargo[] = {"TAE_Unit_NR_Commando"};
	};

	class TAE_Vehicle_NR_AA2_MkII: JMSLLTE_O_veh_AA2mk2_reb_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Speeders";
		crew = "TAE_Unit_NR_Commando";
		typicalCargo[] = {"TAE_Unit_NR_Commando"};
	};

	class TAE_Vehicle_NR_ATST: JMSLLTE_vehgr_ATST_reb_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "New Republic AT-ST";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Armored";
		crew = "TAE_Unit_NR_Commando";
		typicalCargo[] = {"TAE_Unit_NR_Commando"};
	};

	class TAE_Vehicle_NR_Ywing: JMSLLTE_YwingA4_veh_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "BTL-A4 Y-wing Starfighter";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Aircraft";
	};

	class TAE_Vehicle_NR_Uwing: JMSLLTE_UwingHeli_Reb_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "UT-60D U-wing Dropship";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Aircraft";
	};

	class TAE_Vehicle_NR_Xwing_CA2: JMSLLTE_XwingCA2_NR_veh_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "T-65C-A2 X-wing Starfighter";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Aircraft";
	};

	class TAE_Vehicle_NR_Xwing_T70: JMSLLTE_XwingT70_veh_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "T-70 X-wing Starfighter";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Aircraft";
	};

	class TAE_Vehicle_NR_Awing: JMSLLTE_Awing_NR_veh_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "RZ-1 A-wing Interceptor";
		faction = "TAE_Faction_NewRepublic";
		editorSubcategory = "TAE_EdSubcat_NewRepublic_Aircraft";
	};

	class TAE_Unit_Civilian_Random: JMSLLTE_c_jumpsuit_blue_F {
		scope = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Civilian (Random)";
		faction = "TAE_Faction_Civilians";
		editorSubcategory = "TAE_EdSubcat_Civilians";
		editorPreview = "\TAEUnits\data\previews\Karr.paa";
		side = 3;
		identityTypes[] = {"LanguageENG_F","Head_NATO","NoGlasses"};
		icon = "iconMan";
		uniformClass = "JMSLLTE_c_jumpsuit_blue_F_CombatUniform";
		weapons[] = {};
		respawnWeapons[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
		items[] = {};
		respawnItems[] = {};

	};
};

class CfgGroups {
	class East {
		name = "OPFOR";

		class TAE_Faction_NihilRaiders {
			name = "[TAE] Nihil Raider";

			class Infantry {
				name = "Infantry";

				class TAE_Group_Nihil_Fireteam {
					name = "Nihil Fireteam";
					side = 0;
					faction = "TAE_Faction_NihilRaiders";
					icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";

					class Unit0 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Heavy";
						rank = "CORPORAL";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};
				};

				class TAE_Group_Nihil_RaidParty {
					name = "Nihil Raid Party";
					side = 0;
					faction = "TAE_Faction_NihilRaiders";
					icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";

					class Unit0 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Praetorian";
						rank = "SERGEANT";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Heavy";
						rank = "CORPORAL";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_AT_AA";
						rank = "CORPORAL";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Sniper";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};

					class Unit4 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Grenadier";
						rank = "PRIVATE";
						position[] = {-10, -10, 0};
					};

					class Unit5 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {15, -15, 0};
					};

					class Unit6 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {-15, -15, 0};
					};

					class Unit7 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {20, -20, 0};
					};

					class Unit8 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {-20, -20, 0};
					};

					class Unit9 {
						side = 0;
						vehicle = "TAE_Unit_Nihil_Rifleman";
						rank = "PRIVATE";
						position[] = {25, -25, 0};
					};
				};
			};
		};

		class TAE_Faction_NewRepublic {
			name = "[TAE] New Republic";

			class Infantry {
				name = "Infantry";

				class TAE_Group_NR_Fireteam {
					name = "New Republic Fireteam";
					side = 0;
					faction = "TAE_Faction_NewRepublic";
					icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";

					class Unit0 {
						side = 0;
						vehicle = "TAE_Unit_NR_Sergeant";
						rank = "SERGEANT";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 0;
						vehicle = "TAE_Unit_NR_Commando";
						rank = "PRIVATE";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 0;
						vehicle = "TAE_Unit_NR_Commando";
						rank = "PRIVATE";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 0;
						vehicle = "TAE_Unit_NR_Heavy";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};
				};

				class TAE_Group_NR_Squad {
					name = "New Republic Squad";
					side = 0;
					faction = "TAE_Faction_NewRepublic";
					icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";

					class Unit0 {
						side = 0;
						vehicle = "TAE_Unit_NR_Sergeant";
						rank = "SERGEANT";
						position[] = {0, 0, 0};
					};

					class Unit1 {
						side = 0;
						vehicle = "TAE_Unit_NR_Commando";
						rank = "CORPORAL";
						position[] = {5, -5, 0};
					};

					class Unit2 {
						side = 0;
						vehicle = "TAE_Unit_NR_AT";
						rank = "PRIVATE";
						position[] = {-5, -5, 0};
					};

					class Unit3 {
						side = 0;
						vehicle = "TAE_Unit_NR_Medic";
						rank = "PRIVATE";
						position[] = {10, -10, 0};
					};

					class Unit4 {
						side = 0;
						vehicle = "TAE_Unit_NR_Heavy";
						rank = "PRIVATE";
						position[] = {-10, -10, 0};
					};

					class Unit5 {
						side = 0;
						vehicle = "TAE_Unit_NR_Marksman";
						rank = "PRIVATE";
						position[] = {15, -15, 0};
					};

					class Unit6 {
						side = 0;
						vehicle = "TAE_Unit_NR_Sniper";
						rank = "PRIVATE";
						position[] = {-15, -15, 0};
					};

					class Unit7 {
						side = 0;
						vehicle = "TAE_Unit_NR_Alien_Commando";
						rank = "PRIVATE";
						position[] = {20, -20, 0};
					};
				};
			};
		};
	};

	class Indep {
		name = "Independent";

		class TAE_Faction_HouseKarr {
			name = "[TAE] House Karr";

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

	class Civilian {
		name = "Civilian";

		class TAE_Faction_Civilians {
			name = "[TAE] Civilians";

			class Civilians {
				name = "Civilians";

				class TAE_Group_Civilian_Random {
					name = "Civilian (Random)";
					side = 3;
					faction = "TAE_Faction_Civilians";
					icon = "\A3\ui_f\data\map\markers\nato\c_unknown.paa";

					class Unit0 {
						side = 3;
						vehicle = "TAE_Unit_Civilian_Random";
						rank = "PRIVATE";
						position[] = {0, 0, 0};
					};
				};
			};
		};
	};
};
