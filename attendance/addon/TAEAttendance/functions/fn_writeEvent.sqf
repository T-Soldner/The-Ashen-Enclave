params ["_kind", ["_uids", []]];
if (!isServer) exitWith {};
private _utc = systemTimeUTC;
if (!(missionNamespace getVariable ["TAEAttendance_manual",false]) && {!([_utc] call TAEAttendance_fnc_inWindow)} && {_kind != "END"}) exitWith {};
// Only numeric identities, no names or free text in the parseable payload.
_uids = _uids select {count _x == 17 && {(_x splitString "0123456789") isEqualTo []}};
TAEAttendance_sequence = TAEAttendance_sequence + 1;
diag_log format ["TAE_ATTENDANCE_V1|%1|%2|%3|%4|%5|END",TAEAttendance_session,TAEAttendance_sequence,(_utc apply {str _x}) joinString ",",_kind,_uids joinString ","];
