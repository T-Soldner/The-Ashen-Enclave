params ["_terminal", "_pad", "_distance", "_facing"];
private _position = getPosASL _terminal;
private _heading = getDir _terminal;
_position set [0, (_position # 0) + sin _heading * _distance];
_position set [1, (_position # 1) + cos _heading * _distance];
// Preserve the terminal's absolute height without selecting another ship surface.
_pad setPosASL _position;
_pad setDir ((_heading + _facing) mod 360);
true
