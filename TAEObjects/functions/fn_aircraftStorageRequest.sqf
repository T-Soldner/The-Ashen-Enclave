params ["_logic", "_pad", "_actor", "_radius", "_operation", "_payload"];
if (!isServer) exitWith {};
private _notify = {params ["_text"]; ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;};
private _ground = _logic isKindOf "TAE_GroundTerminal";
private _types = if (_ground) then {["LandVehicle"]} else {["Air"]};
private _near = (nearestObjects [_pad, _types, _radius, true]) select {
    alive _x && {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15}
};
if (count _near != 1) exitWith {["Storage requires exactly one intact vehicle on the pad."] call _notify;};
private _vehicle = _near # 0;
if (_ground && {!((typeOf _vehicle) in (call TAE_fnc_getGroundVehicleClasses))}) exitWith {["Vehicle is not authorized for this terminal."] call _notify;};
if (_pad getVariable ["TAE_aircraftBusy", false] || {_vehicle getVariable ["TAE_repairBusy", false]}) exitWith {["Pad or vehicle is busy."] call _notify;};
if (crew _vehicle isNotEqualTo [] || {isEngineOn _vehicle} || {vectorMagnitude velocity _vehicle > 0.5}) exitWith {["Empty the vehicle, shut down its engine and let it stop before storing it."] call _notify;};
if (((getVehicleCargo _vehicle) findIf {crew _x isNotEqualTo []}) >= 0) exitWith {["Empty any carried vehicles before storage."] call _notify;};
_pad setVariable ["TAE_aircraftBusy", true, true];
_vehicle setVariable ["TAE_repairBusy", true, true];
["Crew started moving the vehicle (10 seconds)."] call _notify;
[_logic, _pad, _actor, _radius, _vehicle] spawn {
    params ["_logic", "_pad", "_actor", "_radius", "_vehicle"];
    _vehicle setOwner 2;
    private _deadline = diag_tickTime + 5;
    waitUntil {sleep 0.1; local _vehicle || {isNull _vehicle} || {diag_tickTime > _deadline}};
    private _ready = {
        !isNull _logic && {!isNull _pad} && {alive _vehicle} && {local _vehicle} &&
        {crew _vehicle isEqualTo []} && {((getVehicleCargo _vehicle) findIf {crew _x isNotEqualTo []}) < 0} && {!isEngineOn _vehicle} && {vectorMagnitude velocity _vehicle <= 0.5} &&
        {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15}
    };
    private _end = diag_tickTime + 10;
    waitUntil {sleep 0.25; !(call _ready) || {diag_tickTime >= _end}};
    private _completed = false;
    if (call _ready) then {
        // ViV cargo is separate world objects; do not leave it behind on despawn.
        {deleteVehicle _x;} forEach getVehicleCargo _vehicle;
        deleteVehicle _vehicle;
        _completed = true;
    };
    if (!isNull _vehicle) then {_vehicle setVariable ["TAE_repairBusy", false, true];};
    if (!isNull _pad) then {_pad setVariable ["TAE_aircraftBusy", false, true];};
    if (!isNull _actor) then {
        private _text = if (_completed) then {"Vehicle put in storage; pad cleared."} else {"Vehicle move interrupted. Check the pad and vehicle."};
        ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;
    };
};
