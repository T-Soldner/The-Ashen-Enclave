params ["_logic", "_synced", ["_activated", true]];
if (is3DEN || {!isServer} || {!_activated} || {isNull _logic}) exitWith {};
if (_logic getVariable ["TAE_populationStarted", false]) exitWith {};
_logic setVariable ["TAE_populationStarted", true];

[_logic] spawn {
    params ["_logic"];
    private _count = round ((_logic getVariable ["Count", 15]) max 5 min 40);
    private _vehicleCount = round ((_logic getVariable ["VehicleCount", 0]) max 0 min 10);
    private _vehiclePool = ["ls_vehicle_v35", "ls_vehicle_105kLancer_civ", "WM_74Z_Imperial_Brown",
        "JMSLLTE_C_veh_x34_F", "JMSLLTE_C_veh_g17_F", "JMSLLTE_C_veh_AA2_F",
        "JMSLLTE_C_veh_AA5_F", "JMSLLTE_C_veh_AA5sup_F"] select {
        isClass (configFile >> "CfgVehicles" >> _x)
    };
    private _waypointCount = round ((_logic getVariable ["Waypoints", 5]) max 1 min 20);
    private _pauseChance = (_logic getVariable ["PauseChance", 35]) max 0 min 100;
    private _center = getPosATL _logic;
    private _dimensions = _logic getVariable ["objectArea", [100,100,0,false,-1]];
    _dimensions params ["_a", "_b", "_angle", "_rectangle"];
    _a = _a max 5;
    _b = _b max 5;
    private _area = [_center, _a, _b, _angle, _rectangle];
    private _units = [];
    private _groups = [];
    private _states = [];
    private _vehicles = [];
    diag_log format ["[TAE] Civilian population: requested %1 pedestrians, %2 vehicles; available vehicle classes: %3.", _count, _vehicleCount, _vehiclePool];

    // Bounded rejection sampling: never substitute an unsafe out-of-area point.
    private _sample = {
        params ["_nearIcon", ["_driving", false]];
        private _result = [];
        for "_attempt" from 1 to 60 do {
            private _spawnRadius = if (_driving) then {15 + _vehicleCount * 3} else {15};
            private _x = (random 2 - 1) * (if (_nearIcon) then {_a min _spawnRadius} else {_a});
            private _y = (random 2 - 1) * (if (_nearIcon) then {_b min _spawnRadius} else {_b});
            private _pos = [(_center # 0) + _x * cos _angle + _y * sin _angle,
                (_center # 1) - _x * sin _angle + _y * cos _angle, 0];
            if (_pos inArea _area && {!surfaceIsWater _pos}) then {
                private _safe = _pos isFlatEmpty [if (_driving) then {6} else {1}, -1, 0.5, 2, 0, false];
                if (_safe isNotEqualTo [] && {_safe inArea _area} &&
                    {(_vehicles findIf {_x distance2D _safe < 12}) < 0} &&
                    {(_units findIf {_x distance2D _safe < (if (_driving) then {8} else {2})}) < 0}) exitWith {
                    _result = [_safe # 0, _safe # 1, 0];
                };
            };
        };
        _result
    };

    // Reserve vehicle clearance before pedestrians occupy the spawn area.
    for "_i" from 1 to _vehicleCount do {
        if (isNull _logic || {_vehiclePool isEqualTo []}) exitWith {};
        private _pos = [true, true] call _sample;
        if (_pos isNotEqualTo []) then {
            private _vehicle = createVehicle [selectRandom _vehiclePool, _pos, [], 0, "NONE"];
            _vehicle setDir _angle;
            _vehicle setVehicleAmmo 0;
            {
                _vehicle removeMagazinesTurret [_x # 0, _x # 1];
            } forEach (magazinesAllTurrets _vehicle);
            clearMagazineCargoGlobal _vehicle;
            clearWeaponCargoGlobal _vehicle;
            _vehicle limitSpeed 50;
            private _group = createGroup [civilian, true];
            private _driver = _group createUnit ["TAE_Unit_Civilian_Random", _pos, [], 0, "NONE"];
            _driver assignAsDriver _vehicle;
            _driver moveInDriver _vehicle;
            if (driver _vehicle != _driver) then {
                deleteVehicle _driver;
                deleteVehicle _vehicle;
                deleteGroup _group;
            } else {
                _group setBehaviourStrong "SAFE";
                _group setCombatMode "BLUE";
                _group setSpeedMode "LIMITED";
                _units pushBack _driver;
                _groups pushBack _group;
                _vehicles pushBack _vehicle;
                _states pushBack [_driver, [], [], [], 0, 0, _vehicle];
            };
        };
    };
    if (count _vehicles < _vehicleCount) then {
        diag_log format ["[TAE] Civilian vehicles: spawned %1/%2; check installed pool and clear space near module.", count _vehicles, _vehicleCount];
    };
    private _footCount = 0;
    for "_i" from 1 to _count do {
        if (isNull _logic) exitWith {};
        private _pos = [true] call _sample;
        if (_pos isNotEqualTo []) then {
            private _group = createGroup [civilian, true];
            private _unit = _group createUnit ["TAE_Unit_Civilian_Random", _pos, [], 0, "NONE"];
            _group setBehaviourStrong "SAFE";
            _group setSpeedMode "LIMITED";
            _group setCombatMode "BLUE";
            _unit forceWalk true;
            _units pushBack _unit;
            _groups pushBack _group;
            // Unit, route, active waypoint, destination, departure time, deadline.
            _states pushBack [_unit, [], [], [], 0, 0];
            _footCount = _footCount + 1;
        };
    };
    if (_footCount < _count) then {
        diag_log format ["[TAE] Civilian population: spawned %1/%2 pedestrians; insufficient safe ground near module.", _footCount, _count];
    };
    _logic setVariable ["TAE_populationUnits", _units];
    _logic setVariable ["TAE_populationVehicles", _vehicles];

    while {!isNull _logic} do {
        {
            _x params ["_unit", "_route", "_waypoint", "_destination", "_depart", "_deadline", ["_vehicle", objNull]];
            private _driving = !isNull _vehicle;
            if (alive _unit && {local _unit} && {!_driving || {alive _vehicle && {driver _vehicle == _unit}}}) then {
                if (_driving) then {_vehicle limitSpeed 50;};
                if (_waypoint isNotEqualTo []) then {
                    private _arrived = _unit distance2D _destination < (if (_driving) then {10} else {4});
                    if (_arrived || {time > _deadline}) then {
                        deleteWaypoint _waypoint;
                        _x set [2, []];
                        private _pause = if (_arrived && {random 100 < _pauseChance}) then {15 + random 105} else {0};
                        _x set [4, time + _pause];
                        if (_arrived) then {doStop _unit;};
                    };
                } else {
                    if (time >= _depart) then {
                        if (_route isEqualTo []) then {
                            for "_n" from 1 to _waypointCount do {
                                private _point = [false, _driving] call _sample;
                                if (_point isNotEqualTo []) then {_route pushBack _point;};
                            };
                            _x set [1, _route];
                        };
                        if (_route isNotEqualTo []) then {
                            private _point = _route deleteAt 0;
                            private _wp = (group _unit) addWaypoint [_point, 0];
                            _wp setWaypointType "MOVE";
                            _wp setWaypointSpeed "LIMITED";
                            _wp setWaypointCompletionRadius (if (_driving) then {8} else {3});
                            (group _unit) setCurrentWaypoint _wp;
                            _unit doMove _point;
                            _x set [2, _wp];
                            _x set [3, _point];
                            _x set [5, time + (120 max ((_unit distance2D _point) * 3))];
                        } else {_x set [4, time + 15];};
                    };
                };
            };
        } forEach _states;
        sleep 2;
    };
    // No automatic replacement of casualties. Deleting the module cleans its units.
    if (isNull _logic) then {{deleteVehicle _x;} forEach _units;};
    {deleteVehicle _x;} forEach _vehicles;
    {if (isNull _x || {units _x isEqualTo []}) then {deleteGroup _x;};} forEach _groups;
};
