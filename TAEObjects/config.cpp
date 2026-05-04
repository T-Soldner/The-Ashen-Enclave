class CfgPatches {
	class TAEObjects {
		name = "TAE Objects";
		author = "TAE Mod Team";
		requiredAddons[] = {
			"A3_Weapons_F",
			"ace_arsenal",
			"ace_dragging",
			"ace_cargo",
			"cba_xeh",
			"knd_crates"
		};
		units[] = {
			"TAE_Restricted_Arsenal_Box",
			"TAE_Ammo_Crate",
			"TAE_Demo_Crate",
			"TAE_Medical_Crate"
		};
		weapons[] = {};
	};
};

class CfgFunctions {
	class TAE {
		class Objects {
			file = "TAEObjects\functions";
			class initRestrictedArsenal {};
		};
	};
};

class Extended_Init_EventHandlers {
	class TAE_Restricted_Arsenal_Box {
		class TAEObjects_initRestrictedArsenal {
			init = "_this call TAE_fnc_initRestrictedArsenal";
		};
	};
};

class CfgVehicles {
	class ReammoBox_F;

	class TAE_Restricted_Arsenal_Box: ReammoBox_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Restricted ACE Arsenal";
		author = "TAE Mod Team";
		editorCategory = "EdCat_Supplies";
		editorSubcategory = "EdSubcat_Ammo";
		side = 3;
		armor = 4000;

		model = "knd_crates\arsenalModel\THEBOX.p3d";
		editorPreview = "knd_crates\tex\crates\thumbnail.paa";

		hiddenSelections[] = {
			"camo1"
		};

		hiddenSelectionsTextures[] = {
			"knd_crates\tex\crates\arsenal\camo1_co.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_cargo_canLoad = 0;
		ace_cargo_size = -1;

		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		class TransportBackpacks {};
	};

	class TAE_Ammo_Crate: ReammoBox_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Ammo Crate";
		author = "TAE Mod Team";
		editorCategory = "EdCat_Supplies";
		editorSubcategory = "EdSubcat_Ammo";
		side = 3;
		armor = 4000;

		model = "knd_crates\cratemodel\NewCrate.p3d";
		editorPreview = "knd_crates\tex\crates\thumbnail.paa";

		hiddenSelections[] = {
			"camo1"
		};

		hiddenSelectionsTextures[] = {
			"knd_crates\tex\crates\ammo\camo1_co.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 4000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 2000;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};

		class TransportMagazines {
			class _xx_IDA_Blaster_Cell_Power4_10Rnd_Blue {
				magazine = "IDA_Blaster_Cell_Power4_10Rnd_Blue";
				count = 30;
			};
			class _xx_IDA_Blaster_Cell_Power3_40Rnd_Red {
				magazine = "IDA_Blaster_Cell_Power3_40Rnd_Red";
				count = 40;
			};
			class _xx_IDA_Blaster_Cell_Power3_40Rnd_Yellow {
				magazine = "IDA_Blaster_Cell_Power3_40Rnd_Yellow";
				count = 40;
			};
			class _xx_IDA_Blaster_Cell_Power3_60Rnd_Red {
				magazine = "IDA_Blaster_Cell_Power3_60Rnd_Red";
				count = 30;
			};
			class _xx_IDA_Blaster_Cell_Power2_20Rnd_yellow {
				magazine = "IDA_Blaster_Cell_Power2_20Rnd_yellow";
				count = 30;
			};
			class _xx_IDA_Blaster_Cell_Power2_100Rnd_Green {
				magazine = "IDA_Blaster_Cell_Power2_100Rnd_Green";
				count = 20;
			};
			class _xx_IDA_Blaster_Cell_Power5_5Rnd_Yellow {
				magazine = "IDA_Blaster_Cell_Power5_5Rnd_Yellow";
				count = 30;
			};
			class _xx_IDA_Blaster_Cell_Power5_5Rnd_Green {
				magazine = "IDA_Blaster_Cell_Power5_5Rnd_Green";
				count = 30;
			};

			class _xx_3AS_14rnd_EM10_Mag {
				magazine = "3AS_14rnd_EM10_Mag";
				count = 30;
			};
			class _xx_3AS_15Rnd_EC20_SE14R_Mag {
				magazine = "3AS_15Rnd_EC20_SE14R_Mag";
				count = 30;
			};
			class _xx_3AS_15Rnd_EM20_SE14R_Mag {
				magazine = "3AS_15Rnd_EM20_SE14R_Mag";
				count = 30;
			};
			class _xx_3AS_16Rnd_EC20_Mag {
				magazine = "3AS_16Rnd_EC20_Mag";
				count = 30;
			};
			class _xx_3AS_16Rnd_EM20_Mag {
				magazine = "3AS_16Rnd_EM20_Mag";
				count = 30;
			};
			class _xx_3AS_16Rnd_EY20_Mag {
				magazine = "3AS_16Rnd_EY20_Mag";
				count = 30;
			};
			class _xx_3AS_18Rnd_EM20_EC17_Mag {
				magazine = "3AS_18Rnd_EM20_EC17_Mag";
				count = 30;
			};
			class _xx_3AS_18Rnd_EM20_RK3_Mag {
				magazine = "3AS_18Rnd_EM20_RK3_Mag";
				count = 30;
			};
			class _xx_3AS_18Rnd_EC20_RK3_Mag {
				magazine = "3AS_18Rnd_EC20_RK3_Mag";
				count = 30;
			};
			class _xx_3AS_18Rnd_EM20_Mag {
				magazine = "3AS_18Rnd_EM20_Mag";
				count = 30;
			};
			class _xx_3AS_20Rnd_EG20_mag {
				magazine = "3AS_20Rnd_EG20_mag";
				count = 30;
			};
			class _xx_3AS_40Rnd_EM40_E11_Mag {
				magazine = "3AS_40Rnd_EM40_E11_Mag";
				count = 40;
			};
			class _xx_3AS_40Rnd_EC40_E11_Mag {
				magazine = "3AS_40Rnd_EC40_E11_Mag";
				count = 40;
			};
			class _xx_3AS_50Rnd_EM50_Mag {
				magazine = "3AS_50Rnd_EM50_Mag";
				count = 25;
			};
			class _xx_3AS_60Rnd_EM50_RedPlasma {
				magazine = "3AS_60Rnd_EM50_RedPlasma";
				count = 25;
			};
			class _xx_3AS_200Rnd_EM40_DLT19_Mag {
				magazine = "3AS_200Rnd_EM40_DLT19_Mag";
				count = 15;
			};
			class _xx_3AS_200Rnd_EC40_DLT19_Mag {
				magazine = "3AS_200Rnd_EC40_DLT19_Mag";
				count = 15;
			};
			class _xx_3AS_10Rnd_EM100_DLT19X_Mag {
				magazine = "3AS_10Rnd_EM100_DLT19X_Mag";
				count = 20;
			};
			class _xx_3AS_10Rnd_EC100_DLT19X_Mag {
				magazine = "3AS_10Rnd_EC100_DLT19X_Mag";
				count = 20;
			};
			class _xx_3AS_8Rnd_EY30_Pellets {
				magazine = "3AS_8Rnd_EY30_Pellets";
				count = 20;
			};
			class _xx_3AS_8Rnd_ESlugY_Mag {
				magazine = "3AS_8Rnd_ESlugY_Mag";
				count = 20;
			};
			class _xx_3AS_10Rnd_EC30_Pellets {
				magazine = "3AS_10Rnd_EC30_Pellets";
				count = 20;
			};
			class _xx_3AS_10Rnd_ESlug_Mag {
				magazine = "3AS_10Rnd_ESlug_Mag";
				count = 20;
			};
			class _xx_3AS_1Rnd_ESlug_Doomsday_Mag {
				magazine = "3AS_1Rnd_ESlug_Doomsday_Mag";
				count = 10;
			};
			class _xx_3AS_1Rnd_EC80_Flechette {
				magazine = "3AS_1Rnd_EC80_Flechette";
				count = 10;
			};
			class _xx_3AS_5Rnd_Stun_Mag {
				magazine = "3AS_5Rnd_Stun_Mag";
				count = 20;
			};

			class _xx_JMSLLTE_A180_25rnd_Mag {
				magazine = "JMSLLTE_A180_25rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_A180_30rnd_Mag {
				magazine = "JMSLLTE_A180_30rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_A280CR_20rnd_Mag {
				magazine = "JMSLLTE_A280CR_20rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_A300_15rnd_Mag {
				magazine = "JMSLLTE_A300_15rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_A300C_30rnd_Mag {
				magazine = "JMSLLTE_A300C_30rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_A310_15rnd_Mag {
				magazine = "JMSLLTE_A310_15rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_A475_25rnd_Mag {
				magazine = "JMSLLTE_A475_25rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_DH17_30Rnd_Mag {
				magazine = "JMSLLTE_DH17_30Rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_DH17_60Rnd_Mag {
				magazine = "JMSLLTE_DH17_60Rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_DL18_20rnd_Mag {
				magazine = "JMSLLTE_DL18_20rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_DL44_10rnd_Mag {
				magazine = "JMSLLTE_DL44_10rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_DT12_50rnd_Mag {
				magazine = "JMSLLTE_DT12_50rnd_Mag";
				count = 25;
			};
			class _xx_JMSLLTE_E22_60Rnd_Mag {
				magazine = "JMSLLTE_E22_60Rnd_Mag";
				count = 25;
			};
			class _xx_JMSLLTE_EE3_30rnd_Mag {
				magazine = "JMSLLTE_EE3_30rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_F78_50Rnd_Mag {
				magazine = "JMSLLTE_F78_50Rnd_Mag";
				count = 25;
			};
			class _xx_JMSLLTE_FWMB_40rnd_Mag {
				magazine = "JMSLLTE_FWMB_40rnd_Mag";
				count = 25;
			};
			class _xx_JMSLLTE_K16_15rnd_Mag {
				magazine = "JMSLLTE_K16_15rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_K23_20rnd_Mag {
				magazine = "JMSLLTE_K23_20rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_RK3_20rnd_Mag {
				magazine = "JMSLLTE_RK3_20rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_RT97C_150Rnd_Mag {
				magazine = "JMSLLTE_RT97C_150Rnd_Mag";
				count = 15;
			};
			class _xx_JMSLLTE_SE14_30rnd_Mag {
				magazine = "JMSLLTE_SE14_30rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_T21_25rnd_Mag {
				magazine = "JMSLLTE_T21_25rnd_Mag";
				count = 30;
			};
			class _xx_JMSLLTE_T21B_7rnd_Mag {
				magazine = "JMSLLTE_T21B_7rnd_Mag";
				count = 30;
			};

			class _xx_JLTS_DW32S_mag {
				magazine = "JLTS_DW32S_mag";
				count = 30;
			};
			class _xx_JLTS_E5S_mag {
				magazine = "JLTS_E5S_mag";
				count = 30;
			};
			class _xx_JLTS_RG4D_mag {
				magazine = "JLTS_RG4D_mag";
				count = 30;
			};
			class _xx_JLTS_SBB3_mag {
				magazine = "JLTS_SBB3_mag";
				count = 30;
			};
			class _xx_JLTS_stun_mag_short {
				magazine = "JLTS_stun_mag_short";
				count = 20;
			};
			class _xx_JLTS_stun_mag_long {
				magazine = "JLTS_stun_mag_long";
				count = 20;
			};

			class _xx_ls_magazine_zh73 {
				magazine = "ls_magazine_zh73";
				count = 30;
			};
			class _xx_ls_magazine_westar35c {
				magazine = "ls_magazine_westar35c";
				count = 30;
			};
			class _xx_ls_magazine_westar35s {
				magazine = "ls_magazine_westar35s";
				count = 30;
			};
			class _xx_ls_magazine_westar35sa {
				magazine = "ls_magazine_westar35sa";
				count = 30;
			};
			class _xx_ls_magazine_westar35s_scatter {
				magazine = "ls_magazine_westar35s_scatter";
				count = 20;
			};

			class _xx_LFP_Westar35_Mag {
				magazine = "LFP_Westar35_Mag";
				count = 30;
			};
			class _xx_LFP_Westar35BO_Mag {
				magazine = "LFP_Westar35BO_Mag";
				count = 30;
			};
			class _xx_LFP_westarcarabine_Mag {
				magazine = "LFP_westarcarabine_Mag";
				count = 30;
			};
			class _xx_LFP_WestarCarabineV2_Mag {
				magazine = "LFP_WestarCarabineV2_Mag";
				count = 30;
			};
			class _xx_LFP_westarsniper_mag {
				magazine = "LFP_westarsniper_mag";
				count = 20;
			};
			class _xx_LFP_WestarM5_Mag_Sniper {
				magazine = "LFP_WestarM5_Mag_Sniper";
				count = 20;
			};
			class _xx_SFA_Westar19Rifle_mag {
				magazine = "SFA_Westar19Rifle_mag";
				count = 30;
			};

			class _xx_knd_mag_EE2 {
				magazine = "knd_mag_EE2";
				count = 30;
			};
			class _xx_knd_mag_galaar {
				magazine = "knd_mag_galaar";
				count = 30;
			};
			class _xx_knd_mag_3GL_green {
				magazine = "knd_mag_3GL_green";
				count = 20;
			};
			class _xx_knd_mag_UGL_bactadart {
				magazine = "knd_mag_UGL_bactadart";
				count = 20;
			};
			class _xx_knd_mag_UGL_stimdart {
				magazine = "knd_mag_UGL_stimdart";
				count = 20;
			};
		};

		class TransportItems {};
		class TransportBackpacks {};
	};

	class TAE_Demo_Crate: ReammoBox_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Grenades/Explosives Crate";
		author = "TAE Mod Team";
		editorCategory = "EdCat_Supplies";
		editorSubcategory = "EdSubcat_Ammo";
		side = 3;
		armor = 4000;

		model = "knd_crates\cratemodel\NewCrate.p3d";
		editorPreview = "knd_crates\tex\crates\thumbnail.paa";

		hiddenSelections[] = {
			"camo1"
		};

		hiddenSelectionsTextures[] = {
			"knd_crates\tex\crates\demo\camo1_co.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 2000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 1200;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};

		class TransportMagazines {
			class _xx_3AS_ThermalDetonator {
				magazine = "3AS_ThermalDetonator";
				count = 20;
			};
			class _xx_3AS_SonicDet {
				magazine = "3AS_SonicDet";
				count = 12;
			};
			class _xx_3AS_SmokeBlue {
				magazine = "3AS_SmokeBlue";
				count = 10;
			};
			class _xx_3AS_SmokeGreen {
				magazine = "3AS_SmokeGreen";
				count = 10;
			};
			class _xx_3AS_SmokeRed {
				magazine = "3AS_SmokeRed";
				count = 10;
			};
			class _xx_3AS_SmokeWhite {
				magazine = "3AS_SmokeWhite";
				count = 10;
			};
			class _xx_3AS_SmokeYellow {
				magazine = "3AS_SmokeYellow";
				count = 10;
			};
			class _xx_3AS_ThrowableCharge {
				magazine = "3AS_ThrowableCharge";
				count = 8;
			};
			class _xx_3AS_DetPack {
				magazine = "3AS_DetPack";
				count = 8;
			};
			class _xx_EC01_RemoteMagazine {
				magazine = "EC01_RemoteMagazine";
				count = 8;
			};
			class _xx_RTX_RemoteMagazine {
				magazine = "RTX_RemoteMagazine";
				count = 8;
			};
			class _xx_mti_armoury_mag_breaching_charge {
				magazine = "mti_armoury_mag_breaching_charge";
				count = 8;
			};
			class _xx_mti_armoury_mag_detpack {
				magazine = "mti_armoury_mag_detpack";
				count = 8;
			};
			class _xx_mti_armoury_mag_satchelCharge {
				magazine = "mti_armoury_mag_satchelCharge";
				count = 6;
			};
			class _xx_HX_AT_Mine_Mag {
				magazine = "HX_AT_Mine_Mag";
				count = 6;
			};
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 20;
			};
			class _xx_3Rnd_HE_Grenade_shell {
				magazine = "3Rnd_HE_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_Smoke_Grenade_shell {
				magazine = "1Rnd_Smoke_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_SmokeRed_Grenade_shell {
				magazine = "1Rnd_SmokeRed_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_SmokeGreen_Grenade_shell {
				magazine = "1Rnd_SmokeGreen_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_SmokeBlue_Grenade_shell {
				magazine = "1Rnd_SmokeBlue_Grenade_shell";
				count = 10;
			};
			class _xx_UGL_FlareWhite_F {
				magazine = "UGL_FlareWhite_F";
				count = 10;
			};
			class _xx_UGL_FlareRed_F {
				magazine = "UGL_FlareRed_F";
				count = 10;
			};
			class _xx_UGL_FlareGreen_F {
				magazine = "UGL_FlareGreen_F";
				count = 10;
			};
			class _xx_UGL_FlareYellow_F {
				magazine = "UGL_FlareYellow_F";
				count = 10;
			};
		};

		class TransportItems {
			class _xx_ACE_Clacker {
				name = "ACE_Clacker";
				count = 6;
			};
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 6;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 4;
			};
			class _xx_ACE_wirecutter {
				name = "ACE_wirecutter";
				count = 4;
			};
		};

		class TransportBackpacks {};
	};

	class TAE_Medical_Crate: ReammoBox_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Medical Crate";
		author = "TAE Mod Team";
		editorCategory = "EdCat_Supplies";
		editorSubcategory = "EdSubcat_Ammo";
		side = 3;
		armor = 4000;

		model = "knd_crates\cratemodel\NewCrate.p3d";
		editorPreview = "knd_crates\tex\crates\thumbnail.paa";

		hiddenSelections[] = {
			"camo1"
		};

		hiddenSelectionsTextures[] = {
			"knd_crates\tex\crates\medical\camo1_co.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 2000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 1200;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};
		class TransportMagazines {};

		class TransportItems {
			class _xx_ACE_tourniquet {
				name = "ACE_tourniquet";
				count = 40;
			};
			class _xx_ACE_splint {
				name = "ACE_splint";
				count = 30;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 30;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 30;
			};
			class _xx_ACE_adenosine {
				name = "ACE_adenosine";
				count = 20;
			};
			class _xx_ACE_painkillers {
				name = "ACE_painkillers";
				count = 30;
			};
			class _xx_ACE_salineIV {
				name = "ACE_salineIV";
				count = 20;
			};
			class _xx_ACE_salineIV_500 {
				name = "ACE_salineIV_500";
				count = 30;
			};
			class _xx_ACE_salineIV_250 {
				name = "ACE_salineIV_250";
				count = 30;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 4;
			};
			class _xx_MTI_BactaSpray {
				name = "MTI_BactaSpray";
				count = 200;
			};
			class _xx_MTI_BactaPatch {
				name = "MTI_BactaPatch";
				count = 200;
			};
		};

		class TransportBackpacks {};
	};
};