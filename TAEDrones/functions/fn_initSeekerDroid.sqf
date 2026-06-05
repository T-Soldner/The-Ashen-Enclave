/*
 * Applies droid-friendly crew/group labels and optional turret weapons.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Label <STRING> (default: "Seeker Droid")
 * 2: Replacement weapon classname <STRING> (optional)
 * 3: Replacement magazine classname <STRING> (optional)
 */
params ["_vehicle", ["_label", "Seeker Droid"], ["_weapon", ""], ["_magazine", ""]];

if (isNull _vehicle) exitWith {};

if (_weapon != "") then {
	{
		_vehicle removeWeaponTurret [_x, [0]];
	} forEach (_vehicle weaponsTurret [0]);

	_vehicle addWeaponTurret [_weapon, [0]];

	if (_magazine != "") then {
		_vehicle addMagazineTurret [_magazine, [0], 4];
	};
};

[
	{
		params ["_vehicle"];
		(!isNull _vehicle) && {{!isNull _x} count crew _vehicle > 0}
	},
	{
		params ["_vehicle", "_label"];

		if (isNull _vehicle) exitWith {};

		private _crew = crew _vehicle;
		if (_crew isEqualTo []) exitWith {};

		private _group = group (_crew select 0);
		if (!isNull _group) then {
			_group setGroupIdGlobal [_label];
		};

		{
			_x setName [_label, _label, ""];
		} forEach _crew;
	},
	[_vehicle, _label],
	5
] call CBA_fnc_waitUntilAndExecute;
