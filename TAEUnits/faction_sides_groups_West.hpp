class JMSLLTE_hutt_fact {
	name = "Hutt enforcers";
	class JMSLLTE_group_hutt_inf {
		name = "Hutt forces";
		aliveCategory = "Infantry";
		class JMSLLTE_group_hutt_inf_squad {
			name = "Hutt squad";
			faction = "JMSLLTE_hutt_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_leader";
				rank = "SERGEANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_raider";
				rank = "CORPORAL";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_hutt_raider";
				rank = "PRIVATE";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_raider";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
			class Unit4 {
				side = 1;
				vehicle = "JMSLLTE_hutt_heavy";
				rank = "PRIVATE";
				position[] = {7, 0, 0};
			};
			class Unit5 {
				side = 1;
				vehicle = "JMSLLTE_hutt_raider";
				rank = "CORPORAL";
				position[] = {9, 0, 0};
			};
			class Unit6 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_raider";
				rank = "PRIVATE";
				position[] = {11, 0, 0};
			};
			class Unit7 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_heavyAT";
				rank = "PRIVATE";
				position[] = {13, 0, 0};
			};
			class Unit8 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_heavy";
				rank = "PRIVATE";
				position[] = {15, 0, 0};
			};
		};
		class JMSLLTE_group_hutt_inf_fireteam {
			name = "Hutt fireteam";
			faction = "JMSLLTE_hutt_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_leader";
				rank = "SERGEANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_hutt_raider";
				rank = "CORPORAL";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_heavy";
				rank = "PRIVATE";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_raider";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
		};
		class JMSLLTE_group_hutt_inf_sentry {
			name = "Hutt sentry";
			faction = "JMSLLTE_hutt_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_raider";
				rank = "PRIVATE";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_hutt_raider";
				rank = "PRIVATE";
				position[] = {-5, 0, 0};
			};
		};
		class JMSLLTE_group_hutt_inf_ATpair {
			name = "Hutt AT pair";
			faction = "JMSLLTE_hutt_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_raider";
				rank = "PRIVATE";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_hutt_al_heavyAT";
				rank = "PRIVATE";
				position[] = {-5, 0, 0};
			};
		};
	};
};
class JMSLLTE_Jinata_fact {
	name = "Jinata Security";
	class JMSLLTE_group_jinata_inf {
		name = "Security forces";
		aliveCategory = "Infantry";
		class JMSLLTE_group_jinata_inf_squad {
			name = "Security squad";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_serg";
				rank = "SERGEANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "CORPORAL";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "PRIVATE";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
			class Unit4 {
				side = 1;
				vehicle = "JMSLLTE_jinata_heavy";
				rank = "PRIVATE";
				position[] = {7, 0, 0};
			};
			class Unit5 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "CORPORAL";
				position[] = {9, 0, 0};
			};
			class Unit6 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "PRIVATE";
				position[] = {11, 0, 0};
			};
			class Unit7 {
				side = 1;
				vehicle = "JMSLLTE_jinata_snip";
				rank = "PRIVATE";
				position[] = {13, 0, 0};
			};
			class Unit8 {
				side = 1;
				vehicle = "JMSLLTE_jinata_heavy";
				rank = "PRIVATE";
				position[] = {15, 0, 0};
			};
		};
		class JMSLLTE_group_jinata_inf_fireteam {
			name = "Security fireteam";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_serg";
				rank = "SERGEANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "CORPORAL";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_jinata_heavy";
				rank = "PRIVATE";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
		};
		class JMSLLTE_group_jinata_inf_al_fireteam {
			name = "Security mixed fireteam";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_serg";
				rank = "SERGEANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_al_trooper";
				rank = "CORPORAL";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_jinata_heavy";
				rank = "PRIVATE";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_jinata_al_trooper";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
		};
		class JMSLLTE_group_jinata_inf_vetteam {
			name = "Security elites";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_serg";
				rank = "SERGEANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_operative";
				rank = "CORPORAL";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_jinata_operative";
				rank = "PRIVATE";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_jinata_heavy";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
		};
		class JMSLLTE_group_jinata_inf_HQ {
			name = "Security HQ";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_officer";
				rank = "LIEUTENANT";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_serg";
				rank = "SERGEANT";
				position[] = {-5, 0, 0};
			};
			class Unit2 {
				side = 1;
				vehicle = "JMSLLTE_jinata_operative";
				rank = "CORPORAL";
				position[] = {3, 0, 0};
			};
			class Unit3 {
				side = 1;
				vehicle = "JMSLLTE_jinata_snip";
				rank = "PRIVATE";
				position[] = {5, 0, 0};
			};
		};
		class JMSLLTE_group_jinata_inf_sentry {
			name = "Security sentry";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "PRIVATE";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooper";
				rank = "PRIVATE";
				position[] = {-5, 0, 0};
			};
		};
		class JMSLLTE_group_jinata_inf_ATpair {
			name = "Security AT pair";
			faction = "JMSLLTE_Jinata_fact";
			side = 1;
			rarityGroup = 0.75;
			icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
			class Unit0 {
				side = 1;
				vehicle = "JMSLLTE_jinata_al_trooper";
				rank = "PRIVATE";
				position[] = {0, 5, 0};
			};
			class Unit1 {
				side = 1;
				vehicle = "JMSLLTE_jinata_trooperAT";
				rank = "PRIVATE";
				position[] = {-5, 0, 0};
			};
		};
	};
};
