private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display || {isNull player}) exitWith
{
	[] call TAE_fnc_hudDestroyCamera;
	[] call TAE_fnc_hudClearRadar;
};
private _locations = [
	missionNamespace getVariable ["TAE_HUD_mapLocation", 0],
	missionNamespace getVariable ["TAE_HUD_cameraLocation", 0],
	missionNamespace getVariable ["TAE_HUD_trackerLocation", 0]
];
private _color = missionNamespace getVariable ["TAE_HUD_color", [0.95,0.72,0.14,0.9]];
private _font = missionNamespace getVariable ["TAE_HUD_font", "ls_republic"];
private _used = [0,0,0,0];
private _map = _display displayCtrl 1302;
private _cameraControl = _display displayCtrl 1303;
// Original decoration belongs to the camera; each panel has independent headings.
(_display displayCtrl 1300) ctrlShow false;
(_display displayCtrl 1301) ctrlShow false;
{
	private _index = _forEachIndex;
	private _location = _x;
	private _panel = _display displayCtrl ([1302,1303,1306] # _index);
	private _title = _display displayCtrl ([1314,1304,1324] # _index);
	private _status = _display displayCtrl ([1315,1305,1325] # _index);
	private _active = _location > 0;
	{_x ctrlShow _active;} forEach [_panel,_title,_status];
	if (_active) then
	{
		private _height = safeZoneH * ([0.140,0.140,0.220] # _index);
		private _width = if (_index isEqualTo 2) then {_height * pixelW / pixelH} else {safeZoneW * 0.185};
		private _total = _height + safeZoneH * 0.042;
		private _offset = _used # _location;
		private _left = switch (_location) do
		{
			case 2: {safeZoneX + (safeZoneW - _width)/2};
			case 3: {safeZoneX + safeZoneW * 0.020};
			default {safeZoneX + safeZoneW * 0.975 - _width};
		};
		private _top = if (_location isEqualTo 3) then
		{
			safeZoneY + safeZoneH * 0.115 + _offset
		} else {
			safeZoneY + safeZoneH * 0.975 - _offset - _total
		};
		_used set [_location, _offset + _total + safeZoneH * 0.012];
		_panel ctrlSetPosition [_left,_top + safeZoneH * 0.032,_width,_height];
		_title ctrlSetPosition [_left,_top,_width*0.62,safeZoneH*0.025];
		_status ctrlSetPosition [_left+_width*0.62,_top,_width*0.38,safeZoneH*0.025];
		{_x ctrlCommit 0;} forEach [_panel,_title,_status];
		{
			_x ctrlSetTextColor _color;
			_x ctrlSetFont _font;
		} forEach [_title,_status];
		_title ctrlSetText (["GPS NAVIGATION","HELMET CAMERA","MOTION TRACKER"] # _index);
	};
} forEach _locations;

if ((_locations # 2) > 0) then
{
	(_display displayCtrl 1325) ctrlSetText format ["%1 M", missionNamespace getVariable ["TAE_HUD_radarRange",50]];
	// Camera pose updates every frame; contact scans retain their 10 Hz cadence.
	if (diag_tickTime >= (uiNamespace getVariable ["TAE_HUD_nextRadarUpdate",0])) then
	{
		[] call TAE_fnc_hudUpdateRadar;
		uiNamespace setVariable ["TAE_HUD_nextRadarUpdate",diag_tickTime+0.10];
	};
} else {
	[] call TAE_fnc_hudClearRadar;
};
if ((_locations # 0) > 0) then
{
	(_display displayCtrl 1315) ctrlSetText format ["%1 KM/H", round (abs (speed (vehicle player)))];
	if (diag_tickTime >= (uiNamespace getVariable ["TAE_HUD_nextMapUpdate",0])) then
	{
		_map ctrlMapAnimAdd [0,0.075,getPosASLVisual player];
		ctrlMapAnimCommit _map;
		uiNamespace setVariable ["TAE_HUD_nextMapUpdate",diag_tickTime+0.10];
	};
};
if ((_locations # 1) isEqualTo 0) exitWith {[] call TAE_fnc_hudDestroyCamera;};
private _title = _display displayCtrl 1304;
private _status = _display displayCtrl 1305;
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
