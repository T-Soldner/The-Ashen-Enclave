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
class CfgWeapons
{
	class tgf_armour_light_armour;
	class tae_armor_havoc: tgf_armour_light_armour
	{
		scope = 2;
		displayName = "Havoc's Mandalorian Armour";
		descriptionShort = "Havoc's Mandalorian Armour";
		hiddenSelectionsTextures[] = {"TAEArmor\data\havocretard1.paa","TAEArmor\data\havocretard2.paa"};
	};
};
