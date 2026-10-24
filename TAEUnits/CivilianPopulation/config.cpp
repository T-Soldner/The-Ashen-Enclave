class CfgPatches {
    class TAEUnits_CivilianPopulation {
        requiredVersion = 2.18;
        requiredAddons[] = {"A3_Modules_F", "A3_3DEN", "TAEUnits_HouseKarr", "TAEObjects"};
        units[] = {"TAE_Module_CivilianPopulation"};
        weapons[] = {};
    };
};
class CfgFunctions {
    class TAE {
        class CivilianPopulation {
            file = "TAEUnits\CivilianPopulation\functions";
            class moduleCivilianPopulation {};
        };
    };
};
class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase { class Edit; };
    };
    class TAE_Module_CivilianPopulation: Module_F {
        scope = 2;
        scopeCurator = 0;
        displayName = "TAE Civilian Area Population";
        category = "TAE_Modules";
        function = "TAE_fnc_moduleCivilianPopulation";
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        canSetArea = 1;
        canSetAreaHeight = 0;
        class AttributeValues { size3[] = {100,100,-1}; };
        // Do not expose AttributesBase's helper templates as editable attributes.
        class Attributes {
            class UseAgents {
                expression = "_this setVariable ['UseAgents',_value,true];";
                control = "Checkbox";
                property = "TAE_CivilianUseAgents";
                displayName = "Use agents for pedestrians";
                tooltip = "Lighter ambient pedestrians with limited AI reactions. Vehicle drivers remain normal AI. Off preserves standard civilians.";
                typeName = "BOOL";
                defaultValue = "false";
            };
            class VehicleCount {
                expression = "_this setVariable ['VehicleCount',_value,true];";
                control = "TAE_CivilianVehicleCountSlider";
                property = "TAE_CivilianVehicleCount";
                displayName = "Civilian vehicles (0-10)";
                tooltip = "Fixed pool: LS V-35, civilian 105-K, WM 74-Z, JMS X-34, G-17, A-A2, A-A5 and A-A5 supply when installed. Randomized TAE civilian drivers, no ammunition, 50 km/h limit. Spawn near the icon on clear ground.";
                typeName = "NUMBER";
                defaultValue = "0";
            };
            class Count {
                expression = "_this setVariable ['Count',_value,true];";
                control = "TAE_CivilianCountSlider";
                property = "TAE_CivilianCount";
                displayName = "Civilian count (5-40)";
                typeName = "NUMBER";
                defaultValue = "15";
            };
            class Waypoints {
                control = "Edit";
                expression = "_this setVariable ['Waypoints',_value,true];";
                property = "TAE_CivilianWaypoints";
                displayName = "Waypoints per route (1-20)";
                typeName = "NUMBER";
                defaultValue = "5";
            };
            class PauseChance {
                control = "Edit";
                expression = "_this setVariable ['PauseChance',_value,true];";
                property = "TAE_CivilianPauseChance";
                displayName = "Pause chance (%)";
                tooltip = "Independent chance of a 15-120 second pause. Zero disables pauses.";
                typeName = "NUMBER";
                defaultValue = "35";
            };
        };
    };
};
class Cfg3DEN {
    class Attributes {
        // Preserve the engine parent: dropping Default breaks all Title-derived controls.
        class Default;
        class Title: Default { class Controls; };
        class Slider: Title {
            class Controls: Controls {
                class Title;
                class Value;
                class Edit;
            };
        };
        class TAE_CivilianCountSlider: Slider {
            onLoad = "private _group = _this select 0; [_group controlsGroupCtrl 100, _group controlsGroupCtrl 101, ''] call BIS_fnc_initSliderValue;";
            attributeLoad = "[_this controlsGroupCtrl 100, _this controlsGroupCtrl 101, '', _value] call BIS_fnc_initSliderValue;";
            attributeSave = "round sliderPosition (_this controlsGroupCtrl 100)";
            class Controls: Controls {
                class Title: Title {};
                class Value: Value {
                    sliderRange[] = {5,40};
                    sliderPosition = 15;
                    lineSize = 1;
                    sliderStep = 1;
                };
                class Edit: Edit {};
            };
        };
        class TAE_CivilianVehicleCountSlider: TAE_CivilianCountSlider {
            class Controls: Controls {
                class Title: Title {};
                class Value: Value {
                    sliderRange[] = {0,10};
                    sliderPosition = 0;
                };
                class Edit: Edit {};
            };
        };
    };
};
