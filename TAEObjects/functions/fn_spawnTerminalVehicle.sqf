params ["_class", "_pad"];
if (!isServer || {isNull _pad}) exitWith {objNull};
private _elevation = if (_class isKindOf "TAE_KomrkFighter_Transport") then {2} else {1};
private _position = (getPosASL _pad) vectorAdd [0,0,_elevation];
private _vehicle = createVehicle [_class, ASLToAGL _position, [], 0, "CAN_COLLIDE"];
if (isNull _vehicle) exitWith {objNull};
_vehicle enableSimulationGlobal false;
_vehicle setDir getDir _pad;
_vehicle setVectorUp [0,0,1];
_vehicle setPosASL _position;
_vehicle setVelocity [0,0,0];
_vehicle enableSimulationGlobal true;
_vehicle
