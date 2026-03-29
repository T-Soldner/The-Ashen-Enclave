class CfgPatches
{
	class TAEArmor
	{
		// Meta information for editor
		name = "The Ashen Enclave AUX Mod";
		author = "TAE Mod Team";
		url = "https://discord.gg/9zgGp5QSW7";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game. Note: was disabled on purpose some time late into Arma 2: OA.
		requiredVersion = 1.60;
		// Required addons, used for setting load order. (CfgPatches classname NOT PBO filename!)
		// When any of the addons are missing, a pop-up warning will appear when launching the game.
		requiredAddons[] = { "A3_Data_F_Decade_Loadorder","tgf_armour" };
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content (units and groups) unlocking.
		units[] = {};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {};

		// Optional. If this is 1, if any of requiredAddons[] entry is missing in your game the entire config will be ignored and return no error (but in rpt) so useful to make a compat Mod (Since Arma 3 2.14)
		skipWhenMissingDependencies = 1;
	};
};
class CfgWeapons {
	//Armor inherts
	class tgf_armour_light_armour;
	class tgf_armour_medium_armour;
	class tgf_armour_super_light_armour;
	class tgf_armour_heavy_armour;
	class tgf_armour_battle_armour;
	class tgf_armour_war_chief_armour;
	class tgf_armour_arbiter_armour;
	class ls_mandalorianVest_standard;
	class ItemInfo;
	
	//actual Armor
	class tae_armor_traditional : tgf_armour_light_armour {
		scope = 2;
		displayName = "Traditional Mandalorian Armour";
		descriptionShort = "Traditional Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\traditional1.paa","TAEArmor\data\traditional2.paa"};
	};
	class tae_armor_medium : tgf_armour_medium_armour {
		scope = 1;
		displayName = "Medium Mandalorian Armour";
		descriptionShort = "Medium Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\medium1.paa","TAEArmor\data\medium2.paa"};
	};
	class tae_armor_recon : tgf_armour_super_light_armour {
		scope = 1;
		displayName = "Recon Mandalorian Armour";
		descriptionShort = "Recon Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\recon1.paa","TAEArmor\data\recon2.paa"};
	};
	class tae_armor_heavy : tgf_armour_heavy_armour {
		scope = 1;
		displayName = "Heavy Mandalorian Armour";
		descriptionShort = "Heavy Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\heavy1.paa","TAEArmor\data\heavy2.paa"};
	};
	class tae_armor_battle : tgf_armour_battle_armour {
		scope = 1;
		displayName = "Battle Mandalorian Armour";
		descriptionShort = "Battle Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\battle1.paa","TAEArmor\data\battle2.paa"};
	};
	class tae_armor_war_chief : tgf_armour_battle_armour {
		scope = 1;
		displayName = "War Chief Mandalorian Armour";
		descriptionShort = "War Chief Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\warchief1.paa","TAEArmor\data\warchief2.paa"};
	};
	class tae_armor_arbiter : tgf_armour_battle_armour {
		scope = 1;
		displayName = "Arbiter Mandalorian Armour";
		descriptionShort = "Arbiter Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\arbiter1.paa","TAEArmor\data\arbiter2.paa"};
	};
	class tae_armor_acklay : ls_mandalorianVest_standard {
		author = "Soldner";
		displayName = "Clan Acklay Armor";
		scope = 2;
		scopeArsenal = 2;
		hiddenSelectionsTextures[] = {"TAEArmor\data\acklay_vest_co.paa"};
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
	
	//actual armor
	class tae_helmet_traditional : tgf_helmets_traditional { 
		scope = 2;
		displayname = "Mandalorian traditional Helmet";
		hiddenSelectionsTextures[] = {"TAEArmor\data\traditionalhelmet.paa","\z\tgf\addons\helmets\forgemaster\data\camo2_co.paa"};
	};
	class tae_helmet_battle_master : tgf_helmets_battle_master { 
		scope = 1;
		displayname = "Mandalorian Battle Master Helmet";
	};
	class tae_helmet_gunslinger : tgf_helmets_gunslinger { 
		scope = 1;
		displayname = "Mandalorian Gunslinger Helmet";
	};
	class tae_helmet_warlord : tgf_helmets_warlord { 
		scope = 1;
		displayname = "Mandalorian Warlord Helmet";
	};
	class tae_helmet_viper : tgf_helmets_viper { 
		scope = 1;
		displayname = "Mandalorian Viper Helmet";
	};
	class tae_helmet_heavy : tgf_helmets_heavy { 
		scope = 1;
		displayname = "Mandalorian Heavy Helmet";
	};
	class tae_helmet_pilot : tgf_helmets_pilot { 
		scope = 1;
		displayname = "Mandalorian Pilot Helmet";
	};
	class tae_helmet_shrike : tgf_helmets_shrike { 
		scope = 1;
		displayname = "Mandalorian Shrike Helmet";
	};
	class tae_helmet_arbiter : tgf_helmets_arbiter { 
		scope = 1;
		displayname = "Mandalorian Arbiter Helmet";
	};
	class tae_helmet_war_chief : tgf_helmets_war_chief { 
		scope = 1;
		displayname = "Mandalorian War Chief Helmet";
	};
	class tae_helmet_acklay : ls_mandalorianHelmet_traditional { 
		author = "Soldner";
		displayName = "Clan Acklay Helmet";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"TAEArmor\data\acklay_helmet_co.paa",
			"TAEArmor\data\acklay_visor_co.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
	};
};
