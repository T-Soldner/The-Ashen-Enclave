#include "config_macros.hpp"

class CfgPatches {
	class ADDON {
		name = ADDON_NAME;
		author = "Chatter and M3ales; TAE Mod Team";
		url = "https://github.com/chatterchats/ASTRS";
		requiredAddons[] = {"ace_interact_menu", "tfar_core", "cba_settings", "cba_xeh"};
		units[] = {};
		weapons[] = {};
	};
};

class CfgFunctions {
	class ADDON {
        class TFARLRSettings {
            tag = QUOTE(ADDON);
            requiredAddons[] = {"ace_interact_menu", "tfar_core", "cba_settings", "cba_xeh"};
            file = FUNCTION_PATH;
			class loadLRSettings {};
			class saveLRSettings {};
			class loadSRSettings {};
			class saveSRSettings {};
			class showLRCheck {};
			class showVLRCheck {};
			class showSRCheck {};
			class layoutOptionCheck {};
			class loadAllSettings {};
			class getPrefs {};
			class setPrefs {};
			class getRadioData {};
			class setRadioData {};
			class loadSettings {};
			class setProfile {};
			class copyLegacyRadioData {};
			class copyLegacyLRData {};
			class shortcutEnabledCheck {};
        };
	};
};

#include "CfgVehicles.hpp"

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};
