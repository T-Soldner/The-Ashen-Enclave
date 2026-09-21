if (hasInterface) then {
    ["TAE_aircraftNotice", {params ["_message"]; systemChat format ["[Aircraft Service] %1", _message];}] call CBA_fnc_addEventHandler;
};
if (isServer) then {
    ["TAE_aircraftRequest", {_this call TAE_fnc_aircraftRequisitionRequest;}] call CBA_fnc_addEventHandler;
};
