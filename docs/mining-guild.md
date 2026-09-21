# Mining Guild

OPFOR faction imported from Havoc's Workshop composition [3805843285](https://steamcommunity.com/sharedfiles/filedetails/?id=3805843285). The downloaded header credits Hondo; the user identifies the creator as Havoc. Original model/texture authors remain inherited. No new armor textures are created.

64 placements deduplicate to 20 classes: 8 personnel and 12 vehicles. Original mod classes are not modified. Requires the composition's listed mods; the Workshop composition itself is not required at runtime.

| Entry | TAE classname | Source class |
|---|---|---|
| Missile Specialist | `TAE_MiningGuild_MissileSpecialist` | `O_Soldier_LAT_F` |
| Pilot | `TAE_MiningGuild_Pilot` | `O_helipilot_F` |
| TIE Fighter | `TAE_MiningGuild_TIE` | `WM_TieMG` |
| Rifleman | `TAE_MiningGuild_Rifleman` | `O_Soldier_F` |
| LIU (Support) | `TAE_MiningGuild_LIUS_F` | `JMSLLTE_B_veh_LIUSfwmb_imp_F` |
| LIU (Transport) | `TAE_MiningGuild_LIUS_T` | `JMSLLTE_B_veh_LIUSt_imp_F` |
| Squad Leader | `TAE_MiningGuild_SquadLeader` | `O_Soldier_SL_F` |
| PK-V5 | `TAE_MiningGuild_PKV5` | `ls_vehicle_pkv5_imperial` |
| RAAT | `TAE_MiningGuild_RAAT` | `KND_RAT` |
| 74-Z Speeder | `TAE_MiningGuild_Speeder74Z` | `WM_74Z_Imperial_Brown` |
| X-34 Landspeeder | `TAE_MiningGuild_X34` | `JMSLLTE_B_veh_x34mk2_reb_F` |
| ITT | `TAE_MiningGuild_ITT` | `JMSLLTE_I_veh_ITT_impR_F` |
| LA-S (Deserter) | `TAE_MiningGuild_LAS_Deserter` | `mti_factions_deserters_LAS` |
| LA-S (Z-6) | `TAE_MiningGuild_LAS_Z6` | `knd_heli_las_z6` |
| Nu-class Shuttle | `TAE_MiningGuild_Nu` | `mti_armoury_vehicles_nuclass_nuclass` |
| HK-55 Droid | `TAE_MiningGuild_HK55` | `SFA_KOTOR_HK55` |
| V-wing | `TAE_MiningGuild_VWing` | `WM_VWing` |
| Grenadier | `TAE_MiningGuild_Grenadier` | `O_Soldier_GL_F` |
| Heavy Gunner | `TAE_MiningGuild_HeavyGunner` | `O_Soldier_AR_F` |
| Marksman | `TAE_MiningGuild_Marksman` | `O_Sharpshooter_F` |

3 unique multi-unit infantry formations also appear under OPFOR / Mining Guild. Empty vehicle placement remains empty; standard crewed placement uses guild pilot/rifleman crew.

Loadouts retain container contents, ammunition counts, and weapon attachments. Vehicle skin choices retained: RAAT `bare`, ITT `Tex_ITT_base`. Init code is not copied or executed from the composition.

Validation: config compilation and importer checks; Eden/Zeus preview, dedicated server spawning, respawn and JIP still require in-game testing.
