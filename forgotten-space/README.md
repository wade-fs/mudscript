# 《遺忘的世界》(THE FORGOTTEN SPACE) - Mudlib

![封面](img/fs.jpeg)

> **書名**：遺忘的世界 (THE FORGOTTEN SPACE)  
> **專案定位**：小說世界觀正典的運行引擎，基於 Go-LPC MudScript 開發的開放世界 Mudlib。  
> **核心設計綱領**：四大架構層級（正典、規則、狀態、敘事）與三級事件同步模型。

---

## 專案目錄結構 (Project Directory Hierarchy)

```
forgotten-space/
├── world/                  # 【01 世界正典 (Canon) 與空間定義】不可變設定、九城圖譜與 Region/Zone/Site JSON
│   ├── lore/               # 世界正典設定錄（nine_cities_canon.md 等）
│   ├── cities/             # 太古九城節點定義 JSON（9 城）
│   ├── dependencies/       # 九城文明依存圖（nine_cities_graph.json）
│   ├── topology/           # 宏觀地理拓撲（macro_topology.json）
│   ├── regions/            # 區域定義 JSON（factions / crisis_deck / 資源與物價）
│   ├── zones/              # 分區定義 JSON
│   ├── sites/              # 遺跡／關鍵場域定義 JSON
│   ├── routes/             # 跨區交通路線定義 JSON
│   └── specifications/     # 空間資料模型規格（spatial_schema.md）
│
├── std/                    # 【02 世界規則 (Rules)】標準物件類別庫 (OOP Core)
│   ├── char/               # 玩家與 NPC 基礎行為
│   ├── room/               # 空間房間、遺跡機關房基底
│   └── object/             # 武器、防具、太古遺留物基底
│
├── daemon/                 # 【02 Rules & 03 State】核心常駐守護進程（13 個核心 daemon + skill/）
│   ├── skill/              # 法、力、物技能招式與生剋判定 (SKILL_D)
│   ├── quest_engine_d.c    # 宣告式任務與事件推進引擎 (QUEST_ENGINE_D)
│   ├── event_manager.c     # 卷幕級世界事件與貢獻結算 (EVENT_MANAGER_D)
│   ├── phase_d.c           # 時辰節律、NPC 排程與區域階段 (PHASE_D)
│   ├── region_d.c          # Region 靜態資料與危機／物價惰性求值 (REGION_D)
│   ├── route_d.c           # 路線行旅時間與資訊傳播延遲 (ROUTE_D)
│   ├── tier3_d.c           # 第四卷洞天時差、阻尼與 K/U 雙軌法則 (TIER3_D)
│   ├── city_d.c            # 府城秩序、居留通牒與物證驗真 (CITY_D)
│   ├── rumor_d.c           # 六維交叉查證傳聞與分層語氣 (RUMOR_D)
│   └── world_state_d.c     # 區域級可變動態狀態協調 (WORLD_STATE_D)
│
├── d/                      # 【03 世界狀態 (World State)】空間階梯地圖網絡（305 間實裝房間）
│   ├── village/            # Tier 0：黑石鋪（22 間房）
│   ├── city/               # Tier 1：金石府城九大分區與外城生活區（75 間房）
│   ├── counties/           # Tier 1：六大次級縣城（盤木/重石/青河/鎮風/烈礬/濁水共 91 間房）
│   ├── routes/             # Tier 1：縣際官道、水路與地下暗河節點（22 間房）
│   ├── yunjin/             # Tier 2：雲津仙集暨問道天台（21 間房）
│   ├── sects/              # Tier 2：三山四脈宗門祖庭（太清/八荒/天工/丹鼎共 36 間房）
│   ├── wastes/             # Tier 2：北境雪原官道與北荒裂谷／方舟陣基（20 間房）
│   ├── realm/              # Tier 3：桃花源洞天（灰燼石堡/太虛/萬物/戰祖垂直切片共 18 間房）
│   └── secret/             # Tier 4：禁忌古道、歸墟古淵（規劃預留）
│
├── quests/                 # 【宣告式任務庫】117 個任務 JSON（main / side / event / epic / loop / tutorial / trial）
│
├── article/                # 【04 敘事正文 (Novel)】四卷 170 章成書正文、卷導讀與附錄（SUMMARY.md）
│   ├── 01_volume1/         # 第一卷（Ch.1–38）
│   ├── 02_volume2/         # 第二卷（Ch.39–82）
│   ├── 03_volume3/         # 第三卷（Ch.83–126）
│   ├── 04_volume4/         # 第四卷（Ch.127–170）
│   └── appendix/           # 人物誌、輿圖集、大事紀年表、世俗見聞錄、古法辭典
│
├── narrative/              # 【敘事設計文件】事件規劃簿、區域設計圖譜與 Mudlib 映射總表
│   ├── events/             # 各卷事件規劃簿（EV201~EV422）
│   ├── docs/               # 世界拓撲圖說、NPC 花名冊與寫作規範
│   └── mudlib_lpc_mapping.md
│
├── docs/                   # 正典問題追蹤、變更日誌與宏觀擴建規格
├── data/                   # 雙向同步矩陣（canon_sync_matrix.json）、事件定義與運行存檔
├── tests/                  # LPC 核心整合測試與 Python 稽核腳本（tests/quests/）
├── cmds/                   # 玩家與管理員指令庫
├── include/                # 全域標頭檔 (globals.h, ansi.h, config.h)
├── clone/                  # 具體實例化物件 (NPC、武器、防具、物證、遺物)
├── item/                   # 基礎常規物品定義
├── secure/                 # 系統安全性與權限驗證 (valid.c, master.c)
└── img/                    # 概念視覺與封面 (fs.jpeg)
```

---

## 快速啟動與驗證 (Quick Start & Verification)

在專案根目錄下使用 MudScript 驅動運行本 Mudlib：

```bash
# 以本 mudlib 啟動伺服器
./bin/fsmud -mudlib forgotten-space -master master.c

# 或指定連接訊號中繼
./bin/fsmud -mudlib forgotten-space -master master.c -hub none
```

雙軌同步與任務完整性稽核：

```bash
python3 tests/quests/novel_mud_sync_audit.py
python3 tests/quests/quest_audit.py .
python3 tests/quests/world_liveness_audit.py
```

登入後預設進入 **Tier 0 新手聚落：黑石鋪（`/d/village/square.c`）**。
