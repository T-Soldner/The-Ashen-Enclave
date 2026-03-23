class CfgPatches
{
	class TAEArmor_Custom
	{
		addonRootClass = "TAEArmor";

		requiredVersion = 1.60;
		requiredAddons[] = { "TAEArmor" };
		units[] = {};
		weapons[] = {};
	};
};
class CfgWeapons
{
	//Armor inherits
	class tae_armor_traditional;
	class tae_armor_medium;
	class tae_armor_recon;
	class tae_armor_heavy;
	class tae_armor_battle;
	class tae_armor_war_chief;
	class tae_armor_arbiter;

	//helmet inherts
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
	
	//Hondo
	class tae_hondo_armor : tae_armor_traditional {
		scope = 2;
		displayName = "Hondo's Armor";
		hiddenSelectionsTextures[] = {"TAEArmor\data\hondo1.paa","TAEArmor\data\hondo2.paa"};		
	};
	class tae_hondo_helmet : tae_helmet_battle_master {
		scope = 2;
		displayName = "Hondo's Helmet";
		hiddenSelectionsTextures[] = {"TAEArmor\data\hondohelmet.paa","\z\tgf\addons\helmets\forgemaster\data\camo2_co.paa"};
	};
};
