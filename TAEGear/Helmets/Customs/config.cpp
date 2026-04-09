class CfgPatches {
	class TAEGear_Helmets_Customs {
		addonRootClass = "TAEGear_Helmets";
		requiredVersion = 1.60;
		requiredAddons[] = { "TAEGear_Helmets" };
		units[] = { };
		weapons[] = {
			"tae_karr_helmet_fd",
			"tae_karr_helmet_mr",
			"tae_karr_helmet_ma",
			"tae_karr_helmet_mm",
			"tae_karr_helmet_mv",
			"tae_karr_helmet_niteowl_fd",
			"tae_hondo_helmet",
			"tae_acklay_helmet",
			"tae_acklay_rangefinder",
			"tae_edonn_helmet",
			"tae_edonn_rangefinder",
			"tae_nox_helmet"
		};
	};
};

class XtdGearModels {
	class CamoBase;
	class CfgWeapons {
		class TAE_standard_helmets {
			label = "Standard Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "helmet", "role" };

			class helmet {
				alwaysSelectable = 1;
				label = "Helmet";
				values[] = { "Traditional", "Niteowl" };

				class Traditional {
					label = "Traditional";
				};
				class Niteowl {
					label = "Nite Owl";
				};
			};

			class role {
				alwaysSelectable = 1;
				label = "Role";
				values[] = { "Foundling", "Recruit", "Apprentice", "Standard", "Veteran" };

				class Foundling {
					label = "FD";
				};
				class Recruit {
					label = "MR";
				};
				class Apprentice {
					label = "MA";
				};
				class Standard {
					label = "MM";
				};
				class Veteran {
					label = "MV";
				};
			};
		};

		class TAE_freelancer_helmets {
			label = "Freelancer Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Hondo","Teka" };

				class Hondo {
					label = "Hondo";
				};
				class Teka {
					label = "Teka";
				};
			};
		};

		class TAE_acklay_helmets {
			label = "Clan Acklay Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard", "Edonn", "Nox" };

				class Standard {
					label = "Standard";
				};
				class Edonn {
					label = "Edonn";
				};
				class Nox {
					label = "Nox";
				};
			};
		};
	};
};

class XtdGearInfos {
	class CfgWeapons {
		// Standard
		class tae_karr_helmet_fd {
			model = "TAE_standard_helmets";
			role = "Foundling";
			helmet = "Traditional";
		};
		class tae_karr_helmet_mr {
			model = "TAE_standard_helmets";
			role = "Recruit";
			helmet = "Traditional";
		};
		class tae_karr_helmet_ma {
			model = "TAE_standard_helmets";
			role = "Apprentice";
			helmet = "Traditional";
		};
		class tae_karr_helmet_mm {
			model = "TAE_standard_helmets";
			role = "Standard";
			helmet = "Traditional";
		};
		class tae_karr_helmet_mv {
			model = "TAE_standard_helmets";
			role = "Veteran";
			helmet = "Traditional";
		};
		class tae_karr_helmet_niteowl_fd {
			model = "TAE_standard_helmets";
			role = "Foundling";
			helmet = "Niteowl";
		};

		// Freelancer
		class tae_hondo_helmet {
			model = "TAE_freelancer_helmets";
			owner = "Hondo";
		};
		class tae_teka_helmet {
			model = "TAE_freelancer_helmets";
			owner = "Teka";
		};

		// Acklay
		class tae_acklay_helmet {
			model = "TAE_acklay_helmets";
			owner = "Standard";
		};
		class tae_edonn_helmet {
			model = "TAE_acklay_helmets";
			owner = "Edonn";
		};
		class tae_nox_helmet {
			model = "TAE_acklay_helmets";
			owner = "Nox";
		};
	};
};

class CfgWeapons {
	class ItemInfo;
	class HeadgearItem;

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
	class tae_helmet_ls_dinDjarin;
	class tgf_nvg_rangefinder_r;
	
	//nvg inherit
	class tae_ls_mandalorian_rangefinder;
	
	//House Karr
	class tae_karr_helmet_fd : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Traditional Helmet (Foundling)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Trad_Helm_FND.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Trad_Helm_FND.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_mr : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Traditional Helmet (Mandalorian Recruit)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Trad_Helm_Rec.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Trad_Helm_Rec.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_ma : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Traditional Helmet (Mandalorian Apprentice)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Trad_Helm_Appren.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Trad_Helm_Appren.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_mm : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Traditional Helmet (Mandalorian)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Trad_Helm_Mando.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Trad_Helm_Mando.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_mv : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Traditional Helmet (Mandalorian Veteran)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Trad_Helm_Vet.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Trad_Helm_Vet.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_niteowl_fd : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\niteowlhelmet.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\niteowlhelmet.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};

	//Hondo
	class tae_hondo_helmet : tae_helmet_battle_master {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Hondo's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\BM_Helmet_Hondo.paa",
			"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\BM_Helmet_Hondo.paa",
				"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
			};
		};
	};
	
	//Clan Acklay
	class tae_acklay_helmet : tae_helmet_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Clan Acklay Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\acklay_helmet_co.paa",
			"TAEGear\data\acklay_visor_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","visor","neckTex"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\acklay_helmet_co.paa",
				"TAEGear\data\acklay_visor_co.paa",
				"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
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
	
	//Edonn
	class tae_edonn_helmet : tae_helmet_ls_dinDjarin {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Edonn's Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Edonn_Helmet_co.paa",
			"TAEGear\data\Edonn_Visor_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","visor","neckTex"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Edonn_Helmet_co.paa",
				"TAEGear\data\Edonn_Visor_co.paa",
				"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
			};
		};
	};
	class tae_edonn_rangefinder : tgf_nvg_rangefinder_r {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Edonn's Rangefinder";
		model = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		hiddenSelectionsTextures[] = { "TAEGear\data\Edonn_Rangefinder_CO.paa" };
		picture = "\z\tgf\addons\nvg\rangefinder_r\data\mando_range.paa";
		class ItemInfo: ItemInfo {
			uniformModel = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_on_r.p3d";
			modelOff = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		};
	};
	
	//Nox
	class tae_nox_helmet : tae_helmet_warlord {
		scope = 1;
		scopeArsenal = 1;
		scopeCurator = 1;
		displayName = "Nox's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\noxhelmet.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
			"TAEGear\data\noxhelmet.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
			};
		};
	};

	//Teka
	class tae_teka_helmet : tae_helmet_pilot {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Teka's Helmet";
		hiddenSelections[] = {"camo1","camo2","camo"};
		hiddenSelectionsTextures[] = {"TAEGear\data\Teka_Helmet_CO.paa","TAEGear\data\Teka_Visor_CO.paa","TAEGear\data\Teka_Helmet_Lights_CO.paa"};
		//hiddenselectionsmaterials[] = {"","","\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2","camo"};
			hiddenSelectionsTextures[] = {"TAEGear\data\Teka_Helmet_CO.paa","TAEGear\data\Teka_Visor_CO.paa","TAEGear\data\Teka_Helmet_Lights_CO.paa"};
			//hiddenselectionsmaterials[] = {"","","\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"};
		};
	};
};
