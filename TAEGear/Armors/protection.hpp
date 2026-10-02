// Expand identical protection data without changing class inheritance.
#define TAE_ARMOR_HITPOINT(NAME, HITPOINT) \
    class NAME { \
        hitPointName = HITPOINT; \
        armor = 10; \
        explosionshielding = 10; \
        passThrough = 0.3; \
    };

#define TAE_ARMOR_PROTECTION \
    class HitpointsprotectionInfo { \
        TAE_ARMOR_HITPOINT(Neck, "HitNeck") \
        TAE_ARMOR_HITPOINT(Chest, "HitChest") \
        TAE_ARMOR_HITPOINT(Diaphragm, "HitDiaphragm") \
        TAE_ARMOR_HITPOINT(Abdomen, "HitAbdomen") \
        TAE_ARMOR_HITPOINT(Pelvis, "HitPelvis") \
        TAE_ARMOR_HITPOINT(Arms, "HitArms") \
        TAE_ARMOR_HITPOINT(Hands, "HitHands") \
        TAE_ARMOR_HITPOINT(Legs, "HitLegs") \
    };
