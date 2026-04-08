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
			"tae_karr_armor_nite_owl_fd",
			"tae_hondo_armor",
			"tae_armor_acklay",
			"tae_edonn_armor",
			"tae_nox_armor"
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
				values[] = { "Hondo" };
				class Hondo {
					label = "Hondo";
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
				values[] = { "Standard","Edonn","Nox" };
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
		class tae_karr_armor_niteowl_fd {
			model	= "TAE_standard_vests";
			role	= "Foundling";
			armor 	= "Niteowl";
		};
		//Freelancer
		class tae_hondo_armor {
			model	= "TAE_freelancer_vests";
			owner	= "Standard";
		};
		//Acklay
		class tae_armor_acklay {
			model	= "TAE_acklay_vests";
			owner	= "Standard";
		};
		class tae_edonn_armor {
			model	= "TAE_acklay_vests";
			owner	= "Edonn";
		};
		class tae_nox_armor {
			model	= "TAE_acklay_vests";
			owner	= "Nox";
		};
	};
};

class CfgWeapons {
	class ItemInfo;
	class VestItem;
	
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
	
	//House Karr
	class tae_karr_armor_medium_fd : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Nova";
		displayName = "House Karr Medium Armor (Foundling)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Med_Armor_FND.paa",
			"TAEGear\data\Med_Brace_FND.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Med_Armor_FND.paa",
				"TAEGear\data\Med_Brace_FND.paa"
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
			"TAEGear\data\Med_Armor_Rec.paa",
			"TAEGear\data\Med_Brace_Rec.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Med_Armor_Rec.paa",
				"TAEGear\data\Med_Brace_Rec.paa"
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
			"TAEGear\data\Med_Armor_Appren.paa",
			"TAEGear\data\Med_Brace_Appren.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Med_Armor_Appren.paa",
				"TAEGear\data\Med_Brace_Appren.paa"
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
			"TAEGear\data\Med_Armor_Mando.paa",
			"TAEGear\data\Med_Brace_Mando.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Med_Armor_Mando.paa",
				"TAEGear\data\Med_Brace_Mando.paa"
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
			"TAEGear\data\Med_Armor_Vet.paa",
			"TAEGear\data\Med_Brace_Vet.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Med_Armor_Vet.paa",
				"TAEGear\data\Med_Brace_Vet.paa"
			};
		};
	};
	class tae_karr_armor_niteowl_fd : tae_nite_owl_armor {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "House Karr Nite Owl Armor (Foundling)";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\niteowl1.paa",
			"TAEGear\data\niteowl2.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\niteowl1.paa",
				"TAEGear\data\niteowl2.paa"
			};
		};
	};

	//Hondo
	class tae_hondo_armor : tae_armor_medium {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Hondo's Armor";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Med_Armor_Hondo.paa",
			"TAEGear\data\Med_Brace_Hondo.paa"
		};

		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Med_Armor_Hondo.paa",
				"TAEGear\data\Med_Brace_Hondo.paa"
			};
		};
	};
	
	//Clan Acklay
	class tae_armor_acklay : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Clan Acklay Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\acklay_vest_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\acklay_vest_co.paa"
			};
		};
	};
	
	//Edonn
	class tae_edonn_armor : tae_armor_ls_traditional {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Edonn's Armor";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Edonn_Vest_co.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Edonn_Vest_co.paa"
			};
		};
	};
	
	//Nox
	class tae_nox_armor : tae_armor_arbiter {
		scope = 1;
		scopeArsenal = 1;
		scopeCurator = 1;
		author = "Nox";
		displayName = "Nox's Armor";
		hiddenSelections[] = {"camo1","camo2","camo3"};
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Arb_Armor_Nox.paa",
			"TAEGear\data\Arb_Brace_Nox.paa",
			"TAEGear\data\Arb_Gaunt_Nox.paa"
		};
		class ItemInfo : ItemInfo {
			hiddenSelections[] = {"camo1","camo2","camo3"};
			hiddenSelectionsTextures[] = {
				"TAEGear\data\Arb_Armor_Nox.paa",
				"TAEGear\data\Arb_Brace_Nox.paa",
				"TAEGear\data\Arb_Gaunt_Nox.paa"
			};
		};
	};
};
