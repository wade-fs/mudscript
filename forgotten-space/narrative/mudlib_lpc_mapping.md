# 《遺忘的世界》Mudlib LPC 機制與專案目錄架構映射 (Mudlib LPC Mapping)

> **所屬專案**：`forgotten-space` 系統規格集  
> **關聯文檔**：[小說典藏整理本全章目錄](../article/SUMMARY.md) ｜ [事件與任務鏈總表](events/README.md) ｜ [天下輿圖](../article/appendix/atlas.md) ｜ [群像人物誌](../article/appendix/characters.md) ｜ [四卷大事紀年表](../article/appendix/chronicle.md)  
> **更新時間**：2026-11-22（同步 Phase 1–4 世界真實化擴建、World Liveness 2.0 與第三卷全五幕 Ch. 83–126 落地）  

---

## 一、專案目錄架構總覽 (Project Directory Blueprint)

本目錄樹完美對應「四層架構模型（正典、規則、狀態、敘事）」，作為 `./mudscript/forgotten-space/` 實際檔案佈局的標準規範：

```
mudscript/forgotten-space/
├── world/                  # 【01 世界正典 (Canon)】世界定義與不可變靜態資料 (Cosmology & Lore)
│   ├── history/            # 歷史紀元、大清洗事件
│   ├── geography/          # 地域境界、官道網絡、通行阻隔條件
│   ├── factions/           # 三大道統、宗門淵源、陣營關係譜
│   └── lore/               # 史前大清洗真相、古遺跡密檔、失落知識
│
├── std/                    # 【02 世界規則 (Rules)】標準可繼承物件 (OOP Core)
│   ├── user.c              # 玩家核心邏輯 (六維屬性、三柱池、成長親和、指令處理)
│   ├── living.c            # 生物實體基類 (氣血、五維資格與組織權限、戰鬥心跳、狀態維護)
│   ├── room.c              # 常規房間基類 (出入口、物件容納、動詞註冊)
│   ├── county_room.c       # Tier 1 次級縣城房間基類 (對接 30 天自主演進 Stage 1~4 與地方物價)
│   ├── route_room.c        # 縣際官道／水路／暗河節點基類 (對接 ROUTE_SEGMENTS 與壓縮旅行)
│   ├── item.c              # 常規道具與物品基類
│   └── room/ruin.c         # 史前遺跡機關房基類 (RUIN_ROOM_OB，支援 study, tuoyin, 盲區檢定)
│
├── d/                      # 【03 世界狀態 (World State)】空間階梯地圖與現場網絡 (共 305 間實體房間：Tier 0–1 210 間 ＋ Tier 2 77 間 ＋ Tier 3 18 間)
│   ├── village/            # Tier 0：黑石鋪（街市、南谷、北崖、東林、西壇與雜糧鋪/蒙館/土地祠/洗衣灘/採石場等 22 間房間）
│   ├── city/               # Tier 1：金石府城（四關、外城矮巷/義棚/魚市/碼頭、南市酒肆/染坊、中樞茶肆、東武、西道、北工、地下暗渠等 75 間房間）
│   ├── counties/           # Tier 1：六大次級縣城（盤木 15、重石 15、青河 15、鎮風 15、烈礬 15、濁水 16：6 縣共 91 間房間含生活支翼與 18 處考場；鎮風關北塞接通 Tier 2）
│   ├── routes/             # Tier 1：12 條縣際官道、水路與地下暗河節點（共 22 間路段房間）
│   ├── wastes/             # Tier 2 Act 1 & 3：北境官道 `north_road/`（3 房）暨北荒裂谷、凍土牧戶棚、戰神遺塚、方舟北方陣基（17 房），共 20 間房間
│   ├── yunjin/             # Tier 2 Act 1–4：雲津仙集暨問道天台（廣場、公所、票號、萬寶閣、西街回收廠、石牌坊隔離線、問道天台、冰河木筏碼頭、廟會茶市、苦力棚等共 21 間房間）
│   ├── sects/              # Tier 2 Act 1–5：三山四脈場域（太清 11 [含封存觀測室暨主傳送室、外門抄經/通鋪]、八荒 10、天工 8、丹鼎 7 共 36 間房間）
│   └── realm/              # Tier 3 洞天篇：桃花源碎石高原 (`peach_plateau.c`)、灰燼邊緣 (`edge/` 6 房，含 `beacon_relay.c`)、太虛 (`taixu/` 3 房)、戰祖 (`zhanzu/` 3 房)、萬物 (`wanwu/` 5 房)，共 18 間房間
│
├── daemon/                 # 【02 Rules & 03 State】核心常駐守護進程 (System Daemons)
│   ├── world_state_d.c     # 世界動態狀態守護進程 (十二時辰天候、六縣 30 天時鐘、五大因果經濟事件、區域庫存 `market_stocks` 與貨盤交易)
│   ├── city_d.c            # 金石府城守護進程 (四關稅則、72h 居留法、社會階層 `query_social_tier()`、絕靈法網、證物保管鏈、三印合符與三方會審)
│   ├── travel_d.c          # 縣際長途旅行守護進程 (路段季節封路、重車禁行、精力飲食扣除、時間壓縮與旅途天數累計)
│   ├── phase_d.c           # NPC 三態生命週期守護進程 (23 名作息排程角色、事件相位覆寫與 6 大樞紐 NPC-to-NPC 互動劇本)
│   ├── rumor_d.c           # 市井流言守護進程 (分層語氣 `query_tiered_folk_rumor()`、日常／經濟因果流言與六維交叉口徑 `query_cross_check_rumors()`)
│   ├── event_manager.c     # 全服世界事件調度器 (beast_surge、military_crisis、tier2_crisis 與已註冊之 tier3_calibration)
│   ├── mysteryd.c          # 史前奇遇與個人級事件守護 (MYSTERY_D，天命覺醒與認知盲區判定)
│   ├── quest_engine_d.c    # 宣告式任務狀態機核心引擎 (QUEST_ENGINE_D，支援 talk, deliver, action, kill, item)
│   └── career_d.c          # 職業導引與技能晉升守護
│
├── quests/                 # 【02 Rules & 04 Narratives】宣告式標準 JSON 任務定義庫 (共 117 份 JSON：main 40 / side 38 / event 19 / career 7 / encounter 6 / epic 4 / loop 3)
│   ├── career/             # 三大流派職業日常任務鏈（7 份）
│   ├── loop/               # 採藥、採礦、狩獵循環任務（herb_loop, mining_loop, pelt_loop 共 3 份）
│   ├── encounter/          # 史前遺物奇遇與殘圖拼合任務（enc_black_iron, enc_map_fusion 等 6 份）
│   ├── main/               # 一至四卷主線任務鏈（共 40 份，含 Tier 2 與 Vol.4 全數已實裝主線）
│   ├── side/               # 日常支線與見證支線（共 38 份：Phase 1–3 新增之 24 條 `side_*.json` ＋ 2 條狩獵 ＋ 5 條 Vol.3 ＋ 7 條 Vol.4 實地支線）
│   ├── event/              # 世界危機事件連動任務（19 份，含 Vol.4 Act 3–4 校準戰線 6 份）
│   └── epic/               # 跨卷大型史詩任務鏈（4 份，含 Vol.4 雙向微光信標與歸墟門縫史詩鏈）
│
├── clone/                  # 【03 State】實體化角色與道具複製物（含 `/clone/npc/folk/` 30 名庶民與 `trade_cargo.c` / `temp_residency_pass.c`）
│   ├── npc/                # 含第三卷第一至五幕 50 個新建 `/clone/npc/*.c`（含周師叔、三掌門、四首徒、私盟大執事、5 種二階荒獸／骨龍王／機關獸，另複用 `mo_beggar`、`under_black_market_broker`）
│   └── item/               # 含第三卷第一至五幕 38 項新實裝道具與證物（另復用 `dao_crystal.c`）
│
├── secure/                 # 【02 Rules】特權管理與核心系統模組
│   ├── master.c            # Master Object 系統核心
│   ├── nature_d.c          # 晝夜節氣與跨日推進守護進程
│   ├── map_d.c             # 動態區域地圖繪製守護進程 (支援黑石鋪、金石府城、六大縣城 ASCII 地圖)
│   ├── skill_d.c           # 武學技能與五維資格守護進程 (初級心法、一階三道轉職、六縣 18 考場等效發證與總堂掛單)
│   └── combat_d.c          # 三元戰鬥守護進程 (COMBAT_D，力/法/物 14 式招式、三角生剋、內城絕靈法網反噬與度牒豁免)
│
├── article/                # 【04 敘事正文 (Articles)】小說正文典藏整理本（01_volume1~04_volume4 共 170 章完稿正文與五篇附錄）
│
└── narrative/              # 【04 敘事正典與規格智庫 (Narrative Specs)】MUD 代碼與小說雙向映射規格
    ├── events/             # 第一卷 (EV-101~125)、第二卷 (EV-201~244)、第三卷 (EV301~EV327／tier2_crisis.json) 與第四卷規劃 (EV401~EV422)
    ├── docs/               # Tier 0~3 空間地圖拓撲網絡 (docs/maps/)、NPC 名冊與任務網絡規格
    └── mudlib_lpc_mapping.md # 本文檔：LPC 架構映射
```

---

## 二、LPC 核心類別與守護程序映射表 (LPC Class Mapping)

| 系統模組 | Mudlib 目錄路徑 | LPC 核心類別 / 物件 | 職責與機制說明 |
| :--- | :--- | :--- | :--- |
| **玩家主體** | `/std/user.c` | `inherit USER;` | 定義先天六維 (`str/con/int/spi/dex/per`)、三柱 (`kee/sen/sp`)、成長倍率、飽渴度與終極天命 (`fate`) |
| **生物基底** | `/std/living.c` | `inherit LIVING;` | 生命力、三元動態池、五維能力分離 (`path/skills/qualifications/affiliation/access`)、戰鬥回合與心跳 |
| **常規房間** | `/std/room.c` | `inherit ROOM;` | 空間出入口、環境光暗、短長描述、安全區與動詞註冊 |
| **縣城房間** | `/std/county_room.c` | `inherit COUNTY_ROOM;` | 對接 `WORLD_STATE_D` 30 天自主演進時鐘（Stage 1~4 動態描述切換）與地方專材物價指數 |
| **官道節點** | `/std/route_room.c` | `inherit ROUTE_ROOM;` | 對接 `CITY_D` 12 條標準路段與 `TRAVEL_D` 季節封路、重車禁行、精力飲食消耗與時間壓縮步進 |
| **遺跡機關房** | `/std/room/ruin.c` | `inherit RUIN_ROOM_OB;` | 支援環境動詞 (`search`, `study`, `tuoyin`)、太古銘文與盲區認知檢定 |
| **史前遺物殘片** | `/clone/relic/` | `inherit ITEM;` | 具有歷史殘留氣息、遠古文字銘刻、拓印與碎片拼合功能 (`ancient_black_iron.c`, `tianmen_token.c` 等) |
| **史前奇遇守護** | `/daemon/mysteryd.c` | `MYSTERY_D` | 個人級事件紀錄 (`personal_event/*`)、天命覺醒 (`fate +1`)、認知盲區突破判定 |
| **世界狀態協調** | `/daemon/world_state_d.c` | `WORLD_STATE_D` | 維護十二時辰、降雨礦塌、六縣 30 天時鐘、五大經濟因果事件、區域庫存 `market_stocks`、`economic_batch_tick()` 與特產貨盤交易 |
| **金石府城治理** | `/daemon/city_d.c` | `CITY_D` | 四關稅則、72 小時兩階段居留法、社會階層判定 `query_social_tier()`、絕靈法網、通寶信用凍結、五欄證物保管鏈與三方會審 |
| **長途旅行引擎** | `/daemon/travel_d.c` | `TRAVEL_D` | 管理 12 條縣際路段通行檢定、重車限制、精力與飲食扣除、時間壓縮與個人旅途天數累計 |
| **NPC 生命週期** | `/daemon/phase_d.c` | `PHASE_D` | 管理 23 名核心與庶民 NPC 之十二時辰作息位移、事件相位覆寫，以及 6 大樞紐 NPC-to-NPC 多節拍互動劇本 (`observe`) |
| **市井傳聞引擎** | `/daemon/rumor_d.c` | `RUMOR_D` | 產出分層生活語氣 (`query_tiered_folk_rumor()`)、日常／因果經濟流言、傳聞失真與六維交叉查證 (`query_cross_check_rumors()`) |
| **任務狀態機引擎** | `/daemon/quest_engine_d.c` | `QUEST_ENGINE_D` | 統一掃描 `/quests/**/*.json`（共 117 份，含 Vol.1–4 全線任務鏈與 24 條生活支線），處理 `talk`、`deliver`、`action`、`kill`、`item` 事件與冪等發獎 |
| **武學與資格庫** | `/secure/skill_d.c` | `SKILL_D` | 5 大初級心法、一階三道轉職、六縣 18 處地方分舵等效發證 (`grant_county_initiation`) 與總堂掛單 (`register_at_headquarters`) |
| **三元戰鬥守護** | `/secure/combat_d.c` | `COMBAT_D` | 力／法／物 14 式招式、三角生剋（力剋法、法剋物、物剋力）、內城絕靈法網反噬與度牒豁免檢核 |

---

## 三、雙軌開發落地哲學 (Engine & Narrative Co-evolution)

1. **狀態解耦（Decoupled State Synchronization）**：
   * **世界正典 (Canon)**：史前大清洗、三才分流、金石共治盟約，為全服共用基石。
   * **動態世界狀態 (World State)**：黑石礦坑坍塌、商道阻斷、六縣 30 天危機演進（青河秋汛、鎮風煞潮、烈礬走私、濁水沉船、盤木扣車、重石暗傷），由 `WORLD_STATE_D` 與 `CITY_D` 隨伺服器時間與進度驅動。
   * **個人進度保存 (Personal State)**：玩家拜師、地方分舵或府城總堂立籍、NPC 好感、拓印碑文，存於個人存檔。小說主角的專屬奇遇不強迫每位玩家完全複製，但共享相同的底層因果律。
2. **宣告式 JSON 任務架構對應小說事件**：
   * 任務配置完全與代碼邏輯分離，置於 `/quests/` 目錄（共 117 份 JSON：涵蓋第一至三卷任務鏈、第四卷 Act 1–5 全部 26 份主支線暨史詩鏈與 Phase 1–3 新增之 24 條生活支線）。
   * 小說中的重大情節已轉化為標準 JSON 任務步驟與房間動作；全服目前實裝 **305 間實體房間**（305/305 通過 `world_liveness_audit.py` 五感與互動覆蓋）、**30 名庶民生活 NPC**（`/clone/npc/folk/`）、**23 名排程 NPC 與 6 大樞紐互動劇本**（`PHASE_D`），並通過 `quest_audit.py`、`novel_mud_sync_audit.py`、`world_liveness_audit.py` 與 `make test` 全數自動化驗證。詳見 [living_world_folk_and_side_roster.md](docs/living_world_folk_and_side_roster.md)。
3. **身世世界驗證分支與多起點等效立籍（World Verification & Multi-Origin Parity）**：
   * 支援基於身世的條件分支（採藥孤兒、打鐵學徒、獵戶之子、破落道童、流浪乞兒），以及府城總堂與六大縣城 18 處分舵的「資格全府等效、組織與設施權限分流」模型，全方位體現真實運轉的修真城鄉世界。
