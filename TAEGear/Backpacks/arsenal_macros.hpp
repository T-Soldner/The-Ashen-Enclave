#define TAE_BACKPACK_ARSENAL(CLASS, ROLE, SEX) \
    class CLASS { \
        model = "TAE_standard_Backpacks"; \
        role = ROLE; \
        Sex = SEX; \
    };

#define TAE_JETPACK_ARSENAL(CLASS, ROLE, RADIO) \
    class CLASS { \
        model = "TAE_standard_Jetpacks"; \
        role = ROLE; \
        lr = RADIO; \
    };

#define TAE_CUSTOM_BACKPACK_ARSENAL(CLASS, OWNER, RADIO) \
    class CLASS { \
        model = "TAE_custom_Backpacks"; \
        owner = OWNER; \
        LR = RADIO; \
    };
