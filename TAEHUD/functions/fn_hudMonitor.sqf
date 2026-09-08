if (!hasInterface || {isNull player}) exitWith {};

private _helmet = headgear player;
private _supported = _helmet isNotEqualTo "" && {
	getNumber (configFile >> "CfgWeapons" >> _helmet >> "TAE_HUD") > 0
};
private _enabled = missionNamespace getVariable ["TAE_HUD_enabled", true];
private _userEnabled = uiNamespace getVariable ["TAE_HUD_userEnabled", missionNamespace getVariable ["TAE_HUD_autoEnable", true]];
private _suspended = uiNamespace getVariable ["TAE_HUD_suspended", false];
private _shouldShow = _enabled && _userEnabled && _supported && alive player && !_suspended;
private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];

if (_shouldShow) then
{
	if (isNull _display) then
	{
		[] call TAE_fnc_hudShow;
	};
} else
{
	private _hasHandlers =
		(uiNamespace getVariable ["TAE_HUD_updatePFH", -1]) >= 0 ||
		{(uiNamespace getVariable ["TAE_HUD_compassPFH", -1]) >= 0} ||
		{(uiNamespace getVariable ["TAE_HUD_auxiliaryPFH", -1]) >= 0};

	if (!isNull _display || {_hasHandlers} || {uiNamespace getVariable ["TAE_HUD_visible", false]}) then
	{
		[] call TAE_fnc_hudHide;
	};
};
