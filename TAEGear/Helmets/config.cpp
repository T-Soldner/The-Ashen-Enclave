class CfgPatches {
	class TAEGear_Helmets {
		addonRootClass = "TAEGear";
		requiredVersion = 1.60;
		requiredAddons[] = { "A3_Characters_F", "tgf_helmets", "tgf_nvg", "ls_characters_mandalorian" };
		units[] = { };
		weapons[] = { };
	};
};
class CfgFunctions {
	class TAE {
		class Gear {
			file = "\TAEGear\Helmets\functions";
			class initHelmetDivingVision {
				postInit = 1;
			};
		};
	};
};
class CfgWeapons {
	
	class ItemInfo;
	class HeadgearItem;
	
	//helmet inherts
	class tgf_helmets_battle_master;
	class tgf_helmets_gunslinger;
	class tgf_helmets_gunslinger_vet;
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
	class ls_mandalorianHelmet_dinDjarin;
	class ls_mandalorianHelmet_executioner;
	class ls_mandalorianHelmet_armorer;
	
	//actual armor
	class tae_helmet_traditional : tgf_helmets_traditional { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		scopeArsenal = 0;
		scopeCurator = 0;
		displayname = "Mandalorian Traditional Helmet";
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		displayname = "Mandalorian Gunslinger Helmet (Standard)";
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
	class tae_helmet_gunslinger_vet : tgf_helmets_gunslinger_vet {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayname = "Mandalorian Gunslinger Veteran Helmet";
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
			Uniformmodel = "\z\tgf\addons\helmets\gunslinger_vet\gunslinger_vet.p3d";
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
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
	class tae_helmet_ls_dinDjarin : ls_mandalorianHelmet_dinDjarin { 
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Mandalorian Din Djarin Helmet (LS)";
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
			uniformModel = "\ls\core\addons\characters_mandalorian\helmets\dinDjarin\ls_helmet_mandalorian_dinDjarin.p3d";
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
	class tae_helmet_ls_executioner : ls_mandalorianHelmet_executioner {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Mandalorian Executioner Helmet (LS)";
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
			uniformModel = "\ls\core\addons\characters_mandalorian\helmets\executioner\ls_helmet_mandalorian_executioner.p3d";
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
	class tae_helmet_ls_armorer : ls_mandalorianHelmet_armorer {
		dlc = "The Ashen Enclave AUX Mod";
		scope = 0;
		displayName = "Mandalorian Armorer Helmet (LS)";
		TAE_underwaterVision = 1;
		TAE_HUD = 1;
		class ItemInfo : HeadgearItem {
			mass = 40;
			uniformModel = "\ls\core\addons\characters_mandalorian\helmets\armorer\ls_helmet_mandalorian_armorer.p3d";
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
		ace_nightvision_eyeCups = 0;
		ace_nightvision_generation = 4;
		class ItemInfo: ItemInfo {
			uniformModel = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_on.p3d";
			modelOff = "\ls\core\addons\characters_mandalorian\equipment\nvgs\rangefinder\ls_mandalorian_rangefinder_nvg_off.p3d";
			hiddenSelections[] = {"camo1"};
		};
	};
	
};

class CfgGlasses {
	class None;
	class G_Diving;

	class tae_facewear_helmet_diving_visor: G_Diving {
		scope = 1;
		scopeArsenal = 0;
		displayName = "TAE Integrated Diving Visor";
		model = "";
		picture = "";
		identityTypes[] = {};
		mass = 0;
		mode = 1;
	};

	class tae_facewear_ls_neck_lining: None {
		dlc = "The Ashen Enclave AUX Mod";
		author = "TAE Mod Team";
		scope = 2;
		scopeArsenal = 2;
		displayName = "TAE Neck Seal";
		model = "\z\tgf\addons\undersuit\undersuit_male.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"",
			"\z\tgf\addons\undersuit\data\camo2_co.paa"
		};
		identityTypes[] = {};
		mass = 2;
	};
};
