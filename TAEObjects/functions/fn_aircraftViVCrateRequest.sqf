params ["_logic", "_pad", "_actor", "_radius", "_vehicle", "_counts", "_classes"];
if (!isServer) exitWith {};
private _requested = 0;
{_requested = _requested + _x;} forEach _counts;
if (_requested > 64) exitWith {
    ["TAE_aircraftNotice", ["Request at most 64 crates per swap."], _actor] call CBA_fnc_targetEvent;
};
_pad setVariable ["TAE_aircraftBusy", true, true];
_vehicle setVariable ["TAE_repairBusy", true, true];
["TAE_aircraftNotice", ["Crew is swapping ViV resupply crates (10 seconds)."], _actor] call CBA_fnc_targetEvent;
[_logic, _pad, _actor, _radius, _vehicle, _counts, _classes] spawn {
    params ["_logic", "_pad", "_actor", "_radius", "_vehicle", "_counts", "_classes"];
    private _loaded = getVehicleCargo _vehicle;
    _vehicle setOwner 2;
    private _deadline = diag_tickTime + 5;
    waitUntil {sleep 0.1; isNull _vehicle || {local _vehicle} || {diag_tickTime > _deadline}};
    private _ready = {
        !isNull _logic && {!isNull _pad} && {alive _vehicle} && {local _vehicle} &&
        {crew _vehicle isEqualTo []} && {!isEngineOn _vehicle} && {vectorMagnitude velocity _vehicle <= 0.5} &&
        {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15} &&
        {(_loaded - (getVehicleCargo _vehicle)) isEqualTo []} && {((getVehicleCargo _vehicle) - _loaded) isEqualTo []}
    };
    private _end = diag_tickTime + 10;
    waitUntil {sleep 0.25; !(call _ready) || {diag_tickTime >= _end}};
    private _message = "Crate swap interrupted; cargo was not changed.";
    if (call _ready) then {
        private _old = _loaded select {typeOf _x in _classes};
        private _states = _old apply {[_x, isObjectHidden _x, simulationEnabled _x]};
        private _new = [];
        private _success = true;
        // Retain original crate objects and contents until every replacement fits.
        {
            objNull setVehicleCargo _x;
            _x hideObjectGlobal true;
            _x enableSimulationGlobal false;
            _x setPosASL [0,0,-1000 - _forEachIndex * 5];
        } forEach _old;
        {
            private _class = _x;
            for "_i" from 1 to (_counts # _forEachIndex) do {
                private _crate = createVehicle [_class, [0,0,0], [], 0, "CAN_COLLIDE"];
                if (isNull _crate) exitWith {_success = false;};
                _new pushBack _crate;
                _crate hideObjectGlobal true;
                _crate enableSimulationGlobal false;
                _crate setPosASL [0,0,-2000];
                private _fit = _vehicle canVehicleCargo _crate;
                if (!(_fit # 0) || {!(_fit # 1)} || {!(_vehicle setVehicleCargo _crate)}) exitWith {_success = false;};
            };
            if (!_success) exitWith {};
        } forEach _classes;
        if (_success) then {
            {deleteVehicle _x;} forEach _old;
            {_x hideObjectGlobal false; _x enableSimulationGlobal true;} forEach _new;
            private _defaults = _vehicle getVariable ["knd_vehicles_core_defaultViVCargo", []];
            _vehicle setVariable ["knd_vehicles_core_defaultViVCargo", (_defaults - _old) + _new];
            _message = "ViV resupply crates ready. Other cargo was kept.";
        } else {
            {deleteVehicle _x;} forEach _new;
            private _restored = true;
            {
                _x params ["_crate", "_hidden", "_simulation"];
                if !(_vehicle setVehicleCargo _crate) then {
                    _restored = false;
                    _crate setPosATL (_vehicle modelToWorld [8 + _forEachIndex * 2, 0, 0]);
                };
                _crate hideObjectGlobal _hidden;
                _crate enableSimulationGlobal _simulation;
            } forEach _states;
            _message = if (_restored) then {
                "Requested crates do not fit. Original crates and contents restored."
            } else {
                "Requested crates do not fit. Original supplies kept; check beside the aircraft for unloaded crates."
            };
        };
    };
    if (!isNull _vehicle) then {_vehicle setVariable ["TAE_repairBusy", false, true];};
    if (!isNull _pad) then {_pad setVariable ["TAE_aircraftBusy", false, true];};
    if (!isNull _actor) then {["TAE_aircraftNotice", [_message], _actor] call CBA_fnc_targetEvent;};
};
