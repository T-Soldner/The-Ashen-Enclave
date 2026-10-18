// Cosmetic UAV objects, not infantry agents; service never waits for them.
params ["_vehicle"];
if (!isServer || {isNull _vehicle} || {!isClass (configFile >> "CfgVehicles" >> "3as_INDEP_ScavDroid")}) exitWith {[]};
private _bounds = boundingBoxReal _vehicle;
private _min = _bounds # 0;
private _max = _bounds # 1;
private _width = (abs (_min # 0) max abs (_max # 0)) + 2;
private _length = (abs (_min # 1) max abs (_max # 1)) + 2;
private _height = if ((["TAE_Delta7_Interceptor", "TAE_Z98_Headhunter", "TAE_VWing"] findIf {_vehicle isKindOf _x}) >= 0) then {1} else {2};
private _rotation = random 360;
private _droids = [];
for "_i" from 0 to 2 do {
    // Three separated sectors with jitter guarantee at least 40 degrees separation.
    private _angle = _rotation + 120 * _i + random 80;
    private _offset = [sin _angle * _width, cos _angle * _length, 0];
    private _target = _vehicle modelToWorldWorld _offset;
    private _start = _vehicle modelToWorldWorld [(_offset # 0) + sin _angle * 8, (_offset # 1) + cos _angle * 8, 0];
    _start = _start vectorAdd [0,0,_height];
    _target = _target vectorAdd [0,0,_height];
    {
        private _terrain = getTerrainHeightASL _x;
        _x set [2, (_x # 2) max (_terrain + _height)];
    } forEach [_start, _target];
    private _droid = createVehicle ["3as_INDEP_ScavDroid", ASLToAGL _start, [], 0, "CAN_COLLIDE"];
        if (!isNull _droid) then {
            _droid enableSimulationGlobal false;
            _droid hideObjectGlobal true;
            _droid setPosASL _start;
            _droid allowDamage false;
            _droid disableCollisionWith _vehicle;
            _droid setVehicleAmmo 0;
            _droid setDir (_start getDir _target);
            _droids pushBack _droid;
            ["TAE_serviceDroidVisual", [_droid, _start, _target, _vehicle]] call CBA_fnc_globalEvent;
            [_droid, _start, _target, _vehicle] spawn {
                params ["_droid", "_start", "_target", "_vehicle"];
                private _began = diag_tickTime;
                while {!isNull _droid && {diag_tickTime - _began < 8} && {!(_droid getVariable ["TAE_serviceDepart", false])} && {alive _vehicle}} do {
                    sleep 0.1;
                };
                if (isNull _droid) exitWith {};
                waitUntil {sleep 0.2; isNull _droid || {!alive _vehicle} || {_droid getVariable ["TAE_serviceDepart", false]} || {diag_tickTime - _began > 1800}};
                if (isNull _droid) exitWith {};
                _droid setVariable ["TAE_serviceDepart", true, true];
                _began = diag_tickTime;
                while {!isNull _droid && {diag_tickTime - _began < 8}} do {
                    sleep 0.1;
                };
                deleteVehicle _droid;
            };
        };
};
_droids
