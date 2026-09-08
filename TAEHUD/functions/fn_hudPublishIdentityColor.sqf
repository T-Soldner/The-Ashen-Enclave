if (!hasInterface || {isNull player}) exitWith {};

private _color = +(missionNamespace getVariable
[
	"TAE_HUD_identityColor",
	[0.95, 0.72, 0.14, 0.95]
]);

if (count _color < 4) then {_color pushBack 0.95;};
player setVariable ["TAE_HUD_identityColor", _color, true];

// Publish both identity settings on player changes and setting changes.
private _number = missionNamespace getVariable ["TAE_HUD_squadNumber", 1];
player setVariable ["TAE_HUD_squadNumber", _number, true];
