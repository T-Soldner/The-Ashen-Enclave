private _classes = [
    "TAE_BARC_Stretcher", "TAE_CPH_Speeder", "TAE_Acklay_LIU", "TAE_PX10_R3",
    "TAE_PKV5_Cannon", "TAE_PKV5_Multi", "TAE_PKV5_MLRS", "TAE_PKV5_Mortar", "TAE_PKV5_AA"
];
_classes select {
    isClass (configFile >> "CfgVehicles" >> _x) &&
    {_x isKindOf "LandVehicle"} &&
    {getNumber (configFile >> "CfgVehicles" >> _x >> "scope") == 2}
}
