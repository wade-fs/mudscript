# 《遺忘的世界》(forgotten-space) 世界擴展與真實化統合藍圖 (TODO)

> **核心憲章**：
> 1. **「敘事世界是生活世界的一個切面，而不是生活世界的全部。」**——小說不必寫出整個世界，Mudlib 也不應要求小說替它提供所有內容；未見於小說之職業、階層、地點、物產、傳聞與季節活動，只要不與前三卷正典衝突，皆應自主存在。
> 2. **「不要把鮮活度等同於 NPC 數量。」**——如果每個房間只放一個 NPC、一句對話、幾個指令，最後只是把「空房間」變成「NPC 展示間」。**真正的生活感來自活動、時間變化、社會階層與經濟因果。**

---

## 一、目前進度基準（2026-11-22 實測盤點）

* **總房間數**：`288` 間（`city`: 75、`counties`: 91、`village`: 22、`sects`: 36、`routes`: 22、`yunjin`: 21、`wastes`: 20、`realm`: 1）
* **具備五感描寫**：`288 / 288 (100%)`（全站八大區域 `city` 75/75、`counties` 91/91、`sects` 36/36、`village` 22/22、`routes` 22/22、`yunjin` 21/21、`wastes` 20/20、`realm` 1/1 皆已達 100%，並由 `world_liveness_audit.py` 硬性鎖定）
* **具備住民／NPC**：`257 / 288`（含 `PHASE_D` **23 名**具十二時辰作息與移動劇本之角色）
* **真・空房率（無 S/N/A/Item）**：`0 / 288`（**全站 20 間空房已全數清零**）
* **非主線平凡支線任務**：`24` 條（`quests/side/side_*.json`）
* **自動化驗證**：`world_liveness_audit.py`、`quest_audit.py`、`novel_mud_sync_audit.py`、`make test`、以及 `forgotten-space` 全套 **3171/3171** 測試通過（含 `test_world_liveness.c` **351/351**）。

### 已完成項目

#### Phase 1：骨架與基礎活化（已完成）
- [x] `std/county_room.c`：六縣動態五感、建築對應住民自動生成（`county_innkeeper`、`county_broker`、`county_worker`、`county_bailiff`）、客舍 `rest`/`drink` 與市集 `browse`/`appraise`。
- [x] `std/route_room.c`：官道地貌五感、`survey`/`路況`、`rest`/`drink`、關卡 `check_pass`/`盤查`、`route_traveler` 過客與 `route_guard` 關卡巡檢卒。
- [x] 首批 18 間生活支翼與 13 位庶民 NPC、5 條日常支線、`world_liveness_audit.py` 與 `test_world_liveness.c`。

#### Phase 2A（前兩批）：空間與具名生活場所補完（已完成）
- [x] **Tier 0 黑石鋪全區五感與村社機能補完**（22 間，100% 五感覆蓋）：新增 `village_school.c`（宋秀才）、`peddler_corner.c`（貨郎胡二）、`smokehouse_shed.c`（老套手錢七），補齊其餘 7 間舊房五感。
- [x] **六縣專屬具名生活支翼**（85 → 91 間）：
  - `zhenfeng/garrison_lane.c`（馮嫂縫冬襖）
  - `qinghe/river_tea_shed.c`（老船工柳伯）＋ `ferry_dock.c` 量水尺 `check_gauge`
  - `panmu/timber_wharf.c`（放排老把式林四）
  - `zhongshi/carter_yard.c`（老車匠沈鐵頭）
  - `zhuoshui/ginger_soup_stall.c`（橋工老譚）
  - `liefan/miners_tea_shed.c`（老礦工羅七）
- [x] **Tier 1 金石府城生活功能區擴充**（71 → 75 間）：`wine_tavern.c`（跑商陳大牙與 `trade goods`）、`dye_alley.c`（染坊窄巷）、`charity_clinic_shed.c`（周伯施藥義棚）、`fish_market.c`（魚販劉三娘）。
- [x] **Tier 2 雲津與北荒庶民空間**（雲津 19 → 21、北荒 19 → 20）：`temple_tea_fair.c`（茶市老孫頭）、`dock_coolie_lane.c`（苦力竹籌對帳）、`frost_hunter_camp.c`（牧戶烏蘭尋黃羊）。
- [x] **非主線日常支線擴充至 18 條 + `RUMOR_D` 平民瑣事流言**（`query_slice_of_life_rumor()`）。

---

## 二、接續工作順序（整合 `thinking.md` 架構重整）

> 為避免先建出大量靜態「NPC 展示間」再回頭返工，後續將交錯推進 **「空間補完 (2A) → 世界運作機制 (2B) → 經濟與日常互動 (3) → 鮮活度 2.0 稽核與小說校對 (4) → 第四卷 (5)」**，並嚴格採行**「單一區域小批次 7 步工作法」**：
> `1. 盤點現況 → 2. 查對前三卷正典 → 3. 列擴建清單 → 4. 實作程式碼 → 5. 跑測試與稽核 → 6. 更新 CANON_CHANGELOG.md → 7. 完成才進下一區`

### Phase 2A（續）：全站空房歸零與五感盲區收尾
- [x] **消滅現存 20 間空房（已達成：`0 / 288`，並由 `world_liveness_audit.py` 硬性鎖定）**
  - [x] `d/city/`（8 間空房清零：`south_road`、`dao_gate`、`ruins_hall`、`shang_secret`、`wall_path_e/n/s/w`）
  - [x] `d/yunjin/`（5 間空房清零＋全區 **21/21 100% 五感覆蓋**）
  - [x] `d/sects/`（4 間空房清零：`danding/gate`、`tiangong/gate`、`forge_yard`、`vault_four`）
  - [x] `d/wastes/`（3 間空房清零＋全區 **20/20 100% 五感覆蓋**）
- [x] **舊城區與四大宗門其餘房間五感覆寫補齊（已達成 `288 / 288 (100%)`，並由 `world_liveness_audit.py` 硬性鎖定）**：
  - [x] `d/city/` 剩餘無顯式五感舊房（53 間全數補齊）：區隔內城／外城／四牆／暗渠階層感官差異（`city` 75/75）
  - [x] `d/sects/` 剩餘無顯式五感舊房（24 間全數補齊）：補齊八荒、丹鼎、太清、天工各宗外門雜役與練功場所環境體感與門內生態（`sects` 36/36）

### Phase 2B：世界運作機制（已完成 — 從「靜態展示間」進化為「會呼吸的活世界」）
> 核心原則：一個有五個 NPC 站樁的房間，不一定比兩個正在幹活、彼此對話、隨時間退場的 NPC 真實。

1. **世界的時間維度（日夜時辰 × 季節節律）**
   - [x] 串接現有 `nature_d.c` 時辰與季節系統（新增 `season_override` 與全站 `PHASE_D->query_room_rhythm_line()`），建立房間／區域的「時段環境描寫與活動相位」：
     - **清晨**：魚市開秤、商販備貨、貨郎整理擔子、挑夫上工。
     - **上午**：大集買賣、渡船擺渡、礦洞／石場／林班採料作業。
     - **午後**：工坊鍛打、宗門外門操練、書院／蒙館誦讀。
     - **黃昏**：市集收攤、礦工與苦力下工去茶棚喝粗茶、渡口船隻收纜。
     - **夜間**：街坊宵禁、酒肆喝酒吹牛、客舍避寒、暗巷與鬼市交易、城防巡夜。
     - **季節**：冬季皮襖／木炭／老薑湯需求與價格上升，北荒與高寒山道受風雪阻斷（`std/route_room.c` 實時顯示當季封道實警）。

2. **NPC 自主生活、作息移動與 NPC-to-NPC 關係網**
   - [x] `PHASE_D` 擴充至 23 名作息註冊 NPC（含 10 名庶民勞動角色與兩名專職移動 NPC：`roaming_porter` 阿福、`qinghe_herb_woman` 翠嬸），依時段在生活動線間移動並反映礦難停工失業狀態（如礦工早上在礦區、傍晚在茶棚喝茶、礦場停工時滯留茶棚嘆氣）。
   - [x] 在關鍵樞紐（**青河渡口**、**黑石青石街市**、**南關流民矮巷**、**烈礬礦工粗茶棚**、**雲津冰河碼頭**、**城南老酒肆**）建立多節拍 NPC-to-NPC 可觀察互動事件（支援 `observe` / `旁觀` 指令與 `nature_d` 定時脈動）。

3. **地方經濟的真實因果鏈（升級 `WORLD_STATE_D` 與 `RUMOR_D`）**
   - [x] 讓物價指數變動具備明確的 5 大**因果觸發源**（`landslide_rain`、`mine_shutdown`、`river_surge_sluice`、`gate_tax_lockdown`、`northern_cold_snap`），同步驅動 `market_special_buyer.c` 牌價看板（含皮襖／木炭／老薑湯／糙米民生欄）與 `RUMOR_D->query_causal_economy_rumor()`，讓玩家理解「為什麼漲價」。

4. **完整的社會階層四維度體驗（不只是地理分區）**
   - [x] 於 `CITY_D` 建立 `query_social_tier()` 四維度結構，並於 `score` 與外城／內城關鍵設施落地身分、生計、資源與流動差異：
     - **身分／流動**：無籍流民 -> 《金石南關暫住牌》（`/clone/item/temp_residency_pass.c`，`tenement_alley` `register_pass`）-> 三條保書（學塾青衿／杏林試藥／車馬短褐）-> 正式匠／醫／武／道籍。
     - **住房與飲食落差**：`tenement_alley.c` 土坯通鋪（2 文）＋粗米菜粥（3 文）vs `inn_main.c` 上房雅間（50 文，拒絕無籍流民）。
     - **醫療落差**：`charity_clinic_shed.c` 免費施藥義診（不問戶籍）vs `clinic.c` 杏林醫館診治（50 文並查驗居留身分）。

---

### Phase 3A：基礎跑商貨盤與區域支線擴充（已完成）
- [x] **跨區跑商貨盤初版**：建立 `/clone/item/trade_cargo.c` 與 `WORLD_STATE_D` 六大地區特產貨盤（`panmu_timber`、`liefan_alum`、`zhongshi_iron`、`qinghe_herbs`、`zhenfeng_pelt`、`blackstone_charcoal`），於六縣牙行（`county_broker.c`）、黑石鋪貨棚（`peddler_corner.c`）、金石老酒肆（`wine_tavern.c`）與雲津三宗交割廳（`exchange_hall.c`）串接 `cargo list / buy / sell` 與同產地防刷檢核。
- [x] **補齊六縣、官道與宗門生活支線（18 → 24 條日常支線）**：
  - [x] 各縣委託：`side_county_liefan_credit_grain`（停工賒糧）、`side_county_qinghe_mooring`（搶修纜樁）、`side_county_panmu_charcoal_sled`（冬寒送炭）。
  - [x] 官道與宗門：`side_route_winter_hearth`（寒夜借火）、`side_route_wheel_repair`（修補車輪）、`side_sect_bahuang_ration_tally`（八荒伙房整理家書）。
- [x] **`RUMOR_D` 語氣分層初版**：實作 `query_tiered_folk_rumor()` 與 `std/npc.c` 對話串接，區分 `peasant_boatman`（民俗絮語）與 `merchant_artisan`（供需實務判斷）。

### Phase 3B / 3D：因果經濟閉環、持續性與資訊品質深化（已完成 — 整合 `thinking.md` 核心規格）
> 優先順序：**P0 跨區跑商庫存／風險／防套利** → **P1 Phase 3D 世界經濟持續性** → **P2 可拒絕／地方文化日常參與** → **P3 `RUMOR_D` 六維資訊品質** → **P4 Phase 4 鮮活度 2.0**

1. **P0：因果跨區跑商完整五段經濟循環（已完成）**
   - [x] **真實庫存與動態供需定價**：`WORLD_STATE_D` 建立各地 `market_stocks`（`0..12`），以產地稀缺度、跨區運距、因果急缺與飽和壓價動態計算買賣價格，禁止無上限憑空買賣。
   - [x] **買賣真正反哺世界價格與供應**：採購即扣減產地庫存（售罄則停賣待補）；交付後增加目的地庫存並壓低後續收購牌價。
   - [x] **真實運輸成本與虧損風險**：`trade_cargo.c` 追蹤成色與無引關稅火印；經 `route_room.c` 遇暴雨（`storm`/`landslide_rain`）損耗成色、遇 `gate_tax_lockdown` 無路引補課兩成關稅，交割結果可能大賺亦可能真實虧損。

2. **P1：Phase 3D — 世界經濟的持續性（Persistent Living Economy）（已完成）**
   - [x] **產地再生與 NPC 商販自主行為**：`economic_batch_tick()` 依天災／停工狀態執行產地補貨與消費扣減，並自動更新 `merchant_strategies`（如丹鼎藥商於青河阻斷時改道徵購、金石皮貨行於寒潮切換 `surge_bidding`）。
   - [x] **離線與重啟持久化一致性**：`market_stocks`、`merchant_strategies` 與 `last_settled_gtime` 全面持久化並具冪等時間戳防重入，重啟後不重複結算不亂帳。

3. **P2：日常支線進化 —「參與地方生活」與「選擇不介入」機制（已完成）**
   - [x] `miners_tea_shed.c` 實裝 `decline`／`拒絕` 非強制路徑：玩家可婉拒作保賒糧而不受懲罰，礦工家屬處境持續存在；[earth_shrine.c](file:///home/wade/src/github/mudscript/forgotten-space/d/village/earth_shrine.c)（`offer_rite`／社祭）與 [temple_tea_fair.c](file:///home/wade/src/github/mudscript/forgotten-space/d/yunjin/temple_tea_fair.c)（`beat_drum`／敲社鼓）補齊地方文化參與維度。

4. **P3：`RUMOR_D` 結構化六維資訊品質（交叉驗證真相）（已完成）**
   - [x] `RUMOR_D->query_cross_check_rumors()` 全面產出含 `source`、`event_id`、`credibility`、`region`、`timestamp`、`is_stale` 六維欄位之五方視角傳聞（烈礬礦場停工五方口徑、北荒寒潮五方口徑、青河截水口徑），並接線至廟會茶攤 `tea_gossip` / `聽茶客`。

5. **Phase 3 端對端十步驗收場景（已完成）**
   - [x] 於 [test_world_liveness.c](file:///home/wade/src/github/mudscript/forgotten-space/tests/test_world_liveness.c) 完成十步寒潮經濟閉環、運輸虧損風險、防重入結算與過時標記自動化驗收。

---

### Phase 4：世界鮮活度 2.0 稽核與前三卷小說交叉審查（已完成）
- [x] **升級 [world_liveness_audit.py](file:///home/wade/src/github/mudscript/forgotten-space/tests/quests/world_liveness_audit.py) 至 2.0 規範**：
  - [x] 檢核房間「真・空房率 = 0%」與「五感覆寫 = 100%」。
  - [x] 新增鮮活度深度指標稽核：
    - NPC 工作與活動時段（`PHASE_D` 23 名作息角色＋目標房間驗證＋30 位庶民 NPC `add_response` 互動檢核）
    - NPC 社會關係與多節拍樞紐互動劇本（`PHASE_D` 6 大樞紐 `hub_scenes`＋`relationships`＋`do_observe_scene`）
    - 房間隨日夜／季節／地方經濟階段動態變化（`query_room_rhythm_line`、`set_season_override`、`county_room`/`route_room`）
    - 地點真實經濟活動與 6D 資訊品質（`market_stocks`、`economic_batch_tick`、`merchant_strategies`、`query_social_tier`、`query_cross_check_rumors`）
    - 檢查全站 288 間房 `set_long` 提及之指令動詞於房間／NPC 皆可實際互動（`set_long cmd mismatches: 0`）
- [x] **前三卷小說 ↔ Mudlib 雙向反哺審查**：
  - [x] 核對 `narrative/chapters/volume1`～`volume3`（黑石鋪、六縣、金石府城、雲津、三宗、北荒）里程（東線盤木 450 里＝190+260、西線重石 420 里＝180+240、烈礬 320 里、雲津北行 800 里）、時序與稱謂一致，並於 [ch0002.md](file:///home/wade/src/github/mudscript/forgotten-space/narrative/chapters/volume1/ch0002.md)、[ch0043.md](file:///home/wade/src/github/mudscript/forgotten-space/narrative/chapters/volume2/ch0043.md) 與 [ch0084.md](file:///home/wade/src/github/mudscript/forgotten-space/narrative/chapters/volume3/ch0084.md) 補入庶民市井生活肌理反哺。
  - [x] 同步更新 [canon_sync_matrix.json](file:///home/wade/src/github/mudscript/forgotten-space/data/canon_sync_matrix.json)（新增 `living_world_folk_layer`）、[CANON_CHANGELOG.md](file:///home/wade/src/github/mudscript/forgotten-space/docs/CANON_CHANGELOG.md) 與 [novel_mud_sync_audit.py](file:///home/wade/src/github/mudscript/forgotten-space/tests/quests/novel_mud_sync_audit.py)。

---

### Phase 5：銜接第四卷（Tier 3 異界洞天篇）
- [ ] 確認凡間前三卷已具備獨立生命力後，再展開：
  - [ ] `/d/realm/` 四大分區實裝（`edge/`、`taixu/`、`zhanzu/`、`wanwu/`），落實 `K × U` 機制與高代價雙向信標。
  - [ ] 依 [narrative/volume4.md](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume4.md) 撰寫《第四卷》第 127～170 章正文。
