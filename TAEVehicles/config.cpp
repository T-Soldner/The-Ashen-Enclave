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
			"mti_armoury_vehicles_weapons"
		};
		units[] = {
			"TAE_KomrkFighter_Transport"
		};
		weapons[] = {};
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_Aircraft {
		displayName = "Aircraft";
	};
};

class CfgVehicles {
	class knd_KomrkFighter_VTOL_Dynamic_F;
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
};