class CfgPatches {
    class TAEUniforms {
        name = "TAE Uniforms";
        author = "TAE Mod Team";
        requiredVersion = 1.60;
        requiredAddons[] = { "A3_Characters_F", "tgf_undersuit", "ls_characters_mandalorian" };
        units[] = {
            "tae_uniform_unit_ls_mandalorian",
            "tae_uniform_unit_forgemaster",
            "tae_uniform_unit_forgemaster_seal",
            "tae_uniform_unit_black",
            "tae_uniform_unit_black_seal",
            "tae_uniform_unit_dark_blue",
            "tae_uniform_unit_dark_blue_seal",
            "tae_uniform_unit_dark_green",
            "tae_uniform_unit_dark_green_seal",
            "tae_uniform_unit_grey",
            "tae_uniform_unit_grey_seal",
            "tae_uniform_unit_orange",
            "tae_uniform_unit_orange_seal",
            "tae_uniform_unit_red",
            "tae_uniform_unit_red_seal",
            "tae_uniform_unit_white",
            "tae_uniform_unit_white_seal",
            "tae_uniform_unit_skirata",
            "tae_uniform_unit_vau",
            "tae_uniform_unit_black_female",
            "tae_uniform_unit_dark_blue_female",
            "tae_uniform_unit_grey_female",
            "tae_uniform_unit_red_female",
            "tae_uniform_unit_white_female"
        };
        weapons[] = {
            "tae_uniform_ls_mandalorian",
            "tae_uniform_forgemaster",
            "tae_uniform_forgemaster_seal",
            "tae_uniform_black",
            "tae_uniform_black_seal",
            "tae_uniform_dark_blue",
            "tae_uniform_dark_blue_seal",
            "tae_uniform_dark_green",
            "tae_uniform_dark_green_seal",
            "tae_uniform_grey",
            "tae_uniform_grey_seal",
            "tae_uniform_orange",
            "tae_uniform_orange_seal",
            "tae_uniform_red",
            "tae_uniform_red_seal",
            "tae_uniform_white",
            "tae_uniform_white_seal",
            "tae_uniform_skirata",
            "tae_uniform_vau",
            "tae_uniform_black_female",
            "tae_uniform_dark_blue_female",
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
            options[] = { "source", "type", "sex", "seal" };
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
                values[] = { "Black", "DarkBlue", "DarkGreen", "Forgemaster", "Grey", "Orange", "Red", "Skirata", "Vau", "White" };
                class Black { label = "Black"; };
                class DarkBlue { label = "Dark Blue"; };
                class DarkGreen { label = "Dark Green"; };
                class Forgemaster { label = "Forgemaster"; };
                class Grey { label = "Grey"; };
                class Orange { label = "Orange"; };
                class Red { label = "Red"; };
                class Skirata { label = "Skirata"; };
                class Vau { label = "Vau"; };
                class White { label = "White"; };
            };
            class sex {
                alwaysSelectable = 1;
                label = "Sex";
                values[] = { "Male", "Female" };
                class Male { label = "Male"; };
                class Female { label = "Female"; };
            };
            class seal {
                alwaysSelectable = 1;
                label = "Seal";
                values[] = { "No", "Yes" };
                class No { label = "No"; };
                class Yes { label = "Yes"; };
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
            seal = "No";
        };
        class tae_uniform_forgemaster {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Forgemaster";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_forgemaster_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Forgemaster";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_black {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Black";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_black_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Black";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_dark_blue {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkBlue";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_dark_blue_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkBlue";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_dark_green {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkGreen";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_dark_green_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkGreen";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_grey {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Grey";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_grey_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Grey";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_orange {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Orange";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_orange_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Orange";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_red {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Red";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_red_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Red";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_white {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "White";
            sex = "Male";
            seal = "No";
        };
        class tae_uniform_white_seal {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "White";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_skirata {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Skirata";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_vau {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Vau";
            sex = "Male";
            seal = "Yes";
        };
        class tae_uniform_black_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Black";
            sex = "Female";
            seal = "No";
        };
        class tae_uniform_dark_blue_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "DarkBlue";
            sex = "Female";
            seal = "No";
        };
        class tae_uniform_grey_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Grey";
            sex = "Female";
            seal = "No";
        };
        class tae_uniform_red_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "Red";
            sex = "Female";
            seal = "No";
        };
        class tae_uniform_white_female {
            model = "TAE_standard_uniforms";
            source = "TGF";
            type = "White";
            sex = "Female";
            seal = "No";
        };
    };
};

class CfgVehicles {
    class ls_mandalorian_base;
    class tgf_undersuit_unit_forgemaster;
    class tgf_undersuit_unit_forgemaster_seal;
    class tgf_undersuit_unit_black;
    class tgf_undersuit_unit_black_seal;
    class tgf_undersuit_unit_dark_blue;
    class tgf_undersuit_unit_dark_blue_seal;
    class tgf_undersuit_unit_dark_green;
    class tgf_undersuit_unit_dark_green_seal;
    class tgf_undersuit_unit_grey;
    class tgf_undersuit_unit_grey_seal;
    class tgf_undersuit_unit_orange;
    class tgf_undersuit_unit_orange_seal;
    class tgf_undersuit_unit_red;
    class tgf_undersuit_unit_red_seal;
    class tgf_undersuit_unit_white;
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
        author = "TAE Mod Team";
        displayName = "TAE LS Mandalorian Undersuit";
        uniformClass = "tae_uniform_ls_mandalorian";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_forgemaster: tgf_undersuit_unit_forgemaster {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Forgemaster)";
        uniformClass = "tae_uniform_forgemaster";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_forgemaster_seal: tgf_undersuit_unit_forgemaster_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Forgemaster)";
        uniformClass = "tae_uniform_forgemaster_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_black: tgf_undersuit_unit_black {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Black)";
        uniformClass = "tae_uniform_black";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_black_seal: tgf_undersuit_unit_black_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Black)";
        uniformClass = "tae_uniform_black_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_blue: tgf_undersuit_unit_dark_blue {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_blue_seal: tgf_undersuit_unit_dark_blue_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_green: tgf_undersuit_unit_dark_green {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Dark Green)";
        uniformClass = "tae_uniform_dark_green";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_green_seal: tgf_undersuit_unit_dark_green_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Green)";
        uniformClass = "tae_uniform_dark_green_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_grey: tgf_undersuit_unit_grey {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Grey)";
        uniformClass = "tae_uniform_grey";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_grey_seal: tgf_undersuit_unit_grey_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Grey)";
        uniformClass = "tae_uniform_grey_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_orange: tgf_undersuit_unit_orange {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Orange)";
        uniformClass = "tae_uniform_orange";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_orange_seal: tgf_undersuit_unit_orange_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Orange)";
        uniformClass = "tae_uniform_orange_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_red: tgf_undersuit_unit_red {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Red)";
        uniformClass = "tae_uniform_red";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_red_seal: tgf_undersuit_unit_red_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Red)";
        uniformClass = "tae_uniform_red_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_white: tgf_undersuit_unit_white {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (White)";
        uniformClass = "tae_uniform_white";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_white_seal: tgf_undersuit_unit_white_seal {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (White)";
        uniformClass = "tae_uniform_white_seal";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_skirata: tgf_undersuit_unit_skirata {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Kal Skirata)";
        uniformClass = "tae_uniform_skirata";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_vau: tgf_undersuit_unit_vau {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Walon Vau)";
        uniformClass = "tae_uniform_vau";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_black_female: tgf_undersuit_unit_black_female {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Black)";
        uniformClass = "tae_uniform_black_female";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_dark_blue_female: tgf_undersuit_unit_dark_blue_female {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Dark Blue)";
        uniformClass = "tae_uniform_dark_blue_female";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_grey_female: tgf_undersuit_unit_grey_female {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Grey)";
        uniformClass = "tae_uniform_grey_female";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_red_female: tgf_undersuit_unit_red_female {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Red)";
        uniformClass = "tae_uniform_red_female";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
    class tae_uniform_unit_white_female: tgf_undersuit_unit_white_female {
        scope = 1;
        scopeCurator = 0;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (White)";
        uniformClass = "tae_uniform_white_female";
        class HitPoints {
            class HitFace {
                armor = 5;
                material = -1;
                name = "face_hub";
                passThrough = 0.8;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck {
                armor = 5;
                material = -1;
                name = "neck";
                passThrough = 0.8;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.8;
                radius = 0.2;
                explosionShielding = 0.5;
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 6;
                material = -1;
                name = "pelvis";
                passThrough = 0.8;
                radius = 0.24;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitAbdomen {
                armor = 6;
                material = -1;
                name = "spine1";
                passThrough = 0.8;
                radius = 0.16;
                explosionShielding = 0.1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm {
                armor = 6;
                material = -1;
                name = "spine2";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest {
                armor = 6;
                material = -1;
                name = "spine3";
                passThrough = 0.8;
                radius = 0.18;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.25;
                visual = "injury_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class HitArms {
                armor = 6;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "0";
            };
            class HitHands {
                armor = 6;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.3;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class HitLegs {
                armor = 6;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.14;
                explosionShielding = 0.3;
                visual = "injury_legs";
                minimalHit = 0.01;
                depends = "0";
            };
            class Incapacitated {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 1;
                radius = 0;
                explosionShielding = 0.1;
                visual = "";
                minimalHit = 0;
                depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
            };
            class HitLeftArm {
                armor = 6;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.08;
                explosionShielding = 0.1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm {
                name = "hand_r";
            };
            class HitLeftLeg {
                armor = 6;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg {
                name = "leg_r";
            };
        };
        armor = 2;
        armorStructural = 4;
        explosionShielding = 0.4;
        minTotalDamageThreshold = 0.001;
        impactDamageMultiplier = 0.5;    };
};

class CfgWeapons {
    class ItemInfo;
    class ls_mandalorianUniform;
    class tgf_undersuit_uniform_forgemaster;
    class tgf_undersuit_uniform_forgemaster_seal;
    class tgf_undersuit_uniform_black;
    class tgf_undersuit_uniform_black_seal;
    class tgf_undersuit_uniform_dark_blue;
    class tgf_undersuit_uniform_dark_blue_seal;
    class tgf_undersuit_uniform_dark_green;
    class tgf_undersuit_uniform_dark_green_seal;
    class tgf_undersuit_uniform_grey;
    class tgf_undersuit_uniform_grey_seal;
    class tgf_undersuit_uniform_orange;
    class tgf_undersuit_uniform_orange_seal;
    class tgf_undersuit_uniform_red;
    class tgf_undersuit_uniform_red_seal;
    class tgf_undersuit_uniform_white;
    class tgf_undersuit_uniform_white_seal;
    class tgf_undersuit_uniform_skirata;
    class tgf_undersuit_uniform_vau;
    class tgf_undersuit_uniform_black_female;
    class tgf_undersuit_uniform_dark_blue_female;
    class tgf_undersuit_uniform_grey_female;
    class tgf_undersuit_uniform_red_female;
    class tgf_undersuit_uniform_white_female;

    class tae_uniform_ls_mandalorian: ls_mandalorianUniform {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE LS Mandalorian Undersuit";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_ls_mandalorian";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_forgemaster: tgf_undersuit_uniform_forgemaster {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Forgemaster)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_forgemaster";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_forgemaster_seal: tgf_undersuit_uniform_forgemaster_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Forgemaster)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_forgemaster_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_black: tgf_undersuit_uniform_black {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_black";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_black_seal: tgf_undersuit_uniform_black_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_black_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_dark_blue: tgf_undersuit_uniform_dark_blue {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_blue";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_dark_blue_seal: tgf_undersuit_uniform_dark_blue_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_blue_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_dark_green: tgf_undersuit_uniform_dark_green {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Dark Green)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_green";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_dark_green_seal: tgf_undersuit_uniform_dark_green_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Dark Green)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_green_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_grey: tgf_undersuit_uniform_grey {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_grey";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_grey_seal: tgf_undersuit_uniform_grey_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_grey_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_orange: tgf_undersuit_uniform_orange {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Orange)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_orange";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_orange_seal: tgf_undersuit_uniform_orange_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Orange)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_orange_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_red: tgf_undersuit_uniform_red {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_red";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_red_seal: tgf_undersuit_uniform_red_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_red_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_white: tgf_undersuit_uniform_white {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_white";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_white_seal: tgf_undersuit_uniform_white_seal {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit with Seal (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_white_seal";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_skirata: tgf_undersuit_uniform_skirata {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Kal Skirata)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_skirata";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_vau: tgf_undersuit_uniform_vau {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Mandalorian Undersuit (Walon Vau)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_vau";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_black_female: tgf_undersuit_uniform_black_female {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Black)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_black_female";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_dark_blue_female: tgf_undersuit_uniform_dark_blue_female {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Dark Blue)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_dark_blue_female";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_grey_female: tgf_undersuit_uniform_grey_female {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Grey)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_grey_female";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_red_female: tgf_undersuit_uniform_red_female {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (Red)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_red_female";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
    class tae_uniform_white_female: tgf_undersuit_uniform_white_female {
        scope = 2;
        scopeArsenal = 2;
        author = "TAE Mod Team";
        displayName = "TAE Female Mandalorian Undersuit (White)";
        CBRN_protectionLevel = "4 + 8";
        ACE_GForceCoef = 0.9;
        class ItemInfo: ItemInfo {
            uniformClass = "tae_uniform_unit_white_female";
            containerClass = "Supply150";
            mass = 67;
            uniformType = "Neopren";
            modelSides[] = { 6 };
        };
    };
};
