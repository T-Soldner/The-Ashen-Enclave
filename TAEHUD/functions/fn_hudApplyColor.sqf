private _display = uiNamespace getVariable ["TAE_HUD_display", displayNull];
if (isNull _display) exitWith {};

private _color = missionNamespace getVariable ["TAE_HUD_color", [0.95, 0.72, 0.14, 0.90]];
private _dimColor = +_color;
_dimColor set [3, ((_color # 3) * 0.72) min 1];

{
	(_display displayCtrl _x) ctrlSetTextColor _color;
} forEach [1100, 1110, 1111, 1120, 1121, 1123, 1125, 1304];

{
	(_display displayCtrl _x) ctrlSetTextColor _dimColor;
} forEach [1101, 1122, 1124, 1126, 1127, 1128, 1305];

{
	(_display displayCtrl _x) ctrlSetBackgroundColor _color;
} forEach [1201, 1203, 1204, 1205, 1301];

for "_index" from 0 to 8 do
{
	(_display displayCtrl (1400 + _index)) ctrlSetTextColor _color;
	(_display displayCtrl (1500 + _index)) ctrlSetBackgroundColor _color;
};
(_display displayCtrl 1490) ctrlSetBackgroundColor _color;

(_display displayCtrl 1130) ctrlSetTextColor _color;
(_display displayCtrl 1230) ctrlSetBackgroundColor _color;

for "_index" from 0 to 14 do
{
	private _baseIdc = 2000 + (_index * 10);
	(_display displayCtrl _baseIdc) ctrlSetTextColor _color;
	(_display displayCtrl (_baseIdc + 1)) ctrlSetTextColor _color;
	(_display displayCtrl (_baseIdc + 2)) ctrlSetTextColor _dimColor;
	(_display displayCtrl (_baseIdc + 4)) ctrlSetTextColor _dimColor;
};
