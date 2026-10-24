params [["_terminal", objNull, [objNull]]];
if (isNull _terminal || {is3DEN} || {!(_terminal isKindOf "TAE_GroundTerminal")}) exitWith {};
if (_terminal getVariable ["TAE_groundStarted", false]) exitWith {};
_terminal setVariable ["TAE_groundStarted", true];
waitUntil {sleep 0.1; time > 0};
if (isNull _terminal) exitWith {};
if (isServer) then {
    private _radius = (_terminal getVariable ["TAE_groundRadius", 12]) max 8;
    private _distance = (_terminal getVariable ["TAE_groundDistance", 20]) max (_radius + 6);
    private _pad = createVehicle ["Land_HelipadEmpty_F", [0,0,0], [], 0, "CAN_COLLIDE"];
    [_terminal, _pad, _distance, _terminal getVariable ["TAE_groundFacing", 0]] call TAE_fnc_positionTerminalSpawnPad;
    _terminal setVariable ["TAE_groundData", [_pad, _radius], true];
    _terminal addEventHandler ["Deleted", {
        private _data = (_this # 0) getVariable ["TAE_groundData", []];
        if (_data isNotEqualTo []) then {deleteVehicle (_data # 0);};
    }];
};
if (!hasInterface) exitWith {};
waitUntil {sleep 0.1; isNull _terminal || {!isNil {_terminal getVariable "TAE_groundData"}}};
if (isNull _terminal) exitWith {};
{
    private _label = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
    _terminal addAction [format ["Request %1", _label], {
        params ["_target", "_caller", "_id", "_class"];
        ["TAE_groundRequest", [_target, _caller, _class]] call CBA_fnc_serverEvent;
    }, _x, 1.5, false, true, "", "alive _this && {vehicle _this == _this}", 4];
} forEach (call TAE_fnc_getGroundVehicleClasses);
_terminal addAction ["Service Vehicle", {
    params ["_target", "_caller"];
    ["TAE_groundRequest", [_target, _caller, "service"]] call CBA_fnc_serverEvent;
}, nil, 1.4, false, true, "", "alive _this && {vehicle _this == _this}", 4];
_terminal addAction ["Put vehicle in storage", {
    params ["_target", "_caller"];
    [_target, _caller] spawn {
        params ["_terminal", "_caller"];
        if (["Put the vehicle in storage? This despawns it and discards its cargo and current state.", "Vehicle storage", true, true] call BIS_fnc_guiMessage) then {
            ["TAE_groundRequest", [_terminal, _caller, "store"]] call CBA_fnc_serverEvent;
        };
    };
}, nil, 1.2, false, true, "", "alive _this && {vehicle _this == _this}", 4];
