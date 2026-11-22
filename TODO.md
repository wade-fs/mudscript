# 《遺忘的世界》(forgotten-space) 擴大世界真實度與前三卷整合計畫 TODO

> **定位與核心原則**：「世界必須比小說大」。  
> 小說為了敘事節奏只能剪裁五位少年走過的地點與見過的人；但 Mudlib 是空間載體，不能只做成「小說的插圖版」或只剩下「劇情走廊」。因此優先於展開《第四卷》正文（`narrative/volume4.md`）之前，先回頭全面審查前三卷與 `forgotten-space/` Mudlib，採取**「先填血肉、再補生活支翼，而不只是複製空房間」**的路線，讓凡間世界具備獨立呼吸感、底層煙火氣與真實社會階層。

---

## 一、現況基準與階段總覽

### 已完成（Phase 1：骨架建立與示範樣板，待提交 commit）
> 2026-11-22 實作並於斷電復原後通過全部驗證（`world_liveness_audit.py`、`quest_audit.py`、`novel_mud_sync_audit.py`、`make test` 277/277、`forgotten-space` 全套 2942/2942）。

- [x] **六縣與官道通用基底活化**
  - [x] [std/county_room.c](file:///home/wade/src/github/mudscript/forgotten-space/std/county_room.c)：依六縣風土自動注入 `query_touch` / `query_smell` / `query_listen`，依建築類型自動生成地方住民（`county_innkeeper`、`county_broker`、`county_worker`、`county_bailiff`），實裝客舍歇腳飲食（`rest`/`drink`）與市集牙行行情（`browse`/`appraise`）。
  - [x] [std/route_room.c](file:///home/wade/src/github/mudscript/forgotten-space/std/route_room.c)：依官道地貌自動生成五感描寫與動態過路旅人（`route_traveler`）。
- [x] **新增 18 間生活支翼房間（總房間數 254 → 272 間）**
  - [x] Tier 0 黑石鋪（13 → 19 間）：`chen_grain_shop.c`、`old_granary_yard.c`、`wash_bank.c`、`south_quarry.c`、`earth_shrine.c`、`lumber_slope.c`
  - [x] Tier 1 金石府城（67 → 71 間）：`tenement_alley.c`、`tea_alley.c`、`river_wharf.c`、`scrap_yard.c`
  - [x] Tier 2 三宗與雲津（29+18 → 36+19 間）：太清 `scripture_copy_hall.c` / `outer_dormitory.c`、丹鼎 `outer_herb_terrace.c` / `sect_refectory.c`、天工 `apprentice_shed.c` / `slag_pit.c`、八荒 `outer_barracks.c`、雲津 `river_wharf.c`
- [x] **新增 13 位常駐庶民／雜役 NPC**（`clone/npc/folk/*.c`：`chen_grain_owner`、`wang_washerwoman`、`zhou_quarryman`、`sun_old_carter`、`tea_doctor_lin`、`taiqing_copy_senior`、`danding_cook_nun`、`yunjin_wharf_master`、`county_*`、`route_traveler`）
- [x] **新增 5 條「與五主角主線無關」的市井日常支線任務**（`quests/side/side_*.json`）
  - `side_village_grain_errand`（陳記雜糧・鄰里勻米）
  - `side_village_charcoal_stove`（炭窯石坑・冬前存炭）
  - `side_city_vagrant_letter`（無籍短巷・一紙平安）
  - `side_county_liefan_mungbean`（赤岩客舍・井水綠豆湯）
  - `side_sect_copy_relief`（外門抄經・寒衣粥飯）
- [x] **世界鮮活度體檢與自動化測試**
  - [x] `tests/quests/world_liveness_audit.py`（全圖出口對稱、感官與 NPC 覆蓋盤點）
  - [x] `tests/test_world_liveness.c`（已從斷電中復原並修正，122/122 assertions 全數通過）

---

## 二、後續擴建待辦（Phase 2 ～ Phase 5）

### Phase 2：全面消滅「布景板房間」——分區擴建與具名寫實化
目前各區仍有明顯「僅靠基底通用 NPC 撐場、缺乏獨立地點感或生活支翼」的缺口（盤點基準：總房數 272 間）：

1. **六縣城鎮深度血肉化（`d/counties/` 目前 85 間：explicit NPC=0、explicit sensory=0、action=0）**
   - [ ] 為六縣（`liefan`、`qinghe`、`panmu`、`zhenfeng`、`zhongshi`、`zhuoshui`）逐縣補寫**具名地方小人物與專屬房間覆寫**，不再只依賴通用 `county_*` 模板。
   - [ ] 補齊各縣專屬生活物資買賣與功能性互動（對應各縣背景）：
     - [ ] **鎮風縣（`zhenfeng`）**：皮襖與邊軍冬衣舖、守軍家眷居住巷弄、邊牆補葺工棚。
     - [ ] **青河縣（`qinghe`）**：真實可用船渡系統（青河渡口、撐篙船老大）、採藥散戶曬藥壩、河鮮茶棚。
     - [ ] **盤木縣（`panmu`）**：伐木工棚、木排下水碼頭、松脂烘房與山貨牙行。
     - [ ] **中石縣（`zhongshi`）**：條石採場、車夫歇腳大車店、鐵器修補攤。
     - [ ] **濁水縣（`zhuoshui`）**：沼澤浮橋守橋棚、驅瘴薑湯舖、暗渡小碼頭。
     - [ ] **烈礬縣（`liefan`）**：礦工下工粗茶攤、礬酸洗池與礦工家屬簡陋棚區。
   - [ ] 將六縣建築描述中寫到「朝奉撥算盤」、「攤販叫賣」、「茶博士沏茶」等句子逐一對應實裝 `add_action_rule` 或可互動 NPC／物件，消除「文字有寫、指令按不到」的落差。

2. **官道與荒野生態擴充（`d/routes/` 22 間：explicit NPC=0、action=0；`d/wastes/` 19 間：explicit NPC=7、explicit sensory=1）**
   - [ ] **官道 22 間**：補上路邊野店／茶寮買水買乾糧指令、車夫修輪棚、官道稅卡盤查（呼應《路引》與商道阻塞狀態）、可隨天氣／幕次觸發的官道偶遇小事件。
   - [ ] **北荒與外圍前哨（`d/wastes/` 19 間）**：補齊除主線／事件節點外的一般獵戶營地、凍土採薪點、荒野廢棄哨塔的五感 (`touch`/`smell`/`listen`) 與常駐普通獵人／守望卒。

3. **Tier 0 黑石鋪生活圈補完（`d/village/` 目前 19 間：explicit NPC=15、explicit sensory=6）**
   - [ ] 補齊剩餘房間（13 間舊房中尚未覆寫五感的房間）的 `set_touch`/`set_smell`/`set_listen`。
   - [ ] 擴增「小說未寫、但邊陲山村應有」的日常場所：
     - [ ] 山村簡陋蒙館／私塾（識字老秀才與孩童讀書聲，對照後來主角們走出山村的起點）
     - [ ] 村頭雜貨貨郎攤／鐵匠補鍋棚（可買賣低階日常消耗品：火摺、乾糧、草鞋、麻繩）
     - [ ] 後山獵戶共用的小烘肉寮／藥農曬場

4. **Tier 1 金石府城階層感與市井生活擴充（`d/city/` 目前 71 間：explicit NPC=62、explicit sensory=10、action=13）**
   - [ ] **補齊 61 間舊城區的五感覆寫**：目前全城 71 間僅 10 間有顯式五感，需逐步補齊各坊（東西南北中、外城、暗渠）的季節／階層感官差異。
   - [ ] **新增民間日常功能區**：
     - [ ] 普通民用酒樓／大碗茶館（跑商吹牛、聽取未扭曲／已扭曲之多版本商業情報）
     - [ ] 民間小型施藥義棚／義莊外廊（反映無籍流民看不起大醫館的現實困境）
     - [ ] 布莊、染坊、魚市、城北平民灶巷（展現平民日常衣食住行）
   - [ ] **強化「無籍流民」制度體驗**：在城門、牙行、客舍、工坊之間加入查驗《暫住牌》／《路引》與沒戶籍只能打黑工、睡通鋪的實際生活互動。

5. **Tier 2 雲津商埠與四大宗門日常厚度（`d/sects/` 36 間、`d/yunjin/` 19 間）**
   - [ ] **四大宗門（目前平均每宗 7～10 間，需打破「劇情走廊感」）**：
     - [ ] 補齊外門雜役坊、藏書／圖紙側廂、練功雜場、傷病靜養通鋪、山門外山腳村市。
     - [ ] 讓不走該宗主線的玩家也能在裡頭看到「低階弟子怎麼混日子、挨訓、搶熱飯、偷偷轉賣邊角料」。
   - [ ] **雲津商埠（目前僅 19 間，且僅 1 間顯式五感）**：
     - [ ] 擴充雲津地方廟會茶市、商幫牙行生活巷弄、船塢修補區、南北貨棧卸貨街。
     - [ ] 補齊雲津全區五感覆寫與無關主線的商埠日常互動。

---

### Phase 3：非主線平凡支線任務與跑商物價生態
目前僅有 5 條純生活日常支線（且集中於村／城／烈礬／太清）。需進一步補齊其餘地域與玩法：

- [ ] **跨縣與官道生活支線**：
  - [ ] 幫老車夫在暴雨／山風前搶運官道貨棚（`d/routes/`）
  - [ ] 替牧民／山民找回走失的黃羊或馱騾（`d/wastes/` 或 `d/routes/`）
  - [ ] 其餘五縣各至少 1～2 條純地方民俗支線（如：鎮風縣替邊卒家屬縫補寄送冬衣、青河縣渡船送藥材、盤木縣核對木排號子、中石縣石場修絞盤、濁水縣巡查浮橋纜繩）
- [ ] **府城與宗門／雲津日常支線**：
  - [ ] 在府城或雲津酒館聽跑商吹牛，辨別真假行情後跨縣／跨城倒賣一般物產（如粗鹽、皮襖、松脂、石粉），合法賺取數十到數百文差價（接通 `WORLD_STATE_D` 物價指數）。
  - [ ] 丹鼎宗藥農偷懶採錯草的救火差事、天工坊廢渣坑淘撿可用銅屑的學徒日常、八荒營校場外替老卒修弓弦與寫家書、雲津碼頭替苦力算對帳目防止被克扣工錢。
- [ ] **擴充 `RUMOR_D` 地方市井傳聞**：讓茶寮、碼頭、洗衣淺灘、縣驛的平民 NPC 會聊真實的生活瑣事與對時局的誤解，而不是人人都在複讀大事件。

---

### Phase 4：全站鮮活度硬性稽核與前三卷小說交叉審查
- [ ] **升級 [world_liveness_audit.py](file:///home/wade/src/github/mudscript/forgotten-space/tests/quests/world_liveness_audit.py)**：
  - [ ] 統計並輸出全站「**真・空房率**（無專屬 NPC、無動態住民、無專屬五感、無 `add_action`、無特別物件）」。
  - [ ] 逐區檢核六縣／官道／宗門／府城／雲津／北荒的五感覆蓋率與雙向出口對稱性，設下明確門檻作為回歸檢查。
  - [ ] 檢查房間 `set_long` 中提及的互動動詞或店鋪夥計，避免出現「描述裡有、房間裡空無一物」的落差。
- [ ] **前三卷小說 ↔ Mudlib 雙向反哺審查**：
  - [ ] 對照 `narrative/chapters/volume1`～`volume3`，檢核 Mudlib 新擴出的民間小人物、地方習俗、物價苦衷與地理位置細節是否一致，反過來替前三卷補齊或修正不合地理／生活常理的細節。
  - [ ] 將所有擴建與審查變更同步更新至 [CANON_CHANGELOG.md](file:///home/wade/src/github/mudscript/forgotten-space/docs/CANON_CHANGELOG.md) 與 [novel_mud_sync_audit.py](file:///home/wade/src/github/mudscript/forgotten-space/tests/quests/novel_mud_sync_audit.py)。

---

### Phase 5：銜接第四卷（Tier 3 異界洞天篇）
- [ ] 在前三卷 Mudlib 地圖與人間煙火生態扎實完成後，才回頭展開：
  - [ ] `/d/realm/` 四大分區實裝（`edge/` 灰燼石堡聚落與晶電池黑市、`taixu/` 太虛神宮、`zhanzu/` 戰祖魔殿、`wanwu/` 萬物主機城），落實 `K × U` 規則與「高代價雙向信標通道」。
  - [ ] 依據 [narrative/volume4.md](file:///home/wade/src/github/mudscript/forgotten-space/narrative/volume4.md) 撰寫《第四卷》第 127～170 章正文，讓前面建立的凡間煙火氣成為第四卷「孤懸洞天、遙望故人」最強烈的情感對照。
