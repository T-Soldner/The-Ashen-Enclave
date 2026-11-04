class CfgPatches {
    class TAEAttendance {
        name = "TAE Server Attendance";
        requiredVersion = 2.06;
        requiredAddons[] = {"A3_Functions_F"};
        units[] = {};
        weapons[] = {};
    };
};
class CfgFunctions {
    class TAEAttendance {
        class Collector {
            file = "\TAEAttendance\functions";
            class inWindow {};
            class writeEvent {};
            class init { postInit = 1; };
        };
    };
};
