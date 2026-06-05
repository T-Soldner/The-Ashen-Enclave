class CfgPatches
{
	class JLTS_optionals_TFARBeta_compat
	{
		author="Poly; TAE Mod Team";
		name="The Ashen Enclave JLTS TFAR Beta Compat";
		url="https://steamcommunity.com/sharedfiles/filedetails/?id=2244165431";
		version=1;
		versionStr="1.0.0";
		versionAr[]={1,0,0};
		requiredAddons[]=
		{
			"JLTS_Radios",
			"tfar_core",
			"tfar_handhelds",
			"A3_Weapons_F"
		};
		units[]={};
		weapons[]=
		{
			"JLTS_clone_comlink",
			"JLTS_droid_comlink"
		};
	};
};
class CfgFontFamilies
{
	class JLTS_republic
	{
		fonts[]=
		{
			"\MRC\JLTS\radios\fonts\republic\republic6",
			"\MRC\JLTS\radios\fonts\republic\republic7",
			"\MRC\JLTS\radios\fonts\republic\republic8",
			"\MRC\JLTS\radios\fonts\republic\republic9",
			"\MRC\JLTS\radios\fonts\republic\republic10",
			"\MRC\JLTS\radios\fonts\republic\republic11",
			"\MRC\JLTS\radios\fonts\republic\republic12",
			"\MRC\JLTS\radios\fonts\republic\republic13",
			"\MRC\JLTS\radios\fonts\republic\republic14",
			"\MRC\JLTS\radios\fonts\republic\republic15",
			"\MRC\JLTS\radios\fonts\republic\republic16",
			"\MRC\JLTS\radios\fonts\republic\republic17",
			"\MRC\JLTS\radios\fonts\republic\republic18",
			"\MRC\JLTS\radios\fonts\republic\republic19",
			"\MRC\JLTS\radios\fonts\republic\republic20",
			"\MRC\JLTS\radios\fonts\republic\republic21",
			"\MRC\JLTS\radios\fonts\republic\republic22",
			"\MRC\JLTS\radios\fonts\republic\republic23",
			"\MRC\JLTS\radios\fonts\republic\republic24",
			"\MRC\JLTS\radios\fonts\republic\republic25",
			"\MRC\JLTS\radios\fonts\republic\republic26",
			"\MRC\JLTS\radios\fonts\republic\republic27",
			"\MRC\JLTS\radios\fonts\republic\republic28",
			"\MRC\JLTS\radios\fonts\republic\republic29",
			"\MRC\JLTS\radios\fonts\republic\republic30",
			"\MRC\JLTS\radios\fonts\republic\republic31",
			"\MRC\JLTS\radios\fonts\republic\republic34",
			"\MRC\JLTS\radios\fonts\republic\republic35",
			"\MRC\JLTS\radios\fonts\republic\republic37",
			"\MRC\JLTS\radios\fonts\republic\republic46"
		};
		spaceWidth=0.60000002;
		spacing=0.15000001;
	};
	class JLTS_aurebesh
	{
		fonts[]=
		{
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh6",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh7",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh8",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh9",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh10",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh11",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh12",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh13",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh14",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh15",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh16",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh17",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh18",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh19",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh20",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh21",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh22",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh23",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh24",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh25",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh26",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh27",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh28",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh29",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh30",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh31",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh34",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh35",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh37",
			"\MRC\JLTS\radios\fonts\aurebesh\aurebesh46"
		};
		spaceWidth=0.60000002;
		spacing=0.15000001;
	};
};
class RscBackPicture;
class RscEditLCD;
class HiddenButton;
class HiddenRotator;
class CfgWeapons
{
	class ItemRadio;
	class TFAR_anprc152;
	class JLTS_clone_comlink: TFAR_anprc152
	{
		author="MrClock";
		displayName="$STR_JLTS_names_RadioCWP8";
		descriptionShort="$STR_JLTS_descs_RadioCWP8";
		scope=2;
		scopeArsenal=2;
		scopeCurator=2;
		picture="\MRC\JLTS\radios\data\ui\clone_comlink_item_ui_ca.paa";
		model="\A3\weapons_F\ammo\mag_univ.p3d";
		tf_prototype=1;
		tf_range=5000;
		tf_dialog="JLTS_clone_comlink_dialog";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialogUpdate="call TFAR_fnc_updateSWDialogToChannel;";
		tf_subtype="digital";
		tf_parent="JLTS_clone_comlink";
		tf_additional_channel=1;
	};
	class JLTS_droid_comlink: JLTS_clone_comlink
	{
		displayName="$STR_JLTS_names_RadioDroid";
		descriptionShort="$STR_JLTS_descs_RadioDroid";
		picture="\MRC\JLTS\radios\data\ui\droid_comlink_item_ui_ca.paa";
		tf_dialog="JLTS_droid_comlink_dialog";
		tf_encryptionCode="tf_east_radio_code";
		tf_parent="JLTS_droid_comlink";
	};
	class JLTS_clone_comlink_1: JLTS_clone_comlink
	{
		displayName="CWP-8 1";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_2: JLTS_clone_comlink
	{
		displayName="CWP-8 2";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_3: JLTS_clone_comlink
	{
		displayName="CWP-8 3";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_4: JLTS_clone_comlink
	{
		displayName="CWP-8 4";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_5: JLTS_clone_comlink
	{
		displayName="CWP-8 5";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_6: JLTS_clone_comlink
	{
		displayName="CWP-8 6";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_7: JLTS_clone_comlink
	{
		displayName="CWP-8 7";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_8: JLTS_clone_comlink
	{
		displayName="CWP-8 8";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_9: JLTS_clone_comlink
	{
		displayName="CWP-8 9";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_10: JLTS_clone_comlink
	{
		displayName="CWP-8 10";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_11: JLTS_clone_comlink
	{
		displayName="CWP-8 11";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_12: JLTS_clone_comlink
	{
		displayName="CWP-8 12";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_13: JLTS_clone_comlink
	{
		displayName="CWP-8 13";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_14: JLTS_clone_comlink
	{
		displayName="CWP-8 14";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_15: JLTS_clone_comlink
	{
		displayName="CWP-8 15";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_16: JLTS_clone_comlink
	{
		displayName="CWP-8 16";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_17: JLTS_clone_comlink
	{
		displayName="CWP-8 17";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_18: JLTS_clone_comlink
	{
		displayName="CWP-8 18";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_19: JLTS_clone_comlink
	{
		displayName="CWP-8 19";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_20: JLTS_clone_comlink
	{
		displayName="CWP-8 20";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_21: JLTS_clone_comlink
	{
		displayName="CWP-8 21";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_22: JLTS_clone_comlink
	{
		displayName="CWP-8 22";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_23: JLTS_clone_comlink
	{
		displayName="CWP-8 23";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_24: JLTS_clone_comlink
	{
		displayName="CWP-8 24";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_25: JLTS_clone_comlink
	{
		displayName="CWP-8 25";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_26: JLTS_clone_comlink
	{
		displayName="CWP-8 26";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_27: JLTS_clone_comlink
	{
		displayName="CWP-8 27";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_28: JLTS_clone_comlink
	{
		displayName="CWP-8 28";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_29: JLTS_clone_comlink
	{
		displayName="CWP-8 29";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_30: JLTS_clone_comlink
	{
		displayName="CWP-8 30";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_31: JLTS_clone_comlink
	{
		displayName="CWP-8 31";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_32: JLTS_clone_comlink
	{
		displayName="CWP-8 32";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_33: JLTS_clone_comlink
	{
		displayName="CWP-8 33";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_34: JLTS_clone_comlink
	{
		displayName="CWP-8 34";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_35: JLTS_clone_comlink
	{
		displayName="CWP-8 35";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_36: JLTS_clone_comlink
	{
		displayName="CWP-8 36";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_37: JLTS_clone_comlink
	{
		displayName="CWP-8 37";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_38: JLTS_clone_comlink
	{
		displayName="CWP-8 38";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_39: JLTS_clone_comlink
	{
		displayName="CWP-8 39";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_40: JLTS_clone_comlink
	{
		displayName="CWP-8 40";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_41: JLTS_clone_comlink
	{
		displayName="CWP-8 41";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_42: JLTS_clone_comlink
	{
		displayName="CWP-8 42";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_43: JLTS_clone_comlink
	{
		displayName="CWP-8 43";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_44: JLTS_clone_comlink
	{
		displayName="CWP-8 44";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_45: JLTS_clone_comlink
	{
		displayName="CWP-8 45";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_46: JLTS_clone_comlink
	{
		displayName="CWP-8 46";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_47: JLTS_clone_comlink
	{
		displayName="CWP-8 47";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_48: JLTS_clone_comlink
	{
		displayName="CWP-8 48";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_49: JLTS_clone_comlink
	{
		displayName="CWP-8 49";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_50: JLTS_clone_comlink
	{
		displayName="CWP-8 50";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_51: JLTS_clone_comlink
	{
		displayName="CWP-8 51";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_52: JLTS_clone_comlink
	{
		displayName="CWP-8 52";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_53: JLTS_clone_comlink
	{
		displayName="CWP-8 53";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_54: JLTS_clone_comlink
	{
		displayName="CWP-8 54";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_55: JLTS_clone_comlink
	{
		displayName="CWP-8 55";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_56: JLTS_clone_comlink
	{
		displayName="CWP-8 56";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_57: JLTS_clone_comlink
	{
		displayName="CWP-8 57";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_58: JLTS_clone_comlink
	{
		displayName="CWP-8 58";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_59: JLTS_clone_comlink
	{
		displayName="CWP-8 59";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_60: JLTS_clone_comlink
	{
		displayName="CWP-8 60";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_61: JLTS_clone_comlink
	{
		displayName="CWP-8 61";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_62: JLTS_clone_comlink
	{
		displayName="CWP-8 62";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_63: JLTS_clone_comlink
	{
		displayName="CWP-8 63";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_64: JLTS_clone_comlink
	{
		displayName="CWP-8 64";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_65: JLTS_clone_comlink
	{
		displayName="CWP-8 65";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_66: JLTS_clone_comlink
	{
		displayName="CWP-8 66";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_67: JLTS_clone_comlink
	{
		displayName="CWP-8 67";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_68: JLTS_clone_comlink
	{
		displayName="CWP-8 68";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_69: JLTS_clone_comlink
	{
		displayName="CWP-8 69";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_70: JLTS_clone_comlink
	{
		displayName="CWP-8 70";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_71: JLTS_clone_comlink
	{
		displayName="CWP-8 71";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_72: JLTS_clone_comlink
	{
		displayName="CWP-8 72";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_73: JLTS_clone_comlink
	{
		displayName="CWP-8 73";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_74: JLTS_clone_comlink
	{
		displayName="CWP-8 74";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_75: JLTS_clone_comlink
	{
		displayName="CWP-8 75";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_76: JLTS_clone_comlink
	{
		displayName="CWP-8 76";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_77: JLTS_clone_comlink
	{
		displayName="CWP-8 77";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_78: JLTS_clone_comlink
	{
		displayName="CWP-8 78";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_79: JLTS_clone_comlink
	{
		displayName="CWP-8 79";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_80: JLTS_clone_comlink
	{
		displayName="CWP-8 80";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_81: JLTS_clone_comlink
	{
		displayName="CWP-8 81";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_82: JLTS_clone_comlink
	{
		displayName="CWP-8 82";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_83: JLTS_clone_comlink
	{
		displayName="CWP-8 83";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_84: JLTS_clone_comlink
	{
		displayName="CWP-8 84";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_85: JLTS_clone_comlink
	{
		displayName="CWP-8 85";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_86: JLTS_clone_comlink
	{
		displayName="CWP-8 86";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_87: JLTS_clone_comlink
	{
		displayName="CWP-8 87";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_88: JLTS_clone_comlink
	{
		displayName="CWP-8 88";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_89: JLTS_clone_comlink
	{
		displayName="CWP-8 89";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_90: JLTS_clone_comlink
	{
		displayName="CWP-8 90";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_91: JLTS_clone_comlink
	{
		displayName="CWP-8 91";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_92: JLTS_clone_comlink
	{
		displayName="CWP-8 92";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_93: JLTS_clone_comlink
	{
		displayName="CWP-8 93";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_94: JLTS_clone_comlink
	{
		displayName="CWP-8 94";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_95: JLTS_clone_comlink
	{
		displayName="CWP-8 95";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_96: JLTS_clone_comlink
	{
		displayName="CWP-8 96";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_97: JLTS_clone_comlink
	{
		displayName="CWP-8 97";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_98: JLTS_clone_comlink
	{
		displayName="CWP-8 98";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_99: JLTS_clone_comlink
	{
		displayName="CWP-8 99";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_100: JLTS_clone_comlink
	{
		displayName="CWP-8 100";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_101: JLTS_clone_comlink
	{
		displayName="CWP-8 101";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_102: JLTS_clone_comlink
	{
		displayName="CWP-8 102";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_103: JLTS_clone_comlink
	{
		displayName="CWP-8 103";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_104: JLTS_clone_comlink
	{
		displayName="CWP-8 104";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_105: JLTS_clone_comlink
	{
		displayName="CWP-8 105";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_106: JLTS_clone_comlink
	{
		displayName="CWP-8 106";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_107: JLTS_clone_comlink
	{
		displayName="CWP-8 107";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_108: JLTS_clone_comlink
	{
		displayName="CWP-8 108";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_109: JLTS_clone_comlink
	{
		displayName="CWP-8 109";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_110: JLTS_clone_comlink
	{
		displayName="CWP-8 110";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_111: JLTS_clone_comlink
	{
		displayName="CWP-8 111";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_112: JLTS_clone_comlink
	{
		displayName="CWP-8 112";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_113: JLTS_clone_comlink
	{
		displayName="CWP-8 113";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_114: JLTS_clone_comlink
	{
		displayName="CWP-8 114";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_115: JLTS_clone_comlink
	{
		displayName="CWP-8 115";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_116: JLTS_clone_comlink
	{
		displayName="CWP-8 116";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_117: JLTS_clone_comlink
	{
		displayName="CWP-8 117";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_118: JLTS_clone_comlink
	{
		displayName="CWP-8 118";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_119: JLTS_clone_comlink
	{
		displayName="CWP-8 119";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_120: JLTS_clone_comlink
	{
		displayName="CWP-8 120";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_121: JLTS_clone_comlink
	{
		displayName="CWP-8 121";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_122: JLTS_clone_comlink
	{
		displayName="CWP-8 122";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_123: JLTS_clone_comlink
	{
		displayName="CWP-8 123";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_124: JLTS_clone_comlink
	{
		displayName="CWP-8 124";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_125: JLTS_clone_comlink
	{
		displayName="CWP-8 125";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_126: JLTS_clone_comlink
	{
		displayName="CWP-8 126";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_127: JLTS_clone_comlink
	{
		displayName="CWP-8 127";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_128: JLTS_clone_comlink
	{
		displayName="CWP-8 128";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_129: JLTS_clone_comlink
	{
		displayName="CWP-8 129";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_130: JLTS_clone_comlink
	{
		displayName="CWP-8 130";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_131: JLTS_clone_comlink
	{
		displayName="CWP-8 131";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_132: JLTS_clone_comlink
	{
		displayName="CWP-8 132";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_133: JLTS_clone_comlink
	{
		displayName="CWP-8 133";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_134: JLTS_clone_comlink
	{
		displayName="CWP-8 134";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_135: JLTS_clone_comlink
	{
		displayName="CWP-8 135";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_136: JLTS_clone_comlink
	{
		displayName="CWP-8 136";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_137: JLTS_clone_comlink
	{
		displayName="CWP-8 137";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_138: JLTS_clone_comlink
	{
		displayName="CWP-8 138";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_139: JLTS_clone_comlink
	{
		displayName="CWP-8 139";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_140: JLTS_clone_comlink
	{
		displayName="CWP-8 140";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_141: JLTS_clone_comlink
	{
		displayName="CWP-8 141";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_142: JLTS_clone_comlink
	{
		displayName="CWP-8 142";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_143: JLTS_clone_comlink
	{
		displayName="CWP-8 143";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_144: JLTS_clone_comlink
	{
		displayName="CWP-8 144";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_145: JLTS_clone_comlink
	{
		displayName="CWP-8 145";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_146: JLTS_clone_comlink
	{
		displayName="CWP-8 146";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_147: JLTS_clone_comlink
	{
		displayName="CWP-8 147";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_148: JLTS_clone_comlink
	{
		displayName="CWP-8 148";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_149: JLTS_clone_comlink
	{
		displayName="CWP-8 149";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_150: JLTS_clone_comlink
	{
		displayName="CWP-8 150";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_151: JLTS_clone_comlink
	{
		displayName="CWP-8 151";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_152: JLTS_clone_comlink
	{
		displayName="CWP-8 152";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_153: JLTS_clone_comlink
	{
		displayName="CWP-8 153";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_154: JLTS_clone_comlink
	{
		displayName="CWP-8 154";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_155: JLTS_clone_comlink
	{
		displayName="CWP-8 155";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_156: JLTS_clone_comlink
	{
		displayName="CWP-8 156";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_157: JLTS_clone_comlink
	{
		displayName="CWP-8 157";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_158: JLTS_clone_comlink
	{
		displayName="CWP-8 158";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_159: JLTS_clone_comlink
	{
		displayName="CWP-8 159";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_160: JLTS_clone_comlink
	{
		displayName="CWP-8 160";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_161: JLTS_clone_comlink
	{
		displayName="CWP-8 161";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_162: JLTS_clone_comlink
	{
		displayName="CWP-8 162";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_163: JLTS_clone_comlink
	{
		displayName="CWP-8 163";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_164: JLTS_clone_comlink
	{
		displayName="CWP-8 164";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_165: JLTS_clone_comlink
	{
		displayName="CWP-8 165";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_166: JLTS_clone_comlink
	{
		displayName="CWP-8 166";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_167: JLTS_clone_comlink
	{
		displayName="CWP-8 167";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_168: JLTS_clone_comlink
	{
		displayName="CWP-8 168";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_169: JLTS_clone_comlink
	{
		displayName="CWP-8 169";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_170: JLTS_clone_comlink
	{
		displayName="CWP-8 170";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_171: JLTS_clone_comlink
	{
		displayName="CWP-8 171";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_172: JLTS_clone_comlink
	{
		displayName="CWP-8 172";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_173: JLTS_clone_comlink
	{
		displayName="CWP-8 173";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_174: JLTS_clone_comlink
	{
		displayName="CWP-8 174";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_175: JLTS_clone_comlink
	{
		displayName="CWP-8 175";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_176: JLTS_clone_comlink
	{
		displayName="CWP-8 176";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_177: JLTS_clone_comlink
	{
		displayName="CWP-8 177";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_178: JLTS_clone_comlink
	{
		displayName="CWP-8 178";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_179: JLTS_clone_comlink
	{
		displayName="CWP-8 179";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_180: JLTS_clone_comlink
	{
		displayName="CWP-8 180";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_181: JLTS_clone_comlink
	{
		displayName="CWP-8 181";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_182: JLTS_clone_comlink
	{
		displayName="CWP-8 182";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_183: JLTS_clone_comlink
	{
		displayName="CWP-8 183";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_184: JLTS_clone_comlink
	{
		displayName="CWP-8 184";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_185: JLTS_clone_comlink
	{
		displayName="CWP-8 185";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_186: JLTS_clone_comlink
	{
		displayName="CWP-8 186";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_187: JLTS_clone_comlink
	{
		displayName="CWP-8 187";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_188: JLTS_clone_comlink
	{
		displayName="CWP-8 188";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_189: JLTS_clone_comlink
	{
		displayName="CWP-8 189";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_190: JLTS_clone_comlink
	{
		displayName="CWP-8 190";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_191: JLTS_clone_comlink
	{
		displayName="CWP-8 191";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_192: JLTS_clone_comlink
	{
		displayName="CWP-8 192";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_193: JLTS_clone_comlink
	{
		displayName="CWP-8 193";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_194: JLTS_clone_comlink
	{
		displayName="CWP-8 194";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_195: JLTS_clone_comlink
	{
		displayName="CWP-8 195";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_196: JLTS_clone_comlink
	{
		displayName="CWP-8 196";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_197: JLTS_clone_comlink
	{
		displayName="CWP-8 197";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_198: JLTS_clone_comlink
	{
		displayName="CWP-8 198";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_199: JLTS_clone_comlink
	{
		displayName="CWP-8 199";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_200: JLTS_clone_comlink
	{
		displayName="CWP-8 200";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_201: JLTS_clone_comlink
	{
		displayName="CWP-8 201";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_202: JLTS_clone_comlink
	{
		displayName="CWP-8 202";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_203: JLTS_clone_comlink
	{
		displayName="CWP-8 203";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_204: JLTS_clone_comlink
	{
		displayName="CWP-8 204";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_205: JLTS_clone_comlink
	{
		displayName="CWP-8 205";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_206: JLTS_clone_comlink
	{
		displayName="CWP-8 206";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_207: JLTS_clone_comlink
	{
		displayName="CWP-8 207";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_208: JLTS_clone_comlink
	{
		displayName="CWP-8 208";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_209: JLTS_clone_comlink
	{
		displayName="CWP-8 209";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_210: JLTS_clone_comlink
	{
		displayName="CWP-8 210";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_211: JLTS_clone_comlink
	{
		displayName="CWP-8 211";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_212: JLTS_clone_comlink
	{
		displayName="CWP-8 212";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_213: JLTS_clone_comlink
	{
		displayName="CWP-8 213";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_214: JLTS_clone_comlink
	{
		displayName="CWP-8 214";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_215: JLTS_clone_comlink
	{
		displayName="CWP-8 215";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_216: JLTS_clone_comlink
	{
		displayName="CWP-8 216";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_217: JLTS_clone_comlink
	{
		displayName="CWP-8 217";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_218: JLTS_clone_comlink
	{
		displayName="CWP-8 218";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_219: JLTS_clone_comlink
	{
		displayName="CWP-8 219";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_220: JLTS_clone_comlink
	{
		displayName="CWP-8 220";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_221: JLTS_clone_comlink
	{
		displayName="CWP-8 221";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_222: JLTS_clone_comlink
	{
		displayName="CWP-8 222";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_223: JLTS_clone_comlink
	{
		displayName="CWP-8 223";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_224: JLTS_clone_comlink
	{
		displayName="CWP-8 224";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_225: JLTS_clone_comlink
	{
		displayName="CWP-8 225";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_226: JLTS_clone_comlink
	{
		displayName="CWP-8 226";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_227: JLTS_clone_comlink
	{
		displayName="CWP-8 227";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_228: JLTS_clone_comlink
	{
		displayName="CWP-8 228";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_229: JLTS_clone_comlink
	{
		displayName="CWP-8 229";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_230: JLTS_clone_comlink
	{
		displayName="CWP-8 230";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_231: JLTS_clone_comlink
	{
		displayName="CWP-8 231";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_232: JLTS_clone_comlink
	{
		displayName="CWP-8 232";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_233: JLTS_clone_comlink
	{
		displayName="CWP-8 233";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_234: JLTS_clone_comlink
	{
		displayName="CWP-8 234";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_235: JLTS_clone_comlink
	{
		displayName="CWP-8 235";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_236: JLTS_clone_comlink
	{
		displayName="CWP-8 236";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_237: JLTS_clone_comlink
	{
		displayName="CWP-8 237";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_238: JLTS_clone_comlink
	{
		displayName="CWP-8 238";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_239: JLTS_clone_comlink
	{
		displayName="CWP-8 239";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_240: JLTS_clone_comlink
	{
		displayName="CWP-8 240";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_241: JLTS_clone_comlink
	{
		displayName="CWP-8 241";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_242: JLTS_clone_comlink
	{
		displayName="CWP-8 242";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_243: JLTS_clone_comlink
	{
		displayName="CWP-8 243";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_244: JLTS_clone_comlink
	{
		displayName="CWP-8 244";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_245: JLTS_clone_comlink
	{
		displayName="CWP-8 245";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_246: JLTS_clone_comlink
	{
		displayName="CWP-8 246";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_247: JLTS_clone_comlink
	{
		displayName="CWP-8 247";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_248: JLTS_clone_comlink
	{
		displayName="CWP-8 248";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_249: JLTS_clone_comlink
	{
		displayName="CWP-8 249";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_250: JLTS_clone_comlink
	{
		displayName="CWP-8 250";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_251: JLTS_clone_comlink
	{
		displayName="CWP-8 251";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_252: JLTS_clone_comlink
	{
		displayName="CWP-8 252";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_253: JLTS_clone_comlink
	{
		displayName="CWP-8 253";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_254: JLTS_clone_comlink
	{
		displayName="CWP-8 254";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_255: JLTS_clone_comlink
	{
		displayName="CWP-8 255";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_256: JLTS_clone_comlink
	{
		displayName="CWP-8 256";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_257: JLTS_clone_comlink
	{
		displayName="CWP-8 257";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_258: JLTS_clone_comlink
	{
		displayName="CWP-8 258";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_259: JLTS_clone_comlink
	{
		displayName="CWP-8 259";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_260: JLTS_clone_comlink
	{
		displayName="CWP-8 260";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_261: JLTS_clone_comlink
	{
		displayName="CWP-8 261";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_262: JLTS_clone_comlink
	{
		displayName="CWP-8 262";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_263: JLTS_clone_comlink
	{
		displayName="CWP-8 263";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_264: JLTS_clone_comlink
	{
		displayName="CWP-8 264";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_265: JLTS_clone_comlink
	{
		displayName="CWP-8 265";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_266: JLTS_clone_comlink
	{
		displayName="CWP-8 266";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_267: JLTS_clone_comlink
	{
		displayName="CWP-8 267";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_268: JLTS_clone_comlink
	{
		displayName="CWP-8 268";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_269: JLTS_clone_comlink
	{
		displayName="CWP-8 269";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_270: JLTS_clone_comlink
	{
		displayName="CWP-8 270";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_271: JLTS_clone_comlink
	{
		displayName="CWP-8 271";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_272: JLTS_clone_comlink
	{
		displayName="CWP-8 272";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_273: JLTS_clone_comlink
	{
		displayName="CWP-8 273";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_274: JLTS_clone_comlink
	{
		displayName="CWP-8 274";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_275: JLTS_clone_comlink
	{
		displayName="CWP-8 275";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_276: JLTS_clone_comlink
	{
		displayName="CWP-8 276";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_277: JLTS_clone_comlink
	{
		displayName="CWP-8 277";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_278: JLTS_clone_comlink
	{
		displayName="CWP-8 278";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_279: JLTS_clone_comlink
	{
		displayName="CWP-8 279";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_280: JLTS_clone_comlink
	{
		displayName="CWP-8 280";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_281: JLTS_clone_comlink
	{
		displayName="CWP-8 281";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_282: JLTS_clone_comlink
	{
		displayName="CWP-8 282";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_283: JLTS_clone_comlink
	{
		displayName="CWP-8 283";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_284: JLTS_clone_comlink
	{
		displayName="CWP-8 284";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_285: JLTS_clone_comlink
	{
		displayName="CWP-8 285";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_286: JLTS_clone_comlink
	{
		displayName="CWP-8 286";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_287: JLTS_clone_comlink
	{
		displayName="CWP-8 287";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_288: JLTS_clone_comlink
	{
		displayName="CWP-8 288";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_289: JLTS_clone_comlink
	{
		displayName="CWP-8 289";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_290: JLTS_clone_comlink
	{
		displayName="CWP-8 290";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_291: JLTS_clone_comlink
	{
		displayName="CWP-8 291";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_292: JLTS_clone_comlink
	{
		displayName="CWP-8 292";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_293: JLTS_clone_comlink
	{
		displayName="CWP-8 293";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_294: JLTS_clone_comlink
	{
		displayName="CWP-8 294";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_295: JLTS_clone_comlink
	{
		displayName="CWP-8 295";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_296: JLTS_clone_comlink
	{
		displayName="CWP-8 296";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_297: JLTS_clone_comlink
	{
		displayName="CWP-8 297";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_298: JLTS_clone_comlink
	{
		displayName="CWP-8 298";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_299: JLTS_clone_comlink
	{
		displayName="CWP-8 299";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_300: JLTS_clone_comlink
	{
		displayName="CWP-8 300";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_301: JLTS_clone_comlink
	{
		displayName="CWP-8 301";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_302: JLTS_clone_comlink
	{
		displayName="CWP-8 302";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_303: JLTS_clone_comlink
	{
		displayName="CWP-8 303";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_304: JLTS_clone_comlink
	{
		displayName="CWP-8 304";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_305: JLTS_clone_comlink
	{
		displayName="CWP-8 305";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_306: JLTS_clone_comlink
	{
		displayName="CWP-8 306";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_307: JLTS_clone_comlink
	{
		displayName="CWP-8 307";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_308: JLTS_clone_comlink
	{
		displayName="CWP-8 308";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_309: JLTS_clone_comlink
	{
		displayName="CWP-8 309";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_310: JLTS_clone_comlink
	{
		displayName="CWP-8 310";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_311: JLTS_clone_comlink
	{
		displayName="CWP-8 311";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_312: JLTS_clone_comlink
	{
		displayName="CWP-8 312";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_313: JLTS_clone_comlink
	{
		displayName="CWP-8 313";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_314: JLTS_clone_comlink
	{
		displayName="CWP-8 314";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_315: JLTS_clone_comlink
	{
		displayName="CWP-8 315";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_316: JLTS_clone_comlink
	{
		displayName="CWP-8 316";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_317: JLTS_clone_comlink
	{
		displayName="CWP-8 317";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_318: JLTS_clone_comlink
	{
		displayName="CWP-8 318";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_319: JLTS_clone_comlink
	{
		displayName="CWP-8 319";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_320: JLTS_clone_comlink
	{
		displayName="CWP-8 320";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_321: JLTS_clone_comlink
	{
		displayName="CWP-8 321";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_322: JLTS_clone_comlink
	{
		displayName="CWP-8 322";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_323: JLTS_clone_comlink
	{
		displayName="CWP-8 323";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_324: JLTS_clone_comlink
	{
		displayName="CWP-8 324";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_325: JLTS_clone_comlink
	{
		displayName="CWP-8 325";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_326: JLTS_clone_comlink
	{
		displayName="CWP-8 326";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_327: JLTS_clone_comlink
	{
		displayName="CWP-8 327";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_328: JLTS_clone_comlink
	{
		displayName="CWP-8 328";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_329: JLTS_clone_comlink
	{
		displayName="CWP-8 329";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_330: JLTS_clone_comlink
	{
		displayName="CWP-8 330";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_331: JLTS_clone_comlink
	{
		displayName="CWP-8 331";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_332: JLTS_clone_comlink
	{
		displayName="CWP-8 332";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_333: JLTS_clone_comlink
	{
		displayName="CWP-8 333";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_334: JLTS_clone_comlink
	{
		displayName="CWP-8 334";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_335: JLTS_clone_comlink
	{
		displayName="CWP-8 335";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_336: JLTS_clone_comlink
	{
		displayName="CWP-8 336";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_337: JLTS_clone_comlink
	{
		displayName="CWP-8 337";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_338: JLTS_clone_comlink
	{
		displayName="CWP-8 338";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_339: JLTS_clone_comlink
	{
		displayName="CWP-8 339";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_340: JLTS_clone_comlink
	{
		displayName="CWP-8 340";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_341: JLTS_clone_comlink
	{
		displayName="CWP-8 341";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_342: JLTS_clone_comlink
	{
		displayName="CWP-8 342";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_343: JLTS_clone_comlink
	{
		displayName="CWP-8 343";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_344: JLTS_clone_comlink
	{
		displayName="CWP-8 344";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_345: JLTS_clone_comlink
	{
		displayName="CWP-8 345";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_346: JLTS_clone_comlink
	{
		displayName="CWP-8 346";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_347: JLTS_clone_comlink
	{
		displayName="CWP-8 347";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_348: JLTS_clone_comlink
	{
		displayName="CWP-8 348";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_349: JLTS_clone_comlink
	{
		displayName="CWP-8 349";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_350: JLTS_clone_comlink
	{
		displayName="CWP-8 350";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_351: JLTS_clone_comlink
	{
		displayName="CWP-8 351";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_352: JLTS_clone_comlink
	{
		displayName="CWP-8 352";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_353: JLTS_clone_comlink
	{
		displayName="CWP-8 353";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_354: JLTS_clone_comlink
	{
		displayName="CWP-8 354";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_355: JLTS_clone_comlink
	{
		displayName="CWP-8 355";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_356: JLTS_clone_comlink
	{
		displayName="CWP-8 356";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_357: JLTS_clone_comlink
	{
		displayName="CWP-8 357";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_358: JLTS_clone_comlink
	{
		displayName="CWP-8 358";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_359: JLTS_clone_comlink
	{
		displayName="CWP-8 359";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_360: JLTS_clone_comlink
	{
		displayName="CWP-8 360";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_361: JLTS_clone_comlink
	{
		displayName="CWP-8 361";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_362: JLTS_clone_comlink
	{
		displayName="CWP-8 362";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_363: JLTS_clone_comlink
	{
		displayName="CWP-8 363";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_364: JLTS_clone_comlink
	{
		displayName="CWP-8 364";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_365: JLTS_clone_comlink
	{
		displayName="CWP-8 365";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_366: JLTS_clone_comlink
	{
		displayName="CWP-8 366";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_367: JLTS_clone_comlink
	{
		displayName="CWP-8 367";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_368: JLTS_clone_comlink
	{
		displayName="CWP-8 368";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_369: JLTS_clone_comlink
	{
		displayName="CWP-8 369";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_370: JLTS_clone_comlink
	{
		displayName="CWP-8 370";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_371: JLTS_clone_comlink
	{
		displayName="CWP-8 371";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_372: JLTS_clone_comlink
	{
		displayName="CWP-8 372";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_373: JLTS_clone_comlink
	{
		displayName="CWP-8 373";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_374: JLTS_clone_comlink
	{
		displayName="CWP-8 374";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_375: JLTS_clone_comlink
	{
		displayName="CWP-8 375";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_376: JLTS_clone_comlink
	{
		displayName="CWP-8 376";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_377: JLTS_clone_comlink
	{
		displayName="CWP-8 377";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_378: JLTS_clone_comlink
	{
		displayName="CWP-8 378";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_379: JLTS_clone_comlink
	{
		displayName="CWP-8 379";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_380: JLTS_clone_comlink
	{
		displayName="CWP-8 380";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_381: JLTS_clone_comlink
	{
		displayName="CWP-8 381";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_382: JLTS_clone_comlink
	{
		displayName="CWP-8 382";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_383: JLTS_clone_comlink
	{
		displayName="CWP-8 383";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_384: JLTS_clone_comlink
	{
		displayName="CWP-8 384";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_385: JLTS_clone_comlink
	{
		displayName="CWP-8 385";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_386: JLTS_clone_comlink
	{
		displayName="CWP-8 386";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_387: JLTS_clone_comlink
	{
		displayName="CWP-8 387";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_388: JLTS_clone_comlink
	{
		displayName="CWP-8 388";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_389: JLTS_clone_comlink
	{
		displayName="CWP-8 389";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_390: JLTS_clone_comlink
	{
		displayName="CWP-8 390";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_391: JLTS_clone_comlink
	{
		displayName="CWP-8 391";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_392: JLTS_clone_comlink
	{
		displayName="CWP-8 392";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_393: JLTS_clone_comlink
	{
		displayName="CWP-8 393";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_394: JLTS_clone_comlink
	{
		displayName="CWP-8 394";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_395: JLTS_clone_comlink
	{
		displayName="CWP-8 395";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_396: JLTS_clone_comlink
	{
		displayName="CWP-8 396";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_397: JLTS_clone_comlink
	{
		displayName="CWP-8 397";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_398: JLTS_clone_comlink
	{
		displayName="CWP-8 398";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_399: JLTS_clone_comlink
	{
		displayName="CWP-8 399";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_400: JLTS_clone_comlink
	{
		displayName="CWP-8 400";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_401: JLTS_clone_comlink
	{
		displayName="CWP-8 401";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_402: JLTS_clone_comlink
	{
		displayName="CWP-8 402";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_403: JLTS_clone_comlink
	{
		displayName="CWP-8 403";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_404: JLTS_clone_comlink
	{
		displayName="CWP-8 404";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_405: JLTS_clone_comlink
	{
		displayName="CWP-8 405";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_406: JLTS_clone_comlink
	{
		displayName="CWP-8 406";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_407: JLTS_clone_comlink
	{
		displayName="CWP-8 407";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_408: JLTS_clone_comlink
	{
		displayName="CWP-8 408";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_409: JLTS_clone_comlink
	{
		displayName="CWP-8 409";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_410: JLTS_clone_comlink
	{
		displayName="CWP-8 410";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_411: JLTS_clone_comlink
	{
		displayName="CWP-8 411";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_412: JLTS_clone_comlink
	{
		displayName="CWP-8 412";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_413: JLTS_clone_comlink
	{
		displayName="CWP-8 413";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_414: JLTS_clone_comlink
	{
		displayName="CWP-8 414";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_415: JLTS_clone_comlink
	{
		displayName="CWP-8 415";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_416: JLTS_clone_comlink
	{
		displayName="CWP-8 416";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_417: JLTS_clone_comlink
	{
		displayName="CWP-8 417";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_418: JLTS_clone_comlink
	{
		displayName="CWP-8 418";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_419: JLTS_clone_comlink
	{
		displayName="CWP-8 419";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_420: JLTS_clone_comlink
	{
		displayName="CWP-8 420";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_421: JLTS_clone_comlink
	{
		displayName="CWP-8 421";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_422: JLTS_clone_comlink
	{
		displayName="CWP-8 422";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_423: JLTS_clone_comlink
	{
		displayName="CWP-8 423";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_424: JLTS_clone_comlink
	{
		displayName="CWP-8 424";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_425: JLTS_clone_comlink
	{
		displayName="CWP-8 425";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_426: JLTS_clone_comlink
	{
		displayName="CWP-8 426";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_427: JLTS_clone_comlink
	{
		displayName="CWP-8 427";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_428: JLTS_clone_comlink
	{
		displayName="CWP-8 428";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_429: JLTS_clone_comlink
	{
		displayName="CWP-8 429";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_430: JLTS_clone_comlink
	{
		displayName="CWP-8 430";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_431: JLTS_clone_comlink
	{
		displayName="CWP-8 431";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_432: JLTS_clone_comlink
	{
		displayName="CWP-8 432";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_433: JLTS_clone_comlink
	{
		displayName="CWP-8 433";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_434: JLTS_clone_comlink
	{
		displayName="CWP-8 434";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_435: JLTS_clone_comlink
	{
		displayName="CWP-8 435";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_436: JLTS_clone_comlink
	{
		displayName="CWP-8 436";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_437: JLTS_clone_comlink
	{
		displayName="CWP-8 437";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_438: JLTS_clone_comlink
	{
		displayName="CWP-8 438";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_439: JLTS_clone_comlink
	{
		displayName="CWP-8 439";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_440: JLTS_clone_comlink
	{
		displayName="CWP-8 440";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_441: JLTS_clone_comlink
	{
		displayName="CWP-8 441";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_442: JLTS_clone_comlink
	{
		displayName="CWP-8 442";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_443: JLTS_clone_comlink
	{
		displayName="CWP-8 443";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_444: JLTS_clone_comlink
	{
		displayName="CWP-8 444";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_445: JLTS_clone_comlink
	{
		displayName="CWP-8 445";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_446: JLTS_clone_comlink
	{
		displayName="CWP-8 446";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_447: JLTS_clone_comlink
	{
		displayName="CWP-8 447";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_448: JLTS_clone_comlink
	{
		displayName="CWP-8 448";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_449: JLTS_clone_comlink
	{
		displayName="CWP-8 449";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_450: JLTS_clone_comlink
	{
		displayName="CWP-8 450";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_451: JLTS_clone_comlink
	{
		displayName="CWP-8 451";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_452: JLTS_clone_comlink
	{
		displayName="CWP-8 452";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_453: JLTS_clone_comlink
	{
		displayName="CWP-8 453";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_454: JLTS_clone_comlink
	{
		displayName="CWP-8 454";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_455: JLTS_clone_comlink
	{
		displayName="CWP-8 455";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_456: JLTS_clone_comlink
	{
		displayName="CWP-8 456";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_457: JLTS_clone_comlink
	{
		displayName="CWP-8 457";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_458: JLTS_clone_comlink
	{
		displayName="CWP-8 458";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_459: JLTS_clone_comlink
	{
		displayName="CWP-8 459";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_460: JLTS_clone_comlink
	{
		displayName="CWP-8 460";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_461: JLTS_clone_comlink
	{
		displayName="CWP-8 461";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_462: JLTS_clone_comlink
	{
		displayName="CWP-8 462";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_463: JLTS_clone_comlink
	{
		displayName="CWP-8 463";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_464: JLTS_clone_comlink
	{
		displayName="CWP-8 464";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_465: JLTS_clone_comlink
	{
		displayName="CWP-8 465";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_466: JLTS_clone_comlink
	{
		displayName="CWP-8 466";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_467: JLTS_clone_comlink
	{
		displayName="CWP-8 467";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_468: JLTS_clone_comlink
	{
		displayName="CWP-8 468";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_469: JLTS_clone_comlink
	{
		displayName="CWP-8 469";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_470: JLTS_clone_comlink
	{
		displayName="CWP-8 470";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_471: JLTS_clone_comlink
	{
		displayName="CWP-8 471";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_472: JLTS_clone_comlink
	{
		displayName="CWP-8 472";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_473: JLTS_clone_comlink
	{
		displayName="CWP-8 473";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_474: JLTS_clone_comlink
	{
		displayName="CWP-8 474";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_475: JLTS_clone_comlink
	{
		displayName="CWP-8 475";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_476: JLTS_clone_comlink
	{
		displayName="CWP-8 476";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_477: JLTS_clone_comlink
	{
		displayName="CWP-8 477";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_478: JLTS_clone_comlink
	{
		displayName="CWP-8 478";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_479: JLTS_clone_comlink
	{
		displayName="CWP-8 479";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_480: JLTS_clone_comlink
	{
		displayName="CWP-8 480";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_481: JLTS_clone_comlink
	{
		displayName="CWP-8 481";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_482: JLTS_clone_comlink
	{
		displayName="CWP-8 482";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_483: JLTS_clone_comlink
	{
		displayName="CWP-8 483";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_484: JLTS_clone_comlink
	{
		displayName="CWP-8 484";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_485: JLTS_clone_comlink
	{
		displayName="CWP-8 485";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_486: JLTS_clone_comlink
	{
		displayName="CWP-8 486";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_487: JLTS_clone_comlink
	{
		displayName="CWP-8 487";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_488: JLTS_clone_comlink
	{
		displayName="CWP-8 488";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_489: JLTS_clone_comlink
	{
		displayName="CWP-8 489";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_490: JLTS_clone_comlink
	{
		displayName="CWP-8 490";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_491: JLTS_clone_comlink
	{
		displayName="CWP-8 491";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_492: JLTS_clone_comlink
	{
		displayName="CWP-8 492";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_493: JLTS_clone_comlink
	{
		displayName="CWP-8 493";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_494: JLTS_clone_comlink
	{
		displayName="CWP-8 494";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_495: JLTS_clone_comlink
	{
		displayName="CWP-8 495";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_496: JLTS_clone_comlink
	{
		displayName="CWP-8 496";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_497: JLTS_clone_comlink
	{
		displayName="CWP-8 497";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_498: JLTS_clone_comlink
	{
		displayName="CWP-8 498";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_499: JLTS_clone_comlink
	{
		displayName="CWP-8 499";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_500: JLTS_clone_comlink
	{
		displayName="CWP-8 500";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_501: JLTS_clone_comlink
	{
		displayName="CWP-8 501";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_502: JLTS_clone_comlink
	{
		displayName="CWP-8 502";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_503: JLTS_clone_comlink
	{
		displayName="CWP-8 503";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_504: JLTS_clone_comlink
	{
		displayName="CWP-8 504";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_505: JLTS_clone_comlink
	{
		displayName="CWP-8 505";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_506: JLTS_clone_comlink
	{
		displayName="CWP-8 506";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_507: JLTS_clone_comlink
	{
		displayName="CWP-8 507";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_508: JLTS_clone_comlink
	{
		displayName="CWP-8 508";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_509: JLTS_clone_comlink
	{
		displayName="CWP-8 509";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_510: JLTS_clone_comlink
	{
		displayName="CWP-8 510";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_511: JLTS_clone_comlink
	{
		displayName="CWP-8 511";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_512: JLTS_clone_comlink
	{
		displayName="CWP-8 512";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_513: JLTS_clone_comlink
	{
		displayName="CWP-8 513";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_514: JLTS_clone_comlink
	{
		displayName="CWP-8 514";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_515: JLTS_clone_comlink
	{
		displayName="CWP-8 515";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_516: JLTS_clone_comlink
	{
		displayName="CWP-8 516";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_517: JLTS_clone_comlink
	{
		displayName="CWP-8 517";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_518: JLTS_clone_comlink
	{
		displayName="CWP-8 518";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_519: JLTS_clone_comlink
	{
		displayName="CWP-8 519";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_520: JLTS_clone_comlink
	{
		displayName="CWP-8 520";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_521: JLTS_clone_comlink
	{
		displayName="CWP-8 521";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_522: JLTS_clone_comlink
	{
		displayName="CWP-8 522";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_523: JLTS_clone_comlink
	{
		displayName="CWP-8 523";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_524: JLTS_clone_comlink
	{
		displayName="CWP-8 524";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_525: JLTS_clone_comlink
	{
		displayName="CWP-8 525";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_526: JLTS_clone_comlink
	{
		displayName="CWP-8 526";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_527: JLTS_clone_comlink
	{
		displayName="CWP-8 527";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_528: JLTS_clone_comlink
	{
		displayName="CWP-8 528";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_529: JLTS_clone_comlink
	{
		displayName="CWP-8 529";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_530: JLTS_clone_comlink
	{
		displayName="CWP-8 530";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_531: JLTS_clone_comlink
	{
		displayName="CWP-8 531";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_532: JLTS_clone_comlink
	{
		displayName="CWP-8 532";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_533: JLTS_clone_comlink
	{
		displayName="CWP-8 533";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_534: JLTS_clone_comlink
	{
		displayName="CWP-8 534";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_535: JLTS_clone_comlink
	{
		displayName="CWP-8 535";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_536: JLTS_clone_comlink
	{
		displayName="CWP-8 536";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_537: JLTS_clone_comlink
	{
		displayName="CWP-8 537";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_538: JLTS_clone_comlink
	{
		displayName="CWP-8 538";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_539: JLTS_clone_comlink
	{
		displayName="CWP-8 539";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_540: JLTS_clone_comlink
	{
		displayName="CWP-8 540";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_541: JLTS_clone_comlink
	{
		displayName="CWP-8 541";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_542: JLTS_clone_comlink
	{
		displayName="CWP-8 542";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_543: JLTS_clone_comlink
	{
		displayName="CWP-8 543";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_544: JLTS_clone_comlink
	{
		displayName="CWP-8 544";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_545: JLTS_clone_comlink
	{
		displayName="CWP-8 545";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_546: JLTS_clone_comlink
	{
		displayName="CWP-8 546";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_547: JLTS_clone_comlink
	{
		displayName="CWP-8 547";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_548: JLTS_clone_comlink
	{
		displayName="CWP-8 548";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_549: JLTS_clone_comlink
	{
		displayName="CWP-8 549";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_550: JLTS_clone_comlink
	{
		displayName="CWP-8 550";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_551: JLTS_clone_comlink
	{
		displayName="CWP-8 551";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_552: JLTS_clone_comlink
	{
		displayName="CWP-8 552";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_553: JLTS_clone_comlink
	{
		displayName="CWP-8 553";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_554: JLTS_clone_comlink
	{
		displayName="CWP-8 554";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_555: JLTS_clone_comlink
	{
		displayName="CWP-8 555";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_556: JLTS_clone_comlink
	{
		displayName="CWP-8 556";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_557: JLTS_clone_comlink
	{
		displayName="CWP-8 557";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_558: JLTS_clone_comlink
	{
		displayName="CWP-8 558";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_559: JLTS_clone_comlink
	{
		displayName="CWP-8 559";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_560: JLTS_clone_comlink
	{
		displayName="CWP-8 560";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_561: JLTS_clone_comlink
	{
		displayName="CWP-8 561";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_562: JLTS_clone_comlink
	{
		displayName="CWP-8 562";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_563: JLTS_clone_comlink
	{
		displayName="CWP-8 563";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_564: JLTS_clone_comlink
	{
		displayName="CWP-8 564";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_565: JLTS_clone_comlink
	{
		displayName="CWP-8 565";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_566: JLTS_clone_comlink
	{
		displayName="CWP-8 566";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_567: JLTS_clone_comlink
	{
		displayName="CWP-8 567";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_568: JLTS_clone_comlink
	{
		displayName="CWP-8 568";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_569: JLTS_clone_comlink
	{
		displayName="CWP-8 569";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_570: JLTS_clone_comlink
	{
		displayName="CWP-8 570";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_571: JLTS_clone_comlink
	{
		displayName="CWP-8 571";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_572: JLTS_clone_comlink
	{
		displayName="CWP-8 572";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_573: JLTS_clone_comlink
	{
		displayName="CWP-8 573";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_574: JLTS_clone_comlink
	{
		displayName="CWP-8 574";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_575: JLTS_clone_comlink
	{
		displayName="CWP-8 575";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_576: JLTS_clone_comlink
	{
		displayName="CWP-8 576";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_577: JLTS_clone_comlink
	{
		displayName="CWP-8 577";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_578: JLTS_clone_comlink
	{
		displayName="CWP-8 578";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_579: JLTS_clone_comlink
	{
		displayName="CWP-8 579";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_580: JLTS_clone_comlink
	{
		displayName="CWP-8 580";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_581: JLTS_clone_comlink
	{
		displayName="CWP-8 581";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_582: JLTS_clone_comlink
	{
		displayName="CWP-8 582";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_583: JLTS_clone_comlink
	{
		displayName="CWP-8 583";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_584: JLTS_clone_comlink
	{
		displayName="CWP-8 584";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_585: JLTS_clone_comlink
	{
		displayName="CWP-8 585";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_586: JLTS_clone_comlink
	{
		displayName="CWP-8 586";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_587: JLTS_clone_comlink
	{
		displayName="CWP-8 587";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_588: JLTS_clone_comlink
	{
		displayName="CWP-8 588";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_589: JLTS_clone_comlink
	{
		displayName="CWP-8 589";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_590: JLTS_clone_comlink
	{
		displayName="CWP-8 590";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_591: JLTS_clone_comlink
	{
		displayName="CWP-8 591";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_592: JLTS_clone_comlink
	{
		displayName="CWP-8 592";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_593: JLTS_clone_comlink
	{
		displayName="CWP-8 593";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_594: JLTS_clone_comlink
	{
		displayName="CWP-8 594";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_595: JLTS_clone_comlink
	{
		displayName="CWP-8 595";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_596: JLTS_clone_comlink
	{
		displayName="CWP-8 596";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_597: JLTS_clone_comlink
	{
		displayName="CWP-8 597";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_598: JLTS_clone_comlink
	{
		displayName="CWP-8 598";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_599: JLTS_clone_comlink
	{
		displayName="CWP-8 599";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_600: JLTS_clone_comlink
	{
		displayName="CWP-8 600";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_601: JLTS_clone_comlink
	{
		displayName="CWP-8 601";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_602: JLTS_clone_comlink
	{
		displayName="CWP-8 602";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_603: JLTS_clone_comlink
	{
		displayName="CWP-8 603";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_604: JLTS_clone_comlink
	{
		displayName="CWP-8 604";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_605: JLTS_clone_comlink
	{
		displayName="CWP-8 605";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_606: JLTS_clone_comlink
	{
		displayName="CWP-8 606";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_607: JLTS_clone_comlink
	{
		displayName="CWP-8 607";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_608: JLTS_clone_comlink
	{
		displayName="CWP-8 608";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_609: JLTS_clone_comlink
	{
		displayName="CWP-8 609";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_610: JLTS_clone_comlink
	{
		displayName="CWP-8 610";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_611: JLTS_clone_comlink
	{
		displayName="CWP-8 611";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_612: JLTS_clone_comlink
	{
		displayName="CWP-8 612";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_613: JLTS_clone_comlink
	{
		displayName="CWP-8 613";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_614: JLTS_clone_comlink
	{
		displayName="CWP-8 614";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_615: JLTS_clone_comlink
	{
		displayName="CWP-8 615";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_616: JLTS_clone_comlink
	{
		displayName="CWP-8 616";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_617: JLTS_clone_comlink
	{
		displayName="CWP-8 617";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_618: JLTS_clone_comlink
	{
		displayName="CWP-8 618";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_619: JLTS_clone_comlink
	{
		displayName="CWP-8 619";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_620: JLTS_clone_comlink
	{
		displayName="CWP-8 620";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_621: JLTS_clone_comlink
	{
		displayName="CWP-8 621";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_622: JLTS_clone_comlink
	{
		displayName="CWP-8 622";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_623: JLTS_clone_comlink
	{
		displayName="CWP-8 623";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_624: JLTS_clone_comlink
	{
		displayName="CWP-8 624";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_625: JLTS_clone_comlink
	{
		displayName="CWP-8 625";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_626: JLTS_clone_comlink
	{
		displayName="CWP-8 626";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_627: JLTS_clone_comlink
	{
		displayName="CWP-8 627";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_628: JLTS_clone_comlink
	{
		displayName="CWP-8 628";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_629: JLTS_clone_comlink
	{
		displayName="CWP-8 629";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_630: JLTS_clone_comlink
	{
		displayName="CWP-8 630";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_631: JLTS_clone_comlink
	{
		displayName="CWP-8 631";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_632: JLTS_clone_comlink
	{
		displayName="CWP-8 632";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_633: JLTS_clone_comlink
	{
		displayName="CWP-8 633";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_634: JLTS_clone_comlink
	{
		displayName="CWP-8 634";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_635: JLTS_clone_comlink
	{
		displayName="CWP-8 635";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_636: JLTS_clone_comlink
	{
		displayName="CWP-8 636";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_637: JLTS_clone_comlink
	{
		displayName="CWP-8 637";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_638: JLTS_clone_comlink
	{
		displayName="CWP-8 638";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_639: JLTS_clone_comlink
	{
		displayName="CWP-8 639";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_640: JLTS_clone_comlink
	{
		displayName="CWP-8 640";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_641: JLTS_clone_comlink
	{
		displayName="CWP-8 641";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_642: JLTS_clone_comlink
	{
		displayName="CWP-8 642";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_643: JLTS_clone_comlink
	{
		displayName="CWP-8 643";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_644: JLTS_clone_comlink
	{
		displayName="CWP-8 644";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_645: JLTS_clone_comlink
	{
		displayName="CWP-8 645";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_646: JLTS_clone_comlink
	{
		displayName="CWP-8 646";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_647: JLTS_clone_comlink
	{
		displayName="CWP-8 647";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_648: JLTS_clone_comlink
	{
		displayName="CWP-8 648";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_649: JLTS_clone_comlink
	{
		displayName="CWP-8 649";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_650: JLTS_clone_comlink
	{
		displayName="CWP-8 650";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_651: JLTS_clone_comlink
	{
		displayName="CWP-8 651";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_652: JLTS_clone_comlink
	{
		displayName="CWP-8 652";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_653: JLTS_clone_comlink
	{
		displayName="CWP-8 653";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_654: JLTS_clone_comlink
	{
		displayName="CWP-8 654";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_655: JLTS_clone_comlink
	{
		displayName="CWP-8 655";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_656: JLTS_clone_comlink
	{
		displayName="CWP-8 656";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_657: JLTS_clone_comlink
	{
		displayName="CWP-8 657";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_658: JLTS_clone_comlink
	{
		displayName="CWP-8 658";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_659: JLTS_clone_comlink
	{
		displayName="CWP-8 659";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_660: JLTS_clone_comlink
	{
		displayName="CWP-8 660";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_661: JLTS_clone_comlink
	{
		displayName="CWP-8 661";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_662: JLTS_clone_comlink
	{
		displayName="CWP-8 662";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_663: JLTS_clone_comlink
	{
		displayName="CWP-8 663";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_664: JLTS_clone_comlink
	{
		displayName="CWP-8 664";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_665: JLTS_clone_comlink
	{
		displayName="CWP-8 665";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_666: JLTS_clone_comlink
	{
		displayName="CWP-8 666";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_667: JLTS_clone_comlink
	{
		displayName="CWP-8 667";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_668: JLTS_clone_comlink
	{
		displayName="CWP-8 668";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_669: JLTS_clone_comlink
	{
		displayName="CWP-8 669";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_670: JLTS_clone_comlink
	{
		displayName="CWP-8 670";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_671: JLTS_clone_comlink
	{
		displayName="CWP-8 671";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_672: JLTS_clone_comlink
	{
		displayName="CWP-8 672";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_673: JLTS_clone_comlink
	{
		displayName="CWP-8 673";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_674: JLTS_clone_comlink
	{
		displayName="CWP-8 674";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_675: JLTS_clone_comlink
	{
		displayName="CWP-8 675";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_676: JLTS_clone_comlink
	{
		displayName="CWP-8 676";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_677: JLTS_clone_comlink
	{
		displayName="CWP-8 677";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_678: JLTS_clone_comlink
	{
		displayName="CWP-8 678";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_679: JLTS_clone_comlink
	{
		displayName="CWP-8 679";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_680: JLTS_clone_comlink
	{
		displayName="CWP-8 680";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_681: JLTS_clone_comlink
	{
		displayName="CWP-8 681";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_682: JLTS_clone_comlink
	{
		displayName="CWP-8 682";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_683: JLTS_clone_comlink
	{
		displayName="CWP-8 683";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_684: JLTS_clone_comlink
	{
		displayName="CWP-8 684";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_685: JLTS_clone_comlink
	{
		displayName="CWP-8 685";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_686: JLTS_clone_comlink
	{
		displayName="CWP-8 686";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_687: JLTS_clone_comlink
	{
		displayName="CWP-8 687";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_688: JLTS_clone_comlink
	{
		displayName="CWP-8 688";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_689: JLTS_clone_comlink
	{
		displayName="CWP-8 689";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_690: JLTS_clone_comlink
	{
		displayName="CWP-8 690";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_691: JLTS_clone_comlink
	{
		displayName="CWP-8 691";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_692: JLTS_clone_comlink
	{
		displayName="CWP-8 692";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_693: JLTS_clone_comlink
	{
		displayName="CWP-8 693";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_694: JLTS_clone_comlink
	{
		displayName="CWP-8 694";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_695: JLTS_clone_comlink
	{
		displayName="CWP-8 695";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_696: JLTS_clone_comlink
	{
		displayName="CWP-8 696";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_697: JLTS_clone_comlink
	{
		displayName="CWP-8 697";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_698: JLTS_clone_comlink
	{
		displayName="CWP-8 698";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_699: JLTS_clone_comlink
	{
		displayName="CWP-8 699";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_700: JLTS_clone_comlink
	{
		displayName="CWP-8 700";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_701: JLTS_clone_comlink
	{
		displayName="CWP-8 701";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_702: JLTS_clone_comlink
	{
		displayName="CWP-8 702";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_703: JLTS_clone_comlink
	{
		displayName="CWP-8 703";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_704: JLTS_clone_comlink
	{
		displayName="CWP-8 704";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_705: JLTS_clone_comlink
	{
		displayName="CWP-8 705";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_706: JLTS_clone_comlink
	{
		displayName="CWP-8 706";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_707: JLTS_clone_comlink
	{
		displayName="CWP-8 707";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_708: JLTS_clone_comlink
	{
		displayName="CWP-8 708";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_709: JLTS_clone_comlink
	{
		displayName="CWP-8 709";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_710: JLTS_clone_comlink
	{
		displayName="CWP-8 710";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_711: JLTS_clone_comlink
	{
		displayName="CWP-8 711";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_712: JLTS_clone_comlink
	{
		displayName="CWP-8 712";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_713: JLTS_clone_comlink
	{
		displayName="CWP-8 713";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_714: JLTS_clone_comlink
	{
		displayName="CWP-8 714";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_715: JLTS_clone_comlink
	{
		displayName="CWP-8 715";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_716: JLTS_clone_comlink
	{
		displayName="CWP-8 716";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_717: JLTS_clone_comlink
	{
		displayName="CWP-8 717";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_718: JLTS_clone_comlink
	{
		displayName="CWP-8 718";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_719: JLTS_clone_comlink
	{
		displayName="CWP-8 719";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_720: JLTS_clone_comlink
	{
		displayName="CWP-8 720";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_721: JLTS_clone_comlink
	{
		displayName="CWP-8 721";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_722: JLTS_clone_comlink
	{
		displayName="CWP-8 722";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_723: JLTS_clone_comlink
	{
		displayName="CWP-8 723";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_724: JLTS_clone_comlink
	{
		displayName="CWP-8 724";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_725: JLTS_clone_comlink
	{
		displayName="CWP-8 725";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_726: JLTS_clone_comlink
	{
		displayName="CWP-8 726";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_727: JLTS_clone_comlink
	{
		displayName="CWP-8 727";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_728: JLTS_clone_comlink
	{
		displayName="CWP-8 728";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_729: JLTS_clone_comlink
	{
		displayName="CWP-8 729";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_730: JLTS_clone_comlink
	{
		displayName="CWP-8 730";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_731: JLTS_clone_comlink
	{
		displayName="CWP-8 731";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_732: JLTS_clone_comlink
	{
		displayName="CWP-8 732";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_733: JLTS_clone_comlink
	{
		displayName="CWP-8 733";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_734: JLTS_clone_comlink
	{
		displayName="CWP-8 734";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_735: JLTS_clone_comlink
	{
		displayName="CWP-8 735";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_736: JLTS_clone_comlink
	{
		displayName="CWP-8 736";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_737: JLTS_clone_comlink
	{
		displayName="CWP-8 737";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_738: JLTS_clone_comlink
	{
		displayName="CWP-8 738";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_739: JLTS_clone_comlink
	{
		displayName="CWP-8 739";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_740: JLTS_clone_comlink
	{
		displayName="CWP-8 740";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_741: JLTS_clone_comlink
	{
		displayName="CWP-8 741";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_742: JLTS_clone_comlink
	{
		displayName="CWP-8 742";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_743: JLTS_clone_comlink
	{
		displayName="CWP-8 743";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_744: JLTS_clone_comlink
	{
		displayName="CWP-8 744";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_745: JLTS_clone_comlink
	{
		displayName="CWP-8 745";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_746: JLTS_clone_comlink
	{
		displayName="CWP-8 746";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_747: JLTS_clone_comlink
	{
		displayName="CWP-8 747";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_748: JLTS_clone_comlink
	{
		displayName="CWP-8 748";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_749: JLTS_clone_comlink
	{
		displayName="CWP-8 749";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_750: JLTS_clone_comlink
	{
		displayName="CWP-8 750";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_751: JLTS_clone_comlink
	{
		displayName="CWP-8 751";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_752: JLTS_clone_comlink
	{
		displayName="CWP-8 752";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_753: JLTS_clone_comlink
	{
		displayName="CWP-8 753";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_754: JLTS_clone_comlink
	{
		displayName="CWP-8 754";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_755: JLTS_clone_comlink
	{
		displayName="CWP-8 755";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_756: JLTS_clone_comlink
	{
		displayName="CWP-8 756";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_757: JLTS_clone_comlink
	{
		displayName="CWP-8 757";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_758: JLTS_clone_comlink
	{
		displayName="CWP-8 758";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_759: JLTS_clone_comlink
	{
		displayName="CWP-8 759";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_760: JLTS_clone_comlink
	{
		displayName="CWP-8 760";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_761: JLTS_clone_comlink
	{
		displayName="CWP-8 761";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_762: JLTS_clone_comlink
	{
		displayName="CWP-8 762";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_763: JLTS_clone_comlink
	{
		displayName="CWP-8 763";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_764: JLTS_clone_comlink
	{
		displayName="CWP-8 764";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_765: JLTS_clone_comlink
	{
		displayName="CWP-8 765";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_766: JLTS_clone_comlink
	{
		displayName="CWP-8 766";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_767: JLTS_clone_comlink
	{
		displayName="CWP-8 767";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_768: JLTS_clone_comlink
	{
		displayName="CWP-8 768";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_769: JLTS_clone_comlink
	{
		displayName="CWP-8 769";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_770: JLTS_clone_comlink
	{
		displayName="CWP-8 770";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_771: JLTS_clone_comlink
	{
		displayName="CWP-8 771";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_772: JLTS_clone_comlink
	{
		displayName="CWP-8 772";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_773: JLTS_clone_comlink
	{
		displayName="CWP-8 773";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_774: JLTS_clone_comlink
	{
		displayName="CWP-8 774";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_775: JLTS_clone_comlink
	{
		displayName="CWP-8 775";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_776: JLTS_clone_comlink
	{
		displayName="CWP-8 776";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_777: JLTS_clone_comlink
	{
		displayName="CWP-8 777";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_778: JLTS_clone_comlink
	{
		displayName="CWP-8 778";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_779: JLTS_clone_comlink
	{
		displayName="CWP-8 779";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_780: JLTS_clone_comlink
	{
		displayName="CWP-8 780";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_781: JLTS_clone_comlink
	{
		displayName="CWP-8 781";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_782: JLTS_clone_comlink
	{
		displayName="CWP-8 782";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_783: JLTS_clone_comlink
	{
		displayName="CWP-8 783";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_784: JLTS_clone_comlink
	{
		displayName="CWP-8 784";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_785: JLTS_clone_comlink
	{
		displayName="CWP-8 785";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_786: JLTS_clone_comlink
	{
		displayName="CWP-8 786";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_787: JLTS_clone_comlink
	{
		displayName="CWP-8 787";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_788: JLTS_clone_comlink
	{
		displayName="CWP-8 788";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_789: JLTS_clone_comlink
	{
		displayName="CWP-8 789";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_790: JLTS_clone_comlink
	{
		displayName="CWP-8 790";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_791: JLTS_clone_comlink
	{
		displayName="CWP-8 791";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_792: JLTS_clone_comlink
	{
		displayName="CWP-8 792";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_793: JLTS_clone_comlink
	{
		displayName="CWP-8 793";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_794: JLTS_clone_comlink
	{
		displayName="CWP-8 794";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_795: JLTS_clone_comlink
	{
		displayName="CWP-8 795";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_796: JLTS_clone_comlink
	{
		displayName="CWP-8 796";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_797: JLTS_clone_comlink
	{
		displayName="CWP-8 797";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_798: JLTS_clone_comlink
	{
		displayName="CWP-8 798";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_799: JLTS_clone_comlink
	{
		displayName="CWP-8 799";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_800: JLTS_clone_comlink
	{
		displayName="CWP-8 800";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_801: JLTS_clone_comlink
	{
		displayName="CWP-8 801";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_802: JLTS_clone_comlink
	{
		displayName="CWP-8 802";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_803: JLTS_clone_comlink
	{
		displayName="CWP-8 803";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_804: JLTS_clone_comlink
	{
		displayName="CWP-8 804";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_805: JLTS_clone_comlink
	{
		displayName="CWP-8 805";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_806: JLTS_clone_comlink
	{
		displayName="CWP-8 806";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_807: JLTS_clone_comlink
	{
		displayName="CWP-8 807";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_808: JLTS_clone_comlink
	{
		displayName="CWP-8 808";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_809: JLTS_clone_comlink
	{
		displayName="CWP-8 809";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_810: JLTS_clone_comlink
	{
		displayName="CWP-8 810";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_811: JLTS_clone_comlink
	{
		displayName="CWP-8 811";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_812: JLTS_clone_comlink
	{
		displayName="CWP-8 812";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_813: JLTS_clone_comlink
	{
		displayName="CWP-8 813";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_814: JLTS_clone_comlink
	{
		displayName="CWP-8 814";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_815: JLTS_clone_comlink
	{
		displayName="CWP-8 815";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_816: JLTS_clone_comlink
	{
		displayName="CWP-8 816";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_817: JLTS_clone_comlink
	{
		displayName="CWP-8 817";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_818: JLTS_clone_comlink
	{
		displayName="CWP-8 818";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_819: JLTS_clone_comlink
	{
		displayName="CWP-8 819";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_820: JLTS_clone_comlink
	{
		displayName="CWP-8 820";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_821: JLTS_clone_comlink
	{
		displayName="CWP-8 821";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_822: JLTS_clone_comlink
	{
		displayName="CWP-8 822";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_823: JLTS_clone_comlink
	{
		displayName="CWP-8 823";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_824: JLTS_clone_comlink
	{
		displayName="CWP-8 824";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_825: JLTS_clone_comlink
	{
		displayName="CWP-8 825";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_826: JLTS_clone_comlink
	{
		displayName="CWP-8 826";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_827: JLTS_clone_comlink
	{
		displayName="CWP-8 827";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_828: JLTS_clone_comlink
	{
		displayName="CWP-8 828";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_829: JLTS_clone_comlink
	{
		displayName="CWP-8 829";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_830: JLTS_clone_comlink
	{
		displayName="CWP-8 830";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_831: JLTS_clone_comlink
	{
		displayName="CWP-8 831";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_832: JLTS_clone_comlink
	{
		displayName="CWP-8 832";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_833: JLTS_clone_comlink
	{
		displayName="CWP-8 833";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_834: JLTS_clone_comlink
	{
		displayName="CWP-8 834";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_835: JLTS_clone_comlink
	{
		displayName="CWP-8 835";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_836: JLTS_clone_comlink
	{
		displayName="CWP-8 836";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_837: JLTS_clone_comlink
	{
		displayName="CWP-8 837";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_838: JLTS_clone_comlink
	{
		displayName="CWP-8 838";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_839: JLTS_clone_comlink
	{
		displayName="CWP-8 839";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_840: JLTS_clone_comlink
	{
		displayName="CWP-8 840";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_841: JLTS_clone_comlink
	{
		displayName="CWP-8 841";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_842: JLTS_clone_comlink
	{
		displayName="CWP-8 842";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_843: JLTS_clone_comlink
	{
		displayName="CWP-8 843";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_844: JLTS_clone_comlink
	{
		displayName="CWP-8 844";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_845: JLTS_clone_comlink
	{
		displayName="CWP-8 845";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_846: JLTS_clone_comlink
	{
		displayName="CWP-8 846";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_847: JLTS_clone_comlink
	{
		displayName="CWP-8 847";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_848: JLTS_clone_comlink
	{
		displayName="CWP-8 848";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_849: JLTS_clone_comlink
	{
		displayName="CWP-8 849";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_850: JLTS_clone_comlink
	{
		displayName="CWP-8 850";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_851: JLTS_clone_comlink
	{
		displayName="CWP-8 851";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_852: JLTS_clone_comlink
	{
		displayName="CWP-8 852";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_853: JLTS_clone_comlink
	{
		displayName="CWP-8 853";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_854: JLTS_clone_comlink
	{
		displayName="CWP-8 854";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_855: JLTS_clone_comlink
	{
		displayName="CWP-8 855";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_856: JLTS_clone_comlink
	{
		displayName="CWP-8 856";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_857: JLTS_clone_comlink
	{
		displayName="CWP-8 857";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_858: JLTS_clone_comlink
	{
		displayName="CWP-8 858";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_859: JLTS_clone_comlink
	{
		displayName="CWP-8 859";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_860: JLTS_clone_comlink
	{
		displayName="CWP-8 860";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_861: JLTS_clone_comlink
	{
		displayName="CWP-8 861";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_862: JLTS_clone_comlink
	{
		displayName="CWP-8 862";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_863: JLTS_clone_comlink
	{
		displayName="CWP-8 863";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_864: JLTS_clone_comlink
	{
		displayName="CWP-8 864";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_865: JLTS_clone_comlink
	{
		displayName="CWP-8 865";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_866: JLTS_clone_comlink
	{
		displayName="CWP-8 866";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_867: JLTS_clone_comlink
	{
		displayName="CWP-8 867";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_868: JLTS_clone_comlink
	{
		displayName="CWP-8 868";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_869: JLTS_clone_comlink
	{
		displayName="CWP-8 869";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_870: JLTS_clone_comlink
	{
		displayName="CWP-8 870";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_871: JLTS_clone_comlink
	{
		displayName="CWP-8 871";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_872: JLTS_clone_comlink
	{
		displayName="CWP-8 872";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_873: JLTS_clone_comlink
	{
		displayName="CWP-8 873";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_874: JLTS_clone_comlink
	{
		displayName="CWP-8 874";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_875: JLTS_clone_comlink
	{
		displayName="CWP-8 875";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_876: JLTS_clone_comlink
	{
		displayName="CWP-8 876";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_877: JLTS_clone_comlink
	{
		displayName="CWP-8 877";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_878: JLTS_clone_comlink
	{
		displayName="CWP-8 878";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_879: JLTS_clone_comlink
	{
		displayName="CWP-8 879";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_880: JLTS_clone_comlink
	{
		displayName="CWP-8 880";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_881: JLTS_clone_comlink
	{
		displayName="CWP-8 881";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_882: JLTS_clone_comlink
	{
		displayName="CWP-8 882";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_883: JLTS_clone_comlink
	{
		displayName="CWP-8 883";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_884: JLTS_clone_comlink
	{
		displayName="CWP-8 884";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_885: JLTS_clone_comlink
	{
		displayName="CWP-8 885";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_886: JLTS_clone_comlink
	{
		displayName="CWP-8 886";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_887: JLTS_clone_comlink
	{
		displayName="CWP-8 887";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_888: JLTS_clone_comlink
	{
		displayName="CWP-8 888";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_889: JLTS_clone_comlink
	{
		displayName="CWP-8 889";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_890: JLTS_clone_comlink
	{
		displayName="CWP-8 890";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_891: JLTS_clone_comlink
	{
		displayName="CWP-8 891";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_892: JLTS_clone_comlink
	{
		displayName="CWP-8 892";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_893: JLTS_clone_comlink
	{
		displayName="CWP-8 893";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_894: JLTS_clone_comlink
	{
		displayName="CWP-8 894";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_895: JLTS_clone_comlink
	{
		displayName="CWP-8 895";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_896: JLTS_clone_comlink
	{
		displayName="CWP-8 896";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_897: JLTS_clone_comlink
	{
		displayName="CWP-8 897";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_898: JLTS_clone_comlink
	{
		displayName="CWP-8 898";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_899: JLTS_clone_comlink
	{
		displayName="CWP-8 899";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_900: JLTS_clone_comlink
	{
		displayName="CWP-8 900";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_901: JLTS_clone_comlink
	{
		displayName="CWP-8 901";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_902: JLTS_clone_comlink
	{
		displayName="CWP-8 902";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_903: JLTS_clone_comlink
	{
		displayName="CWP-8 903";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_904: JLTS_clone_comlink
	{
		displayName="CWP-8 904";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_905: JLTS_clone_comlink
	{
		displayName="CWP-8 905";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_906: JLTS_clone_comlink
	{
		displayName="CWP-8 906";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_907: JLTS_clone_comlink
	{
		displayName="CWP-8 907";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_908: JLTS_clone_comlink
	{
		displayName="CWP-8 908";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_909: JLTS_clone_comlink
	{
		displayName="CWP-8 909";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_910: JLTS_clone_comlink
	{
		displayName="CWP-8 910";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_911: JLTS_clone_comlink
	{
		displayName="CWP-8 911";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_912: JLTS_clone_comlink
	{
		displayName="CWP-8 912";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_913: JLTS_clone_comlink
	{
		displayName="CWP-8 913";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_914: JLTS_clone_comlink
	{
		displayName="CWP-8 914";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_915: JLTS_clone_comlink
	{
		displayName="CWP-8 915";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_916: JLTS_clone_comlink
	{
		displayName="CWP-8 916";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_917: JLTS_clone_comlink
	{
		displayName="CWP-8 917";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_918: JLTS_clone_comlink
	{
		displayName="CWP-8 918";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_919: JLTS_clone_comlink
	{
		displayName="CWP-8 919";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_920: JLTS_clone_comlink
	{
		displayName="CWP-8 920";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_921: JLTS_clone_comlink
	{
		displayName="CWP-8 921";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_922: JLTS_clone_comlink
	{
		displayName="CWP-8 922";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_923: JLTS_clone_comlink
	{
		displayName="CWP-8 923";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_924: JLTS_clone_comlink
	{
		displayName="CWP-8 924";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_925: JLTS_clone_comlink
	{
		displayName="CWP-8 925";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_926: JLTS_clone_comlink
	{
		displayName="CWP-8 926";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_927: JLTS_clone_comlink
	{
		displayName="CWP-8 927";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_928: JLTS_clone_comlink
	{
		displayName="CWP-8 928";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_929: JLTS_clone_comlink
	{
		displayName="CWP-8 929";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_930: JLTS_clone_comlink
	{
		displayName="CWP-8 930";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_931: JLTS_clone_comlink
	{
		displayName="CWP-8 931";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_932: JLTS_clone_comlink
	{
		displayName="CWP-8 932";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_933: JLTS_clone_comlink
	{
		displayName="CWP-8 933";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_934: JLTS_clone_comlink
	{
		displayName="CWP-8 934";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_935: JLTS_clone_comlink
	{
		displayName="CWP-8 935";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_936: JLTS_clone_comlink
	{
		displayName="CWP-8 936";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_937: JLTS_clone_comlink
	{
		displayName="CWP-8 937";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_938: JLTS_clone_comlink
	{
		displayName="CWP-8 938";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_939: JLTS_clone_comlink
	{
		displayName="CWP-8 939";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_940: JLTS_clone_comlink
	{
		displayName="CWP-8 940";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_941: JLTS_clone_comlink
	{
		displayName="CWP-8 941";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_942: JLTS_clone_comlink
	{
		displayName="CWP-8 942";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_943: JLTS_clone_comlink
	{
		displayName="CWP-8 943";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_944: JLTS_clone_comlink
	{
		displayName="CWP-8 944";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_945: JLTS_clone_comlink
	{
		displayName="CWP-8 945";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_946: JLTS_clone_comlink
	{
		displayName="CWP-8 946";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_947: JLTS_clone_comlink
	{
		displayName="CWP-8 947";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_948: JLTS_clone_comlink
	{
		displayName="CWP-8 948";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_949: JLTS_clone_comlink
	{
		displayName="CWP-8 949";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_950: JLTS_clone_comlink
	{
		displayName="CWP-8 950";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_951: JLTS_clone_comlink
	{
		displayName="CWP-8 951";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_952: JLTS_clone_comlink
	{
		displayName="CWP-8 952";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_953: JLTS_clone_comlink
	{
		displayName="CWP-8 953";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_954: JLTS_clone_comlink
	{
		displayName="CWP-8 954";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_955: JLTS_clone_comlink
	{
		displayName="CWP-8 955";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_956: JLTS_clone_comlink
	{
		displayName="CWP-8 956";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_957: JLTS_clone_comlink
	{
		displayName="CWP-8 957";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_958: JLTS_clone_comlink
	{
		displayName="CWP-8 958";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_959: JLTS_clone_comlink
	{
		displayName="CWP-8 959";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_960: JLTS_clone_comlink
	{
		displayName="CWP-8 960";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_961: JLTS_clone_comlink
	{
		displayName="CWP-8 961";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_962: JLTS_clone_comlink
	{
		displayName="CWP-8 962";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_963: JLTS_clone_comlink
	{
		displayName="CWP-8 963";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_964: JLTS_clone_comlink
	{
		displayName="CWP-8 964";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_965: JLTS_clone_comlink
	{
		displayName="CWP-8 965";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_966: JLTS_clone_comlink
	{
		displayName="CWP-8 966";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_967: JLTS_clone_comlink
	{
		displayName="CWP-8 967";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_968: JLTS_clone_comlink
	{
		displayName="CWP-8 968";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_969: JLTS_clone_comlink
	{
		displayName="CWP-8 969";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_970: JLTS_clone_comlink
	{
		displayName="CWP-8 970";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_971: JLTS_clone_comlink
	{
		displayName="CWP-8 971";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_972: JLTS_clone_comlink
	{
		displayName="CWP-8 972";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_973: JLTS_clone_comlink
	{
		displayName="CWP-8 973";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_974: JLTS_clone_comlink
	{
		displayName="CWP-8 974";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_975: JLTS_clone_comlink
	{
		displayName="CWP-8 975";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_976: JLTS_clone_comlink
	{
		displayName="CWP-8 976";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_977: JLTS_clone_comlink
	{
		displayName="CWP-8 977";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_978: JLTS_clone_comlink
	{
		displayName="CWP-8 978";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_979: JLTS_clone_comlink
	{
		displayName="CWP-8 979";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_980: JLTS_clone_comlink
	{
		displayName="CWP-8 980";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_981: JLTS_clone_comlink
	{
		displayName="CWP-8 981";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_982: JLTS_clone_comlink
	{
		displayName="CWP-8 982";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_983: JLTS_clone_comlink
	{
		displayName="CWP-8 983";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_984: JLTS_clone_comlink
	{
		displayName="CWP-8 984";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_985: JLTS_clone_comlink
	{
		displayName="CWP-8 985";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_986: JLTS_clone_comlink
	{
		displayName="CWP-8 986";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_987: JLTS_clone_comlink
	{
		displayName="CWP-8 987";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_988: JLTS_clone_comlink
	{
		displayName="CWP-8 988";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_989: JLTS_clone_comlink
	{
		displayName="CWP-8 989";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_990: JLTS_clone_comlink
	{
		displayName="CWP-8 990";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_991: JLTS_clone_comlink
	{
		displayName="CWP-8 991";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_992: JLTS_clone_comlink
	{
		displayName="CWP-8 992";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_993: JLTS_clone_comlink
	{
		displayName="CWP-8 993";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_994: JLTS_clone_comlink
	{
		displayName="CWP-8 994";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_995: JLTS_clone_comlink
	{
		displayName="CWP-8 995";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_996: JLTS_clone_comlink
	{
		displayName="CWP-8 996";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_997: JLTS_clone_comlink
	{
		displayName="CWP-8 997";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_998: JLTS_clone_comlink
	{
		displayName="CWP-8 998";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_999: JLTS_clone_comlink
	{
		displayName="CWP-8 999";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_clone_comlink_1000: JLTS_clone_comlink
	{
		displayName="CWP-8 1000";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_1: JLTS_droid_comlink
	{
		displayName="Battle droid radio 1";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_2: JLTS_droid_comlink
	{
		displayName="Battle droid radio 2";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_3: JLTS_droid_comlink
	{
		displayName="Battle droid radio 3";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_4: JLTS_droid_comlink
	{
		displayName="Battle droid radio 4";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_5: JLTS_droid_comlink
	{
		displayName="Battle droid radio 5";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_6: JLTS_droid_comlink
	{
		displayName="Battle droid radio 6";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_7: JLTS_droid_comlink
	{
		displayName="Battle droid radio 7";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_8: JLTS_droid_comlink
	{
		displayName="Battle droid radio 8";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_9: JLTS_droid_comlink
	{
		displayName="Battle droid radio 9";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_10: JLTS_droid_comlink
	{
		displayName="Battle droid radio 10";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_11: JLTS_droid_comlink
	{
		displayName="Battle droid radio 11";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_12: JLTS_droid_comlink
	{
		displayName="Battle droid radio 12";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_13: JLTS_droid_comlink
	{
		displayName="Battle droid radio 13";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_14: JLTS_droid_comlink
	{
		displayName="Battle droid radio 14";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_15: JLTS_droid_comlink
	{
		displayName="Battle droid radio 15";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_16: JLTS_droid_comlink
	{
		displayName="Battle droid radio 16";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_17: JLTS_droid_comlink
	{
		displayName="Battle droid radio 17";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_18: JLTS_droid_comlink
	{
		displayName="Battle droid radio 18";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_19: JLTS_droid_comlink
	{
		displayName="Battle droid radio 19";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_20: JLTS_droid_comlink
	{
		displayName="Battle droid radio 20";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_21: JLTS_droid_comlink
	{
		displayName="Battle droid radio 21";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_22: JLTS_droid_comlink
	{
		displayName="Battle droid radio 22";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_23: JLTS_droid_comlink
	{
		displayName="Battle droid radio 23";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_24: JLTS_droid_comlink
	{
		displayName="Battle droid radio 24";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_25: JLTS_droid_comlink
	{
		displayName="Battle droid radio 25";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_26: JLTS_droid_comlink
	{
		displayName="Battle droid radio 26";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_27: JLTS_droid_comlink
	{
		displayName="Battle droid radio 27";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_28: JLTS_droid_comlink
	{
		displayName="Battle droid radio 28";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_29: JLTS_droid_comlink
	{
		displayName="Battle droid radio 29";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_30: JLTS_droid_comlink
	{
		displayName="Battle droid radio 30";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_31: JLTS_droid_comlink
	{
		displayName="Battle droid radio 31";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_32: JLTS_droid_comlink
	{
		displayName="Battle droid radio 32";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_33: JLTS_droid_comlink
	{
		displayName="Battle droid radio 33";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_34: JLTS_droid_comlink
	{
		displayName="Battle droid radio 34";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_35: JLTS_droid_comlink
	{
		displayName="Battle droid radio 35";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_36: JLTS_droid_comlink
	{
		displayName="Battle droid radio 36";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_37: JLTS_droid_comlink
	{
		displayName="Battle droid radio 37";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_38: JLTS_droid_comlink
	{
		displayName="Battle droid radio 38";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_39: JLTS_droid_comlink
	{
		displayName="Battle droid radio 39";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_40: JLTS_droid_comlink
	{
		displayName="Battle droid radio 40";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_41: JLTS_droid_comlink
	{
		displayName="Battle droid radio 41";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_42: JLTS_droid_comlink
	{
		displayName="Battle droid radio 42";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_43: JLTS_droid_comlink
	{
		displayName="Battle droid radio 43";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_44: JLTS_droid_comlink
	{
		displayName="Battle droid radio 44";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_45: JLTS_droid_comlink
	{
		displayName="Battle droid radio 45";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_46: JLTS_droid_comlink
	{
		displayName="Battle droid radio 46";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_47: JLTS_droid_comlink
	{
		displayName="Battle droid radio 47";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_48: JLTS_droid_comlink
	{
		displayName="Battle droid radio 48";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_49: JLTS_droid_comlink
	{
		displayName="Battle droid radio 49";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_50: JLTS_droid_comlink
	{
		displayName="Battle droid radio 50";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_51: JLTS_droid_comlink
	{
		displayName="Battle droid radio 51";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_52: JLTS_droid_comlink
	{
		displayName="Battle droid radio 52";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_53: JLTS_droid_comlink
	{
		displayName="Battle droid radio 53";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_54: JLTS_droid_comlink
	{
		displayName="Battle droid radio 54";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_55: JLTS_droid_comlink
	{
		displayName="Battle droid radio 55";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_56: JLTS_droid_comlink
	{
		displayName="Battle droid radio 56";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_57: JLTS_droid_comlink
	{
		displayName="Battle droid radio 57";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_58: JLTS_droid_comlink
	{
		displayName="Battle droid radio 58";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_59: JLTS_droid_comlink
	{
		displayName="Battle droid radio 59";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_60: JLTS_droid_comlink
	{
		displayName="Battle droid radio 60";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_61: JLTS_droid_comlink
	{
		displayName="Battle droid radio 61";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_62: JLTS_droid_comlink
	{
		displayName="Battle droid radio 62";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_63: JLTS_droid_comlink
	{
		displayName="Battle droid radio 63";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_64: JLTS_droid_comlink
	{
		displayName="Battle droid radio 64";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_65: JLTS_droid_comlink
	{
		displayName="Battle droid radio 65";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_66: JLTS_droid_comlink
	{
		displayName="Battle droid radio 66";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_67: JLTS_droid_comlink
	{
		displayName="Battle droid radio 67";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_68: JLTS_droid_comlink
	{
		displayName="Battle droid radio 68";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_69: JLTS_droid_comlink
	{
		displayName="Battle droid radio 69";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_70: JLTS_droid_comlink
	{
		displayName="Battle droid radio 70";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_71: JLTS_droid_comlink
	{
		displayName="Battle droid radio 71";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_72: JLTS_droid_comlink
	{
		displayName="Battle droid radio 72";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_73: JLTS_droid_comlink
	{
		displayName="Battle droid radio 73";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_74: JLTS_droid_comlink
	{
		displayName="Battle droid radio 74";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_75: JLTS_droid_comlink
	{
		displayName="Battle droid radio 75";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_76: JLTS_droid_comlink
	{
		displayName="Battle droid radio 76";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_77: JLTS_droid_comlink
	{
		displayName="Battle droid radio 77";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_78: JLTS_droid_comlink
	{
		displayName="Battle droid radio 78";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_79: JLTS_droid_comlink
	{
		displayName="Battle droid radio 79";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_80: JLTS_droid_comlink
	{
		displayName="Battle droid radio 80";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_81: JLTS_droid_comlink
	{
		displayName="Battle droid radio 81";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_82: JLTS_droid_comlink
	{
		displayName="Battle droid radio 82";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_83: JLTS_droid_comlink
	{
		displayName="Battle droid radio 83";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_84: JLTS_droid_comlink
	{
		displayName="Battle droid radio 84";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_85: JLTS_droid_comlink
	{
		displayName="Battle droid radio 85";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_86: JLTS_droid_comlink
	{
		displayName="Battle droid radio 86";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_87: JLTS_droid_comlink
	{
		displayName="Battle droid radio 87";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_88: JLTS_droid_comlink
	{
		displayName="Battle droid radio 88";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_89: JLTS_droid_comlink
	{
		displayName="Battle droid radio 89";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_90: JLTS_droid_comlink
	{
		displayName="Battle droid radio 90";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_91: JLTS_droid_comlink
	{
		displayName="Battle droid radio 91";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_92: JLTS_droid_comlink
	{
		displayName="Battle droid radio 92";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_93: JLTS_droid_comlink
	{
		displayName="Battle droid radio 93";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_94: JLTS_droid_comlink
	{
		displayName="Battle droid radio 94";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_95: JLTS_droid_comlink
	{
		displayName="Battle droid radio 95";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_96: JLTS_droid_comlink
	{
		displayName="Battle droid radio 96";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_97: JLTS_droid_comlink
	{
		displayName="Battle droid radio 97";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_98: JLTS_droid_comlink
	{
		displayName="Battle droid radio 98";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_99: JLTS_droid_comlink
	{
		displayName="Battle droid radio 99";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_100: JLTS_droid_comlink
	{
		displayName="Battle droid radio 100";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_101: JLTS_droid_comlink
	{
		displayName="Battle droid radio 101";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_102: JLTS_droid_comlink
	{
		displayName="Battle droid radio 102";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_103: JLTS_droid_comlink
	{
		displayName="Battle droid radio 103";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_104: JLTS_droid_comlink
	{
		displayName="Battle droid radio 104";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_105: JLTS_droid_comlink
	{
		displayName="Battle droid radio 105";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_106: JLTS_droid_comlink
	{
		displayName="Battle droid radio 106";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_107: JLTS_droid_comlink
	{
		displayName="Battle droid radio 107";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_108: JLTS_droid_comlink
	{
		displayName="Battle droid radio 108";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_109: JLTS_droid_comlink
	{
		displayName="Battle droid radio 109";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_110: JLTS_droid_comlink
	{
		displayName="Battle droid radio 110";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_111: JLTS_droid_comlink
	{
		displayName="Battle droid radio 111";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_112: JLTS_droid_comlink
	{
		displayName="Battle droid radio 112";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_113: JLTS_droid_comlink
	{
		displayName="Battle droid radio 113";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_114: JLTS_droid_comlink
	{
		displayName="Battle droid radio 114";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_115: JLTS_droid_comlink
	{
		displayName="Battle droid radio 115";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_116: JLTS_droid_comlink
	{
		displayName="Battle droid radio 116";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_117: JLTS_droid_comlink
	{
		displayName="Battle droid radio 117";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_118: JLTS_droid_comlink
	{
		displayName="Battle droid radio 118";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_119: JLTS_droid_comlink
	{
		displayName="Battle droid radio 119";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_120: JLTS_droid_comlink
	{
		displayName="Battle droid radio 120";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_121: JLTS_droid_comlink
	{
		displayName="Battle droid radio 121";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_122: JLTS_droid_comlink
	{
		displayName="Battle droid radio 122";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_123: JLTS_droid_comlink
	{
		displayName="Battle droid radio 123";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_124: JLTS_droid_comlink
	{
		displayName="Battle droid radio 124";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_125: JLTS_droid_comlink
	{
		displayName="Battle droid radio 125";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_126: JLTS_droid_comlink
	{
		displayName="Battle droid radio 126";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_127: JLTS_droid_comlink
	{
		displayName="Battle droid radio 127";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_128: JLTS_droid_comlink
	{
		displayName="Battle droid radio 128";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_129: JLTS_droid_comlink
	{
		displayName="Battle droid radio 129";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_130: JLTS_droid_comlink
	{
		displayName="Battle droid radio 130";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_131: JLTS_droid_comlink
	{
		displayName="Battle droid radio 131";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_132: JLTS_droid_comlink
	{
		displayName="Battle droid radio 132";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_133: JLTS_droid_comlink
	{
		displayName="Battle droid radio 133";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_134: JLTS_droid_comlink
	{
		displayName="Battle droid radio 134";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_135: JLTS_droid_comlink
	{
		displayName="Battle droid radio 135";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_136: JLTS_droid_comlink
	{
		displayName="Battle droid radio 136";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_137: JLTS_droid_comlink
	{
		displayName="Battle droid radio 137";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_138: JLTS_droid_comlink
	{
		displayName="Battle droid radio 138";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_139: JLTS_droid_comlink
	{
		displayName="Battle droid radio 139";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_140: JLTS_droid_comlink
	{
		displayName="Battle droid radio 140";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_141: JLTS_droid_comlink
	{
		displayName="Battle droid radio 141";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_142: JLTS_droid_comlink
	{
		displayName="Battle droid radio 142";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_143: JLTS_droid_comlink
	{
		displayName="Battle droid radio 143";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_144: JLTS_droid_comlink
	{
		displayName="Battle droid radio 144";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_145: JLTS_droid_comlink
	{
		displayName="Battle droid radio 145";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_146: JLTS_droid_comlink
	{
		displayName="Battle droid radio 146";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_147: JLTS_droid_comlink
	{
		displayName="Battle droid radio 147";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_148: JLTS_droid_comlink
	{
		displayName="Battle droid radio 148";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_149: JLTS_droid_comlink
	{
		displayName="Battle droid radio 149";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_150: JLTS_droid_comlink
	{
		displayName="Battle droid radio 150";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_151: JLTS_droid_comlink
	{
		displayName="Battle droid radio 151";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_152: JLTS_droid_comlink
	{
		displayName="Battle droid radio 152";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_153: JLTS_droid_comlink
	{
		displayName="Battle droid radio 153";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_154: JLTS_droid_comlink
	{
		displayName="Battle droid radio 154";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_155: JLTS_droid_comlink
	{
		displayName="Battle droid radio 155";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_156: JLTS_droid_comlink
	{
		displayName="Battle droid radio 156";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_157: JLTS_droid_comlink
	{
		displayName="Battle droid radio 157";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_158: JLTS_droid_comlink
	{
		displayName="Battle droid radio 158";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_159: JLTS_droid_comlink
	{
		displayName="Battle droid radio 159";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_160: JLTS_droid_comlink
	{
		displayName="Battle droid radio 160";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_161: JLTS_droid_comlink
	{
		displayName="Battle droid radio 161";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_162: JLTS_droid_comlink
	{
		displayName="Battle droid radio 162";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_163: JLTS_droid_comlink
	{
		displayName="Battle droid radio 163";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_164: JLTS_droid_comlink
	{
		displayName="Battle droid radio 164";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_165: JLTS_droid_comlink
	{
		displayName="Battle droid radio 165";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_166: JLTS_droid_comlink
	{
		displayName="Battle droid radio 166";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_167: JLTS_droid_comlink
	{
		displayName="Battle droid radio 167";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_168: JLTS_droid_comlink
	{
		displayName="Battle droid radio 168";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_169: JLTS_droid_comlink
	{
		displayName="Battle droid radio 169";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_170: JLTS_droid_comlink
	{
		displayName="Battle droid radio 170";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_171: JLTS_droid_comlink
	{
		displayName="Battle droid radio 171";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_172: JLTS_droid_comlink
	{
		displayName="Battle droid radio 172";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_173: JLTS_droid_comlink
	{
		displayName="Battle droid radio 173";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_174: JLTS_droid_comlink
	{
		displayName="Battle droid radio 174";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_175: JLTS_droid_comlink
	{
		displayName="Battle droid radio 175";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_176: JLTS_droid_comlink
	{
		displayName="Battle droid radio 176";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_177: JLTS_droid_comlink
	{
		displayName="Battle droid radio 177";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_178: JLTS_droid_comlink
	{
		displayName="Battle droid radio 178";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_179: JLTS_droid_comlink
	{
		displayName="Battle droid radio 179";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_180: JLTS_droid_comlink
	{
		displayName="Battle droid radio 180";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_181: JLTS_droid_comlink
	{
		displayName="Battle droid radio 181";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_182: JLTS_droid_comlink
	{
		displayName="Battle droid radio 182";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_183: JLTS_droid_comlink
	{
		displayName="Battle droid radio 183";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_184: JLTS_droid_comlink
	{
		displayName="Battle droid radio 184";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_185: JLTS_droid_comlink
	{
		displayName="Battle droid radio 185";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_186: JLTS_droid_comlink
	{
		displayName="Battle droid radio 186";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_187: JLTS_droid_comlink
	{
		displayName="Battle droid radio 187";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_188: JLTS_droid_comlink
	{
		displayName="Battle droid radio 188";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_189: JLTS_droid_comlink
	{
		displayName="Battle droid radio 189";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_190: JLTS_droid_comlink
	{
		displayName="Battle droid radio 190";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_191: JLTS_droid_comlink
	{
		displayName="Battle droid radio 191";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_192: JLTS_droid_comlink
	{
		displayName="Battle droid radio 192";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_193: JLTS_droid_comlink
	{
		displayName="Battle droid radio 193";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_194: JLTS_droid_comlink
	{
		displayName="Battle droid radio 194";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_195: JLTS_droid_comlink
	{
		displayName="Battle droid radio 195";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_196: JLTS_droid_comlink
	{
		displayName="Battle droid radio 196";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_197: JLTS_droid_comlink
	{
		displayName="Battle droid radio 197";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_198: JLTS_droid_comlink
	{
		displayName="Battle droid radio 198";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_199: JLTS_droid_comlink
	{
		displayName="Battle droid radio 199";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_200: JLTS_droid_comlink
	{
		displayName="Battle droid radio 200";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_201: JLTS_droid_comlink
	{
		displayName="Battle droid radio 201";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_202: JLTS_droid_comlink
	{
		displayName="Battle droid radio 202";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_203: JLTS_droid_comlink
	{
		displayName="Battle droid radio 203";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_204: JLTS_droid_comlink
	{
		displayName="Battle droid radio 204";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_205: JLTS_droid_comlink
	{
		displayName="Battle droid radio 205";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_206: JLTS_droid_comlink
	{
		displayName="Battle droid radio 206";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_207: JLTS_droid_comlink
	{
		displayName="Battle droid radio 207";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_208: JLTS_droid_comlink
	{
		displayName="Battle droid radio 208";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_209: JLTS_droid_comlink
	{
		displayName="Battle droid radio 209";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_210: JLTS_droid_comlink
	{
		displayName="Battle droid radio 210";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_211: JLTS_droid_comlink
	{
		displayName="Battle droid radio 211";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_212: JLTS_droid_comlink
	{
		displayName="Battle droid radio 212";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_213: JLTS_droid_comlink
	{
		displayName="Battle droid radio 213";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_214: JLTS_droid_comlink
	{
		displayName="Battle droid radio 214";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_215: JLTS_droid_comlink
	{
		displayName="Battle droid radio 215";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_216: JLTS_droid_comlink
	{
		displayName="Battle droid radio 216";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_217: JLTS_droid_comlink
	{
		displayName="Battle droid radio 217";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_218: JLTS_droid_comlink
	{
		displayName="Battle droid radio 218";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_219: JLTS_droid_comlink
	{
		displayName="Battle droid radio 219";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_220: JLTS_droid_comlink
	{
		displayName="Battle droid radio 220";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_221: JLTS_droid_comlink
	{
		displayName="Battle droid radio 221";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_222: JLTS_droid_comlink
	{
		displayName="Battle droid radio 222";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_223: JLTS_droid_comlink
	{
		displayName="Battle droid radio 223";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_224: JLTS_droid_comlink
	{
		displayName="Battle droid radio 224";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_225: JLTS_droid_comlink
	{
		displayName="Battle droid radio 225";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_226: JLTS_droid_comlink
	{
		displayName="Battle droid radio 226";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_227: JLTS_droid_comlink
	{
		displayName="Battle droid radio 227";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_228: JLTS_droid_comlink
	{
		displayName="Battle droid radio 228";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_229: JLTS_droid_comlink
	{
		displayName="Battle droid radio 229";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_230: JLTS_droid_comlink
	{
		displayName="Battle droid radio 230";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_231: JLTS_droid_comlink
	{
		displayName="Battle droid radio 231";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_232: JLTS_droid_comlink
	{
		displayName="Battle droid radio 232";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_233: JLTS_droid_comlink
	{
		displayName="Battle droid radio 233";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_234: JLTS_droid_comlink
	{
		displayName="Battle droid radio 234";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_235: JLTS_droid_comlink
	{
		displayName="Battle droid radio 235";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_236: JLTS_droid_comlink
	{
		displayName="Battle droid radio 236";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_237: JLTS_droid_comlink
	{
		displayName="Battle droid radio 237";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_238: JLTS_droid_comlink
	{
		displayName="Battle droid radio 238";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_239: JLTS_droid_comlink
	{
		displayName="Battle droid radio 239";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_240: JLTS_droid_comlink
	{
		displayName="Battle droid radio 240";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_241: JLTS_droid_comlink
	{
		displayName="Battle droid radio 241";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_242: JLTS_droid_comlink
	{
		displayName="Battle droid radio 242";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_243: JLTS_droid_comlink
	{
		displayName="Battle droid radio 243";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_244: JLTS_droid_comlink
	{
		displayName="Battle droid radio 244";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_245: JLTS_droid_comlink
	{
		displayName="Battle droid radio 245";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_246: JLTS_droid_comlink
	{
		displayName="Battle droid radio 246";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_247: JLTS_droid_comlink
	{
		displayName="Battle droid radio 247";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_248: JLTS_droid_comlink
	{
		displayName="Battle droid radio 248";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_249: JLTS_droid_comlink
	{
		displayName="Battle droid radio 249";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_250: JLTS_droid_comlink
	{
		displayName="Battle droid radio 250";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_251: JLTS_droid_comlink
	{
		displayName="Battle droid radio 251";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_252: JLTS_droid_comlink
	{
		displayName="Battle droid radio 252";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_253: JLTS_droid_comlink
	{
		displayName="Battle droid radio 253";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_254: JLTS_droid_comlink
	{
		displayName="Battle droid radio 254";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_255: JLTS_droid_comlink
	{
		displayName="Battle droid radio 255";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_256: JLTS_droid_comlink
	{
		displayName="Battle droid radio 256";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_257: JLTS_droid_comlink
	{
		displayName="Battle droid radio 257";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_258: JLTS_droid_comlink
	{
		displayName="Battle droid radio 258";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_259: JLTS_droid_comlink
	{
		displayName="Battle droid radio 259";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_260: JLTS_droid_comlink
	{
		displayName="Battle droid radio 260";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_261: JLTS_droid_comlink
	{
		displayName="Battle droid radio 261";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_262: JLTS_droid_comlink
	{
		displayName="Battle droid radio 262";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_263: JLTS_droid_comlink
	{
		displayName="Battle droid radio 263";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_264: JLTS_droid_comlink
	{
		displayName="Battle droid radio 264";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_265: JLTS_droid_comlink
	{
		displayName="Battle droid radio 265";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_266: JLTS_droid_comlink
	{
		displayName="Battle droid radio 266";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_267: JLTS_droid_comlink
	{
		displayName="Battle droid radio 267";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_268: JLTS_droid_comlink
	{
		displayName="Battle droid radio 268";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_269: JLTS_droid_comlink
	{
		displayName="Battle droid radio 269";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_270: JLTS_droid_comlink
	{
		displayName="Battle droid radio 270";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_271: JLTS_droid_comlink
	{
		displayName="Battle droid radio 271";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_272: JLTS_droid_comlink
	{
		displayName="Battle droid radio 272";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_273: JLTS_droid_comlink
	{
		displayName="Battle droid radio 273";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_274: JLTS_droid_comlink
	{
		displayName="Battle droid radio 274";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_275: JLTS_droid_comlink
	{
		displayName="Battle droid radio 275";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_276: JLTS_droid_comlink
	{
		displayName="Battle droid radio 276";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_277: JLTS_droid_comlink
	{
		displayName="Battle droid radio 277";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_278: JLTS_droid_comlink
	{
		displayName="Battle droid radio 278";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_279: JLTS_droid_comlink
	{
		displayName="Battle droid radio 279";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_280: JLTS_droid_comlink
	{
		displayName="Battle droid radio 280";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_281: JLTS_droid_comlink
	{
		displayName="Battle droid radio 281";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_282: JLTS_droid_comlink
	{
		displayName="Battle droid radio 282";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_283: JLTS_droid_comlink
	{
		displayName="Battle droid radio 283";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_284: JLTS_droid_comlink
	{
		displayName="Battle droid radio 284";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_285: JLTS_droid_comlink
	{
		displayName="Battle droid radio 285";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_286: JLTS_droid_comlink
	{
		displayName="Battle droid radio 286";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_287: JLTS_droid_comlink
	{
		displayName="Battle droid radio 287";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_288: JLTS_droid_comlink
	{
		displayName="Battle droid radio 288";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_289: JLTS_droid_comlink
	{
		displayName="Battle droid radio 289";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_290: JLTS_droid_comlink
	{
		displayName="Battle droid radio 290";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_291: JLTS_droid_comlink
	{
		displayName="Battle droid radio 291";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_292: JLTS_droid_comlink
	{
		displayName="Battle droid radio 292";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_293: JLTS_droid_comlink
	{
		displayName="Battle droid radio 293";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_294: JLTS_droid_comlink
	{
		displayName="Battle droid radio 294";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_295: JLTS_droid_comlink
	{
		displayName="Battle droid radio 295";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_296: JLTS_droid_comlink
	{
		displayName="Battle droid radio 296";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_297: JLTS_droid_comlink
	{
		displayName="Battle droid radio 297";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_298: JLTS_droid_comlink
	{
		displayName="Battle droid radio 298";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_299: JLTS_droid_comlink
	{
		displayName="Battle droid radio 299";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_300: JLTS_droid_comlink
	{
		displayName="Battle droid radio 300";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_301: JLTS_droid_comlink
	{
		displayName="Battle droid radio 301";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_302: JLTS_droid_comlink
	{
		displayName="Battle droid radio 302";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_303: JLTS_droid_comlink
	{
		displayName="Battle droid radio 303";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_304: JLTS_droid_comlink
	{
		displayName="Battle droid radio 304";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_305: JLTS_droid_comlink
	{
		displayName="Battle droid radio 305";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_306: JLTS_droid_comlink
	{
		displayName="Battle droid radio 306";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_307: JLTS_droid_comlink
	{
		displayName="Battle droid radio 307";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_308: JLTS_droid_comlink
	{
		displayName="Battle droid radio 308";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_309: JLTS_droid_comlink
	{
		displayName="Battle droid radio 309";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_310: JLTS_droid_comlink
	{
		displayName="Battle droid radio 310";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_311: JLTS_droid_comlink
	{
		displayName="Battle droid radio 311";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_312: JLTS_droid_comlink
	{
		displayName="Battle droid radio 312";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_313: JLTS_droid_comlink
	{
		displayName="Battle droid radio 313";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_314: JLTS_droid_comlink
	{
		displayName="Battle droid radio 314";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_315: JLTS_droid_comlink
	{
		displayName="Battle droid radio 315";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_316: JLTS_droid_comlink
	{
		displayName="Battle droid radio 316";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_317: JLTS_droid_comlink
	{
		displayName="Battle droid radio 317";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_318: JLTS_droid_comlink
	{
		displayName="Battle droid radio 318";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_319: JLTS_droid_comlink
	{
		displayName="Battle droid radio 319";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_320: JLTS_droid_comlink
	{
		displayName="Battle droid radio 320";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_321: JLTS_droid_comlink
	{
		displayName="Battle droid radio 321";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_322: JLTS_droid_comlink
	{
		displayName="Battle droid radio 322";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_323: JLTS_droid_comlink
	{
		displayName="Battle droid radio 323";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_324: JLTS_droid_comlink
	{
		displayName="Battle droid radio 324";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_325: JLTS_droid_comlink
	{
		displayName="Battle droid radio 325";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_326: JLTS_droid_comlink
	{
		displayName="Battle droid radio 326";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_327: JLTS_droid_comlink
	{
		displayName="Battle droid radio 327";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_328: JLTS_droid_comlink
	{
		displayName="Battle droid radio 328";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_329: JLTS_droid_comlink
	{
		displayName="Battle droid radio 329";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_330: JLTS_droid_comlink
	{
		displayName="Battle droid radio 330";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_331: JLTS_droid_comlink
	{
		displayName="Battle droid radio 331";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_332: JLTS_droid_comlink
	{
		displayName="Battle droid radio 332";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_333: JLTS_droid_comlink
	{
		displayName="Battle droid radio 333";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_334: JLTS_droid_comlink
	{
		displayName="Battle droid radio 334";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_335: JLTS_droid_comlink
	{
		displayName="Battle droid radio 335";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_336: JLTS_droid_comlink
	{
		displayName="Battle droid radio 336";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_337: JLTS_droid_comlink
	{
		displayName="Battle droid radio 337";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_338: JLTS_droid_comlink
	{
		displayName="Battle droid radio 338";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_339: JLTS_droid_comlink
	{
		displayName="Battle droid radio 339";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_340: JLTS_droid_comlink
	{
		displayName="Battle droid radio 340";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_341: JLTS_droid_comlink
	{
		displayName="Battle droid radio 341";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_342: JLTS_droid_comlink
	{
		displayName="Battle droid radio 342";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_343: JLTS_droid_comlink
	{
		displayName="Battle droid radio 343";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_344: JLTS_droid_comlink
	{
		displayName="Battle droid radio 344";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_345: JLTS_droid_comlink
	{
		displayName="Battle droid radio 345";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_346: JLTS_droid_comlink
	{
		displayName="Battle droid radio 346";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_347: JLTS_droid_comlink
	{
		displayName="Battle droid radio 347";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_348: JLTS_droid_comlink
	{
		displayName="Battle droid radio 348";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_349: JLTS_droid_comlink
	{
		displayName="Battle droid radio 349";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_350: JLTS_droid_comlink
	{
		displayName="Battle droid radio 350";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_351: JLTS_droid_comlink
	{
		displayName="Battle droid radio 351";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_352: JLTS_droid_comlink
	{
		displayName="Battle droid radio 352";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_353: JLTS_droid_comlink
	{
		displayName="Battle droid radio 353";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_354: JLTS_droid_comlink
	{
		displayName="Battle droid radio 354";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_355: JLTS_droid_comlink
	{
		displayName="Battle droid radio 355";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_356: JLTS_droid_comlink
	{
		displayName="Battle droid radio 356";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_357: JLTS_droid_comlink
	{
		displayName="Battle droid radio 357";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_358: JLTS_droid_comlink
	{
		displayName="Battle droid radio 358";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_359: JLTS_droid_comlink
	{
		displayName="Battle droid radio 359";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_360: JLTS_droid_comlink
	{
		displayName="Battle droid radio 360";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_361: JLTS_droid_comlink
	{
		displayName="Battle droid radio 361";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_362: JLTS_droid_comlink
	{
		displayName="Battle droid radio 362";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_363: JLTS_droid_comlink
	{
		displayName="Battle droid radio 363";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_364: JLTS_droid_comlink
	{
		displayName="Battle droid radio 364";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_365: JLTS_droid_comlink
	{
		displayName="Battle droid radio 365";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_366: JLTS_droid_comlink
	{
		displayName="Battle droid radio 366";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_367: JLTS_droid_comlink
	{
		displayName="Battle droid radio 367";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_368: JLTS_droid_comlink
	{
		displayName="Battle droid radio 368";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_369: JLTS_droid_comlink
	{
		displayName="Battle droid radio 369";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_370: JLTS_droid_comlink
	{
		displayName="Battle droid radio 370";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_371: JLTS_droid_comlink
	{
		displayName="Battle droid radio 371";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_372: JLTS_droid_comlink
	{
		displayName="Battle droid radio 372";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_373: JLTS_droid_comlink
	{
		displayName="Battle droid radio 373";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_374: JLTS_droid_comlink
	{
		displayName="Battle droid radio 374";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_375: JLTS_droid_comlink
	{
		displayName="Battle droid radio 375";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_376: JLTS_droid_comlink
	{
		displayName="Battle droid radio 376";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_377: JLTS_droid_comlink
	{
		displayName="Battle droid radio 377";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_378: JLTS_droid_comlink
	{
		displayName="Battle droid radio 378";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_379: JLTS_droid_comlink
	{
		displayName="Battle droid radio 379";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_380: JLTS_droid_comlink
	{
		displayName="Battle droid radio 380";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_381: JLTS_droid_comlink
	{
		displayName="Battle droid radio 381";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_382: JLTS_droid_comlink
	{
		displayName="Battle droid radio 382";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_383: JLTS_droid_comlink
	{
		displayName="Battle droid radio 383";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_384: JLTS_droid_comlink
	{
		displayName="Battle droid radio 384";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_385: JLTS_droid_comlink
	{
		displayName="Battle droid radio 385";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_386: JLTS_droid_comlink
	{
		displayName="Battle droid radio 386";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_387: JLTS_droid_comlink
	{
		displayName="Battle droid radio 387";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_388: JLTS_droid_comlink
	{
		displayName="Battle droid radio 388";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_389: JLTS_droid_comlink
	{
		displayName="Battle droid radio 389";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_390: JLTS_droid_comlink
	{
		displayName="Battle droid radio 390";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_391: JLTS_droid_comlink
	{
		displayName="Battle droid radio 391";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_392: JLTS_droid_comlink
	{
		displayName="Battle droid radio 392";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_393: JLTS_droid_comlink
	{
		displayName="Battle droid radio 393";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_394: JLTS_droid_comlink
	{
		displayName="Battle droid radio 394";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_395: JLTS_droid_comlink
	{
		displayName="Battle droid radio 395";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_396: JLTS_droid_comlink
	{
		displayName="Battle droid radio 396";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_397: JLTS_droid_comlink
	{
		displayName="Battle droid radio 397";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_398: JLTS_droid_comlink
	{
		displayName="Battle droid radio 398";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_399: JLTS_droid_comlink
	{
		displayName="Battle droid radio 399";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_400: JLTS_droid_comlink
	{
		displayName="Battle droid radio 400";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_401: JLTS_droid_comlink
	{
		displayName="Battle droid radio 401";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_402: JLTS_droid_comlink
	{
		displayName="Battle droid radio 402";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_403: JLTS_droid_comlink
	{
		displayName="Battle droid radio 403";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_404: JLTS_droid_comlink
	{
		displayName="Battle droid radio 404";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_405: JLTS_droid_comlink
	{
		displayName="Battle droid radio 405";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_406: JLTS_droid_comlink
	{
		displayName="Battle droid radio 406";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_407: JLTS_droid_comlink
	{
		displayName="Battle droid radio 407";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_408: JLTS_droid_comlink
	{
		displayName="Battle droid radio 408";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_409: JLTS_droid_comlink
	{
		displayName="Battle droid radio 409";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_410: JLTS_droid_comlink
	{
		displayName="Battle droid radio 410";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_411: JLTS_droid_comlink
	{
		displayName="Battle droid radio 411";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_412: JLTS_droid_comlink
	{
		displayName="Battle droid radio 412";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_413: JLTS_droid_comlink
	{
		displayName="Battle droid radio 413";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_414: JLTS_droid_comlink
	{
		displayName="Battle droid radio 414";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_415: JLTS_droid_comlink
	{
		displayName="Battle droid radio 415";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_416: JLTS_droid_comlink
	{
		displayName="Battle droid radio 416";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_417: JLTS_droid_comlink
	{
		displayName="Battle droid radio 417";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_418: JLTS_droid_comlink
	{
		displayName="Battle droid radio 418";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_419: JLTS_droid_comlink
	{
		displayName="Battle droid radio 419";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_420: JLTS_droid_comlink
	{
		displayName="Battle droid radio 420";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_421: JLTS_droid_comlink
	{
		displayName="Battle droid radio 421";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_422: JLTS_droid_comlink
	{
		displayName="Battle droid radio 422";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_423: JLTS_droid_comlink
	{
		displayName="Battle droid radio 423";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_424: JLTS_droid_comlink
	{
		displayName="Battle droid radio 424";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_425: JLTS_droid_comlink
	{
		displayName="Battle droid radio 425";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_426: JLTS_droid_comlink
	{
		displayName="Battle droid radio 426";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_427: JLTS_droid_comlink
	{
		displayName="Battle droid radio 427";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_428: JLTS_droid_comlink
	{
		displayName="Battle droid radio 428";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_429: JLTS_droid_comlink
	{
		displayName="Battle droid radio 429";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_430: JLTS_droid_comlink
	{
		displayName="Battle droid radio 430";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_431: JLTS_droid_comlink
	{
		displayName="Battle droid radio 431";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_432: JLTS_droid_comlink
	{
		displayName="Battle droid radio 432";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_433: JLTS_droid_comlink
	{
		displayName="Battle droid radio 433";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_434: JLTS_droid_comlink
	{
		displayName="Battle droid radio 434";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_435: JLTS_droid_comlink
	{
		displayName="Battle droid radio 435";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_436: JLTS_droid_comlink
	{
		displayName="Battle droid radio 436";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_437: JLTS_droid_comlink
	{
		displayName="Battle droid radio 437";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_438: JLTS_droid_comlink
	{
		displayName="Battle droid radio 438";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_439: JLTS_droid_comlink
	{
		displayName="Battle droid radio 439";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_440: JLTS_droid_comlink
	{
		displayName="Battle droid radio 440";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_441: JLTS_droid_comlink
	{
		displayName="Battle droid radio 441";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_442: JLTS_droid_comlink
	{
		displayName="Battle droid radio 442";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_443: JLTS_droid_comlink
	{
		displayName="Battle droid radio 443";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_444: JLTS_droid_comlink
	{
		displayName="Battle droid radio 444";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_445: JLTS_droid_comlink
	{
		displayName="Battle droid radio 445";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_446: JLTS_droid_comlink
	{
		displayName="Battle droid radio 446";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_447: JLTS_droid_comlink
	{
		displayName="Battle droid radio 447";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_448: JLTS_droid_comlink
	{
		displayName="Battle droid radio 448";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_449: JLTS_droid_comlink
	{
		displayName="Battle droid radio 449";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_450: JLTS_droid_comlink
	{
		displayName="Battle droid radio 450";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_451: JLTS_droid_comlink
	{
		displayName="Battle droid radio 451";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_452: JLTS_droid_comlink
	{
		displayName="Battle droid radio 452";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_453: JLTS_droid_comlink
	{
		displayName="Battle droid radio 453";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_454: JLTS_droid_comlink
	{
		displayName="Battle droid radio 454";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_455: JLTS_droid_comlink
	{
		displayName="Battle droid radio 455";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_456: JLTS_droid_comlink
	{
		displayName="Battle droid radio 456";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_457: JLTS_droid_comlink
	{
		displayName="Battle droid radio 457";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_458: JLTS_droid_comlink
	{
		displayName="Battle droid radio 458";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_459: JLTS_droid_comlink
	{
		displayName="Battle droid radio 459";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_460: JLTS_droid_comlink
	{
		displayName="Battle droid radio 460";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_461: JLTS_droid_comlink
	{
		displayName="Battle droid radio 461";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_462: JLTS_droid_comlink
	{
		displayName="Battle droid radio 462";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_463: JLTS_droid_comlink
	{
		displayName="Battle droid radio 463";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_464: JLTS_droid_comlink
	{
		displayName="Battle droid radio 464";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_465: JLTS_droid_comlink
	{
		displayName="Battle droid radio 465";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_466: JLTS_droid_comlink
	{
		displayName="Battle droid radio 466";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_467: JLTS_droid_comlink
	{
		displayName="Battle droid radio 467";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_468: JLTS_droid_comlink
	{
		displayName="Battle droid radio 468";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_469: JLTS_droid_comlink
	{
		displayName="Battle droid radio 469";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_470: JLTS_droid_comlink
	{
		displayName="Battle droid radio 470";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_471: JLTS_droid_comlink
	{
		displayName="Battle droid radio 471";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_472: JLTS_droid_comlink
	{
		displayName="Battle droid radio 472";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_473: JLTS_droid_comlink
	{
		displayName="Battle droid radio 473";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_474: JLTS_droid_comlink
	{
		displayName="Battle droid radio 474";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_475: JLTS_droid_comlink
	{
		displayName="Battle droid radio 475";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_476: JLTS_droid_comlink
	{
		displayName="Battle droid radio 476";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_477: JLTS_droid_comlink
	{
		displayName="Battle droid radio 477";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_478: JLTS_droid_comlink
	{
		displayName="Battle droid radio 478";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_479: JLTS_droid_comlink
	{
		displayName="Battle droid radio 479";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_480: JLTS_droid_comlink
	{
		displayName="Battle droid radio 480";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_481: JLTS_droid_comlink
	{
		displayName="Battle droid radio 481";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_482: JLTS_droid_comlink
	{
		displayName="Battle droid radio 482";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_483: JLTS_droid_comlink
	{
		displayName="Battle droid radio 483";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_484: JLTS_droid_comlink
	{
		displayName="Battle droid radio 484";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_485: JLTS_droid_comlink
	{
		displayName="Battle droid radio 485";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_486: JLTS_droid_comlink
	{
		displayName="Battle droid radio 486";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_487: JLTS_droid_comlink
	{
		displayName="Battle droid radio 487";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_488: JLTS_droid_comlink
	{
		displayName="Battle droid radio 488";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_489: JLTS_droid_comlink
	{
		displayName="Battle droid radio 489";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_490: JLTS_droid_comlink
	{
		displayName="Battle droid radio 490";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_491: JLTS_droid_comlink
	{
		displayName="Battle droid radio 491";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_492: JLTS_droid_comlink
	{
		displayName="Battle droid radio 492";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_493: JLTS_droid_comlink
	{
		displayName="Battle droid radio 493";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_494: JLTS_droid_comlink
	{
		displayName="Battle droid radio 494";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_495: JLTS_droid_comlink
	{
		displayName="Battle droid radio 495";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_496: JLTS_droid_comlink
	{
		displayName="Battle droid radio 496";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_497: JLTS_droid_comlink
	{
		displayName="Battle droid radio 497";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_498: JLTS_droid_comlink
	{
		displayName="Battle droid radio 498";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_499: JLTS_droid_comlink
	{
		displayName="Battle droid radio 499";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_500: JLTS_droid_comlink
	{
		displayName="Battle droid radio 500";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_501: JLTS_droid_comlink
	{
		displayName="Battle droid radio 501";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_502: JLTS_droid_comlink
	{
		displayName="Battle droid radio 502";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_503: JLTS_droid_comlink
	{
		displayName="Battle droid radio 503";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_504: JLTS_droid_comlink
	{
		displayName="Battle droid radio 504";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_505: JLTS_droid_comlink
	{
		displayName="Battle droid radio 505";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_506: JLTS_droid_comlink
	{
		displayName="Battle droid radio 506";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_507: JLTS_droid_comlink
	{
		displayName="Battle droid radio 507";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_508: JLTS_droid_comlink
	{
		displayName="Battle droid radio 508";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_509: JLTS_droid_comlink
	{
		displayName="Battle droid radio 509";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_510: JLTS_droid_comlink
	{
		displayName="Battle droid radio 510";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_511: JLTS_droid_comlink
	{
		displayName="Battle droid radio 511";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_512: JLTS_droid_comlink
	{
		displayName="Battle droid radio 512";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_513: JLTS_droid_comlink
	{
		displayName="Battle droid radio 513";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_514: JLTS_droid_comlink
	{
		displayName="Battle droid radio 514";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_515: JLTS_droid_comlink
	{
		displayName="Battle droid radio 515";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_516: JLTS_droid_comlink
	{
		displayName="Battle droid radio 516";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_517: JLTS_droid_comlink
	{
		displayName="Battle droid radio 517";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_518: JLTS_droid_comlink
	{
		displayName="Battle droid radio 518";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_519: JLTS_droid_comlink
	{
		displayName="Battle droid radio 519";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_520: JLTS_droid_comlink
	{
		displayName="Battle droid radio 520";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_521: JLTS_droid_comlink
	{
		displayName="Battle droid radio 521";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_522: JLTS_droid_comlink
	{
		displayName="Battle droid radio 522";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_523: JLTS_droid_comlink
	{
		displayName="Battle droid radio 523";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_524: JLTS_droid_comlink
	{
		displayName="Battle droid radio 524";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_525: JLTS_droid_comlink
	{
		displayName="Battle droid radio 525";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_526: JLTS_droid_comlink
	{
		displayName="Battle droid radio 526";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_527: JLTS_droid_comlink
	{
		displayName="Battle droid radio 527";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_528: JLTS_droid_comlink
	{
		displayName="Battle droid radio 528";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_529: JLTS_droid_comlink
	{
		displayName="Battle droid radio 529";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_530: JLTS_droid_comlink
	{
		displayName="Battle droid radio 530";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_531: JLTS_droid_comlink
	{
		displayName="Battle droid radio 531";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_532: JLTS_droid_comlink
	{
		displayName="Battle droid radio 532";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_533: JLTS_droid_comlink
	{
		displayName="Battle droid radio 533";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_534: JLTS_droid_comlink
	{
		displayName="Battle droid radio 534";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_535: JLTS_droid_comlink
	{
		displayName="Battle droid radio 535";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_536: JLTS_droid_comlink
	{
		displayName="Battle droid radio 536";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_537: JLTS_droid_comlink
	{
		displayName="Battle droid radio 537";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_538: JLTS_droid_comlink
	{
		displayName="Battle droid radio 538";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_539: JLTS_droid_comlink
	{
		displayName="Battle droid radio 539";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_540: JLTS_droid_comlink
	{
		displayName="Battle droid radio 540";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_541: JLTS_droid_comlink
	{
		displayName="Battle droid radio 541";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_542: JLTS_droid_comlink
	{
		displayName="Battle droid radio 542";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_543: JLTS_droid_comlink
	{
		displayName="Battle droid radio 543";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_544: JLTS_droid_comlink
	{
		displayName="Battle droid radio 544";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_545: JLTS_droid_comlink
	{
		displayName="Battle droid radio 545";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_546: JLTS_droid_comlink
	{
		displayName="Battle droid radio 546";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_547: JLTS_droid_comlink
	{
		displayName="Battle droid radio 547";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_548: JLTS_droid_comlink
	{
		displayName="Battle droid radio 548";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_549: JLTS_droid_comlink
	{
		displayName="Battle droid radio 549";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_550: JLTS_droid_comlink
	{
		displayName="Battle droid radio 550";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_551: JLTS_droid_comlink
	{
		displayName="Battle droid radio 551";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_552: JLTS_droid_comlink
	{
		displayName="Battle droid radio 552";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_553: JLTS_droid_comlink
	{
		displayName="Battle droid radio 553";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_554: JLTS_droid_comlink
	{
		displayName="Battle droid radio 554";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_555: JLTS_droid_comlink
	{
		displayName="Battle droid radio 555";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_556: JLTS_droid_comlink
	{
		displayName="Battle droid radio 556";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_557: JLTS_droid_comlink
	{
		displayName="Battle droid radio 557";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_558: JLTS_droid_comlink
	{
		displayName="Battle droid radio 558";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_559: JLTS_droid_comlink
	{
		displayName="Battle droid radio 559";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_560: JLTS_droid_comlink
	{
		displayName="Battle droid radio 560";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_561: JLTS_droid_comlink
	{
		displayName="Battle droid radio 561";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_562: JLTS_droid_comlink
	{
		displayName="Battle droid radio 562";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_563: JLTS_droid_comlink
	{
		displayName="Battle droid radio 563";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_564: JLTS_droid_comlink
	{
		displayName="Battle droid radio 564";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_565: JLTS_droid_comlink
	{
		displayName="Battle droid radio 565";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_566: JLTS_droid_comlink
	{
		displayName="Battle droid radio 566";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_567: JLTS_droid_comlink
	{
		displayName="Battle droid radio 567";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_568: JLTS_droid_comlink
	{
		displayName="Battle droid radio 568";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_569: JLTS_droid_comlink
	{
		displayName="Battle droid radio 569";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_570: JLTS_droid_comlink
	{
		displayName="Battle droid radio 570";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_571: JLTS_droid_comlink
	{
		displayName="Battle droid radio 571";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_572: JLTS_droid_comlink
	{
		displayName="Battle droid radio 572";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_573: JLTS_droid_comlink
	{
		displayName="Battle droid radio 573";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_574: JLTS_droid_comlink
	{
		displayName="Battle droid radio 574";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_575: JLTS_droid_comlink
	{
		displayName="Battle droid radio 575";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_576: JLTS_droid_comlink
	{
		displayName="Battle droid radio 576";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_577: JLTS_droid_comlink
	{
		displayName="Battle droid radio 577";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_578: JLTS_droid_comlink
	{
		displayName="Battle droid radio 578";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_579: JLTS_droid_comlink
	{
		displayName="Battle droid radio 579";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_580: JLTS_droid_comlink
	{
		displayName="Battle droid radio 580";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_581: JLTS_droid_comlink
	{
		displayName="Battle droid radio 581";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_582: JLTS_droid_comlink
	{
		displayName="Battle droid radio 582";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_583: JLTS_droid_comlink
	{
		displayName="Battle droid radio 583";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_584: JLTS_droid_comlink
	{
		displayName="Battle droid radio 584";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_585: JLTS_droid_comlink
	{
		displayName="Battle droid radio 585";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_586: JLTS_droid_comlink
	{
		displayName="Battle droid radio 586";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_587: JLTS_droid_comlink
	{
		displayName="Battle droid radio 587";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_588: JLTS_droid_comlink
	{
		displayName="Battle droid radio 588";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_589: JLTS_droid_comlink
	{
		displayName="Battle droid radio 589";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_590: JLTS_droid_comlink
	{
		displayName="Battle droid radio 590";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_591: JLTS_droid_comlink
	{
		displayName="Battle droid radio 591";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_592: JLTS_droid_comlink
	{
		displayName="Battle droid radio 592";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_593: JLTS_droid_comlink
	{
		displayName="Battle droid radio 593";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_594: JLTS_droid_comlink
	{
		displayName="Battle droid radio 594";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_595: JLTS_droid_comlink
	{
		displayName="Battle droid radio 595";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_596: JLTS_droid_comlink
	{
		displayName="Battle droid radio 596";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_597: JLTS_droid_comlink
	{
		displayName="Battle droid radio 597";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_598: JLTS_droid_comlink
	{
		displayName="Battle droid radio 598";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_599: JLTS_droid_comlink
	{
		displayName="Battle droid radio 599";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_600: JLTS_droid_comlink
	{
		displayName="Battle droid radio 600";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_601: JLTS_droid_comlink
	{
		displayName="Battle droid radio 601";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_602: JLTS_droid_comlink
	{
		displayName="Battle droid radio 602";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_603: JLTS_droid_comlink
	{
		displayName="Battle droid radio 603";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_604: JLTS_droid_comlink
	{
		displayName="Battle droid radio 604";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_605: JLTS_droid_comlink
	{
		displayName="Battle droid radio 605";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_606: JLTS_droid_comlink
	{
		displayName="Battle droid radio 606";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_607: JLTS_droid_comlink
	{
		displayName="Battle droid radio 607";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_608: JLTS_droid_comlink
	{
		displayName="Battle droid radio 608";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_609: JLTS_droid_comlink
	{
		displayName="Battle droid radio 609";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_610: JLTS_droid_comlink
	{
		displayName="Battle droid radio 610";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_611: JLTS_droid_comlink
	{
		displayName="Battle droid radio 611";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_612: JLTS_droid_comlink
	{
		displayName="Battle droid radio 612";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_613: JLTS_droid_comlink
	{
		displayName="Battle droid radio 613";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_614: JLTS_droid_comlink
	{
		displayName="Battle droid radio 614";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_615: JLTS_droid_comlink
	{
		displayName="Battle droid radio 615";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_616: JLTS_droid_comlink
	{
		displayName="Battle droid radio 616";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_617: JLTS_droid_comlink
	{
		displayName="Battle droid radio 617";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_618: JLTS_droid_comlink
	{
		displayName="Battle droid radio 618";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_619: JLTS_droid_comlink
	{
		displayName="Battle droid radio 619";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_620: JLTS_droid_comlink
	{
		displayName="Battle droid radio 620";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_621: JLTS_droid_comlink
	{
		displayName="Battle droid radio 621";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_622: JLTS_droid_comlink
	{
		displayName="Battle droid radio 622";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_623: JLTS_droid_comlink
	{
		displayName="Battle droid radio 623";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_624: JLTS_droid_comlink
	{
		displayName="Battle droid radio 624";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_625: JLTS_droid_comlink
	{
		displayName="Battle droid radio 625";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_626: JLTS_droid_comlink
	{
		displayName="Battle droid radio 626";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_627: JLTS_droid_comlink
	{
		displayName="Battle droid radio 627";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_628: JLTS_droid_comlink
	{
		displayName="Battle droid radio 628";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_629: JLTS_droid_comlink
	{
		displayName="Battle droid radio 629";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_630: JLTS_droid_comlink
	{
		displayName="Battle droid radio 630";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_631: JLTS_droid_comlink
	{
		displayName="Battle droid radio 631";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_632: JLTS_droid_comlink
	{
		displayName="Battle droid radio 632";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_633: JLTS_droid_comlink
	{
		displayName="Battle droid radio 633";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_634: JLTS_droid_comlink
	{
		displayName="Battle droid radio 634";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_635: JLTS_droid_comlink
	{
		displayName="Battle droid radio 635";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_636: JLTS_droid_comlink
	{
		displayName="Battle droid radio 636";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_637: JLTS_droid_comlink
	{
		displayName="Battle droid radio 637";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_638: JLTS_droid_comlink
	{
		displayName="Battle droid radio 638";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_639: JLTS_droid_comlink
	{
		displayName="Battle droid radio 639";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_640: JLTS_droid_comlink
	{
		displayName="Battle droid radio 640";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_641: JLTS_droid_comlink
	{
		displayName="Battle droid radio 641";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_642: JLTS_droid_comlink
	{
		displayName="Battle droid radio 642";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_643: JLTS_droid_comlink
	{
		displayName="Battle droid radio 643";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_644: JLTS_droid_comlink
	{
		displayName="Battle droid radio 644";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_645: JLTS_droid_comlink
	{
		displayName="Battle droid radio 645";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_646: JLTS_droid_comlink
	{
		displayName="Battle droid radio 646";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_647: JLTS_droid_comlink
	{
		displayName="Battle droid radio 647";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_648: JLTS_droid_comlink
	{
		displayName="Battle droid radio 648";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_649: JLTS_droid_comlink
	{
		displayName="Battle droid radio 649";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_650: JLTS_droid_comlink
	{
		displayName="Battle droid radio 650";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_651: JLTS_droid_comlink
	{
		displayName="Battle droid radio 651";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_652: JLTS_droid_comlink
	{
		displayName="Battle droid radio 652";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_653: JLTS_droid_comlink
	{
		displayName="Battle droid radio 653";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_654: JLTS_droid_comlink
	{
		displayName="Battle droid radio 654";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_655: JLTS_droid_comlink
	{
		displayName="Battle droid radio 655";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_656: JLTS_droid_comlink
	{
		displayName="Battle droid radio 656";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_657: JLTS_droid_comlink
	{
		displayName="Battle droid radio 657";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_658: JLTS_droid_comlink
	{
		displayName="Battle droid radio 658";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_659: JLTS_droid_comlink
	{
		displayName="Battle droid radio 659";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_660: JLTS_droid_comlink
	{
		displayName="Battle droid radio 660";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_661: JLTS_droid_comlink
	{
		displayName="Battle droid radio 661";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_662: JLTS_droid_comlink
	{
		displayName="Battle droid radio 662";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_663: JLTS_droid_comlink
	{
		displayName="Battle droid radio 663";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_664: JLTS_droid_comlink
	{
		displayName="Battle droid radio 664";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_665: JLTS_droid_comlink
	{
		displayName="Battle droid radio 665";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_666: JLTS_droid_comlink
	{
		displayName="Battle droid radio 666";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_667: JLTS_droid_comlink
	{
		displayName="Battle droid radio 667";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_668: JLTS_droid_comlink
	{
		displayName="Battle droid radio 668";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_669: JLTS_droid_comlink
	{
		displayName="Battle droid radio 669";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_670: JLTS_droid_comlink
	{
		displayName="Battle droid radio 670";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_671: JLTS_droid_comlink
	{
		displayName="Battle droid radio 671";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_672: JLTS_droid_comlink
	{
		displayName="Battle droid radio 672";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_673: JLTS_droid_comlink
	{
		displayName="Battle droid radio 673";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_674: JLTS_droid_comlink
	{
		displayName="Battle droid radio 674";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_675: JLTS_droid_comlink
	{
		displayName="Battle droid radio 675";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_676: JLTS_droid_comlink
	{
		displayName="Battle droid radio 676";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_677: JLTS_droid_comlink
	{
		displayName="Battle droid radio 677";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_678: JLTS_droid_comlink
	{
		displayName="Battle droid radio 678";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_679: JLTS_droid_comlink
	{
		displayName="Battle droid radio 679";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_680: JLTS_droid_comlink
	{
		displayName="Battle droid radio 680";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_681: JLTS_droid_comlink
	{
		displayName="Battle droid radio 681";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_682: JLTS_droid_comlink
	{
		displayName="Battle droid radio 682";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_683: JLTS_droid_comlink
	{
		displayName="Battle droid radio 683";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_684: JLTS_droid_comlink
	{
		displayName="Battle droid radio 684";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_685: JLTS_droid_comlink
	{
		displayName="Battle droid radio 685";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_686: JLTS_droid_comlink
	{
		displayName="Battle droid radio 686";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_687: JLTS_droid_comlink
	{
		displayName="Battle droid radio 687";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_688: JLTS_droid_comlink
	{
		displayName="Battle droid radio 688";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_689: JLTS_droid_comlink
	{
		displayName="Battle droid radio 689";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_690: JLTS_droid_comlink
	{
		displayName="Battle droid radio 690";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_691: JLTS_droid_comlink
	{
		displayName="Battle droid radio 691";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_692: JLTS_droid_comlink
	{
		displayName="Battle droid radio 692";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_693: JLTS_droid_comlink
	{
		displayName="Battle droid radio 693";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_694: JLTS_droid_comlink
	{
		displayName="Battle droid radio 694";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_695: JLTS_droid_comlink
	{
		displayName="Battle droid radio 695";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_696: JLTS_droid_comlink
	{
		displayName="Battle droid radio 696";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_697: JLTS_droid_comlink
	{
		displayName="Battle droid radio 697";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_698: JLTS_droid_comlink
	{
		displayName="Battle droid radio 698";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_699: JLTS_droid_comlink
	{
		displayName="Battle droid radio 699";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_700: JLTS_droid_comlink
	{
		displayName="Battle droid radio 700";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_701: JLTS_droid_comlink
	{
		displayName="Battle droid radio 701";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_702: JLTS_droid_comlink
	{
		displayName="Battle droid radio 702";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_703: JLTS_droid_comlink
	{
		displayName="Battle droid radio 703";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_704: JLTS_droid_comlink
	{
		displayName="Battle droid radio 704";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_705: JLTS_droid_comlink
	{
		displayName="Battle droid radio 705";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_706: JLTS_droid_comlink
	{
		displayName="Battle droid radio 706";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_707: JLTS_droid_comlink
	{
		displayName="Battle droid radio 707";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_708: JLTS_droid_comlink
	{
		displayName="Battle droid radio 708";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_709: JLTS_droid_comlink
	{
		displayName="Battle droid radio 709";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_710: JLTS_droid_comlink
	{
		displayName="Battle droid radio 710";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_711: JLTS_droid_comlink
	{
		displayName="Battle droid radio 711";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_712: JLTS_droid_comlink
	{
		displayName="Battle droid radio 712";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_713: JLTS_droid_comlink
	{
		displayName="Battle droid radio 713";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_714: JLTS_droid_comlink
	{
		displayName="Battle droid radio 714";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_715: JLTS_droid_comlink
	{
		displayName="Battle droid radio 715";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_716: JLTS_droid_comlink
	{
		displayName="Battle droid radio 716";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_717: JLTS_droid_comlink
	{
		displayName="Battle droid radio 717";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_718: JLTS_droid_comlink
	{
		displayName="Battle droid radio 718";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_719: JLTS_droid_comlink
	{
		displayName="Battle droid radio 719";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_720: JLTS_droid_comlink
	{
		displayName="Battle droid radio 720";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_721: JLTS_droid_comlink
	{
		displayName="Battle droid radio 721";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_722: JLTS_droid_comlink
	{
		displayName="Battle droid radio 722";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_723: JLTS_droid_comlink
	{
		displayName="Battle droid radio 723";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_724: JLTS_droid_comlink
	{
		displayName="Battle droid radio 724";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_725: JLTS_droid_comlink
	{
		displayName="Battle droid radio 725";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_726: JLTS_droid_comlink
	{
		displayName="Battle droid radio 726";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_727: JLTS_droid_comlink
	{
		displayName="Battle droid radio 727";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_728: JLTS_droid_comlink
	{
		displayName="Battle droid radio 728";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_729: JLTS_droid_comlink
	{
		displayName="Battle droid radio 729";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_730: JLTS_droid_comlink
	{
		displayName="Battle droid radio 730";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_731: JLTS_droid_comlink
	{
		displayName="Battle droid radio 731";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_732: JLTS_droid_comlink
	{
		displayName="Battle droid radio 732";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_733: JLTS_droid_comlink
	{
		displayName="Battle droid radio 733";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_734: JLTS_droid_comlink
	{
		displayName="Battle droid radio 734";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_735: JLTS_droid_comlink
	{
		displayName="Battle droid radio 735";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_736: JLTS_droid_comlink
	{
		displayName="Battle droid radio 736";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_737: JLTS_droid_comlink
	{
		displayName="Battle droid radio 737";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_738: JLTS_droid_comlink
	{
		displayName="Battle droid radio 738";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_739: JLTS_droid_comlink
	{
		displayName="Battle droid radio 739";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_740: JLTS_droid_comlink
	{
		displayName="Battle droid radio 740";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_741: JLTS_droid_comlink
	{
		displayName="Battle droid radio 741";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_742: JLTS_droid_comlink
	{
		displayName="Battle droid radio 742";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_743: JLTS_droid_comlink
	{
		displayName="Battle droid radio 743";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_744: JLTS_droid_comlink
	{
		displayName="Battle droid radio 744";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_745: JLTS_droid_comlink
	{
		displayName="Battle droid radio 745";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_746: JLTS_droid_comlink
	{
		displayName="Battle droid radio 746";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_747: JLTS_droid_comlink
	{
		displayName="Battle droid radio 747";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_748: JLTS_droid_comlink
	{
		displayName="Battle droid radio 748";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_749: JLTS_droid_comlink
	{
		displayName="Battle droid radio 749";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_750: JLTS_droid_comlink
	{
		displayName="Battle droid radio 750";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_751: JLTS_droid_comlink
	{
		displayName="Battle droid radio 751";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_752: JLTS_droid_comlink
	{
		displayName="Battle droid radio 752";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_753: JLTS_droid_comlink
	{
		displayName="Battle droid radio 753";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_754: JLTS_droid_comlink
	{
		displayName="Battle droid radio 754";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_755: JLTS_droid_comlink
	{
		displayName="Battle droid radio 755";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_756: JLTS_droid_comlink
	{
		displayName="Battle droid radio 756";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_757: JLTS_droid_comlink
	{
		displayName="Battle droid radio 757";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_758: JLTS_droid_comlink
	{
		displayName="Battle droid radio 758";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_759: JLTS_droid_comlink
	{
		displayName="Battle droid radio 759";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_760: JLTS_droid_comlink
	{
		displayName="Battle droid radio 760";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_761: JLTS_droid_comlink
	{
		displayName="Battle droid radio 761";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_762: JLTS_droid_comlink
	{
		displayName="Battle droid radio 762";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_763: JLTS_droid_comlink
	{
		displayName="Battle droid radio 763";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_764: JLTS_droid_comlink
	{
		displayName="Battle droid radio 764";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_765: JLTS_droid_comlink
	{
		displayName="Battle droid radio 765";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_766: JLTS_droid_comlink
	{
		displayName="Battle droid radio 766";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_767: JLTS_droid_comlink
	{
		displayName="Battle droid radio 767";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_768: JLTS_droid_comlink
	{
		displayName="Battle droid radio 768";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_769: JLTS_droid_comlink
	{
		displayName="Battle droid radio 769";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_770: JLTS_droid_comlink
	{
		displayName="Battle droid radio 770";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_771: JLTS_droid_comlink
	{
		displayName="Battle droid radio 771";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_772: JLTS_droid_comlink
	{
		displayName="Battle droid radio 772";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_773: JLTS_droid_comlink
	{
		displayName="Battle droid radio 773";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_774: JLTS_droid_comlink
	{
		displayName="Battle droid radio 774";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_775: JLTS_droid_comlink
	{
		displayName="Battle droid radio 775";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_776: JLTS_droid_comlink
	{
		displayName="Battle droid radio 776";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_777: JLTS_droid_comlink
	{
		displayName="Battle droid radio 777";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_778: JLTS_droid_comlink
	{
		displayName="Battle droid radio 778";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_779: JLTS_droid_comlink
	{
		displayName="Battle droid radio 779";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_780: JLTS_droid_comlink
	{
		displayName="Battle droid radio 780";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_781: JLTS_droid_comlink
	{
		displayName="Battle droid radio 781";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_782: JLTS_droid_comlink
	{
		displayName="Battle droid radio 782";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_783: JLTS_droid_comlink
	{
		displayName="Battle droid radio 783";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_784: JLTS_droid_comlink
	{
		displayName="Battle droid radio 784";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_785: JLTS_droid_comlink
	{
		displayName="Battle droid radio 785";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_786: JLTS_droid_comlink
	{
		displayName="Battle droid radio 786";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_787: JLTS_droid_comlink
	{
		displayName="Battle droid radio 787";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_788: JLTS_droid_comlink
	{
		displayName="Battle droid radio 788";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_789: JLTS_droid_comlink
	{
		displayName="Battle droid radio 789";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_790: JLTS_droid_comlink
	{
		displayName="Battle droid radio 790";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_791: JLTS_droid_comlink
	{
		displayName="Battle droid radio 791";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_792: JLTS_droid_comlink
	{
		displayName="Battle droid radio 792";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_793: JLTS_droid_comlink
	{
		displayName="Battle droid radio 793";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_794: JLTS_droid_comlink
	{
		displayName="Battle droid radio 794";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_795: JLTS_droid_comlink
	{
		displayName="Battle droid radio 795";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_796: JLTS_droid_comlink
	{
		displayName="Battle droid radio 796";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_797: JLTS_droid_comlink
	{
		displayName="Battle droid radio 797";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_798: JLTS_droid_comlink
	{
		displayName="Battle droid radio 798";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_799: JLTS_droid_comlink
	{
		displayName="Battle droid radio 799";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_800: JLTS_droid_comlink
	{
		displayName="Battle droid radio 800";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_801: JLTS_droid_comlink
	{
		displayName="Battle droid radio 801";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_802: JLTS_droid_comlink
	{
		displayName="Battle droid radio 802";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_803: JLTS_droid_comlink
	{
		displayName="Battle droid radio 803";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_804: JLTS_droid_comlink
	{
		displayName="Battle droid radio 804";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_805: JLTS_droid_comlink
	{
		displayName="Battle droid radio 805";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_806: JLTS_droid_comlink
	{
		displayName="Battle droid radio 806";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_807: JLTS_droid_comlink
	{
		displayName="Battle droid radio 807";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_808: JLTS_droid_comlink
	{
		displayName="Battle droid radio 808";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_809: JLTS_droid_comlink
	{
		displayName="Battle droid radio 809";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_810: JLTS_droid_comlink
	{
		displayName="Battle droid radio 810";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_811: JLTS_droid_comlink
	{
		displayName="Battle droid radio 811";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_812: JLTS_droid_comlink
	{
		displayName="Battle droid radio 812";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_813: JLTS_droid_comlink
	{
		displayName="Battle droid radio 813";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_814: JLTS_droid_comlink
	{
		displayName="Battle droid radio 814";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_815: JLTS_droid_comlink
	{
		displayName="Battle droid radio 815";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_816: JLTS_droid_comlink
	{
		displayName="Battle droid radio 816";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_817: JLTS_droid_comlink
	{
		displayName="Battle droid radio 817";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_818: JLTS_droid_comlink
	{
		displayName="Battle droid radio 818";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_819: JLTS_droid_comlink
	{
		displayName="Battle droid radio 819";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_820: JLTS_droid_comlink
	{
		displayName="Battle droid radio 820";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_821: JLTS_droid_comlink
	{
		displayName="Battle droid radio 821";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_822: JLTS_droid_comlink
	{
		displayName="Battle droid radio 822";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_823: JLTS_droid_comlink
	{
		displayName="Battle droid radio 823";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_824: JLTS_droid_comlink
	{
		displayName="Battle droid radio 824";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_825: JLTS_droid_comlink
	{
		displayName="Battle droid radio 825";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_826: JLTS_droid_comlink
	{
		displayName="Battle droid radio 826";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_827: JLTS_droid_comlink
	{
		displayName="Battle droid radio 827";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_828: JLTS_droid_comlink
	{
		displayName="Battle droid radio 828";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_829: JLTS_droid_comlink
	{
		displayName="Battle droid radio 829";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_830: JLTS_droid_comlink
	{
		displayName="Battle droid radio 830";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_831: JLTS_droid_comlink
	{
		displayName="Battle droid radio 831";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_832: JLTS_droid_comlink
	{
		displayName="Battle droid radio 832";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_833: JLTS_droid_comlink
	{
		displayName="Battle droid radio 833";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_834: JLTS_droid_comlink
	{
		displayName="Battle droid radio 834";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_835: JLTS_droid_comlink
	{
		displayName="Battle droid radio 835";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_836: JLTS_droid_comlink
	{
		displayName="Battle droid radio 836";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_837: JLTS_droid_comlink
	{
		displayName="Battle droid radio 837";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_838: JLTS_droid_comlink
	{
		displayName="Battle droid radio 838";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_839: JLTS_droid_comlink
	{
		displayName="Battle droid radio 839";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_840: JLTS_droid_comlink
	{
		displayName="Battle droid radio 840";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_841: JLTS_droid_comlink
	{
		displayName="Battle droid radio 841";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_842: JLTS_droid_comlink
	{
		displayName="Battle droid radio 842";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_843: JLTS_droid_comlink
	{
		displayName="Battle droid radio 843";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_844: JLTS_droid_comlink
	{
		displayName="Battle droid radio 844";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_845: JLTS_droid_comlink
	{
		displayName="Battle droid radio 845";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_846: JLTS_droid_comlink
	{
		displayName="Battle droid radio 846";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_847: JLTS_droid_comlink
	{
		displayName="Battle droid radio 847";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_848: JLTS_droid_comlink
	{
		displayName="Battle droid radio 848";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_849: JLTS_droid_comlink
	{
		displayName="Battle droid radio 849";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_850: JLTS_droid_comlink
	{
		displayName="Battle droid radio 850";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_851: JLTS_droid_comlink
	{
		displayName="Battle droid radio 851";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_852: JLTS_droid_comlink
	{
		displayName="Battle droid radio 852";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_853: JLTS_droid_comlink
	{
		displayName="Battle droid radio 853";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_854: JLTS_droid_comlink
	{
		displayName="Battle droid radio 854";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_855: JLTS_droid_comlink
	{
		displayName="Battle droid radio 855";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_856: JLTS_droid_comlink
	{
		displayName="Battle droid radio 856";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_857: JLTS_droid_comlink
	{
		displayName="Battle droid radio 857";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_858: JLTS_droid_comlink
	{
		displayName="Battle droid radio 858";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_859: JLTS_droid_comlink
	{
		displayName="Battle droid radio 859";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_860: JLTS_droid_comlink
	{
		displayName="Battle droid radio 860";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_861: JLTS_droid_comlink
	{
		displayName="Battle droid radio 861";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_862: JLTS_droid_comlink
	{
		displayName="Battle droid radio 862";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_863: JLTS_droid_comlink
	{
		displayName="Battle droid radio 863";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_864: JLTS_droid_comlink
	{
		displayName="Battle droid radio 864";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_865: JLTS_droid_comlink
	{
		displayName="Battle droid radio 865";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_866: JLTS_droid_comlink
	{
		displayName="Battle droid radio 866";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_867: JLTS_droid_comlink
	{
		displayName="Battle droid radio 867";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_868: JLTS_droid_comlink
	{
		displayName="Battle droid radio 868";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_869: JLTS_droid_comlink
	{
		displayName="Battle droid radio 869";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_870: JLTS_droid_comlink
	{
		displayName="Battle droid radio 870";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_871: JLTS_droid_comlink
	{
		displayName="Battle droid radio 871";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_872: JLTS_droid_comlink
	{
		displayName="Battle droid radio 872";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_873: JLTS_droid_comlink
	{
		displayName="Battle droid radio 873";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_874: JLTS_droid_comlink
	{
		displayName="Battle droid radio 874";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_875: JLTS_droid_comlink
	{
		displayName="Battle droid radio 875";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_876: JLTS_droid_comlink
	{
		displayName="Battle droid radio 876";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_877: JLTS_droid_comlink
	{
		displayName="Battle droid radio 877";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_878: JLTS_droid_comlink
	{
		displayName="Battle droid radio 878";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_879: JLTS_droid_comlink
	{
		displayName="Battle droid radio 879";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_880: JLTS_droid_comlink
	{
		displayName="Battle droid radio 880";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_881: JLTS_droid_comlink
	{
		displayName="Battle droid radio 881";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_882: JLTS_droid_comlink
	{
		displayName="Battle droid radio 882";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_883: JLTS_droid_comlink
	{
		displayName="Battle droid radio 883";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_884: JLTS_droid_comlink
	{
		displayName="Battle droid radio 884";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_885: JLTS_droid_comlink
	{
		displayName="Battle droid radio 885";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_886: JLTS_droid_comlink
	{
		displayName="Battle droid radio 886";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_887: JLTS_droid_comlink
	{
		displayName="Battle droid radio 887";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_888: JLTS_droid_comlink
	{
		displayName="Battle droid radio 888";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_889: JLTS_droid_comlink
	{
		displayName="Battle droid radio 889";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_890: JLTS_droid_comlink
	{
		displayName="Battle droid radio 890";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_891: JLTS_droid_comlink
	{
		displayName="Battle droid radio 891";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_892: JLTS_droid_comlink
	{
		displayName="Battle droid radio 892";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_893: JLTS_droid_comlink
	{
		displayName="Battle droid radio 893";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_894: JLTS_droid_comlink
	{
		displayName="Battle droid radio 894";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_895: JLTS_droid_comlink
	{
		displayName="Battle droid radio 895";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_896: JLTS_droid_comlink
	{
		displayName="Battle droid radio 896";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_897: JLTS_droid_comlink
	{
		displayName="Battle droid radio 897";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_898: JLTS_droid_comlink
	{
		displayName="Battle droid radio 898";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_899: JLTS_droid_comlink
	{
		displayName="Battle droid radio 899";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_900: JLTS_droid_comlink
	{
		displayName="Battle droid radio 900";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_901: JLTS_droid_comlink
	{
		displayName="Battle droid radio 901";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_902: JLTS_droid_comlink
	{
		displayName="Battle droid radio 902";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_903: JLTS_droid_comlink
	{
		displayName="Battle droid radio 903";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_904: JLTS_droid_comlink
	{
		displayName="Battle droid radio 904";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_905: JLTS_droid_comlink
	{
		displayName="Battle droid radio 905";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_906: JLTS_droid_comlink
	{
		displayName="Battle droid radio 906";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_907: JLTS_droid_comlink
	{
		displayName="Battle droid radio 907";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_908: JLTS_droid_comlink
	{
		displayName="Battle droid radio 908";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_909: JLTS_droid_comlink
	{
		displayName="Battle droid radio 909";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_910: JLTS_droid_comlink
	{
		displayName="Battle droid radio 910";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_911: JLTS_droid_comlink
	{
		displayName="Battle droid radio 911";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_912: JLTS_droid_comlink
	{
		displayName="Battle droid radio 912";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_913: JLTS_droid_comlink
	{
		displayName="Battle droid radio 913";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_914: JLTS_droid_comlink
	{
		displayName="Battle droid radio 914";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_915: JLTS_droid_comlink
	{
		displayName="Battle droid radio 915";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_916: JLTS_droid_comlink
	{
		displayName="Battle droid radio 916";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_917: JLTS_droid_comlink
	{
		displayName="Battle droid radio 917";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_918: JLTS_droid_comlink
	{
		displayName="Battle droid radio 918";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_919: JLTS_droid_comlink
	{
		displayName="Battle droid radio 919";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_920: JLTS_droid_comlink
	{
		displayName="Battle droid radio 920";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_921: JLTS_droid_comlink
	{
		displayName="Battle droid radio 921";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_922: JLTS_droid_comlink
	{
		displayName="Battle droid radio 922";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_923: JLTS_droid_comlink
	{
		displayName="Battle droid radio 923";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_924: JLTS_droid_comlink
	{
		displayName="Battle droid radio 924";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_925: JLTS_droid_comlink
	{
		displayName="Battle droid radio 925";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_926: JLTS_droid_comlink
	{
		displayName="Battle droid radio 926";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_927: JLTS_droid_comlink
	{
		displayName="Battle droid radio 927";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_928: JLTS_droid_comlink
	{
		displayName="Battle droid radio 928";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_929: JLTS_droid_comlink
	{
		displayName="Battle droid radio 929";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_930: JLTS_droid_comlink
	{
		displayName="Battle droid radio 930";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_931: JLTS_droid_comlink
	{
		displayName="Battle droid radio 931";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_932: JLTS_droid_comlink
	{
		displayName="Battle droid radio 932";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_933: JLTS_droid_comlink
	{
		displayName="Battle droid radio 933";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_934: JLTS_droid_comlink
	{
		displayName="Battle droid radio 934";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_935: JLTS_droid_comlink
	{
		displayName="Battle droid radio 935";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_936: JLTS_droid_comlink
	{
		displayName="Battle droid radio 936";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_937: JLTS_droid_comlink
	{
		displayName="Battle droid radio 937";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_938: JLTS_droid_comlink
	{
		displayName="Battle droid radio 938";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_939: JLTS_droid_comlink
	{
		displayName="Battle droid radio 939";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_940: JLTS_droid_comlink
	{
		displayName="Battle droid radio 940";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_941: JLTS_droid_comlink
	{
		displayName="Battle droid radio 941";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_942: JLTS_droid_comlink
	{
		displayName="Battle droid radio 942";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_943: JLTS_droid_comlink
	{
		displayName="Battle droid radio 943";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_944: JLTS_droid_comlink
	{
		displayName="Battle droid radio 944";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_945: JLTS_droid_comlink
	{
		displayName="Battle droid radio 945";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_946: JLTS_droid_comlink
	{
		displayName="Battle droid radio 946";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_947: JLTS_droid_comlink
	{
		displayName="Battle droid radio 947";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_948: JLTS_droid_comlink
	{
		displayName="Battle droid radio 948";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_949: JLTS_droid_comlink
	{
		displayName="Battle droid radio 949";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_950: JLTS_droid_comlink
	{
		displayName="Battle droid radio 950";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_951: JLTS_droid_comlink
	{
		displayName="Battle droid radio 951";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_952: JLTS_droid_comlink
	{
		displayName="Battle droid radio 952";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_953: JLTS_droid_comlink
	{
		displayName="Battle droid radio 953";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_954: JLTS_droid_comlink
	{
		displayName="Battle droid radio 954";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_955: JLTS_droid_comlink
	{
		displayName="Battle droid radio 955";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_956: JLTS_droid_comlink
	{
		displayName="Battle droid radio 956";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_957: JLTS_droid_comlink
	{
		displayName="Battle droid radio 957";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_958: JLTS_droid_comlink
	{
		displayName="Battle droid radio 958";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_959: JLTS_droid_comlink
	{
		displayName="Battle droid radio 959";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_960: JLTS_droid_comlink
	{
		displayName="Battle droid radio 960";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_961: JLTS_droid_comlink
	{
		displayName="Battle droid radio 961";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_962: JLTS_droid_comlink
	{
		displayName="Battle droid radio 962";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_963: JLTS_droid_comlink
	{
		displayName="Battle droid radio 963";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_964: JLTS_droid_comlink
	{
		displayName="Battle droid radio 964";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_965: JLTS_droid_comlink
	{
		displayName="Battle droid radio 965";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_966: JLTS_droid_comlink
	{
		displayName="Battle droid radio 966";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_967: JLTS_droid_comlink
	{
		displayName="Battle droid radio 967";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_968: JLTS_droid_comlink
	{
		displayName="Battle droid radio 968";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_969: JLTS_droid_comlink
	{
		displayName="Battle droid radio 969";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_970: JLTS_droid_comlink
	{
		displayName="Battle droid radio 970";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_971: JLTS_droid_comlink
	{
		displayName="Battle droid radio 971";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_972: JLTS_droid_comlink
	{
		displayName="Battle droid radio 972";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_973: JLTS_droid_comlink
	{
		displayName="Battle droid radio 973";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_974: JLTS_droid_comlink
	{
		displayName="Battle droid radio 974";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_975: JLTS_droid_comlink
	{
		displayName="Battle droid radio 975";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_976: JLTS_droid_comlink
	{
		displayName="Battle droid radio 976";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_977: JLTS_droid_comlink
	{
		displayName="Battle droid radio 977";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_978: JLTS_droid_comlink
	{
		displayName="Battle droid radio 978";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_979: JLTS_droid_comlink
	{
		displayName="Battle droid radio 979";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_980: JLTS_droid_comlink
	{
		displayName="Battle droid radio 980";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_981: JLTS_droid_comlink
	{
		displayName="Battle droid radio 981";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_982: JLTS_droid_comlink
	{
		displayName="Battle droid radio 982";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_983: JLTS_droid_comlink
	{
		displayName="Battle droid radio 983";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_984: JLTS_droid_comlink
	{
		displayName="Battle droid radio 984";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_985: JLTS_droid_comlink
	{
		displayName="Battle droid radio 985";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_986: JLTS_droid_comlink
	{
		displayName="Battle droid radio 986";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_987: JLTS_droid_comlink
	{
		displayName="Battle droid radio 987";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_988: JLTS_droid_comlink
	{
		displayName="Battle droid radio 988";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_989: JLTS_droid_comlink
	{
		displayName="Battle droid radio 989";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_990: JLTS_droid_comlink
	{
		displayName="Battle droid radio 990";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_991: JLTS_droid_comlink
	{
		displayName="Battle droid radio 991";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_992: JLTS_droid_comlink
	{
		displayName="Battle droid radio 992";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_993: JLTS_droid_comlink
	{
		displayName="Battle droid radio 993";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_994: JLTS_droid_comlink
	{
		displayName="Battle droid radio 994";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_995: JLTS_droid_comlink
	{
		displayName="Battle droid radio 995";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_996: JLTS_droid_comlink
	{
		displayName="Battle droid radio 996";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_997: JLTS_droid_comlink
	{
		displayName="Battle droid radio 997";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_998: JLTS_droid_comlink
	{
		displayName="Battle droid radio 998";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_999: JLTS_droid_comlink
	{
		displayName="Battle droid radio 999";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class JLTS_droid_comlink_1000: JLTS_droid_comlink
	{
		displayName="Battle droid radio 1000";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
};
class JLTS_clone_rto_radio_dialog
{
	idd=1666;
	movingEnable=1;
	controlsBackground[]={};
	objects[]={};
	onUnload="['OnRadioOpen', player, [player, TF_lr_dialog_radio, true, 'JLTS_clone_rto_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
	onLoad="if(sunOrMoon < 0.2)then{((_this select 0) displayCtrl TF_BACKGROUND_ID) ctrlSetText '\MRC\JLTS\radios\data\ui\clone_rto_night_ui_ca.paa';};";
	controls[]=
	{
		"background",
		"enter",
		"edit",
		"channel_edit",
		"clear",
		"channel01",
		"channel02",
		"channel03",
		"channel04",
		"channel05",
		"channel06",
		"channel07",
		"channel08",
		"channel09",
		"increase_volume",
		"decrease_volume",
		"stereo",
		"additional",
		"speakers"
	};
	class background: RscBackPicture
	{
		idc=67676;
		text="\MRC\JLTS\radios\data\ui\clone_rto_ui_ca.paa";
		x="0.0935937 * safezoneW + safezoneX";
		y="0.0252042 * safezoneH + safezoneY";
		w="0.510056 * safezoneW";
		h="0.942975 * safezoneH";
		moving=1;
	};
	class edit: RscEditLCD
	{
		moving=1;
		idc=1410;
		x="safeZoneX + safeZoneW * 0.345";
		y="safeZoneY + safeZoneH * 0.41555556";
		w="safeZoneW * 0.119375";
		h="safeZoneH * 0.02777778";
		font="JLTS_republic";
		colorText[]={1,1,1,1};
		shadow=2;
		tooltip="$STR_tfar_core_current_freq";
		canModify=1;
		onKeyUp="if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter; };";
	};
	class channel_edit: RscEditLCD
	{
		moving=1;
		idc=1411;
		x="safeZoneX + safeZoneW * 0.235";
		y="safeZoneY + safeZoneH * 0.41555556";
		w="safeZoneW * 0.095625";
		h="safeZoneH * 0.02777778";
		font="JLTS_republic";
		colorText[]={1,1,1,1};
		shadow=2;
		tooltip="$STR_tfar_core_current_channel";
		canModify=0;
	};
	class clear: HiddenButton
	{
		idc=1611;
		x="safeZoneX + safeZoneW * 0.42875";
		y="safeZoneY + safeZoneH * 0.53444445";
		w="safeZoneW * 0.04125";
		h="safeZoneH * 0.04666667";
		tooltip="$STR_tfar_core_clear_frequency";
		action="ctrlSetText [1410,'']; ctrlSetFocus ((findDisplay 1666) displayCtrl 1410);";
	};
	class enter: HiddenButton
	{
		idc=1610;
		x="safeZoneX + safeZoneW * 0.42875";
		y="safeZoneY + safeZoneH * 0.47555556";
		w="safeZoneW * 0.04125";
		h="safeZoneH * 0.04";
		tooltip="$STR_tfar_core_set_frequency";
		onButtonClick="[((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;";
		action="";
	};
	class channel01: HiddenButton
	{
		idc=1701;
		x="safeZoneX + safeZoneW * 0.289375";
		y="safeZoneY + safeZoneH * 0.47666667";
		w="safeZoneW * 0.03125";
		h="safeZoneH * 0.03888889";
		action="[TF_lr_dialog_radio, 0] call TFAR_fnc_setLrChannel;call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_1";
	};
	class channel02: HiddenButton
	{
		idc=1702;
		x="safeZoneX + safeZoneW * 0.330625";
		y="safeZoneY + safeZoneH * 0.47666667";
		w="safeZoneW * 0.03625";
		h="safeZoneH * 0.03888889";
		action="[TF_lr_dialog_radio, 1] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_2";
	};
	class channel03: HiddenButton
	{
		idc=1703;
		x="safeZoneX + safeZoneW * 0.37625";
		y="safeZoneY + safeZoneH * 0.47666667";
		w="safeZoneW * 0.0325";
		h="safeZoneH * 0.03888889";
		action="[TF_lr_dialog_radio, 2] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_3";
	};
	class channel04: HiddenButton
	{
		idc=1704;
		x="safeZoneX + safeZoneW * 0.28875";
		y="safeZoneY + safeZoneH * 0.53333334";
		w="safeZoneW * 0.0325";
		h="safeZoneH * 0.04666667";
		action="[TF_lr_dialog_radio, 3] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_4";
	};
	class channel05: HiddenButton
	{
		idc=1705;
		x="safeZoneX + safeZoneW * 0.33125";
		y="safeZoneY + safeZoneH * 0.53333334";
		w="safeZoneW * 0.034375";
		h="safeZoneH * 0.04666667";
		action="[TF_lr_dialog_radio, 4] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_5";
	};
	class channel06: HiddenButton
	{
		idc=1706;
		x="safeZoneX + safeZoneW * 0.375625";
		y="safeZoneY + safeZoneH * 0.53333334";
		w="safeZoneW * 0.0325";
		h="safeZoneH * 0.04666667";
		action="[TF_lr_dialog_radio, 5] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_6";
	};
	class channel07: HiddenButton
	{
		idc=1707;
		x="safeZoneX + safeZoneW * 0.289375";
		y="safeZoneY + safeZoneH * 0.59888889";
		w="safeZoneW * 0.0325";
		h="safeZoneH * 0.03888889";
		action="[TF_lr_dialog_radio, 6] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_7";
	};
	class channel08: HiddenButton
	{
		idc=1708;
		x="safeZoneX + safeZoneW * 0.331875";
		y="safeZoneY + safeZoneH * 0.59888889";
		w="safeZoneW * 0.034375";
		h="safeZoneH * 0.03888889";
		action="[TF_lr_dialog_radio, 7] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_8";
	};
	class channel09: HiddenButton
	{
		idc=1709;
		x="safeZoneX + safeZoneW * 0.376875";
		y="safeZoneY + safeZoneH * 0.59888889";
		w="safeZoneW * 0.031875";
		h="safeZoneH * 0.03888889";
		action="[TF_lr_dialog_radio, 8] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_9";
	};
	class increase_volume: HiddenButton
	{
		idc=1612;
		x="safeZoneX + safeZoneW * 0.228125";
		y="safeZoneY + safeZoneH * 0.47666667";
		w="safeZoneW * 0.04";
		h="safeZoneH * 0.02666667";
		action="[1, true] call TFAR_fnc_setVolumeViaDialog;";
		tooltip="$STR_tfar_core_increase_volume";
	};
	class decrease_volume: HiddenButton
	{
		idc=1613;
		x="safeZoneX + safeZoneW * 0.228125";
		y="safeZoneY + safeZoneH * 0.52111112";
		w="safeZoneW * 0.04";
		h="safeZoneH * 0.02777778";
		action="[0, true] call TFAR_fnc_setVolumeViaDialog;";
		tooltip="$STR_tfar_core_decrease_volume";
	};
	class stereo: HiddenButton
	{
		idc=1710;
		x="safeZoneX + safeZoneW * 0.228125";
		y="safeZoneY + safeZoneH * 0.56666667";
		w="safeZoneW * 0.04";
		h="safeZoneH * 0.02777778";
		action="[TF_lr_dialog_radio,((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod 3] call TFAR_fnc_setLrStereo; [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip="$STR_tfar_core_stereo_settings";
	};
	class additional: HiddenButton
	{
		idc=12345;
		x="safeZoneX + safeZoneW * 0.42875";
		y="safeZoneY + safeZoneH * 0.59888889";
		w="safeZoneW * 0.04125";
		h="safeZoneH * 0.03888889";
		tooltip="$STR_tfar_core_set_additional";
		action="[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel; call TFAR_fnc_updateLRDialogToChannel; [TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
	};
	class speakers: HiddenButton
	{
		idc=123456;
		x="safeZoneX + safeZoneW * 0.228125";
		y="safeZoneY + safeZoneH * 0.61111112";
		w="safeZoneW * 0.04";
		h="safeZoneH * 0.02888889";
		tooltip="$STR_speakers_settings_true";
		action="TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
};
class JLTS_clone_lr_programmer_radio_dialog
{
	idd=1666;
	movingEnable=1;
	controlsBackground[]={};
	objects[]={};
	onUnload="['OnRadioOpen', player, [player, TF_lr_dialog_radio, true, 'JLTS_clone_lr_programmer_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
	onLoad="if(sunOrMoon < 0.2)then{((_this select 0) displayCtrl TF_BACKGROUND_ID) ctrlSetText '\MRC\JLTS\radios\data\ui\clone_programmer_night_ui_ca.paa';};";
	controls[]=
	{
		"background",
		"enter",
		"edit",
		"channel_edit",
		"clear",
		"channel01",
		"channel02",
		"channel03",
		"channel04",
		"channel05",
		"channel06",
		"channel07",
		"channel08",
		"channel09",
		"increase_volume",
		"decrease_volume",
		"stereo",
		"additional",
		"speakers"
	};
	class background: RscBackPicture
	{
		idc=67676;
		text="\MRC\JLTS\radios\data\ui\clone_programmer_ui_ca.paa";
		x="0.0935937 * safezoneW + safezoneX";
		y="0.0252042 * safezoneH + safezoneY";
		w="0.510056 * safezoneW";
		h="0.942975 * safezoneH";
		moving=1;
	};
	class edit: RscEditLCD
	{
		moving=1;
		idc=1410;
		x="safeZoneX + safeZoneW * 0.26";
		y="safeZoneY + safeZoneH * 0.40333334";
		w="safeZoneW * 0.17625";
		h="safeZoneH * 0.06333334";
		font="JLTS_republic";
		colorText[]={1,1,1,1};
		shadow=2;
		tooltip="$STR_tfar_core_current_freq";
		canModify=1;
		onKeyUp="if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter; };";
	};
	class channel_edit: RscEditLCD
	{
		moving=1;
		idc=1411;
		x="safeZoneX + safeZoneW * 0.26";
		y="safeZoneY + safeZoneH * 0.32555556";
		w="safeZoneW * 0.17625";
		h="safeZoneH * 0.05888889";
		font="JLTS_republic";
		colorText[]={1,1,1,1};
		shadow=2;
		tooltip="$STR_tfar_core_current_channel";
		canModify=0;
	};
	class clear: HiddenButton
	{
		idc=1611;
		x="safeZoneX + safeZoneW * 0.318125";
		y="safeZoneY + safeZoneH * 0.69666667";
		w="safeZoneW * 0.05875";
		h="safeZoneH * 0.03444445";
		tooltip="$STR_tfar_core_clear_frequency";
		action="ctrlSetText [1410,'']; ctrlSetFocus ((findDisplay 1666) displayCtrl 1410);";
	};
	class enter: HiddenButton
	{
		idc=1610;
		x="safeZoneX + safeZoneW * 0.249375";
		y="safeZoneY + safeZoneH * 0.69666667";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03444445";
		tooltip="$STR_tfar_core_set_frequency";
		onButtonClick="[((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;";
		action="";
	};
	class channel01: HiddenButton
	{
		idc=1701;
		x="safeZoneX + safeZoneW * 0.249375";
		y="safeZoneY + safeZoneH * 0.52777778";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 0] call TFAR_fnc_setLrChannel;call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_1";
	};
	class channel02: HiddenButton
	{
		idc=1702;
		x="safeZoneX + safeZoneW * 0.319375";
		y="safeZoneY + safeZoneH * 0.52777778";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 1] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_2";
	};
	class channel03: HiddenButton
	{
		idc=1703;
		x="safeZoneX + safeZoneW * 0.389375";
		y="safeZoneY + safeZoneH * 0.52777778";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 2] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_3";
	};
	class channel04: HiddenButton
	{
		idc=1704;
		x="safeZoneX + safeZoneW * 0.249375";
		y="safeZoneY + safeZoneH * 0.58222223";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 3] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_4";
	};
	class channel05: HiddenButton
	{
		idc=1705;
		x="safeZoneX + safeZoneW * 0.319375";
		y="safeZoneY + safeZoneH * 0.58333334";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 4] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_5";
	};
	class channel06: HiddenButton
	{
		idc=1706;
		x="safeZoneX + safeZoneW * 0.389375";
		y="safeZoneY + safeZoneH * 0.58222223";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 5] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_6";
	};
	class channel07: HiddenButton
	{
		idc=1707;
		x="safeZoneX + safeZoneW * 0.24875";
		y="safeZoneY + safeZoneH * 0.64111112";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 6] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_7";
	};
	class channel08: HiddenButton
	{
		idc=1708;
		x="safeZoneX + safeZoneW * 0.319375";
		y="safeZoneY + safeZoneH * 0.64111112";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 7] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_8";
	};
	class channel09: HiddenButton
	{
		idc=1709;
		x="safeZoneX + safeZoneW * 0.389375";
		y="safeZoneY + safeZoneH * 0.64333334";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03111112";
		action="[TF_lr_dialog_radio, 8] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip="$STR_tfar_core_radio_channel_9";
	};
	class increase_volume: HiddenButton
	{
		idc=1612;
		x="safeZoneX + safeZoneW * 0.410625";
		y="safeZoneY + safeZoneH * 0.75555556";
		w="safeZoneW * 0.035625";
		h="safeZoneH * 0.05";
		action="[1, true] call TFAR_fnc_setVolumeViaDialog;";
		tooltip="$STR_tfar_core_increase_volume";
	};
	class decrease_volume: HiddenButton
	{
		idc=1613;
		x="safeZoneX + safeZoneW * 0.24875";
		y="safeZoneY + safeZoneH * 0.75444445";
		w="safeZoneW * 0.035625";
		h="safeZoneH * 0.05";
		action="[0, true] call TFAR_fnc_setVolumeViaDialog;";
		tooltip="$STR_tfar_core_decrease_volume";
	};
	class stereo: HiddenButton
	{
		idc=1710;
		x="safeZoneX + safeZoneW * 0.3";
		y="safeZoneY + safeZoneH * 0.75444445";
		w="safeZoneW * 0.04";
		h="safeZoneH * 0.05";
		action="[TF_lr_dialog_radio,((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod 3] call TFAR_fnc_setLrStereo; [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip="$STR_tfar_core_stereo_settings";
	};
	class additional: HiddenButton
	{
		idc=12345;
		x="safeZoneX + safeZoneW * 0.39";
		y="safeZoneY + safeZoneH * 0.69555556";
		w="safeZoneW * 0.056875";
		h="safeZoneH * 0.03444445";
		tooltip="$STR_tfar_core_set_additional";
		action="[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel; call TFAR_fnc_updateLRDialogToChannel; [TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
	};
	class speakers: HiddenButton
	{
		idc=123456;
		x="safeZoneX + safeZoneW * 0.3575";
		y="safeZoneY + safeZoneH * 0.75444445";
		w="safeZoneW * 0.04";
		h="safeZoneH * 0.05";
		tooltip="$STR_speakers_settings_true";
		action="TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
};
class JLTS_droid_lr_radio_dialog: JLTS_clone_rto_radio_dialog
{
	onUnload="['OnRadioOpen', player, [player, TF_lr_dialog_radio, true, 'JLTS_droid_lr_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
	onLoad="if(sunOrMoon < 0.2)then{((_this select 0) displayCtrl TF_BACKGROUND_ID) ctrlSetText '\MRC\JLTS\radios\data\ui\droid_lr_ui_ca.paa';};";
	class background: background
	{
		text="\MRC\JLTS\radios\data\ui\droid_lr_ui_ca.paa";
	};
};
class JLTS_clone_comlink_dialog
{
	idd=1333;
	movingEnable=1;
	controlsBackground[]={};
	objects[]={};
	onUnload="['OnRadioOpen', player, [player, TF_sw_dialog_radio, false, 'JLTS_clone_comlink_dialog', false]] call TFAR_fnc_fireEventHandlers;";
	onLoad="if(sunOrMoon < 0.2)then{((_this select 0) displayCtrl TF_BACKGROUND_ID) ctrlSetText '\MRC\JLTS\radios\data\ui\clone_comlink_night_ui_ca.paa';};";
	controls[]=
	{
		"background",
		"enter",
		"edit",
		"channel_edit",
		"clear",
		"prev_channel",
		"next_channel",
		"volume_Switch",
		"stereo",
		"additional",
		"speakers"
	};
	class background: RscBackPicture
	{
		idc=67676;
		text="\MRC\JLTS\radios\data\ui\clone_comlink_ui_ca.paa";
		x="0.0935937 * safezoneW + safezoneX";
		y="0.0252042 * safezoneH + safezoneY";
		w="0.510056 * safezoneW";
		h="0.942975 * safezoneH";
		moving=1;
	};
	class edit: RscEditLCD
	{
		moving=1;
		idc=1400;
		x="safeZoneX + safeZoneW * 0.320625";
		y="safeZoneY + safeZoneH * 0.33";
		w="safeZoneW * 0.12875";
		h="safeZoneH * 0.06";
		font="JLTS_republic";
		colorText[]={1,1,1,1};
		shadow=2;
		tooltip="$STR_tfar_core_current_freq";
		canModify=1;
		onKeyUp="if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1400] call TFAR_handhelds_fnc_onButtonClick_Enter; };";
	};
	class channel_edit: RscEditLCD
	{
		moving=1;
		idc=1604;
		x="safeZoneX + safeZoneW * 0.194375";
		y="safeZoneY + safeZoneH * 0.33";
		w="safeZoneW * 0.12625";
		h="safeZoneH * 0.06";
		font="JLTS_republic";
		colorText[]={1,1,1,1};
		shadow=2;
		tooltip="$STR_tfar_core_current_channel";
		canModify=0;
	};
	class enter: HiddenButton
	{
		idc=1600;
		x="safeZoneX + safeZoneW * 0.489375";
		y="safeZoneY + safeZoneH * 0.46";
		w="safeZoneW * 0.068125";
		h="safeZoneH * 0.07";
		tooltip="$STR_tfar_core_set_frequency";
		onButtonClick="[((ctrlParent (_this select 0))) displayCtrl 1400] call TFAR_handhelds_fnc_onButtonClick_Enter;";
		action="";
	};
	class clear: HiddenButton
	{
		idc=1601;
		x="safeZoneX + safeZoneW * 0.248125";
		y="safeZoneY + safeZoneH * 0.51222223";
		w="safeZoneW * 0.03625";
		h="safeZoneH * 0.06333334";
		tooltip="$STR_tfar_core_clear_frequency";
		action="ctrlSetText [1400,'']; ctrlSetFocus ((findDisplay 1333) displayCtrl 1400);";
	};
	class additional: HiddenButton
	{
		idc=1602;
		x="safeZoneX + safeZoneW * 0.248125";
		y="safeZoneY + safeZoneH * 0.41555556";
		w="safeZoneW * 0.03625";
		h="safeZoneH * 0.06555556";
		tooltip="$STR_tfar_core_set_additional";
		action="[TF_sw_dialog_radio, TF_sw_dialog_radio call TFAR_fnc_getSwChannel] call TFAR_fnc_setAdditionalSwChannel; call TFAR_fnc_updateSWDialogToChannel; [TF_sw_dialog_radio, false] call TFAR_fnc_showRadioInfo;";
	};
	class speakers: HiddenButton
	{
		idc=1603;
		x="safeZoneX + safeZoneW * 0.19625";
		y="safeZoneY + safeZoneH * 0.41555556";
		w="safeZoneW * 0.035";
		h="safeZoneH * 0.06555556";
		tooltip="$STR_tfar_core_speakers_settings_true";
		action="[TF_sw_dialog_radio] call TFAR_fnc_setSwSpeakers;[TF_sw_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
	class next_channel: HiddenButton
	{
		idc=1602;
		x="safeZoneX + safeZoneW * 0.3";
		y="safeZoneY + safeZoneH * 0.41444445";
		w="safeZoneW * 0.0375";
		h="safeZoneH * 0.06888889";
		tooltip="$STR_tfar_core_next_channel";
		action="[1, false] call TFAR_fnc_setChannelViaDialog;";
	};
	class prev_channel: HiddenButton
	{
		idc=1603;
		x="safeZoneX + safeZoneW * 0.3";
		y="safeZoneY + safeZoneH * 0.51111112";
		w="safeZoneW * 0.0375";
		h="safeZoneH * 0.06666667";
		tooltip="$STR_tfar_core_previous_channel";
		action="[0, false] call TFAR_fnc_setChannelViaDialog;";
	};
	class stereo: HiddenButton
	{
		idc=1607;
		x="safeZoneX + safeZoneW * 0.19625";
		y="safeZoneY + safeZoneH * 0.51333334";
		w="safeZoneW * 0.035";
		h="safeZoneH * 0.06555556";
		action="[TF_sw_dialog_radio,((TF_sw_dialog_radio call TFAR_fnc_getCurrentSwStereo) + 1) mod 3] call TFAR_fnc_setSwStereo; [TF_sw_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip="$STR_tfar_core_stereo_settings";
	};
	class volume_Switch: HiddenRotator
	{
		idc=12345;
		x="safeZoneX + safeZoneW * 0.14375";
		y="safeZoneY + safeZoneH * 0.41444445";
		w="safeZoneW * 0.03375";
		h="safeZoneH * 0.16444445";
		tooltip="$STR_rotator_volume";
		onMouseButtonDown="[_this select 1, false] call TFAR_fnc_setVolumeViaDialog;";
	};
};
