# 《遺忘的世界》需求追溯與交付範圍基線矩陣 v1.0
# (Requirements Traceability & Release Scope Baseline Specification)

> **版本**：v1.0（依據 `docs/completed-spec.md` 正式審定）  
> **定位**：連接《完成規格 (`completed-spec.md`)》、《世界設定集 (`world_setting.md`)》、《Tier 1 世界運作模型 (`tier1_world_operating_model_v0_1.md`)》與實際小說正文／LPC 程式碼的**唯一驗收與派工基線（Single Source of Truth for Acceptance & Autonomous Execution）**。  
> **用途**：供後續長程自主開發（`/goal`、`/teamwork-preview`）與獨立審查代理（Level 1 機器驗證 / Level 2 獨立審查 / Level 3 作者裁決）逐項核驗，防止提早宣布完成（Premature Completion）或越權竄改正典（Canon Drift）。

---

## 一、已裁決之範圍與架構決策 (`OPEN-01 ~ OPEN-05` & `Q1 ~ Q6` 正式鎖定)

針對 [completed-spec.md](file:///home/wade/src/github/mudscript/forgotten-space/docs/completed-spec.md#L202-L210) 第六節所列之未決範圍與規則邊界，經作者拍板裁定如下：

### 1. 正式交付範圍與分期里程碑 (`OPEN-01`：`RULE`)
為兼顧「不縮減成只有新手村」與「不因無止境擴充而永遠無法交付」，全專案劃分為三個可獨立驗收之正式版本：
- **Milestone 1（`Release v1.0：凡塵雙卷與城鄉區域網完整交付版`）——【當前首要交付目標】**
  - **小說正式範圍**：
    - 第一卷【黑石驚蟄】（Ch.1 ~ Ch.38，全 38 章正文已 100% 完稿並通過審核）。
    - 第二卷【金石風雲】（Ch.39 ~ Ch.82，全 44 章大綱 v1.0 已鎖定，須完成全部 44 章具備文學品質之正式正文）。
  - **LPC Mudlib 正式範圍**：
    - **Tier 0 新手聚落（黑石鋪 `/d/village/`）**：完整日常生態、五大身世奇遇、北崖礦難、大荒煞潮與黑石關軍政博弈任務鏈，以及主角離村後的 30 天自主演進時鐘。
    - **Tier 1 金石府城（`/d/city/` 9 大分區、45 間正典房、52 位正典具名 NPC）**：四關稅則、紅塵濁氣梯度、絕靈法網、72 小時兩階段居留法、三道總堂轉職、五維能力分離、通寶信用凍結與三印合符／三方會審。
    - **Tier 1 六大次級縣城與官道網路（採方案 B 完整城鎮規模：六縣 85 間房＋官道 22 間節點房＝107 間房）**：青河、烈礬、盤木、鎮風、濁水、重石六縣完整街區、6 縣 × 3 道＝18 個地方等效初階資格認證入口、壓縮旅行系統（`travel_d.c`）與 30 天無主角介入自主演進時間線（Stage 1~4）。
    - **核心系統閉環**：力／法／物三元戰鬥系統（取代舊西幻 `combat_d.c`）、NPC 三態生命週期（`phase_d.c`）、以及角色／世界／事件／證物保管鏈之跨重啟持久化存檔（`MUD-05`）。
- **Milestone 2（`Release v2.0：名山問道擴充版`）**：小說第三卷大綱與正文 ＋ Tier 2 三大名山宗門地圖、登天梯／問心谷山門大考與二階道化機制。
- **Milestone 3（`Release v3.0：洞天與歸墟終局版`）**：小說第四、五卷正文 ＋ Tier 3 桃花源洞天與 Tier 4 歸墟殘塚終局奇遇。

### 2. 六縣空間粒度與「多起點等效資格模型」 (`OPEN-02` 方案 B & `Q1 ~ Q5`：`RULE`)
依據 [tier1_world_operating_model_v0_1.md](file:///home/wade/src/github/mudscript/forgotten-space/docs/tier1_world_operating_model_v0_1.md#L22) `R-01`（「六縣分舵、縣學、地方武館與工坊均可提供等效的初階資格認證與師承入口，玩家不必事事湧向金石府城」），鎖定以下五項設計：
1. **空間規模（方案 B）**：六大縣城各建 **14～15 間實體房間**（合計 **85 間縣城房**，位於 `/d/county/<county_id>/`），外加 12 條標準路段的 **22 間具名官道／水路／暗河節點房**（位於 `/d/road/`），並修正黑石鋪 `square.c` 直通府城 `south_road.c` 的空間跳躍缺陷。
2. **長途旅行壓縮機制（`Q1` / `CROSS-06`）**：由 `/daemon/travel_d.c` 統一管理路段通行。玩家於官道節點移動時，依 `ROUTE_SEGMENTS` 檢查季節封路與重車限制、扣除相應精力（`sp`）與飲食、進行短時間壓縮步進並累加個人敘事旅途天數；另提供車馬大院與漕船付費搭乘。
3. **「資格全府等效，組織與設施權限分流」模型（`Q2` / `WORLD-04`）**：
   - **專業資格（`qualification`）等效**：在六縣通過考核者，核發與府城**完全相同的法定資格代碼**（`lic_diviner`、`lic_escort_guard`、`lic_master_artisan`、`lic_apothecary`），同時於角色 `qualification_issuers` 記錄具體核發機構（如 `"定神靈植道觀（宣道司外派）"`）。依《金石共治盟約》，持縣級資格進入府城同樣視為**已正式立籍 (`formal_resident`)**，且在內城絕靈法網下合法施法、開方或領料。
   - **組織隸屬（`affiliation`）與設施權限（`access`）分流**：縣級考核入籍者隸屬於該組織之**地方分舵**（`branch`），可直接動用本縣分舵設施；若欲動用府城總堂核心設施（如摘星觀象台、千錘地爐坊、披甲兵器庫），須先至府城總堂辦理**「掛單轉錄 (`register_at_headquarters`)」**。
   - **技能傳授一致**：與府城相同，僅啟蒙該道途兩項 Lv.31 基礎核心技能，絕不自動灌頂整條技能樹。
4. **六縣 18 個三道發證機構對齊表（`Q3`）**：

| 縣份 (`county_id`) | 【法】道發證機構 (`lic_diviner`) | 【力】道發證機構 (`lic_escort_guard`) | 【物】道發證機構 (`lic_master_artisan` / `lic_apothecary`) |
| :--- | :--- | :--- | :--- |
| **青河縣 (`qinghe`)** | **定神靈植道觀**（宣道司外派，觀主核發） | **青河水師營校場**（水勇／趟子手黑鐵牌） | **青河洗藥總坊**（採百草分堂分號，核發 `lic_apothecary`） |
| **烈礬縣 (`liefan`)** | **烈礬地火丹房**（觀火受牒度牒） | **烈礬護礦武館**（護礦黑鐵腰牌） | **百工耐火料採辦分舵／官窯**（核發 `lic_master_artisan`） |
| **盤木縣 (`panmu`)** | **盤木山神祠講堂**（山林望氣度牒） | **盤木巡山獵營**（八方武館駐點，山林武卒牌） | **天工木作工棚**（百工機巧分舵，核發 `lic_master_artisan`） |
| **鎮風縣 (`zhenfeng`)**| **鎮風觀星哨台**（邊塞測候度牒） | **八方武館邊關分舵**（軍陣重弓黑鐵腰牌） | **鎮風軍械修造所**（百工邊防分舵，核發 `lic_master_artisan`） |
| **濁水縣 (`zhuoshui`)**| **濁水鎮煞祠**（水澤辟瘴度牒） | **濁水浮橋巡防水寨**（水路護衛腰牌） | **濁水百草毒理棚**（辨毒行醫資格，核發 `lic_apothecary`） |
| **重石縣 (`zhongshi`)**| **重石勘脈堂**（地脈觀象度牒） | **重石開山力士堂**（重甲力士黑鐵牌） | **重石條石總塢**（百工石作分舵，核發 `lic_master_artisan`） |

5. **轄下 12 個村落與具名 NPC（`Q4` & `Q5`）**：12 個村落（蘆花渡、百草坪、紅砂坳、地火堡、青松塢、倒影澗、鷹嘴崖、碎冰堡、泥螺灘、黑水埗、石碾坡、穿山寨）各建 2 間核心房間納入所在縣城；全六縣約 65 位具名 NPC 嚴格遵守防撞規則（禁用單字姓氏 ID）。

### 3. 新手村路徑、三元戰鬥重構、NPC 相位與跨卷伏筆 (`OPEN-03 ~ OPEN-05`)
- **`OPEN-03`（路徑與戰鬥清理）**：黑石鋪正典路徑統一鎖定為 `/d/village/`；舊西幻 `/secure/combat_d.c` 列為 `DERIVED` 必改項目，重構為力／法／物三元招式與 `kee/sen/sp` 消耗；舊 `/area/newbie/` 測試網格與正式世界隔離。
- **`OPEN-04`（NPC 三態生命週期）**：建立 `/daemon/phase_d.c` 列為 `DERIVED` 項目，支援核心具名 NPC 的時辰作息與重大事件相位切換。
- **`OPEN-05`（跨卷伏筆登錄）**：於本基線第四節建立《全書伏筆登錄與 Tier 2~4 終局稀有性門檻表》，確保 `NOV-04` 與 `MYST-05` 在 v1.0 可被獨立審查驗證。

---

## 二、六大領域 37 項正式驗收條件完整追溯矩陣 (`MAINT-02`)

### 標籤與驗收層級定義
- **來源標籤**：`CANON`（已確認世界正典）、`RULE`（已確認世界運作規則）、`DERIVED`（從既有設定推導之必要工程要求）、`QUALITY`（文學與體驗品質要求）、`OPTIONAL`（後續可選擴充）、`OPEN`（待裁決，本表已全數收斂）。
- **驗收層級**：`Level 1`（機器自動化測試直接驗證）、`Level 2`（獨立審查 Agent 依據 Rubric 與反例清單驗證）、`Level 3`（作者創作意圖確認）。

### A. 小說完整性 (`NOV-01 ~ NOV-06`)

| ID | 標籤 | 驗收層級 | 完成條件（v1.0 範圍） | 現有實作與證據位置 | 當前狀態 | 待完成工作包 (`Work Packages`) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **NOV-01** | `CANON` | Level 1 & 2 | 第一卷（Ch.1~38）與第二卷（Ch.39~82）所有規劃章節正文均已完成，無占位符。 | `narrative/chapters/ch0001.md` ~ `ch0038.md` (38/38 完稿)；`narrative/volume2.md` (Ch.39~82 大綱 v1.0 完稿，正文 0/44) | **PARTIAL** | **WP-NOV-1**：依 `volume2.md` v1.0 分五幕撰寫 `ch0039.md` ~ `ch0082.md` 全 44 章正文 |
| **NOV-02** | `CANON` | Level 2 | 五位主角與核心配角（蘇凝霜、陳鎮山、莫三等）具備完整初始處境、關鍵選擇、五維成長與階段性結果。 | `narrative/character_profiles.md`、`narrative/characters/*.md`、`volume1.md`、`volume2.md` §二 | **PARTIAL** | **WP-NOV-2**：於第二卷正文落實五人分途立籍、六縣歷練與四維破境弧線，產出跨章弧線核對報告 |
| **NOV-03** | `RULE` | Level 2 | 重大事件具合理前因、觸發條件與後果，不靠巧合或機械降神。 | `volume1.md`、`volume2.md` §四（路網、證據五欄、三印合符、信用凍結邊界） | **PARTIAL** | **WP-NOV-3**：隨第二卷正文逐幕執行因果鏈審查（核對證據保管鏈與風險天平轉折） |
| **NOV-04** | `CANON` | Level 2 | 重要伏筆與真相有一致揭露順序；跨卷未解伏筆均已登錄為刻意保留。 | 本文件第四節《全書伏筆登錄表》、`shen_ni.md` 六階段、`volume2.md` §一 | **PASS** | 隨第二卷正文完稿逐章勾稽伏筆落點章節 |
| **NOV-05** | `RULE` | Level 1 & 2 | 人物能力、知識、位置、旅行時間、銀兩與持有證物符合當下狀態。 | `docs/novel_mud_audit.md`、`tests/test_ch0001_details.py`、`tests/test_ch06_to_ch12_integration.py` | **PARTIAL** | **WP-NOV-4**：建立第二卷 Ch.39~82 跨章狀態連續性檢查腳本與審查表 |
| **NOV-06** | `QUALITY`| Level 2 & 3 | 正文具備可閱讀之文學品質（感官細節、人物動機、節奏張力、非烏托邦代價），非設定流水帳。 | `narrative/chapters/ch0001.md` ~ `ch0038.md` | **PARTIAL** | **WP-NOV-5**：每幕正文完稿後由獨立審查 Agent 依文學 Rubric 進行反例挑錯與潤飾 |

### B. LPC Mudlib 可運作性 (`MUD-01 ~ MUD-08`)

| ID | 標籤 | 驗收層級 | 完成條件 | 現有實作與證據位置 | 當前狀態 | 待完成工作包 (`Work Packages`) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **MUD-01** | `DERIVED`| Level 1 | 乾淨環境依文件完成建置與啟動。 | `Makefile`、`bin/mudscript`、`forgotten-space/master.c` (`make test` 277/277 通過) | **PASS** | 持續維持 CI / 自動化建置零警告 |
| **MUD-02** | `DERIVED`| Level 1 | 玩家可登入、移動、查看、互動、執行必要指令並正常登出。 | `std/login.c`、`std/user.c`、`cmds/cmd_*.c`、`tests/test_tier1_city.c` | **PASS** | 隨六縣房間擴充同步納入端到端冒煙測試 |
| **MUD-03** | `RULE` | Level 1 | 角色屬性、`kee/sen/sp`、修煉、戰鬥與資源消耗遵循三元力量規則。 | `std/living.c`、`secure/skill_d.c`、`secure/combat_d.c`、`cmds/cmd_perform.c`、`cmds/cmd_practice.c`、`tests/test_combat_classes.c` | **PASS** | **WP-MUD-1（已完成）**：全面重構 `/secure/combat_d.c` 與殘留指令，移除西幻 `fighter/mage/priest` 與 `mp/int/wis`，實裝力／法／物 14 式招式、三角生剋與內城法網檢核 |
| **MUD-04** | `RULE` | Level 1 & 2 | NPC、物品、地圖、任務與玩家狀態按設計互動，無死路。 | Tier 0 主線／煞潮 Phase 1、Tier 1 府城三道轉職已通；待補六縣與會審任務鏈 | **PARTIAL** | **WP-MUD-2**：完成 18 個縣級轉職任務、Vol.1 軍政任務與 Vol.2 四線出府／三方會審任務鏈及 `phase_d.c` |
| **MUD-05** | `DERIVED`| Level 1 | 必要世界狀態與角色進度正確保存、載入，並在重啟後恢復。 | `user.c`、`world_state_d.c`、`nature_d.c` 已存檔；`event_manager.c`、`city_d.c` 與動態物品狀態待補 | **GAP** | **WP-MUD-3**：為 `event_manager.c`、`city_d.c` 及動態物品屬性（證物封存、耐久度）實裝序列化存檔與重啟恢復測試 |
| **MUD-06** | `RULE` | Level 1 | 主要任務、失敗分支、重複觸發、獎勵發放與時限具明確語義。 | `daemon/quest_engine_d.c`、`tests/test_quest_engine_lost_item.py` | **PARTIAL** | **WP-MUD-4**：補齊 72h 居留逾期流民處置、行會請假超時與任務失敗重試測試 |
| **MUD-07** | `DERIVED`| Level 1 | 新增地圖、NPC、任務或物品遵循穩定資料格式與模組介面。 | `std/room.c`、`std/county_room.c`、`std/route_room.c`、`std/npc.c`、`quests/**/*.json` | **PASS** | 透過 `tests/quests/quest_audit.py` 與單元測試持續驗證 |
| **MUD-08** | `DERIVED`| Level 1 & 2 | 無破壞存檔、無限資源或卡死核心流程之重大缺陷。 | `tests/test_loop_decay_and_hunting_chain.py` | **PARTIAL** | **WP-MUD-5**：隔離舊 `/area/newbie/` 測試網格，增補當鋪／錢莊／常平倉平糶防刷邊界測試 |

### C. 小說與 MUD 的一致性 (`CROSS-01 ~ CROSS-06`)

| ID | 標籤 | 驗收層級 | 完成條件 | 現有實作與證據位置 | 當前狀態 | 待完成工作包 (`Work Packages`) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **CROSS-01**| `CANON` | Level 2 | 小說與 MUD 共用同一套已確認的世界正典。 | `world_setting.md`、`tier1_world_operating_model_v0_1.md`、`volume1.md`、`volume2.md` | **PASS** | 維持正典條目 ↔ 程式碼 ↔ 章節雙向索引 |
| **CROSS-02**| `RULE` | Level 1 & 2 | 修行規則、能力限制、資源消耗與進階條件一致。 | `secure/skill_d.c`、`secure/combat_d.c`、`std/living.c`、`daemon/city_d.c` | **PASS** | **WP-MUD-1（已完成）**：三元戰鬥、三柱消耗、三角生剋與內城絕靈法網反噬／度牒豁免已閉合 |
| **CROSS-03**| `RULE` | Level 1 & 2 | 地理、路線、旅行時間與事件時序無重大矛盾。 | `daemon/city_d.c` (`ROUTE_SEGMENTS`)、`daemon/travel_d.c`、`/d/routes/`、`/d/counties/panmu/`、`/d/counties/zhongshi/` | **PARTIAL** | **Batch 1 已完成**（南向雙路網 450里/420里分流、盤木14房、重石14房）；待 **Batch 2 ~ 3** 補齊北向與東西向四縣 |
| **CROSS-04**| `RULE` | Level 2 | 小說角色能力與知識有合理來源，無使用 MUD 不允許之能力。 | `volume1.md`、`volume2.md` §二五維分離表與 §四證據五欄模型 | **PASS** | 於 **WP-NOV-1** 第二卷正文寫作時逐章核驗 |
| **CROSS-05**| `RULE` | Level 1 & 2 | 主角專屬經歷不被當成所有玩家必經事件（多起點與事件範疇分離）。 | `secure/skill_d.c` (`grant_county_initiation`)、`daemon/mysteryd.c` | **PASS** | 透過 **WP-WORLD-1 ~ 3** 實裝六縣 18 個轉職考核任務具體落實 |
| **CROSS-06**| `RULE` | Level 2 | 每個重大跨媒體差異均有明確理由並記錄於案。 | 本文件第三節《跨媒體刻意差異清單》 | **PASS** | 隨後續開發動態維護清單 |

### D. 世界的系統性 (`WORLD-01 ~ WORLD-06`)

| ID | 標籤 | 驗收層級 | 完成條件 | 現有實作與證據位置 | 當前狀態 | 待完成工作包 (`Work Packages`) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **WORLD-01**| `RULE` | Level 1 | 地圖與道路形成連通空間網絡（黑石鋪 13 房＋府城 45 房＋六縣 85 房＋官道 22 房）。 | `/d/village/` (13 房)、`/d/city/` (45 房)、`/d/routes/` (南向 8 房)、`/d/counties/panmu/` (14 房)、`/d/counties/zhongshi/` (14 房) | **PARTIAL** | **Batch 0 & Batch 1 已完成**；待 **Batch 2 ~ 3** 完成其餘四縣（青河、鎮風、烈礬、濁水）與 14 間路網房 |
| **WORLD-02**| `RULE` | Level 1 & 2 | 城鎮、村落、道路與資源點具可解釋功能及相互流向。 | `daemon/world_state_d.c`、`daemon/city_d.c`、`std/county_room.c` | **PARTIAL** | 將六縣市集交易與府城專材長街／常平倉物價動態掛鉤 |
| **WORLD-03**| `RULE` | Level 1 | 官府、行會、商會、宣道司、軍鎮權限邊界清楚（三印合符、三方會審）。 | `daemon/city_d.c` (`POWER_AUTHORITIES`, `check_military_order_auth`, `conduct_tripartite_tribunal`) | **PASS** | 已通過 `test_tier1_city.c` 驗證 |
| **WORLD-04**| `RULE` | Level 1 | 道途、技能、專業資格、組織身分與存取權五維分離（含縣級分舵與總堂掛單分流）。 | `secure/skill_d.c`、`std/living.c` | **PASS** | 已實裝 `grant_county_initiation` 與 `register_at_headquarters` 並通過測試 |
| **WORLD-05**| `RULE` | Level 1 | 世界事件、玩家個人進度與證據保管各有清楚狀態定義。 | `daemon/world_state_d.c`、`daemon/quest_engine_d.c`、`daemon/city_d.c` (`EVIDENCE_REGISTRY`) | **PASS** | 已通過 `test_tier1_city.c` 驗證 |
| **WORLD-06**| `RULE` | Level 1 | 核心遊戲循環在無作者逐次介入下可持續自主運作（含 30 天六縣時鐘跨日推進）。 | `secure/nature_d.c` 跨日驅動 `world_state_d.c` (`advance_county_day("all", 1)`) | **PASS** | 已完成跨日接線並納入長流程模擬測試 |

### E. 奇遇與隱藏歷史 (`MYST-01 ~ MYST-05`)

| ID | 標籤 | 驗收層級 | 完成條件 | 現有實作與證據位置 | 當前狀態 | 待完成工作包 (`Work Packages`) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **MYST-01** | `CANON` | Level 1 | 奇遇具合理發現條件、世界窗口或共鳴機制，不無故出現。 | `daemon/mysteryd.c`、`quests/encounter/enc_*.json`、`tests/test_encounter_system.c` | **PASS** | 隨六縣建置增補青河古河床石閘、重石太古石槨、鬼市九城契版 3 個 Tier 1 奇遇入口 |
| **MYST-02** | `RULE` | Level 1 & 2 | 重大奇遇具後續影響（改變認知、世界狀態、可用線索或未來選擇）。 | `daemon/mysteryd.c` (`personal_event/*`, `fate_points`) | **PARTIAL** | **WP-MYST-1**：於宣道司摘星台、百工千錘坊、商會地下密室掛接 Tier 0 奇遇持有者之專屬共鳴與對話分支 |
| **MYST-03** | `CANON` | Level 2 | 隱藏歷史由多線索逐步拼合，非單一 NPC 直接說出全部真相。 | `quests/encounter/enc_map_fusion.json`、本文件第四節線索依賴圖 | **PASS** | 維持雙來源以上交叉驗證原則 |
| **MYST-04** | `RULE` | Level 1 | 一般成長、普通任務與稀有奇遇具不同獲得機制（窗口＋全服名額＋機緣門檻）。 | `daemon/world_state_d.c` (`windows`, `encounter_slots`)、`tests/test_phase2_encounters.py` | **PASS** | 已通過稀有性窗口與名額測試 |
| **MYST-05** | `CANON` | Level 2 | Tier 4 內容保持真正稀有性，不因完成一般主線而自動取得。 | 本文件第四節《Tier 4 歸墟古道稀有性門檻規格》 | **PASS** | 鎖定跨道途五遺物共鳴＋破除假天道化認知迷障之前置契約 |

### F. 可驗證與可維護性 (`MAINT-01 ~ MAINT-06`)

| ID | 標籤 | 驗收層級 | 完成條件 | 現有實作與證據位置 | 當前狀態 | 待完成工作包 (`Work Packages`) |
| :--- | :---: | :---: | :--- | :--- | :---: | :--- |
| **MAINT-01**| `DERIVED`| Level 1 & 2 | 核心系統、規則、資料格式及啟動方式有文件可查。 | `README.md`、`world_setting.md`、`docs/*.md` | **PASS** | 隨各批次完工同步更新文件 |
| **MAINT-02**| `DERIVED`| Level 2 | 所有必要需求有來源、實作位置及驗收證據。 | 本文件（`docs/traceability_and_scope_baseline.md`） | **PASS** | 隨工作包推進更新狀態欄 |
| **MAINT-03**| `DERIVED`| Level 1 | 核心規則有自動化測試；修正缺陷後可執行回歸測試。 | `make test` (277 項) + `forgotten-space/tests/` (1580+ 項斷言) | **PASS** | 每個工作包均須附帶自動化測試 |
| **MAINT-04**| `DERIVED`| Level 1 | 重要創作決策、規則變更與正典變更有版本紀錄。 | Git 歷史、`tier1_world_operating_model_v0_1.md`、`volume2.md` §九、本文件 §一 | **PASS** | 持續以 Git Commit 與 ADR 記錄變更 |
| **MAINT-05**| `DERIVED`| Level 1 | 系統中斷後可恢復，失敗任務可定位，重試具冪等性不重複發獎。 | `daemon/quest_engine_d.c` 防重入機制 | **PARTIAL** | **WP-MUD-3**：結合跨重啟存檔測試，新增故障恢復與獎勵冪等性專項測試 |
| **MAINT-06**| `DERIVED`| Level 2 | 未解決重大問題、待決設定與已知限制有明確清單。 | 本文件第五節《工作包派工藍圖與已知限制清單》 | **PASS** | 持續追蹤至全數清零 |

---

## 三、跨媒體刻意差異登錄表 (`CROSS-06`)

為確保小說的文學敘事張力與多人連線 MUD 的可玩性互不綁架，以下差異經正式核定為**「刻意設計之跨媒體差異（Intentional Cross-Media Adaptations）」**，不視為設定矛盾：

| 編號 | 項目 | 小說敘事（04 Narratives）表現 | MUD 遊戲系統（02/03 Mudlib）表現 | 設計理由 |
| :--- | :--- | :--- | :--- | :--- |
| **DIFF-01** | **一階立籍起點選擇** | 五位主角在第二卷集中前往金石府城考取一階資格。 | 開放多起點：玩家可在青河、烈礬、盤木、鎮風、濁水、重石六縣之 18 個地方分舵考取完全等效之一階資格（`lic_*`），亦可赴府城總堂報考。 | 小說主角因背負卷一黑石鋪跨縣證據鏈與生死同盟而必須入府城；MUD 玩家則享有完整城鄉生活網絡自由度（`P0-2`）。 |
| **DIFF-02** | **縣際長途旅行時間** | 數百里官道需耗時 2～8 日（如東線盤木道 450 里押運重車耗時十日），期間發生驛站夜毒、家屬對質等章節事件。 | 透過 `/d/road/` 22 間具名節點房與 `/daemon/travel_d.c` 進行**時間壓縮步進**（每段數秒至十餘秒），扣除相應精力飲食並累加角色個人「敘事旅途天數」，不強迫玩家在線上枯等數十小時，亦不快轉全服共用時鐘。 | 多人連線環境下全服共用同一 `nature_d` 時鐘，無法因單一玩家趕路而快轉全服時間（`Q1`）。 |
| **DIFF-03** | **蘇凝霜的位置與信印接應** | 蘇凝霜隨五位主角押解證物進入金石府城，駐留商會總堂並於守孝期受內堂制約。 | 蘇凝霜本體常駐於 Tier 0 黑石鋪 `/d/village/shed.c` 供新手玩家觸發第一卷任務；金石府城端由蘇氏舊部大掌櫃**蘇忠**（`/clone/npc/caravan_yard_manager.c`，駐 `/d/city/south/caravan_yard.c`）全權代表核驗蘇氏信印。 | 避免同一具名 NPC 在多玩家處於不同時間線時發生空間分身衝突（`tier1_npc_roster.md` §6）。 |
| **DIFF-04** | **莫三與魯大山的空間常駐** | 第二卷第 73～82 章莫三與魯大山隨黑石鋪證人隊赴府城出庭作證，秋日返鄉。 | 莫三與魯大山常駐黑石鋪（`/d/village/`），府城端透過信物（阿鐵記號、礦工血手印具結書）或事件相位（`PHASE_D`）於會審副本中呈現。 | 保障 Tier 0 新手村玩家的日常互動與救援主線不因高階玩家進度而中斷。 |
| **DIFF-05** | **主角專屬奇遇 vs 全服奇遇窗口** | 五位主角於第一卷破曉各自觸發唯一太古遺物共鳴。 | 採用 `WORLD_STATE_D` 獨立奇遇窗口（`windows`）＋全服限量名額（`encounter_slots`）＋機緣／身世門檻，未搶得唯一神物之玩家仍可獲得拓片或次級線索，不卡死主線晉升。 | 兼顧奇遇稀有性（`MYST-01~05`）與多人遊戲公平性。 |

---

## 四、全書伏筆登錄與 Tier 2～4 終局稀有性門檻表 (`NOV-04`、`MYST-03`、`MYST-05`)

### 4.1 跨卷核心伏筆與揭露順序表 (`Foreshadowing Registry`)

| 伏筆編號 | 伏筆內容與核心載體 | 初登場（Tier 0 / Vol.1） | 發展與驗證（Tier 1 / Vol.2） | 後續揭露規劃（Tier 2~4 / Vol.3~5，v1.0 刻意保留） |
| :--- | :--- | :--- | :--- | :--- |
| **FS-01** | **太古逆星斷碑與周天星軌逆轉** | Ch.1 顧玄於南谷溪灘洗出逆行蒼龍七宿石刻（`stream_stele`） | Ch.50、53 柳清虛入宣道司摘星台，星淵暗中察覺逆星軌，清虛藏妥拓片；Ch.81 無名遊歷道士見拓片色變 | **Vol.3（Tier 2）** 於紫霄道宮古星台證實大清洗曾以星陣篡改天象；**Vol.5（Tier 4）** 歸墟星塚解開逆星座標。 |
| **FS-02** | **太古不融黑鐵與失落工聖機械** | Ch.2 林鐵生於粗礦核砸出萬度地火不融之微型齒輪構件（`forge_ancient_black_iron`） | Ch.47、54 莫錘與歐陽大師檢視黑鐵公差；Ch.79 鐵生藉黑鐵微米公差領悟「百工格物心眼」破障；Ch.81 名山採辦經生高價求購遭拒 | **Vol.3（Tier 2）** 千機百巧門證實為太古「破界機關城」核心；**Vol.4~5** 用於開啟洞天與歸墟封門。 |
| **FS-03** | **太古戰神獵獸圖騰與荒古純陽血脈** | Ch.3 燕隼於化骨泥沼以暴熊濁血喚醒圖騰玄柱（`commune_forest_totem`） | Ch.49、52、80 霸山傳授磐石樁與真氣逆沖，壓制煞氣反噬；Ch.62 查獲大伯燕山五年前持【走山令】入外荒舊檔 | **Vol.3（Tier 2）** 霸王崩山宗與北方外荒深處尋獲燕山蹤跡，揭開荒古力修不假外物、以肉身抗天劫之秘。 |
| **FS-04** | **清修道化玉晶遺骸與「天羅活體牢籠」** | Ch.4 枯木老道揭露玉皇頂晶化慘劇，柳清虛窺天見暗灰星空鎖鏈（`stargaze_altar`） | Ch.50、53 宣道司將「假天道化」列為禁題，清虛以實證辯證過關；Ch.80 靜心閣斬破心魔 | **Vol.3（Tier 2）** 目睹名山高階長老「登仙實為道化結晶」；**Vol.4（Tier 3）** 揭曉洞天實為古大能躲避天羅收割之避難所。 |
| **FS-05** | **【萬物行商・天門引】與沈泥「雲記」舊約** | Ch.5 沈泥於廢柴房掘出黑鐵皮青金星紋古令（`search_shed_wood`）與「沈雲妮」玉佩 | Ch.51 當鋪死帳見雲妮名（階段二）→ Ch.65 濁水老帳房核實「雲記」旁支與文承敬舊案（階段三）→ Ch.73 觸發密室玄鐵重門共鳴 → Ch.77 鬼市購九城青銅契版 → Ch.78 莫三吐露太古舊約（階段四～五起點） | **Vol.3~4** 憑商會通行信印與天門引串聯九大仙城古商道遺址，集齊認證栓開啟玄鐵重門，完成階段五「舊約全文」與階段六「更名與贏家」。 |
| **FS-06** | **地煞血精晶錠的終極買家** | Ch.15~36 北崖古礦盜採血精、丙字柒號坩堝除渣 | Ch.75 三方會審扳倒府城保護傘錢百川，但軍器局更上層買家被按下；Ch.77 鬼市揭露最終買家為「無世俗門派標記之名山採辦經生」 | **Vol.3（Tier 2）** 揭曉名山宗門高層暗中收購凡間高濃度地煞血精，用以延緩自身「道化結晶」或餵養護山靈獸。 |
| **FS-07** | **六縣地底史前遺構（青河石閘／重石石槨）** | 無（Tier 1 新增區域線索） | Ch.59/66 及六縣 30 天時鐘 Stage 4：青河潰壩沖出半截史前石閘、重石採石深溝切穿太古石槨氣孔；Ch.82 五件太古殘片同時朝北方發熱共鳴 | **Vol.3~5** 證實整個金石府與八百里落龍古脈實為太古九城之一的外圍陣基。 |

### 4.2 Tier 4（禁忌古道／歸墟殘塚）稀有性與解鎖門檻規格 (`MYST-05`)
為確保 Tier 4 內容在整個遊戲生命週期中維持真正稀有性（絕不因完成一般主線或刷滿等級而自動取得）：
1. **非主線保送原則**：一般玩家完成 Tier 0 → Tier 1 → Tier 2 → Tier 3 主線可晉升至三階洞天宗師，但**不會自動獲得 Tier 4 歸墟古道座標或入場資格**。
2. **複合解鎖三要件**：
   - **要件一（多源歷史拼圖 `MYST-03`）**：須跨越至少三個區域收集史前殘片（如太古逆星拓片、不融黑鐵、天門引共鳴契版、青河史前石閘銘文、重石石槨拓印），完成 `enc_map_fusion` 級別的跨道途考據拼合。
   - **要件二（三元破障共鳴）**：須由具備力、法、物三道不同高階領悟之行者協同（或自身堪破三元同源之謎），在特定天時窗口（`WORLD_STATE_D` 極罕見之歸墟潮汐窗口）引動共鳴。
   - **要件三（認知迷障勘破）**：角色須曾在道化心魔叩問中選擇「實證逆命」而非「順天道化」，具備獨立的 `personal_event/pierced_false_heaven` 標記。

---

## 五、邁向 `Release v1.0` 的模組化派工藍圖 (`Work Packages`)

為達成 [completed-spec.md](file:///home/wade/src/github/mudscript/forgotten-space/docs/completed-spec.md#L190-L201) 的五道最終交付閘門，將所有 `PARTIAL` / `GAP` 項目拆解為以下可獨立執行與驗收的工作包：

### 階段一：Tier 1 城鄉路網與六縣等效資格系統（對應 `six_county_network_plan.md`）
- **批次 0（底層基類與等效資格核心引擎）——【✅ 已完成並通過測試】**
  - 建立 `/std/county_room.c`（對接 `WORLD_STATE_D` Stage 1~4 動態描述與地方物價）與 `/std/route_room.c`（對接 `CITY_D` `ROUTE_SEGMENTS`）。
  - 建立 `/daemon/travel_d.c`（處理 12 條標準路段的季節封路、重車禁行、精力飲食消耗、壓縮步進與個人旅途天數累計）。
  - 擴充 `/std/living.c` 與 `/secure/skill_d.c`：實裝 6 縣 × 3 道＝18 個地方考核入口定義、`grant_county_initiation(me, county_id, path)`、發證機構記錄 `query_qualification_issuer(lic_id)`、以及分舵與總堂「掛單 (`register_at_headquarters`)」權限分流。
  - 於 `/secure/nature_d.c` 接線跨日自動推進 `WORLD_STATE_D->advance_county_day("all", 1)`。
- **批次 1（南線雙縣：盤木縣 14 房 ＋ 重石縣 14 房 ＋ 東西兩線官道 8 節點 ＋ 6 處地方考場）——【✅ 已完成並通過測試】**
  - 修正黑石鋪 `square.c` 直通府城 `south_road.c` 的跳躍，打通東線盤木道（450 里，通重車）與西線重石棧道（420 里，禁重車）雙線匯入南關，實裝 36 間新房間與 6 處地方考場。
- **批次 2（西北雙縣：青河縣 14 房 ＋ 鎮風縣 14 房 ＋ 水陸官道 7 節點 ＋ 22 NPC ＋ 6 考核）**
  - 打通青河水陸兩線（含蘆花渡漕船與史前石閘奇遇）與北塞鎮風天風谷線。
- **批次 3（東南雙縣：烈礬縣 14 房 ＋ 濁水縣 15 房 ＋ 山道與地下暗河 7 節點 ＋ 21 NPC ＋ 6 考核）**
  - 打通東北烈礬紅石道與東南濁水浮橋／地下溶洞暗河（接駁府城 `/d/city/under/drain_gate.c`）。

### 階段二：Mudlib 核心系統閉環（`WP-MUD-1 ~ 5`）
- **`WP-MUD-1`（三元戰鬥系統重構）——【✅ 已完成並通過測試】**：重構 `/secure/combat_d.c`、`/secure/guild_d.c`、`/cmds/cmd_perform.c`、`/cmds/cmd_practice.c`、`/cmds/cmd_info.c`，徹底移除西幻 `fighter/mage/priest` 與 `mp/int/wis` 殘留，全面實裝力道、法道、物道之 14 式戰鬥招式、三角生剋與 `kee/sen/sp` 消耗。
- **`WP-MUD-2`（NPC 三態生命週期與跨區任務鏈）**：實裝 `/daemon/phase_d.c`，並完成 Vol.1 軍政博弈與 Vol.2 四線出府／西水門搶修／暗渠公證取證／三方會審任務 JSON。
- **`WP-MUD-3 ~ 5`（跨重啟持久化與冪等性防刷驗證）**：為 `event_manager.c`、`city_d.c` 與動態證物屬性補齊 `save_object` / `restore_object`，隔離舊 `/area/newbie/` 網格，並通過重啟恢復與冪等性測試。

### 階段三：小說第二卷【金石風雲】全 44 章正文撰寫與雙軌審查（`WP-NOV-1 ~ 5`）
- 按五幕結構（第一幕 Ch.39~46、第二幕 Ch.47~57、第三幕 Ch.58~67、第四幕 Ch.68~76、第五幕 Ch.77~82）分五批次撰寫 `forgotten-space/narrative/chapters/ch0039.md` ~ `ch0082.md`。
- 每幕完成後執行 `Level 1`（連續性腳本檢查）與 `Level 2`（獨立審查 Agent 對照 `volume2.md` v1.0 與本基線矩陣進行反例審查）。
