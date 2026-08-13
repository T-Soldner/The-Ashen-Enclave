if (!hasInterface) exitWith {};

[] spawn {
	waitUntil {!isNull player};
	[player] call TAE_fnc_addQuartermasterDiary;

	addMissionEventHandler ["EntityRespawned", {
		params ["_newEntity"];

		if (_newEntity isEqualTo player) then {
			[_newEntity] call TAE_fnc_addQuartermasterDiary;
		};
	}];
};
