if (hasInterface) then {
	["TAE_groundNotice", {params ["_message"]; systemChat format ["[Ground Terminal] %1", _message];}] call CBA_fnc_addEventHandler;
	["TAE_serviceDroidVisual", {_this call TAE_fnc_animateAircraftServiceDroid;}] call CBA_fnc_addEventHandler;
    ["TAE_aircraftNotice", {params ["_message"]; systemChat format ["[Vehicle Service] %1", _message];}] call CBA_fnc_addEventHandler;
};
if (isServer) then {
	["TAE_groundRequest", {_this call TAE_fnc_groundVehicleRequest;}] call CBA_fnc_addEventHandler;
    ["TAE_aircraftRequest", {_this call TAE_fnc_aircraftRequisitionRequest;}] call CBA_fnc_addEventHandler;
};
