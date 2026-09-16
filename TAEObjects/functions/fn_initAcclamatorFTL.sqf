// Sci-fi Support Plus builds these lists in preInit. Register locally on every
// machine in postInit so Zeus dialogs and ship faction checks agree, including JIP.
if (!isClass (configFile >> "CfgPatches" >> "PHAN_ScifiSupportPlus")) exitWith {};

private _listPairs = [
    ["PHAN_ALL_Ships_list", "PHAN_ALL_Ships_listDISPLAY"],
    ["PHAN_SW_Ships_list", "PHAN_SW_Ships_listDISPLAY"]
];

{
    _x params ["_classesName", "_labelsName"];
    private _classes = missionNamespace getVariable [_classesName, []];
    private _labels = missionNamespace getVariable [_labelsName, []];
    if (count _classes != count _labels) then {
        diag_log format ["[TAE] Skipping FTL registration: mismatched %1 / %2", _classesName, _labelsName];
    } else {
        {
            if !(_x in _classes) then {
                private _config = configFile >> "CfgVehicles" >> _x;
                _classes pushBack _x;
                _labels pushBack [getText (_config >> "displayName"), "", getText (_config >> "editorPreview"), [1, 1, 1, 1]];
            };
        } forEach ["TAE_Acclamator", "TAE_Acclamator_Landed"];
        missionNamespace setVariable [_classesName, _classes];
        missionNamespace setVariable [_labelsName, _labels];
    };
} forEach _listPairs;

private _republicShips = missionNamespace getVariable ["PHAN_Republic_FTL_ships_list", []];
{ _republicShips pushBackUnique _x; } forEach ["TAE_Acclamator", "TAE_Acclamator_Landed"];
missionNamespace setVariable ["PHAN_Republic_FTL_ships_list", _republicShips];
