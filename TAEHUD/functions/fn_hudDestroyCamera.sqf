private _camera = uiNamespace getVariable ["TAE_HUD_auxiliaryCamera", objNull];
if (!isNull _camera) then
{
	_camera cameraEffect ["Terminate", "Back"];
	camDestroy _camera;
};

uiNamespace setVariable ["TAE_HUD_auxiliaryCamera", objNull];
uiNamespace setVariable ["TAE_HUD_cameraTarget", objNull];
