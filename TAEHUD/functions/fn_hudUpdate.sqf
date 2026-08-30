private _unit = player;
private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display || {isNull _unit}) exitWith {};

[_display] call TAE_fnc_hudUpdateSquad;

private _inVehicle = (vehicle _unit) isNotEqualTo _unit;
{
	(_display displayCtrl _x) ctrlShow !_inVehicle;
} forEach [1120, 1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1202, 1203];

if (_inVehicle) exitWith
{
	[true] call TAE_fnc_hudSetVanillaWeaponInfo;
	[true] call TAE_fnc_hudSetVanillaStanceInfo;
};

[false] call TAE_fnc_hudSetVanillaWeaponInfo;
[false] call TAE_fnc_hudSetVanillaStanceInfo;

private _stanceName = toLower (stance _unit);
private _animation = toLower (animationState _unit);
private _adjustment = "";
{
	_x params ["_token", "_suffix"];
	if (_animation find _token >= 0) exitWith
	{
		_adjustment = _suffix;
	};
} forEach
[
	["dleft", "_left"],
	["dright", "_right"],
	["ddown", "_down"],
	["dup", "_up"]
];

private _isAlternativeRun = _animation in
[
	"arma_alternativerunwithlauncher",
	"arma_alternativepistol",
	"arma_alternativerun_water_light",
	"arma_alternativerun",
	"arma_alternativerunlowered",
	"arma_alternativerun_water_heavy",
	"arma_alternativerun_ww2style"
];

private _animationSpeed = _animation select [9, 3];
private _isProne = (_animation select [5, 3]) isEqualTo "pne";
private _speedLevel = if (_isProne) then
{
	switch (_animationSpeed) do
	{
		case "wlk": {1};
		case "run": {2};
		case "spr": {3};
		case "eva": {4};
		default {0};
	};
} else
{
	switch (_animationSpeed) do
	{
		case "wlk": {1};
		case "tac": {2};
		case "run": {3};
		case "eva": {4};
		default {0};
	};
};
if (_isAlternativeRun) then {_speedLevel = 4;};

private _speedIcon = if (_speedLevel > 0) then
{
	format ["\z\ace\addons\ui\ui\speed_indicator\%1_ca.paa", _speedLevel]
} else
{
	""
};
(_display displayCtrl 1127) ctrlSetText _speedIcon;

// Keep the display upright during vanilla sprints and Alternative Running's
// custom states, which can report an undefined or transient stance.
if ((_animation select [9, 3]) isEqualTo "eva" || {_isAlternativeRun}) then
{
	_stanceName = "stand";
	_adjustment = "";
};

private _stanceState = if (isWeaponDeployed _unit) then
{
	"deploy_"
} else
{
	["", "rest_"] select (isWeaponRested _unit)
};
private _stanceIcon = if (_stanceName in ["stand", "crouch", "prone"]) then
{
	format
	[
		"\a3\ui_f\data\igui\rscingameui\rscunitinfo\si_%1%2%3_ca.paa",
		_stanceState,
		_stanceName,
		_adjustment
	]
} else
{
	""
};
(_display displayCtrl 1120) ctrlSetText _stanceIcon;

private _throwable = currentThrowable _unit;
private _throwableMagazine = _throwable param [0, ""];

if (_throwableMagazine isEqualTo "") then
{
	(_display displayCtrl 1125) ctrlSetText "";
	(_display displayCtrl 1126) ctrlSetText "NO THROWABLE";
} else
{
	private _throwableConfig = configFile >> "CfgMagazines" >> _throwableMagazine;
	private _throwableName = getText (_throwableConfig >> "displayName");
	private _throwablePicture = getText (_throwableConfig >> "picture");
	private _throwableCount = {
		(_x param [0, ""]) isEqualTo _throwableMagazine
	} count (throwables _unit);

	(_display displayCtrl 1125) ctrlSetText _throwablePicture;
	(_display displayCtrl 1126) ctrlSetText format ["%1 x%2", toUpper _throwableName, _throwableCount];
};

private _weapon = currentWeapon _unit;

if (_weapon isEqualTo "") exitWith
{
	(_display displayCtrl 1121) ctrlSetText "UNARMED";
	(_display displayCtrl 1122) ctrlSetText "SAFE";
	(_display displayCtrl 1123) ctrlSetText "--";
	(_display displayCtrl 1124) ctrlSetText "0 MAGS // 0 RES";
	(_display displayCtrl 1128) ctrlSetText "RNG -- M";
};

private _weaponConfig = configFile >> "CfgWeapons" >> _weapon;
private _weaponName = getText (_weaponConfig >> "displayName");
private _weaponState = weaponState _unit;
private _mode = _weaponState param [2, "SAFE"];
private _magazine = _weaponState param [3, ""];
private _loadedAmmo = _weaponState param [4, 0];
private _zeroing = round (currentZeroing _unit);
private _modeLabel = toUpper ((_mode splitString "_") joinString " ");
private _normalizedMode = (_modeLabel splitString " ") joinString "";
if (_normalizedMode isEqualTo "FULLAUTO") then
{
	_modeLabel = "AUTO";
};

private _spareMagazines = (magazinesAmmoFull _unit) select
{
	(_x # 0) isEqualTo _magazine && {!(_x # 2)}
};
private _reserveAmmo = 0;
{
	_reserveAmmo = _reserveAmmo + (_x # 1);
} forEach _spareMagazines;

(_display displayCtrl 1121) ctrlSetText (toUpper _weaponName);
(_display displayCtrl 1122) ctrlSetText _modeLabel;
(_display displayCtrl 1123) ctrlSetText str _loadedAmmo;
(_display displayCtrl 1124) ctrlSetText format ["%1 MAGS // %2 RES", count _spareMagazines, _reserveAmmo];
(_display displayCtrl 1128) ctrlSetText (if (_zeroing > 0) then {format ["RNG %1 M", _zeroing]} else {"RNG -- M"});
