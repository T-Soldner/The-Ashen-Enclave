params [
	["_unit", objNull, [objNull]],
	["_vehicle", objNull, [objNull]],
	["_cargoIndex", -1, [0]]
];

if (
	isNull _unit
	|| {isNull _vehicle}
	|| {!local _unit}
	|| {!alive _unit}
	|| {!alive _vehicle}
	|| {vehicle _unit isNotEqualTo _unit}
	|| {_unit distance _vehicle > 50}
	|| {isTouchingGround _unit}
	|| {(getPosATL _unit select 2) < 2}
	|| {isTouchingGround _vehicle}
	|| {(getPosATL _vehicle select 2) < 5}
	|| {(vectorMagnitude velocity _vehicle * 3.6) > 200}
) exitWith {};

_unit assignAsCargoIndex [_vehicle, _cargoIndex];
_unit moveInCargo [_vehicle, _cargoIndex, false];

if (vehicle _unit isEqualTo _vehicle) then {
	["You were recovered by the Kom'rk."] call TAE_fnc_showRecoveryMessage;
};
