/*
	Author: pike713
	Modified by TAE Mod Team, 2026-08-17: use ACE's current medication status API.

	Description:
	Checks if the status of a unit's medications.

	Parameters:
	_unit: OBJECT - The object to check for morphine

	Returns:
	ARRAY - number array in the form [morphine, epinephrine, adenosine], indicating the amount of each
		medication present.
*/

params [
	"_unit"
];

["Morphine", "Epinephrine", "Adenosine"] apply {
	([_unit, _x, false] call ace_medical_status_fnc_getMedicationCount) select 1
}
