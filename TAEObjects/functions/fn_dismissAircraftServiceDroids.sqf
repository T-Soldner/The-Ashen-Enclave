params ["_droids"];
if (!isServer) exitWith {};
{
    if (!isNull _x) then {_x setVariable ["TAE_serviceDepart", true, true];};
} forEach _droids;
[_droids] spawn {
    params ["_droids"];
    sleep 10;
    {if (!isNull _x) then {deleteVehicle _x;};} forEach _droids;
};
