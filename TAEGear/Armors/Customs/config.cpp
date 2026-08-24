class CfgPatches {
	class TAEGear_Armors_Customs {
		addonRootClass = "TAEGear_Armors";
		requiredVersion = 1.60;
		requiredAddons[] = { "TAEGear_Armors" };
		units[] = {};
		weapons[] = {
			"tae_karr_armor_medium_fd",
			"tae_karr_armor_medium_mr",
			"tae_karr_armor_medium_ma",
			"tae_karr_armor_medium_mm",
			"tae_karr_armor_medium_mv",
			"tae_karr_armor_niteowl_fd",
			"tae_karr_armor_niteowl_mr",
			"tae_karr_armor_niteowl_ma",
			"tae_karr_armor_niteowl_mm",
			"tae_karr_armor_niteowl_mv",
			"tae_hondo_armor",
			"tae_teka_armor",
			"tae_shyyyo_recon_armor",
			"tae_acklay_armor",
			"tae_acklay_niteowl_armor",
			"tae_stasik_armor",
			"tae_edonn_armor",
			"tae_nox_armor",
			"tae_jimothy_armor",
			"tae_frenk_armor",
			"tae_foxx_armor",
			"tae_galaxy_armor",
			"tae_juno_armor",
			"tae_varen_recon_armor",
			"tae_varen_niteowl_armor",
			"tae_haranverd_traditional_armor",
			"tae_haranverd_niteowl_armor",
			"tae_rook_armor",
			"tae_hades_armor",
			"tae_andora_armor",
			"tae_goostivool_armor"
		};
	};
};

class XtdGearModels {
	class CamoBase;
	class CfgWeapons {
		class TAE_standard_vests {
			label = "Standard Vests";
			author = "TAE Aux Mod Team";
			options[] = { "armor","role" };
			class role {
				alwaysSelectable = 1;
				label = "Role";
				values[] = { "Foundling","Recruit","Apprentice","Standard","Veteran" };
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
			class armor {
				alwaysSelectable = 1;
				label = "Armor";
				values[] = { "Traditional","Niteowl"};
				class Traditional {
					label = "Traditional";
				};
				class Niteowl {
					label = "Nite Owl";
				};
			};
		};
		class TAE_freelancer_vests {
			label = "Freelancer Vests";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };
			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Hondo", "Edonn", "Nox" };
				class Hondo {
					label = "Hondo";
				};
				class Edonn {
					label = "Edonn";
				};
				class Nox {
					label = "Nox";
				};
			};
		};
		class TAE_pilot_vests {
			label = "Pilot Vests";
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
		class TAE_acklay_vests {
			label = "Clan Acklay Vests";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };
			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Acklay","Niteowl","Stasik","Jimothy","Frenk" };
				class Acklay {
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
			};
		};
		class TAE_foxx_vests {
			label = "Clan Foxx Vests";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };
			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard", "Juno", "Galaxy" };
				class Standard {
					label = "Standard";
				};
				class Juno {
					label = "Juno";
				};
				class Galaxy {
					label = "Galaxy";
				};
			};
		};
		class TAE_varen_vests {
			label = "Clan Varen Vests";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };
			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard","Niteowl" };
				class Standard {
					label = "Standard";
				};
				class Niteowl {
					label = "Nite Owl";
				};
			};
		};
		class TAE_haranverd_vests {
			label = "Clan Haranverd Vests";
			author = "TAE Aux Mod Team";
			options[] = { "style" };
			class style {
				alwaysSelectable = 1;
				label = "Style";
				values[] = { "Traditional", "Niteowl" };
				class Traditional {
					label = "Traditional";
				};
				class Niteowl {
					label = "Nite Owl";
				};
			};
		};
		class TAE_rook_vests {
			label = "Clan Rook Vests";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };
			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Standard", "Hades", "Andora", "Goostivool" };
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
			};
		};
	};
};
class XtdGearInfos {
	class CfgWeapons {
		//Standard
		class tae_karr_armor_medium_fd {
			model	= "TAE_standard_vests";
			role	= "Foundling";
			armor 	= "Traditional";
		};
		class tae_karr_armor_medium_mr {
			model	= "TAE_standard_vests";
			role	= "Recruit";
			armor 	= "Traditional";
		};
		class tae_karr_armor_medium_ma {
			model	= "TAE_standard_vests";
			role	= "Apprentice";
			armor 	= "Traditional";
		};
		class tae_karr_armor_medium_mm {
			model	= "TAE_standard_vests";
			role	= "Standard";
			armor 	= "Traditional";
		};
		class tae_karr_armor_medium_mv {
			model	= "TAE_standard_vests";
			role	= "Veteran";
			armor 	= "Traditional";
		};
		
		//Nite Owl
		class tae_karr_armor_niteowl_fd {
			model	= "TAE_standard_vests";
			role	= "Foundling";
			armor 	= "Niteowl";
		};
		class tae_karr_armor_niteowl_mr {
			model	= "TAE_standard_vests";
			role	= "Recruit";
			armor 	= "Niteowl";
		};
		class tae_karr_armor_niteowl_ma {
			model	= "TAE_standard_vests";
			role	= "Apprentice";
			armor 	= "Niteowl";
		};
		class tae_karr_armor_niteowl_mm {
			model	= "TAE_standard_vests";
			role	= "Standard";
			armor 	= "Niteowl";
		};
		class tae_karr_armor_niteowl_mv {
			model	= "TAE_standard_vests";
			role	= "Veteran";
			armor 	= "Niteowl";
		};
		
		//Freelancer
		class tae_hondo_armor {
			model	= "TAE_freelancer_vests";
			owner	= "Hondo";
		};
		class tae_nox_armor {
			model	= "TAE_freelancer_vests";
			owner	= "Nox";
		};
		class tae_edonn_armor {
			model	= "TAE_freelancer_vests";
			owner	= "Edonn";
		};
		class tae_teka_armor {
			model	= "TAE_pilot_vests";
			owner	= "Teka";
		};
		class tae_shyyyo_recon_armor {
			model	= "TAE_pilot_vests";
			owner	= "Shyyyo";
		};
		//Acklay
		class tae_acklay_armor {
			model	= "TAE_acklay_vests";
			owner	= "Acklay";
		};
		class tae_acklay_niteowl_armor {
			model	= "TAE_acklay_vests";
			owner	= "Niteowl";
		};
		class tae_stasik_armor {
			model	= "TAE_acklay_vests";
			owner	= "Stasik";
		};
		class tae_jimothy_armor {
			model	= "TAE_acklay_vests";
			owner	= "Jimothy";
		};
		class tae_frenk_armor {
			model	= "TAE_acklay_vests";
			owner	= "Frenk";
		};
		
		//Foxx
		class tae_foxx_armor {
			model	= "TAE_foxx_vests";
			owner	= "Standard";
			
		};
		class tae_juno_armor {
			model	= "TAE_foxx_vests";
			owner	= "Juno";
		};
		class tae_galaxy_armor {
			model	= "TAE_foxx_vests";
			owner	= "Galaxy";
		};

		// Varen
		class tae_varen_recon_armor {
			model	= "TAE_varen_vests";
			owner	= "Standard";
		};
		class tae_varen_niteowl_armor {
			model	= "TAE_varen_vests";
			owner	= "Niteowl";
		};
		class tae_haranverd_traditional_armor {
			model = "TAE_haranverd_vests";
			style = "Traditional";
		};
		class tae_haranverd_niteowl_armor {
			model = "TAE_haranverd_vests";
			style = "Niteowl";
		};
		class tae_rook_armor {
			model	= "TAE_rook_vests";
			owner	= "Standard";
		};
		class tae_hades_armor {
			model	= "TAE_rook_vests";
			owner	= "Hades";
		};
		class tae_andora_armor {
			model	= "TAE_rook_vests";
			owner	= "Andora";
		};
		class tae_goostivool_armor {
			model	= "TAE_rook_vests";
			owner	= "Goostivool";
		};
	};
};

class CfgWeapons {
	class ItemInfo;
	class VestItem;
	
	// Armor inherits
	class tae_armor_traditional;
	class tae_armor_medium;
	class tae_armor_recon;
	class tae_armor_heavy;
	class tae_armor_battle;
	class tae_armor_war_chief;
	class tae_armor_arbiter;
	class tae_armor_ls_traditional;
	class tae_nite_owl_armor;
	
	// Freelancer Vests
	// House Karr Medium
	class tae_karr_armor_medium_fd : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Medium Armor (Foundling)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\Traditional\MED_Armor_FND.paa",
			"TAEGear\data\HouseKarr\Traditional\MED_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\MED_Armor_FND.paa",
				"TAEGear\data\HouseKarr\Traditional\MED_Brace_FND.paa"
			};
		};
	};
	class tae_karr_armor_medium_mr : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Medium Armor (Mandalorian Recruit)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\Traditional\MED_Armor_Rec.paa",
			"TAEGear\data\HouseKarr\Traditional\MED_Brace_Rec.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\MED_Armor_Rec.paa",
				"TAEGear\data\HouseKarr\Traditional\MED_Brace_Rec.paa"
			};
		};
	};
	class tae_karr_armor_medium_ma : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Medium Armor (Mandalorian Apprentice)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\Traditional\MED_Armor_App.paa",
			"TAEGear\data\HouseKarr\Traditional\MED_Brace_App.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\MED_Armor_App.paa",
				"TAEGear\data\HouseKarr\Traditional\MED_Brace_App.paa"
			};
		};
	};
	class tae_karr_armor_medium_mm : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Medium Armor (Mandalorian)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\Traditional\MED_Armor_Mando.paa",
			"TAEGear\data\HouseKarr\Traditional\MED_Brace_Mando.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\MED_Armor_Mando.paa",
				"TAEGear\data\HouseKarr\Traditional\MED_Brace_Mando.paa"
			};
		};
	};
	class tae_karr_armor_medium_mv : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Medium Armor (Mandalorian Veteran)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\Traditional\MED_Armor_Vet.paa",
			"TAEGear\data\HouseKarr\Traditional\MED_Brace_Vet.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\Traditional\MED_Armor_Vet.paa",
				"TAEGear\data\HouseKarr\Traditional\MED_Brace_Vet.paa"
			};
		};
	};
	// House Karr Nite Owl
	class tae_karr_armor_niteowl_fd : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Armor (Foundling)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_FND.paa",
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_FND.paa",
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
			};
		};
	};
	class tae_karr_armor_niteowl_mr : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Armor (Mandalorian Recruit)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MR.paa",
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MR.paa",
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
			};
		};
	};
	class tae_karr_armor_niteowl_ma : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Armor (Mandalorian Apprentice)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MA.paa",
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MA.paa",
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
			};
		};
	};
	class tae_karr_armor_niteowl_mm : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Armor (Mandalorian)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MM.paa",
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MM.paa",
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
			};
		};
	};
	class tae_karr_armor_niteowl_mv : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "House Karr Nite Owl Armor (Mandalorian Veteran)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MV.paa",
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Armor_MV.paa",
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
			};
		};
	};

	// Hondo
	class tae_hondo_armor : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Hondo's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Hondo\MED_Armor_Hondo.paa",
			"TAEGear\data\Hondo\MED_Brace_Hondo.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Hondo\MED_Armor_Hondo.paa",
				"TAEGear\data\Hondo\MED_Brace_Hondo.paa"
			};
		};
	};
	
	// Teka
	class tae_teka_armor : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Teka";
		displayName = "Teka's Pilot Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Teka\MED_Armor_Teka.paa",
			"TAEGear\data\Teka\MED_Brace_Teka.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Teka\MED_Armor_Teka.paa",
				"TAEGear\data\Teka\MED_Brace_Teka.paa"
			};
		};
	};
	class tae_shyyyo_recon_armor : tae_armor_recon {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Shyyyo Recon Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Shyyyo\REC_Armor_Shyyyo.paa",
			"TAEGear\data\Shyyyo\REC_Brace_Shyyyo.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Shyyyo\REC_Armor_Shyyyo.paa",
				"TAEGear\data\Shyyyo\REC_Brace_Shyyyo.paa"
			};
		};
	};
	
	// Clan Acklay
	class tae_acklay_armor : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Clan Acklay Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Acklay\LS_TRAD_Armor_Acklay.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Acklay\LS_TRAD_Armor_Acklay.paa"
			};
		};
	};
	class tae_acklay_niteowl_armor : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Clan Acklay Nite Owl Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Acklay\NITE_Armor_Acklay.paa",
			"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Acklay\NITE_Armor_Acklay.paa",
				"TAEGear\data\HouseKarr\NiteOwl\NITE_Brace_FND.paa"
			};
		};
	};
	class tae_stasik_armor : tae_armor_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Stasik's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Stasik\TRAD_Armor_Stasik.paa",
			"TAEGear\data\Stasik\TRAD_Brace_Stasik.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Stasik\TRAD_Armor_Stasik.paa",
				"TAEGear\data\Stasik\TRAD_Brace_Stasik.paa"
			};
		};
	};
	// Edonn
	class tae_edonn_armor : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Edonn";
		displayName = "Edonn's Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Edonn\LS_Armor_Edonn.paa"
		};
		hiddenSelectionsMaterials[] = {
			"TAEGear\data\Edonn\LS_Armor_Edonn.rvmat"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Edonn\LS_Armor_Edonn.paa"
			};
			hiddenSelectionsMaterials[] = {
				"TAEGear\data\Edonn\LS_Armor_Edonn.rvmat"
			};
		};
	};

	// Frenk
	class tae_frenk_armor : tae_armor_arbiter {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Frenk's Arbiter Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Frenk\ARB_Armor_Frenk.paa",
			"TAEGear\data\Frenk\ARB_Brace_Frenk.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Frenk\ARB_Armor_Frenk.paa",
				"TAEGear\data\Frenk\ARB_Brace_Frenk.paa"
			};
		};
	};
	
	// Nox
	class tae_nox_armor : tae_armor_heavy {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Nox's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Nox\HEAV_Armor_Nox.paa",
			"TAEGear\data\Nox\HEAV_Brace_Nox.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Nox\HEAV_Armor_Nox.paa",
				"TAEGear\data\Nox\HEAV_Brace_Nox.paa"
			};
		};
	};
	
	//Jimothy
	class tae_jimothy_armor : tae_armor_heavy {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Jimothy's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Jimothy\HEAV_Armor_Jimothy.paa",
			"TAEGear\data\Jimothy\HEAV_Brace_Jimothy.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Jimothy\HEAV_Armor_Jimothy.paa",
				"TAEGear\data\Jimothy\HEAV_Brace_Jimothy.paa"
			};
		};
	};

	// Clan Foxx
	class tae_foxx_armor : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Juno";
		displayName = "Clan Foxx Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Foxx\MED_Armor_Foxx.paa",
			"TAEGear\data\Foxx\MED_Brace_Foxx.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Foxx\MED_Armor_Foxx.paa",
				"TAEGear\data\Foxx\MED_Brace_Foxx.paa"
			};
		};
	};
	class tae_juno_armor : tae_armor_heavy {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Juno";
		displayName = "Juno's Heavy Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Juno\HEAV_Armor_Juno.paa",
			"TAEGear\data\Juno\HEAV_Brace_Juno.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Juno\HEAV_Armor_Juno.paa",
				"TAEGear\data\Juno\HEAV_Brace_Juno.paa"
			};
		};
	};
	class tae_galaxy_armor : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Galaxy";
		displayName = "Galaxy's Medium Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Galaxy\MED_Armor_Galaxy.paa",
			"TAEGear\data\Galaxy\MED_Brace_Galaxy.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Galaxy\MED_Armor_Galaxy.paa",
				"TAEGear\data\Galaxy\MED_Brace_Galaxy.paa"
			};
		};
	};
	// Clan Varen
	class tae_varen_recon_armor : tae_armor_recon {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Valeria";
		displayName = "Clan Varen Recon Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Varen\REC_Armor_Varen.paa",
			"TAEGear\data\Varen\REC_Brace_Varen.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Varen\REC_Armor_Varen.paa",
				"TAEGear\data\Varen\REC_Brace_Varen.paa"
			};
		};
	};
	class tae_varen_niteowl_armor : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Valeria";
		displayName = "Clan Varen Nite Owl Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Varen\NITE_Armor_Varen.paa",
			"TAEGear\data\Varen\NITE_Brace_Varen.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Varen\NITE_Armor_Varen.paa",
				"TAEGear\data\Varen\NITE_Brace_Varen.paa"
			};
		};
	};

	// Clan Haranverd
	class tae_haranverd_traditional_armor : tae_armor_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Clan Haranverd Traditional Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Haranverd\TRAD_Armor_Haranverd.paa",
			"\z\tgf\addons\armour\light_armour\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Haranverd\TRAD_Armor_Haranverd.paa",
				"\z\tgf\addons\armour\light_armour\data\camo2_co.paa"
			};
		};
	};

	class tae_haranverd_niteowl_armor : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Clan Haranverd Nite Owl Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Haranverd\NITE_Armor_Haranverd.paa",
			"\z\tgf\addons\armour\nite_owl_armour\data\camo2_co.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Haranverd\NITE_Armor_Haranverd.paa",
				"\z\tgf\addons\armour\nite_owl_armour\data\camo2_co.paa"
			};
		};
	};
	// Clan Rook
	class tae_rook_armor : tae_armor_battle {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Clan Rook Battle Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Rook\BAT_Armor_Rook.paa",
			"TAEGear\data\Rook\BAT_Brace_Rook.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Rook\BAT_Armor_Rook.paa",
				"TAEGear\data\Rook\BAT_Brace_Rook.paa"
			};
		};
	};
	class tae_hades_armor : tae_armor_war_chief {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Lanval";
		displayName = "Hades' War Chief Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Hades\WAR_Armor_Hades.paa",
			"TAEGear\data\Hades\WAR_Brace_Hades.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Hades\WAR_Armor_Hades.paa",
				"TAEGear\data\Hades\WAR_Brace_Hades.paa"
			};
		};
	};
	class tae_andora_armor : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Jimothy";
		displayName = "Andora's Nite Owl Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Andora\NITE_Armor_Andora.paa",
			"TAEGear\data\Andora\NITE_Brace_Andora.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Andora\NITE_Armor_Andora.paa",
				"TAEGear\data\Andora\NITE_Brace_Andora.paa"
			};
		};
	};
	class tae_goostivool_armor : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nox";
		displayName = "Goostivool's Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Goostivool\LS_Armor_Goostivool.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Goostivool\LS_Armor_Goostivool.paa"
			};
		};
	};
};
