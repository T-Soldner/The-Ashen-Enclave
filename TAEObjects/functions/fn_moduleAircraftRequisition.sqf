params [["_logic", objNull], ["_units", []], ["_activated", true]];
if (!_activated || {isNull _logic} || {is3DEN}) exitWith {};
if (!canSuspend) exitWith {_this spawn TAE_fnc_moduleAircraftRequisition;};
if (_logic getVariable ["TAE_requisitionStarted", false]) exitWith {};
_logic setVariable ["TAE_requisitionStarted", true];

if (isServer) then {
    private _isTerminal = _logic isKindOf "TAE_AircraftTerminal";
    private _mode = if (_isTerminal) then {_logic getVariable ["TAE_terminalMode", 1]} else {1};
    if (_mode == 0) exitWith {_logic setVariable ["TAE_requisitionData", [], true];};
    private _terminal = if (_isTerminal) then {_logic} else {missionNamespace getVariable [_logic getVariable ["Terminal", "TAE_AircraftTerminal"], objNull]};
    private _pad = missionNamespace getVariable [_logic getVariable ["Pad", "TAE_AircraftPad"], objNull];
    if (_isTerminal) then {
        // Keep a shared server-created anchor for spawning, service checks and JIP.
        private _radius = (_logic getVariable ["Radius", 30]) max 5;
        private _distance = (_logic getVariable ["TAE_spawnDistance", 40]) max (_radius + 6);
        private _heading = getDir _terminal;
        private _position = getPosATL _terminal;
        _position set [0, (_position # 0) + sin _heading * _distance];
        _position set [1, (_position # 1) + cos _heading * _distance];
        _pad = createVehicle ["Land_HelipadEmpty_F", _position, [], 0, "CAN_COLLIDE"];
        _pad setPosATL _position;
        _pad setDir ((_heading + (_logic getVariable ["TAE_spawnFacing", 0])) mod 360);
        _logic setVariable ["TAE_generatedAircraftPad", _pad];
        _logic addEventHandler ["Deleted", {
            deleteVehicle ((_this # 0) getVariable ["TAE_generatedAircraftPad", objNull]);
        }];
    };
    private _repairOnly = _mode == 2 || {getNumber (configOf _logic >> "TAE_repairOnly") == 1};
    private _classes = if (_repairOnly) then {[]} else {parseSimpleArray (_logic getVariable ["Aircraft", "[]"])};
    if (!_repairOnly && {_classes isEqualTo []}) then {
        _classes = ["TAE_VWing", "TAE_Delta7_Interceptor", "TAE_KomrkFighter_Transport", "TAE_Skycat_Transport", "TAE_Z98_Headhunter"];
    };
    private _valid = [];
    {
        if (_x isEqualType "" && {isClass (configFile >> "CfgVehicles" >> _x)} && {_x isKindOf "Air"} && {getNumber (configFile >> "CfgVehicles" >> _x >> "scope") == 2}) then {
            _valid pushBackUnique _x;
        } else {diag_log format ["[TAE Aircraft] Rejected aircraft classname: %1", _x];};
    } forEach _classes;
    if (isNull _terminal || {isNull _pad} || {_terminal == _pad} || {!isNull (_pad getVariable ["TAE_requisitionModule", objNull])}) exitWith {
        diag_log "[TAE Aircraft] Missing terminal/pad or pad already assigned. Module disabled.";
        _logic setVariable ["TAE_requisitionError", "Aircraft terminal: missing pad or pad already assigned. Check Eden settings.", true];
        _logic setVariable ["TAE_requisitionData", [], true];
    };
    _pad setVariable ["TAE_requisitionModule", _logic, true];
    _logic setVariable ["TAE_requisitionData", [_terminal, _pad, _valid, (_logic getVariable ["Radius", 30]) max 5, (_logic getVariable ["RepairSeconds", 60]) max 1], true];
};
if (!hasInterface) exitWith {};
waitUntil {sleep 0.1; isNull _logic || {!isNil {_logic getVariable "TAE_requisitionData"}}};
if (isNull _logic) exitWith {};
private _data = _logic getVariable ["TAE_requisitionData", []];
if (_data isEqualTo []) exitWith {
    if (_logic isKindOf "TAE_AircraftTerminal" && {!isNil {_logic getVariable "TAE_requisitionError"}}) then {
        _logic addAction ["Aircraft terminal: configuration problem", {
            systemChat ((_this # 0) getVariable ["TAE_requisitionError", "Check terminal Eden settings."]);
        }, nil, 1, false, true, "", "alive _this && {vehicle _this == _this}", 4];
    };
};
_data params ["_terminal", "_pad", "_classes"];
private _actions = [];
private _condition = "alive _this && {vehicle _this == _this} && {getNumber (configFile >> 'CfgVehicles' >> typeOf _this >> 'ls_common_pilot') == 1}";
{
    private _label = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
    _actions pushBack (_terminal addAction [format ["Request %1", _label], {
        params ["_target", "_caller", "_id", "_args"];
        _args params ["_logic", "_class"];
        ["TAE_aircraftRequest", [_logic, _caller, _class]] call CBA_fnc_serverEvent;
    }, [_logic, _x], 1.5, false, true, "", _condition, 4]);
} forEach _classes;
_actions pushBack (_terminal addAction ["Repair aircraft on pad", {
    params ["_target", "_caller", "_id", "_logic"];
    ["TAE_aircraftRequest", [_logic, _caller, "repair"]] call CBA_fnc_serverEvent;
}, _logic, 1.4, false, true, "", _condition, 4]);
{
    _actions pushBack (_terminal addAction [_x # 0, {
        params ["_target", "_caller", "_id", "_args"];
        _args params ["_logic", "_operation"];
        if (_operation == "pylon") then {[_logic] call TAE_fnc_aircraftPylonMenu;} else {
            ["TAE_aircraftRequest", [_logic, _caller, _operation]] call CBA_fnc_serverEvent;
        };
    }, [_logic, _x # 1], 1.3, false, true, "", _condition, 4]);
} forEach [["Refuel aircraft on pad", "refuel"], ["Rearm aircraft on pad", "rearm"], ["Change aircraft pylons", "pylon"]];
waitUntil {sleep 1; isNull _logic || {isNull _terminal} || {isNull _pad}};
if (!isNull _terminal) then {{_terminal removeAction _x;} forEach _actions;};
