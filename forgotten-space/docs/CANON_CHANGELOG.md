# 《遺忘的世界》正典變更日誌 (Canon Changelog)

本文件追蹤《遺忘的世界》小說正典修訂與 Mudlib 可執行世界之間的雙向同步紀錄，配合 [data/canon_sync_matrix.json](../data/canon_sync_matrix.json) 與 [tests/quests/novel_mud_sync_audit.py](../tests/quests/novel_mud_sync_audit.py) 使用。

## 2026-11-22 — Phase 1 / Phase 2A 世界真實化與「空房歸零」擴建
* **生活空間與非主線支線擴建（254 → 288 間房、18 條平凡日常支線）**：
  * 六縣（`std/county_room.c`）與官道（`std/route_room.c`）全面具備動態風土五感、地方住民／關卡巡檢與歇腳／路況／盤查互動，並於六縣補入具名庶民生活支翼。
  * Tier 0 黑石鋪（22/22）、Tier 1 府城（75/75：含酒肆跑商、施藥義棚、魚市、染坊、四牆步道、暗渠及內外城分層五感）、四大宗門（36/36：含八荒／丹鼎／太清／天工外門雜役與功法場域五感）、Tier 2 雲津（21/21）、北荒（20/20）完成五感覆蓋與互動填實，全站 288 間房達成 **288/288 (100%) 五感覆蓋**與 **0 空房**（均由 `world_liveness_audit.py` 硬性鎖定）。
  * `RUMOR_D` 新增 `query_slice_of_life_rumor()` 平民日常流言，並新增 `tests/quests/world_liveness_audit.py` 與 `tests/test_world_liveness.c` 長駐回歸檢核。

## 2026-11-21 — 小說一至三卷修訂與 Mudlib 體驗深度對齊
* **小說正典（Vol.1–3 共 126 章）**：
  * 完成第一至三卷敘事節奏、五主角聲音辨識度、感官物質細節與第三卷終章洞天前瞻修訂。
  * 新增三卷讀者大事記與人物狀態導讀（`narrative/chapters/volume{1,2,3}/README.md`）。
* **Mudlib 體驗強化（對應 `ss.md` 全數條目）**：
  1. **感官優先與偏好系統**：`std/room.c` 新增全域 `touch`/`smell`/`listen` 與五身世感官視角濾鏡；`cmds/cmd_set.c` + `std/living.c` 支援 `brief_numeric` 純感官模式與 `brief_sensory` 切換；關鍵房間及 `d/realm/peach_plateau.c` 全面實裝動態感官與第四卷三倍源質警兆。
  2. **物證出示、互相印證與污染/偽造風險**：新增 `cmds/cmd_present.c`；`CITY_D` 實作跨卷互鎖組合（包含三卷北荒/戰祖物證鏈）、未封存物證暗渠涉水自動污染（`d/city/under/canal_hub.c`）、偽造假證反噬罰則及文承敬/白先生公證封存修復。
  3. **五器共鳴多階段技術校驗**：`d/sects/taiqing/ark_portal_chamber.c` 與 `d/wastes/ark_core_chamber.c` 實作 5 座方位石台/凹龕順序校驗、誤差診斷與實體信物/隊友協同（`strict` 模式）。
  4. **傳聞扭曲、卷幕動態、資格區隔與貢獻回放**：`RUMOR_D->query_distorted_rumor()` 接入 `std/npc.c`、`square_storyteller.c`、`zhao_hunter.c`、`market_special_buyer.c`；`EVENT_MANAGER_D` 實作小說卷幕對應、多玩家貢獻度階梯結算與 `cmds/cmd_chronicle.c` 歷史回放指令；`QUEST_ENGINE_D` 結合幕次倍率與多身世組隊協同獎勵加成；府城醫館、百工爐房、專材長街與宣道正殿透過 `std/room.c` 宣告式動作規則（`add_action_rule`）實質檢定「會做 vs 有資格做」。
