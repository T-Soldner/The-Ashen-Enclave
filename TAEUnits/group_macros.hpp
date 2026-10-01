#ifndef TAE_GROUP_MACROS_HPP
#define TAE_GROUP_MACROS_HPP
#define TAE_GROUP_MEMBER(CLASS, SIDE, VEHICLE, RANK, X, Y, Z) \
    class CLASS { \
        side = SIDE; \
        vehicle = VEHICLE; \
        rank = RANK; \
        position[] = {X, Y, Z}; \
    };
#endif
