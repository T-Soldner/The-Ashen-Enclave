class CfgPatches {
	class TAEUnits_HouseKarr {
		name = "House Karr";
		author = "TAE Mod Team";
		requiredVersion = 1.0;
		requiredAddons[] = {
			"A3_Characters_F"
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
			"TAE_Unit_Sniper"
		};
		weapons[] = {};
	};
};

class CfgFactionClasses {
	class TAE_Faction_HouseKarr {
		displayName = "House Karr";
		side = 2;
		priority = 2;
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Infantry {
		displayName = "Infantry";
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

	class TAE_Unit_Base: I_Soldier_F {
		scope = 0;
		scopeCurator = 0;
		author = "TAE Mod Team";
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Infantry";
		side = 2;
		genericNames = "TAE_GenericNames_HouseKarr";

		identityTypes[] = {
			"LanguageENG_F",
			"Head_NATO",
			"G_NATO_default"
		};

		icon = "iconMan";
		uniformClass = "tgf_undersuit_uniform_grey_seal";
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

	class TAE_Unit_Veteran: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Veteran";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Veteran_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Veteran_picture_ca.paa";
		backpack = "tae_modular_pack_lr";

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['LFP_westarcarabine','','','',['LFP_westarcarabine_Mag',60],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mv',[['LFP_westarcarabine_Mag',20,60],['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1]]],['tae_modular_pack_lr',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ACE_painkillers',2,10]]],'tae_karr_helmet_mv','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; _unit addPrimaryWeaponItem 'LFP_westarcarabine_scopesn'; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Engineer: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Engineer";
		icon = "iconManEngineer";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Engineer_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Engineer_picture_ca.paa";
		backpack = "tae_modular_pack_engi";

		engineer = 1;
		canDeactivateMines = 1;
		detectSkill = 80;
		ace_isEngineer = 1;
		ace_isEOD = 1;

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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['LFP_westarcarabine','','','',['LFP_westarcarabine_Mag',60],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1],['ACE_M26_Clacker',1]]],['tae_karr_armor_medium_mm',[['LFP_westarcarabine_Mag',20,60],['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1]]],['tae_modular_pack_engi',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ToolKit',1],['ACE_painkillers',2,10],['RTX_RemoteMagazine',3,1]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; _unit addPrimaryWeaponItem 'LFP_westarcarabine_scopesn'; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Medic: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Medic";
		icon = "iconManMedic";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Medic_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Medic_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['LFP_westarcarabine','','','',['LFP_westarcarabine_Mag',60],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mm',[['LFP_westarcarabine_Mag',20,60],['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1]]],['tae_modular_pack',[['ACE_surgicalKit',1],['ACE_tourniquet',5],['ACE_splint',6],['ACE_salineIV_500',5],['ACE_salineIV',5],['ACE_morphine',10],['ACE_epinephrine',10],['ACE_adenosine',10],['MTI_BactaPatch',30],['MTI_BactaSpray',30],['ACE_painkillers',2,10]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; _unit addPrimaryWeaponItem 'LFP_westarcarabine_scopesn'; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Marksman: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Marksman";
		icon = "iconManRecon";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Marksman_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Marksman_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['JMSLLTE_T21BBlasterRifle','','','',['JMSLLTE_T21B_7rnd_Mag',7],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mm',[['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1],['JMSLLTE_T21B_7rnd_Mag',20,7],['LFP_Westar35_Mag',5,20]]],['tae_modular_pack',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ACE_painkillers',2,10]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_AT_AA: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "AT/AA";
		icon = "iconManAT";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_AT_AA_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_AT_AA_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['LFP_westarcarabine','','','',['LFP_westarcarabine_Mag',60],[],''],['JMSLLTE_HH12_launcher','','','',['JMSLLTE_HH12_AT_Mag',1],[],''],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1],['LFP_westarcarabine_Mag',14,60],['3AS_ThermalDetonator',4,1]]],['tae_karr_armor_medium_mm',[['MTI_BactaSpray',20],['MTI_BactaPatch',20],['ACE_adenosine',5],['ACE_epinephrine',5],['ACE_morphine',5],['ACE_salineIV',3],['ACE_salineIV_500',3],['ACE_splint',4],['ACE_surgicalKit',1],['ACE_tourniquet',4],['LFP_westarcarabine_Mag',6,60],['3AS_ThermalDetonator',1,1],['3AS_SmokeWhite',5,1],['ACE_painkillers',2,10]]],['tae_modular_pack',[['JMSLLTE_HH12_AT_Mag',3,1],['JMSLLTE_HH12_AA_Mag',1,1]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; _unit addPrimaryWeaponItem 'LFP_westarcarabine_scopesn'; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Grenadier: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Grenadier";
		icon = "iconManExplosive";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Grenadier_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Grenadier_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['IDA_E10_UGL','','acc_flashlight','IDA_E11_scope',['IDA_Blaster_Cell_Power3_40Rnd_Red',40],['IDA_HE_LauncherGrenade',1],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mm',[['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1],['IDA_HE_LauncherGrenade',5,1],['IDA_Blaster_Cell_Power3_40Rnd_Red',20,40],['LFP_Westar35_Mag',4,20]]],['tae_modular_pack',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ACE_painkillers',2,10]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_CQC_Specialist: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "CQC Specialist";
		icon = "iconMan";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_CQC_Specialist_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_CQC_Specialist_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['3AS_DP23_F','','','',['3AS_10Rnd_EC30_Pellets',10],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mm',[['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1],['LFP_Westar35_Mag',4,20],['3AS_10Rnd_ESlug_Mag',8,10],['3AS_10Rnd_EC30_Pellets',8,10]]],['tae_modular_pack',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ACE_painkillers',2,10]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Heavy_Weapons: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Heavy Weapons";
		icon = "iconManMG";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Heavy_Weapons_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Heavy_Weapons_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['3AS_DLT19','','','3AS_Imp_Optic_2',['3AS_200Rnd_EM40_DLT19_Mag',189],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mm',[['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1],['LFP_Westar35_Mag',4,20],['3AS_200Rnd_EM40_DLT19_Mag',4,200]]],['tae_modular_pack',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ACE_painkillers',2,10]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
	};

	class TAE_Unit_Sniper: TAE_Unit_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Sniper";
		icon = "iconManRecon";
		editorPreview = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Sniper_preview.jpg";
		picture = "\TAEUnits_HouseKarr\data\ui\TAE_Unit_Sniper_picture_ca.paa";
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

		class EventHandlers {
			init = "params ['_unit']; _unit spawn { params ['_unit']; sleep 0.1; removeUniform _unit; _unit forceAddUniform 'tgf_undersuit_uniform_grey_seal'; _unit setSpeaker 'ACE_NoVoice'; _unit setUnitLoadout [[['IDA_Galaar90','','','IDA_TargetingScope',['IDA_Blaster_Cell_Power5_5Rnd_Yellow',5],[],''],[],['LFP_Westar_35','','','',['LFP_Westar35_Mag',20],[],'']],['tgf_undersuit_uniform_grey_seal',[['MineDetector',1],['ACE_MapTools',1],['ACE_Flashlight_XL50',1],['ACE_EntrenchingTool',1],['ACE_CableTie',5],['MTI_catTab_tablet',1],['ACE_IR_Strobe_Item',1]]],['tae_karr_armor_medium_mm',[['3AS_ThermalDetonator',5,1],['3AS_SmokeWhite',5,1],['LFP_Westar35_Mag',4,20],['IDA_Blaster_Cell_Power5_5Rnd_Yellow',16,5]]],['tae_modular_pack',[['ACE_surgicalKit',1],['ACE_tourniquet',4],['ACE_splint',4],['ACE_salineIV_500',3],['ACE_salineIV',3],['ACE_morphine',5],['ACE_epinephrine',5],['ACE_adenosine',5],['MTI_BactaPatch',20],['MTI_BactaSpray',20],['ACE_painkillers',2,10]]],'tae_karr_helmet_mm','tgf_facewear_medium_belt',['JMSLLTE_W_TD23_white_F','','','',[],[],''],['ItemMap','ItemGPS','ls_radios_hush98','ItemCompass','ItemWatch','tgf_nvg_rangefinder_r']]; removeGoggles _unit; _unit addGoggles 'tgf_facewear_medium_belt'; };";
		};
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
		};
	};
};