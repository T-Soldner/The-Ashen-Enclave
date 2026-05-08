class CfgPatches {
	class TAEVehicles {
		name = "TAE Vehicles";
		author = "TAE Mod Team";
		requiredAddons[] = {
			"A3_Data_F_Loadorder",
			"ace_cargo",
			"KND_Komrk",
			"TAEObjects",
			"TAEUnits_HouseKarr",
			"mti_armoury_vehicles_weapons",
			"ls_vehicles_z98",
			"knd_jdumb"
		};
		units[] = {
			"TAE_KomrkFighter_Transport",
			"TAE_Z98_Headhunter"
		};
		weapons[] = {
			"TAE_Z98_weapon_Lightning",
			"TAE_Z98_weapon_Typhoon",
			"TAE_Z98_weapon_Hurricane",
			"TAE_Z98_weapon_Hammers",
			"TAE_Z98_weapon_Stalkers",
			"TAE_Z98_weapon_Shinies_Light",
			"TAE_Z98_weapon_DB78"
		};
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Aircraft {
		displayName = "Aircraft";
	};
};

class CfgWeapons {
	class mti_armoury_weapon_AA_Missile_Light_Pylon;
	class mti_armoury_weapon_AA_Short_Missile_Pylon;
	class mti_armoury_weapon_AA_Long_Missile_Pylon;
	class mti_armoury_weapon_AGM_Missile_Pylon;
	class mti_armoury_weapon_Harm_Missile_Pylon;
	class mti_armoury_weapon_Dumb_Bomb_Light_Pylon;
	class knd_pylonweapon_jdumb;

	class TAE_Z98_weapon_Lightning: mti_armoury_weapon_AA_Missile_Light_Pylon {
		magazines[] = {
			"TAE_Z98_mag_Lightning"
		};
	};

	class TAE_Z98_weapon_Typhoon: mti_armoury_weapon_AA_Short_Missile_Pylon {
		magazines[] = {
			"TAE_Z98_mag_Typhoon"
		};
	};

	class TAE_Z98_weapon_Hurricane: mti_armoury_weapon_AA_Long_Missile_Pylon {
		magazines[] = {
			"TAE_Z98_mag_Hurricane"
		};
	};

	class TAE_Z98_weapon_Hammers: mti_armoury_weapon_AGM_Missile_Pylon {
		magazines[] = {
			"TAE_Z98_mag_Hammers"
		};
	};

	class TAE_Z98_weapon_Stalkers: mti_armoury_weapon_Harm_Missile_Pylon {
		magazines[] = {
			"TAE_Z98_mag_Stalkers"
		};
	};

	class TAE_Z98_weapon_Shinies_Light: mti_armoury_weapon_Dumb_Bomb_Light_Pylon {
		magazines[] = {
			"TAE_Z98_mag_Shinies_Light"
		};
	};

	class TAE_Z98_weapon_DB78: knd_pylonweapon_jdumb {
		magazines[] = {
			"TAE_Z98_mag_DB78"
		};
	};
};
class CfgAmmo {
	class mti_armoury_ammo_AGM_Missile;

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
	class mti_armoury_mag_Dumb_Bomb_Mag_Light;
	class knd_pylonrack_jdumb;

	class TAE_Z98_mag_Lightning: mti_armoury_mag_AA_Light_Mag {
		displayName = "Lightning";
		displayNameShort = "Lightning";
		hardpoints[] = {
			"TAE_Z98_HP_OUTER_AA"
		};
		pylonWeapon = "TAE_Z98_weapon_Lightning";
	};

	class TAE_Z98_mag_Typhoon: mti_armoury_mag_AA_Short_Mag {
		displayName = "Typhoon";
		displayNameShort = "Typhoon";
		hardpoints[] = {
			"TAE_Z98_HP_OUTER_AA",
			"TAE_Z98_HP_MIDDLE"
		};
		pylonWeapon = "TAE_Z98_weapon_Typhoon";
	};

	class TAE_Z98_mag_Hurricane: mti_armoury_mag_AA_Long_Mag {
		displayName = "Hurricane";
		displayNameShort = "Hurricane";
		hardpoints[] = {
			"TAE_Z98_HP_MIDDLE",
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Hurricane";
	};

	class TAE_Z98_mag_Hammers: mti_armoury_mag_AGM_Mag {
		displayName = "Hammers";
		displayNameShort = "Hammers";
		ammo = "TAE_Z98_ammo_Hammers";
		hardpoints[] = {
			"TAE_Z98_HP_MIDDLE",
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Hammers";
	};

	class TAE_Z98_mag_Stalkers: mti_armoury_mag_HARM_Missile_Mag {
		displayName = "Stalkers";
		displayNameShort = "Stalkers";
		hardpoints[] = {
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Stalkers";
	};

	class TAE_Z98_mag_Shinies_Light: mti_armoury_mag_Dumb_Bomb_Mag_Light {
		displayName = "Shinies";
		displayNameShort = "Shinies";
		hardpoints[] = {
			"TAE_Z98_HP_MIDDLE",
			"TAE_Z98_HP_INNER"
		};
		pylonWeapon = "TAE_Z98_weapon_Shinies_Light";
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

class CfgVehicles {
	class knd_KomrkFighter_VTOL_Dynamic_F;
	class ls_vehicle_z98;

	class TAE_KomrkFighter_Transport_base: knd_KomrkFighter_VTOL_Dynamic_F {
		scope = 0;
		scopeCurator = 0;

		class Components {
			class TransportPylonsComponent;
		};
	};

	class TAE_KomrkFighter_Transport: TAE_KomrkFighter_Transport_base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Kom'rk-Class Fighter Transport";
		author = "TAE Mod Team";

		side = 2;
		faction = "TAE_Faction_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Aircraft";

		crew = "TAE_Unit_Engineer";
		typicalCargo[] = {
			"TAE_Unit_Engineer"
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

			class Jaro {
				displayName = "Jaro";
				author = "House Kandosii";
				textures[] = {
					"knd_vehicles_komrk\tx\Jaro\Fore_co.paa",
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
					"knd_vehicles_komrk\tx\Jaro\aft_co.paa",
					"knd_vehicles_komrk\tx\Jaro\wing_co.paa"
				};
				factions[] = {};
			};
		};

		textureList[] = {
			"base", 0,
			"Jaro", 1
		};

		class Components: Components {
			class TransportPylonsComponent: TransportPylonsComponent {
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
							"mti_armoury_weapon_AA_Pylon",
							"mti_armoury_weapon_AA_Heavy_Pylon"
						};
						attachment = "mti_armoury_mag_AA_Short_Mag";
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
							"mti_armoury_weapon_Rock_Pylon",
							"mti_armoury_weapon_Bomb_Heavy_Pylon"
						};
						attachment = "mti_armoury_mag_Smart_Bomb_Mag_Heavy";
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
							"mti_armoury_weapon_HARM_Pylon"
						};
						attachment = "mti_armoury_mag_HARM_Missile_Mag";
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
							"mti_armoury_weapon_AGM_Heavy_Pylon"
						};
						attachment = "mti_armoury_mag_AGM_Mag";
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
							"mti_armoury_mag_AA_Short_Mag",
							"mti_armoury_mag_AA_Short_Mag",
							"mti_armoury_mag_Smart_Bomb_Mag_Heavy",
							"mti_armoury_mag_Smart_Bomb_Mag_Heavy",
							"mti_armoury_mag_HARM_Missile_Mag",
							"mti_armoury_mag_HARM_Missile_Mag",
							"mti_armoury_mag_AGM_Mag",
							"mti_armoury_mag_AGM_Mag"
						};
					};

					class Typhoon {
						displayName = "Typhoon";
						attachment[] = {
							"",
							"mti_armoury_mag_AA_Short_Mag",
							"mti_armoury_mag_AA_Short_Mag",
							"",
							"",
							"",
							"",
							"",
							""
						};
					};

					class Bombs {
						displayName = "Bombs";
						attachment[] = {
							"",
							"",
							"",
							"mti_armoury_mag_Smart_Bomb_Mag_Heavy",
							"mti_armoury_mag_Smart_Bomb_Mag_Heavy",
							"",
							"",
							"",
							""
						};
					};

					class Stalkers {
						displayName = "Stalkers";
						attachment[] = {
							"",
							"",
							"",
							"",
							"",
							"mti_armoury_mag_HARM_Missile_Mag",
							"mti_armoury_mag_HARM_Missile_Mag",
							"",
							""
						};
					};

					class Hammers {
						displayName = "Hammers";
						attachment[] = {
							"",
							"",
							"",
							"",
							"",
							"",
							"",
							"mti_armoury_mag_AGM_Mag",
							"mti_armoury_mag_AGM_Mag"
						};
					};

					class GroundAttack {
						displayName = "Ground Attack";
						attachment[] = {
							"",
							"mti_armoury_mag_AA_Short_Mag",
							"mti_armoury_mag_AA_Short_Mag",
							"mti_armoury_mag_Smart_Bomb_Mag_Heavy",
							"mti_armoury_mag_Smart_Bomb_Mag_Heavy",
							"",
							"",
							"mti_armoury_mag_AGM_Mag",
							"mti_armoury_mag_AGM_Mag"
						};
					};

					class SEAD {
						displayName = "SEAD";
						attachment[] = {
							"",
							"mti_armoury_mag_AA_Short_Mag",
							"mti_armoury_mag_AA_Short_Mag",
							"",
							"",
							"mti_armoury_mag_HARM_Missile_Mag",
							"mti_armoury_mag_HARM_Missile_Mag",
							"",
							""
						};
					};
				};
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

	class TAE_Z98_Headhunter_base: ls_vehicle_z98 {
		scope = 0;
		scopeCurator = 0;

		class Components {
			class TransportPylonsComponent;
		};
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

		crew = "TAE_Unit_Engineer";
		typicalCargo[] = {
			"TAE_Unit_Engineer"
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

		class Components: Components {
			class TransportPylonsComponent: TransportPylonsComponent {
				UIPicture = "\ls\core\addons\vehicles_z98\data\ui\z98_3den_ca.paa";

				class pylons {
					class pylons1 {
						hardpoints[] = {
							"TAE_Z98_HP_INNER"
						};
						attachment = "TAE_Z98_mag_Shinies_Light";
						priority = 1;
						maxweight = 5000;
						UIposition[] = {0.42,0.36};
					};

					class pylons2 {
						hardpoints[] = {
							"TAE_Z98_HP_INNER"
						};
						attachment = "TAE_Z98_mag_Shinies_Light";
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
							"TAE_Z98_mag_Shinies_Light",
							"TAE_Z98_mag_Shinies_Light",
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
							"TAE_Z98_mag_Shinies_Light",
							"TAE_Z98_mag_Shinies_Light",
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

					class LightBombs {
						displayName = "Light Bombs";
						attachment[] = {
							"TAE_Z98_mag_Shinies_Light",
							"TAE_Z98_mag_Shinies_Light",
							"TAE_Z98_mag_Shinies_Light",
							"TAE_Z98_mag_Shinies_Light",
							"TAE_Z98_mag_Lightning",
							"TAE_Z98_mag_Lightning"
						};
					};
				};
			};
		};
	};
};