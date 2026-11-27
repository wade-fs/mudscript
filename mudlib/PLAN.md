# `multiverse/` — 多小說共用 MVVM × Overlay Mudlib 架構計畫

> **狀態**：架構規劃書（Draft / Backlog；暫不更動現有 `forgotten-space/` 或 Go Driver）  
> **目標容器目錄**：`~/src/github/mudscript/multiverse/`  
> **設計宗旨**：以單一共用核心層（`common/`）搭配可插拔的多世界資料層（`worlds/<world_id>/`），同時容納 **`forgotten-space`（《遺忘的世界》）＋ `wanjie-lou`（《萬界風月樓》）＋ `xxx` ＋ `yyy` ...**，讓每部小說只需專注於自身的 Model（正典 JSON 與極少專屬規則），共用同一套 MVVM / MVP 執行期與前端介面。

---

## 一、為何需要 `multiverse/` 新容器

目前 `~/src/github/mudscript/` 底下是「單一世界一個完整 Mudlib 目錄」（如 `fs/`、`fsmud/`、`forgotten-space/`）。如果再把第 2、第 3 本小說複製貼上整套 `std/`、`cmds/`、`daemon/`、`web/static/`，會面臨三個結構性問題：
1. **核心邏輯重複維護**：修一個 `look`、`quest_engine_d`、`phase_d` 或 WebSocket UI 協議，要改 N 份一樣的檔案。
2. **世界耦合風險**：若為了省事把多本小說塞進同一個 `forgotten-space/`，不同年代、力量體系、語彙規範、18+ 分級與存檔會立刻互相衝突。
3. **內容開發太重**：每開一個房間、NPC、任務都要手寫大量重複的 `.c` 樣板碼，無法像現代遊戲引擎一樣主要由宣告式 JSON 驅動。

**`multiverse/` 的解法**：將整個新世代 Mudlib 拆為「**共用核心（`common/`）** ＋ **多世界掛載槽（`worlds/*`）**」，並用 Go Driver 原生 Overlay VFS 串接起來。

---

## 二、總體目錄拓撲（Container Layout）

```text
mudscript/
├── cmd/, driver/, preprocessor/       # Go Driver：擴充 -common / -world 疊層 VFS 與寫入隔離
├── forgotten-space/                   # 【既有資產】現有《遺忘的世界》穩定線，遷移過渡期間保持零破壞
│
└── multiverse/                        # 【新架構容器】統一容納共用核心與多部小說世界
    ├── PLAN.md                        # 本架構與遷移計畫
    ├── tools/                         # 跨世界共用工具（開世界鷹架 new_world.py、通用 Schema/追溯稽核器）
    │
    ├── common/                        # 【共用層：VM / Presenter ＋ 預設 View】與任何單一小說無關
    │   ├── master.c
    │   ├── secure/                    # 帳號認證、權限與存檔邊界檢查
    │   ├── include/                   # ansi.h, globals.h, mvvm_protocol.h
    │   ├── std/
    │   │   ├── living.c               # 通用生物／角色屬性容器
    │   │   ├── json_room.c            # 資料驅動房間基底
    │   │   ├── json_npc.c             # 資料驅動 NPC 基底（對話樹／日程／行為）
    │   │   └── json_item.c            # 資料驅動道具基底
    │   ├── cmds/                      # 通用玩家與巫師指令（look, go, talk, act, quest, inv, save...）
    │   ├── daemon/
    │   │   ├── schema_d.c             # 載入 worlds/<id>/schema/*.json，註冊力量體系／幣制／屬性公式
    │   │   ├── room_factory_d.c       # 依 JSON 動態具現或索引房間、出口與環境互動
    │   │   ├── quest_engine_d.c       # 宣告式任務、分支選擇與狀態效應推進引擎
    │   │   ├── world_state_d.c        # 各世界動態變數、危機牌組與事件匯流排
    │   │   ├── phase_d.c              # 時辰節律與 NPC 排程核心
    │   │   └── ui_bridge_d.c          # 將房間/任務/角色狀態打包為結構化 ViewModel DTO（Web + ANSI）
    │   └── web/static/                # 共用前端 SPA 殼層（讀取各世界 theme manifest 換皮渲染）
    │
    └── worlds/                        # 【各小說獨立世界層：Model ＋ 少數專屬擴充 ＋ 隔離 Data】
        ├── _template/                 # 標準新世界開箱模板（一鍵複製建立 xxx / yyy）
        │
        ├── forgotten-space/           # 《遺忘的世界》（漸進遷移／對應現有 forgotten-space/）
        │   ├── manifest.json          # 世界識別、啟動參數、啟用的規則模組、主題風格
        │   ├── schema/                # 法/力/物三維體系、太古九城拓撲與依賴圖
        │   ├── regions/, zones/, sites/, routes/
        │   ├── rooms/, npcs/, items/, quests/
        │   ├── daemon/                # 只保留本書特有法則（city_d, region_d, route_d, tier3_d）
        │   ├── web/theme/             # 古典荒原／灰金風格覆寫
        │   ├── tests/                 # 沿用反系統流語彙檢查與九城因果稽核
        │   └── data/                  # 《遺忘的世界》獨立存檔與狀態
        │
        ├── wanjie-lou/                # 《萬界風月樓》（對應 /home/wade/src/github/novel/sex）
        │   ├── manifest.json          # 世界識別（含分級標記、九界架構開關、主題設定）
        │   ├── schema/                # 九大平行力量體系、萬分制修復刻度（0..10000）、三態內容鎖定表
        │   ├── rooms/, npcs/, items/, quests/   # 萬界樓九大設施 ＋ 01青玄 / 02滄瀾 ... 09太虛
        │   ├── daemon/                # 只保留本書特有法則（tower_d, anchor_d, resonance_d, commerce_d）
        │   ├── web/theme/             # 萬界樓星門儀表板、修復度進度條與諸天切換面板
        │   ├── tests/                 # 對齊 chapters/01~03（88章）與 world_bible.md 稽核
        │   └── data/                  # 《萬界風月樓》獨立存檔與狀態（與其他世界完全隔離）
        │
        ├── xxx/                       # 未來的第 3 本小說（依 _template/ 生成）
        └── yyy/                       # 未來的第 4 本小說（依 _template/ 生成）
```

---

## 三、核心技術設計

### 3.1 Go Driver 疊層虛擬檔案系統（Overlay VFS）

現有 `driver/file.go` 已具備「磁碟 `MudLibPath` → 內嵌 `EmbeddedFS`」兩層讀取機制，路徑組裝集中於 `driver/file.go`、`driver/driver.go`、`driver/efun_system.go`、`driver/efun_object.go`、`driver/efun_buffer.go`、`driver/init_hub.go`、`preprocessor/preprocessor.go` 與 `cmd/fsmud/main.go`。擴充方式如下：

1. **統一啟動方式**：
   ```bash
   ./bin/fsmud -common multiverse/common -mudlib multiverse/worlds/forgotten-space -master master.c
   ./bin/fsmud -common multiverse/common -mudlib multiverse/worlds/wanjie-lou -master master.c
   ./bin/fsmud -common multiverse/common -mudlib multiverse/worlds/xxx -master master.c
   ```
   （未指定 `-common` 時行為與現在完全相同，保證現有 `forgotten-space/`、`fsmud/`、`fs/` 零回歸。）
2. **讀取覆寫鏈（World → Common → Embedded）**：
   - 封裝 `d.ResolveReadPath()` / `d.ReadFile()`：先查 `MudLibPath`（`worlds/<name>/...`），找不到再落回 `CommonPath`（`multiverse/common/...`），最後才查 `EmbeddedFS`。
   - **局部覆寫能力**：若某世界不需特別邏輯，直接吃 `common/`；若某世界需要特化指令或介面（例如覆寫 `/cmds/look.c` 或 `/web/static/theme.css`），只要在自己目錄放同名檔案即自動生效。
   - `Preprocessor` 支援多層 include path（`#include <...>` 優先找世界層再找 `common/include`）；`get_dir()` 合併兩層目錄內容並由上層覆寫同名項。
3. **寫入安全隔離（Write Pinning + Virtual Chroot）**：
   - 封裝 `d.ResolveWritePath()`：所有 `save_object`、`write_file`、`rm`、`mkdir`、`rename`、`data/`、`log/` **強制只能寫入上層 `MudLibPath`（`worlds/<name>/data/`）**。
   - 每一層讀取皆保留現有 Virtual Chroot 邊界校驗（禁止 `..` 逃逸）。`common/` 在執行期對所有世界而言是**純唯讀共用底座**。

### 3.2 MVVM / MVP 資料驅動分層契約

目標是讓「**新增一部小說世界時，90% 以上工作是撰寫標準化 JSON Model，而不是寫大量重複 `.c` 檔**」：

| 層級 | 放在哪裡 | 職責規範 |
| :--- | :--- | :--- |
| **Model（純設定與正典資料）** | `multiverse/worlds/<id>/` 下的 `manifest.json`、`schema/`、`rooms/`、`npcs/`、`items/`、`quests/` | 描述該世界「有什麼」：空間拓撲、人物對話狀態機、物件屬性、力量公式參數、任務條件與分支後果。**不寫任何渲染格式、顏色碼或引擎流程控制**。 |
| **ViewModel / Presenter（狀態機與業務規則）** | 通用邏輯在 `multiverse/common/daemon/` ＋ `std/`；<br>世界特有規則在 `worlds/<id>/daemon/` | `common` 提供通用的房間/NPC具現、選擇分支任務引擎、時辰排程與策略插槽（Hooks）；各世界只在真的無法用 JSON 表達時，才掛入自己的專屬 Daemon（如 `tier3_d.c`、`tower_d.c`）。輸出標準化 DTO Snapshot。 |
| **View（呈現與互動介面）** | `multiverse/common/web/static/` ＋ `ui_bridge_d.c`（＋世界層 `web/theme/`） | 根據 ViewModel 送出的結構化狀態（當前房間、出口按鈕、互動動作、對話選項、進度條／儀表板、角色面板）統一渲染；同一套資料同時相容 WebSocket GUI 與文字終端（ANSI）。 |

#### 房間與 NPC 的「無重複 `.c`」實作策略（二選一拍板）
目前 Driver 預設依賴載入實體 `.c` 檔，未來實作 JSON 驅動房間/NPC 時提供兩條清潔路徑：
* **選項 A — Master `compile_object()` 虛擬工廠（推薦長期架構）**：當載入 `/rooms/qingxuan_gate` 找不到 `.c` 時，Driver 委派 `master.c` 呼叫 `room_factory_d` clone `/std/json_room` 並以對應 JSON 初始化，達成真正的「零冗餘 `.c` 檔」。
* **選項 B — Build-time 極簡 Stub 產生器**：維持 Driver 物件載入不變，由 `multiverse/tools/sync_stubs.py` 依 `rooms/*.json` 自動產生 3 行極簡 `.c` stub，JSON 仍是唯一真理來源（Single Source of Truth）。

---

## 四、多元世界容納示範：如何同時承載不同小說

### 4.1 槽位一：`worlds/forgotten-space/`（嚴肅單界寫實）
* **專屬法則**：保留現有九城因果圖、`city_d.c`（府城秩序／驗真）、`region_d.c`（危機牌組／物價）、`route_d.c`（行旅延遲）、`tier3_d.c`（洞天時差阻尼與 K/U 雙軌）。
* **專屬稽核**：啟用 `ban_modern_jargon` 規則，維持既有雙向追溯與九城一致性檢查。
* **遷移方式**：**不強制中斷開發**；先讓現有 `~/src/github/mudscript/forgotten-space/` 繼續穩定推進當前項目，待 `multiverse/common/` 與 Driver `-common` 驗證完成後，再分批把 `std/`、`cmds/` 與通用 `quest_engine_d.c` 對接遷移進 `multiverse/worlds/forgotten-space/`。

### 4.2 槽位二：`worlds/wanjie-lou/`（諸天萬界＋成人雙修）
* **小說來源**：`/home/wade/src/github/novel/sex/`（現有 88 章＋《world_bible.md》v1.2）。
* **專屬法則**：
  - `tower_d.c`：萬界樓萬分制修復（`0 ~ 10000`）＋ 兩層設施解鎖（設施本體 → 內容三態：已發現／已解鎖／已掌握）。
  - `anchor_d.c`：紅顏時空錨點（神魂感應）vs 本土位面定錨點（空間出口）、跨界權限矩陣與物理門檻（如 `250/10000` = `2.50%`）、資訊落差原則。
  - `resonance_d.c`：《太上玄奼真經》九篇章與「成年／自願／心境／生命印記」三階因果檢核。
  - `commerce_d.c`：跨界商票清算與物資中轉本源消耗限制。
  - 多力量體系 `schema/`：九大世界（青玄修仙、滄瀾高武、艾瑟蘭魔法、諾瓦星域科技基因……）各有獨立境界與數值表，透過 `schema_d.c` 熱切換。

### 4.3 槽位三與後續：`worlds/xxx/`、`worlds/yyy/`
* 透過 `python3 multiverse/tools/new_world.py <world_id>` 從 `worlds/_template/` 生成標準骨架（含 `manifest.json`、基本 `schema/`、起始房間與測試掛鉤）。
* 只要填寫該小說的結構化 JSON 與選配擴充 Hook，即可直接以 `-common multiverse/common -mudlib multiverse/worlds/<world_id>` 啟動完整可玩的世界與前端介面。

---

## 五、共用稽核與開發工具鏈（`multiverse/tools/`）

將原本 `forgotten-space/tests/quests/` 的驗證方法論升級為**「共用稽核核心 ＋ 世界規則插件」**：
1. **`validate_world.py <world_id>`**：讀取 `manifest.json` 驗證必填 JSON 結構、房間出口雙向可達性、NPC／道具／任務引用完整性。
2. **`audit_schema_usage.py <world_id>`**：確保所有世界 JSON 欄位皆有對應的 `common/daemon/` 或 `worlds/<id>/daemon/` 消費，消除幽靈欄位。
3. **`traceability_audit.py <world_id>`**：產出並檢查「小說章節 ↔ 任務 ↔ NPC ↔ 地點」雙向追溯矩陣（規則與章節路徑由各世界 `manifest.json` 指定）。

---

## 六、分階段實施路線圖（未來動工順序）

| 階段 | 工作項目 | 關鍵驗收指標 |
| :--- | :--- | :--- |
| **Phase 0**<br>Driver Overlay 支援 | 改造 `driver/`、`preprocessor/`、`cmd/fsmud/` 支援 `-common` 讀取疊層與上層 `WriteLayer` 寫入鎖定。 | `make test` 與既有 `forgotten-space` 全套測試無回歸；新增多層 Chroot 與寫入隔離測試通過。 |
| **Phase 1**<br>建置 `multiverse/common/` | 從現有核心抽離與世界觀無關的 `master.c`、`std/`、`cmds/`、`quest_engine_d.c`、`phase_d.c`、`world_state_d.c` 與前端殼層。 | 用最小試驗世界 `_template` 搭配 `-common multiverse/common` 可正常啟動、登入、移動、接解任務與存檔。 |
| **Phase 2**<br>MVVM JSON 工廠與 DTO | 實作 `schema_d.c`、`room_factory_d.c`、`json_room.c`、`json_npc.c`、`ui_bridge_d.c` 與選擇分支擴充。 | 純 JSON 即可定義新房間、NPC 狀態機、帶後果選擇任務與獨立力量體系表。 |
| **Phase 3**<br>首個新世界驗證（`wanjie-lou`） | 以《萬界風月樓》Vol.1（ch001–ch016）建立驗證切片（萬界樓中樞＋青玄界初段＋`tower_d`／`resonance_d`）。 | 驗證新架構能在幾乎不碰 `common/` 的前提下獨立承載全新題材與系統。 |
| **Phase 4**<br>雙界擴展與 `forgotten-space` 對接評估 | 為 `wanjie-lou` 補齊 Vol.2–3（至 ch088）；同時實測將 `forgotten-space` 對應轉為 `multiverse/worlds/forgotten-space/` 的結構相容度。 | 兩套風格截然不同的世界共用同一 `multiverse/common/` 穩定運行，所有自動稽核與 LPC 測試全過。 |
| **Phase 5**<br>開放 `xxx` / `yyy` 模板化複製 | 定稿 `worlds/_template/`、`new_world.py` 腳手架與多世界並存部署腳本（Docker / K8s manifest 生成）。 | 開啟第 3 部小說新世界只需撰寫 Model JSON 與可選規則插件，開箱即用。 |

---

## 七、日後啟動 Phase 0 前須拍板的三個設計問題

1. **現有 `forgotten-space/` 的長期位置**：未來是計畫正式遷入 `multiverse/worlds/forgotten-space/`（原目錄淘汰或保留軟連結），還是先讓 `multiverse/` 服務所有新小說，穩定後再遷？
2. **房間／NPC JSON 具現技術路線**：選擇擴充 Go Driver 支援虛擬物件工廠 `compile_object()`（Phase 2 無 `.c` stub），還是維持現有物件載入並由工具產生極簡 stub `.c`？
3. **跨倉庫邊界**：像 `/home/wade/src/github/novel/sex/` 等小說正文各自位於獨立目錄，日後稽核腳本是透過設定路徑跨倉讀取，還是將摘要索引匯入各世界目錄內的 `canon/`？
