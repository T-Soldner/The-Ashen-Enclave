/*
ADV_aceCPR_fnc_getBloodLoss - by Belbo
Modified by TAE Mod Team, 2026-08-17: use ACE's current blood-loss API.
*/

params ["_caller", "_target"];

// Blood loss of all unbandaged, untourniquetted wounds.
private _totalBloodLoss = [_target] call ace_medical_status_fnc_getBloodLoss;


//diagnostics:
[_caller,format ["the patient has a bloodloss of %1",_totalBloodLoss]] call adv_aceCPR_fnc_diag;

//return
_totalBloodLoss;
