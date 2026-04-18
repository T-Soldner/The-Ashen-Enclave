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
		tf_isolatedAmount = 0.65;
		tf_encryptionCode = "tf_west_radio_code";
		tf_dialog = "anarc210_radio_dialog";
		tf_subtype = "digital_lr";
		tf_range = 25000;
		tf_dialogUpdate = "[""%1""] call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio = 1;
	};
	
	
	/*
	//Jennas jumppacks test
	class Bag_Base;
	class tae_jetpack : Bag_Base {
		scope = 1;
		displayName = "TAE base";
		picture = "\z\tgf\addons\backpacks\jt12\data\JT12.paa";
		tas_is_jetpack = 0;
		maximumload = 500;
		jen_jetpacks_core_isJetpack = 1;
		jen_jetpacks_core_acceleration = 2;
		jen_jetpacks_core_drag = 6;
		mass = 50;
		jen_jetpacks_core_fuelCoef = 1;
		jen_jetpacks_core_heatCoef = 1;
		jen_jetpacks_core_coolCoef = 1;
		jen_jetpacks_core_ascensionCoef = 1;
		jen_jetpacks_core_jumpCoef = 1;
		jen_jetpacks_core_fuelCapacity = 250;
		jen_jetpacks_core_strafeCoef = 1;
	};
	class tae_hondo_JT12_LR : tae_jetpack {
		scope = 2;
		displayName = "Hondo's JT-12 Jetpack";
		descriptionShort = "Hondo's JT-12 Jetpack";
		model = "\z\tgf\addons\backpacks\jt12\jt12_jetpack.p3d";
		hiddenSelectionsTextures[] = {"TAEGear\data\JT12_Hondo.paa"};
		picture = "\z\tgf\addons\backpacks\jt12\data\JT12.paa";
		tf_hasLRradio = 1;
		tf_range = 13500;
	};
	class tae_edonn_J6 : tae_jetpack {
		scope = 2;
		model = "\z\tgf\addons\backpacks\z6\z6_jetpack.p3d";
		displayName = "Edonn's Z-6 Jetpack";
		descriptionShort = "Edonn's Z-6 Jetpack";
		hiddenSelectionsTextures[] = {"TAEGear\data\Edonn_Z6_CO.paa"};
		picture = "\z\tgf\addons\backpacks\z6\data\Z6.paa";
	};*/
};