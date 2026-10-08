if (isNil "ls_common_fnc_hideHead") exitWith {};

TAE_fnc_rememberHelmetFace = {
	params ["_unit", ["_visibleFace", ""]];
	if (isNull _unit || {!local _unit}) exitWith {};
	if ((([_unit] call ls_common_fnc_getBiology) select 0) == "hologram") exitWith {};
	if (_visibleFace == "") then {_visibleFace = face _unit;};
	if (_visibleFace == "" || {toLower _visibleFace == "ls_hidehead"}) then {
		_visibleFace = _unit getVariable ["TAE_helmetVisibleFace", ""];
		if (_visibleFace == "") then {_visibleFace = _unit getVariable ["ls_common_oldFace", ""];};
	};
	if (_visibleFace == "" || {toLower _visibleFace == "ls_hidehead"}) exitWith {};
	if (_visibleFace != (_unit getVariable ["TAE_helmetVisibleFace", ""])) then {
		_unit setVariable ["TAE_helmetVisibleFace", _visibleFace, true];
	};
};

TAE_fnc_queueHelmetHeadRestore = {
	params ["_unit"];
	if (isNull _unit || {!local _unit}) exitWith {};
	[_unit] call TAE_fnc_rememberHelmetFace;
	private _restore = {
		params ["_unit"];
		if (isNull _unit || {!local _unit} || {!alive _unit}) exitWith {};
		if (getNumber (configFile >> "CfgWeapons" >> headgear _unit >> "ls_common_hideHead") == 1) exitWith {};
		if (toLower (face _unit) != "ls_hidehead") exitWith {};
		// Holograms intentionally use an invisible face even without these helmets.
		if ((([_unit] call ls_common_fnc_getBiology) select 0) == "hologram") exitWith {};
		private _savedFace = _unit getVariable ["TAE_helmetVisibleFace", ""];
		if (_savedFace == "" || {toLower _savedFace == "ls_hidehead"}) exitWith {};
		_unit setVariable ["ls_common_oldFace", _savedFace, true];
		[_unit, false] call ls_common_fnc_hideHead;
	};
	// Recheck after sling/loadout handlers and asynchronous face events settle.
	[_restore, [_unit]] call CBA_fnc_execNextFrame;
	[_restore, [_unit], 0.5] call CBA_fnc_waitAndExecute;
	[_restore, [_unit], 1.5] call CBA_fnc_waitAndExecute;
};

// Track LS face changes, using its saved face if another handler already hid the head.
["ls_common_setFace", {
	params ["_unit", "_newFace"];
	if (toLower _newFace == "ls_hidehead") then {
		[_unit] call TAE_fnc_rememberHelmetFace;
	} else {
		[_unit, _newFace] call TAE_fnc_rememberHelmetFace;
	};
}] call CBA_fnc_addEventHandler;

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

// Recover missed scripted removals, initial loadouts and locality transfers.
[{
	{
		if (local _x && {alive _x}) then {
			[_x] call TAE_fnc_rememberHelmetFace;
			if (toLower (face _x) == "ls_hidehead" && {getNumber (configFile >> "CfgWeapons" >> headgear _x >> "ls_common_hideHead") != 1}) then {
				[_x] call TAE_fnc_queueHelmetHeadRestore;
			};
		};
	} forEach allUnits;
}, 1] call CBA_fnc_addPerFrameHandler;
