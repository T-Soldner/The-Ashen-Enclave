if (!isServer) exitWith {};

["TAE_barcStretcherRequest", {
    params ["_barc", "_actor", "_deploy"];
    if (isNull _barc || {isNull _actor}) exitWith {};
    if (!(_barc isKindOf "TAE_BARC_Stretcher") || {!alive _barc}) exitWith {};
    if (!alive _actor || {_actor distance _barc > 6}) exitWith {};

    private _key = "mti_armoury_vehicles_barc_stretcher";
    private _stretcher = _barc getVariable [_key, objNull];
    if (_deploy) then {
        // Keep MTI's attachment and destruction cleanup, but run it on the server.
        // The event handler executes unscheduled, so duplicate requests see this result.
        if (alive _stretcher) exitWith {};
        [_barc] call compileScript ["\z\mti_armoury\addons\vehicles\barc\XEH_stretcherBARC.sqf"];
    } else {
        if (isNull _stretcher || {crew _stretcher isNotEqualTo []}) exitWith {};
        deleteVehicle _stretcher;
        _barc setVariable [_key, nil, true];
    };
}] call CBA_fnc_addEventHandler;
