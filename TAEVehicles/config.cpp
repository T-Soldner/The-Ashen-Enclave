class CfgPatches {
	class TAEVehicles {
		name = "TAE Vehicles";
		author = "TAE Mod Team";
		requiredAddons[] = {
			"A3_Data_F_Loadorder",
			"ace_cargo",
			"ace_missileguidance",
			"KND_Komrk",
			"knd_vehicles_skycat",
			"TAEObjects",
			"TAEUnits_HouseKarr",
			"mti_armoury_vehicles_weapons",
			"ls_vehicles_z98",
			"knd_jdumb"
		};
		units[] = {
			"TAE_KomrkFighter_Transport",
			"TAE_Skycat_Transport",
			"TAE_Z98_Headhunter"
		};
		weapons[] = {
			"TAE_Skycat_weapon_MPR10",
			"TAE_Skycat_weapon_Talon",
			"TAE_Skycat_weapon_Firebrand",
			"TAE_Skycat_weapon_Wraith",
			"TAE_Komrk_weapon_Lightning",
			"TAE_Komrk_weapon_Typhoon",
			"TAE_Komrk_weapon_Hurricane",
			"TAE_Komrk_weapon_Stalkers",
			"TAE_Komrk_weapon_Hammers",
			"TAE_Z98_weapon_Lightning",
			"TAE_Z98_weapon_Typhoon",
			"TAE_Z98_weapon_Hurricane",
			"TAE_Z98_weapon_Hammers",
			"TAE_Z98_weapon_Stalkers",
			"TAE_Z98_weapon_DB78"
		};
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Aircraft {
		displayName = "Aircraft";
	};
};

class CfgFunctions {
	class TAE {
		class Vehicles {
			file = "\TAEVehicles\functions";
			class boardRecoveredPlayer {};
			class recoverAirbornePlayers {};
			class showRecoveryMessage {};
		};
	};
};

class CfgWeapons {
	class mti_armoury_weapon_AA_Missile_Light_Pylon;
	class mti_armoury_weapon_AA_Short_Missile_Pylon;
	class mti_armoury_weapon_AA_Long_Missile_Pylon;
	class mti_armoury_weapon_AGM_Missile_Pylon;
	class mti_armoury_weapon_Harm_Missile_Pylon;
	class ace_missileguidance_dagr;
	class knd_pylonweapon_jdumb;

	class TAE_Skycat_weapon_MPR10: ace_missileguidance_dagr {
		displayName = "MPR-10 Guided Proton Rockets";
		displayNameShort = "MPR-10";
		magazines[] = {
			"TAE_Skycat_mag_MPR10"
		};
	};

	class TAE_Komrk_weapon_Hammers: mti_armoury_weapon_AGM_Missile_Pylon {
		displayName = "Firebrand Proton Missile";
		displayNameShort = "Firebrand";
		magazines[] = {
			"TAE_Komrk_mag_Hammers"
		};
	};

	class TAE_Komrk_weapon_Lightning: mti_armoury_weapon_AA_Missile_Light_Pylon {
		displayName = "Talon Interceptor";
		displayNameShort = "Talon";
		magazines[] = {
			"TAE_Komrk_mag_Lightning"
		};
	};

	class TAE_Komrk_weapon_Typhoon: mti_armoury_weapon_AA_Short_Missile_Pylon {
		displayName = "Pursuit Concussion Missile";
		displayNameShort = "Pursuit";
		magazines[] = {
			"TAE_Komrk_mag_Typhoon"
		};
	};

	class TAE_Komrk_weapon_Hurricane: mti_armoury_weapon_AA_Long_Missile_Pylon {
		displayName = "Longspear Missile";
		displayNameShort = "Longspear";
		magazines[] = {
			"TAE_Komrk_mag_Hurricane"
		};
	};

	class TAE_Komrk_weapon_Stalkers: mti_armoury_weapon_Harm_Missile_Pylon {
		displayName = "Wraith Anti-Radiation Missile";
		displayNameShort = "Wraith";
		magazines[] = {
			"TAE_Komrk_mag_Stalkers"
		};
	};

	class TAE_Skycat_weapon_Talon: TAE_Komrk_weapon_Lightning {
		magazines[] = {
			"TAE_Skycat_mag_Talon"
		};
	};

	class TAE_Skycat_weapon_Firebrand: TAE_Komrk_weapon_Hammers {
		magazines[] = {
			"TAE_Skycat_mag_Firebrand"
		};
	};

	class TAE_Skycat_weapon_Wraith: TAE_Komrk_weapon_Stalkers {
		magazines[] = {
			"TAE_Skycat_mag_Wraith"
		};
	};

	class TAE_Z98_weapon_Lightning: mti_armoury_weapon_AA_Missile_Light_Pylon {
		displayName = "Talon Interceptor";
		displayNameShort = "Talon";
		magazines[] = {
			"TAE_Z98_mag_Lightning"
		};
	};

	class TAE_Z98_weapon_Typhoon: mti_armoury_weapon_AA_Short_Missile_Pylon {
		displayName = "Pursuit Concussion Missile";
		displayNameShort = "Pursuit";
		magazines[] = {
			"TAE_Z98_mag_Typhoon"
		};
	};

	class TAE_Z98_weapon_Hurricane: mti_armoury_weapon_AA_Long_Missile_Pylon {
		displayName = "Longspear Missile";
		displayNameShort = "Longspear";
		magazines[] = {
			"TAE_Z98_mag_Hurricane"
		};
	};

	class TAE_Z98_weapon_Hammers: mti_armoury_weapon_AGM_Missile_Pylon {
		displayName = "Firebrand Proton Missile";
		displayNameShort = "Firebrand";
		magazines[] = {
			"TAE_Z98_mag_Hammers"
		};
	};

	class TAE_Z98_weapon_Stalkers: mti_armoury_weapon_Harm_Missile_Pylon {
		displayName = "Wraith Anti-Radiation Missile";
		displayNameShort = "Wraith";
		magazines[] = {
			"TAE_Z98_mag_Stalkers"
		};
	};

	class TAE_Z98_weapon_DB78: knd_pylonweapon_jdumb {
		displayName = "DB-78 Seismic Bomb";
		displayNameShort = "Seismic Bomb";
		magazines[] = {
			"TAE_Z98_mag_DB78"
		};
	};
};
class CfgAmmo {
	class ACE_Hydra70_DAGR;
	class mti_armoury_ammo_AGM_Missile;

	class TAE_Skycat_ammo_MPR10: ACE_Hydra70_DAGR {
		displayName = "MPR-10 Guided Proton Rocket";
		displayNameShort = "MPR-10";
	};

	class TAE_Firebrand_ammo_IRLaser: mti_armoury_ammo_AGM_Missile {
		missileLockMaxDistance = 5000;
	};

	class TAE_Z98_ammo_Hammers: mti_armoury_ammo_AGM_Missile {
		irLock = 1;
		laserLock = 0;
		airLock = 0;
		nvLock = 1;
		weaponLockSystem = 2 + 16;

		missileLockCone = 90;
		missileKeepLockedCone = 120;
		missileLockMaxDistance = 5000;
		missileLockMinDistance = 100;
	};
};

class CfgMagazines {
	class mti_armoury_mag_AA_Light_Mag;
	class mti_armoury_mag_AA_Short_Mag;
	class mti_armoury_mag_AA_Long_Mag;
	class mti_armoury_mag_AGM_Mag;
	class mti_armoury_mag_HARM_Missile_Mag;
	class PylonRack_24Rnd_ACE_DAGR;
	class knd_pylonrack_jdumb;

	class TAE_Skycat_mag_MPR10: PylonRack_24Rnd_ACE_DAGR {
		displayName = "MPR-10 Guided Proton Rockets (10-Round)";
		displayNameShort = "MPR-10 (10)";
		descriptionShort = "Ten guided proton rockets for precision attacks against vehicles and hardened ground targets.";
		ammo = "TAE_Skycat_ammo_MPR10";
		count = 10;
		hardpoints[] = {
			"TAE_SKYCAT_HP_MPR10"
		};
		pylonWeapon = "TAE_Skycat_weapon_MPR10";
	};

	class TAE_Komrk_mag_Hammers: mti_armoury_mag_AGM_Mag {
		displayName = "Firebrand Proton Missile (3-Round)";
		displayNameShort = "Firebrand (3)";
		descriptionShort = "Firebrand is an infrared- and laser-guided proton missile for air-to-ground strikes, with a maximum lock range of 5 kilometers.";
		ammo = "TAE_Firebrand_ammo_IRLaser";
		count = 3;
		hardpoints[] = {
			"TAE_KOMRK_HP_HAMMERS"
		};
		pylonWeapon = "TAE_Komrk_weapon_Hammers";
	};

	class TAE_Komrk_mag_Lightning: mti_armoury_mag_AA_Light_Mag {
		displayName = "Talon Interceptor (3-Round)";
		displayNameShort = "Talon (3)";
		descriptionShort = "Talon is a short-range anti-air interceptor missile with a maximum lock range of 1.5 kilometers.";
		count = 3;
		hardpoints[] = {
			"TAE_KOMRK_HP_AA"
		};
		pylonWeapon = "TAE_Komrk_weapon_Lightning";
	};

	class TAE_Komrk_mag_Typhoon: mti_armoury_mag_AA_Short_Mag {
		displayName = "Pursuit Concussion (3-Round)";
		displayNameShort = "Pursuit (3)";
		descriptionShort = "Pursuit is a medium-range concussion missile for general anti-air engagements, with a maximum lock range of 6 kilometers.";
		count = 3;
		hardpoints[] = {
			"TAE_KOMRK_HP_AA"
		};
		pylonWeapon = "TAE_Komrk_weapon_Typhoon";
	};

	class TAE_Komrk_mag_Hurricane: mti_armoury_mag_AA_Long_Mag {
		displayName = "Longspear (3-Round)";
		displayNameShort = "Longspear (3)";
		descriptionShort = "Longspear is a long-range anti-air missile intended to engage distant aircraft.";
		count = 3;
		hardpoints[] = {
			"TAE_KOMRK_HP_AA"
		};
		pylonWeapon = "TAE_Komrk_weapon_Hurricane";
	};

	class TAE_Komrk_mag_Stalkers: mti_armoury_mag_HARM_Missile_Mag {
		displayName = "Wraith Anti-Radiation (3-Round)";
		displayNameShort = "Wraith (3)";
		descriptionShort = "Wraith is an anti-radiation missile designed to engage active emitters.";
		count = 3;
		hardpoints[] = {
			"TAE_KOMRK_HP_STALKERS"
		};
		pylonWeapon = "TAE_Komrk_weapon_Stalkers";
	};

	class TAE_Skycat_mag_Talon: TAE_Komrk_mag_Lightning {
		hardpoints[] = {
			"TAE_SKYCAT_HP_TALON"
		};
		pylonWeapon = "TAE_Skycat_weapon_Talon";
	};

	class TAE_Skycat_mag_Firebrand: TAE_Komrk_mag_Hammers {
		hardpoints[] = {
			"TAE_SKYCAT_HP_FIREBRAND"
		};
		pylonWeapon = "TAE_Skycat_weapon_Firebrand";
	};

	class TAE_Skycat_mag_Wraith: TAE_Komrk_mag_Stalkers {
		hardpoints[] = {
			"TAE_SKYCAT_HP_WRAITH"
		};
		pylonWeapon = "TAE_Skycat_weapon_Wraith";
	};

	class TAE_Z98_mag_Lightning: mti_armoury_mag_AA_Light_Mag {
		displayName = "Talon Interceptor (3-Round)";
		displayNameShort = "Talon (3)";
		descriptionShort = "Talon is a short-range anti-air interceptor missile with a maximum lock range of 1.5 kilometers.";
		count = 3;
		hardpoints[] = {
			"TAE_Z98_HP_OUTER_AA"
		};
		pylonWeapon = "TAE_Z98_weapon_Lightning";
	};

	class TAE_Z98_mag_Typhoon: mti_armoury_mag_AA_Short_Mag {
		displayName = "Pursuit Concussion (3-Round)";
		displayNameShort = "Pursuit (3)";
		descriptionShort = "Pursuit is a medium-range concussion missile for general anti-air engagements, with a maximum lock range of 6 kilometers.";
		count = 3;
		hardpoints[] = {
			"TAE_Z98_HP_OUTER_AA",
			"TAE_Z98_HP_MIDDLE"
		};
		pylonWeapon = "TAE_Z98_weapon_Typhoon";
	};

	class TAE_Z98_mag_Hurricane: mti_armoury_mag_AA_Long_Mag {
		displayName = "Longspear (3-Round)";
		displayNameShort = "Longspear (3)";
		descriptionShort = "Longspear is a long-range anti-air missile intended to engage distant aircraft.";
		count = 3;
		hardpoints[] = {
			"TAE_Z98_HP_MIDDLE",
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Hurricane";
	};

	class TAE_Z98_mag_Hammers: mti_armoury_mag_AGM_Mag {
		displayName = "Firebrand Proton Missile (3-Round)";
		displayNameShort = "Firebrand (3)";
		descriptionShort = "Firebrand is an infrared- and visual-guided proton missile for air-to-ground strikes, with a maximum lock range of 5 kilometers.";
		ammo = "TAE_Z98_ammo_Hammers";
		count = 3;
		hardpoints[] = {
			"TAE_Z98_HP_MIDDLE",
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Hammers";
	};

	class TAE_Z98_mag_Stalkers: mti_armoury_mag_HARM_Missile_Mag {
		displayName = "Wraith Anti-Radiation (3-Round)";
		displayNameShort = "Wraith (3)";
		descriptionShort = "Wraith is an anti-radiation missile designed to engage active emitters.";
		count = 3;
		hardpoints[] = {
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Stalkers";
	};

	class TAE_Z98_mag_DB78: knd_pylonrack_jdumb {
		displayName = "DB-78 Seismic Bomb";
		displayNameShort = "Seismic Bomb";
		hardpoints[] = {
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_DB78";
	};
};

class SensorTemplateActiveRadar;
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

class CfgVehicles {
	class Helicopter_Base_H;
	class knd_KomrkFighter_VTOL_Dynamic_F;
	class knd_vehicles_skycat: Helicopter_Base_H {
		class Components;
	};
	class ls_vehicle_z98;

	class TAE_KomrkFighter_Transport_base: knd_KomrkFighter_VTOL_Dynamic_F {
		scope = 0;
		scopeCurator = 0;
		vtol = 4;
		lockDetectionSystem = 30;
		incomingMissileDetectionSystem = 26;
		radarTargetSize = 0.6;
		visualTargetSize = 1;
		irTargetSize = 0.8;
		tf_hasLRradio = 1;
		tf_range = 100000;
	};

	class TAE_KomrkFighter_Transport: TAE_KomrkFighter_Transport_base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Kom'rk-Class Fighter Transport";
		author = "TAE Mod Team";

		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Aircraft";

		crew = "TAE_Unit_Pilot";
		typicalCargo[] = {
			"TAE_Unit_Pilot"
		};

		ace_cargo_hasCargo = 1;
		ace_cargo_space = 8;

		hiddenSelections[] = {
			"camo1",
			"body",
			"r2",
			"r4",
			"r5",
			"r6",
			"r7",
			"e7",
			"ball_body",
			"ball_panel1",
			"ball_panel2",
			"bb2",
			"bb3",
			"bb8",
			"bb9",
			"cb23",
			"camo2",
			"camo3"
		};

		hiddenSelectionsTextures[] = {
			"TAEVehicles\data\komrk\base_fore_co.paa",
			"knd_astromechs\tx\newrepublic\chassis\chassis_co.paa",
			"",
			"",
			"",
			"",
			"",
			"knd_astromechs\tx\newrepublic\e7\e7_co.paa",
			"knd_astromechs\tx\bb2\camo1_co.paa",
			"",
			"knd_astromechs\tx\bb2\camo3_co.paa",
			"knd_astromechs\tx\bb2\bb2_co.paa",
			"",
			"",
			"",
			"",
			"TAEVehicles\data\komrk\base_aft_co.paa",
			"TAEVehicles\data\komrk\base_wing_co.paa"
		};

		class TextureSources {
			class base {
				displayName = "Base";
				author = "TAE Mod Team";
				textures[] = {
					"TAEVehicles\data\komrk\base_fore_co.paa",
					"knd_astromechs\tx\newrepublic\chassis\chassis_co.paa",
					"",
					"",
					"",
					"",
					"",
					"knd_astromechs\tx\newrepublic\e7\e7_co.paa",
					"knd_astromechs\tx\bb2\camo1_co.paa",
					"",
					"knd_astromechs\tx\bb2\camo3_co.paa",
					"knd_astromechs\tx\bb2\bb2_co.paa",
					"",
					"",
					"",
					"",
					"TAEVehicles\data\komrk\base_aft_co.paa",
					"TAEVehicles\data\komrk\base_wing_co.paa"
				};
				factions[] = {};
			};
		};

		textureList[] = {
			"base", 1
		};

		class Components {
			class TransportCountermeasuresComponent {};

			class TransportPylonsComponent {
				UIPicture = "\knd_vehicles_komrk\tx\3den_CA.paa";

				class pylons {
					class pylon1 {
						hardpoints[] = {};
						attachment = "";
						priority = 1;
						maxweight = 0;
						UIposition[] = {0.35,0.25};
						bay = 1;
					};

					class pylon2 {
						hardpoints[] = {
							"TAE_KOMRK_HP_AA"
						};
						attachment = "TAE_Komrk_mag_Typhoon";
						priority = 2;
						maxweight = 2500;
						UIposition[] = {0.45,0.15};
					};

					class pylon3: pylon2 {
						priority = 3;
						UIposition[] = {0.20,0.15};
						mirroredMissilePos = 2;
					};

					class pylon4 {
						hardpoints[] = {
							"TAE_KOMRK_HP_HAMMERS"
						};
						attachment = "";
						priority = 4;
						maxweight = 5000;
						UIposition[] = {0.55,0.40};
					};

					class Pylon5: pylon4 {
						priority = 5;
						UIposition[] = {0.10,0.40};
						mirroredMissilePos = 4;
					};

					class Pylon6 {
						hardpoints[] = {
							"TAE_KOMRK_HP_STALKERS",
							"TAE_KOMRK_HP_HAMMERS"
						};
						attachment = "TAE_Komrk_mag_Stalkers";
						priority = 6;
						maxweight = 2500;
						UIposition[] = {0.60,0.45};
					};

					class Pylon7: Pylon6 {
						priority = 7;
						UIposition[] = {0.05,0.45};
						mirroredMissilePos = 6;
					};

					class Pylon8 {
						hardpoints[] = {
							"TAE_KOMRK_HP_HAMMERS"
						};
						attachment = "TAE_Komrk_mag_Hammers";
						priority = 8;
						maxweight = 2500;
						UIposition[] = {0.50,0.55};
					};

					class Pylon9: Pylon8 {
						priority = 9;
						UIposition[] = {0.15,0.55};
						mirroredMissilePos = 8;
					};
				};

				class presets {
					class empty {
						displayName = "Empty";
						attachment[] = {};
					};

					class Default {
						displayName = "House Karr Default";
						attachment[] = {
							"",
							"TAE_Komrk_mag_Typhoon",
							"TAE_Komrk_mag_Typhoon",
							"",
							"",
							"TAE_Komrk_mag_Stalkers",
							"TAE_Komrk_mag_Stalkers",
							"TAE_Komrk_mag_Hammers",
							"TAE_Komrk_mag_Hammers"
						};
					};

					class Typhoon {
						displayName = "Pursuit";
						attachment[] = {
							"",
							"TAE_Komrk_mag_Typhoon",
							"TAE_Komrk_mag_Typhoon",
							"",
							"",
							"",
							"",
							"",
							""
						};
					};

					class Stalkers {
						displayName = "Wraith";
						attachment[] = {
							"",
							"",
							"",
							"",
							"",
							"TAE_Komrk_mag_Stalkers",
							"TAE_Komrk_mag_Stalkers",
							"",
							""
						};
					};

					class Hammers {
						displayName = "Firebrand";
						attachment[] = {
							"",
							"",
							"",
							"",
							"",
							"",
							"",
							"TAE_Komrk_mag_Hammers",
							"TAE_Komrk_mag_Hammers"
						};
					};

					class GroundAttack {
						displayName = "Ground Attack";
						attachment[] = {
							"",
							"TAE_Komrk_mag_Typhoon",
							"TAE_Komrk_mag_Typhoon",
							"",
							"",
							"",
							"",
							"TAE_Komrk_mag_Hammers",
							"TAE_Komrk_mag_Hammers"
						};
					};

					class SEAD {
						displayName = "SEAD";
						attachment[] = {
							"",
							"TAE_Komrk_mag_Typhoon",
							"TAE_Komrk_mag_Typhoon",
							"",
							"",
							"TAE_Komrk_mag_Stalkers",
							"TAE_Komrk_mag_Stalkers",
							"",
							""
						};
					};
				};
				class bays {
					class BayCenter {
						bayOpenTime = 1;
						openBayWhenWeaponSelected = 1;
						autoCloseWhenEmptyDelay = 2;
					};
				};
			};

			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
				componentType = "VehicleSystemsDisplayManager";
				left = 1;
				defaultDisplay = "EmptyDisplay";

				class Components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};

					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {5000, 10000};
						resource = "RscCustomInfoSensors";
					};
				};
			};

			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
				componentType = "VehicleSystemsDisplayManager";
				right = 1;
				defaultDisplay = "SensorDisplay";

				class Components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};

					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {5000, 10000};
						resource = "RscCustomInfoSensors";
					};
				};
			};

			class SensorsManagerComponent {
				class Components {
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
						class AirTarget {
							minRange = 0;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};

						class GroundTarget {
							minRange = 0;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
					};
				};
			};
		};

		class UserActions {
			class RecoverAirbornePlayers {
				displayName = "Recover Airborne Personnel";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				showWindow = 0;
				hideOnUse = 1;
				condition = "((player isEqualTo currentPilot this) AND (alive this) AND (isEngineOn this) AND !(isTouchingGround this) AND (((getPosATL this) select 2) >= 5) AND (((vectorMagnitude (velocity this)) * 3.6) <= 200) AND (time >= (this getVariable ['TAE_recoveryAvailableAt',0])))";
				statement = "[this,player] remoteExecCall ['TAE_fnc_recoverAirbornePlayers',2]";
			};

			class OpenDoor {
				displayName = "Open Drop Bay";
				source = "user";
				radius = 5;
				onlyForPlayer = 1;
				condition = "((player == currentPilot this) AND (alive this) AND ((this animationSourcePhase ""bay.1"") isEqualTo 0) AND ((this animationSourcePhase ""pylonIsEmpty.1"") isEqualTo 1))";
				statement = "['knd_komrk_bay',[this,true]] call CBA_fnc_globalEvent;";
				position = "";
			};

			class CloseDoor {
				displayName = "Close Drop Bay";
				source = "user";
				radius = 5;
				onlyForPlayer = 1;
				condition = "((player == currentPilot this) AND (alive this) AND ((this animationSourcePhase ""bay.1"") isEqualTo 1) AND ((this animationSourcePhase ""pylonIsEmpty.1"") isEqualTo 1))";
				statement = "['knd_komrk_bay',[this,false]] call CBA_fnc_globalEvent;";
				position = "";
			};

			class throwPeopleOut: CloseDoor {
				displayName = "Eject Passengers";
				statement = "this call knd_fnc_ejectCargoBay; ['knd_komrk_bay',[this,false]] call CBA_fnc_globalEvent;";
			};
		};
		class ace_cargo {
			class cargo {
				class knd_resupply_jetpack {
					type = "knd_resupply_jetpack";
					amount = 1;
				};

				class TAE_Ammo_Crate {
					type = "TAE_Ammo_Crate";
					amount = 1;
				};

				class TAE_Demo_Crate {
					type = "TAE_Demo_Crate";
					amount = 1;
				};

				class TAE_Medical_Crate {
					type = "TAE_Medical_Crate";
					amount = 1;
				};
			};
		};
	};

	class TAE_Skycat_Transport: knd_vehicles_skycat {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr SKYCAT/I Transport";
		author = "TAE Mod Team";

		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Aircraft";

		crew = "TAE_Unit_Pilot";
		typicalCargo[] = {
			"TAE_Unit_Pilot"
		};

		tf_hasLRradio = 1;
		tf_range = 100000;

		class Components: Components {
			class TransportCountermeasuresComponent {};

			class TransportPylonsComponent {
				UIPicture = "\knd_vehicles_skycat\tex\pylons_ca.paa";

				class pylons {
					class pylon1 {
						hardpoints[] = {
							"TAE_SKYCAT_HP_MPR10"
						};
						attachment = "TAE_Skycat_mag_MPR10";
						priority = 10;
						maxweight = 300;
						UIposition[] = {0.31,0.10};
					};

					class pylon2: pylon1 {
						UIposition[] = {0.31,0.15};
						mirroredMissilePos = 1;
					};

					class pylon3 {
						hardpoints[] = {
							"TAE_SKYCAT_HP_TALON",
							"TAE_SKYCAT_HP_FIREBRAND"
						};
						attachment = "TAE_Skycat_mag_Talon";
						priority = 9;
						maxweight = 2500;
						UIposition[] = {0.51,0.35};
					};

					class pylon4: pylon3 {
						priority = 13;
						UIposition[] = {0.11,0.35};
						mirroredMissilePos = 3;
					};

					class pylon5 {
						hardpoints[] = {
							"TAE_SKYCAT_HP_FIREBRAND",
							"TAE_SKYCAT_HP_WRAITH"
						};
						attachment = "TAE_Skycat_mag_Firebrand";
						priority = 7;
						maxweight = 5000;
						UIposition[] = {0.41,0.25};
					};

					class pylon6: pylon5 {
						priority = 12;
						UIposition[] = {0.21,0.25};
						mirroredMissilePos = 5;
					};
				};

				class presets {
					class Empty {
						displayName = "Empty";
						attachment[] = {};
					};

					class Default {
						displayName = "House Karr Default";
						attachment[] = {
							"TAE_Skycat_mag_MPR10",
							"TAE_Skycat_mag_MPR10",
							"TAE_Skycat_mag_Talon",
							"TAE_Skycat_mag_Talon",
							"TAE_Skycat_mag_Firebrand",
							"TAE_Skycat_mag_Firebrand"
						};
					};
				};
			};
		};

		ace_cargo_hasCargo = 1;
		ace_cargo_space = 15;
		class ace_cargo {
			class cargo {
				class knd_resupply_jetpack {
					type = "knd_resupply_jetpack";
					amount = 1;
				};

				class TAE_Ammo_Crate {
					type = "TAE_Ammo_Crate";
					amount = 1;
				};

				class TAE_Demo_Crate {
					type = "TAE_Demo_Crate";
					amount = 1;
				};

				class TAE_Medical_Crate {
					type = "TAE_Medical_Crate";
					amount = 1;
				};
			};
		};
	};

	class TAE_Z98_Headhunter_base: ls_vehicle_z98 {
		scope = 0;
		scopeCurator = 0;
		vtol = 4;
		lockDetectionSystem = 30;
		incomingMissileDetectionSystem = 26;
		radarTargetSize = 0.3;
		visualTargetSize = 0.7;
		irTargetSize = 0.5;
		tf_hasLRradio = 1;
		tf_range = 100000;
		aileronSensitivity = 0.7;
		aileronControlsSensitivityCoef = 2.8;
		elevatorSensitivity = 1.1;
	};

	class TAE_Z98_Headhunter: TAE_Z98_Headhunter_base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Z-98 Interceptor";
		author = "TAE Mod Team";

		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Aircraft";

		availableForSupportTypes[] = {
			"CAS_Bombing",
			"CAS_Heli"
		};

		crew = "TAE_Unit_Pilot";
		typicalCargo[] = {
			"TAE_Unit_Pilot"
		};

		weapons[] = {
			"mti_armoury_weapon_Z95_Heavy_Cannon",
			"Laserdesignator_mounted",
			"ls_weapon_CMFlareLauncher"
		};

		magazines[] = {
			"mti_armoury_mag_Z95_Cannon_Mag",
			"mti_armoury_mag_Z95_Cannon_Mag",
			"mti_armoury_mag_Z95_Cannon_Mag",
			"Laserbatteries",
			"192Rnd_CMFlare_Chaff_Magazine",
			"192Rnd_CMFlare_Chaff_Magazine"
		};

		laserScanner = 1;

		hiddenSelections[] = {
			"camo1",
			"camo2"
		};

		hiddenSelectionsTextures[] = {
			"TAEVehicles\data\z98\base_hull_co.paa",
			"\ls\core\addons\vehicles_z98\data\cockpit_co.paa"
		};

		class TextureSources {
			class base {
				displayName = "Base";
				author = "TAE Mod Team";
				factions[] = {};
				textures[] = {
					"TAEVehicles\data\z98\base_hull_co.paa",
					"\ls\core\addons\vehicles_z98\data\cockpit_co.paa"
				};
			};
			
			class Grey {
				displayName = "Grey";
				author = "Legion Studios";
				factions[] = {};
				textures[] = {
					"\ls\core\addons\vehicles_z98\data\hull_grey_co.paa",
					"\ls\core\addons\vehicles_z98\data\cockpit_co.paa"
				};
			};
		};

		textureList[] = {
			"Grey", 0,
			"base", 1
		};

		class Components {
			class TransportCountermeasuresComponent {};

			class TransportPylonsComponent {
				UIPicture = "\ls\core\addons\vehicles_z98\data\ui\z98_3den_ca.paa";

				class pylons {
					class pylons1 {
						hardpoints[] = {
							"TAE_Z98_HP_INNER"
						};
						attachment = "";
						priority = 1;
						maxweight = 5000;
						UIposition[] = {0.42,0.36};
					};

					class pylons2 {
						hardpoints[] = {
							"TAE_Z98_HP_INNER"
						};
						attachment = "";
						priority = 1;
						maxweight = 5000;
						UIposition[] = {0.42,0.19};
					};

					class pylons3 {
						hardpoints[] = {
							"TAE_Z98_HP_MIDDLE"
						};
						attachment = "TAE_Z98_mag_Hammers";
						priority = 2;
						maxweight = 2500;
						UIposition[] = {0.42,0.12};
					};

					class pylons4 {
						hardpoints[] = {
							"TAE_Z98_HP_MIDDLE"
						};
						attachment = "TAE_Z98_mag_Hammers";
						priority = 2;
						maxweight = 2500;
						UIposition[] = {0.42,0.43};
					};

					class pylons5 {
						hardpoints[] = {
							"TAE_Z98_HP_OUTER_AA"
						};
						attachment = "TAE_Z98_mag_Lightning";
						priority = 3;
						maxweight = 300;
						UIposition[] = {0.42,0.50};
					};

					class pylons6 {
						hardpoints[] = {
							"TAE_Z98_HP_OUTER_AA"
						};
						attachment = "TAE_Z98_mag_Lightning";
						priority = 3;
						maxweight = 300;
						UIposition[] = {0.42,0.05};
					};
				};

				class presets {
					class empty {
						displayName = "Empty";
						attachment[] = {};
					};

					class Default {
						displayName = "House Karr Default";
						attachment[] = {
							"",
							"",
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Lightning",
							"TAE_Z98_mag_Lightning"
						};
					};

					class AirSuperiority {
						displayName = "Air Superiority";
						attachment[] = {
							"TAE_Z98_mag_Hurricane",
							"TAE_Z98_mag_Hurricane",
							"TAE_Z98_mag_Hurricane",
							"TAE_Z98_mag_Hurricane",
							"TAE_Z98_mag_Typhoon",
							"TAE_Z98_mag_Typhoon"
						};
					};

					class GroundAttack {
						displayName = "Ground Attack";
						attachment[] = {
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Hammers",
							"",
							"",
							"TAE_Z98_mag_Lightning",
							"TAE_Z98_mag_Lightning"
						};
					};

					class SEAD {
						displayName = "SEAD";
						attachment[] = {
							"TAE_Z98_mag_Stalkers",
							"TAE_Z98_mag_Stalkers",
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Typhoon",
							"TAE_Z98_mag_Typhoon"
						};
					};

					class Seismic {
						displayName = "Seismic";
						attachment[] = {
							"TAE_Z98_mag_DB78",
							"TAE_Z98_mag_DB78",
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Hammers",
							"TAE_Z98_mag_Lightning",
							"TAE_Z98_mag_Lightning"
						};
					};
				};
			};

			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
				componentType = "VehicleSystemsDisplayManager";
				left = 1;
				defaultDisplay = "EmptyDisplay";

				class Components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};

					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {8000, 16000, 32000};
						resource = "RscCustomInfoSensors";
					};
				};
			};

			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
				componentType = "VehicleSystemsDisplayManager";
				right = 1;
				defaultDisplay = "SensorDisplay";

				class Components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};

					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {8000, 16000, 32000};
						resource = "RscCustomInfoSensors";
					};
				};
			};

			class SensorsManagerComponent {
				class Components {
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
						class AirTarget {
							minRange = 0;
							maxRange = 32000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};

						class GroundTarget {
							minRange = 0;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
					};
				};
			};
		};
	};
};
