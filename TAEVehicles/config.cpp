class CfgPatches {
	class TAEVehicles {
		name = "TAE Vehicles";
		author = "TAE Mod Team";
		requiredAddons[] = {
			"A3_Data_F_Loadorder",
			"ace_cargo",
			"KND_Komrk",
			"TAEObjects",
			"TAEUnits_HouseKarr"
		};
		units[] = {
			"TAE_KomrkFighter_Transport"
		};
		weapons[] = {};
	};
};

class CfgVehicles {
	class knd_KomrkFighter_VTOL_Dynamic_F;

	class TAE_KomrkFighter_Transport: knd_KomrkFighter_VTOL_Dynamic_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Kom'rk-Class Fighter Transport";
		author = "TAE Mod Team";

		crew = "TAE_Unit_Engineer";
		typicalCargo[] = {
			"TAE_Unit_Engineer"
		};

		ace_cargo_hasCargo = 1;
		ace_cargo_space = 8;

		hiddenSelections[] = {
			"fore",
			"aft",
			"wing"
		};

		hiddenSelectionsTextures[] = {
			"knd_vehicles_komrk\tx\Jaro\Fore_co.paa",
			"knd_vehicles_komrk\tx\Jaro\aft_co.paa",
			"knd_vehicles_komrk\tx\Jaro\wing_co.paa"
		};

		class textureSources {
			class base {
				displayName = "Base";
				author = "TAE Mod Team";
				textures[] = {
					"TAEVehicles\data\komrk\base_fore_co.paa",
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