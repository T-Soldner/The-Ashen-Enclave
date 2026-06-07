TAE_medicalDiagnosticsEnabled = true;

["ace_medical_woundReceived", {
	params ["_unit", "_allDamages", "_shooter", "_ammo"];

	if (!TAE_medicalDiagnosticsEnabled || {!local _unit} || {!(_unit isKindOf "TAE_Unit_HitPoint_Base")}) exitWith {};

	private _weapon = if (isNull _shooter) then {""} else {currentWeapon _shooter};
	private _magazine = if (isNull _shooter) then {""} else {currentMagazine _shooter};
	private _ammoDamageType = getText (configFile >> "CfgAmmo" >> _ammo >> "ACE_damageType");
	private _magazineAmmo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");
	private _magazineDamageType = getText (configFile >> "CfgAmmo" >> _magazineAmmo >> "ACE_damageType");
	private _damageSummary = _allDamages apply {
		_x params ["_damage", "_bodyPart"];
		format ["%1:%2", _bodyPart, _damage]
	};

	private _message = format [
		"[TAE MED DIAG] ammo=%1 type=%2 weapon=%3 mag=%4 parts=%5 raw=%6",
		_ammo,
		_ammoDamageType,
		_weapon,
		_magazine,
		_damageSummary joinString ",",
		_allDamages
	];

	diag_log _message;
	if (_unit isEqualTo player) then {
		systemChat _message;
	};

	[{
		params ["_unit", "_ammo", "_ammoDamageType", "_weapon", "_magazine", "_magazineAmmo", "_magazineDamageType"];

		private _openWounds = _unit getVariable ["ace_medical_openWounds", createHashMap];
		private _woundClassNames = missionNamespace getVariable ["ace_medical_damage_woundClassNames", []];

		diag_log format [
			"[TAE MED DIAG WOUNDS] unit=%1 class=%2 ammo=%3 ammoType=%4 weapon=%5 magazine=%6 magazineAmmo=%7 magazineAmmoType=%8 woundClasses=%9 openWounds=%10",
			name _unit,
			typeOf _unit,
			_ammo,
			_ammoDamageType,
			_weapon,
			_magazine,
			_magazineAmmo,
			_magazineDamageType,
			_woundClassNames,
			_openWounds
		];
	}, [_unit, _ammo, _ammoDamageType, _weapon, _magazine, _magazineAmmo, _magazineDamageType]] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addEventHandler;

diag_log "[TAE MED DIAG] ACE wound diagnostics enabled for TAE units";
