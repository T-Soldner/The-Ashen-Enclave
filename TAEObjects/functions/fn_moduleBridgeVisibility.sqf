params [["_logic", objNull], ["_units", []], ["_activated", true]];
if (!_activated || {isNull _logic} || {is3DEN}) exitWith {};
if (_logic getVariable ["TAE_bridgeStarted", false]) exitWith {};
_logic setVariable ["TAE_bridgeStarted", true];

// Layer enumeration is server-side; publish references for existing and JIP clients.
if (isServer) then {
    waitUntil {sleep 0.1; time > 0 || {isNull _logic}};
    if (isNull _logic) exitWith {};
    private _exterior = missionNamespace getVariable [_logic getVariable ["Exterior", "TAE_Acclamator_Exterior"], objNull];
    private _width = _logic getVariable ["HalfWidth", 30];
    private _length = _logic getVariable ["HalfLength", 30];
    private _layer = getMissionLayerEntities (_logic getVariable ["InteriorLayer", "TAE_Bridge_Interior"]);
    private _height = _logic getVariable ["HalfHeight", 8];
    private _excluded = (_logic getVariable ["Exclusions", "BridgeShield,Bridge_Close_Ray,Bridge_Open_Ray"]) splitString ", ;";
    private _objects = (_layer param [0, []]) select {
        !isNull _x && {!(_x isKindOf "CAManBase")} && {!(_x isKindOf "Logic")} &&
        {!(_x isKindOf "EmptyDetector")} && {_x != _exterior} &&
        {!((vehicleVarName _x) in _excluded)}
    };
    if (isNull _exterior || {_objects isEqualTo []} || {_height <= 0} || {_width <= 0} || {_length <= 0}) exitWith {
        diag_log "[TAE Bridge] Invalid exterior, interior layer or zone dimensions. No visibility changes applied.";
        _logic setVariable ["TAE_bridgeData", [], true];
    };
    _logic setVariable ["TAE_bridgeData", [_exterior, _objects, _width, _length, _height], true];
};

// Include single-player/listen hosts; dedicated servers and headless clients stay unchanged.
if (!hasInterface) exitWith {};
waitUntil {sleep 0.1; isNull _logic || {!isNil {_logic getVariable "TAE_bridgeData"}}};
if (isNull _logic) exitWith {};
private _data = _logic getVariable ["TAE_bridgeData", []];
if (_data isEqualTo []) exitWith {};
_data params ["_exterior", "_objects", "_width", "_length", "_height"];
private _originalExterior = isObjectHidden _exterior;
private _originalInterior = _objects apply {isObjectHidden _x};
private _previous = -1;
while {!isNull _logic && {!isNull _exterior}} do {
    private _inside = !isNull player && {alive player} && {
        player inArea [getPosATL _logic, _width, _length, getDir _logic, true, _height]
    };
    // Zeus sees the unchanged composition; do not use the remote camera as player position.
    private _state = if (!isNull (findDisplay 312)) then {2} else {if (_inside) then {1} else {0}};
    if (_state != _previous) then {
        _exterior hideObject (if (_state == 2) then {_originalExterior} else {_originalExterior || {_inside}});
        {
            _x hideObject ((_originalInterior select _forEachIndex) || {_state == 0});
        } forEach _objects;
        _previous = _state;
    };
    sleep 0.25;
};
if (!isNull _exterior) then {_exterior hideObject _originalExterior;};
{if (!isNull _x) then {_x hideObject (_originalInterior select _forEachIndex);};} forEach _objects;
