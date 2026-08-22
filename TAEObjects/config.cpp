class CfgPatches {
	class TAEObjects {
		name = "TAE Objects";
		author = "TAE Mod Team";
		requiredAddons[] = {
			"A3_Weapons_F",
			"ace_interaction",
			"ace_interact_menu",
			"ace_arsenal",
			"ace_medical_treatment",
			"ace_dragging",
			"ace_cargo",
			"cba_xeh",
			"JLTS_weapons_crates",
			"3AS_Props",
			"3AS_Prop_Droids",
			"3as_GNK_Prop",
			"3AS_Prop_Flags",
			"ls_characters_mandalorian",
			"tgf_helmets",
			"TAEGear_Helmets_Customs",
			"TAEGear_Armors_Customs",
			"TAEDrones",
			"mti_armoury_props_locker",
			"SFA_Structure_Bed",
			"knd_crates"
		};
		units[] = {
			"TAE_Restricted_Arsenal_Box",
			"TAE_Specialization_Gonk_Droid",
			"TAE_Medical_Droid",
			"TAE_Ammo_Crate",
			"TAE_Demo_Crate",
			"TAE_Medical_Crate",
			"TAE_Bed_Acklay",
			"TAE_Bed_Foxx",
			"TAE_Bed_Varen",
			"TAE_Bed_Rook",
			"TAE_Bed_HouseKarr",
			"TAE_Bed_Shyyyo",
			"TAE_Vexillum_Acklay",
			"TAE_Vexillum_Foxx",
			"TAE_Vexillum_Varen",
			"TAE_Vexillum_Rook",
			"TAE_Vexillum_HouseKarr",
			"TAE_Vexillum_Shyyyo",
			"TAE_MokTech_Locker",
			"TAE_Wearable_Acklay_Helmet",
			"TAE_Wearable_Foxx_Helmet",
			"TAE_Wearable_Varen_Helmet",
			"TAE_Wearable_Haranverd_Helmet",
			"TAE_Wearable_Rook_Helmet",
			"TAE_Wearable_Freelancer_Helmet",
			"TAE_Wearable_Nox_Helmet",
			"TAE_Wearable_Hondo_Helmet",
			"TAE_Wearable_Edonn_Helmet",
			"TAE_Wearable_Teka_Helmet"
		};
		weapons[] = {};
	};
};

class CfgEditorCategories {
	class TAE_EdCat_HouseKarr {
		displayName = "[TAE] House Karr Objects";
	};
};

class CfgEditorSubcategories {
	class TAE_EdSubcat_HouseKarr_ArsenalServices {
		displayName = "Arsenal and Services";
	};

	class TAE_EdSubcat_HouseKarr_Supplies {
		displayName = "Supplies";
	};

	class TAE_EdSubcat_HouseKarr_Vexillums {
		displayName = "Vexillums";
	};

	class TAE_EdSubcat_HouseKarr_Furniture {
		displayName = "Furniture";
	};

	class TAE_EdSubcat_HouseKarr_WearableItems {
		displayName = "Wearable Items";
	};
};

class CfgFunctions {
	class TAE {
		class Objects {
			file = "TAEObjects\functions";
			class applyWearableLoadout {};
			class fullHealPlayer {};
			class initRestrictedArsenal {};
			class setPlayerPermissions {};
		};
	};
};

class Extended_Init_EventHandlers {
	class TAE_Restricted_Arsenal_Box {
		class TAEObjects_initRestrictedArsenal {
			init = "_this call TAE_fnc_initRestrictedArsenal";
		};
	};

};

class CfgVehicles {
	class JLTS_Ammobox_weapons_GAR;
	class JLTS_Ammobox_explosives_GAR;
	class JLTS_Ammobox_ammo_GAR;
	class 3AS_Small_Mando_Stand;
	class SFA_Bed_Single;
	class ThingX;
	class mti_armoury_props_locker_base;
	class 3as_GNK;
	class Land_3AS_Medical_Droid;

	class TAE_Specialization_Gonk_Droid: 3as_GNK {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Specialization Gonk Droid";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;

		class ACE_Actions {
			class ACE_MainActions {
				displayName = "Specialization Permissions";
				condition = "alive _player";
				distance = 3;
				position = "[0,0,0.5]";

				class TAE_GrantEngineerPermissions {
					displayName = "Receive Engineer and Explosives Permissions";
					condition = "alive _player";
					statement = "[_player, 'engineer'] call TAE_fnc_setPlayerPermissions";
				};

				class TAE_GrantMedicalPermissions {
					displayName = "Receive Medical Permissions";
					condition = "alive _player";
					statement = "[_player, 'medic'] call TAE_fnc_setPlayerPermissions";
				};

				class TAE_RemoveAllPermissions {
					displayName = "Remove All Permissions";
					condition = "alive _player";
					statement = "[_player, 'none'] call TAE_fnc_setPlayerPermissions";
				};
			};
		};
	};

	class TAE_Medical_Droid: Land_3AS_Medical_Droid {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Medical Droid";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;

		class ACE_Actions {
			class ACE_MainActions {
				displayName = "Medical Droid";
				condition = "alive _player";
				distance = 3;
				position = "[0,0,0.5]";

				class TAE_FullHeal {
					displayName = "Full Heal";
					condition = "alive _player";
					statement = "[_player] call TAE_fnc_fullHealPlayer";
				};
			};
		};
	};

	class TAE_Bed_Base: SFA_Bed_Single {
		scope = 0;
		scopeCurator = 0;
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Furniture";
		hiddenSelections[] = {"camo1"};
	};

	class TAE_Bed_Acklay: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Acklay Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_acklay_co.paa"
		};
	};

	class TAE_Bed_Foxx: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Foxx Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_foxx_co.paa"
		};
	};

	class TAE_Bed_Varen: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Varen Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_varen_co.paa"
		};
	};

	class TAE_Bed_Rook: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Rook Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_rook_co.paa"
		};
	};

	class TAE_Bed_HouseKarr: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_karr_co.paa"
		};
	};

	class TAE_Bed_Shyyyo: TAE_Bed_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Shyyyo Bed";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\furniture\tae_bed_shyyyo_co.paa"
		};
	};

	class TAE_Wearable_Helmet_Base: ThingX {
		scope = 0;
		scopeCurator = 0;
		displayName = "Wearable Helmet";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_WearableItems";
		model = "\ls\core\addons\characters_mandalorian\helmets\traditional\ls_helmet_mandalorian_traditional.p3d";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Acklay\LS_TRAD_Helmet_Acklay.paa",
			"\TAEGear\data\Acklay\LS_TRAD_Visor_Acklay.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		simulation = "thingX";
		armor = 50;

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_cargo_canLoad = 0;
		ace_cargo_size = -1;
		ace_cargo_noRename = 1;
	};

	class TAE_Wearable_Acklay_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Acklay Helmet";

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnAcklayArmor {
					displayName = "Put On Acklay's Armor";
					condition = "true";
					statement = "[_player,'tae_acklay_armor','tae_acklay_helmet','tae_ls_grey_rangefinder','','tae_uniform_ls_mandalorian'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnStasikArmor {
					displayName = "Put On Stasik's Armor";
					condition = "true";
					statement = "[_player,'tae_stasik_armor','tae_stasik_helmet','tgf_nvg_rangefinder_r','','tae_uniform_black_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnJimothyArmor {
					displayName = "Put On Jimothy's Armor";
					condition = "true";
					statement = "[_player,'tae_jimothy_armor','tae_jimothy_helmet','tae_jimothy_rangefinder','tae_facewear_ls_neck_lining','tae_uniform_vau'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnFrenkArmor {
					displayName = "Put On Frenk's Armor";
					condition = "true";
					statement = "[_player,'tae_frenk_armor','tae_frenk_helmet','tae_dark_grey_rangefinder','tae_facewear_ls_neck_lining','tae_uniform_dark_green_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnTowiArmor {
					displayName = "Put On Towi's Armor";
					condition = "true";
					statement = "[_player,'tae_acklay_niteowl_armor','tae_towi_helmet','tae_ls_grey_rangefinder','tae_facewear_ls_neck_lining','tae_uniform_black_female'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnNiteOwlArmor {
					displayName = "Put On Nite Owl's Armor";
					condition = "true";
					statement = "[_player,'tae_acklay_niteowl_armor','tae_acklay_niteowl_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_black_female'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Foxx_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Foxx Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Foxx\TRAD_Helmet_Foxx.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnFoxxArmor {
					displayName = "Put On Foxx's Armor";
					condition = "true";
					statement = "[_player,'tae_foxx_armor','tae_foxx_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnJunoArmor {
					displayName = "Put On Juno's Armor";
					condition = "true";
					statement = "[_player,'tae_juno_armor','tae_juno_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnBeanArmor {
					displayName = "Put On Bean's Armor";
					condition = "true";
					statement = "[_player,'tae_foxx_armor','tae_bean_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnGreyArmor {
					displayName = "Put On Grey's Armor";
					condition = "true";
					statement = "[_player,'tae_foxx_armor','tae_grey_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnGalaxyArmor {
					displayName = "Put On Galaxy's Armor";
					condition = "true";
					statement = "[_player,'tae_galaxy_armor','tae_galaxy_helmet','tae_foxx_rangefinder','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Varen_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Varen Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Varen\TRAD_Helmet_Varen.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnVarenArmor {
					displayName = "Put On Varen's Armor";
					condition = "true";
					statement = "[_player,'tae_varen_recon_armor','tae_varen_helmet','tae_dark_red_rangefinder','','tae_uniform_dark_red_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnVarenNiteOwlArmor {
					displayName = "Put On Varen's Nite Owl Armor";
					condition = "true";
					statement = "[_player,'tae_varen_niteowl_armor','tae_varen_helmet','','','tae_uniform_dark_red_female'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Haranverd_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Clan Haranverd Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Haranverd\TRAD_Helmet_Haranverd.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				position = "[0,0,0]";
				distance = 2;
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnHaranverdTraditionalArmor {
					displayName = "Put On Clan Haranverd Traditional Armor";
					condition = "true";
					statement = "[_player,'tae_haranverd_traditional_armor','tae_haranverd_traditional_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnHaranverdNiteOwlArmor {
					displayName = "Put On Clan Haranverd Nite Owl Armor";
					condition = "true";
					statement = "[_player,'tae_haranverd_niteowl_armor','tae_haranverd_niteowl_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Rook_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Rook Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Rook\TRAD_Helmet_Rook.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnRookArmor {
					displayName = "Put On Rook's Armor";
					condition = "true";
					statement = "[_player,'tae_rook_armor','tae_rook_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnHadesArmor {
					displayName = "Put On Hades' Armor";
					condition = "true";
					statement = "[_player,'tae_hades_armor','tae_hades_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnVarioArmor {
					displayName = "Put On Vario's Armor";
					condition = "true";
					statement = "[_player,'tae_rook_armor','tae_vario_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnAndoraArmor {
					displayName = "Put On Andora's Armor";
					condition = "true";
					statement = "[_player,'tae_andora_armor','tae_andora_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_black_female'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnGoostivoolArmor {
					displayName = "Put On Goostivool's Armor";
					condition = "true";
					statement = "[_player,'tae_goostivool_armor','tae_goostivool_helmet','tgf_nvg_rangefinder_r','','tae_uniform_ls_mandalorian'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnShenArmor {
					displayName = "Put On Shen's Armor";
					condition = "true";
					statement = "[_player,'tae_rook_armor','tae_shen_helmet','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Freelancer_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Freelancer Helmet";
		model = "\z\tgf\addons\helmets\traditional\traditional_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\HouseKarr\Traditional\TRAD_Helmet_Mando.paa",
			"\z\tgf\addons\helmets\traditional\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnRecruitArmor {
					displayName = "Put On Mandalorian Recruit's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_medium_mr','tae_karr_helmet_mr','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnApprenticeArmor {
					displayName = "Put On Mandalorian Apprentice's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_medium_ma','tae_karr_helmet_ma','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnMandalorianArmor {
					displayName = "Put On Mandalorian's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_medium_mm','tae_karr_helmet_mm','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnVeteranArmor {
					displayName = "Put On Mandalorian Veteran's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_medium_mv','tae_karr_helmet_mv','tgf_nvg_rangefinder_r','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnNiteOwlRecruitArmor {
					displayName = "Put On Nite Owl Recruit's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_niteowl_mr','tae_karr_helmet_niteowl_mr','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnNiteOwlApprenticeArmor {
					displayName = "Put On Nite Owl Apprentice's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_niteowl_ma','tae_karr_helmet_niteowl_ma','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnNovaArmor {
					displayName = "Put On Nova's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_niteowl_ma','tae_nova_helmet','tgf_nvg_nite_owl_rangefinder','','tae_uniform_white_female'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnNiteOwlMandalorianArmor {
					displayName = "Put On Nite Owl's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_niteowl_mm','tae_karr_helmet_niteowl_mm','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnNiteOwlVeteranArmor {
					displayName = "Put On Nite Owl Veteran's Armor";
					condition = "true";
					statement = "[_player,'tae_karr_armor_niteowl_mv','tae_karr_helmet_niteowl_mv','tgf_nvg_nite_owl_rangefinder','','tae_uniform_grey_female'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Nox_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Nox Helmet";
		model = "\z\tgf\addons\helmets\warlord\warlord_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Nox\WAR_Helmet_Nox.paa",
			"\z\tgf\addons\helmets\warlord\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnNoxArmor {
					displayName = "Put On Nox's Armor";
					condition = "true";
					statement = "[_player,'tae_nox_armor','tae_nox_helmet','','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Hondo_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Hondo Helmet";
		model = "\z\tgf\addons\helmets\battle_master\battle_master.p3d";
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Hondo\BM_Helmet_Hondo.paa",
			"\z\tgf\addons\helmets\battle_master\data\camo2_co.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnHondoArmor {
					displayName = "Put On Hondo's Armor";
					condition = "true";
					statement = "[_player,'tae_hondo_armor','tae_hondo_helmet','','','tae_uniform_forgemaster_seal'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Edonn_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Edonn Helmet";
		model = "\ls\core\addons\characters_mandalorian\helmets\dinDjarin\ls_helmet_mandalorian_dinDjarin.p3d";
		hiddenSelections[] = {"camo1","visor","neckTex"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.paa",
			"\TAEGear\data\Edonn\LS_DIN_Visor_Edonn.paa",
			"\ls\core\addons\characters_mandalorian\helmets\traditional\data\neck_co.paa"
		};
		hiddenSelectionsMaterials[] = {
			"\TAEGear\data\Edonn\LS_DIN_Helmet_Edonn.rvmat",
			"\TAEGear\data\Edonn\LS_DIN_Visor_Edonn.rvmat"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnEdonnArmor {
					displayName = "Put On Edonn's Armor";
					condition = "true";
					statement = "[_player,'tae_edonn_armor','tae_edonn_helmet','tgf_nvg_circuit','','tae_uniform_ls_mandalorian'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_Wearable_Teka_Helmet: TAE_Wearable_Helmet_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "Shyyyo Pilot Helmet";
		model = "\z\tgf\addons\helmets\pilot\pilot_helmet.p3d";
		hiddenSelections[] = {"camo1","camo2","camo"};
		hiddenSelectionsTextures[] = {
			"\TAEGear\data\Shyyyo\PLT_Helmet_Shyyyo.paa",
			"\TAEGear\data\Shyyyo\PLT_Visor_Shyyyo.paa",
			"\TAEGear\data\Shyyyo\PLT_Lights_Shyyyo.paa"
		};

		class ACE_Actions {
			class ACE_MainActions {
				distance = 100;
				position = "[0,-0.3,0.8]";
				selection = "";
				displayName = "Helmet";
				condition = "true";

				class TAE_PutOnTekaArmor {
					displayName = "Put On Teka's Armor";
					condition = "true";
					statement = "[_player,'tae_teka_armor','tae_teka_helmet','','','tae_uniform_black_seal'] call TAE_fnc_applyWearableLoadout";
				};

				class TAE_PutOnShyyyoArmor {
					displayName = "Put On Shyyyo's Armor";
					condition = "true";
					statement = "[_player,'tae_shyyyo_recon_armor','tae_shyyyo_helmet','','','tae_uniform_grey_seal'] call TAE_fnc_applyWearableLoadout";
				};
			};
		};
	};

	class TAE_MokTech_Locker: mti_armoury_props_locker_base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Locker";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Furniture";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsMaterials[] = {
			"",
			"\z\mti_armoury\addons\props\locker\data\base_texture\locker.rvmat"
		};
		hiddenSelectionsTextures[] = {
			"",
			"\z\mti_armoury\addons\props\locker\data\base_texture\locker_CO.paa"
		};
		editorPreview = "\z\mti_armoury\addons\props\locker\data\editorpreviews\locker_base.jpg";

		ace_interaction_canInteract = 0;

		class UserActions {};

		class ACE_Actions {
			class ACE_MainActions {
				condition = "false";
			};
		};
		class ACE_SelfActions {};
	};

	class TAE_Vexillum_Base: 3AS_Small_Mando_Stand {
		scope = 0;
		scopeCurator = 0;
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Vexillums";
		model = "3AS\3AS_Props\Flags\models\Small_Stand\3as_Small_Stand.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsMaterials[] = {
			"\TAEObjects\data\vexillums\tae_vexillum.rvmat"
		};
	};

	class TAE_Vexillum_Acklay: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Acklay Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_acklay_co.paa"
		};
	};

	class TAE_Vexillum_Foxx: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Foxx Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_foxx_co.paa"
		};
	};

	class TAE_Vexillum_Varen: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Varen Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_varen_co.paa"
		};
	};

	class TAE_Vexillum_Rook: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Rook Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_rook_co.paa"
		};
	};

	class TAE_Vexillum_HouseKarr: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Command Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_house_karr_co.paa"
		};
	};

	class TAE_Vexillum_Shyyyo: TAE_Vexillum_Base {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Shyyyo Vexillum";
		hiddenSelectionsTextures[] = {
			"\TAEObjects\data\vexillums\tae_vexillum_shyyyo_co.paa"
		};
	};

	class TAE_Restricted_Arsenal_Box: JLTS_Ammobox_weapons_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Restricted ACE Arsenal";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_ArsenalServices";
		side = 3;
		armor = 4000;
		hiddenSelectionsTextures[] = {
			"\MRC\JLTS\weapons\Crates\data\crate_1_GAR_co.paa",
			"\TAEObjects\data\screen_karr_arsenal.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_cargo_canLoad = 0;
		ace_cargo_size = -1;

		class ACE_Actions {
			class ACE_MainActions {
				distance = 6;
				position = "[0,0,0.9]";
				selection = "";
				displayName = "Interactions";
				condition = "true";
			};
		};

		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		class TransportBackpacks {};
	};

	class TAE_Ammo_Crate: JLTS_Ammobox_weapons_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Ammo Crate";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Supplies";
		side = 3;
		armor = 4000;
		hiddenSelectionsTextures[] = {
			"\MRC\JLTS\weapons\Crates\data\crate_1_GAR_co.paa",
			"\TAEObjects\data\screen_karr_arsenal.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 4000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 2000;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};

		class TransportMagazines {};

		class TransportItems {
			class _xx_knd_crates_ammoTin_verySmall {
				name = "knd_crates_ammoTin_verySmall";
				count = 50;
			};
			class _xx_knd_crates_ammoTin_small {
				name = "knd_crates_ammoTin_small";
				count = 50;
			};
			class _xx_knd_crates_ammoTin_large {
				name = "knd_crates_ammoTin_large";
				count = 50;
			};
		};
		class TransportBackpacks {};
	};

	class TAE_Demo_Crate: JLTS_Ammobox_explosives_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Grenades/Explosives Crate";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Supplies";
		side = 3;
		armor = 4000;
		hiddenSelectionsTextures[] = {
			"\MRC\JLTS\weapons\Crates\data\crate_1_GAR_co.paa",
			"\TAEObjects\data\screen_karr_arsenal.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 2000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 1200;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};

		class TransportMagazines {
			class _xx_3AS_ThermalDetonator {
				magazine = "3AS_ThermalDetonator";
				count = 20;
			};
			class _xx_3AS_SonicDet {
				magazine = "3AS_SonicDet";
				count = 12;
			};
			class _xx_3AS_SmokeBlue {
				magazine = "3AS_SmokeBlue";
				count = 10;
			};
			class _xx_3AS_SmokeGreen {
				magazine = "3AS_SmokeGreen";
				count = 10;
			};
			class _xx_3AS_SmokeRed {
				magazine = "3AS_SmokeRed";
				count = 10;
			};
			class _xx_3AS_SmokeWhite {
				magazine = "3AS_SmokeWhite";
				count = 10;
			};
			class _xx_3AS_SmokeYellow {
				magazine = "3AS_SmokeYellow";
				count = 10;
			};
			class _xx_3AS_ThrowableCharge {
				magazine = "3AS_ThrowableCharge";
				count = 8;
			};
			class _xx_3AS_DetPack {
				magazine = "3AS_DetPack";
				count = 8;
			};
			class _xx_EC01_RemoteMagazine {
				magazine = "EC01_RemoteMagazine";
				count = 8;
			};
			class _xx_RTX_RemoteMagazine {
				magazine = "RTX_RemoteMagazine";
				count = 8;
			};
			class _xx_mti_armoury_mag_breaching_charge {
				magazine = "mti_armoury_mag_breaching_charge";
				count = 8;
			};
			class _xx_mti_armoury_mag_detpack {
				magazine = "mti_armoury_mag_detpack";
				count = 8;
			};
			class _xx_mti_armoury_mag_satchelCharge {
				magazine = "mti_armoury_mag_satchelCharge";
				count = 6;
			};
			class _xx_HX_AT_Mine_Mag {
				magazine = "HX_AT_Mine_Mag";
				count = 6;
			};
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 20;
			};
			class _xx_3Rnd_HE_Grenade_shell {
				magazine = "3Rnd_HE_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_Smoke_Grenade_shell {
				magazine = "1Rnd_Smoke_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_SmokeRed_Grenade_shell {
				magazine = "1Rnd_SmokeRed_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_SmokeGreen_Grenade_shell {
				magazine = "1Rnd_SmokeGreen_Grenade_shell";
				count = 10;
			};
			class _xx_1Rnd_SmokeBlue_Grenade_shell {
				magazine = "1Rnd_SmokeBlue_Grenade_shell";
				count = 10;
			};
			class _xx_UGL_FlareWhite_F {
				magazine = "UGL_FlareWhite_F";
				count = 10;
			};
			class _xx_UGL_FlareRed_F {
				magazine = "UGL_FlareRed_F";
				count = 10;
			};
			class _xx_UGL_FlareGreen_F {
				magazine = "UGL_FlareGreen_F";
				count = 10;
			};
			class _xx_UGL_FlareYellow_F {
				magazine = "UGL_FlareYellow_F";
				count = 10;
			};
		};

		class TransportItems {
			class _xx_ACE_Clacker {
				name = "ACE_Clacker";
				count = 6;
			};
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 6;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 4;
			};
			class _xx_ACE_wirecutter {
				name = "ACE_wirecutter";
				count = 4;
			};
		};

		class TransportBackpacks {};
	};

	class TAE_Medical_Crate: JLTS_Ammobox_ammo_GAR {
		scope = 2;
		scopeCurator = 2;
		displayName = "House Karr Medical Crate";
		author = "TAE Mod Team";
		editorCategory = "TAE_EdCat_HouseKarr";
		editorSubcategory = "TAE_EdSubcat_HouseKarr_Supplies";
		side = 3;
		armor = 4000;
		hiddenSelectionsTextures[] = {
			"\MRC\JLTS\weapons\Crates\data\crate_3_GAR_co.paa",
			"\TAEObjects\data\screen_karr_arsenal.paa"
		};

		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0,1.3,0};
		ace_dragging_dragDirection = 0;
		ace_dragging_ignoreWeight = 1;

		ace_cargo_canLoad = 1;
		ace_cargo_size = 1;
		ace_cargo_noRename = 0;
		ace_cargo_blockUnloadCarry = 1;

		maximumLoad = 2000;
		transportMaxWeapons = 200;
		transportMaxMagazines = 1200;
		transportMaxItems = 200;
		transportMaxBackpacks = 20;

		class TransportWeapons {};
		class TransportMagazines {};

		class TransportItems {
			class _xx_ACE_tourniquet {
				name = "ACE_tourniquet";
				count = 40;
			};
			class _xx_ACE_splint {
				name = "ACE_splint";
				count = 30;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 30;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 30;
			};
			class _xx_ACE_adenosine {
				name = "ACE_adenosine";
				count = 20;
			};
			class _xx_ACE_painkillers {
				name = "ACE_painkillers";
				count = 30;
			};
			class _xx_ACE_salineIV {
				name = "ACE_salineIV";
				count = 20;
			};
			class _xx_ACE_salineIV_500 {
				name = "ACE_salineIV_500";
				count = 30;
			};
			class _xx_ACE_salineIV_250 {
				name = "ACE_salineIV_250";
				count = 30;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 4;
			};
			class _xx_MTI_BactaSpray {
				name = "MTI_BactaSpray";
				count = 200;
			};
			class _xx_MTI_BactaPatch {
				name = "MTI_BactaPatch";
				count = 200;
			};
		};

		class TransportBackpacks {};
	};
};
