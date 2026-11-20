# Tier 2 任務 JSON 索引

第三卷任務 JSON 位於專案根目錄 `quests/`，依現有引擎分類存放（共 **28 份** `v3_*` 任務 JSON）：

- 一般主線：`quests/main/v3_*.json`（17 份：Act 1 實裝 6 份、Act 2 實裝 6 份、Act 3 實裝 2 份、Act 4 實裝 `v3_evidence_chain_hearing`、`v3_act4_sanyuan_defense`、`v3_postwar_reform_and_restitution` 共 3 份，全數 17 份主線已實裝）
- 支線任務：`quests/side/v3_*.json`（5 份：Act 1 一份、Act 2 兩份、Act 3 一份、Act 4 新增 `v3_act4_cloud_top_tournament`，全數已實裝）
- 史詩跨階段：`quests/epic/v3_*.json`（2 份：`v3_five_relic_resonance` 已實裝；`v3_tier2_departure` 為五幕初稿）
- 世界事件：`quests/event/v3_*.json`（4 份：Act 3 `v3_preserve_field_evidence` ＋ Act 4 `v3_cross_sect_evidence_audit`、`v3_crystal_quarantine_response`、`v3_north_wall_beast_surge` 全數實裝）
- 世界事件定義：`data/event_defs/tier2_crisis.json`（已註冊於 `include/world_event.h` 與 `daemon/event_manager.c`，支援會武前評估至 `defense_outcome` 三檔評價暨 `dump_status` 證物顯示；敘事同步副本：`narrative/events/tier2_crisis.json`）

**實作狀態**：第一至四幕（Ch. 83–120）對應之 **27 條 Act 1–4 任務**、64 間 Tier 2 LPC 房間（`/d/wastes/*` 19、`yunjin` 18、`taiqing` 7、`bahuang` 9、`tiangong` 6、`danding` 5）、49 個 Act 1–4 新建 `/clone/npc/*.c`（另複用 `mo_beggar`、`under_black_market_broker`）與 31 項新建 `/clone/item/*.c` 道具（另復用 `dao_crystal.c`）已實裝並納入 `test_v3_act1.c`～`test_v3_act4.c` 全數驗證；僅餘第五幕收官史詩任務 **1 份**（`v3_tier2_departure.json`）待後續封存觀測室與轉場章節落地。
