# Tier 3 任務 JSON 索引（第四卷規劃藍圖・v1.1 密度重組版）

> 狀態：**Act 1–4 共 22 份任務 JSON 已全部實裝並通過 `quest_audit.py` 驗證**；僅餘 Act 5 (`Ch.165–170`) 4 份預定於最後一幕落地。  
> **任務密度調整**：依據 `TODO.md` Phase 6 Step 3 檢討，修正原 12 份／44 章（`0.27`/章）過疏問題，參考前三卷（約 `0.72`/章）重組為 **26 份規劃任務／44 章（`0.59`/章）**，特別將 **Act 1 拆細為 3 條任務**、**Act 4 依五條並行戰線拆為 5 條非二元且不綁特定身世之並行支線**共同計入 `EVENT_TIER3_CALIBRATION`。

| 類別目錄 | 規劃任務檔名（計 26 份規劃任務） | 對應幕次與章節 | 預估前置區域／NPC／世界事件指標 |
|---|---|---|---|
| `quests/main/` | `v4_act1_bastion_arrival.json` | Act 1 (Ch. 127–128) | ✅ 已實裝：`/d/realm/peach_plateau` → `/d/realm/edge/ash_watch_post`、`ash_warden_qi`（熄燈＋阻尼實測） |
| `quests/main/` | `v4_act1_salt_market_stove.json` | Act 1 (Ch. 129, 132) | ✅ 已實裝：`/d/realm/edge/stardust_salt_flats`、`salt_market_broker`、`ash_watch_post`（預扣查帳＋換芯暖爐） |
| `quests/side/` | `v4_act1_clinic_and_eagle_mark.json` | Act 1 (Ch. 130–131, 133–134) | ✅ 已實裝：`/d/realm/edge/edge_clinic`、`basalt_ridge`、`scorch_border`（排異診斷＋向量測繪＋鷹記拓印） |
| `quests/main/` | `v4_act2_taixu_calibration_spy.json` | Act 2 (Ch. 135–136) | ✅ 已實裝：`/d/realm/taixu/white_jade_steps`、`taixu_observer_heng`、`taixu_clerk_yanping`（玉化晶核＋銅匣債，`tier3_u/law` 路徑二） |
| `quests/main/` | `v4_act2_wanwu_ark_registry.json` | Act 2 (Ch. 137–138) | ✅ 已實裝：`/d/realm/wanwu/scrap_ring`、`wanwu_auditor_qi`、`wanwu_inspector_chen`（拆銅匣＋九號艙檔，`tier3_u/craft` 路徑二） |
| `quests/main/` | `v4_act2_zhanzu_yanshan_trail.json` | Act 2 (Ch. 139–140) | ✅ 已實裝：`/d/realm/zhanzu/hunting_camp`、`zhanzu_packmaster_tuo`、`yan_shan`（重力截息＋斷目重逢，`tier3_u/force` 雙路徑） |
| `quests/side/` | `v4_act2_law_rejection_clinic.json` | Act 2 (Ch. 141) | ✅ 已實裝：`/d/realm/edge/edge_clinic`、`stone_clinic_healer_su`（三極樣本緩衝針方＋血樣暗倉座標，`tier3_u/medicine`） |
| `quests/main/` | `v4_act2_nine_city_offline_node.json` | Act 2 (Ch. 142–143) | ✅ 已實裝：`/d/realm/wanwu/nine_city_node`（啟封樞紐＋逐戶補登石堡火種配額總帳，`tier3_u/commerce` 路徑一） |
| `quests/main/` | `v4_act2_countdown_convergence.json` | Act 2 (Ch. 144) | ✅ 已實裝：`/d/realm/edge/ash_watch_post`（五方異常拼圖算準九十日倒數） |
| `quests/main/` | `v4_act3_labor_pact_stations.json` | Act 3 (Ch. 145) | ✅ 已實裝：`/d/realm/wanwu/scrap_ring`、`wanwu_auditor_qi`（外環二十四站與鹽晶寮停工準備） |
| `quests/main/` | `v4_act3_three_pole_mutual_compact.json` | Act 3 (Ch. 146) | ✅ 已實裝：`/d/realm/edge/ash_watch_post`、`zhanzu_packmaster_tuo`（締結《三極維護工役互助密約》，`tier3_u/commerce` 路徑二） |
| `quests/side/` | `v4_act3_cross_realm_broker_intercept.json` | Act 3 (Ch. 147) | ✅ 已實裝：`/d/realm/wanwu/scrap_ring`、`cross_realm_broker`（截獲赤火篆印跨界走私晶箱） |
| `quests/event/` | `v4_act3_taixu_scan_deflection.json` | Act 3 (Ch. 148–149) | ✅ 已實裝：`/d/realm/edge/ash_watch_post`、`taixu_clerk_yanping`（偏折星鎖三息保名冊，聯動 `EVENT_TIER3_CALIBRATION` `T-2 → T-1`） |
| `quests/main/` | `v4_act3_arena_rescue_yanshan.json` | Act 3 (Ch. 150–151) | ✅ 已實裝：`/d/realm/zhanzu/arena_pit`、`zhanzu_quartermaster_han`、`yan_shan`（鬥獸坑奪救燕山與九礦奴） |
| `quests/main/` | `v4_act3_human_seed_bridge_truce.json` | Act 3 (Ch. 152) | ✅ 已實裝：`/d/realm/wanwu/arbitration_bridge`、`wanwu_arbiter_core`、`wanwu_inspector_chen`（憑補冊總帳暫緩清零十日） |
| `quests/side/` | `v4_act3_ten_day_war_prep.json` | Act 3 (Ch. 153–154) | ✅ 已實裝：`/d/realm/edge/ash_watch_post`、`edge_clinic`（熔爐改鑄總栓與分流針、藥爐備料） |
| `quests/event/` | `v4_act4_labor_strike_sanction.json` | Act 4 (Ch. 155–156) | ✅ 已實裝：`/d/realm/wanwu/scrap_ring`（戰線一・不綁身世：`labor_solidarity`，大停工與部落拒徵） |
| `quests/event/` | `v4_act4_taixu_star_deflection.json` | Act 4 (Ch. 157–158) | ✅ 已實裝：`/d/realm/taixu/calibration_hall`（戰線二・不綁身世：`array_deflection`，揭帳與偏星一度半） |
| `quests/event/` | `v4_act4_bone_gate_defense.json` | Act 4 (Ch. 159–160) | ✅ 已實裝：`/d/realm/zhanzu/bone_gate`（戰線三・不綁身世：`outpost_defense`，巨骨哨卡阻獸與五年密牌） |
| `quests/event/` | `v4_act4_clinic_fog_and_conduit.json` | Act 4 (Ch. 161–162) | ✅ 已實裝：`/d/realm/edge/edge_clinic` → `/d/realm/wanwu/conduit_well`（戰線四・不綁身世：`outpost_defense`＋`labor_solidarity`，三十座藥爐護民與帶壓活榫換栓） |
| `quests/event/` | `v4_act4_arbitration_equal_charter.json` | Act 4 (Ch. 163–164) | ✅ 已實裝：`/d/realm/wanwu/arbitration_bridge`（戰線五・不綁身世：`charter_legitimacy`，平權契書、百年停戰與歸墟深碑警報，`T0 → T+1`） |
| `quests/side/` | `v4_act4_postwar_clinic_relief.json` | Act 4 (Ch. 164 善後) | ✅ 已實裝：`/d/realm/edge/edge_clinic`、`stone_clinic_healer_su`（校準夜後傷員照護與三極貨殖清單巡檢） |
| `quests/main/` | `v4_act5_beacon_crystal_gathering.json` | Act 5 (Ch. 165–166) | `/d/realm/edge/beacon_relay`（籌備三百斤高純鹽晶儲柱與黑鐵導波環，計入 `beacon_readiness`） |
| `quests/epic/` | `v4_act5_two_way_beacon_and_guixu.json` | Act 5 (Ch. 167, 170) | `/d/realm/edge/beacon_relay` → `/d/realm/peach_plateau`（三息傳信雲津兼遙見歸墟門縫，`T+2`；不自動解鎖 Tier 4） |
| `quests/side/` | `v4_act5_bastion_autonomy_council.json` | Act 5 (Ch. 168) | `/d/realm/edge/ash_watch_post`、`ash_warden_qi`（遺民留守自治與去留抉擇議會） |
| `quests/side/` | `v4_act5_three_yuan_prototype_trial.json` | Act 5 (Ch. 169) | `/d/realm/edge/basalt_ridge`（五人三元雛流試驗，驗證 `§4.2` 共鳴原型而不強制綁定個人解鎖） |

---

## 底層基礎建設現況（Step 3 已落地）

- **規則引擎**：`/daemon/tier3_d.c`（`TIER3_D`）與 `/secure/combat_d.c`（舊招三倍耗能／半威力、單一可調表、兩觀察路徑解鎖 `U`、高代價信標檢定、`§4.2` Tier 4 門檻隔離）。
- **世界事件定義與狀態機**：`data/event_defs/tier3_calibration.json`、`include/world_event.h`（`EVENT_TIER3_CALIBRATION`）與 `daemon/event_manager.c`（純函式評估器 `evaluate_tier3_calibration()` 與週期輪轉 `cycle_tier3_calibration()`）。
- **自動化防歪樓測試**：`tests/test_tier3_foundation.c`（已納入 `cmd_tests` 總測試套組）。
- **前哨起點**：`/d/realm/peach_plateau.c` 已於第三卷第五幕實裝。
