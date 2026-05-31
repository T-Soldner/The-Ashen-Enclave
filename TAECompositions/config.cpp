class CfgPatches {
	class TAECompositions {
		name = "TAE Compositions";
		author = "TAE Mod Team";
		requiredVersion = 2.10;
		requiredAddons[] = {
			"ls_props_staticships",
			"3AS_Prop_Platforms",
			"3AS_Structures_LandingPads",
			"A3_Structures_F_Exp_Industrial_Port",
			"3AS_Structures2_FlatShields",
			"3AS_Structure2_MissionTools",
			"3AS_Prop_Sullust",
			"3AS_Structures2_StairsLadderElevator",
			"TAEVehicles",
			"3AS_Prop_Crates",
			"3AS_Imperial_Air_Gozanti",
			"mti_factions_mando",
			"mti_factions_deathwatch",
			"mti_armoury_vehicles_mutt",
			"knd_vehicles_ewing",
			"WM_74Z_Imperial",
			"3AS_Structures_FOB",
			"WM_ImperialLamp",
			"TAEObjects",
			"TAEUnits_HouseKarr",
			"A3_Modules_F_Curator_Curator",
			"A3_Weapons_F",
			"ls_radios",
			"TAEUniforms",
			"objectbase_Mod",
			"3AS_Prop_Interiors",
			"JMSLLTE_vehair_Uwing",
			"3AS_Prop_Capital_ISD",
			"3AS_CIS_Wheeled_PAC",
			"Bacta",
			"lsb_fob",
			"3AS_Prop_Barricades",
			"lsb_walkways",
			"3AS_Prop_pipes",
			"3AS_Structures2_GenericFOB",
			"JMSLLTE_props_computers",
			"3AS_Structures_ShieldGenerator",
			"OPTRE_UNSC_Structure_Military",
			"OPTRE_UNSC_Structure_Arctic_Military",
			"3AS_Prop_Terminals",
			"A3_Modules_F_Multiplayer",
			"JMS_st_objectsFont",
			"A3_Structures_F_Mark_VR_Shapes",
			"ls_props_structures",
			"A3_Structures_F_Bootcamp_VR_Helpers",
			"ls_holoprojector",
			"A3_Misc_F_Helpers",
			"OPTRE_UNSC_Structure_HoloObjects",
			"3AS_Prop_Flags",
			"A3_Props_F_AoW_Items_Decorative",
			"WM_ATAT",
			"ls_vehicles_aat",
			"3AS_Imperial",
			"A3_Props_F_Orange_Furniture",
			"SFA_Structure_Terminal",
			"3AS_Prop_Furniture",
			"3AS_Props2_Furniture2",
			"3AS_TalzStructures",
			"JMSLLTE_props_other",
			"OPTRE_UNSC_Structure_Signs",
			"JMSLLTE_e11",
			"JMSLLTE_e11d",
			"JMSLLTE_a280",
			"JMSLLTE_DLT19",
			"lsb_props_containers",
			"OPTRE_UNSC_Structure_Containers",
			"A3_Structures_F_Furniture",
			"OPTRE_Buildings_Street_Objects",
			"A3_Structures_F_Mil_Helipads",
			"JLTS_C_Intel",
			"JLTS_C_Credits",
			"mti_armoury_props_misc",
			"mti_armoury_props_intel",
			"3as_GNK_Prop",
			"knd_props",
			"tgf_props",
			"ace_sitting",
			"A3_Structures_F_Heli_Furniture",
			"3AS_Intel",
			"3AS_Prop_Tatooine",
			"3AS_Prop_Posters",
			"3AS_Prop_Sensors",
			"3AS_Marketplace",
			"3AS_Props2_MiscItems",
			"SFA_Structure_Bed",
			"lsb_modules",
			"3AS_Prop_Droids",
			"knd_reconfigs"
		};
		units[] = {};
		weapons[] = {};
	};
};

class CfgEditorCategories {
	class TAE_EdCat_Compositions {
		displayName = "[TAE] Compositions";
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_Fleet {
		displayName = "Fleet";
	};
};

class Cfg3DEN {
	class Compositions {
		class TAE_Comp_FleetSpawn {
			scope = 2;
			path = "TAECompositions\compositions\TAE_Fleet_Spawn";
			side = 8;
			editorCategory = "TAE_EdCat_Compositions";
			editorSubcategory = "TAE_EdSubcat_Fleet";
			displayName = "TAE Fleet Spawn";
			icon = "\A3\ui_f\data\map\markers\nato\n_unknown.paa";
			useSideColorOnIcon = 0;
		};
	};
};
