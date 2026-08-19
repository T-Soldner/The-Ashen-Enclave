params [["_unit", objNull, [objNull]]];

if (isNull _unit || {!local _unit}) exitWith {};

_unit setDamage 0;

if (!isNil "ace_medical_treatment_fnc_fullHeal") then {
	[_unit, _unit] call ace_medical_treatment_fnc_fullHeal;
};

hint "You have been fully healed.";
