params ["_display"];

if (isNull _display || {isNull player}) exitWith {};

private _groupUnits = units (group player);
private _trackedUnits = _groupUnits select {_x isNotEqualTo player && {!isNull _x}};
private _slotCount = 15;
private _visibleCount = (count _trackedUnits) min _slotCount;
private _hudColor = missionNamespace getVariable ["TAE_HUD_color", [0.95, 0.72, 0.14, 0.90]];
private _dimColor = +_hudColor;
_dimColor set [3, ((_hudColor # 3) * 0.72) min 1];

private _rowX = safeZoneX + (safeZoneW * 0.025);
private _arrowColumnWidth = safeZoneH * 0.022;
private _normalSpacing = safeZoneH * 0.032;
private _availableHeight = safeZoneH * 0.273;
private _rowSpacing = if (_visibleCount <= 7) then
{
	_normalSpacing
} else
{
	(_availableHeight / _visibleCount) min _normalSpacing
};
private _rowScale = ((_rowSpacing / _normalSpacing) max 0.58) min 1;
private _rowHeight = safeZoneH * 0.036 * _rowScale;
private _arrowSizeX = safeZoneH * 0.034 * _rowScale;
private _arrowSizeY = safeZoneH * 0.034 * _rowScale;
private _nameFontHeight = safeZoneH * 0.014 * _rowScale;
private _roleFontHeight = safeZoneH * 0.010 * _rowScale;
private _dataFontHeight = safeZoneH * 0.013 * _rowScale;
private _contentBottom = safeZoneY + safeZoneH - (safeZoneH * 0.051);
private _rowsHeight = if (_visibleCount > 0) then
{
	((_visibleCount - 1) * _rowSpacing) + _rowHeight
} else
{
	0
};
private _rowY = _contentBottom - _rowsHeight;
private _headerLineY = _rowY - (safeZoneH * 0.008);
private _headerY = _headerLineY - (safeZoneH * 0.026);

private _header = _display displayCtrl 1130;
_header ctrlSetPosition
[
	safeZoneX + (safeZoneW * 0.02),
	_headerY,
	safeZoneW * 0.22,
	safeZoneH * 0.024
];
_header ctrlCommit 0;

private _headerLine = _display displayCtrl 1230;
_headerLine ctrlSetPosition
[
	safeZoneX + (safeZoneW * 0.02),
	_headerLineY,
	safeZoneW * 0.22,
	safeZoneH * 0.002
];
_headerLine ctrlCommit 0;

private _nodeCount = count _groupUnits;
private _displayedNodeCount = _visibleCount + 1;
private _nodeLabel = if (_nodeCount > (_slotCount + 1)) then
{
	format ["%1/%2 NODES", _displayedNodeCount, _nodeCount]
} else
{
	format ["%1 %2", _nodeCount, ["NODE", "NODES"] select (_nodeCount isNotEqualTo 1)]
};
_header ctrlSetText format ["SQUAD LINK // %1", _nodeLabel];

for "_index" from 0 to (_slotCount - 1) do
{
	private _baseIdc = 2000 + (_index * 10);
	private _controls =
	[
		_display displayCtrl _baseIdc,
		_display displayCtrl (_baseIdc + 1),
		_display displayCtrl (_baseIdc + 2),
		_display displayCtrl (_baseIdc + 3),
		_display displayCtrl (_baseIdc + 4)
	];

	if (_index >= count _trackedUnits) then
	{
		{_x ctrlShow false;} forEach _controls;
	} else
	{
		private _unit = _trackedUnits # _index;
		private _y = _rowY + (_index * _rowSpacing);
		private _isDead = !alive _unit;
		private _isSpeaking = _unit getVariable ["TFAR_isSpeaking", false];
		private _identityColor = +(_unit getVariable ["TAE_HUD_identityColor", _hudColor]);
		if (count _identityColor < 4) then {_identityColor pushBack 0.95;};
		private _medicClass = _unit getVariable ["ace_medical_medicClass", _unit getUnitTrait "Medic"];
		private _engineerClass = _unit getVariable ["ACE_isEngineer", _unit getUnitTrait "Engineer"];
		if (_medicClass isEqualType true) then {_medicClass = [0, 1] select _medicClass;};
		if (_engineerClass isEqualType true) then {_engineerClass = [0, 1] select _engineerClass;};
		private _roles = [];
		if (_medicClass >= 1) then {_roles pushBack "MEDIC";};
		if (_engineerClass >= 1) then {_roles pushBack "ENGINEER";};
		private _isUnconscious = !_isDead &&
		{
			_unit getVariable ["ACE_isUnconscious", false] ||
			{lifeState _unit isEqualTo "INCAPACITATED"}
		};
		private _status = "AWAKE";
		private _statusColor = [0.25, 0.90, 0.45, 0.95];

		if (_isUnconscious) then
		{
			_status = "UNCON";
			_statusColor = [1.00, 0.24, 0.18, 0.98];
		};
		if (_isDead) then
		{
			_status = "DEAD";
			_statusColor = [0.55, 0.57, 0.60, 0.82];
		};

		{_x ctrlShow true;} forEach _controls;

		(_controls # 0) ctrlSetPosition
		[
			_rowX + ((_arrowColumnWidth - _arrowSizeX) / 2),
			_y + ((_rowHeight - _arrowSizeY) / 2),
			_arrowSizeX,
			_arrowSizeY
		];
		(_controls # 0) ctrlCommit 0;

		(_controls # 1) ctrlSetFontHeight _nameFontHeight;
		(_controls # 1) ctrlSetPosition
		[
			_rowX + _arrowColumnWidth + (safeZoneW * 0.004),
			_y - (safeZoneH * 0.005 * _rowScale),
			safeZoneW * 0.10,
			safeZoneH * 0.021 * _rowScale
		];
		(_controls # 1) ctrlCommit 0;

		(_controls # 2) ctrlSetFontHeight _dataFontHeight;
		(_controls # 2) ctrlSetPosition
		[
			_rowX + _arrowColumnWidth + (safeZoneW * 0.106),
			_y,
			safeZoneW * 0.043,
			_rowHeight
		];
		(_controls # 2) ctrlCommit 0;

		(_controls # 3) ctrlSetFontHeight _dataFontHeight;
		(_controls # 3) ctrlSetPosition
		[
			_rowX + _arrowColumnWidth + (safeZoneW * 0.151),
			_y,
			safeZoneW * 0.061,
			_rowHeight
		];
		(_controls # 3) ctrlCommit 0;

		(_controls # 4) ctrlSetFontHeight _roleFontHeight;
		(_controls # 4) ctrlSetPosition
		[
			_rowX + _arrowColumnWidth + (safeZoneW * 0.004),
			_y + (safeZoneH * 0.014 * _rowScale),
			safeZoneW * 0.10,
			safeZoneH * 0.014 * _rowScale
		];
		(_controls # 4) ctrlCommit 0;

		(_controls # 0) ctrlSetAngle [player getRelDir _unit, 0.5, 0.5];
		(_controls # 0) ctrlSetTextColor _identityColor;
		(_controls # 1) ctrlSetText format
		[
			["%1", "TX // %1"] select _isSpeaking,
			toUpper name _unit
		];
		(_controls # 1) ctrlSetTextColor _identityColor;
		(_controls # 2) ctrlSetText format ["%1 M", round (player distance _unit)];
		(_controls # 2) ctrlSetTextColor _dimColor;
		(_controls # 3) ctrlSetText _status;
		(_controls # 3) ctrlSetTextColor _statusColor;
		(_controls # 4) ctrlSetText (_roles joinString " // ");
		(_controls # 4) ctrlSetTextColor _dimColor;
	};
};
