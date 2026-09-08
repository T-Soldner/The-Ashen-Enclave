if (isNull player) exitWith {};
private _range = missionNamespace getVariable ["TAE_HUD_radarRange", 50];
private _candidates = (player nearEntities [["Man", "Air", "Car", "Motorcycle", "Tank"], _range]) select
{
	_x isNotEqualTo vehicle player && {alive _x} && {!isObjectHidden _x}
};
private _handlers = uiNamespace getVariable ["TAE_HUD_radarHandlers", []];
private _retained = [];
{
	_x params ["_unit", "_event", "_id"];
	if (_unit in _candidates) then {_retained pushBack _x;} else
	{
		if (!isNull _unit) then {_unit removeEventHandler [_event, _id];};
	};
} forEach _handlers;
private _bound = _retained apply {_x # 0};
{
	if !(_x in _bound) then
	{
		private _event = if (_x isKindOf "Man") then {"FiredMan"} else {"Fired"};
		private _id = _x addEventHandler [_event,
		{
			params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo"];
			// Match TCP's sound thresholds, including integral suppression.
			// Muzzle brakes must not be treated as suppressors merely for occupying a slot.
			private _audible = configFile >> "CfgAmmo" >> _ammo >> "audibleFire";
			private _suppressed = isNumber _audible && {getNumber _audible < 5.5};
			if (_unit isKindOf "Man") then
			{
				private _attachment = (_unit weaponAccessories _muzzle) param [0, ""];
				if (_attachment isNotEqualTo "") then
				{
					private _coefficient = configFile >> "CfgWeapons" >> _attachment >> "ItemInfo" >> "AmmoCoef" >> "audibleFire";
					_suppressed = isNumber _coefficient && {getNumber _coefficient < 1};
				};
			};
			if (_suppressed) exitWith {};
			private _shots = uiNamespace getVariable ["TAE_HUD_radarShots", []];
			_shots = _shots select {(_x # 0) isNotEqualTo _unit && {(_x # 1) > diag_tickTime}};
			_shots pushBack [_unit, diag_tickTime + 0.5];
			uiNamespace setVariable ["TAE_HUD_radarShots", _shots];
		}];
		_retained pushBack [_x, _event, _id];
	};
} forEach _candidates;
uiNamespace setVariable ["TAE_HUD_radarHandlers", _retained];
uiNamespace setVariable ["TAE_HUD_radarCandidates", _candidates];
uiNamespace setVariable ["TAE_HUD_radarShots", (uiNamespace getVariable ["TAE_HUD_radarShots", []]) select
{
	(_x # 1) > diag_tickTime && {(_x # 0) in _candidates}
}];
