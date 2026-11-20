# Tier 2 任務 JSON 索引

第三卷任務 JSON 位於專案根目錄 `quests/`，依現有引擎分類存放（共 **25 份** `v3_*` 任務 JSON）：

- 一般主線：`quests/main/v3_*.json`（16 份：含 6 份 Act 1 已實裝主線、6 份 Act 2 已實裝主線 [`v3_taiqing_star_archive`、`v3_bahuang_bloodline_watch`、`v3_tiangong_ancient_mechanism`、`v3_danding_blood_pill_cases`、`v3_five_way_evidence_convergence`、`v3_act2_yunjin_ghost_and_sanyuan`]，以及 4 份 Act 3–5 主線初稿）
- 支線任務：`quests/side/v3_*.json`（3 份：Act 1 `v3_act1_cold_plain_rescue.json` 1 份，與 Act 2 `v3_act2_taiqing_ascension_secret.json`、`v3_act2_bahuang_ghost_gorge.json` 2 份，皆已實裝）
- 史詩跨階段：`quests/epic/v3_*.json`（2 份初稿）
- 世界事件：`quests/event/v3_*.json`（4 份初稿；其中 `v3_cross_sect_evidence_audit.json`、`v3_crystal_quarantine_response.json` 已同步修正第二幕實際房間與 NPC 路徑）
- 世界事件定義：`data/event_defs/tier2_crisis.json`（已註冊於 `include/world_event.h` 與 `daemon/event_manager.c`，含 `evaluate_tier2_crisis()` 與 `on_stage_timeout_tier2_crisis()`；敘事同步副本：`narrative/events/tier2_crisis.json`）

**實作狀態**：第一至二幕（Ch. 83–101）對應之 **15 條 Act 1–2 任務**、41 間 LPC 房間（`/d/wastes/north_road/*`、`/d/yunjin/*`、`/d/sects/*`）、33 個 Act 1–2 新建 `/clone/npc/*.c`（含 `ironback_wolf`、`iron_yak` 2 種妖獸，另複用既有 `mo_beggar`、`under_black_market_broker` 並增補 `mo_san`／`gui_jianchou` 別名）與 16 項新建 `/clone/item/*.c` 道具（另複用 `dao_crystal.c`）已實裝並納入 `test_v3_act1.c`／`test_v3_act2.c` 驗證；第三至五幕之其餘 **10 份任務 JSON** 仍為架構初稿，待後續房間與 NPC 落地。
