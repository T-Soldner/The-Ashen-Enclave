class CfgPatches {
    class TAEUniforms {
        name = "TAE Uniforms";
        author = "TAE Mod Team";
        requiredVersion = 1.60;
        requiredAddons[] = { "A3_Characters_F", "tgf_undersuit", "ls_characters_mandalorian" };
        units[] = {
            "tae_uniform_unit_ls_mandalorian",
            "tae_uniform_unit_forgemaster_seal",
            "tae_uniform_unit_black_seal",
            "tae_uniform_unit_brown_seal",
            "tae_uniform_unit_dark_blue_seal",
            "tae_uniform_unit_dark_green_seal",
            "tae_uniform_unit_dark_red_seal",
            "tae_uniform_unit_grey_seal",
            "tae_uniform_unit_orange_seal",
            "tae_uniform_unit_red_seal",
            "tae_uniform_unit_white_seal",
            "tae_uniform_unit_skirata",
            "tae_uniform_unit_vau",
            "tae_uniform_unit_black_female",
            "tae_uniform_unit_dark_blue_female",
            "tae_uniform_unit_dark_red_female",
            "tae_uniform_unit_grey_female",
            "tae_uniform_unit_red_female",
            "tae_uniform_unit_white_female"
        };
        weapons[] = {
            "tae_uniform_ls_mandalorian",
            "tae_uniform_forgemaster_seal",
            "tae_uniform_black_seal",
            "tae_uniform_brown_seal",
            "tae_uniform_dark_blue_seal",
            "tae_uniform_dark_green_seal",
            "tae_uniform_dark_red_seal",
            "tae_uniform_grey_seal",
            "tae_uniform_orange_seal",
            "tae_uniform_red_seal",
            "tae_uniform_white_seal",
            "tae_uniform_skirata",
            "tae_uniform_vau",
            "tae_uniform_black_female",
            "tae_uniform_dark_blue_female",
            "tae_uniform_dark_red_female",
            "tae_uniform_grey_female",
            "tae_uniform_red_female",
            "tae_uniform_white_female"
        };
    };
};

class XtdGearModels {
    class CfgWeapons {
        class TAE_standard_uniforms {
            label = "TAE Uniforms";
            author = "TAE Aux Mod Team";
            options[] = { "source", "type", "sex" };
            class source {
                alwaysSelectable = 1;
                label = "Source";
                values[] = { "TGF", "LS" };
                class TGF { label = "TGF"; };
                class LS { label = "LS"; };
            };
            class type {
                alwaysSelectable = 1;
                label = "Type";
                values[] = { "Black", "Grey", "White", "Red", "DarkRed", "Orange", "Brown", "DarkGreen", "DarkBlue", "Forgemaster", "Skirata", "Vau" };
                class Black { label = "Black"; };
                class Grey { label = "Grey"; };
                class White { label = "White"; };
                class Red { label = "Red"; };
                class DarkRed { label = "Dark Red"; };
                class Orange { label = "Orange"; };
                class Brown { label = "Brown"; };
                class DarkGreen { label = "Dark Green"; };
                class DarkBlue { label = "Dark Blue"; };
                class Forgemaster { label = "Forgemaster"; };
                class Skirata { label = "Skirata"; };
                class Vau { label = "Vau"; };
            };
            class sex {
                alwaysSelectable = 1;
                label = "Sex";
                values[] = { "Male", "Female" };
                class Male { label = "Male"; };
                class Female { label = "Female"; };
            };
        };
    };
};

class XtdGearInfos {
    class CfgWeapons {
        class tae_uniform_ls_mandalorian {
            model = "TAE_standard_uniforms";
            source = "LS";
            type = "Black";
            sex = "Male";
        };
        class tae_uniform_forgemaster_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Forgemaster";
            sex = "Male";
        };
        class tae_uniform_black_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Black";
            sex = "Male";
        };
        class tae_uniform_brown_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Brown";
            sex = "Male";
        };
        class tae_uniform_dark_blue_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkBlue";
            sex = "Male";
        };
        class tae_uniform_dark_green_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkGreen";
            sex = "Male";
        };
        class tae_uniform_dark_red_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkRed";
            sex = "Male";
        };
        class tae_uniform_grey_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Grey";
            sex = "Male";
        };
        class tae_uniform_orange_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Orange";
            sex = "Male";
        };
        class tae_uniform_red_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Red";
            sex = "Male";
        };
        class tae_uniform_white_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "White";
            sex = "Male";
        };
        class tae_uniform_skirata {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Skirata";
            sex = "Male";
        };
        class tae_uniform_vau {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Vau";
            sex = "Male";
        };
        class tae_uniform_black_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Black";
            sex = "Female";
        };
        class tae_uniform_dark_blue_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkBlue";
            sex = "Female";
        };
        class tae_uniform_dark_red_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkRed";
            sex = "Female";
        };
        class tae_uniform_grey_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Grey";
            sex = "Female";
        };
        class tae_uniform_red_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Red";
            sex = "Female";
        };
        class tae_uniform_white_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "White";
            sex = "Female";
        };
    };
};

class CfgVehicles {
    class ls_mandalorian_base;
    class tgf_undersuit_unit_forgemaster_seal;
    class tgf_undersuit_unit_black_seal;
    class tgf_undersuit_unit_dark_blue_seal;
    class tgf_undersuit_unit_dark_green_seal;
    class tgf_undersuit_unit_grey_seal;
    class tgf_undersuit_unit_orange_seal;
    class tgf_undersuit_unit_red_seal;
    class tgf_undersuit_unit_white_seal;
    class tgf_undersuit_unit_skirata;
    class tgf_undersuit_unit_vau;
    class tgf_undersuit_unit_black_female;
    class tgf_undersuit_unit_dark_blue_female;
    class tgf_undersuit_unit_grey_female;
    class tgf_undersuit_unit_red_female;
    class tgf_undersuit_unit_white_female;

    class tae_uniform_unit_ls_mandalorian: ls_mandalorian_base {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE LS Mandalorian Undersuit";
        uniformClass = "tae_uniform_ls_mandalorian";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_forgemaster_seal: tgf_undersuit_unit_forgemaster_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Forgemaster)";
        uniformClass = "tae_uniform_forgemaster_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_black_seal: tgf_undersuit_unit_black_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Black)";
        uniformClass = "tae_uniform_black_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_blue_seal: tgf_undersuit_unit_dark_blue_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_green_seal: tgf_undersuit_unit_dark_green_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Green)";
        uniformClass = "tae_uniform_dark_green_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_grey_seal: tgf_undersuit_unit_grey_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Grey)";
        uniformClass = "tae_uniform_grey_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_orange_seal: tgf_undersuit_unit_orange_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Orange)";
        uniformClass = "tae_uniform_orange_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_red_seal: tgf_undersuit_unit_red_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Red)";
        uniformClass = "tae_uniform_red_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_red_seal: tae_uniform_unit_red_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Red)";
        uniformClass = "tae_uniform_dark_red_seal";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Dark_Red_co.paa",
            "\z\tgf\addons\undersuit\data\camo2_co.paa"
        };
    };
    class tae_uniform_unit_brown_seal: tae_uniform_unit_red_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Brown)";
        uniformClass = "tae_uniform_brown_seal";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Brown_co.paa",
            "\z\tgf\addons\undersuit\data\camo2_co.paa"
        };
    };
    class tae_uniform_unit_white_seal: tgf_undersuit_unit_white_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (White)";
        uniformClass = "tae_uniform_white_seal";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_skirata: tgf_undersuit_unit_skirata {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Kal Skirata)";
        uniformClass = "tae_uniform_skirata";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_vau: tgf_undersuit_unit_vau {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Walon Vau)";
        uniformClass = "tae_uniform_vau";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_black_female: tgf_undersuit_unit_black_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Black)";
        uniformClass = "tae_uniform_black_female";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_blue_female: tgf_undersuit_unit_dark_blue_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue_female";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_red_female: tgf_undersuit_unit_red_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Red)";
        uniformClass = "tae_uniform_dark_red_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_Dark_Red_co.paa",
            "\z\tgf\addons\undersuit\data\camo2_co.paa"
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;
    };
    class tae_uniform_unit_grey_female: tgf_undersuit_unit_grey_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Grey)";
        uniformClass = "tae_uniform_grey_female";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_red_female: tgf_undersuit_unit_red_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Red)";
        uniformClass = "tae_uniform_red_female";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_white_female: tgf_undersuit_unit_white_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (White)";
        uniformClass = "tae_uniform_white_female";
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
};

class CfgWeapons {
    class ls_mandalorianUniform {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_forgemaster_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_black_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_dark_blue_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_dark_green_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_grey_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_orange_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_red_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_white_seal {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_skirata {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_vau {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_black_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_dark_blue_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_grey_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_red_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_white_female {
        class ItemInfo;
    };

    class tae_uniform_ls_mandalorian: ls_mandalorianUniform {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE LS Mandalorian Undersuit";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_ls_mandalorian";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_forgemaster_seal: tgf_undersuit_uniform_forgemaster_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Forgemaster)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_forgemaster_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_black_seal: tgf_undersuit_uniform_black_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_black_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_dark_blue_seal: tgf_undersuit_uniform_dark_blue_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_blue_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_dark_green_seal: tgf_undersuit_uniform_dark_green_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Green)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_green_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_grey_seal: tgf_undersuit_uniform_grey_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_grey_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_orange_seal: tgf_undersuit_uniform_orange_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Orange)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_orange_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_red_seal: tgf_undersuit_uniform_red_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_red_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_dark_red_seal: tae_uniform_red_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Red)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_red_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_brown_seal: tae_uniform_red_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Brown)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_brown_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_white_seal: tgf_undersuit_uniform_white_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_white_seal";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_skirata: tgf_undersuit_uniform_skirata {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Kal Skirata)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_skirata";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_vau: tgf_undersuit_uniform_vau {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Walon Vau)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_vau";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_black_female: tgf_undersuit_uniform_black_female {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_black_female";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_dark_blue_female: tgf_undersuit_uniform_dark_blue_female {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_blue_female";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_dark_red_female: tgf_undersuit_uniform_red_female {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_red_female";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_grey_female: tgf_undersuit_uniform_grey_female {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_grey_female";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_red_female: tgf_undersuit_uniform_red_female {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_red_female";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
    class tae_uniform_white_female: tgf_undersuit_uniform_white_female {
        scope = 2;
        scopeArsenal = 2;
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_white_female";
            containerClass = "Supply120";
            mass = 40;
            uniformType = "Neopren";
        };
    };
};
