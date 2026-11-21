# Tier 3 任務 JSON 索引（第四卷規劃藍圖）

> 狀態：**規劃索引（v1.0，尚未建立 `quests/*/v4_*.json` 檔案）**。待第四卷第一至五幕開展實作後，將依下表對齊 `quests/` 目錄分類逐幕落地並納入 `quest_audit.py` 稽核（比照第三卷 `tier2_quest_json_index.md` 模式）：

| 類別目錄 | 規劃任務檔名（計 12 份規劃任務） | 對應幕次與章節 | 預估前置區域／NPC |
|---|---|---|---|
| `quests/main/` | `v4_act1_ash_bastion_survival.json` | Act 1 (Ch. 127–134) | `/d/realm/edge/ash_watch_post`、`ash_warden_qi` |
| `quests/main/` | `v4_act2_taixu_calibration_spy.json` | Act 2 (Ch. 135–136) | `/d/realm/taixu/white_jade_steps`、`taixu_observer_heng` |
| `quests/main/` | `v4_act2_wanwu_ark_registry.json` | Act 2 (Ch. 137–138) | `/d/realm/wanwu/scrap_ring`、`wanwu_auditor_qi` |
| `quests/main/` | `v4_act2_zhanzu_yanshan_trail.json` | Act 2 (Ch. 139–140) | `/d/realm/zhanzu/hunting_camp`、`zhanzu_packmaster_tuo`、`yan_shan` |
| `quests/main/` | `v4_act2_nine_city_offline_node.json` | Act 2 (Ch. 142–144) | `/d/realm/wanwu/nine_city_node`、`wanwu_arbiter_core` |
| `quests/main/` | `v4_act3_arena_rescue_yanshan.json` | Act 3 (Ch. 150–151) | `/d/realm/zhanzu/arena_pit`、`yan_shan` |
| `quests/main/` | `v4_act4_shen_yunnini_charter.json` | Act 4 (Ch. 152, 163) | `/d/realm/wanwu/arbitration_bridge`、`wanwu_arbiter_core` |
| `quests/side/` | `v4_act2_law_rejection_clinic.json` | Act 2 (Ch. 130, 141) | `/d/realm/edge/edge_clinic`、`stone_clinic_healer_su` |
| `quests/side/` | `v4_act3_cross_realm_broker_intercept.json` | Act 3 (Ch. 147) | `/d/realm/wanwu/scrap_ring`、`cross_realm_broker` |
| `quests/event/` | `v4_act3_taixu_scan_deflection.json` | Act 3 (Ch. 148–149) | `/d/realm/edge/ash_watch_post`（聯動 `EVENT_TIER3_CALIBRATION`） |
| `quests/event/` | `v4_act4_three_pillar_calibration_crisis.json` | Act 4 (Ch. 155–162) | `/d/realm/taixu/calibration_hall`、`/d/realm/wanwu/conduit_well` |
| `quests/epic/` | `v4_act5_two_way_beacon_and_guixu.json` | Act 5 (Ch. 165–170) | `/d/realm/edge/beacon_relay`、`/d/realm/peach_plateau`（預埋歸墟入口） |

- **規劃世界事件定義檔**：`data/event_defs/tier3_calibration.json`（對稱 `tier2_crisis.json`，管理 `T-2 → T+2` 校準與大停工博弈指標）。
- **目前 Mudlib 實作前哨**：`/d/realm/peach_plateau.c` 已於第三卷第五幕落成並通過 `test_v3_act5.c` 驗證，作為進入本任務群的唯一零號錨點。
