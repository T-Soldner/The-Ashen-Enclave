#define TAE_IMPOSTER_GEAR "tae_karr_armor_medium_mv", "tae_karr_helmet_mv", "ItemMap", "ItemGPS", "ls_radios_hush98", "ItemCompass", "ItemWatch", "tgf_nvg_rangefinder_r"
#define TAE_IMPOSTER_GRENADIER_GEAR "acc_flashlight", "IDA_E11_scope", TAE_IMPOSTER_GEAR
#define TAE_IMPOSTER_HEAVY_GEAR "3AS_Imp_Optic_2", TAE_IMPOSTER_GEAR
#define TAE_IMPOSTER_SNIPER_GEAR "tae_TargetingScope_FP2", TAE_IMPOSTER_GEAR
#define TAE_IMPOSTER_UNIT(CLASS, BASE, GEAR) \
    class CLASS: BASE { \
        side = 0; \
        faction = "TAE_Faction_HouseKarr_Imposters"; \
        scope = 2; \
        scopeCurator = 2; \
        uniformClass = "tae_uniform_dark_red_seal"; \
        hiddenSelectionsTextures[] = {"TAEGear\Data\Uniforms\Undersuit_Dark_Red_co.paa", "\z\tgf\addons\undersuit\data\camo2_co.paa"}; \
        linkedItems[] = {GEAR}; \
        respawnLinkedItems[] = {GEAR}; \
    };

TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Veteran, TAE_Unit_Veteran, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_RisingPhoenix, TAE_Unit_RisingPhoenix, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Engineer, TAE_Unit_Engineer, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Medic, TAE_Unit_Medic, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Marksman, TAE_Unit_Marksman, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_AT_AA, TAE_Unit_AT_AA, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Grenadier, TAE_Unit_Grenadier, TAE_IMPOSTER_GRENADIER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_CQC_Specialist, TAE_Unit_CQC_Specialist, TAE_IMPOSTER_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Heavy_Weapons, TAE_Unit_Heavy_Weapons, TAE_IMPOSTER_HEAVY_GEAR)
TAE_IMPOSTER_UNIT(TAE_Unit_Imposter_Sniper, TAE_Unit_Sniper, TAE_IMPOSTER_SNIPER_GEAR)

#undef TAE_IMPOSTER_UNIT
#undef TAE_IMPOSTER_SNIPER_GEAR
#undef TAE_IMPOSTER_HEAVY_GEAR
#undef TAE_IMPOSTER_GRENADIER_GEAR
#undef TAE_IMPOSTER_GEAR
