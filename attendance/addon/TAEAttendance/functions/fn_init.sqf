if (!isServer || {!isMultiplayer}) exitWith {};
if (missionNamespace getVariable ["TAEAttendance_initialized",false]) exitWith {};
TAEAttendance_initialized = true;
TAEAttendance_sequence = 0;
TAEAttendance_fnc_identity = {
    params ["_uid", "_name"];
    if (count _uid != 17 || {_name isEqualTo ""}) exitWith {};
    diag_log format ["TAE_IDENTITY_V1|%1|%2|END", _uid, ((toArray (_name select [0,100])) apply {str _x}) joinString ","];
};
TAEAttendance_session = format ["%1-%2-%3",(systemTimeUTC apply {str _x}) joinString "-",floor (diag_tickTime * 1000),floor random 1000000000];
addMissionEventHandler ["PlayerConnected", {
    params ["_id","_uid","_name"];
    [_uid,_name] call TAEAttendance_fnc_identity;
    ["JOIN",[_uid]] call TAEAttendance_fnc_writeEvent;
}];
addMissionEventHandler ["PlayerDisconnected", {
    params ["_id","_uid"];
    ["LEAVE",[_uid]] call TAEAttendance_fnc_writeEvent;
}];
addMissionEventHandler ["Ended", { ["END",[]] call TAEAttendance_fnc_writeEvent; }];
[] spawn {
    private _wasActive = false;
    private _knownNames = createHashMap;
    while {true} do {
        {
            private _uid = getPlayerUID _x;
            private _name = name _x;
            if ((_knownNames getOrDefault [_uid, ""]) != _name) then {
                [_uid,_name] call TAEAttendance_fnc_identity;
                _knownNames set [_uid,_name];
            };
        } forEach allPlayers;
        private _active = (missionNamespace getVariable ["TAEAttendance_manual",false]) || {[systemTimeUTC] call TAEAttendance_fnc_inWindow};
        if (_active) then {
            private _uids = [];
            {
                private _info = getUserInfo _x;
                if (count _info > 7 && {!(_info select 7)}) then { _uids pushBackUnique (_info select 2); };
            } forEach allUsers;
            ["PRESENCE",_uids] call TAEAttendance_fnc_writeEvent;
        };
        if (_wasActive && {!_active}) then { ["END",[]] call TAEAttendance_fnc_writeEvent; };
        _wasActive = _active;
        sleep 60;
    };
};
