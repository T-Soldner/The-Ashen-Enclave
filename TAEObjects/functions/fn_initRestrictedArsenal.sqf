params ["_box"];

if (isNull _box) exitWith {};

if (isServer) then {
	clearWeaponCargoGlobal _box;
	clearMagazineCargoGlobal _box;
	clearItemCargoGlobal _box;
	clearBackpackCargoGlobal _box;

	_box setVariable ["ace_dragging_canCarry", false, true];
	_box setVariable ["ace_dragging_canDrag", false, true];
	_box setVariable ["ace_cargo_canLoad", false, true];
	_box setVariable ["ace_cargo_size", -1, true];
};

private _items = call TAE_fnc_getArsenalItems;

if (isServer) then {
	[_box, true, true] call ace_arsenal_fnc_removeVirtualItems;
	[_box, _items, true] call ace_arsenal_fnc_initBox;
};

[_box] spawn {
	params ["_box"];

	waitUntil {
		sleep 0.1;
		isNull _box || {
			private _actions = _box getVariable ["ace_interact_menu_actions", []];
			(_actions findIf { ((_x select 0) select 0) == "ace_arsenal_interaction" }) != -1
		}
	};

	if (isNull _box) exitWith {};

	private _actions = _box getVariable ["ace_interact_menu_actions", []];
	private _arsenalActionIndex = _actions findIf { ((_x select 0) select 0) == "ace_arsenal_interaction" };

	if (_arsenalActionIndex != -1) then {
		((_actions select _arsenalActionIndex) select 0) set [1, "Open Ashen Enclave Arsenal"];
		_box setVariable ["ace_interact_menu_actions", _actions];
	};
};
