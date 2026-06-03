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
			"tae_acklay_armor",
			"tae_acklay_niteowl_armor",
			"tae_edonn_armor",
			"tae_nox_armor",
			"tae_jimothy_armor",
			"tae_foxx_armor",
			"tae_varen_recon_armor",
			"tae_rook_armor"
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
				values[] = { "Hondo","Teka","Nox" };
				class Hondo {
					label = "Hondo";
				};
				class Teka {
					label = "Teka";
				};
				class Nox {
					label = "Nox";
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
				values[] = { "Standard","Niteowl","Edonn","Jimothy" };
				class Standard {
					label = "Standard";
				};
				class Niteowl {
					label = "Nite owl";
				};
				class Edonn {
					label = "Edonn";
				};
				class Jimothy {
					label = "Jimothy";
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
				values[] = { "Standard" };
				class Standard {
					label = "Standard";
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
				values[] = { "Standard" };
				class Standard {
					label = "Standard";
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
				values[] = { "Standard" };
				class Standard {
					label = "Standard";
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
		class tae_teka_armor {
			model	= "TAE_freelancer_vests";
			owner	= "Teka";
		};
		class tae_nox_armor {
			model	= "TAE_freelancer_vests";
			owner	= "Nox";
		};
		
		//Acklay
		class tae_acklay_armor {
			model	= "TAE_acklay_vests";
			owner	= "Standard";
		};
		class tae_acklay_niteowl_armor {
			model	= "TAE_acklay_vests";
			owner	= "Niteowl";
		};
		class tae_edonn_armor {
			model	= "TAE_acklay_vests";
			owner	= "Edonn";
		};
		class tae_jimothy_armor {
			model	= "TAE_acklay_vests";
			owner	= "Jimothy";
		};
		
		//Foxx
		class tae_foxx_armor {
			model	= "TAE_foxx_vests";
			owner	= "Standard";
			
		};

		// Varen
		class tae_varen_recon_armor {
			model	= "TAE_varen_vests";
			owner	= "Standard";
		};
		class tae_rook_armor {
			model	= "TAE_rook_vests";
			owner	= "Standard";
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
		author = "Soldner";
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
		author = "Soldner";
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
		author = "Soldner";
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
		author = "Soldner";
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
		author = "Soldner";
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
		displayName = "House Karr Medium Armor (Foundling)";
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
	
	// Clan Acklay
	class tae_acklay_armor : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
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
		author = "Soldner";
		displayName = "House Karr Nite Owl Armor (Mandalorian Veteran)";
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
	// Edonn
	class tae_edonn_armor : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Edonn's Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Edonn\LS_Armor_Edonn.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Edonn\LS_Armor_Edonn.paa"
			};
		};
	};
	
	// Nox
	class tae_nox_armor : tae_armor_heavy {
		scope = 1;
		scopeArsenal = 1;
		scopeCurator = 1;
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
		scope = 1;
		scopeArsenal = 1;
		scopeCurator = 1;
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
		author = "Juno Foxx";
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
	// Clan Varen
	class tae_varen_recon_armor : tae_armor_recon {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
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
	// Clan Rook
	class tae_rook_armor : tae_armor_battle {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
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
};
