// Shared service worker. Uses the repair worker's locks to serialize all pad jobs.
params ["_logic", "_pad", "_actor", "_radius", "_operation", "_payload"];
if (!isServer) exitWith {};
private _notify = {params ["_text"]; ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;};
private _near = (nearestObjects [_pad, ["Air"], _radius, true]) select {alive _x && {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15}};
if (count _near != 1) exitWith {["Exactly one intact aircraft must be on the pad."] call _notify;};
private _vehicle = _near # 0;
if (_pad getVariable ["TAE_aircraftBusy", false] || {_vehicle getVariable ["TAE_repairBusy", false]}) exitWith {["Pad or aircraft is busy."] call _notify;};
if (crew _vehicle isNotEqualTo [] || {isEngineOn _vehicle} || {vectorMagnitude velocity _vehicle > 0.5}) exitWith {["Empty the aircraft, shut down its engine and let it stop before servicing."] call _notify;};
private _validPylon = true;
if (_operation == "pylon") then {
    _validPylon = false;
    if (count _payload == 3 && {(_payload # 0) isEqualType objNull} && {(_payload # 1) isEqualType 0} && {(_payload # 2) isEqualType ""}) then {
        _payload params ["_target", "_index", "_magazine"];
        _validPylon = _target == _vehicle && {(getAllPylonsInfo _vehicle) findIf {(_x # 0) == _index} >= 0} && {_magazine == "" || {_magazine in (_vehicle getCompatiblePylonMagazines _index)}};
    };
};
if (!_validPylon) exitWith {["Aircraft changed or pylon store is incompatible."] call _notify;};
_pad setVariable ["TAE_aircraftBusy", true, true];
_vehicle setVariable ["TAE_repairBusy", true, true];
[format ["Crew started %1.", _operation]] call _notify;
[_logic, _pad, _actor, _radius, _vehicle, _operation, _payload] spawn {
    params ["_logic", "_pad", "_actor", "_radius", "_vehicle", "_operation", "_payload"];
    _vehicle setOwner 2;
    private _deadline = diag_tickTime + 5;
    waitUntil {sleep 0.1; local _vehicle || {isNull _vehicle} || {diag_tickTime > _deadline}};
    private _ready = {
        !isNull _logic && {!isNull _pad} && {alive _vehicle} && {local _vehicle} && {crew _vehicle isEqualTo []} && {!isEngineOn _vehicle} && {vectorMagnitude velocity _vehicle <= 0.5} && {_vehicle distance2D _pad <= _radius} && {abs ((getPosASL _vehicle # 2) - (getPosASL _pad # 2)) < 15}
    };
    private _completed = false;
    switch (_operation) do {
        case "refuel": {
            while {call _ready && {fuel _vehicle < 1}} do {
                sleep 1;
                if (call _ready) then {_vehicle setFuel ((fuel _vehicle + 1/30) min 1);};
            };
            _completed = call _ready && {fuel _vehicle >= 1};
        };
        case "rearm": {
            // Keep mounted pylon stores separate from integral gun/countermeasure magazines.
            private _pylons = getAllPylonsInfo _vehicle;
            private _pylonClasses = _pylons apply {_x # 3};
            private _groups = [];
            private _collect = {
                params ["_config", "_path"];
                private _mags = getArray (_config >> "magazines");
                {
                    _x params ["_class", "_turret"];
                    if (_turret isEqualTo _path && {!(_class in _mags)}) then {_mags pushBack _class;};
                } forEach magazinesAllTurrets _vehicle;
                {
                    private _class = _x;
                    if (_class != "" && {!(_class in _pylonClasses)}) then {
                        private _count = {_x == _class} count _mags;
                        private _existing = {(_x # 0) == _class && {(_x # 1) isEqualTo _path}} count magazinesAllTurrets _vehicle;
                        _groups pushBack [_class, +_path, _count max _existing];
                    };
                } forEach (_mags arrayIntersect _mags);
                if !(_path isEqualTo [-1]) then {
                    {[_x, _path + [_forEachIndex]] call _collect;} forEach ("true" configClasses (_config >> "Turrets"));
                };
            };
            // Driver magazines live on the vehicle config; turret paths start at [], not [-1].
            [configOf _vehicle, [-1]] call _collect;
            {
                [_x, [_forEachIndex]] call _collect;
            } forEach ("true" configClasses (configOf _vehicle >> "Turrets"));
            private _jobs = (_groups apply {["magazine", _x]}) + ((_pylons select {(_x # 3) != ""}) apply {["pylon", _x]});
            _completed = call _ready;
            {
                private _end = diag_tickTime + 60 / ((count _jobs) max 1);
                waitUntil {sleep 0.25; !(call _ready) || {diag_tickTime >= _end}};
                if !(call _ready) exitWith {_completed = false;};
                _x params ["_kind", "_job"];
                if (_kind == "pylon") then {
                    _vehicle setAmmoOnPylon [_job # 0, getNumber (configFile >> "CfgMagazines" >> (_job # 3) >> "count")];
                } else {
                    _job params ["_class", "_path", "_count"];
                    if !(_vehicle turretLocal _path) exitWith {_completed = false;};
                    // Rebuild this class only, restoring expended reserve magazines as well.
                    _vehicle removeMagazinesTurret [_class, _path];
                    private _capacity = getNumber (configFile >> "CfgMagazines" >> _class >> "count");
                    for "_i" from 1 to _count do {_vehicle addMagazineTurret [_class, _path, _capacity];};
                };
                if (!_completed) exitWith {};
            } forEach _jobs;
        };
        case "pylon": {
            _payload params ["_target", "_index", "_magazine"];
            private _end = diag_tickTime + 30;
            waitUntil {sleep 0.25; !(call _ready) || {diag_tickTime >= _end}};
            if (call _ready) then {
                private _pylons = getAllPylonsInfo _vehicle;
                private _row = _pylons findIf {(_x # 0) == _index};
                if (_row >= 0 && {_magazine == "" || {_magazine in (_vehicle getCompatiblePylonMagazines _index)}}) then {
                    private _pylon = _pylons # _row;
                    private _oldWeapon = getText (configFile >> "CfgMagazines" >> (_pylon # 3) >> "pylonWeapon");
                    _completed = _vehicle setPylonLoadout [_index, _magazine, false, _pylon # 2];
                    // Never remove an integral weapon or one still used by another rack.
                    private _used = (getAllPylonsInfo _vehicle) findIf {getText (configFile >> "CfgMagazines" >> (_x # 3) >> "pylonWeapon") == _oldWeapon};
                    private _cfg = configOf _vehicle;
                    {if (_x >= 0) then {_cfg = ("true" configClasses (_cfg >> "Turrets")) # _x;};} forEach (_pylon # 2);
                    if (_completed && {_oldWeapon != ""} && {_used < 0} && {!(_oldWeapon in getArray (_cfg >> "weapons"))}) then {
                        private _path = _pylon # 2;
                        if (_path isEqualTo []) then {_path = [-1];};
                        _vehicle removeWeaponTurret [_oldWeapon, _path];
                    };
                };
            };
        };
    };
    if (!isNull _vehicle) then {_vehicle setVariable ["TAE_repairBusy", false, true];};
    if (!isNull _pad) then {_pad setVariable ["TAE_aircraftBusy", false, true];};
    if (!isNull _actor) then {
        ["TAE_aircraftNotice", [["Service interrupted; completed work retained.", "Service complete."] select _completed], _actor] call CBA_fnc_targetEvent;
    };
};
