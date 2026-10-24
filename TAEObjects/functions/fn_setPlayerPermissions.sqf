params [
	["_unit", objNull, [objNull]],
	["_permission", "none", [""]]
];

if (isNull _unit || {!local _unit}) exitWith {};

// Role selections replace previous permissions, including Zeus-assigned MTI roles.
if (!isNil "mti_common_fnc_setUnitTrait") then {
	{
		[_unit, _x, false] call mti_common_fnc_setUnitTrait;
	} forEach ["medic", "demo", "tech", "pilot", "cqc"];
};
[_unit, "pilot", 0] call ls_common_fnc_setSkill;
_unit setVariable ["TAE_pilotPermission", false, true];
_unit setUnitTrait ["Medic", false];
_unit setUnitTrait ["Engineer", false];
_unit setUnitTrait ["ExplosiveSpecialist", false];
_unit setVariable ["ace_medical_medicClass", 0, true];
_unit setVariable ["ACE_IsEngineer", 0, true];
_unit setVariable ["ACE_isEOD", 0, true];

private _message = switch (toLower _permission) do {
	case "pilot": {
		if (!isNil "mti_common_fnc_setUnitTrait") then {
			[_unit, "pilot", true] call mti_common_fnc_setUnitTrait;
			[_unit, "tech", true] call mti_common_fnc_setUnitTrait;
		};
		[_unit, "pilot", 1] call ls_common_fnc_setSkill;
		_unit setVariable ["TAE_pilotPermission", true, true];
		_unit setUnitTrait ["Engineer", true];
		_unit setVariable ["ACE_IsEngineer", 1, true];
		"You are now authorized as a pilot and engineer."
	};
	case "engineer": {
		if (!isNil "mti_common_fnc_setUnitTrait") then {
			[_unit, "demo", true] call mti_common_fnc_setUnitTrait;
			[_unit, "tech", true] call mti_common_fnc_setUnitTrait;
		};
		_unit setUnitTrait ["Engineer", true];
		_unit setUnitTrait ["ExplosiveSpecialist", true];
		_unit setVariable ["ACE_IsEngineer", 1, true];
		_unit setVariable ["ACE_isEOD", 1, true];
		"You are now authorized as an engineer and explosives specialist."
	};
	case "medic": {
		_unit setUnitTrait ["Medic", true];
		_unit setVariable ["ace_medical_medicClass", 1, true];
		"You are now authorized as a medic."
	};
	default {
		"All special permissions removed."
	};
};

hint _message;
