class CfgPatches {
	class TAEGear_Backpacks {
		addonRootClass = "TAEGear";
		requiredVersion = 1.60;
		requiredAddons[] = { "knd_jetpacks" };
		units[] = { 
			"tae_jetpack_Z6",
			"tae_jetpack_Z6_LR",
			"tae_jetpack_z12",
			"tae_jetpack_z12_LR",
			"tae_jetpack_JT12",
			"tae_jetpack_JT12_LR",
			"tae_hondo_JT12_LR",
			"tae_edonn_JT12_LR"
		};
		weapons[] = { };
	};
};

/*Config parameters of note:
jen_jetpacks_core_isJetpack
Determines whether the backpack is a jetpack or not

jen_jetpacks_core_acceleration
Determines how much acceleration the jetpack can output front, sideways, and backwards.

jen_jetpacks_core_drag
Coefficient for air resistance (drag). 

jen_jetpacks_core_fuelCoef
How quickly the jetpack drains fuel.

jen_jetpacks_core_fuelCapacity
The maximum fuel capacity of the jetpack.

jen_jetpacks_core_heatCoef
How quickly the jetpack heats up.

jen_jetpacks_core_coolCoef
How quickly the jetpack cools down when turned off.

jen_jetpacks_core_ascensionCoef
Coefficient for going up with spacebar (by default). 

jen_jetpacks_core_jumpCoef
How powerful the initial "hop" on activation is.

jen_jetpacks_core_strafeCoef
Coefficient for left-right controls. 0 = no strafing, 0.5 = strafe half as fast as you go forward, 1 = strafe just as fast as you go forward

jen_jetpacks_core_particlePoints[]
An array that contains the names of named points in the backpack model's memory LOD where flames come out.
Not useful without doing our own P3Ds

jen_jetpacks_core_isFuelCan
Determines whether a misc item is a fuel container or not

jen_jetpacks_core_fuelCanSize
Determines the size of the fuel can in Magical Fuel Units (corresponds to jetpack fuel capacity numbers)*/

class XtdGearModels {
	class CfgVehicles {
		class TAE_standard_Backpacks {
			label = "Standard Backpacks";
			author = "TAE Aux Mod Team";
			options[] = { "role", "lr" };

			class role {
				alwaysSelectable = 1;
				label = "Role";
				values[] = { "Z6", "Z12", "JT12" };

				class Z6 {
					label = "Z-6";
				};

				class Z12 {
					label = "Z-12";
				};

				class JT12 {
					label = "JT-12";
				};
			};

			class lr {
				alwaysSelectable = 1;
				label = "LR";
				values[] = { "Yes", "No" };

				class Yes {
					label = "Yes";
				};

				class No {
					label = "No";
				};
			};
		};

		class TAE_custom_Backpacks {
			label = "Custom Backpacks";
			author = "TAE Aux Mod Team";
			options[] = { "owner" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Hondo", "Edonn" };

				class Hondo {
					label = "Hondo";
				};

				class Edonn {
					label = "Edonn";
				};
			};
		};
	};
};

class XtdGearInfos {
	class CfgVehicles {
		class tae_jetpack_Z6 {
			model = "TAE_standard_Backpacks";
			role = "Z6";
			lr = "No";
		};

		class tae_jetpack_Z6_LR {
			model = "TAE_standard_Backpacks";
			role = "Z6";
			lr = "Yes";
		};

		class tae_jetpack_z12 {
			model = "TAE_standard_Backpacks";
			role = "Z12";
			lr = "No";
		};

		class tae_jetpack_z12_LR {
			model = "TAE_standard_Backpacks";
			role = "Z12";
			lr = "Yes";
		};

		class tae_jetpack_JT12 {
			model = "TAE_standard_Backpacks";
			role = "JT12";
			lr = "No";
		};

		class tae_jetpack_JT12_LR {
			model = "TAE_standard_Backpacks";
			role = "JT12";
			lr = "Yes";
		};

		class tae_hondo_Z12_LR {
			model = "TAE_custom_Backpacks";
			owner = "Hondo";
		};

		class tae_edonn_JT12_LR {
			model = "TAE_custom_Backpacks";
			owner = "Edonn";
		};
	};
};


class CfgVehicles {
	//Jennas jumppacks test
	class Bag_Base;
	class tae_jetpack : Bag_Base {
		scope = 1;
		displayName = "TAE base";
		picture = "\knd_jetpacks\data\JT12_icon_co.paa";
		maximumload = 300;
		mass = 50;
		jen_jetpacks_core_isJetpack = 1;
		jen_jetpacks_core_acceleration = 2.5;
		jen_jetpacks_core_drag = 5;
		jen_jetpacks_core_fuelCoef = 3;
		jen_jetpacks_core_heatCoef = 1;
		jen_jetpacks_core_coolCoef = 1;
		jen_jetpacks_core_ascensionCoef = 1.1;
		jen_jetpacks_core_jumpCoef = 1;
		jen_jetpacks_core_fuelCapacity = 150;
		jen_jetpacks_core_strafeCoef = 0.7;
	};
	
	// Base Jetpacks
	class tae_jetpack_z12 : tae_jetpack {
		displayName = "House Karr Z-12 Jetpack";
		scope = 2;
		model = "knd_jetpacks\data\z12\pack.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"knd_jetpacks\data\Z12\Rocket_co.paa","knd_jetpacks\data\Z12\pack_co.paa"};
		knd_isRocketJetpack = 1;
	};
	class tae_jetpack_z12_LR : tae_jetpack_z12 {
		displayName = "House Karr Z-12 LR Jetpack";
		model = "knd_jetpacks\data\z12rto\pack.p3d";
		hiddenselectionstextures[] = {"knd_jetpacks\data\Z12\Rocket_co.paa","knd_jetpacks\data\Z12RTO\pack_co.paa"};
		tf_dialog = "bussole_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 10000;
		tf_isolatedAmount = 0.65;
		tf_subtype = "digital_lr";
	};	
	class tae_jetpack_JT12 : tae_jetpack {
		displayName = "House Karr JT-12 Jetpack";
		scope = 2;
		picture = "\knd_jetpacks\data\JT12_icon_co.paa";
		author = "Maxim + Jenna";
		model = "\knd_jetpacks\data\jt12\jt12.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"\knd_jetpacks\data\jt12\rocket_co.paa","\knd_jetpacks\data\jt12\pack_co.paa"};
	};
	class tae_jetpack_JT12_LR : tae_jetpack_JT12 {
		displayName = "House Karr JT-12 LR Jetpack";
		model = "\knd_jetpacks\data\jt12RTO\jt12RTO.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"\knd_jetpacks\data\jt12\rocket_co.paa","\knd_jetpacks\data\jt12RTO\pack_co.paa"};
		tf_dialog = "bussole_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 10000;
		tf_subtype = "digital_lr";
	};
	class tae_jetpack_Z6 : tae_jetpack {
		displayName = "House Karr Z-6 Jetpack";
		scope = 2;
		model = "knd_jetpacks\data\z6\z6_final.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"knd_jetpacks\data\Z6\Rocket_co.paa","knd_jetpacks\data\Z6\pack_co.paa"};
		knd_isRocketJetpack = 1;
	};
	class tae_jetpack_Z6_LR : tae_jetpack_Z6 {
		displayName = "House Karr Z-6 LR Jetpack";
		model = "knd_jetpacks\data\z6RTO\z6RTO.p3d";
		hiddenselectionstextures[] = {"knd_jetpacks\data\Z6\Rocket_co.paa","knd_jetpacks\data\Z6RTO\pack_co.paa"};
		tf_dialog = "bussole_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 10000;
		tf_subtype = "digital_lr";
	};
	
	class tae_hondo_Z12_LR : tae_jetpack_z12_LR {
		scope = 2;
		displayName = "Hondo's Z-12 Jetpack";
		descriptionShort = "Hondo's JT-12 Jetpack";
		//hiddenselectionstextures[] = {"\knd_jetpacks\data\jt12\rocket_co.paa","\knd_jetpacks\data\jt12RTO\pack_co.paa"};
		//hiddenSelectionsTextures[] = {"TAEGear\data\JT12_Hondo.paa"}; OLD
	};
	class tae_edonn_JT12_LR : tae_jetpack_JT12_LR {
		scope = 2;
		displayName = "Edonn's JT-12 Jetpack";
		descriptionShort = "Edonn's JT-12 Jetpack";
		//hiddenselectionstextures[] = {"\knd_jetpacks\data\jt12\rocket_co.paa","\knd_jetpacks\data\jt12RTO\pack_co.paa"};
		//hiddenSelectionsTextures[] = {"TAEGear\data\JT12_Edonn"}; OLD
	};
};