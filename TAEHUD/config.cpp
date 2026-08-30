class CfgPatches
{
	class TAEHUD
	{
		name = "The Ashen Enclave - Helmet HUD";
		author = "TAE Mod Team";
		url = "https://discord.gg/9zgGp5QSW7";
		requiredVersion = 1.60;
		requiredAddons[] =
		{
			"TAECore",
			"TAEGear_Helmets",
			"ls_common",
			"cba_main",
			"cba_xeh",
			"cba_settings",
			"cba_keybinding",
			"ace_ui"
		};
		units[] = {};
		weapons[] = {};
	};
};

class CfgFunctions
{
	class TAE
	{
		class HUD
		{
			file = "\TAEHUD\functions";
			class hudApplyColor {};
			class hudCycleAuxiliary {};
			class hudCycleCameraTarget {};
			class hudDestroyCamera {};
			class hudDrawAuxiliaryMap {};
			class hudHide {};
			class hudInitCompassControls {};
			class hudInitClient {};
			class hudInitSquadControls {};
			class hudMonitor {};
			class hudOnLoad {};
			class hudOnUnload {};
			class hudPublishIdentityColor {};
			class hudShow {};
			class hudSetVanillaStanceInfo {};
			class hudSetVanillaWeaponInfo {};
			class hudToggle {};
			class hudUpdate {};
			class hudUpdateAuxiliary {};
			class hudUpdateCompass {};
			class hudUpdateSquad {};
		};
	};
};

class Extended_PreInit_EventHandlers
{
	class TAEHUD
	{
		init = "call compile preprocessFileLineNumbers '\TAEHUD\XEH_preInit.sqf'";
	};
};

class Extended_PostInit_EventHandlers
{
	class TAEHUD
	{
		init = "call compile preprocessFileLineNumbers '\TAEHUD\XEH_postInit.sqf'";
	};
};

class RscText;
class RscPicture;
class RscMapControl;
class TAE_HUD_CompassLabel: RscText
{
	style = 2;
	shadow = 0;
};

class RscTitles
{
	class RscTAEHelmetHUD
	{
		idd = -1;
		duration = 1e+011;
		fadeIn = 0.15;
		fadeOut = 0.15;
		movingEnable = 0;
		onLoad = "_this call TAE_fnc_hudOnLoad";
		onUnload = "_this call TAE_fnc_hudOnUnload";

		class controlsBackground
		{
			class CompassBackground: RscText
			{
				idc = 1200;
				x = "safeZoneX + (safeZoneW * 0.30)";
				y = "safeZoneY + (safeZoneH * 0.005)";
				w = "safeZoneW * 0.40";
				h = "safeZoneH * 0.078";
				colorBackground[] = {0,0,0,0};
			};
			class CompassLine: RscText
			{
				idc = 1201;
				x = "safeZoneX + (safeZoneW * 0.30)";
				y = "safeZoneY + (safeZoneH * 0.010)";
				w = "safeZoneW * 0.40";
				h = "safeZoneH * 0.003";
				colorBackground[] = {0.95,0.72,0.14,0.90};
			};
			class WeaponBackground: RscText
			{
				idc = 1202;
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.235)";
				y = "safeZoneY + (safeZoneH * 0.025)";
				w = "safeZoneW * 0.215";
				h = "safeZoneH * 0.180";
				colorBackground[] = {0,0,0,0};
			};
			class WeaponLine: RscText
			{
				idc = 1203;
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.235)";
				y = "safeZoneY + (safeZoneH * 0.025)";
				w = "safeZoneW * 0.215";
				h = "safeZoneH * 0.003";
				colorBackground[] = {0.95,0.72,0.14,0.90};
			};
			class UpperLeftAccent: RscText
			{
				idc = 1204;
				x = "safeZoneX + (safeZoneW * 0.02)";
				y = "safeZoneY + (safeZoneH * 0.04)";
				w = "safeZoneW * 0.11";
				h = "safeZoneH * 0.003";
				colorBackground[] = {0.95,0.72,0.14,0.75};
			};
			class LowerLeftAccent: UpperLeftAccent
			{
				idc = 1205;
				y = "safeZoneY + safeZoneH - (safeZoneH * 0.043)";
				w = "safeZoneW * 0.16";
			};
			class AuxiliaryBackground: RscText
			{
				idc = 1300;
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.215)";
				y = "safeZoneY + (safeZoneH * 0.795)";
				w = "safeZoneW * 0.195";
				h = "safeZoneH * 0.190";
				colorBackground[] = {0,0,0,0.42};
			};
			class AuxiliaryLine: RscText
			{
				idc = 1301;
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.215)";
				y = "safeZoneY + (safeZoneH * 0.795)";
				w = "safeZoneW * 0.195";
				h = "safeZoneH * 0.003";
				colorBackground[] = {0.95,0.72,0.14,0.90};
			};
		};

		class controls
		{
			class SystemLabel: RscText
			{
				idc = 1100;
				text = "TAE // VISOR LINK";
				font = "ls_republic";
				sizeEx = "safeZoneH * 0.016";
				shadow = 0;
				colorText[] = {0.95,0.72,0.14,0.90};
				x = "safeZoneX + (safeZoneW * 0.02)";
				y = "safeZoneY + (safeZoneH * 0.012)";
				w = "safeZoneW * 0.145";
				h = "safeZoneH * 0.022";
			};
			class SystemStatus: SystemLabel
			{
				idc = 1101;
				text = "HELMET SYSTEMS ONLINE";
				font = "ls_republic";
				sizeEx = "safeZoneH * 0.010";
				colorText[] = {0.75,0.78,0.80,0.82};
				y = "safeZoneY + (safeZoneH * 0.043)";
			};
			class CompassTicks: RscText
			{
				idc = 1110;
				text = "";
				font = "EtelkaMonospacePro";
				style = 2;
				sizeEx = "safeZoneH * 0.019";
				shadow = 0;
				colorText[] = {0.95,0.72,0.14,0.90};
				x = "safeZoneX + (safeZoneW * 0.31)";
				y = "safeZoneY + (safeZoneH * 0.055)";
				w = "safeZoneW * 0.38";
				h = "safeZoneH * 0.027";
			};
			class CompassHeading: CompassTicks
			{
				idc = 1111;
				text = "000 DEG";
				font = "RobotoCondensedBold";
				sizeEx = "safeZoneH * 0.018";
				y = "safeZoneY + (safeZoneH * 0.025)";
				h = "safeZoneH * 0.024";
			};
			class StanceIndicator: RscPicture
			{
				idc = 1120;
				text = "";
				colorText[] = {0.95,0.72,0.14,0.90};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.225)";
				y = "safeZoneY + (safeZoneH * 0.055)";
				w = "safeZoneW * 0.055";
				h = "safeZoneH * 0.080";
			};
			class WeaponName: RscText
			{
				idc = 1121;
				text = "WEAPON LINK";
				font = "RobotoCondensedBold";
				style = 1;
				sizeEx = "safeZoneH * 0.018";
				shadow = 0;
				colorText[] = {0.95,0.72,0.14,0.90};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.145)";
				y = "safeZoneY + (safeZoneH * 0.040)";
				w = "safeZoneW * 0.125";
				h = "safeZoneH * 0.030";
			};
			class WeaponMode: WeaponName
			{
				idc = 1122;
				text = "SAFE";
				font = "RobotoCondensed";
				sizeEx = "safeZoneH * 0.015";
				colorText[] = {0.75,0.78,0.80,0.86};
				y = "safeZoneY + (safeZoneH * 0.070)";
				h = "safeZoneH * 0.024";
			};
			class LoadedAmmo: WeaponName
			{
				idc = 1123;
				text = "--";
				font = "EtelkaMonospaceProBold";
				sizeEx = "safeZoneH * 0.047";
				y = "safeZoneY + (safeZoneH * 0.095)";
				h = "safeZoneH * 0.055";
			};
			class ReserveAmmo: WeaponName
			{
				idc = 1124;
				text = "0 MAGS // 0 RES";
				font = "EtelkaMonospacePro";
				sizeEx = "safeZoneH * 0.014";
				colorText[] = {0.75,0.78,0.80,0.86};
				y = "safeZoneY + (safeZoneH * 0.150)";
				h = "safeZoneH * 0.022";
			};
			class ThrowableIcon: RscPicture
			{
				idc = 1125;
				text = "";
				colorText[] = {0.95,0.72,0.14,0.90};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.225)";
				y = "safeZoneY + (safeZoneH * 0.180)";
				w = "safeZoneW * 0.016";
				h = "safeZoneH * 0.022";
			};
			class ThrowableName: RscText
			{
				idc = 1126;
				text = "NO THROWABLE";
				font = "RobotoCondensed";
				sizeEx = "safeZoneH * 0.013";
				shadow = 0;
				colorText[] = {0.75,0.78,0.80,0.86};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.205)";
				y = "safeZoneY + (safeZoneH * 0.179)";
				w = "safeZoneW * 0.080";
				h = "safeZoneH * 0.022";
			};
			class SpeedReadout: RscPicture
			{
				idc = 1127;
				text = "";
				colorText[] = {0.75,0.78,0.80,0.86};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.225)";
				y = "safeZoneY + (safeZoneH * 0.136)";
				w = "safeZoneH * 0.052";
				h = "safeZoneH * 0.013";
			};
			class RangeReadout: RscText
			{
				idc = 1128;
				text = "RNG -- M";
				font = "EtelkaMonospacePro";
				sizeEx = "safeZoneH * 0.013";
				shadow = 0;
				colorText[] = {0.75,0.78,0.80,0.86};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.225)";
				y = "safeZoneY + (safeZoneH * 0.153)";
				w = "safeZoneW * 0.075";
				h = "safeZoneH * 0.020";
			};
			class AuxiliaryMap: RscMapControl
			{
				idc = 1302;
				onDraw = "_this call TAE_fnc_hudDrawAuxiliaryMap";
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.210)";
				y = "safeZoneY + (safeZoneH * 0.835)";
				w = "safeZoneW * 0.185";
				h = "safeZoneH * 0.140";
			};
			class AuxiliaryCamera: RscPicture
			{
				idc = 1303;
				text = "#(argb,512,512,1)r2t(TAE_HUD_HELMETCAM,1.0)";
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.210)";
				y = "safeZoneY + (safeZoneH * 0.835)";
				w = "safeZoneW * 0.185";
				h = "safeZoneH * 0.140";
			};
			class AuxiliaryTitle: RscText
			{
				idc = 1304;
				text = "AUXILIARY LINK";
				font = "ls_republic";
				sizeEx = "safeZoneH * 0.013";
				shadow = 0;
				colorText[] = {0.95,0.72,0.14,0.90};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.210)";
				y = "safeZoneY + (safeZoneH * 0.803)";
				w = "safeZoneW * 0.105";
				h = "safeZoneH * 0.025";
			};
			class AuxiliaryStatus: AuxiliaryTitle
			{
				idc = 1305;
				text = "OFFLINE";
				font = "EtelkaMonospacePro";
				style = 1;
				sizeEx = "safeZoneH * 0.011";
				colorText[] = {0.75,0.78,0.80,0.86};
				x = "safeZoneX + safeZoneW - (safeZoneW * 0.105)";
				w = "safeZoneW * 0.080";
			};
		};
	};
};
