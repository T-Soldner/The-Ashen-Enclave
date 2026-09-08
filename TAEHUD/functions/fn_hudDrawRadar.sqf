params ["_map"];
if (isNull player || {(uiNamespace getVariable ["TAE_HUD_auxiliaryMode", 0]) isNotEqualTo 3}) exitWith {};

// Use an off-terrain map as a drawing surface. Screen conversion keeps range
// calibration independent of terrain size, UI scale, and map zoom limits.
_map ctrlMapAnimAdd [0, 0.01, [-1000000, -1000000]];
ctrlMapAnimCommit _map;
private _rect = ctrlPosition _map;
private _cx = (_rect # 0) + (_rect # 2) / 2;
private _cy = (_rect # 1) + (_rect # 3) / 2;
// Triple the original size at 4K and preserve its screen proportion at other resolutions.
private _iconScale = 3 * (safeZoneH / pixelH) / 2160;
private _chevronLength = 5 * _iconScale;
// Leave scaled padding for contact chevrons at the range boundary.
private _ry = (((_rect # 3) / 2) min (((_rect # 2) / 2) * (pixelH / pixelW))) - 14 * _iconScale * pixelH;
private _rx = _ry * (pixelW / pixelH);
private _color = +(missionNamespace getVariable ["TAE_HUD_color", [0.95, 0.72, 0.14, 0.9]]);
private _center = _map ctrlMapScreenToWorld [_cx, _cy];
private _heading = (positionCameraToWorld [0,0,0]) getDir (positionCameraToWorld [0,0,10]);
private _range = missionNamespace getVariable ["TAE_HUD_radarRange", 50];
private _rings = if (_range isEqualTo 100) then {[0.25, 0.5, 0.75, 1]} else {[0.5, 1]};
private _ringHalfWidth = (safeZoneH / pixelH / 2160) max 0.5;
{
	private _fraction = _x;
	// Adjacent concentric strokes give the rings a resolution-scaled thickness.
	for "_offset" from (-_ringHalfWidth) to _ringHalfWidth step 0.5 do
	{
		private _ringX = _rx * _fraction + _offset * pixelW;
		private _ringY = _ry * _fraction + _offset * pixelH;
		private _last = _map ctrlMapScreenToWorld [_cx, _cy - _ringY];
		for "_angle" from 5 to 360 step 5 do
		{
			private _next = _map ctrlMapScreenToWorld [_cx + sin _angle * _ringX, _cy - cos _angle * _ringY];
			_map drawLine [_last, _next, _color];
			_last = _next;
		};
	};
} forEach _rings;
private _axisColor = +_color;
_axisColor set [3, (_color # 3) * 0.45];
private _font = missionNamespace getVariable ["TAE_HUD_font", "ls_republic"];
{
	private _bearing = _forEachIndex * 90 - _heading;
	for "_offset" from (-_ringHalfWidth) to _ringHalfWidth step 0.5 do
	{
		private _offsetX = cos _bearing * _offset * pixelW;
		private _offsetY = sin _bearing * _offset * pixelH;
		private _start = _map ctrlMapScreenToWorld [_cx + _offsetX, _cy + _offsetY];
		private _edge = _map ctrlMapScreenToWorld [_cx + sin _bearing * _rx + _offsetX, _cy - cos _bearing * _ry + _offsetY];
		_map drawLine [_start, _edge, _axisColor];
	};
	private _labelY = _ry + 8 * _iconScale * pixelH;
	private _labelX = _labelY * (pixelW / pixelH);
	private _labelPosition = _map ctrlMapScreenToWorld [_cx + sin _bearing * _labelX, _cy - cos _bearing * _labelY];
	_map drawIcon ["", _color, _labelPosition, 0, 0, 0, _x, 0, 0.035, _font, "center"];
} forEach ["N", "E", "S", "W"];
_map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _color, _center, 12 * _iconScale, 12 * _iconScale, 0];

private _shots = uiNamespace getVariable ["TAE_HUD_radarShots", []];
{
	private _unit = _x;
	private _distance = player distance _unit;
	if (!isNull _unit && {alive _unit} && {!isObjectHidden _unit} && {_distance <= _range}) then
	{
		private _velocity = velocity _unit;
		private _speed = 3.6 * vectorMagnitude _velocity;
		private _shotIndex = _shots findIf {(_x # 0) isEqualTo _unit};
		private _shotFade = if (_shotIndex < 0) then {0} else {(((_shots # _shotIndex) # 1) - diag_tickTime) / 0.5};
		private _isSquad = _unit in units group player;
		if (_isSquad || {_speed > 4.5} || {_shotFade > 0}) then
		{
			private _contactColor = [1, 0.75, 0.15, 1];
			if ((player knowsAbout _unit) > 0.1) then
			{
				_contactColor = if (((side group player) getFriend (side _unit)) >= 0.6) then {[0.25, 0.9, 0.45, 1]} else {[1, 0.2, 0.15, 1]};
			};
			if (_isSquad) then
			{
				private _medicClass = _unit getVariable ["ace_medical_medicClass", _unit getUnitTrait "Medic"];
				if (_medicClass isEqualType true) then {_medicClass = [0, 1] select _medicClass;};
				_contactColor = [[0.72, 0.88, 1.00, 0.95], [1.00, 0.20, 0.18, 0.98]] select (_medicClass >= 1);
			} else
			{
				_contactColor set [3, ((_speed / 10) max _shotFade) min 1];
			};
			private _bearing = (player getDir _unit) - _heading;
			private _position = _map ctrlMapScreenToWorld [_cx + sin _bearing * _rx * (_distance / _range), _cy - cos _bearing * _ry * (_distance / _range)];
			private _size = (if (_unit isKindOf "Man") then {7} else {10}) * _iconScale;
			_map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _contactColor, _position, _size, _size, 0];
			private _horizontalSpeed = sqrt ((_velocity # 0)^2 + (_velocity # 1)^2);
			if (_horizontalSpeed > 0.3) then
			{
				private _direction = ((_velocity # 0) atan2 (_velocity # 1)) - _heading;
				private _screen = [_cx + sin _bearing * _rx * (_distance / _range), _cy - cos _bearing * _ry * (_distance / _range)];
				// Place both chevron ends on the dot's radius.
				private _tipOffset = _chevronLength * cos 35 + sqrt (((_size / 2)^2 - (_chevronLength * sin 35)^2) max 0);
				private _tip = [(_screen # 0) + sin _direction * _tipOffset * pixelW, (_screen # 1) - cos _direction * _tipOffset * pixelH];
				private _tipWorld = _map ctrlMapScreenToWorld _tip;
				{
					private _end = _map ctrlMapScreenToWorld [(_tip # 0) - sin (_direction + _x) * _chevronLength * pixelW, (_tip # 1) + cos (_direction + _x) * _chevronLength * pixelH];
					_map drawLine [_tipWorld, _end, _contactColor];
				} forEach [-35, 35];
			};
		};
	};
} forEach (uiNamespace getVariable ["TAE_HUD_radarCandidates", []]);
