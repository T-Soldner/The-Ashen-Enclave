class CfgPatches {
	class TAEMarkers {
		name = "TAE Markers";
		author = "TAE Mod Team";
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};

class CfgMarkerClasses {
	class TAE_MarkerClass_FactionFlags {
		displayName = "[TAE] Faction Flags";
	};
};

class CfgMarkers {
	class TAE_Marker_HouseKarr {
		name = "House Karr";
		icon = "\TAEMarkers\data\house_karr_marker_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 32;
		shadow = 0;
		scope = 2;
		markerClass = "TAE_MarkerClass_FactionFlags";
	};

	class TAE_Marker_Nihil {
		name = "Nihil";
		icon = "\TAEMarkers\data\nihil_marker_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 32;
		shadow = 0;
		scope = 2;
		markerClass = "TAE_MarkerClass_FactionFlags";
	};

	class TAE_Marker_BlackSpireCartel {
		name = "Black Spire Cartel";
		icon = "\TAEMarkers\data\black_spire_cartel_marker_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 32;
		shadow = 0;
		scope = 2;
		markerClass = "TAE_MarkerClass_FactionFlags";
	};

	class TAE_Marker_NewRepublic {
		name = "New Republic";
		icon = "\TAEMarkers\data\new_republic_marker_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 32;
		shadow = 0;
		scope = 2;
		markerClass = "TAE_MarkerClass_FactionFlags";
	};
};
