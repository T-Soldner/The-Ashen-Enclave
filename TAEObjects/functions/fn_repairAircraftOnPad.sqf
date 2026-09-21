// Shared server-only repair operation for requisition and repair-only terminals.
params ["_logic", "_pad", "_actor", "_radius", "_duration"];
if (!isServer || {isNull _logic} || {isNull _pad} || {isNull _actor}) exitWith {};
private _notify = {params ["_text"]; ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;};
if (_pad getVariable ["TAE_aircraftBusy", false]) exitWith {["Pad is busy."] call _notify;};
_duration = _duration max 1;
private _near = nearestObjects [_pad, ["Air"], _radius, true];
_near = _near select {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15};
private _aircraft = _near select {_x isKindOf "Air" && {alive _x}};
if (count _aircraft != 1) exitWith {["Exactly one intact aircraft must be on the pad."] call _notify;};
private _vehicle = _aircraft # 0;
if (_vehicle getVariable ["TAE_repairBusy", false]) exitWith {["Aircraft is already being repaired."] call _notify;};
if (crew _vehicle isNotEqualTo [] || {isEngineOn _vehicle} || {vectorMagnitude velocity _vehicle > 0.5}) exitWith {["Empty the aircraft, shut down its engine and let it stop before repair."] call _notify;};
_pad setVariable ["TAE_aircraftBusy", true, true];
_vehicle setVariable ["TAE_repairBusy", true, true];
["Repair crew started work."] call _notify;
[_logic, _pad, _vehicle, _actor, _radius, _duration] spawn {
    params ["_logic", "_pad", "_vehicle", "_actor", "_radius", "_duration"];
    // Empty aircraft can be transferred to the server for local damage commands.
    _vehicle setOwner 2;
    private _deadline = diag_tickTime + 5;
    waitUntil {sleep 0.1; local _vehicle || {isNull _vehicle} || {diag_tickTime > _deadline}};
    private _completed = false;
    private _step = 1 / _duration;
    while {!isNull _logic && {!isNull _pad} && {alive _vehicle} && {local _vehicle} && {crew _vehicle isEqualTo []} && {!isEngineOn _vehicle} && {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15} && {vectorMagnitude velocity _vehicle <= 0.5}} do {
        private _hits = getAllHitPointsDamage _vehicle;
        private _damage = damage _vehicle;
        private _values = _hits param [2, []];
        if (_damage <= 0 && {(_values findIf {_x > 0}) < 0}) exitWith {_completed = true;};
        sleep 1;
        if (crew _vehicle isEqualTo [] && {!isEngineOn _vehicle} && {local _vehicle} && {alive _vehicle} && {!isNull _logic} && {!isNull _pad} && {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15} && {vectorMagnitude velocity _vehicle <= 0.5}) then {
            // Re-read after waiting so damage taken during the interval is not discarded.
            _damage = damage _vehicle;
            _values = (getAllHitPointsDamage _vehicle) param [2, []];
            _vehicle setDamage ((_damage - _step) max 0);
            {_vehicle setHitIndex [_forEachIndex, (_x - _step) max 0];} forEach _values;
        };
    };
    if (!isNull _vehicle) then {_vehicle setVariable ["TAE_repairBusy", false, true];};
    if (!isNull _pad) then {_pad setVariable ["TAE_aircraftBusy", false, true];};
    if (!isNull _actor) then {
        ["TAE_aircraftNotice", [["Repair interrupted; completed work retained.", "Repair complete."] select _completed], _actor] call CBA_fnc_targetEvent;
    };
};
