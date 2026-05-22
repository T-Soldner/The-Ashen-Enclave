class CfgPatches {
	class TAEGear_Uniforms {
		addonRootClass = "TAEGear";
		requiredVersion = 1.60;
		requiredAddons[] = { "TAEGear" };
		units[] = {
			"TAE_Beroya_Edonn_F"
		};
		weapons[] = {
			"TAE_Beroya_Edonn"
		};
	};
};
class CfgVehicles {
	class knd_beroya_F;
	class TAE_Beroya_Edonn_F: knd_beroya_F {
		scope = 1;
		scopeCurator = 0;
		author = "Soldner";
		displayName = "Edonn's Beroya Armor";
		hiddenSelectionsTextures[] = {"TAEGear\data\BER_Armor_Edonn_1.paa","TAEGear\data\BER_Armor_Edonn_2.paa","knd_newArmor\tex\beroya\camo3_co.paa"};
		uniformClass = "TAE_Beroya_Edonn";
	};
};
class CfgWeapons {
	class ItemInfo;
	class knd_beroya;
	class TAE_Beroya_Edonn : knd_beroya {
		scope = 2;
		scopeArsenal = 2;
		author = "Soldner";
		displayName = "Edonn's Beroya Armor";
		hiddenSelectionsTextures[] = {"TAEGear\data\BER_Armor_Edonn_1.paa","TAEGear\data\BER_Armor_Edonn_2.paa","knd_newArmor\tex\beroya\camo3_co.paa"};
		class ItemInfo: ItemInfo
		{
			uniformClass = "TAE_Beroya_Edonn_F";
		};
	};
};
