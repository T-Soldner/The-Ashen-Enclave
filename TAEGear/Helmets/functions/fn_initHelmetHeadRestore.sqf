if (isNil "ls_common_fnc_hideHead") exitWith {};

TAE_fnc_queueHelmetHeadRestore = {
	params ["_unit"];
	if (isNull _unit || {!local _unit}) exitWith {};
	private _restore = {
		params ["_unit"];
		if (isNull _unit || {!local _unit} || {!alive _unit}) exitWith {};
		if (getNumber (configFile >> "CfgWeapons" >> headgear _unit >> "ls_common_hideHead") == 1) exitWith {};
		if (toLower (face _unit) != "ls_hidehead") exitWith {};
		// Holograms intentionally use an invisible face even without these helmets.
		if ((([_unit] call ls_common_fnc_getBiology) select 0) == "hologram") exitWith {};
		private _savedFace = _unit getVariable ["ls_common_oldFace", ""];
		if (_savedFace == "" || {toLower _savedFace == "ls_hidehead"}) exitWith {};
		[_unit, false] call ls_common_fnc_hideHead;
	};
	// Recheck after sling/loadout handlers and asynchronous face events settle.
	[_restore, [_unit]] call CBA_fnc_execNextFrame;
	[_restore, [_unit], 0.5] call CBA_fnc_waitAndExecute;
};

["CAManBase", "SlotItemChanged", {
	params ["_unit", "_item", "_slot"];
	if (_slot != 605) exitWith {};
	[_unit] call TAE_fnc_queueHelmetHeadRestore;
}] call CBA_fnc_addClassEventHandler;

// HOA removes headgear by script; listen to its completion event explicitly.
["hoa_sling_helmetSlung", {
	params ["_unit"];
	[_unit] call TAE_fnc_queueHelmetHeadRestore;
}] call CBA_fnc_addEventHandler;
