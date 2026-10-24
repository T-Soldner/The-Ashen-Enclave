params ["_class", "_pad"];
if (!isServer || {isNull _pad}) exitWith {objNull};
private _position = getPosASL _pad;
// Stage clear of deck geometry before placing the model with its own clearance.
private _vehicle = createVehicle [_class, ASLToAGL (_position vectorAdd [0,0,100]), [], 0, "CAN_COLLIDE"];
if (isNull _vehicle) exitWith {objNull};
_vehicle enableSimulationGlobal false;
_vehicle setDir getDir _pad;
_vehicle setVectorUp [0,0,1];
private _bounds = 2 boundingBoxReal _vehicle;
private _bottom = (_bounds # 0) # 2;
_position set [2, (_position # 2) - _bottom + 0.15];
_vehicle setPosASL _position;
_vehicle setVelocity [0,0,0];
_vehicle enableSimulationGlobal true;
_vehicle
