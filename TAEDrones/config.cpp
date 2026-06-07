class CfgPatches {
	class TAEDrones {
		name = "TAE Drones";
		author = "TAE Mod Team";
		addonRootClass = "TAECore";
		requiredVersion = 1.60;
		requiredAddons[] = {
			"TAECore",
			"cba_main",
			"cba_xeh",
			"ace_common",
			"ace_interact_menu",
			"TAEUnits_HouseKarr",
			"mti_armoury_drones_blasterturret",
			"mti_armoury_drones_paap",
			"mti_armoury_drones_prowler"
		};
		units[] = {
			"tae_blaster_turret",
			"tae_autonomous_aa_turret",
			"tae_autonomous_at_turret",
			"tae_seeker_droid"
		};
		weapons[] = {
			"tae_blaster_turret_packed",
			"tae_autonomous_aa_turret_packed",
			"tae_autonomous_at_turret_packed",
			"tae_weapon_autonomous_aa",
			"tae_weapon_autonomous_at",
			"tae_seeker_droid_packed"
		};
	};
};

class CfgFunctions {
	class TAEDrones {
		tag = "TAEDrones";

		class functions {
			file = "TAEDrones\functions";
			class initSeekerDroid {};
			class pickUpVehicle {};
			class placeDownVehicle {};
		};
	};
};

class CfgWeapons {
	class CBA_MiscItem_ItemInfo;
	class ACE_ItemCore;
	class MissileLauncher;
	class missiles_titan: MissileLauncher {
		class Player;
	};

	class tae_weapon_autonomous_at: missiles_titan {
		author = "TAE Mod Team";
		displayName = "Autonomous AT Launcher";
		magazines[] = {"mti_armoury_mag_patp"};
		modes[] = {"Player"};
		weaponLockDelay = 4;
		magazineReloadTime = 3;
		aiRateOfFire = 8;
		aiRateOfFireDistance = 2000;

		class Player: Player {
			reloadTime = 3;
		};
	};

	class tae_weapon_autonomous_aa: missiles_titan {
		author = "TAE Mod Team";
		displayName = "Autonomous AA Launcher";
		magazines[] = {"mti_armoury_mag_paap"};
		modes[] = {"Player"};
		weaponLockDelay = 4;
		magazineReloadTime = 3;
		aiRateOfFire = 8;
		aiRateOfFireDistance = 2000;

		class Player: Player {
			reloadTime = 3;
		};
	};

	class tae_blaster_turret_packed: ACE_ItemCore {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Blaster Turret (Packed)";
		descriptionShort = "Blaster Turret (Packed)";
		picture = "\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
		model = "3AS\3AS_Static\BlasterTurret\Model\BlasterTurret.p3d";

		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 80;
		};
	};

	class tae_autonomous_aa_turret_packed: ACE_ItemCore {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Autonomous AA Turret (Packed)";
		descriptionShort = "Autonomous AA Turret (Packed)";
		picture = "\z\mti_armoury\addons\drones\paap\data\ui\paap_ca.paa";
		model = "\z\mti_armoury\addons\drones\paap\paap_packed.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\z\mti_armoury\addons\drones\paap\data\paap\camo1_co.paa"};

		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 80;
		};
	};

	class tae_autonomous_at_turret_packed: tae_autonomous_aa_turret_packed {
		author = "TAE Mod Team";
		displayName = "Autonomous AT Turret (Packed)";
		descriptionShort = "Autonomous AT Turret (Packed)";
		hiddenSelectionsTextures[] = {"\z\mti_armoury\addons\drones\paap\data\patp\camo1_co.paa"};
	};

	class tae_seeker_droid_packed: ACE_ItemCore {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Seeker Droid (Packed)";
		descriptionShort = "Seeker Droid packed for carriage";
		picture = "\MRC\JLTS\drones\prowler1000\data\ui\map_prowler_ca.paa";
		model = "\MRC\JLTS\drones\prowler1000\prowler.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"3as\3as_Drones\UAS2\data\recondrone_CO.paa"};

		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 80;
		};
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Drones {
		displayName = "Drones";
	};
};

class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Equipment {
				class TAE_Deploy_SeekerDroid {
					displayName = "Deploy Seeker Droid";
					condition = "[_player, 'tae_seeker_droid_packed'] call ace_common_fnc_hasItem";
					statement = "[_player, 'tae_seeker_droid', 'tae_seeker_droid_packed'] call TAEDrones_fnc_placeDownVehicle";
					showDisabled = 0;
					icon = "\MRC\JLTS\drones\prowler1000\data\ui\map_prowler_ca.paa";
				};
				class TAE_Deploy_BlasterTurret {
					displayName = "Deploy Blaster Turret";
					condition = "[_player, 'tae_blaster_turret_packed'] call ace_common_fnc_hasItem";
					statement = "[_player, 'tae_blaster_turret', 'tae_blaster_turret_packed'] call TAEDrones_fnc_placeDownVehicle";
					showDisabled = 0;
					icon = "\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
				};
				class TAE_Deploy_AutonomousAATurret {
					displayName = "Deploy Autonomous AA Turret";
					condition = "[_player, 'tae_autonomous_aa_turret_packed'] call ace_common_fnc_hasItem";
					statement = "[_player, 'tae_autonomous_aa_turret', 'tae_autonomous_aa_turret_packed'] call TAEDrones_fnc_placeDownVehicle";
					showDisabled = 0;
					icon = "\z\mti_armoury\addons\drones\paap\data\ui\paap_ca.paa";
				};
				class TAE_Deploy_AutonomousATTurret {
					displayName = "Deploy Autonomous AT Turret";
					condition = "[_player, 'tae_autonomous_at_turret_packed'] call ace_common_fnc_hasItem";
					statement = "[_player, 'tae_autonomous_at_turret', 'tae_autonomous_at_turret_packed'] call TAEDrones_fnc_placeDownVehicle";
					showDisabled = 0;
					icon = "\z\mti_armoury\addons\drones\paap\data\ui\paap_ca.paa";
				};
			};
		};
	};

	class I_UAV_AI;
	class tae_seeker_droid_ai: I_UAV_AI {
		scope = 1;
		scopeCurator = 0;
		author = "TAE Mod Team";
		displayName = "Seeker Droid AI";
	};

	class tae_autonomous_turret_ai: I_UAV_AI {
		scope = 1;
		scopeCurator = 0;
		author = "TAE Mod Team";
		displayName = "Autonomous Turret Droid";
	};

	class mti_armoury_drones_blasterturret_base;
	class mti_armoury_drones_paap_aa;
	class mti_armoury_drones_paap_at;
	class mti_armoury_drones_prowler_1500;

	class tae_blaster_turret: mti_armoury_drones_blasterturret_base {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Blaster Turret";
		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Drones";
		crew = "tae_autonomous_turret_ai";
		typicalCargo[] = {"tae_autonomous_turret_ai"};
		mti_drones_packsTo = "tae_blaster_turret_packed";
	};

	class tae_autonomous_aa_turret: mti_armoury_drones_paap_aa {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Autonomous AA Turret";
		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Drones";
		crew = "tae_autonomous_turret_ai";
		typicalCargo[] = {"tae_autonomous_turret_ai"};
		mti_drones_packsTo = "tae_autonomous_aa_turret_packed";
	};

	class tae_autonomous_at_turret: mti_armoury_drones_paap_at {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Autonomous AT Turret";
		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Drones";
		crew = "tae_autonomous_turret_ai";
		typicalCargo[] = {"tae_autonomous_turret_ai"};
		mti_drones_packsTo = "tae_autonomous_at_turret_packed";
	};

	class tae_seeker_droid: mti_armoury_drones_prowler_1500 {
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		author = "TAE Mod Team";
		displayName = "Seeker Droid";
		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Drones";
		crew = "tae_seeker_droid_ai";
		typicalCargo[] = {"tae_seeker_droid_ai"};

		altFullForce = 2500;
		altNoForce = 2600;
		fuelCapacity = 200;
		weapons[] = {};
		magazines[] = {};
		mti_drones_packsTo = "";

		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			displayName = "";
			dissasembleTo[] = {};
		};
	};
};

class Extended_Init_EventHandlers {
	class tae_blaster_turret {
		class TAEDrones_PickUpAction {
			init = "params ['_vehicle']; [_vehicle, 'Blaster Turret'] call TAEDrones_fnc_initSeekerDroid; private _action = ['TAE_PickUp_BlasterTurret', 'Pick Up Blaster Turret', '', {params ['_target', '_player']; [_player, _target, 'tae_blaster_turret_packed'] call TAEDrones_fnc_pickUpVehicle;}, {alive _target}] call ace_interact_menu_fnc_createAction; [_vehicle, 0, ['ACE_MainActions'], _action] call ace_interact_menu_fnc_addActionToObject;";
		};
	};
	class tae_autonomous_aa_turret {
		class TAEDrones_PickUpAction {
			init = "params ['_vehicle']; [_vehicle, 'Autonomous AA Turret', 'tae_weapon_autonomous_aa', 'mti_armoury_mag_paap'] call TAEDrones_fnc_initSeekerDroid; private _action = ['TAE_PickUp_AutonomousAATurret', 'Pick Up Autonomous AA Turret', '', {params ['_target', '_player']; [_player, _target, 'tae_autonomous_aa_turret_packed'] call TAEDrones_fnc_pickUpVehicle;}, {alive _target}] call ace_interact_menu_fnc_createAction; [_vehicle, 0, ['ACE_MainActions'], _action] call ace_interact_menu_fnc_addActionToObject;";
		};
	};
	class tae_autonomous_at_turret {
		class TAEDrones_PickUpAction {
			init = "params ['_vehicle']; [_vehicle, 'Autonomous AT Turret', 'tae_weapon_autonomous_at', 'mti_armoury_mag_patp'] call TAEDrones_fnc_initSeekerDroid; private _action = ['TAE_PickUp_AutonomousATTurret', 'Pick Up Autonomous AT Turret', '', {params ['_target', '_player']; [_player, _target, 'tae_autonomous_at_turret_packed'] call TAEDrones_fnc_pickUpVehicle;}, {alive _target}] call ace_interact_menu_fnc_createAction; [_vehicle, 0, ['ACE_MainActions'], _action] call ace_interact_menu_fnc_addActionToObject;";
		};
	};
	class tae_seeker_droid {
		class TAEDrones_PickUpAction {
			init = "params ['_vehicle']; [_vehicle] call TAEDrones_fnc_initSeekerDroid; private _action = ['TAE_PickUp_SeekerDroid', 'Pick Up Seeker Droid', '', {params ['_target', '_player']; [_player, _target, 'tae_seeker_droid_packed'] call TAEDrones_fnc_pickUpVehicle;}, {alive _target}] call ace_interact_menu_fnc_createAction; [_vehicle, 0, ['ACE_MainActions'], _action] call ace_interact_menu_fnc_addActionToObject;";
		};
	};
};
