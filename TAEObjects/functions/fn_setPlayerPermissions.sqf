params [
	["_unit", objNull, [objNull]],
	["_permission", "none", [""]]
];

if (isNull _unit || {!local _unit}) exitWith {};

private _message = switch (toLower _permission) do {
	case "engineer": {
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
		_unit setUnitTrait ["Medic", false];
		_unit setUnitTrait ["Engineer", false];
		_unit setUnitTrait ["ExplosiveSpecialist", false];
		_unit setVariable ["ace_medical_medicClass", 0, true];
		_unit setVariable ["ACE_IsEngineer", 0, true];
		_unit setVariable ["ACE_isEOD", 0, true];
		"All special permissions removed."
	};
};

hint _message;
