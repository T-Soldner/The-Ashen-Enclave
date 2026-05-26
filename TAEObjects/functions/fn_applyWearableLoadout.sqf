params [
	["_unit", objNull, [objNull]],
	["_vest", "", [""]],
	["_helmet", "", [""]],
	["_nvg", "", [""]],
	["_goggles", "", [""]],
	["_uniform", "", [""]]
];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {
	_this remoteExecCall ["TAE_fnc_applyWearableLoadout", _unit];
};

if (_uniform != "") then {
	removeUniform _unit;
	_unit forceAddUniform _uniform;
};

removeVest _unit;
removeHeadgear _unit;
removeGoggles _unit;

if (_vest != "") then {
	_unit addVest _vest;
};

if (_helmet != "") then {
	_unit addHeadgear _helmet;
};

if (_nvg != "") then {
	_unit linkItem _nvg;
};

if (_goggles != "") then {
	_unit addGoggles _goggles;
};
