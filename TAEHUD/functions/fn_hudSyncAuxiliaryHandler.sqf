private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
private _mode = missionNamespace getVariable ["TAE_HUD_auxiliaryDisplay", 0];
uiNamespace setVariable ["TAE_HUD_auxiliaryMode", _mode];
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
	private _interval = [0.10, 0] select (_mode isEqualTo 2);
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
