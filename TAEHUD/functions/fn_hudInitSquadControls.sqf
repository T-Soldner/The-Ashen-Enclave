params ["_display"];

if (isNull _display) exitWith {};

private _header = _display ctrlCreate ["RscText", 1130];
_header ctrlSetText "SQUAD LINK // 1 NODE";
_header ctrlSetFont "ls_republic";
_header ctrlSetFontHeight (safeZoneH * 0.016);
_header ctrlSetPosition
[
	safeZoneX + (safeZoneW * 0.02),
	safeZoneY + safeZoneH - (safeZoneH * 0.085),
	safeZoneW * 0.22,
	safeZoneH * 0.024
];
_header ctrlCommit 0;

private _headerLine = _display ctrlCreate ["RscText", 1230];
_headerLine ctrlSetPosition
[
	safeZoneX + (safeZoneW * 0.02),
	safeZoneY + safeZoneH - (safeZoneH * 0.059),
	safeZoneW * 0.22,
	safeZoneH * 0.002
];
_headerLine ctrlCommit 0;

private _arrowWidth = safeZoneH * 0.022;
private _arrowSizeX = safeZoneH * 0.034;
private _arrowSizeY = safeZoneH * 0.034;
private _rowHeight = safeZoneH * 0.036;
private _rowSpacing = safeZoneH * 0.032;
private _rowX = safeZoneX + (safeZoneW * 0.025);
private _rowY = safeZoneY + safeZoneH - (safeZoneH * 0.051);

for "_index" from 0 to 14 do
{
	private _baseIdc = 2000 + (_index * 10);
	private _y = _rowY + (_index * _rowSpacing);

	private _arrow = _display ctrlCreate ["RscPicture", _baseIdc];
	_arrow ctrlSetText "\TAEHUD\data\squad_direction_ca.paa";
	_arrow ctrlSetPosition
	[
		_rowX + ((_arrowWidth - _arrowSizeX) / 2),
		_y + ((_rowHeight - _arrowSizeY) / 2),
		_arrowSizeX,
		_arrowSizeY
	];
	_arrow ctrlCommit 0;

	private _name = _display ctrlCreate ["RscText", _baseIdc + 1];
	_name ctrlSetFont "ls_republic";
	_name ctrlSetFontHeight (safeZoneH * 0.014);
	_name ctrlSetPosition
	[
		_rowX + _arrowWidth + (safeZoneW * 0.004),
		_y - (safeZoneH * 0.005),
		safeZoneW * 0.10,
		safeZoneH * 0.021
	];
	_name ctrlCommit 0;

	private _role = _display ctrlCreate ["RscText", _baseIdc + 4];
	_role ctrlSetFont "ls_republic";
	_role ctrlSetFontHeight (safeZoneH * 0.010);
	_role ctrlSetPosition
	[
		_rowX + _arrowWidth + (safeZoneW * 0.004),
		_y + (safeZoneH * 0.014),
		safeZoneW * 0.10,
		safeZoneH * 0.014
	];
	_role ctrlCommit 0;

	private _distance = _display ctrlCreate ["RscText", _baseIdc + 2];
	_distance ctrlSetFont "ls_republic";
	_distance ctrlSetFontHeight (safeZoneH * 0.013);
	_distance ctrlSetPosition
	[
		_rowX + _arrowWidth + (safeZoneW * 0.106),
		_y,
		safeZoneW * 0.043,
		_rowHeight
	];
	_distance ctrlCommit 0;

	private _status = _display ctrlCreate ["RscText", _baseIdc + 3];
	_status ctrlSetFont "ls_republic";
	_status ctrlSetFontHeight (safeZoneH * 0.013);
	_status ctrlSetPosition
	[
		_rowX + _arrowWidth + (safeZoneW * 0.151),
		_y,
		safeZoneW * 0.061,
		_rowHeight
	];
	_status ctrlCommit 0;

	{
		_x ctrlShow false;
	} forEach [_arrow, _name, _distance, _status, _role];
};
