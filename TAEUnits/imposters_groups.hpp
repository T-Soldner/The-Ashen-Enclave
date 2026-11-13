class TAE_Faction_HouseKarr_Imposters {
    name = "[TAE] House Karr Imposters";
    class Infantry {
        name = "Infantry";
        class TAE_Group_Imposter_Squad {
            name = "Squad";
            side = 0;
            faction = "TAE_Faction_HouseKarr_Imposters";
            icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
            TAE_GROUP_MEMBER(Unit0, 0, "TAE_Unit_Imposter_Veteran", "SERGEANT", 0, 0, 0)
            TAE_GROUP_MEMBER(Unit1, 0, "TAE_Unit_Imposter_Engineer", "CORPORAL", 5, -5, 0)
            TAE_GROUP_MEMBER(Unit2, 0, "TAE_Unit_Imposter_Medic", "CORPORAL", -5, -5, 0)
            TAE_GROUP_MEMBER(Unit3, 0, "TAE_Unit_Imposter_Marksman", "PRIVATE", 10, -10, 0)
            TAE_GROUP_MEMBER(Unit4, 0, "TAE_Unit_Imposter_AT_AA", "PRIVATE", -10, -10, 0)
            TAE_GROUP_MEMBER(Unit5, 0, "TAE_Unit_Imposter_Grenadier", "PRIVATE", 15, -15, 0)
            TAE_GROUP_MEMBER(Unit6, 0, "TAE_Unit_Imposter_CQC_Specialist", "PRIVATE", -15, -15, 0)
            TAE_GROUP_MEMBER(Unit7, 0, "TAE_Unit_Imposter_Heavy_Weapons", "PRIVATE", 20, -20, 0)
            TAE_GROUP_MEMBER(Unit8, 0, "TAE_Unit_Imposter_Sniper", "PRIVATE", -20, -20, 0)
        };
        class TAE_Group_Imposter_Fireteam {
            name = "Fireteam";
            side = 0;
            faction = "TAE_Faction_HouseKarr_Imposters";
            icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
            TAE_GROUP_MEMBER(Unit0, 0, "TAE_Unit_Imposter_Veteran", "SERGEANT", 0, 0, 0)
            TAE_GROUP_MEMBER(Unit1, 0, "TAE_Unit_Imposter_Medic", "CORPORAL", 5, -5, 0)
            TAE_GROUP_MEMBER(Unit2, 0, "TAE_Unit_Imposter_Marksman", "PRIVATE", -5, -5, 0)
            TAE_GROUP_MEMBER(Unit3, 0, "TAE_Unit_Imposter_AT_AA", "PRIVATE", 10, -10, 0)
        };
        class TAE_Group_Imposter_Sentry {
            name = "Sentry";
            side = 0;
            faction = "TAE_Faction_HouseKarr_Imposters";
            icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
            TAE_GROUP_MEMBER(Unit0, 0, "TAE_Unit_Imposter_Marksman", "CORPORAL", 0, 0, 0)
            TAE_GROUP_MEMBER(Unit1, 0, "TAE_Unit_Imposter_Grenadier", "PRIVATE", 5, -5, 0)
        };
        class TAE_Group_Imposter_RisingPhoenixTeam {
            name = "Rising Phoenix Team";
            side = 0;
            faction = "TAE_Faction_HouseKarr_Imposters";
            icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
            TAE_GROUP_MEMBER(Unit0, 0, "TAE_Unit_Imposter_RisingPhoenix", "SERGEANT", 0, 0, 0)
            class Unit1: Unit0 { rank = "PRIVATE"; position[] = {5,-5,0}; };
            class Unit2: Unit1 { position[] = {-5,-5,0}; };
            class Unit3: Unit1 { position[] = {10,-10,0}; };
            class Unit4: Unit1 { position[] = {-10,-10,0}; };
        };
    };
};
