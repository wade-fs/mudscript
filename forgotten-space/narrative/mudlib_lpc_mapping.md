# 《遺忘的世界》Mudlib LPC 機制與專案目錄架構映射 (Mudlib LPC Mapping)

> **所屬專案**：`forgotten-space` 系統規格集  
> **關聯文檔**：[世界觀與 Mudlib 架構設定集](file:///home/wade/src/github/mudscript/forgotten-space/narrative/world_setting.md) ｜ [第一卷大綱【黑石驚蟄】](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume1.md) ｜ [第二卷大綱【金石風雲】](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume2.md) ｜ [第三卷大綱【名山問道】](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume3.md) ｜ [事件與任務鏈總表](file:///home/wade/src/github/mudscript/forgotten-space/narrative/events/README.md)  
> **更新時間**：2026-11-14  

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
├── d/                      # 【03 世界狀態 (World State)】空間階梯地圖與現場網絡 (共 187 間實體房間)
│   ├── village/            # Tier 0：黑石鋪（中央街市、南谷、北崖、東林、西壇、黑石關等 13 間核心房間）
│   ├── city/               # Tier 1：金石府城（四關、外城、南市、中樞、東武、西道、北工、地下暗渠等 67 間房間）
│   ├── counties/           # Tier 1：六大次級縣城（盤木、重石、青河、鎮風、烈礬、濁水，6 縣共 85 間房間與 18 處考場）
│   └── routes/             # Tier 1：12 條縣際官道、水路與地下暗河節點（共 22 間路段房間）
│
├── daemon/                 # 【02 Rules & 03 State】核心常駐守護進程 (System Daemons)
│   ├── world_state_d.c     # 世界動態狀態守護進程 (十二時辰天候、水情、礦脈、商隊、地煞、六縣 30 天演進時鐘)
│   ├── city_d.c            # 金石府城守護進程 (四關稅則、72h 居留法、絕靈法網、證物保管鏈、三印合符與三方會審)
│   ├── travel_d.c          # 縣際長途旅行守護進程 (路段季節封路、重車禁行、精力飲食扣除、時間壓縮與旅途天數累計)
│   ├── phase_d.c           # NPC 三態生命週期守護進程 (十二時辰作息位移、世界事件相位覆寫與離場保護)
│   ├── rumor_d.c           # 茶肆市井流言守護進程 (跨縣事件與物價波動傳聞廣播)
│   ├── event_manager.c     # 全服世界事件調度器 (北崖礦難、大荒煞潮、四階段狀態推進)
│   ├── mysteryd.c          # 史前奇遇與個人級事件守護 (MYSTERY_D，天命覺醒與認知盲區判定)
│   ├── quest_engine_d.c    # 宣告式任務狀態機核心引擎 (QUEST_ENGINE_D，支援 talk, deliver, action, kill, item)
│   └── career_d.c          # 職業導引與技能晉升守護
│
├── quests/                 # 【02 Rules & 04 Narratives】宣告式標準 JSON 任務定義庫 (共 37 條完整任務鏈)
│   ├── career/             # 三大流派職業日常任務鏈（herb_loop, mining_loop, pelt_loop）
│   ├── encounter/          # 史前遺物奇遇與殘圖拼合任務（enc_black_iron, enc_map_fusion 等 6 條）
│   ├── main/               # 第一卷與第二卷五幕主線任務鏈（v1 礦難/煞潮/關城博弈；v2 入城/立籍/六縣/會審/北望 等 21 條）
│   └── side/               # 市井日常與身世專屬機緣任務（lost_axe, village_errands 等 7 條）
│
├── secure/                 # 【02 Rules】特權管理與核心系統模組
│   ├── master.c            # Master Object 系統核心
│   ├── nature_d.c          # 晝夜節氣與跨日推進守護進程
│   ├── map_d.c             # 動態區域地圖繪製守護進程 (支援黑石鋪、金石府城、六大縣城 ASCII 地圖)
│   ├── skill_d.c           # 武學技能與五維資格守護進程 (初級心法、一階三道轉職、六縣 18 考場等效發證與總堂掛單)
│   └── combat_d.c          # 三元戰鬥守護進程 (COMBAT_D，力/法/物 14 式招式、三角生剋、內城絕靈法網反噬與度牒豁免)
│
└── narrative/              # 【04 敘事內容 (Narratives)】小說創作與世界事件關聯索引
    ├── characters/         # 五重視角主角與關鍵配角檔案 (顧玄、林鐵生、燕隼、柳清虛、沈泥等 17 份人物誌)
    ├── chapters/           # 第一卷 (ch0001.md ~ ch0038.md) 與第二卷 (ch0039.md ~ ch0082.md) 全 82 章完稿正文
    ├── events/             # 第一卷 (EV-101~125) 與第二卷 (EV-201~244) 事件記錄簿與 Mudlib 對照表
    ├── docs/               # 需求追溯與交付範圍基線矩陣 (traceability_and_scope_baseline.md)
    ├── volume1.md          # 第一卷【黑石驚蟄】全 38 章宏觀五幕大綱
    ├── volume2.md          # 第二卷【金石風雲】全 44 章宏觀五幕大綱
    ├── character_profiles.md # 核心人物檔案與身世世界觀設定
    ├── novel_outline.md    # 小說大綱與各卷宏觀規劃
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
| **世界狀態協調** | `/daemon/world_state_d.c` | `WORLD_STATE_D` | 維護區域級可變狀態（十二時辰、降雨水谷、礦道坍塌、商隊出入、東林地煞、六縣 30 天演進時鐘） |
| **金石府城治理** | `/daemon/city_d.c` | `CITY_D` | 四關稅則、72 小時兩階段居留法、絕靈法網、通寶信用凍結、五欄證物保管鏈、三印合符與三方會審 |
| **長途旅行引擎** | `/daemon/travel_d.c` | `TRAVEL_D` |  관리 12 條縣際路段通行檢定、重車限制、精力與飲食扣除、時間壓縮與個人旅途天數累計 |
| **NPC 生命週期** | `/daemon/phase_d.c` | `PHASE_D` | 管理核心具名 NPC 的十二時辰作息位移、世界事件相位覆寫與退場保護 |
| **任務狀態機引擎** | `/daemon/quest_engine_d.c` | `QUEST_ENGINE_D` | 統一掃描 `/quests/**/*.json`（37 條任務），處理 `talk`、`deliver`、`action`、`kill`、`item` 事件與冪等發獎 |
| **武學與資格庫** | `/secure/skill_d.c` | `SKILL_D` | 5 大初級心法、一階三道轉職、六縣 18 處地方分舵等效發證 (`grant_county_initiation`) 與總堂掛單 (`register_at_headquarters`) |
| **三元戰鬥守護** | `/secure/combat_d.c` | `COMBAT_D` | 力／法／物 14 式招式、三角生剋（力剋法、法剋物、物剋力）、內城絕靈法網反噬與度牒豁免檢核 |

---

## 三、雙軌開發落地哲學 (Engine & Narrative Co-evolution)

1. **狀態解耦（Decoupled State Synchronization）**：
   * **世界正典 (Canon)**：史前大清洗、三才分流、金石共治盟約，為全服共用基石。
   * **動態世界狀態 (World State)**：黑石礦坑坍塌、商道阻斷、六縣 30 天危機演進（青河秋汛、鎮風煞潮、烈礬走私、濁水沉船、盤木扣車、重石暗傷），由 `WORLD_STATE_D` 與 `CITY_D` 隨伺服器時間與進度驅動。
   * **個人進度保存 (Personal State)**：玩家拜師、地方分舵或府城總堂立籍、NPC 好感、拓印碑文，存於個人存檔。小說主角的專屬奇遇不強迫每位玩家完全複製，但共享相同的底層因果律。
2. **宣告式 JSON 任務架構對應小說事件**：
   * 任務配置完全與代碼邏輯分離，置於 `/quests/` 目錄（涵蓋第一卷與第二卷全 82 章對應之 37 條任務鏈）。
   * 小說中的重大情節（如救出老礦工、黑石關軍政博弈、四關入城、72 小時居留緩衝、三道考場立籍、四縣採辦、西水門搶修、暗渠公證取證、府衙三方會審、四維破境、冬至北望）全數轉化為標準 JSON 任務步驟與房間動作，並由 `tests/quests/quest_audit.py` 與 `MUD_TEST_MODE=1` 自動化回歸測試（2,323 項斷言）100% 驗證。
3. **身世世界驗證分支與多起點等效立籍（World Verification & Multi-Origin Parity）**：
   * 支援基於身世的條件分支（採藥孤兒、打鐵學徒、獵戶之子、破落道童、流浪乞兒），以及府城總堂與六大縣城 18 處分舵的「資格全府等效、組織與設施權限分流」模型，全方位體現真實運轉的修真城鄉世界。
