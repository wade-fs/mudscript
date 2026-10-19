# 《遺忘的世界》Mudlib LPC 機制與專案目錄架構映射 (Mudlib LPC Mapping)

> **所屬專案**：`forgotten-space` 系統規格集  
> **關聯文檔**：[世界觀與 Mudlib 架構設定集](file:///home/wade/src/github/mudscript/forgotten-space/world_setting.md) ｜ [第一卷大綱【黑石驚蟄】](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume1.md)  
> **更新時間**：2026-10-19  

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
│   ├── living.c            # 生物實體基類 (氣血、戰鬥心跳、狀態維護)
│   ├── room.c              # 常規房間基類 (出入口、物件容納、動詞註冊)
│   ├── item.c              # 常規道具與物品基類
│   └── room/ruin.c         # 史前遺跡機關房基類 (RUIN_ROOM_OB，支援 study, tuoyin, 盲區檢定)
│
├── d/                      # 【03 世界狀態 (World State)】空間階梯地圖與現場網絡
│   ├── village/            # Tier 0：黑石鋪（中央街市、南谷、北崖、東林、西壇等10間核心房間）
│   └── city/               # Tier 1：金石都城（城防武館、官辦道壇、百工行會、黑市暗渠，規劃中）
│
├── daemon/                 # 【02 Rules & 03 State】核心常駐守護進程 (System Daemons)
│   ├── world_state_d.c     # 世界動態狀態守護進程 (十二時辰天候、水情、礦脈、商隊、地煞)
│   ├── mysteryd.c          # 史前奇遇與個人級事件守護 (MYSTERY_D，天命覺醒與認知盲區判定)
│   ├── quest_engine_d.c    # 宣告式任務狀態機核心引擎 (QUEST_ENGINE_D，支援 talk, deliver, action, kill)
│   ├── career_d.c          # 職業導引與技能晉升守護
│   └── combat_d.c          # 戰鬥守護進程 (COMBAT_D，三角生剋公式、氣血狂潮打斷、機關佈陣，近期規劃)
│
├── quests/                 # 【02 Rules & 04 Narratives】宣告式標準 JSON 任務定義庫
│   ├── career/             # 三大流派職業入門任務鏈（herb_loop, mining_loop, pelt_loop 等）
│   ├── main/               # 主線進階與世界大事件任務
│   └── side/               # 市井日常與各身世專屬機緣任務
│
├── secure/                 # 【02 Rules】特權管理與核心系統模組
│   ├── master.c            # Master Object 系統核心
│   └── skill_d.c           # 武學技能守護進程 (初級調息心法、升級經驗、熟練度管理)
│
└── narrative/              # 【04 敘事內容 (Narratives)】小說創作與世界事件關聯索引
    ├── characters/         # 五重視角主角與關鍵配角檔案 (顧玄、林鐵生、燕隼、柳清虛、沈泥)
    ├── chapters/           # 第一卷小說章節正文 (ch0001.md ~ ch0032.md，持續推進中)
    ├── volume1.md          # 第一卷【黑石驚蟄】全 38 章宏觀五幕大綱
    ├── character_profiles.md # 核心人物檔案與身世世界觀設定
    ├── novel_outline.md    # 小說大綱與各卷宏觀規劃
    └── mudlib_lpc_mapping.md # 本文檔：LPC 架構映射
```

---

## 二、LPC 核心類別與守護程序映射表 (LPC Class Mapping)

| 系統模組 | Mudlib 目錄路徑 | LPC 核心類別 / 物件 | 職責與機制說明 |
| :--- | :--- | :--- | :--- |
| **玩家主體** | `/std/user.c` | `inherit USER;` | 定義先天六維 (`str/con/int/spi/dex/per`)、三柱 (`kee/sen/sp`)、成長倍率、飽渴度與終極天命 (`fate`) |
| **生物基底** | `/std/living.c` | `inherit LIVING;` | 具有生命力、三元動態池、戰鬥回合與心跳機制 |
| **常規房間** | `/std/room.c` | `inherit ROOM;` | 空間出入口、環境光暗、短長描述、安全區與動詞註冊 |
| **遺跡機關房** | `/std/room/ruin.c` | `inherit RUIN_ROOM_OB;` | 支援環境動詞 (`search`, `study`, `tuoyin`)、太古銘文與盲區認知檢定 |
| **史前遺物殘片** | `/clone/relic/` | `inherit ITEM;` | 具有歷史殘留氣息、遠古文字銘刻、拓印與碎片拼合功能 (`ancient_black_iron.c`, `tianmen_token.c` 等) |
| **史前奇遇守護** | `/daemon/mysteryd.c` | `MYSTERY_D` | 個人級事件紀錄 (`personal_event/*`)、天命覺醒 (`fate +1`)、認知盲區突破判定 |
| **世界狀態協調** | `/daemon/world_state_d.c` | `WORLD_STATE_D` | 維護區域級可變狀態（十二時辰、降雨水谷、礦道坍塌、商隊出入、東林地煞） |
| **任務狀態機引擎** | `/daemon/quest_engine_d.c` | `QUEST_ENGINE_D` | 統一掃描 `/quests/*.json`，處理 `talk`、`deliver`、`action`、`kill` 事件，支援信物防呆補發 |
| **武學技能庫** | `/secure/skill_d.c` | `SKILL_D` | 5 大初級入門心法 (`dream_sleep`, `still_heart` 等)、熟練度成長與技能升級公式 |
| **戰鬥守護進程** | `/daemon/combat_d.c` | `COMBAT_D` | 三角生剋（力剋法、法剋物、物克力）、氣血狂潮近身打斷、機關陷阱消耗（近期規劃實裝） |

---

## 三、雙軌開發落地哲學 (Engine & Narrative Co-evolution)

1. **狀態解耦（Decoupled State Synchronization）**：
   * **世界正典 (Canon)**：史前大清洗、三才分流，為全服共用基石。
   * **動態世界狀態 (World State)**：黑石礦坑坍塌、商道阻斷、虎跳峽棧道崩塌，由 `WORLD_STATE_D` 隨伺服器時間與進度驅動。
   * **個人進度保存 (Personal State)**：玩家拜師、NPC 好感、拓印碑文，存於個人存檔。小說主角的專屬奇遇不強迫每位玩家完全複製，但共享相同的底層因果律。
2. **宣告式 JSON 任務架構對應小說事件**：
   * 任務配置完全與代碼邏輯分離，置於 `/quests/` 目錄。
   * 小說中的重大情節（如救出老礦工、採集淬火液、追查走私線索）直接轉化為標準 JSON 任務步驟，實現「小說即設定，設定即代碼」。
3. **身世世界驗證分支（World Verification Branching）**：
   * 未來 `QUEST_ENGINE_D` 將進一步支援基於身世的條件分支：採藥孤兒優先解鎖草藥生態線索，打鐵學徒優先解鎖材料應力線索，獵戶之子優先解鎖獸跡動態，破落道童優先解鎖符文天象，流浪乞兒優先解鎖市井利益情報，全方位體現五種「理解世界的方式」。
