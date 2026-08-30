private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display || {isNull player}) exitWith {};

if ((vehicle player) isEqualTo player) then
{
	[false] call TAE_fnc_hudSetVanillaWeaponInfo;
	[false] call TAE_fnc_hudSetVanillaStanceInfo;
};

private _viewVector = getCameraViewDirection player;
private _heading = (((_viewVector # 0) atan2 (_viewVector # 1)) + 360) mod 360;
private _baseBearing = floor (_heading / 15) * 15;
private _cardinals = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"];
private _hudColor = missionNamespace getVariable ["TAE_HUD_color", [0.95, 0.72, 0.14, 0.90]];
private _centerX = safeZoneX + (safeZoneW * 0.50);
private _tapeWidth = safeZoneW * 0.40;
private _labelWidth = safeZoneW * 0.05;

private _formatBearing =
{
	private _text = str round _this;
	while {count _text < 3} do {_text = "0" + _text;};
	_text
};

for "_index" from 0 to 8 do
{
	private _bearing = (_baseBearing + ((_index - 4) * 15) + 360) mod 360;
	private _delta = (_bearing - _heading + 540) mod 360 - 180;
	private _x = _centerX + ((_delta / 120) * _tapeWidth);
	private _isCardinal = (_bearing mod 45) isEqualTo 0;
	private _labelText = if (_isCardinal) then
	{
		_cardinals # (_bearing / 45)
	} else
	{
		_bearing call _formatBearing
	};
	private _edgeAlpha = 1 - ((((abs _delta) - 45) max 0) / 20);
	_edgeAlpha = (_edgeAlpha max 0.15) min 1;
	private _color = +_hudColor;
	_color set [3, (_hudColor # 3) * _edgeAlpha];

	private _label = _display displayCtrl (1400 + _index);
	_label ctrlSetText _labelText;
	_label ctrlSetTextColor _color;
	_label ctrlSetPosition
	[
		_x - (_labelWidth / 2),
		safeZoneY + (safeZoneH * 0.055),
		_labelWidth,
		safeZoneH * 0.027
	];
	_label ctrlCommit 0;

	private _tickHeight = safeZoneH * ([0.008, 0.012] select _isCardinal);
	private _tick = _display displayCtrl (1500 + _index);
	_tick ctrlSetBackgroundColor _color;
	_tick ctrlSetPosition
	[
		_x - (safeZoneW * 0.0005),
		safeZoneY + (safeZoneH * 0.013),
		safeZoneW * 0.001,
		_tickHeight
	];
	_tick ctrlCommit 0;
};

private _roundedHeading = round _heading;
if (_roundedHeading >= 360) then {_roundedHeading = 0;};
(_display displayCtrl 1111) ctrlSetText format ["%1 DEG", _roundedHeading call _formatBearing];

private _playerPosition = getPosVisual player;
private _trackedUnits = (units group player) select {_x isNotEqualTo player && {!isNull _x}};
private _markerSlots = 15;

for "_index" from 0 to (_markerSlots - 1) do
{
	private _marker = _display displayCtrl (1600 + _index);
	if (_index >= count _trackedUnits) then
	{
		_marker ctrlShow false;
	} else
	{
		private _unit = _trackedUnits # _index;
		private _relativeVector = (getPosVisual _unit) vectorDiff _playerPosition;
		private _bearing = (((_relativeVector # 0) atan2 (_relativeVector # 1)) + 360) mod 360;
		private _delta = (_bearing - _heading + 540) mod 360 - 180;
		private _isVisible = abs _delta <= 60;

		if (!_isVisible) then
		{
			_marker ctrlShow false;
		} else
		{
			private _medicClass = _unit getVariable ["ace_medical_medicClass", _unit getUnitTrait "Medic"];
			if (_medicClass isEqualType true) then {_medicClass = [0, 1] select _medicClass;};
			private _isMedic = _medicClass >= 1;
			private _isDead = !alive _unit;
			private _markerSize = safeZoneH * ([0.014, 0.018] select _isMedic);
			private _markerColor = if (_isDead) then
			{
				[0.55, 0.57, 0.60, 0.72]
			} else
			{
				[[0.72, 0.88, 1.00, 0.95], [1.00, 0.20, 0.18, 0.98]] select _isMedic
			};
			private _edgeAlpha = 1 - ((((abs _delta) - 48) max 0) / 12);
			_markerColor set [3, (_markerColor # 3) * (_edgeAlpha max 0 min 1)];
			private _x = _centerX + ((_delta / 120) * _tapeWidth);

			_marker ctrlSetTextColor _markerColor;
			_marker ctrlSetPosition
			[
				_x - (_markerSize / 2),
				safeZoneY + (safeZoneH * 0.0195) - (_markerSize / 2),
				_markerSize,
				_markerSize
			];
			_marker ctrlShow true;
			_marker ctrlCommit 0;
		};
	};
};

private _waypointMarker = _display displayCtrl 1690;
private _waypointPosition = customWaypointPosition;
if (_waypointPosition isEqualTo []) then
{
	_waypointMarker ctrlShow false;
} else
{
	private _relativeVector = _waypointPosition vectorDiff _playerPosition;
	private _bearing = (((_relativeVector # 0) atan2 (_relativeVector # 1)) + 360) mod 360;
	private _delta = (_bearing - _heading + 540) mod 360 - 180;

	if (abs _delta > 60) then
	{
		_waypointMarker ctrlShow false;
	} else
	{
		private _markerSize = safeZoneH * 0.024;
		private _edgeAlpha = 1 - ((((abs _delta) - 48) max 0) / 12);
		private _x = _centerX + ((_delta / 120) * _tapeWidth);

		_waypointMarker ctrlSetTextColor [0.30, 0.62, 1.00, _edgeAlpha max 0 min 1];
		_waypointMarker ctrlSetPosition
		[
			_x - (_markerSize / 2),
			safeZoneY + (safeZoneH * 0.0195) - (_markerSize / 2),
			_markerSize,
			_markerSize
		];
		_waypointMarker ctrlShow true;
		_waypointMarker ctrlCommit 0;
	};
};
