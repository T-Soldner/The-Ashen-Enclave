if (uiNamespace getVariable ["TAE_HUD_visible", false]) exitWith {};

("TAE_HUD_LAYER" call BIS_fnc_rscLayer) cutRsc ["RscTAEHelmetHUD", "PLAIN", 0.15, false];
