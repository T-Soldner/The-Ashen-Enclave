disableSerialization;
params ["_display"];
diag_log "[TAE] Main menu spotlight setup started.";
private _deadline = diag_tickTime + 30;
private _ready = false;

// Spotlights are created after display load. Wait for our picture rather than
// racing the native menu initialization. The display onLoad retains BIS setup.
waitUntil {
    uiSleep 0.1;
    if (isNull _display) exitWith {true};
    _ready = !(((_display displayCtrl 1020) getVariable ["spotlights", []]) isEqualTo []);
    _ready || {diag_tickTime >= _deadline}
};
if (isNull _display) exitWith {};
if (!_ready) exitWith {diag_log "[TAE] Main menu spotlight setup timed out waiting for anchor 1020.";};

private _hiddenClasses = [
    "spotlight1", "spotlight2", "spotlight3",
    "spotlightprev", "spotlightnext",
    "backgroundspotlight", "backgroundspotlightleft", "backgroundspotlightright"
];
{
    if (toLower (ctrlClassName _x) in _hiddenClasses) then {
        _x ctrlShow false;
        _x ctrlEnable false;
    };
} forEach allControls _display;

// DLC/mod configurations can restore native controls or move the anchor.
{
    (_display displayCtrl _x) ctrlShow false;
    (_display displayCtrl _x) ctrlEnable false;
} forEach [1020, 1021, 1022, 1060, 1061];

{
    private _picture = _x controlsGroupCtrl 1023;
    if (toLower (ctrlText _picture) == "\taeinsignias\data\house_karr_logo_ca.paa") then {
        private _tile = _x;
        private _scale = 0.4875;
        // Scale every descendant in its parent's coordinate space, including
        // the hit target and nested picture/hover groups, to avoid cropping.
        {
            private _parent = ctrlParentControlsGroup _x;
            while {!isNull _parent && {_parent != _tile}} do {
                _parent = ctrlParentControlsGroup _parent;
            };
            if (_parent == _tile) then {
                _x ctrlSetPosition ((ctrlPosition _x) apply {_x * _scale});
                _x ctrlCommit 0;
                private _hoverPosition = _x getVariable ["pos", []];
                if !(_hoverPosition isEqualTo []) then {
                    _x setVariable ["pos", _hoverPosition apply {_x * _scale}];
                };
            };
        } forEach allControls _display;
        private _position = ctrlPosition _x;
        _position set [0, safeZoneX + safeZoneW * 0.025];
        _position set [1, safeZoneY + safeZoneH * 0.11];
        _position set [2, (_position select 2) * _scale];
        _position set [3, (_position select 3) * _scale];
        _x ctrlSetPosition _position;
        _x ctrlCommit 0;
    } else {
        _x ctrlShow false;
        _x ctrlEnable false;
    };
} forEach ((_display displayCtrl 1020) getVariable ["spotlights", []]);
diag_log "[TAE] Main menu spotlight layout applied.";
