params ["_map"];

if ((uiNamespace getVariable ["TAE_HUD_auxiliaryMode", 0]) isNotEqualTo 1) exitWith {};
if (isNull player) exitWith {};

private _hudColor = missionNamespace getVariable ["TAE_HUD_color", [0.95, 0.72, 0.14, 0.90]];
private _icon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";

_map drawIcon
[
	_icon,
	_hudColor,
	getPosASLVisual player,
	24,
	24,
	getDirVisual player,
	"",
	0,
	0.03,
	"RobotoCondensedBold",
	"center"
];

{
	private _identityColor = _x getVariable ["TAE_HUD_identityColor", _hudColor];
	_map drawIcon
	[
		_icon,
		_identityColor,
		getPosASLVisual _x,
		18,
		18,
		getDirVisual _x,
		toUpper name _x,
		1,
		0.025,
		"RobotoCondensed",
		"left"
	];
} forEach ((units group player) select {_x isNotEqualTo player && {alive _x}});
