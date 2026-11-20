# Tier 2 任務 JSON 索引

第三卷任務 JSON 位於專案根目錄 `quests/`，依現有引擎分類存放（共 **26 份** `v3_*` 任務 JSON）：

- 一般主線：`quests/main/v3_*.json`（16 份：含 Act 1 實裝 6 份、Act 2 實裝 6 份、Act 3 實裝 `v3_north_wastes_expedition` 與 `v3_ark_excavation_evidence` 2 份，以及 2 份 Act 4 主線初稿 `v3_evidence_chain_hearing`、`v3_postwar_reform_and_restitution`）
- 支線任務：`quests/side/v3_*.json`（4 份：Act 1 `v3_act1_cold_plain_rescue`、Act 2 兩份、Act 3 `v3_act3_war_god_tomb`，皆已實裝）
- 史詩跨階段：`quests/epic/v3_*.json`（2 份：`v3_five_relic_resonance` 已於 Act 3 全面實裝閉環；`v3_tier2_departure` 為五幕初稿）
- 世界事件：`quests/event/v3_*.json`（4 份：`v3_preserve_field_evidence` 已於 Act 3 實裝；其餘 3 份為四幕事件初稿）
- 世界事件定義：`data/event_defs/tier2_crisis.json`（已註冊於 `include/world_event.h` 與 `daemon/event_manager.c`，支援 `T-2 → T-1 → T0` 評估暨 `dump_status` 證物顯示；敘事同步副本：`narrative/events/tier2_crisis.json`）

**實作狀態**：第一至三幕（Ch. 83–111）對應之 **20 條 Act 1–3 任務**、57 間 Tier 2 LPC 房間（`/d/wastes/north_road/*`、`wastes` 深處、`yunjin`、`taiqing`、`bahuang`、`tiangong`、`danding`）、41 個 Act 1–3 新建 `/clone/npc/*.c`（含荒獸與敵對頭目，另複用 `mo_beggar`／`under_black_market_broker`）與 25 項新建 `/clone/item/*.c` 道具（另複用 `dao_crystal.c`）已實裝並納入 `test_v3_act1.c`／`test_v3_act2.c`／`test_v3_act3.c` 驗證；第四至五幕之其餘 **6 份任務 JSON** 仍為架構初稿，待後續會武與終局房間落地。
