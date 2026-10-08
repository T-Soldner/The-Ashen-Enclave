params ["_logic", "_pad", "_actor", "_radius", "_payload"];
if (!isServer) exitWith {};
private _notify = {params ["_text"]; ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;};
if (count _payload != 2) exitWith {};
_payload params ["_vehicle", "_counts"];
if !(_vehicle isEqualType objNull && {_counts isEqualType []}) exitWith {};
private _classes = call TAE_fnc_getResupplyCrateClasses;
if (count _counts != count _classes || {_counts findIf {!(_x isEqualType 0) || {!finite _x} || {_x < 0} || {_x > 1000} || {_x != floor _x}} != -1}) exitWith {["Invalid crate counts."] call _notify;};
private _near = (nearestObjects [_pad, ["Air"], _radius, true]) select {alive _x && {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15}};
if (count _near != 1 || {_near # 0 != _vehicle}) exitWith {["The selected aircraft must be the only intact aircraft on the pad."] call _notify;};
if (_pad getVariable ["TAE_aircraftBusy", false] || {_vehicle getVariable ["TAE_repairBusy", false]}) exitWith {["Pad or aircraft is busy."] call _notify;};
if (crew _vehicle isNotEqualTo [] || {isEngineOn _vehicle} || {vectorMagnitude velocity _vehicle > 0.5}) exitWith {["Empty the aircraft, stop it and shut down the engine first."] call _notify;};
if !(_vehicle getVariable ["ace_cargo_hasCargo", getNumber (configOf _vehicle >> "ace_cargo_hasCargo") == 1]) exitWith {["This aircraft does not support ACE cargo."] call _notify;};
private _loaded = +(_vehicle getVariable ["ace_cargo_loaded", []]);
private _replace = _loaded select {(if (_x isEqualType "") then {_x} else {typeOf _x}) in _classes};
private _available = [_vehicle] call ace_cargo_fnc_getCargoSpaceLeft;
{_available = _available + (([_x] call ace_cargo_fnc_getSizeItem) max 0);} forEach _replace;
private _required = 0;
{_required = _required + (_counts # _forEachIndex) * (([_x] call ace_cargo_fnc_getSizeItem) max 0);} forEach _classes;
if (_required > _available) exitWith {[format ["Not enough cargo space: requested %1, available %2. Other cargo is reserved.", _required, _available]] call _notify;};
_pad setVariable ["TAE_aircraftBusy", true, true];
_vehicle setVariable ["TAE_repairBusy", true, true];
["Crew is swapping resupply crates (10 seconds)."] call _notify;
[_logic, _pad, _actor, _radius, _vehicle, _counts, _classes, _loaded, _replace, _required] spawn {
    params ["_logic", "_pad", "_actor", "_radius", "_vehicle", "_counts", "_classes", "_loaded", "_replace", "_required"];
    sleep 10;
    private _valid = !isNull _logic && {!isNull _pad} && {alive _vehicle} && {crew _vehicle isEqualTo []} && {!isEngineOn _vehicle} && {vectorMagnitude velocity _vehicle <= 0.5} && {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15} && {_loaded isEqualTo (_vehicle getVariable ["ace_cargo_loaded", []])};
    private _available = [_vehicle] call ace_cargo_fnc_getCargoSpaceLeft;
    {_available = _available + (([_x] call ace_cargo_fnc_getSizeItem) max 0);} forEach _replace;
    _valid = _valid && {_required <= _available};
    private _message = "Crate swap interrupted; cargo was not changed.";
    if (_valid) then {
        {[_x, _vehicle] call ace_cargo_fnc_removeCargoItem;} forEach _replace;
        private _failed = false;
        {
            private _class = _x;
            for "_i" from 1 to (_counts # _forEachIndex) do {
                if !([_class, _vehicle, true] call ace_cargo_fnc_loadItem) then {_failed = true;};
            };
        } forEach _classes;
        _message = if (_failed) then {"Some crates could not be loaded. Check ACE cargo; capacity was not exceeded."} else {"Resupply crate loadout ready."};
    };
    if (!isNull _vehicle) then {_vehicle setVariable ["TAE_repairBusy", false, true];};
    if (!isNull _pad) then {_pad setVariable ["TAE_aircraftBusy", false, true];};
    if (!isNull _actor) then {["TAE_aircraftNotice", [_message], _actor] call CBA_fnc_targetEvent;};
};
