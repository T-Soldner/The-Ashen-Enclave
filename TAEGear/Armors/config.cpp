class CfgPatches {
	class TAEGear_Armors {
		addonRootClass = "TAEGear";
		requiredVersion = 1.60;
		requiredAddons[] = { "tgf_armour","ls_characters_mandalorian" };
		units[] = { };
		weapons[] = {
			"tae_armor_traditional",
			"tae_armor_medium",
			"tae_armor_recon",
			"tae_armor_heavy",
			"tae_armor_battle",
			"tae_armor_war_chief",
			"tae_armor_arbiter",
			"tae_armor_ls_traditional",
			"tae_nite_owl_armor"
		};
	};
};
class CfgWeapons {
	
	class ItemInfo;
	class VestItem;
	
	//Armor inherts
	class tgf_armour_light_armour;
	class tgf_armour_medium_armour;
	class tgf_armour_super_light_armour;
	class tgf_armour_heavy_armour;
	class tgf_armour_battle_armour;
	class tgf_armour_war_chief_armour;
	class tgf_armour_arbiter_armour;
	class ls_mandalorianVest_standard;
	class tgf_armour_nite_owl_armour;
	
	//actual Armor
	class tae_armor_traditional : tgf_armour_light_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		scopeArsenal = 0;
		displayName = "Traditional Mandalorian Armor";
		descriptionShort = "Traditional Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\light_armour\light_armour.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_medium : tgf_armour_medium_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Medium Mandalorian Armor";
		descriptionShort = "Medium Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\medium_armour\medium_armour.p3d";
			
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_recon : tgf_armour_super_light_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Recon Mandalorian Armor";
		descriptionShort = "Recon Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\super_light_armour\super_light_armour.p3d";
			
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_heavy : tgf_armour_heavy_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Heavy Mandalorian Armor";
		descriptionShort = "Heavy Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\heavy_armour\heavy_armour.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_battle : tgf_armour_battle_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Battle Mandalorian Armor";
		descriptionShort = "Battle Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\battle_armour\battle_armour.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_war_chief : tgf_armour_war_chief_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "War Chief Mandalorian Armor";
		descriptionShort = "War Chief Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\war_chief_armour\war_chief_armour.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_arbiter : tgf_armour_arbiter_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Arbiter Mandalorian Armor";
		descriptionShort = "Arbiter Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\arbiter_armour\arbiter_armour.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_armor_ls_traditional : ls_mandalorianVest_standard {
		dlc = "The Ashen Enclave AUX Mod";
		author = "Soldner";
		displayName = "Traditional Mandalorian Armor (LS)";
		scope = 0;
		class ItemInfo: VestItem {
			uniformModel = "\ls\core\addons\characters_mandalorian\vests\standard\ls_vest_mandalorian.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest {
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm {
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen {
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis {
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms {
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands {
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs {
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_nite_owl_armor : tgf_armour_nite_owl_armour {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Nite Owl Mandalorian Armor";
		descriptionShort = "Nite Owl Mandalorian Armor";
		class ItemInfo: VestItem {
			Uniformmodel = "\z\tgf\addons\armour\nite_owl_armour\nite_owl_armour.p3d";
			containerClass = "Supply300";
			mass = 20;
			passThrough = 0.3;
			modelSides[] = { 6 };
			class HitpointsprotectionInfo {
				class Neck {
					hitPointName = "HitNeck";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Chest
				{
					hitPointName = "HitChest";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Diaphragm
				{
					hitPointName = "HitDiaphragm";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Abdomen
				{
					hitPointName = "HitAbdomen";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Pelvis
				{
					hitPointName = "HitPelvis";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Arms
				{
					hitPointName = "HitArms";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Hands
				{
					hitPointName = "HitHands";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
				class Legs
				{
					hitPointName = "HitLegs";
					armor = 10;
					explosionshielding = 10;
					passThrough = 0.3;
				};
			};
		};
	};
};
