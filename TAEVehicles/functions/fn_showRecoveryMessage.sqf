params [["_message", "", [""]]];

if (_message isNotEqualTo "") then {
	systemChat format ["[TAE Recovery] %1", _message];
};
