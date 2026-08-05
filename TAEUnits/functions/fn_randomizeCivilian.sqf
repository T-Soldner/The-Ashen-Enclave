params ["_unit"];

if (!local _unit) exitWith {};

[_unit] spawn {
	params ["_unit"];

	sleep 0.1;

	private _uniforms = [
		"JMSLLTE_c_jumpsuit_blue_F_CombatUniform",
		"JMSLLTE_c_jumpsuit_sand_F_CombatUniform",
		"JMSLLTE_c_jumpsuit_green_F_CombatUniform",
		"JMSLLTE_c_genshirt_beige_F_CombatUniform",
		"JMSLLTE_c_genshirt_blue_F_CombatUniform",
		"JMSLLTE_c_genshirt2_black_F_CombatUniform",
		"JMSLLTE_c_genshirt2_beige_F_CombatUniform",
		"ls_uniform_spacer",
		"ls_uniform_spacer_alt",
		"ls_uniform_spacer_brown",
		"ls_uniform_spacer_brown_alt",
		"ls_uniform_pathfinder",
		"ls_uniform_pathfinder_r",
		"ls_uniform_pathfinder_brown",
		"ls_uniform_pathfinder_brown_r",
		"ls_uniform_pathfinder_navy",
		"ls_uniform_pathfinder_navy_r",
		"ls_uniform_pathfinder_navy_alt",
		"ls_uniform_pathfinder_navy_alt_r",
		"U_C_PilotJacket_black_RF",
		"U_C_PilotJacket_open_black_RF",
		"U_C_PilotJacket_brown_RF",
		"U_C_PilotJacket_open_brown_RF",
		"U_C_PilotJacket_lbrown_RF",
		"U_C_PilotJacket_open_lbrown_RF"
	];

	private _vests = [
		"",
		"JMSLLTE_c_GenVest_blue",
		"JMSLLTE_c_GenVest_orange",
		"JMSLLTE_c_VestPilot_red",
		"JMSLLTE_c_VestPilot_blue",
		"JMSLLTE_c_VestPilot_black",
		"mti_factions_civilian_vest_Worker",
		"mti_factions_civilian_vest_Worker_R",
		"ls_vest_spacer",
		"ls_vest_poncho",
		"ls_vest_poncho_partnerBlack",
		"ls_vest_poncho_partnerWhite",
		"ls_vest_poncho_peaceBlue",
		"ls_vest_poncho_peaceGreen",
		"ls_vest_poncho_peaceRed",
		"ls_vest_poncho_sidestripeBlue",
		"ls_vest_poncho_sidestripeBrown",
		"ls_vest_poncho_sidestripeRed",
		"ls_vest_poncho_sidestripeWhite",
		"ls_vest_flakJacket",
		"ls_vest_flakJacket_brown",
		"ls_vest_flakJacket_pouches",
		"ls_vest_flakJacket_pouches_brown",
		"ls_vest_flakJacket_pouchesAlt",
		"ls_vest_flakJacket_pouchesAlt_brown",
		"ls_vest_flakJacket_open",
		"V_Safety_yellow_F",
		"V_Safety_orange_F",
		"V_Safety_blue_F",
		"V_Pocketed_olive_F",
		"V_Pocketed_coyote_F",
		"V_Pocketed_black_F"
	];

	private _faceIdentityTypes = [
		// JMSLLTE species
		"HeadNikto",
		"HeadIshi",
		"HeadAbed",
		"HeadDuros",
		"HeadSullustan",
		"HeadRodian",
		"HeadQuarren",

		// StarForge species
		"HeadArcona",
		"HeadCathar",
		"HeadChiss",
		"HeadCyborg",
		"HeadMirakulan",
		"HeadTrando",
		"HeadTwilek",

		// MokTech/SOB and Legion Studios species
		"MTI_SpeciesRandom",
		"ls_head_randomSpecies",

		// Vanilla Arma 3 humans
		"Head_NATO",
		"Head_Euro",
		"Head_Greek",
		"Head_Asian",
		"Head_African",
		"Head_Russian",
		"Head_Tanoan",
		"Head_Enoch"
	];

	private _faceConfig = configFile >> "CfgFaces" >> "Man_A3";
	private _faces = [];

	{
		private _types = getArray (_x >> "identityTypes");
		if ((_types findIf {_x in _faceIdentityTypes}) >= 0 && {getNumber (_x >> "disabled") == 0}) then {
			_faces pushBackUnique (configName _x);
		};
	} forEach ("true" configClasses _faceConfig);

	// Female Base includes bald variants under the same identity type, so use its haired faces explicitly.
	{
		if (isClass (_faceConfig >> _x)) then {
			_faces pushBackUnique _x;
		};
	} forEach [
		"xs_f_face_Lisa",
		"xs_f_face_Lisa1",
		"xs_f_face_Lisa2",
		"xs_f_face_Nidia",
		"xs_f_face_Nidia_y",
		"xs_f_face_Jodie"
	];

	// Keep clones uncommon and limited to five standard Legion Studios faces.
	{
		if (isClass (_faceConfig >> _x)) then {
			_faces pushBackUnique _x;
		};
	} forEach [
		"ls_cloneA",
		"ls_cloneB",
		"ls_cloneC",
		"ls_cloneD",
		"ls_cloneE"
	];

	removeAllWeapons _unit;
	removeAllItems _unit;
	removeAllAssignedItems _unit;
	removeUniform _unit;
	removeVest _unit;
	removeBackpack _unit;
	removeHeadgear _unit;
	removeGoggles _unit;

	if (_faces isNotEqualTo []) then {
		_unit setFace (selectRandom _faces);
	};

	_unit forceAddUniform (selectRandom _uniforms);

	private _vest = selectRandom _vests;
	if (_vest != "") then {
		_unit addVest _vest;
	};

	private _planningMode = (expectedDestination _unit) select 1;
	private _hasMoveOrder =
		currentCommand _unit == "MOVE" ||
		{!unitReady _unit} ||
		{_planningMode != "DoNotPlan"};
	private _isPlayerControlled =
		isPlayer _unit ||
		{!isNull (_unit getVariable ["BIS_fnc_moduleRemoteControl_owner", objNull])};

	if (
		vehicle _unit == _unit &&
		{!_hasMoveOrder} &&
		{!_isPlayerControlled} &&
		{!(_unit getVariable ["TAE_civilianAmbientUsed", false])}
	) then {
		_unit setVariable ["TAE_civilianAmbientUsed", true];

		private _ambientAnimation = selectRandom [
			"STAND_U1",
			"STAND_U2",
			"STAND_U3",
			"LISTEN_BRIEFING",
			"SIT_LOW_U",
			"LEAN"
		];

		[_unit, _ambientAnimation, "ASIS"] call BIS_fnc_ambientAnim;

		[_unit] spawn {
			params ["_unit"];

			waitUntil {
				sleep 0.25;

				private _planningMode = if (local _unit) then {
					(expectedDestination _unit) select 1
				} else {
					"DoNotPlan"
				};

				!alive _unit ||
				{isPlayer _unit} ||
				{!isNull (_unit getVariable ["BIS_fnc_moduleRemoteControl_owner", objNull])} ||
				{currentCommand _unit == "MOVE"} ||
				{!unitReady _unit} ||
				{_planningMode != "DoNotPlan"} ||
				{_unit getVariable ["WBK_VariableScared", false]}
			};

			if (!isNull _unit) then {
				_unit call BIS_fnc_ambientAnim__terminate;
				if (alive _unit) then {
					_unit setBehaviour "CARELESS";
				};
			};
		};
	};
};
