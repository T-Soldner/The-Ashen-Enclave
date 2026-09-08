private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display || {isNull player}) exitWith
{
	[] call TAE_fnc_hudDestroyCamera;
	[] call TAE_fnc_hudClearRadar;
};

private _mode = uiNamespace getVariable ["TAE_HUD_auxiliaryMode", 0];
private _background = _display displayCtrl 1300;
private _line = _display displayCtrl 1301;
private _map = _display displayCtrl 1302;
private _cameraControl = _display displayCtrl 1303;
private _title = _display displayCtrl 1304;
private _status = _display displayCtrl 1305;
private _active = _mode > 0;

// Keep the tracker header above its larger square; restore the map/camera layout.
private _headerY = safeZoneY + safeZoneH * (if (_mode isEqualTo 3) then {0.723} else {0.803});
private _headerX = safeZoneX + safeZoneW - safeZoneW * 0.210;
private _headerWidth = safeZoneW * 0.185;
if (_mode isEqualTo 3) then
{
	_headerWidth = safeZoneH * 0.220 * (pixelW / pixelH);
	_headerX = safeZoneX + safeZoneW * 0.975 - _headerWidth;
};
_title ctrlSetPosition [_headerX, _headerY, _headerWidth * 0.72, safeZoneH * 0.025];
_status ctrlSetPosition [_headerX + _headerWidth * 0.72, _headerY, _headerWidth * 0.28, safeZoneH * 0.025];
_title ctrlCommit 0;
_status ctrlCommit 0;

{
	_x ctrlShow _active;
} forEach [_background, _line, _title, _status];
_map ctrlShow (_mode isEqualTo 1);
_cameraControl ctrlShow (_mode isEqualTo 2);
(_display displayCtrl 1306) ctrlShow (_mode isEqualTo 3);
if (_mode isNotEqualTo 3) then {[] call TAE_fnc_hudClearRadar;};

if (_mode isEqualTo 3) exitWith
{
	_background ctrlShow false;
	_line ctrlShow false;
	[] call TAE_fnc_hudDestroyCamera;
	_title ctrlSetText "MOTION TRACKER";
	_status ctrlSetText format ["%1 M", missionNamespace getVariable ["TAE_HUD_radarRange", 50]];
	[] call TAE_fnc_hudUpdateRadar;
};

if (_mode isEqualTo 0) exitWith
{
	[] call TAE_fnc_hudDestroyCamera;
};

if (_mode isEqualTo 1) exitWith
{
	[] call TAE_fnc_hudDestroyCamera;
	_title ctrlSetText "GPS NAVIGATION";
	_status ctrlSetText format ["%1 KM/H", round (abs (speed (vehicle player)))];
	private _nextMapUpdate = uiNamespace getVariable ["TAE_HUD_nextMapUpdate", 0];
	if (diag_tickTime >= _nextMapUpdate) then
	{
		_map ctrlMapAnimAdd [0, 0.075, getPosASLVisual player];
		ctrlMapAnimCommit _map;
		uiNamespace setVariable ["TAE_HUD_nextMapUpdate", diag_tickTime + 0.10];
	};
};

_title ctrlSetText "HELMET CAMERA";
private _targets = (units group player) select
{
	_x isNotEqualTo player && {alive _x}
};

if (_targets isEqualTo []) exitWith
{
	_status ctrlSetText "NO CAMERA LINK";
	[] call TAE_fnc_hudDestroyCamera;
};

private _index = uiNamespace getVariable ["TAE_HUD_cameraTargetIndex", 0];
_index = _index mod (count _targets);
uiNamespace setVariable ["TAE_HUD_cameraTargetIndex", _index];
private _target = _targets # _index;
private _camera = uiNamespace getVariable ["TAE_HUD_auxiliaryCamera", objNull];

if (isNull _camera) then
{
	_camera = "camera" camCreate [0, 0, 0];
	_camera cameraEffect ["Internal", "Back", "TAE_HUD_HELMETCAM"];
	_camera camSetFov 0.82;
	_camera camCommit 0;
	uiNamespace setVariable ["TAE_HUD_auxiliaryCamera", _camera];
};

uiNamespace setVariable ["TAE_HUD_cameraTarget", _target];
private _direction = eyeDirection _target;
private _cameraPosition = (eyePos _target) vectorAdd (_direction vectorMultiply 0.12);
_camera setPosASL _cameraPosition;
_camera setVectorDirAndUp [_direction, vectorUp _target];
_status ctrlSetText format
[
	"%1 // %2 M",
	toUpper name _target,
	round (player distance _target)
];
