params ["_display"];

if (isNull _display) exitWith {};

for "_index" from 0 to 8 do
{
	private _label = _display ctrlCreate ["TAE_HUD_CompassLabel", 1400 + _index];
	_label ctrlSetFont "EtelkaMonospacePro";
	_label ctrlSetFontHeight (safeZoneH * 0.018);
	_label ctrlSetPosition
	[
		safeZoneX + (safeZoneW * 0.475),
		safeZoneY + (safeZoneH * 0.055),
		safeZoneW * 0.05,
		safeZoneH * 0.027
	];
	_label ctrlCommit 0;

	private _tick = _display ctrlCreate ["RscText", 1500 + _index];
	_tick ctrlSetPosition
	[
		safeZoneX + (safeZoneW * 0.4995),
		safeZoneY + (safeZoneH * 0.013),
		safeZoneW * 0.001,
		safeZoneH * 0.008
	];
	_tick ctrlCommit 0;
};

private _centerMarker = _display ctrlCreate ["RscText", 1490];
_centerMarker ctrlSetPosition
[
	safeZoneX + (safeZoneW * 0.4995),
	safeZoneY + (safeZoneH * 0.013),
	safeZoneW * 0.001,
	safeZoneH * 0.012
];
_centerMarker ctrlCommit 0;

for "_index" from 0 to 14 do
{
	private _squadMarker = _display ctrlCreate ["RscPicture", 1600 + _index];
	_squadMarker ctrlSetText "\TAEHUD\data\squad_compass_diamond_ca.paa";
	_squadMarker ctrlSetPosition
	[
		safeZoneX + (safeZoneW * 0.493),
		safeZoneY + (safeZoneH * 0.0125),
		safeZoneH * 0.014,
		safeZoneH * 0.014
	];
	_squadMarker ctrlShow false;
	_squadMarker ctrlCommit 0;
};

private _waypointMarker = _display ctrlCreate ["RscPicture", 1690];
_waypointMarker ctrlSetText "\TAEHUD\data\waypoint_chevron_ca.paa";
_waypointMarker ctrlSetPosition
[
	safeZoneX + (safeZoneW * 0.488),
	safeZoneY + (safeZoneH * 0.0075),
	safeZoneH * 0.024,
	safeZoneH * 0.024
];
_waypointMarker ctrlSetTextColor [0.30, 0.62, 1.00, 1.00];
_waypointMarker ctrlShow false;
_waypointMarker ctrlCommit 0;
