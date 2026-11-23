# 《遺忘的世界》空間資料模型與 Phase 2 整合規格
## Spatial Model & Existing Implementation Integration

- **建議路徑：** `forgotten-space/world/specifications/spatial_schema.md`
- **版本：** v1.1
- **階段：** Phase 2 — 空間資料模型與引擎整合
- **前置文件：**
  - `world/lore/nine_cities_canon.md`
  - `narrative/docs/maps/macro_nine_cities_atlas.md`
- **實作基準：** `phase2.tgz`
- **文件定位：** 既有實作整合、資料模型統一與後續擴充規格

---

# 1. 文件目的

本文件定義《遺忘的世界》Mudlib 的宏觀空間資料模型，並將目前已經存在的 Region、Route、World State 與太古九城資料整合至一致的架構。

本階段不是重新開發一套空間系統，而是以既有程式為基礎，補足資料結構、管理責任、持久化及驗證機制。

核心原則：

1. **No-Rewrite Principle：** 優先擴充既有 daemon 與資料結構，不全面重寫。
2. **正典優先：** 空間資料不得超越已確認的世界正典。
3. **分層管理：** Region、Zone、Site 各自承擔不同粒度的空間描述。
4. **雙網分離：** 地理交通網與文明依存網必須分開。
5. **靜態與動態分離：** 世界定義不等於當前世界狀態。
6. **惰性運算：** 無人活動的區域不應持續空轉。
7. **未知可以存在：** 不為了填滿資料欄位而虛構座標、路線或遺跡。

本文件將資料狀態分成三類：

| 標記 | 意義 |
|---|---|
| IMPLEMENTED | 已在現有程式中實作 |
| PARTIAL | 已有初步實作，但尚未完整 |
| TARGET | 本文件規劃的後續目標 |

除非明確標記為 IMPLEMENTED，否則不可將規格描述視為現有程式已經具備的能力。

# 2. Phase 2 現況盤點

## 2.1 已存在的核心程式

| 檔案 | 現有職責 | 狀態 |
|---|---|---|
| `include/region.h` | 空間層級、Tier、探索階段、路線類型與路徑常數 | IMPLEMENTED |
| `daemon/region_d.c` | Region 靜態資料載入、資源、物價、危機與惰性求值 | PARTIAL |
| `daemon/route_d.c` | 路線載入、行旅時間、資訊傳播延遲、道路通阻 | IMPLEMENTED |
| `daemon/world_state_d.c` | 世界狀態、區域與路線 daemon 聯動 | IMPLEMENTED |
| `world/regions/*.json` | 現代城市、縣與村落的區域資料 | IMPLEMENTED |
| `world/routes/*.json` | 現有六條實體交通路線 | IMPLEMENTED |
| `world/cities/*.json` | 太古九城基本資料 | IMPLEMENTED |
| `world/dependencies/nine_cities_graph.json` | 九城文明依存圖 | IMPLEMENTED |
| `world/topology/macro_topology.json` | 現代地理節點及已確認連線 | IMPLEMENTED |
| `tests/test_phase2_architecture.c` | Phase 2 架構測試 | IMPLEMENTED |

## 2.2 現有資料規模

依目前提供的程式包：

| 項目 | 數量 |
|---|---:|
| 太古九城資料 | 9 |
| 現代 Region 資料 | 8 |
| 九城依存節點 | 9 |
| 九城依存邊 | 32 |
| 實體 Route 定義 | 6 |
| 宏觀拓撲節點 | 8 |
| 宏觀拓撲已確認連線 | 6 |

注意：九城依存圖目前實際有 32 條邊；現有測試採用「至少 26 條」作為通過條件。後續應改成結構與正典驗證，而不只是檢查邊數。

## 2.3 現有實作的重要限制

目前程式已經具備 Region 和 Route 的基本運作能力，但仍有以下缺口：

| 項目 | 現況 | 後續工作 |
|---|---|---|
| Region 管理 | 已實作 | 統一 Schema |
| Zone 管理 | 只有引用欄位及部分 JSON 定義 | 建立正式資料管理 |
| Site 管理 | 尚無獨立管理機制 | 後續擴充 |
| Route 管理 | 已實作 | 補充方向性與驗證 |
| Dependency Graph | 已有 32 條邊 | 正典逐邊驗收 |
| 靜態資料載入 | 已實作 | 加入 Schema 驗證 |
| 動態狀態 | 已有初步管理 | 完成持久化 |
| Lazy Evaluation | 已有價格衰減 | 擴充事件與時間補算 |
| World State 聯動 | 已實作 | 明確化事件與資料責任 |

**本階段的核心工作不是增加更多 Region，而是讓已存在的空間資料具備一致、可靠、可擴充的管理方式。**

# 3. 空間層級

採用三層空間模型：

```text
Region
  └── Zone
        └── Site
```

## 3.1 Region：宏觀區域

Region 是世界的宏觀地理、生活或經濟節點。

可以代表：

- 太古城市。
- 現代府城。
- 縣級區域。
- 村落。
- 山域。
- 森林。
- 海域。
- 特殊空間。

Region 不一定是行政區，也不一定有固定人口或管理者。

目前已有的 Region：

- 金石府城。
- 黑石鋪。
- 重石縣。
- 青河縣。
- 烈礬縣。
- 鎮風縣。
- 盤木縣。
- 拓荒縣。

太古九城則由 `world/cities/` 管理其文明節點資料。

後續應讓太古城市與現代 Region 共用一致的空間識別與引用規則，但不應為了統一而抹除兩者的歷史與功能差異。

## 3.2 Zone：具體場域

Zone 是 Region 內部具有共同環境、活動或管理特徵的場域。

例如：

```text
金石府城 Region
  ├── 地表城區 Zone
  ├── 地下暗渠 Zone
  └── 天樞南域陣基 Zone
```

Zone 不一定是一個 LPC 房間。

一個 Zone 可以包含多個 Site，也可以包含多個 LPC 房間。

## 3.3 Site：具體地點

Site 是實際可以被角色發現、進入或互動的地點。

例如：

- 遺跡入口。
- 古代機關。
- 地下殘殿。
- 陣基核心。
- NPC 活動地點。
- 資源採集點。

Site 可以對應一個或多個 LPC 房間，但兩者不必一對一。

## 3.4 Tier 不屬於 Region

現有 `region.h` 已經明確定義：

```c
#define TIER_0 0
#define TIER_1 1
#define TIER_2 2
#define TIER_3 3
#define TIER_4 4
```

Tier 是場域危險與挑戰程度，不是行政級別，也不是角色等級。

本規格進一步確立：

- Tier 可以定義在 Zone。
- 必要時可以在 Site 局部覆寫。
- Region 不應只有單一 Tier。
- Zone / Site 的危險程度應由實際環境與挑戰條件決定。

Stage 與 Tier 必須分開：

| 名稱 | 意義 |
|---|---|
| Stage | 劇情或探索開放階段 |
| Tier | 場域危險與挑戰層次 |

金石府城 Stage 1/2/3 不等於 Tier 1/2/3。

# 4. 統一資料識別與引用

## 4.1 ID 規則

空間 ID 使用穩定、唯一、不可隨顯示名稱變更的識別碼。

例如：

```text
jinshi
heishipu
ancient_tianshu
tianshu_south_array
tianshu_south_ruins_hall
```

規則：

1. ID 使用小寫英文及底線。
2. 顯示名稱可以修改，ID 不應隨之改變。
3. 不同資料類型不得使用同一 ID。
4. 引用其他資料時必須使用 ID，不使用顯示名稱。
5. 已被動態狀態引用的 ID，不可任意重新命名。

## 4.2 建議統一空間識別

建議在資料模型中使用：

```json
{
  "id": "jinshi",
  "spatial_type": "region"
}
```

而不是讓每種資料各自使用不一致的識別方式。

但現有 Region 使用 `region_id`，城市使用 `id`，不應立即全部改名。

採漸進相容策略：

- 第一階段：載入器接受現有欄位。
- 第二階段：統一內部 mapping 的識別欄位。
- 第三階段：新增資料全部使用統一格式。
- 第四階段：舊欄位完成遷移後才考慮移除。

# 5. Region 資料模型

## 5.1 現有資料結構

目前 `world/regions/*.json` 已經使用以下欄位：

```json
{
  "region_id": "jinshi",
  "name": "金石府城",
  "civ_level": "prefecture",
  "coords": [0, 0, 100],
  "resources": {},
  "factions": {},
  "crisis_deck": [],
  "zone_refs": []
}
```

這是現有實作格式，應先保留。

## 5.2 建議標準化後的結構

```json
{
  "schema_version": "1.1",
  "region_id": "jinshi",
  "name": "金石府城",
  "region_type": "MODERN_CITY",
  "civ_level": "prefecture",

  "geography": {
    "position": null,
    "coordinate_space": null,
    "precision": "UNKNOWN"
  },

  "resources": {
    "primary_product": "refined_metal",
    "secondary_product": "official_charter",
    "demand": [
      "raw_iron",
      "grain",
      "heavy_stone",
      "timber"
    ],
    "reserves": {
      "refined_metal": 50000,
      "grain_granary": 80000
    },
    "price_index": 100
  },

  "factions": {},
  "crisis_deck": [],

  "zone_refs": [],

  "canonical_ref": [],
  "evidence": [],
  "confidence": "CONFIRMED"
}
```

這是目標格式，不要求現有 JSON 一次全部修改。

## 5.3 座標相容與正典保護

目前部分 Region JSON 已存在：

```json
"coords": [0, 0, 100]
```

這些欄位可能供既有遊戲邏輯或地理排列使用。

不得直接將其解讀為已經確認的世界絕對座標。

處理方式：

1. 先盤點座標是否被程式引用。
2. 確認座標的原始用途。
3. 如果只是遊戲內部相對座標，標記為 `LOCAL` 或 `GAME_SPACE`。
4. 如果尚未確認其正典意義，不得升級成世界絕對座標。
5. 在遷移完成前保留舊 `coords`，避免破壞既有功能。

目標格式：

```json
{
  "geography": {
    "position": null,
    "coordinate_space": "UNKNOWN",
    "precision": "UNKNOWN"
  }
}
```

**不允許為了填滿欄位而自行補出九城座標。**

# 6. Zone 與 Site 正式化

## 6.1 現況

目前 Region JSON 使用：

```json
"zone_refs": [
  {
    "zone_id": "jinshi_surface",
    "type": "city_center",
    "tier": 1
  }
]
```

城市 JSON 則使用：

```json
"zones": [
  "central_sanctum",
  "southern_foundation_hub",
  "leyline_regulator"
]
```

這兩種格式並不一致，而且目前尚未有獨立的 Zone / Site 管理 daemon。

## 6.2 目標目錄

```text
world/
  ├── regions/
  ├── zones/
  ├── sites/
  ├── cities/
  ├── routes/
  ├── dependencies/
  └── topology/
```

建議：

- Region JSON 保存 Zone 引用。
- Zone JSON 保存 Site 引用。
- Site JSON 保存 LPC 房間引用及具體互動設定。

## 6.3 Zone 標準格式

```json
{
  "schema_version": "1.1",
  "zone_id": "jinshi_underground",
  "region_id": "jinshi",
  "name": "金石府城地下暗渠",
  "zone_type": "UNDERGROUND",

  "danger_tier": 2,

  "environment": {
    "tags": [
      "UNDERGROUND",
      "ANCIENT_STRUCTURE"
    ]
  },

  "site_refs": [],

  "discovery_rules": {},
  "access_rules": {},
  "survival_rules": {},

  "status": "ACTIVE",
  "evidence": [],
  "confidence": "CONFIRMED"
}
```

## 6.4 Site 標準格式

```json
{
  "schema_version": "1.1",
  "site_id": "tianshu_south_ruins_hall",
  "zone_id": "tianshu_south_array",
  "name": "天樞南域殘殿",
  "site_type": "RUIN",

  "room_refs": [
    "/d/city/under/ruins_hall"
  ],

  "discovery_rules": {},
  "access_rules": {},
  "survival_rules": {},

  "status": "ACTIVE",
  "evidence": [],
  "confidence": "CONFIRMED"
}
```

以上是目標格式，Site ID 與現有 LPC 路徑仍需逐項核對。

# 7. 探索規則

現有 `region.h` 已定義：

```c
#define EXPLORE_DISCOVERY "discovery"
#define EXPLORE_ACCESS    "access"
#define EXPLORE_SURVIVAL  "survival"
```

本規格將其正式化為三個獨立規則集合。

## 7.1 Discovery Rules

回答：

「角色如何知道這個地方存在？」

```json
{
  "required_knowledge": [],
  "required_clues": [],
  "required_events": [],
  "visibility": "UNKNOWN"
}
```

## 7.2 Access Rules

回答：

「角色如何進入這個地方？」

```json
{
  "required_items": [],
  "required_quests": [],
  "required_capabilities": [],
  "required_event_states": []
}
```

`required_items` 只屬於 Access，不得放入 Discovery。

## 7.3 Survival Rules

回答：

「進入後能否在這個環境中生存？」

```json
{
  "resistance_requirements": {},
  "protection_requirements": [],
  "environmental_constraints": [],
  "mechanism_knowledge": [],
  "party_requirements": []
}
```

不得將角色等級作為唯一門檻。

# 8. Route 實體交通模型

## 8.1 現況

目前 `route_d.c` 已具備：

- 載入 `/world/routes/*.json`。
- 查詢路線定義。
- 查詢起點與終點路線。
- 計算步行與坐騎時間。
- 計算貨運時間。
- 查詢資訊傳播延遲。
- 查詢大宗貨物影響延遲。
- 設定道路封閉與恢復。
- 保存道路動態狀態。

因此不應另外建立一個全新的 Route Daemon。

## 8.2 現有 Route 格式

```json
{
  "route_id": "zhongshi_to_jinshi",
  "name": "重石金石官道",
  "from": "zhongshi",
  "to": "jinshi",
  "type": "road",

  "transport": {
    "distance": 240,
    "travel_time_minutes": 180,
    "capacity_freight": 100,
    "toll_copper": 2,
    "risk_tier": 1,
    "conditions": {
      "weather_sensitive": true,
      "requires_permit": false,
      "checkpoint_present": true
    }
  },

  "propagation": {
    "information_delay_minutes": 60,
    "freight_impact_delay_minutes": 180,
    "weight_attenuation": 0.85
  }
}
```

這是現有程式可使用的格式，先予以保留。

## 8.3 後續補充欄位

```json
{
  "schema_version": "1.1",
  "route_id": "zhongshi_to_jinshi",
  "directionality": "BIDIRECTIONAL",
  "evidence": [],
  "confidence": "CONFIRMED"
}
```

需要補足：

- 方向性。
- 路線狀態定義。
- 資料來源。
- 可信度。
- 是否為單向交通。
- 是否具有替代路線。

但不能在尚未確認的情況下，因為程式方便而假設所有路線都是雙向。

## 8.4 目前六條路線

| Route ID | 路線 | 類型 |
|---|---|---|
| `heishipu_to_jinshi` | 黑石關驛道 | ROAD |
| `zhongshi_to_jinshi` | 重石金石官道 | ROAD |
| `qinghe_to_jinshi` | 青河漕運水路 | RIVER |
| `liefan_to_jinshi` | 烈礬赤銅大官道 | ROAD |
| `zhenfeng_to_jinshi` | 北塞鎮風古隘道 | PASS |
| `panmu_to_jinshi` | 盤木林間木道 | ROAD |

這六條是目前資料中已存在的 Route，不代表整個現代世界只有這六條道路。

特別注意：

- `tuogu` 已有 Region JSON。
- 但目前沒有對應的 `tuogu_to_jinshi` Route。
- 不應為了讓六縣全部有路線而自動補出第七條路線。

## 8.5 Route 狀態

目前動態狀態以 `blocked` 為主。

後續可統一為：

```text
OPEN
RESTRICTED
BLOCKED
DESTROYED
SEALED
UNKNOWN
```

舊資料遷移：

| 舊欄位 | 新狀態 |
|---|---|
| blocked = 0 | OPEN |
| blocked = 1 | BLOCKED |

其他狀態必須由實際事件及資料定義決定。

# 9. 雙軌因果傳播

Route 同時承載實體交通及部分資訊傳播，但兩者必須分開計算。

## 9.1 Physical Transport

負責：

- 人員移動。
- 商隊運輸。
- 貨物移動。
- 移動時間。
- 通行容量。
- 運輸成本。
- 道路通阻。

## 9.2 Information Propagation

負責：

- 消息傳播。
- 商業情報。
- 市場預期。
- 事件消息。
- 供需變化的資訊影響。

目前 Route JSON 已經分別保存：

```json
{
  "information_delay_minutes": 60,
  "freight_impact_delay_minutes": 180
}
```

這個雙軌設計應保留。

但必須注意：

- 資訊傳播不一定需要實體貨物。
- 實體貨物可能因交通中斷而延遲。
- 消息可能先於貨物抵達。
- Route 不是資訊傳播的唯一載體。

未來可增加獨立傳播方式，例如驛站、宗門傳訊或陣法傳訊，但必須有正典或實際遊戲設定依據。

# 10. 太古九城資料整合

## 10.1 現況

目前已經存在九份城市 JSON：

```text
world/cities/
  ├── tianshu.json
  ├── xuanzhu.json
  ├── qingming.json
  ├── guanxing.json
  ├── cangjing.json
  ├── canglan.json
  ├── baigong.json
  ├── zhenyue.json
  └── guixu.json
```

每份資料目前包含：

- `id`
- `name`
- `aliases`
- `civilization_role`
- `spatial_type`
- `status`
- `known_by`
- `evidence`
- `confidence`
- `zones`
- `dependencies`
- `topology`

這些欄位有價值，但需要重新界定語義。

## 10.2 城市正典機能

| 城市 | 核心機能 |
|---|---|
| 天樞城 | 陣法中樞、空間協調、地脈總調度 |
| 玄鑄城 | 重型冶煉、靈金合金、陣基構件 |
| 青溟城 | 靈植培育、物種保存、生態維護 |
| 觀星城 | 天象測繪、星煞監測、空間預警 |
| 滄鏡城 | 典籍彙編、文明記憶、術法真本 |
| 滄瀾城 | 水利工程、內河與跨海航運調度 |
| 百工城 | 自動傀儡、自律機關、標準器物 |
| 鎮岳城 | 軍事防禦、邊界屏障、大型鎮煞要塞 |
| 歸墟城 | 能量迴圈終端、高危廢料與界隙消解 |

以上是九城的文明機能，不等於現代城市的行政狀態。

## 10.3 古代城市狀態與現代殘留必須分離

目前部分城市 JSON 的 `status` 可能同時混合：

- 太古城市毀滅後的狀態。
- 遺跡目前的狀態。
- 現代居民或勢力活動狀態。
- 特殊空間狀態。

例如滄瀾城的 `flourishing_secular_port`，不能直接等同於太古滄瀾城完整保存。

建議未來拆分：

```json
{
  "ancient_status": "RUINED",
  "remaining_structure_status": "PARTIAL",
  "modern_manifestation": "UNKNOWN",
  "access_status": "UNKNOWN"
}
```

這樣才能同時表達：

- 太古文明已經毀滅。
- 某些古代設施仍然存在。
- 現代地區可能延續部分水利與航運功能。
- 現代人未必知道其太古來源。

這是資料語義修正，不是要求所有城市現在就填入上述示例值。

## 10.4 Zones 欄位必須逐項驗收

目前城市 JSON 已經列出部分 Zone 名稱，但不能因為這些名稱存在，就視為已經完成地理正典。

例如：

- `central_sanctum`
- `seed_vault`
- `astronomical_archives`
- `rift_threshold`

這些資料應逐項檢查：

1. 是否有正典依據？
2. 是已確認場域，還是設計推定？
3. 是否已經在小說或 Mudlib 中出現？
4. 是否只是未來可探索的候選場域？
5. 是否存在精確位置或完整地貌等未授權推定？

未通過驗收的項目可以保留在工作資料，但不得標記為已確認的正式 Zone。

## 10.5 known_by 的語義

目前 `known_by` 使用：

```json
[
  "scholars",
  "archaeologists",
  "cangjing_seekers"
]
```

這代表哪些群體可能知道該城市，不等於玩家的個別探索進度。

後續應區分：

- 世界中哪些群體知道。
- 哪些 NPC 知道。
- 玩家角色知道多少。
- 哪些資訊只是傳聞。

不能因為城市 JSON 中存在 `known_by`，就讓所有玩家自動取得城市完整地圖。

# 11. 九城文明依存圖

## 11.1 現況

目前：

```text
world/dependencies/nine_cities_graph.json
```

已經建立：

- 9 個節點。
- 32 條依存邊。
- `dependency_type`。
- `direction`。
- `strength`。
- `necessity`。
- `description`。

這是既有的重要資產，應保留，不應重寫成只有城市名稱的簡化表格。

## 11.2 目前依存圖的問題

現有依存資料比單純的九城功能表更具體，但也存在需要驗收的內容：

1. 部分依存邊的具體供應方向尚需正典確認。
2. `strength` 的 S/A/B 等級目前尚未形成可驗證的量化定義。
3. `necessity` 與 `strength` 可能重複表達相近概念。
4. `direction` 使用 inbound、outbound、supply、transport、information 等不同語義，尚未統一。
5. 部分邊可能把功能依存、資訊交換與物流運輸混在同一種圖模型。

因此，本階段不應直接增加更多依存邊，而應先完成語義驗收。

## 11.3 建議統一 Edge 語義

```json
{
  "source": "xuanzhu",
  "target": "baigong",
  "dependency_type": "MATERIAL",
  "relation": "SUPPLIES",
  "strength": "A",
  "necessity": "IMPORTANT",
  "evidence": [],
  "confidence": "INFERRED"
}
```

欄位說明：

| 欄位 | 說明 |
|---|---|
| source | 供應或支援來源 |
| target | 接受支援的對象 |
| dependency_type | 依存類型 |
| relation | 關係方向與語義 |
| strength | 依存強度 |
| necessity | 必要程度 |
| evidence | 正典依據 |
| confidence | 可信度 |

這是目標格式，應先以相容方式讀取現有資料，再進行遷移。

## 11.4 Strength 與 Necessity 必須分開定義

建議：

| Strength | 意義 |
|---|---|
| S | 關鍵依存，斷裂會直接造成核心功能失效 |
| A | 強依存，斷裂造成重大效能下降 |
| B | 中度依存，可高成本替代 |
| C | 弱依存，主要造成效率損失 |

Necessity：

| 值 | 意義 |
|---|---|
| NECESSARY | 文明系統不可缺少 |
| IMPORTANT | 對完整能力十分重要 |
| SUPPORTING | 提供額外支援 |

兩者不能只靠名稱判斷，必須為實際依存關係提供定義依據。

## 11.5 文明依存不等於地理相鄰

即使玄鑄城與青溟城在文明機能上互相依賴，也不代表兩者在現代地理上有直接道路。

同理：

- `dependencies` 不能自動生成 Route。
- `topology` 不能自動生成 Route。
- 功能供應關係不能自動生成地理座標。

這是九城資料最重要的保護原則之一。

# 12. 現代宏觀拓撲

## 12.1 現況

目前：

```text
world/topology/macro_topology.json
```

包含 8 個現代地理節點及 6 條已確認連線。

節點包括：

- 金石府城。
- 重石縣。
- 黑石鋪。
- 青河縣。
- 烈礬縣。
- 鎮風縣。
- 盤木縣。
- 拓荒縣。

現有六條連線都指向金石府城。

## 12.2 目前缺口

拓荒縣已有 Region JSON，但沒有對應 Route，也沒有出現在目前六條連線中。

這不是程式必須立即補齊的錯誤，而是目前地理網絡尚未完整的事實。

後續應確認：

- 拓荒縣與金石府城是否存在已確認的交通關係。
- 是否透過其他 Region 間接連通。
- 是否尚未建立交通設定。
- 是否有其他既有地理資料可以作為依據。

在確認之前，維持未知。

## 12.3 Topology 與 Route 的關係

Topology 表達宏觀地理節點及已知關係。

Route 表達實際可運作的交通路線。

兩者關係：

```text
Macro Topology
    │
    ├── Nodes
    │
    └── Connections
           │
           └── route_ref
                    │
                    ▼
                 Route
                    │
                    ├── Transport
                    └── Propagation
```

Topology 中的連線可以沒有 Route，表示關係尚未具體化。

但如果標記為已確認實體交通連線，就應該有相應 Route 或明確的資料依據。

# 13. 靜態定義與動態狀態

## 13.1 現況

`region_d.c` 已經分開管理：

```c
nosave mapping region_defs;
mapping region_states;
```

這個方向正確，應保留。

`route_d.c` 也分開管理：

```c
nosave mapping routes_def;
mapping route_states;
```

因此不需要重新設計整套靜態／動態分離架構。

## 13.2 目標目錄

```text
world/
  ├── regions/
  ├── zones/
  ├── sites/
  ├── cities/
  ├── routes/
  ├── dependencies/
  └── topology/

data/
  ├── regions/
  ├── routes/
  ├── zones/
  ├── sites/
  └── events/
```

`world/` 保存靜態定義。

`data/` 保存執行期間的動態狀態。

## 13.3 動態狀態範例

| 靜態定義 | 動態狀態 |
|---|---|
| Region 存在 | 當前人口與資源變化 |
| Zone 存在 | Zone 是否受災 |
| Site 存在 | 機關是否損壞 |
| Route 存在 | 道路是否封閉 |
| 遺跡存在 | 遺跡是否被探索 |
| 城市具有文明機能 | 當前機能是否仍能運作 |

不得將動態狀態直接寫回正典靜態資料。

# 14. Lazy Evaluation 與世界模擬

## 14.1 現況

`region_d.c` 已經實作：

- Region 狀態的延遲計算。
- `last_eval_time`。
- 物價指數回歸。
- 危機狀態維持。
- 資源儲量查詢及調整。

目前物價採每 60 遊戲分鐘衰減約 10% 的離散步進方式。

概念為：

\[
D_{n+1}=0.9D_n
\]

其中：

\[
P_n=100+D_n
\]

這與先前文件中的連續時間指數公式不同。

目前應以程式實際演算法為準，不可在規格中將兩者描述成完全相同。

## 14.2 現有不足

目前 `evaluate_region()` 的主要延遲計算集中於價格指數。

尚未完整涵蓋：

- 所有區域事件的時間補算。
- 跨區貨物流動的批次結算。
- 長時間離線期間的事件一致性。
- 動態狀態完整持久化。

因此 Lazy Evaluation 尚屬 PARTIAL。

## 14.3 離散事件不得自然消失

以下狀態不能單純依時間自動恢復：

- 礦坑塌方。
- 道路封鎖。
- 建築損毀。
- 機關故障。
- 封印破壞。
- 戰爭或重大災害。

必須由事件、工程或其他具體行動完成狀態轉移。

目前 `region_d.c` 已有 `active_crises` 與 `resolve_region_crisis()` 的初步設計，應保留並補足完整持久化。

# 15. 持久化與資料一致性

## 15.1 目前最重要的技術缺口

目前 `region_d.c` 的：

```c
int save_region(string region_id)
int restore_region(string region_id)
```

尚未完成實際分區存取。

因此：

- Region 動態狀態尚不能視為已完整持久化。
- `last_eval_time` 可能無法在重啟後正確恢復。
- 資源與物價的跨重啟一致性仍需驗證。

`route_d.c` 已有道路狀態的 `save_object()` 與 `restore_object()`，但仍需檢查是否能正確處理新增路線、舊資料及異常恢復。

## 15.2 建議優先完成

第一階段：

1. Region 狀態分區存檔。
2. Region 狀態分區恢復。
3. Route 狀態存檔與恢復驗證。
4. 存檔格式版本管理。
5. 伺服器重啟後的時間差補算。

第二階段：

1. Zone 動態狀態。
2. Site 動態狀態。
3. 跨區事件冪等處理。
4. 跨區物流與庫存一致性。

## 15.3 事件冪等性

同一事件不能因為：

- daemon 重載。
- 伺服器重啟。
- Lazy Evaluation 重複呼叫。
- 玩家重複觸發查詢。

而造成重複扣除庫存、重複搬運貨物或重複產生經濟影響。

後續事件資料應具備穩定的事件 ID 與處理狀態。

# 16. Daemon 職責

既有 daemon 應保留，逐步明確化責任。

| Daemon | 主要職責 | 不應負責 |
|---|---|---|
| `world_state_d` | 全域世界狀態與跨系統協調 | 包辦所有區域模擬 |
| `region_d` | Region 資源、物價、危機與惰性求值 | 管理所有 NPC 對話 |
| `route_d` | 實體路線、通阻、行旅及路線傳播延遲 | 決定市場價格 |
| `event_manager` | 事件發布、訂閱與因果派送 | 直接實作所有經濟規則 |
| `rumor_d` | 傳聞及資訊傳播 | 直接改變庫存數值 |
| `city_d` | 特定城市專屬邏輯 | 取代通用 Region 管理 |

Zone / Site 的獨立管理尚未建立。

本階段可以先由 Region 資料管理層提供 Zone / Site 查詢介面，不必立即增加新的常駐 daemon。

待資料量與實際需求明確後，再決定是否需要獨立的 `zone_d` 或 `site_d`。

**不要為了架構看起來完整，就提前增加大量空殼 daemon。**

# 17. Phase 2 實作順序

本階段應依照既有程式成熟度安排，不必從最上層重新開發。

## P2-A：既有資料盤點與正典驗收

- [ ] 核對九城 JSON 與九城正典。
- [ ] 核對 32 條文明依存邊。
- [ ] 核對九城 Zone 名稱與正典依據。
- [ ] 檢查 `topology` 是否被誤用為地理連線。
- [ ] 檢查 `known_by` 的語義。
- [ ] 檢查現代 Region 的 `coords` 是否有程式依賴。
- [ ] 核對六條 Route 的起點、終點及資料依據。
- [ ] 記錄拓荒縣尚未建立 Route 的狀態。

## P2-B：資料 Schema 統一

- [ ] 定義 Region Schema。
- [ ] 定義 Zone Schema。
- [ ] 定義 Site Schema。
- [ ] 定義 Route Schema。
- [ ] 定義 Dependency Schema。
- [ ] 定義 Topology Schema。
- [ ] 定義資料版本與相容讀取規則。
- [ ] 加入 JSON 結構驗證。

## P2-C：Zone / Site 管理

- [ ] 統一 Region 的 `zone_refs`。
- [ ] 將城市 JSON 的 `zones` 轉為標準引用。
- [ ] 建立 Zone 獨立資料檔。
- [ ] 建立 Site 獨立資料檔。
- [ ] 支援 LPC 房間引用。
- [ ] 不破壞現有房間 exits。

## P2-D：Route 與 Topology 整合

- [ ] 保留現有六條 Route。
- [ ] 明確 Route 方向性。
- [ ] 統一 Route 狀態。
- [ ] 驗證 Topology 的 Route 引用。
- [ ] 確認拓荒縣交通關係是否存在。
- [ ] 不補未確認的九城交通網。

## P2-E：Region / Route 持久化

- [ ] 完成 `save_region()`。
- [ ] 完成 `restore_region()`。
- [ ] 驗證資源與物價存檔。
- [ ] 驗證危機狀態存檔。
- [ ] 驗證 Route 通阻狀態存檔。
- [ ] 驗證重啟後的時間補算。
- [ ] 驗證重複事件不會重複執行。

## P2-F：既有系統回歸

- [ ] 執行 `test_phase2_architecture.c`。
- [ ] 執行原有世界狀態測試。
- [ ] 執行原有區域事件測試。
- [ ] 執行金石府城地下空間測試。
- [ ] 執行伺服器重啟恢復測試。
- [ ] 確認既有遊戲行為沒有回歸。

# 18. 驗收標準

## 18.1 資料模型

- [ ] Region、Zone、Site 各自有明確定義。
- [ ] Route 是獨立關係資料。
- [ ] Dependency Graph 與 Route Graph 分離。
- [ ] Stage 與 Tier 分離。
- [ ] Discovery、Access、Survival 分離。
- [ ] 未知座標可以保留為 null。
- [ ] 所有資料可追溯來源。

## 18.2 現有程式相容

- [ ] 原有 Region JSON 可以載入。
- [ ] 原有 Route JSON 可以載入。
- [ ] 原有九城 JSON 可以載入。
- [ ] 原有 Dependency Graph 可以載入。
- [ ] 原有 World State 聯動不受破壞。
- [ ] 既有 LPC 房間不需要全面重寫。

## 18.3 持久化

- [ ] Region 狀態可保存。
- [ ] Region 狀態可恢復。
- [ ] Route 狀態可保存。
- [ ] Route 狀態可恢復。
- [ ] 重啟後時間差補算正確。
- [ ] 重複事件不造成重複影響。

## 18.4 正典保護

- [ ] 九城名稱正確。
- [ ] 九城機能與正典一致。
- [ ] 不將文明依存當成地理相鄰。
- [ ] 不將推定 Zone 當成已確認地理。
- [ ] 不補九城精確座標。
- [ ] 不補九城完整道路。
- [ ] 不補全部遺跡清單。
- [ ] 不將歸墟的特殊空間性質簡化為一般地理位置。

# 19. 版本與後續方向

本文件 v1.1 的核心工作是讓現有 Phase 2 實作與正式規格一致。

完成後再進入：

**Phase 3：世界空間持續演進**

可能涵蓋：

- Zone 級環境模擬。
- Site 級機關與遺跡狀態。
- 跨區物流。
- NPC 移動。
- 區域供需聯動。
- 世界事件與資訊傳播。
- 玩家行動造成的延遲因果影響。

不應在 Phase 2 尚未完成資料一致性與持久化之前，就先擴大模擬範圍。

---

# 20. 最終設計原則

《遺忘的世界》的空間系統不是一張靜態地圖，而是一個持續演進的世界模型。

Region 描述宏觀生活與地理區域。

Zone 描述區域內的實際場域。

Site 描述可被探索與互動的具體地點。

Route 描述實體移動。

Dependency Graph 描述文明機能依存。

Information Propagation 描述消息與因果影響。

World State 描述這些空間與關係目前的狀態。

各系統必須能夠獨立運作，也必須能夠透過明確的資料介面互相協作。

**最重要的原則：不重寫已經能運作的世界，不把尚未知道的世界假裝成已經知道；讓空間資料隨著正典、探索與世界事件逐步成長。**
