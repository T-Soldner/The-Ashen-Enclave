params ["_box"];
if (!isServer || {isNull _box} || {!(_box isKindOf "TAE_Demo_Crate" || {_box isKindOf "TAE_AT_Crate"} || {_box isKindOf "TAE_GL_Crate"})} || {_box getVariable ["TAE_ammoInitialized", false]}) exitWith {};
_box setVariable ["TAE_ammoInitialized", true];

private _items = call TAE_fnc_getArsenalItems;
private _glMagazines = [];
private _atMagazines = [];
private _antiTankCrate = _box isKindOf "TAE_AT_Crate";
private _glCrate = _box isKindOf "TAE_GL_Crate";
private _getMagazines = {
	params ["_muzzle"];
	private _magazines = getArray (_muzzle >> "magazines");
	{
		private _well = configFile >> "CfgMagazineWells" >> _x;
		{_magazines append getArray _x;} forEach (configProperties [_well, "isArray _x", true]);
	} forEach getArray (_muzzle >> "magazineWell");
	_magazines
};
private _isGrenadeLauncher = {
	params ["_config"];
	private _found = false;
	while {isClass _config && {!_found}} do {
		_found = toLower configName _config in ["grenadelauncher", "ugl_f"];
		_config = inheritsFrom _config;
	};
	_found
};
clearWeaponCargoGlobal _box;
clearItemCargoGlobal _box;
clearMagazineCargoGlobal _box;
clearBackpackCargoGlobal _box;
if (_antiTankCrate) then {
	{
		if (_x in _items && {isClass (configFile >> "CfgWeapons" >> _x)}) then {
			_box addWeaponCargoGlobal [_x, 4];
		};
	} forEach ["3AS_RPS6_G"];
};
// Alternate blaster/stun muzzles are not grenade launchers.
{
	private _weapon = configFile >> "CfgWeapons" >> _x;
	if (isClass _weapon) then {
		private _isLauncher = getNumber (_weapon >> "type") == 4;
		private _muzzles = getArray (_weapon >> "muzzles");
		if (_muzzles isEqualTo []) then {_muzzles = ["this"];};
		{
			private _muzzle = if (toLower _x == "this") then {_weapon} else {_weapon >> _x};
			private _isGL = [_muzzle] call _isGrenadeLauncher;
			if (_isGL) then {_glMagazines append ([_muzzle] call _getMagazines);};
			if (_isLauncher && {!_isGL}) then {_atMagazines append ([_muzzle] call _getMagazines);};
		} forEach _muzzles;
	};
} forEach _items;

private _throwableMagazines = [];
private _throw = configFile >> "CfgWeapons" >> "Throw";
{
	_throwableMagazines append ([_throw >> _x] call _getMagazines);
} forEach getArray (_throw >> "muzzles");
private _added = [];
{
	private _config = configFile >> "CfgMagazines" >> _x;
	if (isClass _config && {!(_x in _added)}) then {
		// Fuel cans are supplies, even if upstream registers them as throwable magazines.
		if (toLower _x == "knd_jetpacks_fuelcan") then {continue;};
		if (_antiTankCrate && {_x in ["mti_armoury_mag_paap", "mti_armoury_mag_patp"]}) then {continue;};
		if (_x in ["KND_82mm_HE_Carryable", "KND_82mm_Smoke_Carryable", "KND_82mm_Flare_Carryable"]) then {continue;};
		private _ammo = configFile >> "CfgAmmo" >> getText (_config >> "ammo");
		private _simulation = toLower getText (_ammo >> "simulation");
		private _isDemolition = _simulation in ["shotmine", "shotdirectionalbomb", "shotpipebomb"];
		private _isAT = _x in _atMagazines || {_simulation in ["shotrocket", "shotmissile"]};
		private _include = if (_antiTankCrate) then {_isAT} else {
			if (_glCrate) then {_x in _glMagazines} else {
				!_isAT && {!(_x in _glMagazines)} && {_isDemolition || {_x in _throwableMagazines}}
			}
		};
		if (_include) then {
			_box addMagazineCargoGlobal [_x, 20];
			_added pushBack _x;
		};
	};
} forEach _items;

if (_box isKindOf "TAE_Demo_Crate") then {
	{
		_x params ["_item", "_count"];
		if (_item in _items && {isClass (configFile >> "CfgWeapons" >> _item)}) then {
			_box addItemCargoGlobal [_item, _count];
		};
	} forEach [["mti_armoury_props_misc_clacker_item", 5], ["ACE_DefusalKit", 5], ["ACE_wirecutter", 4]];
};

{
	if (_antiTankCrate && {_x in _items} && {isClass (configFile >> "CfgWeapons" >> _x)}) then {
		_box addItemCargoGlobal [_x, 15];
	};
} forEach ["knd_z6rocket", "knd_z6rocket_AA", "knd_z6rocket_AT"];
