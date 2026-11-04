// Gregorian weekday and US Eastern DST, independent of the server timezone.
params ["_utc"];
_utc params ["_year", "_month", "_day", "_hour"];
private _weekday = {
    params ["_y", "_m", "_d"];
    if (_m < 3) then { _y = _y - 1; };
    (_y + floor (_y / 4) - floor (_y / 100) + floor (_y / 400) + ([0,3,2,5,0,3,5,1,4,6,2,4] select (_m - 1)) + _d) mod 7
};
private _marchSunday = 8 + ((7 - ([_year,3,1] call _weekday)) mod 7);
private _novemberSunday = 1 + ((7 - ([_year,11,1] call _weekday)) mod 7);
private _dst = (_month > 3 && {_month < 11}) ||
    {_month == 3 && {_day > _marchSunday || {_day == _marchSunday && {_hour >= 7}}}} ||
    {_month == 11 && {_day < _novemberSunday || {_day == _novemberSunday && {_hour < 6}}}};
private _localHour = _hour - ([5,4] select _dst);
private _localDay = [_year,_month,_day] call _weekday;
if (_localHour < 0) then {
    _localHour = _localHour + 24;
    _localDay = (_localDay + 6) mod 7;
};
_localDay == 6 && {(_localHour >= 14 && {_localHour < 17}) || {_localHour >= 19 && {_localHour < 22}}}
