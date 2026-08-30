private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display || {isNull player}) exitWith
{
	[] call TAE_fnc_hudDestroyCamera;
};

private _mode = uiNamespace getVariable ["TAE_HUD_auxiliaryMode", 0];
private _background = _display displayCtrl 1300;
private _line = _display displayCtrl 1301;
private _map = _display displayCtrl 1302;
private _cameraControl = _display displayCtrl 1303;
private _title = _display displayCtrl 1304;
private _status = _display displayCtrl 1305;
private _active = _mode > 0;

{
	_x ctrlShow _active;
} forEach [_background, _line, _title, _status];
_map ctrlShow (_mode isEqualTo 1);
_cameraControl ctrlShow (_mode isEqualTo 2);

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
