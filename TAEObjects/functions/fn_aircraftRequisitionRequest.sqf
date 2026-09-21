params [["_logic", objNull, [objNull]], ["_actor", objNull, [objNull]], ["_request", "", [""]], ["_payload", [], [[]]]];
if (!isServer || {isNull _logic} || {isNull _actor}) exitWith {};
if (!(_logic isKindOf "TAE_Module_AircraftRequisition")) exitWith {};
private _data = _logic getVariable ["TAE_requisitionData", []];
if (_data isEqualTo []) exitWith {};
_data params ["_terminal", "_pad", "_classes", "_radius", "_duration"];
if (isNull _terminal || {isNull _pad} || {!alive _actor} || {!isPlayer _actor} || {vehicle _actor != _actor} || {_actor distance _terminal > 5}) exitWith {};
private _notify = {params ["_text"]; ["TAE_aircraftNotice", [_text], _actor] call CBA_fnc_targetEvent;};
if (getNumber (configFile >> "CfgVehicles" >> typeOf _actor >> "ls_common_pilot") != 1) exitWith {["Pilot qualification required."] call _notify;};
if (_pad getVariable ["TAE_aircraftBusy", false]) exitWith {["Pad is busy."] call _notify;};
// nearestObjects includes wrecks, so a destroyed aircraft still blocks a new spawn.
private _near = nearestObjects [_pad, ["Air", "LandVehicle", "Ship", "CAManBase"], _radius, true];
_near = _near select {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15};
if !(_request in ["repair", "refuel", "rearm", "pylon"]) exitWith {
    if !(_request in _classes) exitWith {["Aircraft is not authorized for this terminal."] call _notify;};
    if (_near isNotEqualTo []) exitWith {["Pad occupied. Clear people, vehicles and wrecks first."] call _notify;};
    _pad setVariable ["TAE_aircraftBusy", true, true];
    private _aircraft = createVehicle [_request, ASLToAGL getPosASL _pad, [], 0, "CAN_COLLIDE"];
    if (!isNull _aircraft) then {
        _aircraft setDir getDir _pad;
        _aircraft setPosASL getPosASL _pad;
        _aircraft setVelocity [0,0,0];
        ["Aircraft ready on pad."] call _notify;
    } else {["Aircraft creation failed."] call _notify;};
    _pad setVariable ["TAE_aircraftBusy", false, true];
};
if (_request == "repair") exitWith {[_logic, _pad, _actor, _radius, _duration] call TAE_fnc_repairAircraftOnPad;};
[_logic, _pad, _actor, _radius, _request, _payload] call TAE_fnc_serviceAircraftOnPad;
