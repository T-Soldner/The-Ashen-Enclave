// Each client renders its own cosmetic UAV; no network position stepping.
params ["_marker", "_start", "_target", "_vehicle"];
if (!hasInterface || {isNull _marker}) exitWith {};
private _visual = createVehicleLocal ["3as_INDEP_ScavDroid", ASLToAGL _start, [], 0, "CAN_COLLIDE"];
if (isNull _visual) exitWith {};
_visual enableSimulation false;
_visual allowDamage false;
_visual disableCollisionWith _vehicle;
_visual setPosASL _start;
_visual setDir (_start getDir _target);
private _state = [_marker, _visual, _start, _target, diag_tickTime, false];
[
    {
        params ["_state", "_handle"];
        _state params ["_marker", "_visual", "_start", "_target", "_began", "_departing"];
        if (isNull _marker || {isNull _visual}) exitWith {
            deleteVehicle _visual;
            [_handle] call CBA_fnc_removePerFrameHandler;
        };
        if (!_departing && {_marker getVariable ["TAE_serviceDepart", false]}) then {
            _target = getPosASL _visual;
            _began = diag_tickTime;
            _departing = true;
            _state set [3, _target];
            _state set [4, _began];
            _state set [5, true];
            _visual setDir (_target getDir _start);
        };
        private _fraction = (((diag_tickTime - _began) / 8) max 0) min 1;
        // Smoothstep eases acceleration and deceleration at both ends.
        private _ease = _fraction * _fraction * (3 - 2 * _fraction);
        private _from = [_start, _target] select _departing;
        private _to = [_target, _start] select _departing;
        _visual setPosASL (_from vectorAdd ((_to vectorDiff _from) vectorMultiply _ease));
        if (_departing && {_fraction >= 1}) then {
            deleteVehicle _visual;
            [_handle] call CBA_fnc_removePerFrameHandler;
        };
    },
    0,
    _state
] call CBA_fnc_addPerFrameHandler;
