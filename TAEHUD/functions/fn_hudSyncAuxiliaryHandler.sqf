private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
private _mapOn = (missionNamespace getVariable ["TAE_HUD_mapLocation", 0]) > 0;
private _cameraOn = (missionNamespace getVariable ["TAE_HUD_cameraLocation", 0]) > 0;
private _radarOn = (missionNamespace getVariable ["TAE_HUD_trackerLocation", 0]) > 0;
private _mode = ([0, 1] select _mapOn) + ([0, 2] select _cameraOn) + ([0, 4] select _radarOn);
private _handler = uiNamespace getVariable ["TAE_HUD_auxiliaryPFH", -1];
private _handlerMode = uiNamespace getVariable ["TAE_HUD_auxiliaryPFHMode", 0];
private _shouldRun = !isNull _display && {_mode > 0};

if (_handler >= 0 && {_handlerMode isNotEqualTo _mode}) then
{
	[_handler] call CBA_fnc_removePerFrameHandler;
	_handler = -1;
	uiNamespace setVariable ["TAE_HUD_auxiliaryPFH", -1];
	uiNamespace setVariable ["TAE_HUD_auxiliaryPFHMode", 0];
};

if (_shouldRun && {_handler < 0}) then
{
	private _interval = [0.10, 0] select _cameraOn;
	_handler = [{[] call TAE_fnc_hudUpdateAuxiliary;}, _interval] call CBA_fnc_addPerFrameHandler;
	uiNamespace setVariable ["TAE_HUD_auxiliaryPFH", _handler];
	uiNamespace setVariable ["TAE_HUD_auxiliaryPFHMode", _mode];
};

if (!_shouldRun && {_handler >= 0}) then
{
	[_handler] call CBA_fnc_removePerFrameHandler;
	uiNamespace setVariable ["TAE_HUD_auxiliaryPFH", -1];
	uiNamespace setVariable ["TAE_HUD_auxiliaryPFHMode", 0];
};

if (isNull _display) then
{
	[] call TAE_fnc_hudDestroyCamera;
	[] call TAE_fnc_hudClearRadar;
} else
{
	[] call TAE_fnc_hudUpdateAuxiliary;
};
