if (!hasInterface) exitWith {};

[] spawn {
	private _visorClass = "tae_facewear_helmet_diving_visor";
	private _activeUnit = objNull;
	private _savedFacewear = "";
	private _visorApplied = false;

	while {true} do {
		private _unit = player;

		if (_unit isNotEqualTo _activeUnit) then {
			if (
				_visorApplied &&
				{!isNull _activeUnit} &&
				{goggles _activeUnit == _visorClass}
			) then {
				removeGoggles _activeUnit;
				if (_savedFacewear != "") then {
					_activeUnit addGoggles _savedFacewear;
				};
			};

			_activeUnit = _unit;
			_savedFacewear = "";
			_visorApplied = false;
		};

		if (!isNull _unit && {local _unit}) then {
			private _helmetConfig = configFile >> "CfgWeapons" >> headgear _unit;
			private _sealedHelmet = getNumber (_helmetConfig >> "TAE_underwaterVision") > 0;
			private _eyesUnderwater = (eyePos _unit select 2) < 0;
			private _shouldUseVisor = alive _unit && {_sealedHelmet} && {_eyesUnderwater};

			if (_visorApplied && {goggles _unit != _visorClass}) then {
				_savedFacewear = "";
				_visorApplied = false;
			};

			if (_shouldUseVisor && {!_visorApplied}) then {
				_savedFacewear = goggles _unit;
				removeGoggles _unit;
				_unit addGoggles _visorClass;
				_visorApplied = true;
			};

			if (!_shouldUseVisor && {_visorApplied}) then {
				removeGoggles _unit;
				if (_savedFacewear != "") then {
					_unit addGoggles _savedFacewear;
				};

				_savedFacewear = "";
				_visorApplied = false;
			};
		};

		sleep 0.2;
	};
};
