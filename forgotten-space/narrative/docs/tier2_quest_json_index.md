# Tier 2 任務 JSON 索引

第三卷任務 JSON 位於專案根目錄 `quests/`，依現有引擎分類存放（共 **29 份** `v3_*` 任務 JSON，全數已實裝並通過驗證）：

- 一般主線：`quests/main/v3_*.json`（18 份：Act 1 實裝 6 份、Act 2 實裝 6 份、Act 3 實裝 2 份、Act 4 實裝 3 份、Act 5 新增並實裝 `v3_act5_lvl100_trials`，全數 18 份主線完畢）
- 支線任務：`quests/side/v3_*.json`（5 份：Act 1 一份、Act 2 兩份、Act 3 一份、Act 4 一份，全數已實裝）
- 史詩跨階段：`quests/epic/v3_*.json`（2 份：`v3_five_relic_resonance` 與 Act 5 `v3_tier2_departure` 皆已全段實裝閉環）
- 世界事件：`quests/event/v3_*.json`（4 份：Act 3 `v3_preserve_field_evidence` ＋ Act 4 `v3_cross_sect_evidence_audit`、`v3_crystal_quarantine_response`、`v3_north_wall_beast_surge` 全數實裝）
- 世界事件定義：`data/event_defs/tier2_crisis.json`（已註冊於 `include/world_event.h` 與 `daemon/event_manager.c`，支援會武前評估至 `defense_outcome` 三檔評價暨 `dump_status` 證物顯示；敘事同步副本：`narrative/events/tier2_crisis.json`）

**實作狀態**：第三卷第一至五幕（Ch. 83–126）對應之 **全部 29 條 `v3_*` 任務**、66 間 Tier 2 LPC 房間＋1 間 Tier 3 初臨點（`/d/wastes/*` 19、`yunjin` 18、`taiqing` 9、`bahuang` 9、`tiangong` 6、`danding` 5、`/d/realm/peach_plateau.c` 1）、50 個新建 `/clone/npc/*.c`（另複用 `mo_beggar`、`under_black_market_broker`）與 38 項新建 `/clone/item/*.c` 道具（另複用 `dao_crystal.c`）皆已實裝完成，並通過 `tests/quests/quest_audit.py`、`test_v3_act1.c`～`test_v3_act5.c` 全數驗證。
