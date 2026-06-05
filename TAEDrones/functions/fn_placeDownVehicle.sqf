/*
 * Places a carried vehicle item in front of a unit.
 * Based on the 1st MEU place_down vehicle helper.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Vehicle classname <STRING>
 * 2: Item classname to remove <STRING>
 */
params ["_unit", "_vehicleClass", "_itemClass"];

if (isNull _unit || {!([_unit, _itemClass] call ace_common_fnc_hasItem)}) exitWith {};

if (stance _unit == "STAND") then {
	[_unit, "AmovPercMstpSrasWrflDnon_diary"] call ace_common_fnc_doAnimation;
};

[
	{
		params ["_unit", "_vehicleClass", "_itemClass"];

		if (isNull _unit || {!isClass (configFile >> "CfgVehicles" >> _vehicleClass)} || {!([_unit, _itemClass] call ace_common_fnc_hasItem)}) exitWith {};

		private _direction = getDir _unit;
		private _position = getPosASL _unit vectorAdd [0.8 * sin _direction, 0.8 * cos _direction, 0.02];
		private _vehicle = _vehicleClass createVehicle [0, 0, 0];

		if (isNull _vehicle) exitWith {};

		createVehicleCrew _vehicle;
		private _group = createGroup [independent, true];
		{
			[_x] joinSilent _group;
		} forEach crew _vehicle;
		_unit removeItem _itemClass;

		_vehicle setDir _direction;
		_vehicle setPosASL _position;

		if ((getPosATL _vehicle select 2) - (getPos _vehicle select 2) < 1E-5) then {
			_vehicle setVectorUp (surfaceNormal (position _vehicle));
		};
	},
	[_unit, _vehicleClass, _itemClass],
	1
] call CBA_fnc_waitAndExecute;
