params [["_visible", true, [true]]];

private _hudState = shownHUD;
if (isNil {uiNamespace getVariable "TAE_HUD_savedVanillaInfo"}) then
{
	uiNamespace setVariable ["TAE_HUD_savedVanillaInfo", _hudState param [1, true]];
};
private _savedInfo = uiNamespace getVariable ["TAE_HUD_savedVanillaInfo", true];
_hudState set [1, _visible && _savedInfo];
showHUD _hudState;

private _unitInfoDisplay = uiNamespace getVariable ["RscUnitInfo", displayNull];

if (isNull _unitInfoDisplay) then
{
	private _matches = allDisplays select
	{
		(_x getVariable ["BIS_fnc_initDisplay_configClass", ""]) isEqualTo "RscUnitInfo"
	};
	_unitInfoDisplay = _matches param [0, displayNull];
};

if (isNull _unitInfoDisplay) then
{
	_unitInfoDisplay = findDisplay 300;
};

if (isNull _unitInfoDisplay) exitWith {};

{
	private _control = _unitInfoDisplay displayCtrl _x;
	if (!isNull _control) then
	{
		_control ctrlShow _visible;
		_control ctrlSetFade ([1, 0] select _visible);
		_control ctrlCommit 0;
	};
} forEach
[
	2302, // Infantry weapon panel
	2303, // Vehicle weapon panel
	187,  // Weapon-mode arrows (fallback for non-grouped layouts)
	168,  // Weapon zeroing
	380,  // Infantry freefall speed
	121,  // Vehicle speed value
	1004, // Vehicle speed unit
	1006  // Vehicle speed background
];

// The vanilla soldier HUD nests the mode arrows inside its weapon groups and
// can reshow that child independently of the parent control.
{
	private _group = _unitInfoDisplay displayCtrl _x;
	if (!isNull _group) then
	{
		private _modeTexture = _group controlsGroupCtrl 187;
		if (!isNull _modeTexture) then
		{
			_modeTexture ctrlShow _visible;
			_modeTexture ctrlSetFade ([1, 0] select _visible);
			_modeTexture ctrlCommit 0;
		};
	};
} forEach [2302, 2303];
