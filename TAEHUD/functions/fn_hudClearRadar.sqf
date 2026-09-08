// Own only this display's local firing handlers; remove them on mode change/unload.
{
	_x params ["_unit", "_event", "_id"];
	if (!isNull _unit) then {_unit removeEventHandler [_event, _id];};
} forEach (uiNamespace getVariable ["TAE_HUD_radarHandlers", []]);
uiNamespace setVariable ["TAE_HUD_radarHandlers", []];
uiNamespace setVariable ["TAE_HUD_radarCandidates", []];
uiNamespace setVariable ["TAE_HUD_radarShots", []];
