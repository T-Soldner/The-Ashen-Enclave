{
	private _handler = uiNamespace getVariable [_x, -1];
	if (_handler >= 0) then
	{
		[_handler] call CBA_fnc_removePerFrameHandler;
		uiNamespace setVariable [_x, -1];
	};
} forEach
[
	"TAE_HUD_updatePFH",
	"TAE_HUD_compassPFH",
	"TAE_HUD_auxiliaryPFH"
];

uiNamespace setVariable ["TAE_HUD_auxiliaryPFHMode", 0];
[] call TAE_fnc_hudDestroyCamera;
[] call TAE_fnc_hudClearRadar;
