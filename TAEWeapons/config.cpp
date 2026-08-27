class CfgPatches {
	class TAEWeapons {
		name = "The Ashen Enclave AUX Mod";
		author = "TAE Mod Team";
		url = "https://discord.gg/9zgGp5QSW7";
		requiredVersion = 1.60;
		requiredAddons[] = { "IDA_INDEP", "mti_armoury_weapons_hpb" };
		units[] = {};
		weapons[] = {
			"tae_TargetingScope_FP2",
			"tae_IQA12",
			"tae_HPB14"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgAmmo {
	class mti_armoury_ammo_hpb_base;
	class mti_armoury_ammo_hpb_scatter;
	class mti_armoury_ammo_Shotgun_Sub_HP;

	class tae_ammo_HPB14 : mti_armoury_ammo_hpb_base {
		hit = 4.5;
		caliber = 2;
		indirectHit = 0;
		indirectHitRange = 0;
	};

	class tae_ammo_HPB14_scatter_pellet : mti_armoury_ammo_Shotgun_Sub_HP {
		hit = 3;
		caliber = 1;
		indirectHit = 0;
		indirectHitRange = 0;
	};

	class tae_ammo_HPB14_scatter : mti_armoury_ammo_hpb_scatter {
		hit = 3;
		caliber = 1;
		indirectHit = 0;
		indirectHitRange = 0;
		submunitionAmmo = "tae_ammo_HPB14_scatter_pellet";
	};
};

class CfgMagazines {
	class mti_armoury_mag_HPB;
	class mti_armoury_mag_hpb_underbarrel;

	class tae_mag_HPB14 : mti_armoury_mag_HPB {
		author = "TAE Mod Team";
		dlc = "The Ashen Enclave AUX Mod";
		displayName = "HPB-14 150rnd Reduced-Power Energy Cell";
		displayNameShort = "Reduced Power";
		descriptionShort = "Reduced-power energy cell for the TAE HPB-14";
		ammo = "tae_ammo_HPB14";
	};

	class tae_mag_HPB14_scatter : mti_armoury_mag_hpb_underbarrel {
		author = "TAE Mod Team";
		dlc = "The Ashen Enclave AUX Mod";
		displayName = "HPB-14 10rnd Reduced-Power Scatter Cell";
		displayNameShort = "Reduced-Power Scatter";
		descriptionShort = "Reduced-power scatter cell for the TAE HPB-14";
		ammo = "tae_ammo_HPB14_scatter";
	};
};

class CowsSlot;

class CfgWeapons {
	class InventoryOpticsItem_Base_F;
	class WeaponSlotsInfo;

	class IDA_TargetingScope;
	class IDA_IQA11;
	class mti_armoury_weapon_hpb {
		class Standard;
		class Heavy;
	};

	class tae_TargetingScope_FP2 : IDA_TargetingScope {
		scope = 2;
		scopeArsenal = 2;
		dlc = "The Ashen Enclave AUX Mod";
		author = "Edonn";
		displayName = "FP-2 Targeting Scope";

		class ItemInfo : InventoryOpticsItem_Base_F {
			mass = 10;
			optics = 1;
			modelOptics = "\A3\Weapons_F\acc\reticle_lrps_F";
			allowedSlots[] = {801,701,901};

			class OpticsModes {
				class IDA_TargetingScope {
					opticsID = 2;
					useModelOptics = 1;
					opticsPPEffects[] = {"OpticsRadialBlur1","OpticsBlur1"};
					opticsZoomMin = 0.0083;
					opticsZoomMax = 0.05;
					opticsZoomInit = 0.05;
					discreteDistance[] = {200};
					discreteDistanceInitIndex = 0;
					discreteInitIndex = 0;
					discretefov[] = {0.05,0.025,0.0167,0.0125,0.01,0.0083};
					distanceZoomMin = 100;
					distanceZoomMax = 1000;
					memoryPointCamera = "opticView";
					visionMode[] = {};
					opticsFlare = 1;
					opticsDisablePeripherialVision = 1;
					cameraDir = "";
				};
			};
		};
	};

	class tae_IQA12 : IDA_IQA11 {
		dlc = "The Ashen Enclave AUX Mod";
		author = "Edonn";
		scope = 2;
		scopeArsenal = 2;
		displayName = "IQA-12 Targeting Blaster";
		baseWeapon = "tae_IQA12";

		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 120;

			class CowsSlot : CowsSlot {
				compatibleItems[] = { "IDA_TargetingScope", "tae_TargetingScope_FP2" };
				iconPicture = "";
			};

			class MuzzleSlot;
			class PointerSlot;
			class UnderBarrelSlot;
		};

		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "tae_TargetingScope_FP2";
			};
		};
	};

	class tae_HPB14 : mti_armoury_weapon_hpb {
		author = "TAE Mod Team";
		dlc = "The Ashen Enclave AUX Mod";
		scope = 2;
		scopeArsenal = 2;
		displayName = "HPB-14 Heavy Blaster Rifle (Reduced Power)";
		baseWeapon = "tae_HPB14";
		magazines[] = {"tae_mag_HPB14"};
		magazineWell[] = {};

		class Standard : Standard {
			magazines[] = {"tae_mag_HPB14"};
			magazineWell[] = {};
		};

		class Heavy : Heavy {
			magazines[] = {"tae_mag_HPB14_scatter"};
			magazineWell[] = {};
		};
	};
};
