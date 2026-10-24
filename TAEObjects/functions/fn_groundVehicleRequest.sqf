params [["_terminal", objNull, [objNull]], ["_actor", objNull, [objNull]], ["_class", "", [""]]];
if (!isServer || {isNull _terminal} || {isNull _actor}) exitWith {};
if !(_terminal isKindOf "TAE_GroundTerminal") exitWith {};
if (!isPlayer _actor || {!alive _actor} || {vehicle _actor != _actor} || {_actor distance _terminal > 5}) exitWith {};
private _notify = {params ["_message"]; ["TAE_groundNotice", [_message], _actor] call CBA_fnc_targetEvent;};
private _data = _terminal getVariable ["TAE_groundData", []];
if (_data isEqualTo []) exitWith {};
_data params ["_pad", "_radius"];
if (isNull _pad) exitWith {};
if (_pad getVariable ["TAE_aircraftBusy", false]) exitWith {["Spawn area is busy."] call _notify;};
if (_class == "service") exitWith {
    [_terminal, _pad, _actor, _radius, "service", []] call TAE_fnc_serviceAircraftOnPad;
};
if (_class == "store") exitWith {
    [_terminal, _pad, _actor, _radius, "store", []] call TAE_fnc_aircraftStorageRequest;
};
if !(_class in (call TAE_fnc_getGroundVehicleClasses)) exitWith {["Vehicle is not authorized."] call _notify;};
private _near = nearestObjects [_pad, ["Air", "LandVehicle", "Ship", "CAManBase"], _radius, true];
_near = _near select {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15};
if (_near isNotEqualTo []) exitWith {["Clear people, vehicles and wrecks from the spawn area first."] call _notify;};
if (surfaceIsWater getPosWorld _pad) exitWith {["The spawn area must be on land."] call _notify;};
_pad setVariable ["TAE_aircraftBusy", true, true];
private _vehicle = createVehicle [_class, getPosATL _pad, [], 0, "CAN_COLLIDE"];
if (!isNull _vehicle) then {
    _vehicle setDir getDir _pad;
    _vehicle setPosATL getPosATL _pad;
    _vehicle setVectorUp surfaceNormal getPosWorld _pad;
    _vehicle setVelocity [0,0,0];
    ["Vehicle ready. Move it clear before requesting another."] call _notify;
} else {["Vehicle creation failed."] call _notify;};
_pad setVariable ["TAE_aircraftBusy", false, true];
