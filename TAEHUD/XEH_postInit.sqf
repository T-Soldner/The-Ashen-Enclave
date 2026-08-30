if (!hasInterface) exitWith {};

[
	{!isNull player && {!isNull findDisplay 46}},
	{[] call TAE_fnc_hudInitClient;}
] call CBA_fnc_waitUntilAndExecute;
