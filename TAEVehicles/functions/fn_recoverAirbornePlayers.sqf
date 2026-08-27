if (!isServer) exitWith {};

params [
	["_vehicle", objNull, [objNull]],
	["_pilot", objNull, [objNull]]
];

private _notifyPilot = {
	params ["_message"];
	[_message] remoteExecCall ["TAE_fnc_showRecoveryMessage", owner _pilot];
};

if (
	isNull _vehicle
	|| {isNull _pilot}
	|| {!alive _vehicle}
	|| {!alive _pilot}
	|| {currentPilot _vehicle isNotEqualTo _pilot}
) exitWith {
	["Recovery unavailable: pilot authorization failed."] call _notifyPilot;
};

private _speedKph = vectorMagnitude velocity _vehicle * 3.6;
if (
	!(isEngineOn _vehicle)
	|| {isTouchingGround _vehicle}
	|| {(getPosATL _vehicle select 2) < 5}
	|| {_speedKph > 200}
) exitWith {
	["Recovery unavailable: remain airborne and below 200 km/h."] call _notifyPilot;
};

private _availableAt = _vehicle getVariable ["TAE_recoveryAvailableAt", 0];
if (time < _availableAt) exitWith {
	["Recovery system is cycling."] call _notifyPilot;
};
_vehicle setVariable ["TAE_recoveryAvailableAt", time + 3, true];

private _emptySeats = fullCrew [_vehicle, "cargo", true] select {
	isNull (_x select 0) && {isNull (_x param [5, objNull])}
};
if (_emptySeats isEqualTo []) exitWith {
	["Recovery unavailable: no cargo seats are open."] call _notifyPilot;
};

private _candidates = allPlayers select {
	alive _x
	&& {vehicle _x isEqualTo _x}
	&& {_x distance _vehicle <= 50}
	&& {!isTouchingGround _x}
	&& {(getPosATL _x select 2) >= 2}
};
_candidates = [_candidates, [], {_x distance _vehicle}, "ASCEND"] call BIS_fnc_sortBy;

if (_candidates isEqualTo []) exitWith {
	["Recovery sweep found no airborne personnel within 50 meters."] call _notifyPilot;
};

private _recoveryCount = (count _candidates) min (count _emptySeats);
for "_index" from 0 to (_recoveryCount - 1) do {
	private _unit = _candidates select _index;
	private _cargoIndex = (_emptySeats select _index) select 2;
	[_unit, _vehicle, _cargoIndex] remoteExecCall ["TAE_fnc_boardRecoveredPlayer", owner _unit];
};

[format ["Recovery sweep engaged for %1 personnel.", _recoveryCount]] call _notifyPilot;
