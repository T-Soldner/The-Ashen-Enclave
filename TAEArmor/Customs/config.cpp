class CfgPatches {
	class TAEArmor_Custom {
		addonRootClass = "TAEArmor";
		requiredVersion = 1.60;
		requiredAddons[] = { "TAEArmor" };
		units[] = { "tae_hondo_JT12" };
		weapons[] = {
			"tae_karr_armor_traditional",
			"tae_karr_helmet_traditional",
			"tae_karr_armor_nite_owl",
			"tae_karr_helmet_nite_owl",
			"tae_hondo_armor",
			"tae_hondo_helmet",
			"tae_helmet_acklay",
			"tae_armor_acklay",
			"tae_acklay_rangefinder",
			"tae_nox_helmet",
			"tae_nox_armor"
		};
	};
};

class CfgWeapons {
	class ItemInfo;
	class VestItem;
	class HeadgearItem;
	
	//Armor inherits
	class tae_armor_traditional;
	class tae_armor_medium;
	class tae_armor_recon;
	class tae_armor_heavy;
	class tae_armor_battle;
	class tae_armor_war_chief;
	class tae_armor_arbiter;
	class tae_armor_ls_traditional;
	class tae_nite_owl_armor;

	//helmet inherits
	class tae_helmet_traditional;
	class tae_helmet_battle_master;
	class tae_helmet_gunslinger;
	class tae_helmet_warlord;
	class tae_helmet_viper;
	class tae_helmet_heavy;
	class tae_helmet_pilot;
	class tae_helmet_shrike;
	class tae_helmet_arbiter;
	class tae_helmet_war_chief;
	class tae_helmet_ls_traditional;
	class tae_helmet_nite_owl;
	
	//nvg inherit
	class tae_ls_mandalorian_rangefinder;
	
	//House Karr
	class tae_karr_armor_traditional : tae_armor_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "House Karr Traditional Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\traditional1.paa",
			"TAEArmor\data\traditional2.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\traditional1.paa",
				"TAEArmor\data\traditional2.paa"
			};
		};
	};
	class tae_karr_helmet_traditional : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "House Karr Traditional Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\traditionalhelmet.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\traditionalhelmet.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_armor_nite_owl : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "House Karr Nite Owl Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\niteowl1.paa",
			"TAEArmor\data\niteowl2.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\niteowl1.paa",
				"TAEArmor\data\niteowl2.paa"
			};
		};
	};
	class tae_karr_helmet_nite_owl : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\niteowlhelmet.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\niteowlhelmet.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};

	//Hondo
	class tae_hondo_armor : tae_armor_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Hondo's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\hondo1.paa",
			"TAEArmor\data\hondo2.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\hondo1.paa",
				"TAEArmor\data\hondo2.paa"
			};
		};
	};
	class tae_hondo_helmet : tae_helmet_battle_master {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Hondo's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\hondohelmet.paa",
			"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\hondohelmet.paa",
				"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
			};
		};
	};
	
	//Clan Acklay
	class tae_helmet_acklay : tae_helmet_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Clan Acklay Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\acklay_helmet_co.paa",
			"TAEArmor\data\acklay_visor_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","visor","neckTex"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\acklay_helmet_co.paa",
				"TAEArmor\data\acklay_visor_co.paa",
				"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
			};
		};
	};
	class tae_armor_acklay : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Clan Acklay Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\acklay_vest_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\acklay_vest_co.paa"
			};
		};
	};
	class tae_acklay_rangefinder : tae_ls_mandalorian_rangefinder {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Clan Acklay Rangefinder";
		model = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_on.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\ls\core\addons\characters_mandalorian\helmets\original\data\original_co.paa"};
		visionMode[] = {"Normal","NVG","TI"};
		thermalMode[] = {0,1};

		class ItemInfo : ItemInfo {
			uniformModel = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_on.p3d";
			modelOff = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_off.p3d";
			hiddenSelections[] = {"camo1"};
		};
	};

	//Nox
	class tae_nox_armor : tae_armor_arbiter {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Nox's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\nox1.paa",
			"TAEArmor\data\nox2.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEArmor\data\nox1.paa",
				"TAEArmor\data\nox2.paa"
			};
		};
	};
	class tae_nox_helmet : tae_helmet_warlord {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Nox's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\noxhelmet.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
			"TAEArmor\data\noxhelmet.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
			};
		};
	};
};

class CfgVehicles {
	class tgf_backpacks_JT12_LR;
	
	class tae_hondo_JT12 : tgf_backpacks_JT12_LR {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Hondo's JT-12 Jetpack";
		descriptionShort = "Hondo's JT-12 Jetpack";
		hiddenSelectionsTextures[] = {"TAEArmor\data\hondojt12.paa"};
	};
};