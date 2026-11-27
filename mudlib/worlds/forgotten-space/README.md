# 《遺忘的世界》(THE FORGOTTEN SPACE) - Mudlib

![封面](img/fs.jpeg)

> **書名**：遺忘的世界 (THE FORGOTTEN SPACE)  
> **專案定位**：小說世界觀正典的運行引擎，基於 Go-LPC MudScript Overlay 架構開發的獨立世界 Mudlib（掛載於 `mudlib/common/` 共用核心之上）。  
> **核心設計綱領**：四大架構層級（正典、規則、狀態、敘事）與三級事件同步模型。

---

## 專案目錄結構 (Project Directory Hierarchy)

```
mudlib/worlds/forgotten-space/
├── manifest.json           # 世界註冊清單（world_id / mudlib_id / start_room / exclude_cmds / custom_fields）
├── schema/                 # 世界體系 Schema JSON（三維道統 / 大荒通寶 / 屬性公式）
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
├── std/                    # 【02 世界規則 (Rules)】世界覆寫基底類別庫
├── daemon/                 # 【02 Rules & 03 State】核心常駐守護進程（world_init_d.c + 世界專屬 daemon）
├── d/                      # 【03 世界狀態 (World State)】空間階梯地圖網絡（305 間實裝房間）
├── quests/                 # 【宣告式任務庫】117 個任務 JSON（main / side / event / epic / loop / tutorial / trial）
├── chapters/               # 【04 敘事正文 (Novel)】四卷 170 章成書正文、卷導讀、附錄與圖庫（SUMMARY.md）
├── docs/                   # 正典問題追蹤、變更日誌與宏觀擴建規格
├── data/                   # 雙向同步矩陣（canon_sync_matrix.json）、事件定義與運行存檔
├── tests/                  # LPC 核心整合測試與 Python 稽核腳本（tests/quests/）
├── cmds/                   # 世界專屬玩家與管理員指令庫
├── include/                # 全域標頭檔 (globals.h, ansi.h, config.h)
├── clone/                  # 具體實例化物件 (NPC、武器、防具、物證、遺物)
├── item/                   # 基礎常規物品定義
├── secure/                 # 系統安全性與權限驗證 (valid.c 等)
└── img/                    # 概念視覺與封面 (fs.jpeg)
```

---

## 快速啟動與驗證 (Quick Start & Verification)

在專案根目錄下使用 MudScript Overlay 驅動運行本世界：

```bash
# 編譯引擎
go build -o bin/mudscript ./cmd/fsmud

# 以 Overlay 模式啟動伺服器
./bin/mudscript -common mudlib/common -mudlib mudlib/worlds/forgotten-space -master master.c --hub none

# 執行全套 LPC 自動化測試
MUD_TEST_MODE=1 ./bin/mudscript -common mudlib/common -mudlib mudlib/worlds/forgotten-space -master master.c --hub none
```

雙軌同步、世界驗證與任務完整性稽核：

```bash
python3 mudlib/tools/validate_world.py forgotten-space
python3 mudlib/tools/audit_schema_usage.py forgotten-space
python3 mudlib/tools/traceability_audit.py forgotten-space
cd mudlib/worlds/forgotten-space && python3 tests/quests/novel_mud_sync_audit.py
cd mudlib/worlds/forgotten-space && python3 tests/quests/traceability_audit.py
cd mudlib/worlds/forgotten-space && python3 tests/quests/quest_audit.py .
cd mudlib/worlds/forgotten-space && python3 tests/quests/world_liveness_audit.py .
```

登入後預設進入 **Tier 0 新手聚落：黑石鋪（`/d/village/square.c`）**。
