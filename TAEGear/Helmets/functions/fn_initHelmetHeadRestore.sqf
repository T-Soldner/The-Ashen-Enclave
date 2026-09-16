if (isNil "ls_common_fnc_hideHead") exitWith {};

["CAManBase", "SlotItemChanged", {
	params ["_unit", "_item", "_slot"];
	if (!local _unit || {_slot != 605}) exitWith {};

	// Let LS and loadout handlers finish before checking the actual equipped helmet.
	[{
		params ["_unit"];
		if (isNull _unit || {!local _unit} || {!alive _unit}) exitWith {};
		if (getNumber (configFile >> "CfgWeapons" >> headgear _unit >> "ls_common_hideHead") == 1) exitWith {};
		if (toLower (face _unit) != "ls_hidehead") exitWith {};
		// Holograms intentionally use an invisible face even without these helmets.
		if ((([_unit] call ls_common_fnc_getBiology) select 0) == "hologram") exitWith {};
		private _savedFace = _unit getVariable ["ls_common_oldFace", ""];
		if (_savedFace == "" || {toLower _savedFace == "ls_hidehead"}) exitWith {};
		[_unit, false] call ls_common_fnc_hideHead;
	}, [_unit]] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addClassEventHandler;
