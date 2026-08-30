#define TAE_SPLASH_ONLOAD onLoad = "private _screen = uiNamespace getVariable ['TAE_sessionSplash','']; if (_screen isEqualTo '') then {_screen = selectRandom ['\TAECore\textures\screen.paa','\TAECore\textures\screen2.paa']; uiNamespace setVariable ['TAE_sessionSplash',_screen];}; (_this select 0) ctrlSetText _screen;"
// Release version: MAJOR.MINOR.FEATURE.REVISION
// MAJOR: breaking compatibility or dependency restructuring.
// MINOR: a new PBO or major subsystem; reset FEATURE and REVISION to 0.
// FEATURE: substantial content in an existing PBO, such as a new vehicle, faction, or system; reset REVISION to 0.
// REVISION: routine arsenal, texture, armor, helmet, balance, and config updates.
#define TAE_VERSION 1.2
#define TAE_VERSION_STR "1.2.0.1"
#define TAE_VERSION_AR 1,2,0,1

class CfgPatches
{
	class TAECore
	{
		// Meta information for editor
		name = "The Ashen Enclave AUX Mod";
		author = "TAE Mod Team";
		url = "https://discord.gg/9zgGp5QSW7";
		version = TAE_VERSION;
		versionStr = TAE_VERSION_STR;
		versionAr[] = {TAE_VERSION_AR};

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game. Note: was disabled on purpose some time late into Arma 2: OA.
		requiredVersion = 1.60;
		// Required addons, used for setting load order. (CfgPatches classname NOT PBO filename!)
		// When any of the addons are missing, a pop-up warning will appear when launching the game.
		requiredAddons[] = { "A3_Data_F_Decade_Loadorder" };
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content (units and groups) unlocking.
		units[] = {};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {};

		// Optional. If this is 1, if any of requiredAddons[] entry is missing in your game the entire config will be ignored and return no error (but in rpt) so useful to make a compat Mod (Since Arma 3 2.14)
		skipWhenMissingDependencies = 1;
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class TAE
			{
				main_addon = "TAECore";
			};
		};
	};
};
class CfgFunctions
{
	class TAE
	{
		class Core
		{
			file = "\TAECore\functions";
			class addQuartermasterDiary {};
			class initQuartermasterDiary
			{
				postInit = 1;
			};
		};
	};
};
class CfgMods
{
	class Mod_Base;
	class TAE_Core: Mod_Base
	{
		logo = "TAECore\textures\logo.paa";
		picture = "TAECore\textures\logo.paa";
		name = "The Ashen Enclave AUX Mod";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class TAE_Core
		{
			list[] = {"TAECore"};
		};
	};
};
class CfgEditorCategories
{
	class TAE_AUX_EdCat
	{
		displayName = "The Ashen Enclave";
	};
};
class CfgEditorSubcategories
{
	class TAE_EdSubCat_Mandalorian
	{
		displayName = "Mandalorians";
	};
};
class cfgFactionClasses
{
	class TAE_Faction
	{
		displayName = "The Ashen Enclave";
		priority = 1;
		side = 1;
		icon = "";
	};
};
class RscPicture{};
class RscActiveText{};
class RscActivePicture: RscActiveText{};
class RscText{};
class RscStandardDisplay{};
class RscDisplayMain: RscStandardDisplay
{
	class Controls
	{
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		class Logo: RscActivePicture
		{
			text="\TAECore\textures\logo.paa";
		};
	};
	enableDisplay=0;
	delete Spotlight;
	class RscActiveText;
	class RscActivePicture: RscActiveText
	{
		style=48;
		color[]={1,1,1,0.5};
		colorActive[]={1,1,1,1};
	};
	class controlsBackground
	{
		class LoadingPic: RscPicture
		{
			idc=1;
			TAE_SPLASH_ONLOAD
			x="SafeZoneX";
			y="SafeZoneY";
			h="SafeZoneH";
			w="SafeZoneW";
			text="\TAECore\textures\screen.paa";
		};
	};
};
class RscDisplayLoading
{
	class Variants
	{
		class LoadingOne
		{
			idd=250;
			class controls
			{
				class LoadingPic: RscPicture
				{
					idc=1;
					TAE_SPLASH_ONLOAD
					x="SafeZoneX";
					y="SafeZoneY";
					h="SafeZoneH";
					w="SafeZoneW";
					text="\TAECore\textures\screen.paa";
				};
			};
		};
		class Loading_West1: LoadingOne
		{
			class controls
			{
				class LoadingPic
				{
					idc=1;
					x="SafeZoneX";
					y="SafeZoneY";
					h="SafeZoneH";
					w="SafeZoneW";
					text="\TAECore\textures\screen.paa";
				};
			};
		};
		class Loading_West2: LoadingOne
		{
			class controls
			{
				class LoadingPic
				{
					idc=1;
					x="SafeZoneX";
					y="SafeZoneY";
					h="SafeZoneH";
					w="SafeZoneW";
					text="\TAECore\textures\screen.paa";
				};
			};
		};
		class Loading_East1: LoadingOne
		{
			class controls
			{
				class LoadingPic
				{
					idc=1;
					x="SafeZoneX";
					y="SafeZoneY";
					h="SafeZoneH";
					w="SafeZoneW";
					text="\TAECore\textures\screen.paa";
				};
			};
		};
		class Loading_East2: LoadingOne
		{
			class controls
			{
				class LoadingPic
				{
					idc=1;
					x="SafeZoneX";
					y="SafeZoneY";
					h="SafeZoneH";
					w="SafeZoneW";
					text="\TAECore\textures\screen.paa";
				};
			};
		};
	};
};
class RscDisplayLoadMission: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPicture
		{
			idc=1;
			TAE_SPLASH_ONLOAD
			x="SafeZoneX";
			y="SafeZoneY";
			h="SafeZoneH";
			w="SafeZoneW";
			text="\TAECore\textures\screen.paa";
		};
	};
};
class RscDisplayStart: RscStandardDisplay
{
	class controls
	{
		class LoadingPic: RscPicture
		{
			idc=1;
			TAE_SPLASH_ONLOAD
			x="SafeZoneX";
			y="SafeZoneY";
			h="SafeZoneH";
			w="SafeZoneW";
			text="\TAECore\textures\screen.paa";
		};
	};
};
class RscDisplayMPPlayers;
class RscDisplayClientWait: RscDisplayMPPlayers
{
	class LoadingPic: RscPicture
	{
		idc=1;
		TAE_SPLASH_ONLOAD
		x="SafeZoneX";
		y="SafeZoneY";
		h="SafeZoneH";
		w="SafeZoneW";
		text="\TAECore\textures\screen.paa";
	};
};
class RscDisplayClient: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPicture
		{
			idc=1;
			TAE_SPLASH_ONLOAD
			x="SafeZoneX";
			y="SafeZoneY";
			h="SafeZoneH";
			w="SafeZoneW";
			text="\TAECore\textures\screen.paa";
		};
	};
};
