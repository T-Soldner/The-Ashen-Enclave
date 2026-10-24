// Leave SQF statements outside macro arguments so their commas remain intact.
#define TAE_WEARABLE_ACTION_BEGIN(CLASS, LABEL) \
    class CLASS { \
        displayName = LABEL; \
        condition = "true";
