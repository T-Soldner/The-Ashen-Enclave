params [["_unit", objNull, [objNull]]];
if (isNull _unit) exitWith {false};
if (!isNil "ls_common_fnc_getSkill" && {([_unit, "pilot"] call ls_common_fnc_getSkill) > 0}) exitWith {true};
getNumber (configOf _unit >> "ls_common_pilot") == 1
