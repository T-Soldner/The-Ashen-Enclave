params ["_logic"];
disableSerialization;
private _data = _logic getVariable ["TAE_requisitionData", []];
if (_data isEqualTo []) exitWith {};
_data params ["_terminal", "_pad", "_classes", "_radius"];
private _near = (nearestObjects [_pad, ["Air"], _radius, true]) select {alive _x && {abs ((getPosASL _x # 2) - (getPosASL _pad # 2)) < 15}};
if (count _near != 1) exitWith {systemChat "[Aircraft Service] Exactly one aircraft must be on the pad.";};
private _vehicle = _near # 0;
private _pylons = getAllPylonsInfo _vehicle;
if (_pylons isEqualTo []) exitWith {systemChat "[Aircraft Service] This aircraft has no pylons.";};
if (crew _vehicle isNotEqualTo [] || {isEngineOn _vehicle} || {vectorMagnitude velocity _vehicle > 0.5}) exitWith {
    systemChat "[Aircraft Service] Empty the aircraft, shut down its engine and let it stop first.";
};
private _component = configOf _vehicle >> "Components" >> "TransportPylonsComponent";
private _display = (findDisplay 46) createDisplay "RscDisplayEmpty";
_display setVariable ["TAE_context", [_logic, _vehicle, _pylons]];
private _left = safeZoneX + 0.06 * safeZoneW;
private _top = safeZoneY + 0.10 * safeZoneH;
private _width = 0.88 * safeZoneW;
private _height = 0.72 * safeZoneH;
private _background = _display ctrlCreate ["RscText", 100];
_background ctrlSetPosition [_left,_top,_width,_height];
_background ctrlSetBackgroundColor [0.12,0.12,0.12,1];
_background ctrlCommit 0;
private _title = _display ctrlCreate ["RscText", 101];
_title ctrlSetText format ["Configure pylons (%1)", getText (configOf _vehicle >> "displayName")];
_title ctrlSetPosition [_left,_top - 0.04 * safeZoneH,_width,0.04 * safeZoneH];
_title ctrlSetBackgroundColor [0.45,0.32,0.1,1];
_title ctrlCommit 0;
private _picture = _display ctrlCreate ["RscPicture", 102];
_picture ctrlSetText getText (_component >> "uiPicture");
_picture ctrlSetPosition [_left,_top,_width,_height];
_picture ctrlCommit 0;
private _configs = "true" configClasses (_component >> "Pylons");
private _controls = [];
{
    _x params ["_index", "_name", "_turret", "_original"];
    private _configIndex = _configs findIf {configName _x == _name};
    private _cfg = if (_configIndex >= 0) then {_configs # _configIndex} else {configNull};
    private _position = getArray (_cfg >> "UIposition");
    if (count _position != 2) then {_position = [0.05 + (_forEachIndex mod 3) * 0.25,0.05 + floor (_forEachIndex / 3) * 0.07];};
    // Pylon offsets use the same 0.75 by 0.65 reference picture as Eden.
    _position = _position apply {if (_x isEqualType "") then {call compile _x} else {_x}};
    private _combo = _display ctrlCreate ["RscCombo", 200 + _forEachIndex];
    private _comboWidth = 0.20 * safeZoneW;
    _combo ctrlSetPosition [
        _left + ((_position # 0) / 0.75 * _width max 0 min (_width - _comboWidth)),
        _top + ((_position # 1) / 0.65 * _height max 0 min (_height - 0.04 * safeZoneH)),
        _comboWidth,0.035 * safeZoneH
    ];
    _combo ctrlSetTooltip _name;
    _combo ctrlCommit 0;
    _combo lbAdd "<empty>";
    _combo lbSetData [0, ""];
    private _selected = 0;
    {
        private _row = _combo lbAdd getText (configFile >> "CfgMagazines" >> _x >> "displayName");
        _combo lbSetData [_row, _x];
        _combo lbSetTooltip [_row, _x];
        if (_x == _original) then {_selected = _row;};
    } forEach (_vehicle getCompatiblePylonMagazines _index);
    if (_original != "" && {_selected == 0}) then {
        _selected = _combo lbAdd getText (configFile >> "CfgMagazines" >> _original >> "displayName");
        _combo lbSetData [_selected, _original];
    };
    _combo lbSetCurSel _selected;
    _combo setVariable ["TAE_pylonIndex", _index];
    _controls pushBack [_combo, _index, getNumber (_cfg >> "mirroredMissilePos"), _original];
} forEach _pylons;
_display setVariable ["TAE_pylonControls", _controls];
private _mirror = _display ctrlCreate ["RscCheckBox", 103];
_mirror ctrlSetPosition [_left + _width - 0.03 * safeZoneW,_top + _height + 0.01 * safeZoneH,0.025 * safeZoneW,0.035 * safeZoneH];
_mirror ctrlCommit 0;
private _mirrorLabel = _display ctrlCreate ["RscText", 104];
_mirrorLabel ctrlSetText "Mirror";
_mirrorLabel ctrlSetPosition [_left + _width - 0.13 * safeZoneW,_top + _height + 0.01 * safeZoneH,0.10 * safeZoneW,0.035 * safeZoneH];
_mirrorLabel ctrlCommit 0;
private _syncMirror = {
        params ["_combo", "_selection"];
        private _display = ctrlParent _combo;
        if (_display getVariable ["TAE_syncing", false]) exitWith {};
        (_display displayCtrl 105) lbSetCurSel 0;
        if !(cbChecked (_display displayCtrl 103)) exitWith {};
        _display setVariable ["TAE_syncing", true];
        private _controls = _display getVariable "TAE_pylonControls";
        private _index = _combo getVariable "TAE_pylonIndex";
        private _row = _controls findIf {(_x # 1) == _index};
        private _partner = (_controls # _row) # 2;
        private _store = _combo lbData _selection;
        {
            if ((_x # 1) == _partner || {(_x # 2) == _index}) then {
                private _other = _x # 0;
                for "_i" from 0 to (lbSize _other - 1) do {
                    if (_other lbData _i == _store) exitWith {_other lbSetCurSel _i;};
                };
            };
        } forEach _controls;
        _display setVariable ["TAE_syncing", false];
};
_display setVariable ["TAE_syncMirror", _syncMirror];
{
    (_x # 0) ctrlAddEventHandler ["LBSelChanged", _syncMirror];
} forEach _controls;
_mirror ctrlAddEventHandler ["CheckedChanged", {
    params ["_ctrl", "_checked"];
    if (_checked != 1) exitWith {};
    private _display = ctrlParent _ctrl;
    {
        if ((_x # 2) == 0) then {
            private _combo = _x # 0;
            [_combo, lbCurSel _combo] call (_display getVariable "TAE_syncMirror");
        };
    } forEach (_display getVariable "TAE_pylonControls");
}];
private _presets = _display ctrlCreate ["RscCombo", 105];
_presets ctrlSetPosition [_left,_top + _height + 0.01 * safeZoneH,0.36 * safeZoneW,0.035 * safeZoneH];
_presets ctrlCommit 0;
_presets lbAdd "Custom";
private _presetValues = [[]];
{
    _presets lbAdd getText (_x >> "displayName");
    _presetValues pushBack getArray (_x >> "attachment");
} forEach ("true" configClasses (_component >> "Presets"));
_display setVariable ["TAE_presetValues", _presetValues];
_presets lbSetCurSel 0;
_presets ctrlAddEventHandler ["LBSelChanged", {
    params ["_ctrl", "_index"];
    if (_index <= 0) exitWith {};
    private _display = ctrlParent _ctrl;
    private _values = (_display getVariable "TAE_presetValues") # _index;
    _display setVariable ["TAE_syncing", true];
    {
        private _combo = _x # 0;
        private _store = _values param [_forEachIndex, ""];
        for "_i" from 0 to (lbSize _combo - 1) do {
            if (_combo lbData _i == _store) exitWith {_combo lbSetCurSel _i;};
        };
    } forEach (_display getVariable "TAE_pylonControls");
    _display setVariable ["TAE_syncing", false];
}];
private _apply = _display ctrlCreate ["RscButton", 106];
_apply ctrlSetText "Install loadout";
_apply ctrlSetTooltip "Crew takes 30 seconds per changed pylon.";
_apply ctrlSetPosition [_left + _width - 0.40 * safeZoneW,_top + _height + 0.06 * safeZoneH,0.24 * safeZoneW,0.04 * safeZoneH];
_apply ctrlCommit 0;
_apply ctrlAddEventHandler ["ButtonClick", {
    private _display = ctrlParent (_this # 0);
    (_display getVariable "TAE_context") params ["_logic", "_vehicle", "_pylons"];
    private _changes = [];
    {
        _x params ["_combo", "_index", "_mirror", "_original"];
        private _magazine = _combo lbData lbCurSel _combo;
        if (_magazine != _original) then {_changes pushBack [_index, _magazine];};
    } forEach (_display getVariable "TAE_pylonControls");
    if (_changes isEqualTo []) exitWith {systemChat "[Aircraft Service] No pylon changes selected.";};
    ["TAE_aircraftRequest", [_logic, player, "pylon", [_vehicle, _changes]]] call CBA_fnc_serverEvent;
    _display closeDisplay 1;
}];
private _cancel = _display ctrlCreate ["RscButton", 107];
_cancel ctrlSetText "Cancel";
_cancel ctrlSetPosition [_left + _width - 0.15 * safeZoneW,_top + _height + 0.06 * safeZoneH,0.15 * safeZoneW,0.04 * safeZoneH]; _cancel ctrlCommit 0;
_cancel ctrlAddEventHandler ["ButtonClick", {(ctrlParent (_this # 0)) closeDisplay 2;}];
