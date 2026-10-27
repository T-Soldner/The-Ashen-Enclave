params ["_terminal", "_pad", "_distance", "_facing"];
private _position = getPosASL _terminal;
private _heading = getDir _terminal;
_position set [0, (_position # 0) + sin _heading * _distance];
_position set [1, (_position # 1) + cos _heading * _distance];
// Search near the terminal's deck, not down through the ship to terrain.
private _surfaces = lineIntersectsSurfaces [
    _position vectorAdd [0,0,3], _position vectorAdd [0,0,-8],
    _terminal, _pad, true, 20, "GEOM", "NONE"
];
private _best = [];
private _difference = 1e10;
{
    _x params ["_hit", "_normal"];
    private _delta = abs ((_hit # 2) - (_position # 2));
    if ((_normal # 2) > 0.5 && {_delta < _difference}) then {
        _best = _hit;
        _difference = _delta;
    };
} forEach _surfaces;
// Terrain is a valid surface only when it is near the terminal's own level.
private _terrain = getTerrainHeightASL _position;
if (!surfaceIsWater _position && {abs (_terrain - (_position # 2)) <= 8} && {abs (_terrain - (_position # 2)) < _difference}) then {
    _best = [_position # 0, _position # 1, _terrain];
};
private _supported = _best isNotEqualTo [];
if (_supported) then {_position = _best;};
_pad setPosASL _position;
_pad setDir ((_heading + _facing) mod 360);
_pad setVariable ["TAE_spawnHasSurface", _supported];
_supported
