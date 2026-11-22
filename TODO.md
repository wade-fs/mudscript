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
* **非主線平凡支線任務**：`18` 條（`quests/side/side_*.json`）
* **自動化驗證**：`world_liveness_audit.py`、`quest_audit.py`、`novel_mud_sync_audit.py`、`make test`、以及 `forgotten-space` 全套 **3136/3136** 測試通過（含 `test_world_liveness.c` **316/316**）。

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

### Phase 3：日常支線與因果經濟互動（深度融入）
- [ ] **因果驅動的跨區跑商系統**：玩家可根據 `WORLD_STATE_D` 當期因果（如暴雨停運、礦難缺炭、寒潮缺襖），在老酒肆、縣城牙行與雲津商棧低買高賣具體貨品，體驗真實風險與利潤。
- [ ] **補齊六縣、官道與宗門後續生活支線**：
  - [ ] 各縣依不同時段或經濟狀態觸發的日常委託（例：礦場停工期替礦工家屬賒糧、水漲期搶修渡口纜樁、冬寒期趕送煤炭皮襖）。
  - [ ] 官道野店茶寮與天氣相關的臨機事件（暴雨護貨、寒夜借火、修補車輪）。
- [ ] **深化 `RUMOR_D` 生活語氣**：區分普通農婦／船夫的誤解絮語與專業跑商／老匠工的實務判斷。

---

### Phase 4：世界鮮活度 2.0 稽核與前三卷小說交叉審查
- [ ] **升級 [world_liveness_audit.py](file:///home/wade/src/github/mudscript/forgotten-space/tests/quests/world_liveness_audit.py) 至 2.0 規範**：
  - [ ] 檢核房間「真・空房率 = 0%」。
  - [ ] 新增鮮活度深度指標稽核：
    - NPC 是否有明確工作與活動時段（`schedule` / 工作行為）
    - NPC 是否存在與其他 NPC 的社會關係或互動訊息
    - 房間是否隨日夜／季節／地方經濟階段改變描述或生態
    - 地點是否具備真實經濟活動（買賣、工錢、借貸、過秤或物價因果）
    - 檢查房間 `set_long` 中提及之店鋪人員與動詞在房間內是否皆可實際互動
- [ ] **前三卷小說 ↔ Mudlib 雙向反哺審查**：
  - [ ] 逐區回查 `narrative/chapters/volume1`～`volume3`（黑石鋪、六縣、金石府城、雲津、三宗、北荒），確認新增平民生活細節與時間軸、地理距離、官制稱謂一致，並反哺修訂前三卷略顯單薄的生活場景。
  - [ ] 同步更新 [CANON_CHANGELOG.md](file:///home/wade/src/github/mudscript/forgotten-space/docs/CANON_CHANGELOG.md) 與 [novel_mud_sync_audit.py](file:///home/wade/src/github/mudscript/forgotten-space/tests/quests/novel_mud_sync_audit.py)。

---

### Phase 5：銜接第四卷（Tier 3 異界洞天篇）
- [ ] 確認凡間前三卷已具備獨立生命力後，再展開：
  - [ ] `/d/realm/` 四大分區實裝（`edge/`、`taixu/`、`zhanzu/`、`wanwu/`），落實 `K × U` 機制與高代價雙向信標。
  - [ ] 依 [narrative/volume4.md](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume4.md) 撰寫《第四卷》第 127～170 章正文。
