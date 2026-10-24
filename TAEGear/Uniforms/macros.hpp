// Keep upstream inheritance and per-variant textures/credits in config.cpp.
#define TAE_UNIFORM_PROTECTION \
    armor = 2; \
    armorStructural = 4; \
    explosionShielding = 0.4; \
    minTotalDamageThreshold = 0.001; \
    impactDamageMultiplier = 0.5;

#define TAE_UNIFORM_ITEM(UNIT) \
    class ItemInfo: ItemInfo { \
        uniformModel = "-"; \
        uniformClass = UNIT; \
        containerClass = "Supply120"; \
        mass = 40; \
        uniformType = "Neopren"; \
    };

#define TAE_UNIFORM_SUITPACK \
    model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d"; \
    hiddenSelections[] = {"camo"}; \
    hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.025,0.025,0.025,1,CO)"}; \
    scope = 2; \
    scopeArsenal = 2;

#define TAE_UNIFORM_ARSENAL(CLASS, SOURCE, TYPE, SEX) \
    class CLASS { \
        model = "TAE_standard_uniforms"; \
        source = SOURCE; \
        type = TYPE; \
        sex = SEX; \
    };
