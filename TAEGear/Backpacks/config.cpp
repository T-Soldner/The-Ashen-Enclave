class CfgPatches {
	class TAEGear_Backpacks {
		addonRootClass = "TAEGear";
		requiredVersion = 1.60;
		requiredAddons[] = { "tgf_backpacks" };
		units[] = { "tae_hondo_JT12" };
		weapons[] = { };
	};
};

class CfgVehicles {
	//inherits
	class tgf_backpacks_JT12_LR;
	class tgf_backpacks_Z6;
	
	class tae_hondo_JT12 : tgf_backpacks_JT12_LR {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Hondo";
		displayName = "Hondo's JT-12 Jetpack";
		descriptionShort = "Hondo's JT-12 Jetpack";
		hiddenSelectionsTextures[] = {"TAEGear\data\JT12_Hondo.paa"};
	};
	class tae_edonn_J6 : tgf_backpacks_Z6 {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "Soldner";
		displayName = "Edonn's Z-6 Jetpack";
		descriptionShort = "Edonn's Z-6 Jetpack";
		hiddenSelectionsTextures[] = {"TAEGear\data\Edonn_Z6_CO.paa"};
	};
};