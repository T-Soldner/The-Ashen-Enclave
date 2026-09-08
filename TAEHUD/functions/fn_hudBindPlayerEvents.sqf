params [["_unit", objNull, [objNull]]];

if (isNull _unit || {_unit getVariable ["TAE_HUD_eventsBound", false]}) exitWith {};
_unit setVariable ["TAE_HUD_eventsBound", true];

_unit addEventHandler
[
	"SlotItemChanged",
	{
		params ["_unit"];
		if (_unit isEqualTo player) then
		{
			[] call TAE_fnc_hudMonitor;
		};
	}
];

_unit addEventHandler
[
	"Killed",
	{
		params ["_unit"];
		if (_unit isEqualTo player) then
		{
			[] call TAE_fnc_hudHide;
		};
	}
];
