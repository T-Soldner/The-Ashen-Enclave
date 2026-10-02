#include "arsenal_macros.hpp"

class CfgPatches {
	class TAEGear_Backpacks {
		addonRootClass = "TAEGear";
		requiredVersion = 1.60;
		requiredAddons[] = { "jen_jetpacks_core", "knd_jetpacks", "knd_rotarycanon", "tgf_backpacks", "JLTS_optionals_TFARBeta_compat", "IDA_Ammo", "3AS_Weapons", "JLTS_weapons_DW32S" };
		units[] = { 
			"tae_jetpack_Z6",
			"tae_jetpack_z12",
			"tae_jetpack_JT12",
			"tae_jetpack_JT12_LR",
			"tae_jetpack_JT13",
			"tae_jetpack_JT13_LR",
			"tae_jetpack_MSEJT4",
			"tae_jetpack_MSEJT4_LR",
			"tae_jetpack_Z4",
			"tae_hondo_JT13",
			"tae_hondo_JT13_LR",
			"tae_stasik_JT12",
			"tae_jimothy_JT12",
			"tae_frenk_JT12",
			"tae_stasik_JT12_LR",
			"tae_edonn_JT13_LR",
			"tae_edonn_JT13",
			"tae_nova_Z6"
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
		class TAE_standard_Jetpacks {
			label = "Standard Jetpacks";
			author = "TAE Aux Mod Team";
			options[] = { "role", "lr" };

			class role {
				alwaysSelectable = 1;
				label = "Role";
				values[] = { "JT13", "JT12", "MSEJT4", "Z6", "Z12", "Z4" };

				class Z6 {
					label = "Z-6";
				};

				class Z12 {
					label = "Z-12";
				};

				class JT12 {
					label = "JT-12";
				};

				class JT13 {
					label = "JT-13";
				};

				class MSEJT4 {
					label = "MS-EJT4";
				};

				class Z4 {
					label = "Z-4";
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
		
		class TAE_standard_Backpacks {
			label = "Standard Backpacks";
			author = "TAE Aux Mod Team";
			options[] = { "role", "Sex" };

			class role {
				alwaysSelectable = 1;
				label = "Role";
				values[] = { "Standard", "Communications", "Engineer" };

				class Standard {
					label = "Standard";
				};

				class Communications {
					label = "Comms";
				};

				class Engineer {
					label = "Engineer";
				};
			};

			class Sex {
				alwaysSelectable = 1;
				label = "Sex";
				values[] = { "Male", "Female" };

				class Male {
					label = "Male";
				};

				class Female {
					label = "Female";
				};
			};
		};

		class TAE_custom_Backpacks {
			label = "Custom Backpacks";
			author = "TAE Aux Mod Team";
			options[] = { "owner", "LR" };

			class owner {
				alwaysSelectable = 1;
				label = "Owner";
				values[] = { "Hondo", "Stasik", "Edonn", "Nova", "Jimothy", "Frenk" };
				class Frenk { label = "Frenk"; };
				class Jimothy { label = "Jimothy"; };

				class Hondo {
					label = "Hondo";
				};

				class Stasik {
					label = "Stasik";
				};

				class Edonn {
					label = "Edonn";
				};

				class Nova {
					label = "Nova";
				};
			};

			class LR {
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

	};
};

class XtdGearInfos {
	class CfgVehicles {
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_frenk_JT12, "Frenk", "No")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_jimothy_JT12, "Jimothy", "No")
		//Jetpacks
		TAE_JETPACK_ARSENAL(tae_jetpack_Z6, "Z6", "No")
		TAE_JETPACK_ARSENAL(tae_jetpack_z12, "Z12", "No")
		TAE_JETPACK_ARSENAL(tae_jetpack_JT12, "JT12", "No")
		TAE_JETPACK_ARSENAL(tae_jetpack_JT12_LR, "JT12", "Yes")
		TAE_JETPACK_ARSENAL(tae_jetpack_JT13, "JT13", "No")
		TAE_JETPACK_ARSENAL(tae_jetpack_JT13_LR, "JT13", "Yes")
		TAE_JETPACK_ARSENAL(tae_jetpack_MSEJT4, "MSEJT4", "No")
		TAE_JETPACK_ARSENAL(tae_jetpack_MSEJT4_LR, "MSEJT4", "Yes")
		TAE_JETPACK_ARSENAL(tae_jetpack_Z4, "Z4", "No")
		
		//Backpacks
		TAE_BACKPACK_ARSENAL(tae_modular_pack, "Standard", "Male")
		TAE_BACKPACK_ARSENAL(tae_modular_pack_female, "Standard", "Female")
		TAE_BACKPACK_ARSENAL(tae_modular_pack_lr, "Communications", "Male")
		TAE_BACKPACK_ARSENAL(tae_modular_pack_lr_female, "Communications", "Female")
		TAE_BACKPACK_ARSENAL(tae_modular_pack_engi, "Engineer", "Male")
		TAE_BACKPACK_ARSENAL(tae_modular_pack_engi_female, "Engineer", "Female")

		//Custom Backpacks
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_hondo_JT13, "Hondo", "No")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_hondo_JT13_LR, "Hondo", "Yes")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_stasik_JT12, "Stasik", "No")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_stasik_JT12_LR, "Stasik", "Yes")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_edonn_JT13_LR, "Edonn", "Yes")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_edonn_JT13, "Edonn", "No")
		TAE_CUSTOM_BACKPACK_ARSENAL(tae_nova_Z6, "Nova", "No")

	};
};

class CfgVehicles {
	class Bag_Base;
	class KND_RotaryBackpack;
	class tae_jetpack : Bag_Base {
		scope = 1;
		displayName = "TAE base";
		picture = "\knd_jetpacks\data\JT12_icon_co.paa";
		maximumload = 240;
		mass = 60;
		jen_jetpacks_core_isJetpack = 1;
	};
	
	// Base Jetpacks
	class tae_jetpack_JT13 : tae_jetpack {
		displayName = "House Karr JT-13 Jetpack";
		scope = 2;
		picture = "\knd_jetpacks\data\JT13_icon_co.paa";
		author = "Kandosii Mod Devs and Edonn";
		model = "\knd_jetpacks\data\jt13\jt13.p3d";
		hiddenselections[] = {"camo1"};
		hiddenselectionstextures[] = {"knd_jetpacks\data\jt13\camo1_co.paa"};
		maximumload = 160;
		jen_jetpacks_core_acceleration = 4;
		jen_jetpacks_core_drag = 4.8;
		jen_jetpacks_core_fuelCoef = 5;
		jen_jetpacks_core_heatCoef = 3;
		jen_jetpacks_core_coolCoef = 1.5;
		jen_jetpacks_core_ascensionCoef = 1.3;
		jen_jetpacks_core_jumpCoef = 1.2;
		jen_jetpacks_core_fuelCapacity = 104;
		jen_jetpacks_core_strafeCoef = 1;
	};
	class tae_jetpack_JT13_LR : tae_jetpack_JT13 {
		displayName = "House Karr JT-13 LR Jetpack";
		author = "Kandosii Mod Devs and Edonn";
		model = "\knd_jetpacks\data\jt13RTO\jt13RTO.p3d";
		hiddenselections[] = {"camo1"};
		hiddenselectionstextures[] = {"knd_jetpacks\data\jt13RTO\camo1_co.paa"};
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 30000;
		tf_subtype = "digital_lr";
	};
	class tae_jetpack_JT12 : tae_jetpack {
		displayName = "House Karr JT-12 Jetpack";
		scope = 2;
		picture = "\knd_jetpacks\data\JT12_icon_co.paa";
		author = "Kandosii Mod Devs and Edonn";
		model = "\knd_jetpacks\data\jt12\jt12.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"\knd_jetpacks\data\jt12\rocket_co.paa","\knd_jetpacks\data\jt12\pack_co.paa"};
		maximumload = 240;
		jen_jetpacks_core_acceleration = 2.5;
		jen_jetpacks_core_drag = 5;
		jen_jetpacks_core_fuelCoef = 3;
		jen_jetpacks_core_heatCoef = 2;
		jen_jetpacks_core_coolCoef = 1;
		jen_jetpacks_core_ascensionCoef = 1.1;
		jen_jetpacks_core_jumpCoef = 1;
		jen_jetpacks_core_fuelCapacity = 120;
		jen_jetpacks_core_strafeCoef = 0.7;
	};
	class tae_jetpack_JT12_LR : tae_jetpack_JT12 {
		displayName = "House Karr JT-12 LR Jetpack";
		author = "Kandosii Mod Devs and Edonn";
		model = "\knd_jetpacks\data\jt12RTO\jt12RTO.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"\knd_jetpacks\data\jt12\rocket_co.paa","\knd_jetpacks\data\jt12RTO\pack_co.paa"};
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 30000;
		tf_subtype = "digital_lr";
	};
	class tae_jetpack_MSEJT4 : KND_RotaryBackpack {
		displayName = "House Karr MS-EJT4 Jetpack";
		scope = 2;
		picture = "\knd_rotary\data\backpack_picture_co.paa";
		author = "Kandosii Mod Devs and Edonn";
		model = "\knd_rotary\backpack\knd_rotarybackpack.p3d";
		hiddenselections[] = {"camo1","camo2"};
		hiddenselectionstextures[] = {
			"\knd_rotary\backpack\rotarybackpack_co.paa",
			"\knd_rotary\backpack\rotarybackpack_co.paa"
		};
		maximumload = 320;
		mass = 60;
		jen_jetpacks_core_acceleration = 1.9;
		jen_jetpacks_core_drag = 5.5;
		jen_jetpacks_core_fuelCoef = 1.25;
		jen_jetpacks_core_heatCoef = 0.75;
		jen_jetpacks_core_coolCoef = 1.5;
		jen_jetpacks_core_ascensionCoef = 0.9;
		jen_jetpacks_core_jumpCoef = 1;
		jen_jetpacks_core_fuelCapacity = 220;
		jen_jetpacks_core_strafeCoef = 0.45;
	};
	class tae_jetpack_MSEJT4_LR : tae_jetpack_MSEJT4 {
		displayName = "House Karr MS-EJT4 LR Jetpack";
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 30000;
		tf_subtype = "digital_lr";
	};
	class tae_jetpack_Z6 : tae_jetpack {
		displayName = "House Karr Z-6 Jetpack";
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		model = "knd_jetpacks\data\z6\z6_final.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"knd_jetpacks\data\Z6\Rocket_co.paa","knd_jetpacks\data\Z6\pack_co.paa"};
		maximumload = 176;
		jen_jetpacks_core_acceleration = 3.4;
		jen_jetpacks_core_drag = 6.25;
		jen_jetpacks_core_fuelCoef = 5.5;
		jen_jetpacks_core_heatCoef = 3.2;
		jen_jetpacks_core_coolCoef = 1.3;
		jen_jetpacks_core_ascensionCoef = 1.15;
		jen_jetpacks_core_jumpCoef = 1.1;
		jen_jetpacks_core_fuelCapacity = 96;
		jen_jetpacks_core_strafeCoef = 0.8;
		knd_isRocketJetpack = 1;
	};
	class tae_jetpack_z12 : tae_jetpack {
		displayName = "House Karr Z-12 Jetpack";
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		model = "knd_jetpacks\data\z12\pack.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"knd_jetpacks\data\Z12\Rocket_co.paa","knd_jetpacks\data\Z12\pack_co.paa"};
		maximumload = 224;
		jen_jetpacks_core_acceleration = 2.2;
		jen_jetpacks_core_drag = 5.5;
		jen_jetpacks_core_fuelCoef = 3.5;
		jen_jetpacks_core_heatCoef = 2.2;
		jen_jetpacks_core_coolCoef = 1;
		jen_jetpacks_core_ascensionCoef = 1;
		jen_jetpacks_core_jumpCoef = 0.9;
		jen_jetpacks_core_fuelCapacity = 111;
		jen_jetpacks_core_strafeCoef = 0.55;
		knd_isRocketJetpack = 1;
	};
	class tae_jetpack_Z4 : tae_jetpack {
		displayName = "House Karr Z-4 Jetpack";
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		model = "\knd_jetpacks\data\PV\pissviszla.p3d";
		hiddenselections[] = {"rocket","pack"};
		hiddenselectionstextures[] = {"\knd_jetpacks\data\PV\rocket_co.paa","\knd_jetpacks\data\PV\pack_co.paa"};
		maximumload = 256;
		jen_jetpacks_core_acceleration = 1.6;
		jen_jetpacks_core_drag = 6;
		jen_jetpacks_core_fuelCoef = 1.5;
		jen_jetpacks_core_heatCoef = 1;
		jen_jetpacks_core_coolCoef = 1.3;
		jen_jetpacks_core_ascensionCoef = 0.8;
		jen_jetpacks_core_jumpCoef = 0.9;
		jen_jetpacks_core_fuelCapacity = 200;
		jen_jetpacks_core_strafeCoef = 0.3;
		knd_isRocketJetpack = 1;
	};
	
	//Normal Backpacks
	class tgf_backpacks_modular_pack;
	class tgf_backpacks_modular_pack_female;
	class tgf_backpacks_modular_pack_lr;
	class tgf_backpacks_modular_pack_lr_female;
	class tgf_backpacks_modular_pack_engi;
	class tgf_backpacks_modular_pack_engi_female;
	
	
	class tae_modular_pack : tgf_backpacks_modular_pack {
		scope = 2;
		maximumload = 400;
		mass = 60;
	};
	class tae_modular_pack_grenadier : tae_modular_pack {
		scope = 1;
		scopeArsenal = 0;

		class TransportMagazines {
			class _xx_IDA_HE_LauncherGrenade {
				magazine = "IDA_HE_LauncherGrenade";
				count = 5;
			};
		};
	};
	class tae_modular_pack_heavy : tae_modular_pack {
		scope = 1;
		scopeArsenal = 0;
		class TransportMagazines {};
	};
	class tae_modular_pack_marksman : tae_modular_pack {
		scope = 1;
		scopeArsenal = 0;

		class TransportMagazines {
			class _xx_JLTS_DW32S_mag {
				magazine = "JLTS_DW32S_mag";
				count = 10;
			};
		};
	};
	class tae_modular_pack_medic : tae_modular_pack {
		scope = 1;
		scopeArsenal = 0;
		maximumload = 600;

		class TransportMagazines {
			class _xx_LFP_westarcarabine_Mag {
				magazine = "LFP_westarcarabine_Mag";
				count = 20;
			};
		};
	};
	class tae_modular_pack_female : tgf_backpacks_modular_pack_female {
		scope = 2;
		maximumload = 400;
		mass = 60;
	};
	class tae_modular_pack_lr : tgf_backpacks_modular_pack_lr {
		scope = 2;
		maximumload = 400;
		mass = 60;
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 30000;
		tf_subtype = "digital_lr";
	};
	class tae_modular_pack_lr_female : tgf_backpacks_modular_pack_lr_female {
		scope = 2;
		maximumload = 400;
		mass = 60;
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_independent_radio_code";
		tf_hasLRradio = 1;
		tf_range = 30000;
		tf_subtype = "digital_lr";
	};
	class tae_modular_pack_engi : tgf_backpacks_modular_pack_engi {
		scope = 2;
		maximumload = 400;
		mass = 60;
	};
	class tae_modular_pack_engi_female : tgf_backpacks_modular_pack_engi_female {
		scope = 2;
		maximumload = 400;
		mass = 60;
	};
	
	// Custom Packs
	class tae_hondo_JT13 : tae_jetpack_JT13 {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Hondo's JT-13 Jetpack";
		descriptionShort = "Hondo's JT-13 Jetpack";
		hiddenselectionstextures[] = {"TAEGear\data\Hondo\JT13_Pack_Hondo_co.paa"};
	};
	class tae_hondo_JT13_LR : tae_jetpack_JT13_LR {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Hondo's JT-13 Jetpack LR";
		descriptionShort = "Hondo's JT-13 Jetpack LR";
		hiddenselectionstextures[] = {"TAEGear\data\Hondo\JT13_RTO_Pack_Hondo_co.paa"};
	};
	class tae_frenk_JT12 : tae_jetpack_JT12 {
		scope = 2;
		author = "House Kandosii and Jimothy";
		displayName = "Frenk's JT-12 Jetpack";
		descriptionShort = "Frenk's JT-12 Jetpack";
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Frenk\JT12_Rocket_Frenk.paa",
			"TAEGear\data\Frenk\JT12_Pack_Frenk.paa"
		};
	};
	class tae_jimothy_JT12 : tae_jetpack_JT12 {
		scope = 2;
		author = "House Kandosii and Jimothy";
		displayName = "Jimothy's JT-12 Jetpack";
		descriptionShort = "Jimothy's JT-12 Jetpack";
		hiddenSelectionsTextures[] = {
			"TAEGear\data\Jimothy\JT12_Rocket_Jimothy.paa",
			"TAEGear\data\Jimothy\JT12_Pack_Jimothy.paa"
		};
	};
	class tae_stasik_JT12 : tae_jetpack_JT12 {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Stasik's JT-12 Jetpack";
		descriptionShort = "Stasik's JT-12 Jetpack";
		hiddenselectionstextures[] = {
			"\knd_jetpacks\data\jt12\rocket_co.paa",
			"TAEGear\data\Stasik\JT12_Pack_Stasik_co.paa"
		};
	};
	class tae_stasik_JT12_LR : tae_jetpack_JT12_LR {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Stasik's JT-12 Jetpack LR";
		descriptionShort = "Stasik's JT-12 Jetpack LR";
		hiddenselectionstextures[] = {
			"\knd_jetpacks\data\jt12\rocket_co.paa",
			"TAEGear\data\Stasik\JT12_RTO_Pack_Stasik_co.paa"
		};
	};
	class tae_edonn_JT13_LR : tae_jetpack_JT13_LR {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Edonn's JT-13 Jetpack LR";
		descriptionShort = "Edonn's JT-13 Jetpack LR";
		hiddenselectionstextures[] = {"TAEGear\data\Edonn\JT13_RTO_Pack_Edonn_co.paa"};
	};
	class tae_edonn_JT13 : tae_jetpack_JT13 {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Edonn's JT-13 Jetpack";
		descriptionShort = "Edonn's JT-13 Jetpack";
		hiddenselectionstextures[] = {"TAEGear\data\Edonn\JT13_Pack_Edonn_co.paa"};
	};
	class tae_nova_Z6 : tae_jetpack_Z6 {
		scope = 2;
		author = "Kandosii Mod Devs and Edonn";
		displayName = "Nova's Z-6 Jetpack";
		descriptionShort = "Nova's Z-6 Jetpack";
		hiddenselectionstextures[] = {
			"TAEGear\data\Nova\Z6_Rocket_Nova_co.paa",
			"TAEGear\data\Nova\Z6_Pack_Nova_co.paa"
		};
	};
};
