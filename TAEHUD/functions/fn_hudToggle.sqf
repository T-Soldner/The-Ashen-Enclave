if (!hasInterface || {isNull player}) exitWith {};

private _helmet = headgear player;
private _supported = _helmet isNotEqualTo "" && {
	getNumber (configFile >> "CfgWeapons" >> _helmet >> "TAE_HUD") > 0
};

if (!_supported) exitWith
{
	hintSilent "A compatible Mandalorian helmet is required.";
};

private _newState = !(uiNamespace getVariable ["TAE_HUD_userEnabled", true]);
uiNamespace setVariable ["TAE_HUD_userEnabled", _newState];

if (_newState) then
{
	[] call TAE_fnc_hudMonitor;
} else
{
	[] call TAE_fnc_hudHide;
};
