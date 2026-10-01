#include "macros.hpp"

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
            "tae_uniform_unit_orange_female",
            "tae_uniform_unit_brown_female",
            "tae_uniform_unit_dark_green_female",
            "tae_uniform_unit_forgemaster_female",
            "tae_uniform_unit_skirata_female",
            "tae_uniform_unit_vau_female",
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
            "tae_uniform_orange_female",
            "tae_uniform_brown_female",
            "tae_uniform_dark_green_female",
            "tae_uniform_forgemaster_female",
            "tae_uniform_skirata_female",
            "tae_uniform_vau_female",
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
                class DarkGreen { label = "Green"; };
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
        TAE_UNIFORM_ARSENAL(tae_uniform_ls_mandalorian, "LS", "Black", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_forgemaster_seal, "TGF", "Forgemaster", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_black_seal, "TGF", "Black", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_brown_seal, "TGF", "Brown", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_dark_blue_seal, "TGF", "DarkBlue", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_dark_green_seal, "TGF", "DarkGreen", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_dark_red_seal, "TGF", "DarkRed", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_grey_seal, "TGF", "Grey", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_orange_seal, "TGF", "Orange", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_red_seal, "TGF", "Red", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_white_seal, "TGF", "White", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_skirata, "TGF", "Skirata", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_vau, "TGF", "Vau", "Male")
        TAE_UNIFORM_ARSENAL(tae_uniform_orange_female, "TGF", "Orange", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_brown_female, "TGF", "Brown", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_dark_green_female, "TGF", "DarkGreen", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_forgemaster_female, "TGF", "Forgemaster", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_skirata_female, "TGF", "Skirata", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_vau_female, "TGF", "Vau", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_black_female, "TGF", "Black", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_dark_blue_female, "TGF", "DarkBlue", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_dark_red_female, "TGF", "DarkRed", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_grey_female, "TGF", "Grey", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_red_female, "TGF", "Red", "Female")
        TAE_UNIFORM_ARSENAL(tae_uniform_white_female, "TGF", "White", "Female")
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
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_forgemaster_seal: tgf_undersuit_unit_forgemaster_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Forgemaster)";
        uniformClass = "tae_uniform_forgemaster_seal";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_black_seal: tgf_undersuit_unit_black_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Black)";
        uniformClass = "tae_uniform_black_seal";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_dark_blue_seal: tgf_undersuit_unit_dark_blue_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue_seal";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_dark_green_seal: tgf_undersuit_unit_dark_green_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Green)";
        uniformClass = "tae_uniform_dark_green_seal";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_grey_seal: tgf_undersuit_unit_grey_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Grey)";
        uniformClass = "tae_uniform_grey_seal";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_orange_seal: tgf_undersuit_unit_orange_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Orange)";
        uniformClass = "tae_uniform_orange_seal";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_red_seal: tgf_undersuit_unit_red_seal {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Red)";
        uniformClass = "tae_uniform_red_seal";
        TAE_UNIFORM_PROTECTION    };
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
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_skirata: tgf_undersuit_unit_skirata {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Kal Skirata)";
        uniformClass = "tae_uniform_skirata";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_vau: tgf_undersuit_unit_vau {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Walon Vau)";
        uniformClass = "tae_uniform_vau";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_black_female: tgf_undersuit_unit_black_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Black)";
        uniformClass = "tae_uniform_black_female";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_dark_blue_female: tgf_undersuit_unit_dark_blue_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue_female";
        TAE_UNIFORM_PROTECTION    };
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
        TAE_UNIFORM_PROTECTION
    };
    class tae_uniform_unit_grey_female: tgf_undersuit_unit_grey_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Grey)";
        uniformClass = "tae_uniform_grey_female";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_red_female: tgf_undersuit_unit_red_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Red)";
        uniformClass = "tae_uniform_red_female";
        TAE_UNIFORM_PROTECTION    };
    class tae_uniform_unit_orange_female: tae_uniform_unit_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Orange)";
        uniformClass = "tae_uniform_orange_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_orange_co.paa",
            "\z\tgf\addons\undersuit\data\fem\black\camo2_co.paa"
        };
    };
    class tae_uniform_unit_brown_female: tae_uniform_unit_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Brown)";
        uniformClass = "tae_uniform_brown_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_brown_co.paa",
            "\z\tgf\addons\undersuit\data\fem\black\camo2_co.paa"
        };
    };
    class tae_uniform_unit_dark_green_female: tae_uniform_unit_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Green)";
        uniformClass = "tae_uniform_dark_green_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_dark_green_co.paa",
            "\z\tgf\addons\undersuit\data\fem\black\camo2_co.paa"
        };
    };
    class tae_uniform_unit_forgemaster_female: tae_uniform_unit_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Forgemaster)";
        uniformClass = "tae_uniform_forgemaster_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_forgemaster_co.paa",
            "\z\tgf\addons\undersuit\data\fem\black\camo2_co.paa"
        };
    };
    class tae_uniform_unit_skirata_female: tae_uniform_unit_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Kal Skirata)";
        uniformClass = "tae_uniform_skirata_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_skirata_co.paa",
            "\z\tgf\addons\undersuit\data\fem\black\camo2_co.paa"
        };
    };
    class tae_uniform_unit_vau_female: tae_uniform_unit_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Walon Vau)";
        uniformClass = "tae_uniform_vau_female";
        hiddenSelectionsTextures[] = {
            "TAEGear\Data\Uniforms\Undersuit_Fem_vau_co.paa",
            "\z\tgf\addons\undersuit\data\fem\black\camo2_co.paa"
        };
    };
    class tae_uniform_unit_white_female: tgf_undersuit_unit_white_female {
        scope = 1;
        scopeCurator = 0;
        modelSides[] = { 0, 1, 2, 3 };
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (White)";
        uniformClass = "tae_uniform_white_female";
        TAE_UNIFORM_PROTECTION    };
};

class CfgWeapons {
    class ls_uniform_base;
    class tgf_undersuit_uniform_male;
    class tgf_undersuit_uniform_female;
    // Preserve upstream parents when exposing their nested ItemInfo classes.
    class ls_mandalorianUniform: ls_uniform_base {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_forgemaster_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_black_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_dark_blue_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_dark_green_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_grey_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_orange_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_red_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_white_seal: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_skirata: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_vau: tgf_undersuit_uniform_male {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_black_female: tgf_undersuit_uniform_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_dark_blue_female: tgf_undersuit_uniform_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_grey_female: tgf_undersuit_uniform_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_red_female: tgf_undersuit_uniform_female {
        class ItemInfo;
    };
    class tgf_undersuit_uniform_white_female: tgf_undersuit_uniform_female {
        class ItemInfo;
    };

    class tae_uniform_ls_mandalorian: ls_mandalorianUniform {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE LS Mandalorian Undersuit";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_ls_mandalorian")
    };
    class tae_uniform_forgemaster_seal: tgf_undersuit_uniform_forgemaster_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Forgemaster)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_forgemaster_seal")
    };
    class tae_uniform_black_seal: tgf_undersuit_uniform_black_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_black_seal")
    };
    class tae_uniform_dark_blue_seal: tgf_undersuit_uniform_dark_blue_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_dark_blue_seal")
    };
    class tae_uniform_dark_green_seal: tgf_undersuit_uniform_dark_green_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Green)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_dark_green_seal")
    };
    class tae_uniform_grey_seal: tgf_undersuit_uniform_grey_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_grey_seal")
    };
    class tae_uniform_orange_seal: tgf_undersuit_uniform_orange_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Orange)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_orange_seal")
    };
    class tae_uniform_red_seal: tgf_undersuit_uniform_red_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_red_seal")
    };
    class tae_uniform_dark_red_seal: tae_uniform_red_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Red)";
        TAE_UNIFORM_ITEM("tae_uniform_unit_dark_red_seal")
    };
    class tae_uniform_brown_seal: tae_uniform_red_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Brown)";
        TAE_UNIFORM_ITEM("tae_uniform_unit_brown_seal")
    };
    class tae_uniform_white_seal: tgf_undersuit_uniform_white_seal {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_white_seal")
    };
    class tae_uniform_skirata: tgf_undersuit_uniform_skirata {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Kal Skirata)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_skirata")
    };
    class tae_uniform_vau: tgf_undersuit_uniform_vau {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Mandalorian Undersuit with Seal (Walon Vau)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_vau")
    };
    class tae_uniform_black_female: tgf_undersuit_uniform_black_female {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_black_female")
    };
    class tae_uniform_dark_blue_female: tgf_undersuit_uniform_dark_blue_female {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_dark_blue_female")
    };
    class tae_uniform_dark_red_female: tgf_undersuit_uniform_red_female {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Dark Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_dark_red_female")
    };
    class tae_uniform_grey_female: tgf_undersuit_uniform_grey_female {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_grey_female")
    };
    class tae_uniform_red_female: tgf_undersuit_uniform_red_female {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_red_female")
    };
    class tae_uniform_orange_female: tae_uniform_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Orange)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_orange_female";
        };
    };
    class tae_uniform_brown_female: tae_uniform_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Brown)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_brown_female";
        };
    };
    class tae_uniform_dark_green_female: tae_uniform_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Green)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_green_female";
        };
    };
    class tae_uniform_forgemaster_female: tae_uniform_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Forgemaster)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_forgemaster_female";
        };
    };
    class tae_uniform_skirata_female: tae_uniform_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Kal Skirata)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_skirata_female";
        };
    };
    class tae_uniform_vau_female: tae_uniform_black_female {
        author = "The Great Forge and Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (Walon Vau)";
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_vau_female";
        };
    };
    class tae_uniform_white_female: tgf_undersuit_uniform_white_female {
        TAE_UNIFORM_SUITPACK
        author = "Edonn";
        displayName = "TAE Female Mandalorian Undersuit with Seal (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        TAE_UNIFORM_ITEM("tae_uniform_unit_white_female")
    };
};
