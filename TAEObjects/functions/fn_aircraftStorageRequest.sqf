params ["_logic", "_pad", "_actor", "_radius", "_operation", "_payload"];
if (!isServer) exitWith {};
private _notify = {params ["_text"]; ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;};
private _near = (nearestObjects [_pad, ["Air"], _radius, true]) select {
    alive _x && {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15}
};
if (count _near != 1) exitWith {["Storage requires exactly one intact aircraft on the pad."] call _notify;};
private _vehicle = _near # 0;
if (_pad getVariable ["TAE_aircraftBusy", false] || {_vehicle getVariable ["TAE_repairBusy", false]}) exitWith {["Pad or aircraft is busy."] call _notify;};
if (crew _vehicle isNotEqualTo [] || {isEngineOn _vehicle} || {vectorMagnitude velocity _vehicle > 0.5}) exitWith {["Empty the aircraft, shut down its engine and let it stop before storing it."] call _notify;};
_pad setVariable ["TAE_aircraftBusy", true, true];
_vehicle setVariable ["TAE_repairBusy", true, true];
["Crew started moving the aircraft (10 seconds)."] call _notify;
[_logic, _pad, _actor, _radius, _vehicle] spawn {
    params ["_logic", "_pad", "_actor", "_radius", "_vehicle"];
    _vehicle setOwner 2;
    private _deadline = diag_tickTime + 5;
    waitUntil {sleep 0.1; local _vehicle || {isNull _vehicle} || {diag_tickTime > _deadline}};
    private _ready = {
        !isNull _logic && {!isNull _pad} && {alive _vehicle} && {local _vehicle} &&
        {crew _vehicle isEqualTo []} && {!isEngineOn _vehicle} && {vectorMagnitude velocity _vehicle <= 0.5} &&
        {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15}
    };
    private _end = diag_tickTime + 10;
    waitUntil {sleep 0.25; !(call _ready) || {diag_tickTime >= _end}};
    private _completed = false;
    if (call _ready) then {
        deleteVehicle _vehicle;
        _completed = true;
    };
    if (!isNull _vehicle) then {_vehicle setVariable ["TAE_repairBusy", false, true];};
    if (!isNull _pad) then {_pad setVariable ["TAE_aircraftBusy", false, true];};
    if (!isNull _actor) then {
        private _text = if (_completed) then {"Aircraft put in storage; pad cleared."} else {"Aircraft move interrupted. Check the pad and aircraft."};
        ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;
    };
};
