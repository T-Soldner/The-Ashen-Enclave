/*
 * Picks a placed vehicle back up into an inventory item.
 * Based on the 1st MEU pick_up vehicle helper.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Vehicle to delete <OBJECT>
 * 2: Item classname to add <STRING>
 */
params ["_unit", "_vehicle", "_itemClass"];

if (stance _unit == "STAND") then {
	[_unit, "AmovPercMstpSrasWrflDnon_diary"] call ace_common_fnc_doAnimation;
};

[
	{
		params ["_unit", "_vehicle", "_itemClass"];

		if (isNull _unit || {isNull _vehicle} || {!alive _vehicle}) exitWith {};

		{
			deleteVehicle _x;
		} forEach crew _vehicle;

		deleteVehicle _vehicle;
		[_unit, _itemClass] call ace_common_fnc_addToInventory;
	},
	[_unit, _vehicle, _itemClass],
	1
] call CBA_fnc_waitAndExecute;
