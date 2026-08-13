class CfgPatches {
	class TAEGear_Helmets_Customs {
		addonRootClass = "TAEGear_Helmets";
		requiredVersion = 1.60;
		requiredAddons[] = { "TAEGear_Helmets", "ls_characters_clone_legacy" };
		units[] = { };
		weapons[] = {
			"tae_karr_helmet_fd",
			"tae_karr_helmet_mr",
			"tae_karr_helmet_ma",
			"tae_karr_helmet_mm",
			"tae_karr_helmet_mv",
			"tae_karr_helmet_niteowl_fd",
			"tae_karr_helmet_niteowl_mr",
			"tae_karr_helmet_niteowl_ma",
			"tae_karr_helmet_niteowl_mm",
			"tae_karr_helmet_niteowl_mv",
			"tae_hondo_helmet",
			"tae_nova_helmet",
			"tae_teka_helmet",
			"tae_shyyyo_helmet",
			"tae_acklay_helmet",
			"tae_ls_grey_rangefinder",
			"tae_acklay_niteowl_helmet",
			"tae_edonn_helmet",
			"tae_dark_grey_rangefinder",
			"tae_nox_helmet",
			"tae_jimothy_helmet",
			"tae_jimothy_rangefinder",
			"tae_frenk_helmet",
			"tae_towi_helmet",
			"tae_stasik_helmet",
			"tae_foxx_helmet",
			"tae_juno_helmet",
			"tae_bean_helmet",
			"tae_galaxy_helmet",
			"tae_varen_helmet",
			"tae_valeria_helmet",
			"tae_vario_helmet",
			"tae_dark_red_rangefinder",
			"tae_foxx_rangefinder",
			"tae_rook_helmet",
			"tae_hades_helmet",
			"tae_grey_helmet",
			"tae_andora_helmet",
			"tae_goostivool_helmet",
			"tae_shen_helmet"
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
					label = "Foundling";
				};
				class Recruit {
					label = "Recruit";
				};
				class Apprentice {
					label = "Apprentice";
				};
				class Standard {
					label = "Mandalorian";
				};
				class Veteran {
					label = "Veteran";
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
				values[] = { "Hondo","Nova","Edonn","Nox" };

				class Hondo {
					label = "Hondo";
				};
				class Nova {
					label = "Nova";
				};
				class Edonn {
					label = "Edonn";
				};
				class Nox {
					label = "Nox";
				};
			};
		};

		class TAE_pilot_helmets {
			label = "Pilot Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Teka","Shyyyo" };

				class Teka {
					label = "Teka";
				};
				class Shyyyo {
					label = "Shyyyo";
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
				values[] = { "Standard","Niteowl", "Stasik", "Jimothy", "Frenk", "Towi" };

				class Standard {
					label = "Standard";
				};
				class Niteowl {
					label = "Nite owl";
				};
				class Stasik {
					label = "Stasik";
				};
				class Jimothy {
					label = "Jimothy";
				};
				class Frenk {
					label = "Frenk";
				};
				class Towi {
					label = "Towi";
				};
			};
		};
		
		class TAE_foxx_helmets {
			label = "Clan Foxx Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard", "Juno", "Bean", "Grey", "Galaxy" };

				class Standard {
					label = "Standard";
				};
				class Juno {
					label = "Juno";
				};
				class Bean {
					label = "Bean";
				};
				class Grey {
					label = "Grey";
				};
				class Galaxy {
					label = "Galaxy";
				};
			};
		};
		class TAE_varen_helmets {
			label = "Clan Varen Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard", "Valeria" };

				class Standard {
					label = "Standard";
				};
				class Valeria {
					label = "Valeria";
				};
			};
		};
		class TAE_rook_helmets {
			label = "Clan Rook Helmets";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard", "Hades", "Andora", "Goostivool", "Shen", "Vario" };

				class Standard {
					label = "Standard";
				};
				class Hades {
					label = "Hades";
				};
				class Andora {
					label = "Andora";
				};
				class Goostivool {
					label = "Goostivool";
				};
				class Shen {
					label = "Shen";
				};
				class Vario {
					label = "Vario";
				};
			};
		};
		class TAE_nvgs {
			label = "TAE NVGs";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "LSGrey", "DarkGrey", "Jimothy", "DarkRed", "Foxx" };

				class LSGrey {
					label = "LS Grey";
				};
				class DarkGrey {
					label = "Dark Grey";
				};
				class Jimothy {
					label = "Heavy Grey";
				};
				class DarkRed {
					label = "Dark Red";
				};
				class Foxx {
					label = "Foxx";
				};
			};
		};
	};
};

class XtdGearInfos {
	class CfgWeapons {
		// TAE NVGs

		// Karr Medium
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
		// Nite Owl
		class tae_karr_helmet_niteowl_fd {
			model = "TAE_standard_helmets";
			role = "Foundling";
			helmet = "Niteowl";
		};
		class tae_karr_helmet_niteowl_mr {
			model = "TAE_standard_helmets";
			role = "Recruit";
			helmet = "Niteowl";
		};
		class tae_karr_helmet_niteowl_ma {
			model = "TAE_standard_helmets";
			role = "Apprentice";
			helmet = "Niteowl";
		};
		class tae_karr_helmet_niteowl_mm {
			model = "TAE_standard_helmets";
			role = "Standard";
			helmet = "Niteowl";
		};
		class tae_karr_helmet_niteowl_mv {
			model = "TAE_standard_helmets";
			role = "Veteran";
			helmet = "Niteowl";
		};

		// Freelancer
		class tae_hondo_helmet {
			model = "TAE_freelancer_helmets";
			owner = "Hondo";
		};
		class tae_nova_helmet {
			model = "TAE_freelancer_helmets";
			owner = "Nova";
		};
		class tae_edonn_helmet {
			model = "TAE_freelancer_helmets";
			owner = "Edonn";
		};
		class tae_teka_helmet {
			model = "TAE_pilot_helmets";
			owner = "Teka";
		};
		class tae_shyyyo_helmet {
			model = "TAE_pilot_helmets";
			owner = "Shyyyo";
		};
		class tae_nox_helmet {
			model = "TAE_freelancer_helmets";
			owner = "Nox";
		};

		// Clan Acklay
		class tae_acklay_helmet {
			model = "TAE_acklay_helmets";
			owner = "Standard";
		};
		class tae_ls_grey_rangefinder {
			model = "TAE_nvgs";
			owner = "LSGrey";
		};
		class tae_acklay_niteowl_helmet {
			model = "TAE_acklay_helmets";
			owner = "Niteowl";
		};
		class tae_dark_grey_rangefinder {
			model = "TAE_nvgs";
			owner = "DarkGrey";
		};
		class tae_stasik_helmet {
			model = "TAE_acklay_helmets";
			owner = "Stasik";
		};
		class tae_jimothy_helmet {
			model = "TAE_acklay_helmets";
			owner = "Jimothy";
		};
		class tae_jimothy_rangefinder {
			model = "TAE_nvgs";
			owner = "Jimothy";
		};
		class tae_frenk_helmet {
			model = "TAE_acklay_helmets";
			owner = "Frenk";
		};
		class tae_towi_helmet {
			model = "TAE_acklay_helmets";
			owner = "Towi";
		};
		
		// Clan Foxx
		class tae_foxx_helmet {
			model = "TAE_foxx_helmets";
			owner = "Standard";
		};
		class tae_juno_helmet {
			model = "TAE_foxx_helmets";
			owner = "Juno";
		};
		class tae_bean_helmet {
			model = "TAE_foxx_helmets";
			owner = "Bean";
		};
		class tae_grey_helmet {
			model = "TAE_foxx_helmets";
			owner = "Grey";
		};
		class tae_galaxy_helmet {
			model = "TAE_foxx_helmets";
			owner = "Galaxy";
		};

		// Clan Varen
		class tae_varen_helmet {
			model = "TAE_varen_helmets";
			owner = "Standard";
		};
		class tae_valeria_helmet {
			model = "TAE_varen_helmets";
			owner = "Valeria";
		};
		class tae_dark_red_rangefinder {
			model = "TAE_nvgs";
			owner = "DarkRed";
		};
		class tae_foxx_rangefinder {
			model = "TAE_nvgs";
			owner = "Foxx";
		};
		class tae_rook_helmet {
			model = "TAE_rook_helmets";
			owner = "Standard";
		};
		class tae_hades_helmet {
			model = "TAE_rook_helmets";
			owner = "Hades";
		};
		class tae_vario_helmet {
			model = "TAE_rook_helmets";
			owner = "Vario";
		};
		class tae_andora_helmet {
			model = "TAE_rook_helmets";
			owner = "Andora";
		};
		class tae_goostivool_helmet {
			model = "TAE_rook_helmets";
			owner = "Goostivool";
		};
		class tae_shen_helmet {
			model = "TAE_rook_helmets";
			owner = "Shen";
		};
	};
};

class CfgWeapons {
	class ItemInfo;
	class HeadgearItem;

	// helmet inherits
	class tae_helmet_traditional;
	class tae_helmet_battle_master;
	class tae_helmet_gunslinger;
	class tae_helmet_gunslinger_vet;
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
	class tae_helmet_ls_executioner;
	class tae_helmet_ls_armorer;
	class tgf_nvg_rangefinder_r;
	
	// nvg inherit
	class tae_ls_mandalorian_rangefinder;
	class tgf_nvg_heavy_nv;
	
	// FreeLancers
	// House Karr Mediunm
	class tae_karr_helmet_fd : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Traditional Helmet (Foundling)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_FND.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_FND.paa",
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
			"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Rec.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Rec.paa",
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
			"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_App.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_App.paa",
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
			"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Mando.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Mando.paa",
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
			"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Vet.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Vet.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	
	// House Karr Nite Owl
	class tae_karr_helmet_niteowl_fd : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_FND.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_FND.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_niteowl_mr : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MR.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MR.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_niteowl_ma : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MA.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MA.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_niteowl_mm : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MM.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MM.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};
	class tae_karr_helmet_niteowl_mv : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MV.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Helmet_MV.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};
	
	// Hondo
	class tae_hondo_helmet : tae_helmet_battle_master {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Hondo's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Hondo\BM_Helmet_Hondo.paa",
			"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Hondo\BM_Helmet_Hondo.paa",
				"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
			};
		};
	};
	class tae_nova_helmet : tae_helmet_ls_armorer {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "Nova's Armorer Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Nova\ARM_Helmet_Nova.paa",
			"\ls\core\addons\characters_mandalorian\helmets\armorer\data\visor_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\armorer\data\neck_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","visor","neckTex"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Nova\ARM_Helmet_Nova.paa",
				"\ls\core\addons\characters_mandalorian\helmets\armorer\data\visor_co.paa",
				"\ls\core\addons\characters_mandalorian\helmets\armorer\data\neck_co.paa"
			};
		};
	};
	
	// Teka
	class tae_teka_helmet : tae_helmet_pilot {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Teka";
		displayName = "Teka's Helmet";
		hiddenSelections[] = {"camo1","camo2","camo"};
		hiddenSelectionsTextures[] = {"TAEGear\data\Teka\PLT_Helmet_Teka.paa","TAEGear\data\Teka\PLT_Visor_Teka.paa","TAEGear\data\Teka\PLT_Lights_Teka.paa"};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2","camo"};
			hiddenSelectionsTextures[] = {"TAEGear\data\Teka\PLT_Helmet_Teka.paa","TAEGear\data\Teka\PLT_Visor_Teka.paa","TAEGear\data\Teka\PLT_Lights_Teka.paa"};
		};
	};
	class tae_shyyyo_helmet : tae_helmet_pilot {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Shyyyo Pilot Helmet";
		hiddenSelections[] = {"camo1","camo2","camo"};
		hiddenSelectionsTextures[] = {"TAEGear\data\Shyyyo\PLT_Helmet_Shyyyo.paa","TAEGear\data\Shyyyo\PLT_Visor_Shyyyo.paa","TAEGear\data\Shyyyo\PLT_Lights_Shyyyo.paa"};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2","camo"};
			hiddenSelectionsTextures[] = {"TAEGear\data\Shyyyo\PLT_Helmet_Shyyyo.paa","TAEGear\data\Shyyyo\PLT_Visor_Shyyyo.paa","TAEGear\data\Shyyyo\PLT_Lights_Shyyyo.paa"};
		};
	};
	
	// Clan Acklay
	class tae_acklay_helmet : tae_helmet_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Clan Acklay Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Acklay\LS_TRAD_Helmet_Acklay.paa",
			"TAEGear\data\Acklay\LS_TRAD_Visor_Acklay.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","visor","neckTex"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Acklay\LS_TRAD_Helmet_Acklay.paa",
				"TAEGear\data\Acklay\LS_TRAD_Visor_Acklay.paa",
				"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
			};
		};
	};
	class tae_ls_grey_rangefinder : tae_ls_mandalorian_rangefinder {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "LS Grey";
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
	
	class tae_acklay_niteowl_helmet : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Clan Acklay Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Acklay\NITE_Helmet_Acklay.paa",
			"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Acklay\NITE_Helmet_Acklay.paa",
				"\z\tgf\addons\helmets\nite_owl\data\camo2_co.paa"
			};
		};
	};
	// Edonn
	class tae_edonn_helmet : tae_helmet_ls_dinDjarin {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Edonn's Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.paa",
			"TAEGear\data\Edonn\LS_DIN_Visor_Edonn.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		hiddenSelectionsMaterials[] = {
			"TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.rvmat",
			"TAEGear\data\Edonn\LS_DIN_Visor_Edonn.rvmat"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","visor","neckTex"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.paa",
				"TAEGear\data\Edonn\LS_DIN_Visor_Edonn.paa",
				"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
			};
			hiddenSelectionsMaterials[] = {
				"TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.rvmat",
				"TAEGear\data\Edonn\LS_DIN_Visor_Edonn.rvmat"
			};
		};
	};
	class tae_dark_grey_rangefinder : tgf_nvg_rangefinder_r {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Dark Grey";
		model = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		visionMode[] = { "Normal", "NVG", "TI" };
		hiddenSelectionsTextures[] = { "TAEGear\data\Edonn\LS_DIN_Rangefinder_Edonn.paa" };
		picture = "\z\tgf\addons\nvg\rangefinder_r\data\mando_range.paa";
		class ItemInfo: ItemInfo {
			uniformModel = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_on_r.p3d";
			hiddenSelectionsTextures[] = { "TAEGear\data\Edonn\LS_DIN_Rangefinder_Edonn.paa" };
			modelOff = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		};
	};
	
	// Nox
	class tae_nox_helmet : tae_helmet_warlord {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Nox's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Nox\WAR_Helmet_Nox.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Nox\WAR_Helmet_Nox.paa",
				"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
			};
		};
	};
	
	
	// Jimothy
	class tae_jimothy_helmet : tae_helmet_heavy {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Jimothy's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Jimothy\HEAV_Helmet_Jimothy.paa",
			"TAEGear\data\Jimothy\HEAV_Visor_Jimothy.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Jimothy\HEAV_Helmet_Jimothy.paa",
				"TAEGear\data\Jimothy\HEAV_Visor_Jimothy.paa"
			};
		};
	};
	class tae_jimothy_rangefinder : tgf_nvg_heavy_nv {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		hiddenSelectionsTextures[] = {"TAEGear\data\Jimothy\HEAV_NVG_Jimothy.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\z\tgf\addons\nvg\heavy_nv\heavy_nv.p3d";
			modelOff = "\z\tgf\addons\nvg\heavy_nv\heavy_nv.p3d";
		hiddenSelectionsTextures[] = {"TAEGear\data\Jimothy\HEAV_NVG_Jimothy.paa"};
		};
	};

	// Frenk
	class tae_frenk_helmet : tae_helmet_gunslinger {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Frenk's Gunslinger Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Frenk\GUN_Helmet_Frenk.paa",
			"TAEGear\data\Frenk\GUN_Visor_Frenk.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Frenk\GUN_Helmet_Frenk.paa",
				"TAEGear\data\Frenk\GUN_Visor_Frenk.paa"
			};
		};
	};
	class tae_towi_helmet : tae_helmet_arbiter {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Towi's Arbiter Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Towi\ARB_Helmet_Towi.paa",
			"TAEGear\data\Towi\ARB_Visor_Towi.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Towi\ARB_Helmet_Towi.paa",
				"TAEGear\data\Towi\ARB_Visor_Towi.paa"
			};
		};
	};
	
	// Stasik
	class tae_stasik_helmet : tae_helmet_viper {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Stasik's Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Stasik\VPR_Helmet_Stasik.paa",
			"TAEGear\data\Stasik\VPR_Visor_Stasik.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Stasik\VPR_Helmet_Stasik.paa",
				"TAEGear\data\Stasik\VPR_Visor_Stasik.paa"
			};
		};
	};

	// Clan Foxx
	class tae_foxx_helmet : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Juno";
		displayName = "Clan Foxx Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Foxx\TRAD_Helmet_Foxx.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Foxx\TRAD_Helmet_Foxx.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_juno_helmet : tae_helmet_arbiter {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Juno";
		displayName = "Juno's Arbiter Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Juno\ARB_Helmet_Juno.paa",
			"TAEGear\data\Juno\ARB_Visor_Juno.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Juno\ARB_Helmet_Juno.paa",
				"TAEGear\data\Juno\ARB_Visor_Juno.paa"
			};
		};
	};
	class tae_bean_helmet : tae_helmet_war_chief{
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Bean";
		displayName = "Clan Foxx Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Foxx\WAR_Helmet_Bean.paa",
			"\z\tgf\addons\helmets\war_chief\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Foxx\WAR_Helmet_Bean.paa",
				"\z\tgf\addons\helmets\war_chief\data\camo2_co.paa"
			};
		};
	};

	// Clan Varen
	class tae_varen_helmet : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Valeria";
		displayName = "Clan Varen Traditional Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Varen\TRAD_Helmet_Varen.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Varen\TRAD_Helmet_Varen.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_valeria_helmet : tae_helmet_viper {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Valeria";
		displayName = "Valeria's Viper Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Varen\VPR_Helmet_Valeria.paa",
			"\z\tgf\addons\helmets\viper\data\camo2_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Varen\VPR_Helmet_Valeria.paa",
				"\z\tgf\addons\helmets\viper\data\camo2_co.paa"
			};
		};
	};
	class tae_dark_red_rangefinder : tgf_nvg_rangefinder_r {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Valeria";
		displayName = "Dark Red";
		model = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = { "TAEGear\data\Varen\TRAD_Rangefinder_Varen.paa" };
		picture = "\z\tgf\addons\nvg\rangefinder_r\data\mando_range.paa";

		class ItemInfo: ItemInfo {
			uniformModel = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_on_r.p3d";
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = { "TAEGear\data\Varen\TRAD_Rangefinder_Varen.paa" };
			modelOff = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		};
	};
	class tae_foxx_rangefinder : tgf_nvg_rangefinder_r {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Juno";
		displayName = "Clan Foxx Rangefinder";
		model = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"TAEGear\data\Juno\TRAD_Rangefinder_Foxx.paa"};
		picture = "\z\tgf\addons\nvg\rangefinder_r\data\mando_range.paa";

		class ItemInfo: ItemInfo {
			uniformModel = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_on_r.p3d";
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {"TAEGear\data\Juno\TRAD_Rangefinder_Foxx.paa"};
			modelOff = "\z\tgf\addons\nvg\rangefinder_r\rangefinder_off_r.p3d";
		};
	};

	// Clan Rook
	class tae_rook_helmet : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Clan Rook Traditional Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Rook\TRAD_Helmet_Rook.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Rook\TRAD_Helmet_Rook.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_hades_helmet : tae_helmet_arbiter {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Lanval";
		displayName = "Hades' Arbiter Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Hades\ARB_Helmet_Hades.paa",
			"TAEGear\data\Hades\ARB_Visor_Hades.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Hades\ARB_Helmet_Hades.paa",
				"TAEGear\data\Hades\ARB_Visor_Hades.paa"
			};
		};
	};
	class tae_grey_helmet : tae_helmet_gunslinger_vet {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Bean";
		displayName = "Grey's Gunslinger Veteran Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Grey\GUNV_Helmet_Grey.paa",
			"\z\tgf\addons\helmets\gunslinger_vet\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Grey\GUNV_Helmet_Grey.paa",
				"\z\tgf\addons\helmets\gunslinger_vet\data\camo2_co.paa"
			};
		};
	};
	class tae_galaxy_helmet : tae_helmet_gunslinger {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Galaxy's Gunslinger Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Galaxy\GUN_Helmet_Galaxy.paa",
			"TAEGear\data\Galaxy\GUN_Visor_Galaxy.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Galaxy\GUN_Helmet_Galaxy.paa",
				"TAEGear\data\Galaxy\GUN_Visor_Galaxy.paa"
			};
		};
	};
	class tae_vario_helmet : tae_helmet_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Vario's Traditional Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Vario\TRAD_Helmet_Vario.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Vario\TRAD_Helmet_Vario.paa",
				"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
			};
		};
	};
	class tae_andora_helmet : tae_helmet_nite_owl {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Andora's Nite Owl Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Andora\NITE_Helmet_Andora.paa",
			"TAEGear\data\Andora\NITE_Visor_Andora.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Andora\NITE_Helmet_Andora.paa",
				"TAEGear\data\Andora\NITE_Visor_Andora.paa"
			};
		};
	};
	class tae_goostivool_helmet : tae_helmet_ls_executioner {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Goostivool's Executioner Helmet";
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Goostivool\EXEC_Helmet_Goostivool.paa",
			"\ls\core\addons\characters_mandalorian\helmets\executioner\data\visor_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\executioner\data\neck_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Goostivool\EXEC_Helmet_Goostivool.paa",
				"\ls\core\addons\characters_mandalorian\helmets\executioner\data\visor_co.paa",
				"\ls\core\addons\characters_mandalorian\helmets\executioner\data\neck_co.paa"
			};
		};
	};
	class tae_shen_helmet : tae_helmet_gunslinger {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Shen's Gunslinger Helmet";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Shen\GUN_Helmet_Shen.paa",
			"TAEGear\data\Shen\GUN_Visor_Shen.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Shen\GUN_Helmet_Shen.paa",
				"TAEGear\data\Shen\GUN_Visor_Shen.paa"
			};
		};
	};
};
