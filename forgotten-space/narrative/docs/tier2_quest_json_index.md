# Tier 2 任務 JSON 索引

第三卷任務 JSON 位於專案根目錄 `quests/`，依現有引擎分類存放：

- 一般主線：`quests/main/v3_*.json`（15 份：其中 6 份為 Act 1 已實裝主線，含 `v3_northbound_and_yunjin_arrival`、`v3_yuntu_market_charter` 與 4 條 `v3_act1_*` 宗門試煉）
- 支線任務：`quests/side/v3_*.json`（1 份：`v3_act1_cold_plain_rescue.json`，Act 1 已實裝）
- 史詩跨階段：`quests/epic/v3_*.json`（2 份初稿）
- 世界事件：`quests/event/v3_*.json`（4 份初稿）
- 世界事件定義：`data/event_defs/tier2_crisis.json`（已註冊於 `include/world_event.h` 與 `daemon/event_manager.c`；敘事同步副本：`narrative/events/tier2_crisis.json`）

**實作狀態**：第一幕（Ch. 83–90）對應之 **7 條 Act 1 任務**、20 間 LPC 房間（`/d/wastes/north_road/*`、`/d/yunjin/*`、`/d/sects/*`）、19 名 NPC（`/clone/npc/*.c`）與 8 項道具（`/clone/item/*.c`）已實裝並通過 `quest_audit.py` 與 `test_v3_act1.c` 測試；第二至五幕之其餘 **15 份任務 JSON** 仍為架構初稿，待後續房間與 NPC 落地。
