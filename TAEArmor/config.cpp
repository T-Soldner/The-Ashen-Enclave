class CfgPatches {
	class TAEArmor {
		// Meta information for editor
		name = "The Ashen Enclave AUX Mod";
		author = "TAE Mod Team";
		url = "https://discord.gg/9zgGp5QSW7";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game. Note: was disabled on purpose some time late into Arma 2: OA.
		requiredVersion = 1.60;
		// Required addons, used for setting load order. (CfgPatches classname NOT PBO filename!)
		// When any of the addons are missing, a pop-up warning will appear when launching the game.
		requiredAddons[] = { "A3_Data_F_Decade_Loadorder","tgf_armour","tgf_helmets","ls_characters_mandalorian" };
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content (units and groups) unlocking.
		units[] = {};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {};

		// Optional. If this is 1, if any of requiredAddons[] entry is missing in your game the entire config will be ignored and return no error (but in rpt) so useful to make a compat Mod (Since Arma 3 2.14)
		skipWhenMissingDependencies = 1;
	};
};
class CfgWeapons {
	
	class ItemInfo;
	class HeadgearItem;
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

	//helmet inherts
	class tgf_helmets_battle_master;
	class tgf_helmets_gunslinger;
	class tgf_helmets_warlord;
	class tgf_helmets_viper;
	class tgf_helmets_heavy;
	class tgf_helmets_pilot;
	class tgf_helmets_traditional;
	class tgf_helmets_shrike;
	class tgf_helmets_arbiter;
	class tgf_helmets_war_chief;
	class ls_mandalorianHelmet_traditional;
	class tgf_helmets_nite_owl;
	
	//actual armor
	class tae_helmet_traditional : tgf_helmets_traditional { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		scopeArsenal = 0;
		scopeCurator = 0;
		displayname = "Mandalorian Traditional Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_battle_master : tgf_helmets_battle_master { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Battle Master Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\battle_master\battle_master.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_gunslinger : tgf_helmets_gunslinger { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Gunslinger Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\gunslinger\gunslinger.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_warlord : tgf_helmets_warlord { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Warlord Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\warlord\warlord_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_viper : tgf_helmets_viper { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Viper Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\viper\viper_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_heavy : tgf_helmets_heavy { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Heavy Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\heavy\heavy_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_pilot : tgf_helmets_pilot { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Pilot Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\pilot\pilot_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_shrike : tgf_helmets_shrike { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Shrike Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\shrike\shrike.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_arbiter : tgf_helmets_arbiter { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Arbiter Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\arbiter\arbiter_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_war_chief : tgf_helmets_war_chief { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian War Chief Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\war_chief\war_chief.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_nite_owl : tgf_helmets_nite_owl { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Nite Owl Helmet";
		class ItemInfo : HeadgearItem {
			Uniformmodel = "\z\tgf\addons\helmets\nite_owl\nite_owl_helmet.p3d";
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};
	class tae_helmet_ls_traditional : ls_mandalorianHelmet_traditional { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Mandalorian Traditional Helmet (LS)";
		class ItemInfo : HeadgearItem {
			uniformModel = "\ls\core\addons\characters_mandalorian\helmets\traditional\ls_helmet_mandalorian_traditional.p3d";
			hiddenSelections[] = {"camo1","visor","neckTex"};
			class HitpointsProtectionInfo {
				class Face {
					armor = 15;
					hitpointName = "HitFace";
					passThrough = 0.3;
				};
				class Head {
					armor = 15;
					hitPointName = "HitHead";
					passThrough = 0.3;
				};
				class Neck {
					armor = 15;
					hitpointName = "HitNeck";
					passThrough = 0.3;
				};
			};
		};
	};

	//NVG
	class ls_mandalorian_rangefinder;
	class tae_ls_mandalorian_rangefinder: ls_mandalorian_rangefinder {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Mandalorian Rangefinder";
		model = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_on.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\ls\core\addons\characters_mandalorian\helmets\original\data\original_co.paa"};
		visionMode[] = {"Normal","NVG","TI"};
		thermalMode[] = {0,1};
		class ItemInfo: ItemInfo {
			uniformModel = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_on.p3d";
			modelOff = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_off.p3d";
			hiddenSelections[] = {"camo1"};
		};
	};
};
