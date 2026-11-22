# 《遺忘的世界》凡塵生活層名冊：庶民 NPC、作息樞紐與日常支線總表

> **更新時間**：2026-11-22（對齊 Phase 1–4 World Liveness 2.0 實裝現況）  
> **定位**：彙整 `tier1_npc_roster.md` 與 `tier2_npc_roster.md` 主線具名人物之外的**凡俗生活生態層**，作為 [`mudlib_lpc_mapping.md`](../mudlib_lpc_mapping.md)、[`events/README.md`](../events/README.md) 與開發測試的統一索引。

---

## 一、庶民生活 NPC 名冊（`/clone/npc/folk/*.c` 共 30 名）

| 檔案名稱 | 姓名 | 常見駐點 / 分佈區域 | 生活與機制定位 |
|---|---|---|---|
| `charity_herbalist.c` | 義診老藥工周伯 | `/d/city/outer/charity_clinic_shed.c` | 南關外施藥義棚義診，為無籍流民與貧戶提供低門檻基礎問診（`PHASE_D` 註冊） |
| `chen_grain_owner.c` | 陳老漢 | `/d/village/chen_grain_shop.c` | 黑石鋪陳記雜糧鋪店主，連結《鄰里勻米》支線與村落糧價傳聞 |
| `county_bailiff.c` | 地方巡檢卒 | 六縣城門與官署分佈 | 地方縣城治安巡檢、盤查與公告答詢 |
| `county_broker.c` | 地方朝奉 | 六縣當鋪與牙行分佈 | 地方典當估價與 `WORLD_STATE_D` 跨區特產貨盤 (`cargo`) 交易對口 |
| `county_innkeeper.c` | 客棧夥計 | 六縣驛站客舍分佈 | 縣城客棧歇腳茶飯、宿費與地方路況詢問 |
| `county_worker.c` | 地方老匠工 | 府城外城碼頭／染坊／回爐區與宗門雜役區 | 各地手藝匠工、苦力勞作與生活日常見證 |
| `danding_cook_nun.c` | 火頭道姑 | `/d/sects/danding/sect_refectory.c` | 丹鼎外門清淡百味膳堂執炊，外門弟子日常飲食補給 |
| `feng_seamstress.c` | 馮嫂 | `/d/counties/zhenfeng/garrison_lane.c` | 鎮風縣戍卒家眷窄巷縫補冬衣，連結《邊卒冬襖》支線 |
| `fishmonger_liu.c` | 魚販劉三娘 | `/d/city/outer/fish_market.c` | 外城河埠魚市攤販，與南關矮巷老車夫、挑夫同列生計流言網（`PHASE_D` 註冊） |
| `liefan_old_miner.c` | 老礦工羅七 | `/d/counties/liefan/tongtuo_ridge.c` ↔ `miners_tea_shed.c` | 烈礬礦脈老礦工，隨 `mine_shutdown` 因果事件停工聚於粗茶棚（`PHASE_D` 註冊） |
| `panmu_raftsman.c` | 放排老把式林四 | `/d/counties/panmu/fir_logging_line.c` ↔ `timber_wharf.c` | 盤木伐木放排把式，連結《扎排下水》支線（`PHASE_D` 註冊） |
| `peddler_hu.c` | 貨郎胡二 | `/d/village/peddler_corner.c` | 黑石鋪貨郎棚，對接特產貨盤（黑石木炭等）與日常雜貨（`PHASE_D` 註冊） |
| `qian_trapper.c` | 老套手錢七 | `/d/village/smokehouse_shed.c` | 黑石鋪山麓烘肉寮，提供獸皮／熏肉與山林陷阱常識 |
| `qinghe_boatman.c` | 老船工柳伯 | `/d/counties/qinghe/river_tea_shed.c` / 蘆花渡口 | 青河渡口船工，觀測水勢、連結《量尺問水》支線（`PHASE_D` 註冊） |
| `qinghe_herb_woman.c` | 採藥婦翠嬸 | `/d/counties/qinghe/ferry_dock.c` 等 | 青河碼頭採藥婦，於青河渡口樞紐參與水運藥物互動（`PHASE_D` 註冊） |
| `roaming_porter.c` | 挑夫阿福 | `/d/city/outer/river_wharf.c` 等 | 城郊碼頭與貨路間流動挑夫，散播沿途貨物與天候消息（`PHASE_D` 註冊） |
| `route_guard.c` | 關卡巡檢卒 | `/d/routes/` 官道關卡節點 | 官道沿線關卡值守、盤查重車禁行與季節積雪預警 |
| `route_traveler.c` | 趕路趟子手 | `/d/routes/` 官道與 `/d/sects/bahuang/outer_barracks.c` | 往返官道與北境軍營之行腳趟子手，交流路況經驗 |
| `song_xiucai.c` | 宋秀才 | `/d/village/village_school.c` | 黑石鋪村尾蒙館塾師，連結《一錠松煙墨》支線 |
| `sun_old_carter.c` | 孫老車夫 | `/d/city/outer/tenement_alley.c` | 南關矮巷老車夫，見證城內外階層與生計落差（`PHASE_D` 註冊） |
| `taiqing_copy_senior.c` | 戒律抄經師兄 | `/d/sects/taiqing/scripture_copy_hall.c` | 太清外門抄經堂領班師兄，連結《抄經換餐》支線 |
| `tavern_merchant.c` | 跑商陳大牙 | `/d/city/south/wine_tavern.c` | 金石老酒肆資深行商，對接貨盤與《跑商聽風》支線 |
| `tea_doctor_lin.c` | 茶博士老林 | `/d/city/center/tea_alley.c` | 城中槐蔭茶肆掌壺茶博士，提供市井消息與茶敘交流 |
| `wang_washerwoman.c` | 王大嬸 | `/d/village/wash_bank.c` | 碎石溪下游搗衣淺灘村婦，反映黑石鋪農婦視角傳聞 |
| `wastes_herder.c` | 老牧戶烏蘭 | `/d/wastes/frost_hunter_camp.c` | 北荒凍土牧戶避風棚老牧戶，連結《荒原迷蹤》尋羊支線 |
| `yunjin_tea_vendor.c` | 茶市老孫頭 | `/d/yunjin/temple_tea_fair.c` | 雲津山神廟會茶市攤主，支援民俗茶攤聽風互動 |
| `yunjin_wharf_master.c` | 冰河船把頭 | `/d/yunjin/river_wharf.c` | 雲津冰河木筏碼頭船把頭，樞紐互動與《竹籌對帳》要角 |
| `zhongshi_wheelwright.c` | 老車匠沈鐵頭 | `/d/counties/zhongshi/carter_yard.c` | 重石條石大車棚車匠，連結《八輪潤軸》支線 |
| `zhou_quarryman.c` | 石匠老周 | `/d/village/south_quarry.c` / 重石採石線 | 南山石場老石匠，連結《冬日備炭》支線（`PHASE_D` 註冊） |
| `zhuoshui_bridgekeeper.c` | 橋工老譚 | `/d/counties/zhuoshui/ginger_soup_stall.c` | 濁水老薑驅瘴攤橋工，連結《老薑驅瘴》支線 |

---

## 二、`PHASE_D` 排程與樞紐互動網絡（23 名排程角色 × 6 大樞紐）

### 1. 排程註冊清單（`daemon/phase_d.c` 共 23 名）
- **劇情／城鎮核心角色（13 名）**：`zhang_butcher`、`lao_miner`、`mo_beggar`、`kumu_daoist`、`center_doctor_bai`、`center_teacher_lu`、`center_wenchengjing`、`gong_mochui`、`wu_bashan`、`dao_xingyuan`、`square_watchman`、`square_storyteller`、`market_special_buyer`。
- **庶民生活排程角色（10 名）**：`fishmonger_liu`、`sun_old_carter`、`qinghe_boatman`、`qinghe_herb_woman`、`roaming_porter`、`liefan_old_miner`、`zhou_quarryman`、`panmu_raftsman`、`peddler_hu`、`charity_herbalist`。

### 2. 六大樞紐 NPC-to-NPC 多節拍互動劇本（支援 `observe` / `旁觀` 指令）
1. `/d/counties/qinghe/ferry_dock.c`（青河渡口碼頭）
2. `/d/village/square.c`（黑石鋪青石街市）
3. `/d/city/outer/tenement_alley.c`（金石南關流民矮巷）
4. `/d/counties/liefan/miners_tea_shed.c`（烈礬礦工粗茶棚）
5. `/d/yunjin/river_wharf.c`（雲津冰河木筏碼頭）
6. `/d/city/south/wine_tavern.c`（金石城南老酒肆）

---

## 三、生活支線任務索引（`/quests/side/` 共 31 份：24 條生活支線 ＋ 7 條獵殺／三卷見證支線）

### 1. Phase 1–3 新增平凡生活支線（24 條 `side_*.json`）

| 區域 | 任務 ID | 任務名稱 |
|---|---|---|
| **黑石鋪 (Tier 0)** | `side_village_grain_errand` | 陳記雜糧・鄰里勻米 |
| | `side_village_school_ink` | 村尾蒙館・一錠松煙墨 |
| | `side_village_charcoal_stove` | 南山石場・冬日備炭 |
| **金石府城 (Tier 1)** | `side_city_vagrant_letter` | 南關矮巷・家書代筆 |
| | `side_city_trade_rumor` | 老酒肆・跑商聽風 |
| **六大縣城 (Tier 1)** | `side_county_qinghe_ferry` | 蘆花渡口・量尺問水 |
| | `side_county_qinghe_mooring` | 青河碼頭・搶修纜樁 |
| | `side_county_liefan_mungbean` | 赤岩客舍・井水綠豆湯 |
| | `side_county_liefan_credit_grain` | 烈礬礦棚・停工賒糧 |
| | `side_county_panmu_raft` | 倒影澗畔・扎排下水 |
| | `side_county_panmu_charcoal_sled` | 盤木林道・冬寒送炭 |
| | `side_county_zhongshi_axle` | 磐石車棚・八輪潤軸 |
| | `side_county_zhenfeng_coat` | 鎮風矮巷・邊卒冬襖 |
| | `side_county_zhuoshui_bridge` | 濁水老攤・老薑驅瘴 |
| **官道水陸** | `side_route_storm_cargo` | 官道驟雨・搶運貨棚 |
| | `side_route_wheel_repair` | 青河水驛・修補車輪 |
| | `side_route_winter_hearth` | 林海官道・寒夜借火 |
| **四大宗門 (Tier 2)** | `side_sect_copy_relief` | 山門暮粥・抄經換餐（太清） |
| | `side_sect_danding_herb_oops` | 外門藥圃・誤採搶救（丹鼎） |
| | `side_sect_tiangong_slag_pick` | 冷卻渣槽・淘撿玄鐵（天工） |
| | `side_sect_bahuang_bowstring` | 外營通鋪・磨刀修弦（八荒） |
| | `side_sect_bahuang_ration_tally` | 八荒伙房・舊欠家書（八荒） |
| **雲津／北荒 (Tier 2)** | `side_yunjin_coolie_tally` | 冰河碼頭・竹籌對帳 |
| | `side_wastes_lost_goat` | 凍土尋羊・荒原迷蹤 |

### 2. 其餘 `/quests/side/` 任務（7 條）
- Tier 0 狩獵防煞（2 條）：`hunting_chain`、`wolf_hunter`
- Vol.3 實地見證支線（5 條）：`v3_act1_cold_plain_rescue`、`v3_act2_bahuang_ghost_gorge`、`v3_act2_taiqing_ascension_secret`、`v3_act3_war_god_tomb`、`v3_act4_cloud_top_tournament`

---

## 四、因果經濟、階層差異與六維傳聞機制（Phase 2B–3D）

1. **五大經濟因果事件 (`WORLD_STATE_D`)**：
   - `landslide_rain`（山雨塌方）、`mine_shutdown`（礦坑停工）、`river_surge_sluice`（漲水啟閘）、`gate_tax_lockdown`（關卡增稅封檢）、`northern_cold_snap`（北境寒潮）。
   - 連動區域庫存 `market_stocks`、定期持續結算 `economic_batch_tick()`、商販策略切換 `merchant_strategies` 與 `market_special_buyer.c` 即時民生牌價。
2. **六大特產貨盤跨區套利 (`/clone/item/trade_cargo.c`)**：
   - `panmu_timber`、`liefan_alum`、`zhongshi_iron`、`qinghe_herbs`、`zhenfeng_pelt`、`blackstone_charcoal`；支援 `cargo list / buy / sell` 跨區套利、飽和出貨虧損與 `route_room.c` 暴雨折損／封關補稅檢定。
3. **社會階層四維差異 (`CITY_D->query_social_tier()`)**：
   - 依居留憑證（《暫住牌》`temp_residency_pass.c` 與三緩衝腰牌／正式戶籍）區隔南關流民矮巷（2 文通鋪、3 文菜粥、免費義棚義診）與內城客棧、杏林醫館的身分、生計、資源與流動門檻。
4. **六維交叉傳聞與分層語氣 (`RUMOR_D`)**：
   - `query_cross_check_rumors(event_id)`（含 `source`、`event_id`、`credibility`、`region`、`timestamp`、`is_stale` 六欄位五方口徑）、`query_tiered_folk_rumor()`、`query_slice_of_life_rumor()`、`query_causal_economy_rumor()`。
