class CfgPatches {
	class TAEWeapons {
		name = "The Ashen Enclave AUX Mod";
		author = "TAE Mod Team";
		url = "https://discord.gg/9zgGp5QSW7";
		requiredVersion = 1.60;
		requiredAddons[] = { "IDA_INDEP" };
		units[] = {};
		weapons[] = {
			"tae_TargetingScope_FP2",
			"tae_IQA12"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgWeapons {
	class InventoryOpticsItem_Base_F;
	class WeaponSlotsInfo;
	class CowsSlot;
	class ItemInfo;

	class IDA_TargetingScope;
	class IDA_IQA11;

	class tae_TargetingScope_FP2 : IDA_TargetingScope {
		scope = 2;
		scopeArsenal = 2;
		dlc = "The Ashen Enclave AUX Mod";
		author = "Soldner";
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
		author = "Soldner";
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
};