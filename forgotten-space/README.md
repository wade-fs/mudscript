# 《遺忘的世界》(THE FORGOTTEN SPACE) - Mudlib

![封面](img/fs.jpeg)

> **書名**：遺忘的世界 (THE FORGOTTEN SPACE)  
> **專案定位**：小說世界觀正典的運行引擎，基於 Go-LPC MudScript 開發的開放世界 Mudlib。  
> **核心設計綱領**：四大架構層級（正典、規則、狀態、敘事）與三級事件同步模型。

---

## 專案目錄結構 (Project Directory Hierarchy)

```
forgotten-space/
├── world/                  # 【01 世界正典 (Canon)】不可變歷史、地理公理與大清洗真相
│   ├── history/            # 歷史紀元、重大正典事件
│   ├── geography/          # 宏觀地域、山海邊界、通行阻隔
│   ├── factions/           # 三大道統源流、宗門恩怨譜
│   └── lore/               # 史前大清洗、古代遺跡密檔、失落技術
│
├── std/                    # 【02 世界規則 (Rules)】標準物件類別庫 (OOP Core)
│   ├── char/               # 玩家與 NPC 基礎行為
│   ├── room/               # 空間房間、遺跡機關房基底
│   └── object/             # 武器、防具、太古遺留物基底
│
├── daemon/                 # 【02 Rules & 03 State】核心常駐守護進程
│   ├── skill/              # 法、力、物技能招式與生剋判定 (SKILL_D)
│   ├── questd.c            # 主線進階與考核任務 (QUEST_D)
│   ├── mysteryd.c          # 史前解謎與天候古陣響應 (MYSTERY_D)
│   ├── career_d.c          # 生計委託與三大道統閉合任務鏈 (CAREER_D)
│   └── world_state_d.c     # 區域級可變動態狀態協調 (WORLD_STATE_D)
│
├── d/                      # 【03 世界狀態 (World State)】空間階梯地圖網絡
│   ├── village/            # Tier 0：黑石鋪／斷崖集（五方立體微生態）
│   ├── city/               # Tier 1：大都府城與市井三大世俗勢力
│   ├── mountain/           # Tier 2：宗門祖庭與名山靈川
│   ├── realm/              # Tier 3：異界洞天、桃花源單向門戶
│   └── secret/             # Tier 4：禁忌古道、失落遺跡深層
│
├── narrative/              # 【04 敘事內容 (Narratives)】小說創作與世界事件索引
│   ├── characters/         # 小說人物小傳與 MUD 角色關聯
│   ├── events/             # 小說核心情節及其對世界狀態之影響
│   └── chapters/           # 各章節場景、登場人物與伏筆索引
│
├── cmds/                   # 玩家與管理員指令庫
├── include/                # 全域標頭檔 (globals.h, ansi.h, config.h)
├── clone/                  # 具體實例化物件 (武器、防具、遺物、NPC)
├── data/                   # 運行時玩家存檔與動態資料
├── secure/                 # 系統安全性與權限驗證 (valid.c, master.c)
└── img/                    # 概念視覺與封面 (fs.jpeg)
```

---

## 快速啟動 (Quick Start)

在專案根目錄下使用 MudScript 驅動運行本 Mudlib：

```bash
# 以本 mudlib 啟動伺服器
./bin/fsmud -mudlib forgotten-space -master master.c

# 或指定連接訊號中繼
./bin/fsmud -mudlib forgotten-space -master master.c -hub none
```

登入後預設進入 **Tier 0 新手聚落：黑石鋪（`/d/village/square.c`）**。
