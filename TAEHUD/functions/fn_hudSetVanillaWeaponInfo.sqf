params [["_visible", true, [true]]];

// Restore only controls we changed, with their original visibility and fade.
private _saved = uiNamespace getVariable ["TAE_HUD_hiddenWeaponControls", []];
if (_visible) exitWith
{
	{
		_x params ["_control", "_shown", "_fade"];
		if (!isNull _control) then
		{
			_control ctrlShow _shown;
			_control ctrlSetFade _fade;
			_control ctrlCommit 0;
		};
	} forEach _saved;
	uiNamespace setVariable ["TAE_HUD_hiddenWeaponControls", []];
};

// Keep the info layer itself enabled for scope/binocular distance readouts.
// In-game UI layers are also registered separately by BIS_fnc_initDisplay.
// Multiple IDD 300 displays can coexist; the namespace handle may not be newest.
private _candidates = +allDisplays;
{_candidates pushBackUnique _x;} forEach (uiNamespace getVariable ["IGUI_displays", []]);
private _displays = _candidates select
{
	!isNull _x && {ctrlIDD _x isEqualTo 300 ||
	{(_x getVariable ["BIS_fnc_initDisplay_configClass", ""]) isEqualTo "RscUnitInfo"}
	}
};
private _info = uiNamespace getVariable ["RscUnitInfo", displayNull];
if (!isNull _info) then {_displays pushBackUnique _info;};
_info = findDisplay 300;
if (!isNull _info) then {_displays pushBackUnique _info;};
_saved = _saved select {!isNull (_x # 0)};
private _controls = [];
{
	private _display = _x;
	{
		private _control = _display displayCtrl _x;
		if (!isNull _control) then {_controls pushBackUnique _control;};
	} forEach [2302,2303,187,380,121,1004,1006];
	// Hide children as well: the engine can update their visibility independently.
	// Only zeroing, not the optic's CA_Distance (198).
	{
		if (ctrlClassName _x in [
			"CA_Zeroing", "CA_Weapon", "CA_ModeTexture", "CA_Mode",
			"CA_ValueReload", "CA_AmmoCount", "CA_MagCount", "CA_AmmoType",
			"CA_GrenadeType", "CA_GrenadeCount", "CA_GunnerWeapon",
			"CA_BackgroundWeapon", "CA_BackgroundWeaponTitle",
			"CA_BackgroundWeaponTitleDark", "CA_BackgroundWeaponMode"
		]) then {_controls pushBackUnique _x;};
	} forEach allControls _display;
	{
		private _group = _display displayCtrl _x;
		if (!isNull _group) then
		{
			private _arrows = _group controlsGroupCtrl 187;
			if (!isNull _arrows) then {_controls pushBackUnique _arrows;};
		};
	} forEach [2302,2303];
} forEach _displays;
// Capture all states before hiding parents, which can affect child visibility.
{
	private _control = _x;
	if ((_saved findIf {(_x # 0) isEqualTo _control}) < 0) then
	{
		_saved pushBack [_control, ctrlShown _control, ctrlFade _control];
	};
} forEach _controls;
{
	_x ctrlShow false;
	_x ctrlSetFade 1;
	_x ctrlCommit 0;
} forEach _controls;
uiNamespace setVariable ["TAE_HUD_hiddenWeaponControls", _saved];
