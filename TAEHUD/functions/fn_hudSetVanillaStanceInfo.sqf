params [["_visible", true, [true]]];

private _aceSpeedIndicator = uiNamespace getVariable ["ace_ui_speedIndicator", controlNull];
if (!isNull _aceSpeedIndicator) then
{
	private _showAceSpeed = _visible &&
		{missionNamespace getVariable ["ace_ui_enableSpeedIndicator", true]};
	_aceSpeedIndicator ctrlShow _showAceSpeed;
	_aceSpeedIndicator ctrlSetFade ([1, 0] select _showAceSpeed);
	_aceSpeedIndicator ctrlCommit 0;

	if (_showAceSpeed && {!isNil "ace_ui_fnc_handleSpeedIndicator"} && {!isNull player}) then
	{
		[animationState player] call ace_ui_fnc_handleSpeedIndicator;
	} else
	{
		_aceSpeedIndicator ctrlSetText "";
	};
};

private _stanceDisplay = uiNamespace getVariable ["RscStanceInfo", displayNull];
if (isNull _stanceDisplay) then
{
	_stanceDisplay = uiNamespace getVariable ["BIS_RscStanceInfo_display", displayNull];
};
if (isNull _stanceDisplay) then
{
	_stanceDisplay = missionNamespace getVariable ["BIS_RscStanceInfo_display", displayNull];
};
if (isNull _stanceDisplay) then
{
	private _matches = allDisplays select
	{
		(_x getVariable ["BIS_fnc_initDisplay_configClass", ""]) isEqualTo "RscStanceInfo"
	};
	_stanceDisplay = _matches param [0, displayNull];
};
if (isNull _stanceDisplay) then
{
	_stanceDisplay = findDisplay 303;
};

if (isNull _stanceDisplay) exitWith {};

{
	_x ctrlShow _visible;
	_x ctrlSetFade ([1, 0] select _visible);
	_x ctrlCommit 0;
} forEach (allControls _stanceDisplay);

{
	private _control = _stanceDisplay displayCtrl _x;
	if (!isNull _control) then
	{
		_control ctrlShow _visible;
		_control ctrlSetFade ([1, 0] select _visible);
		_control ctrlCommit 0;
	};
} forEach [1201, 188];
