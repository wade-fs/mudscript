# 《遺忘的世界》正典變更日誌 (Canon Changelog)

本文件追蹤《遺忘的世界》小說正典修訂與 Mudlib 可執行世界之間的雙向同步紀錄，配合 [data/canon_sync_matrix.json](../data/canon_sync_matrix.json) 與 [tests/quests/novel_mud_sync_audit.py](../tests/quests/novel_mud_sync_audit.py) 使用。

## 2026-11-27 — 第三～四卷區域定義補完與世界模擬引擎接軌
* **補齊第三～四卷 Region / Zone / Site 靜態定義**：於 `world/regions/` 新增 10 個區域 JSON（`yunjin`、`taiqing`、`bahuang`、`tiangong`、`danding`、`wastes`、`realm_edge`、`realm_taixu`、`realm_wanwu`、`realm_zhanzu`），含各區 `factions` 初始影響力與 3～4 張 `crisis_deck` 危機牌組；於 `world/zones/` 補齊 17 個對應 Zone JSON（總數由 6 增至 23），於 `world/sites/` 新增 4 個跨區關鍵 Site（`taiqing_ark_portal`、`wastes_ark_core`、`realm_edge_beacon_relay`、`realm_wanwu_conduit_well`），並同步擴充 [world/topology/macro_topology.json](../world/topology/macro_topology.json)。
* **接通第三～四卷世界模擬引擎**：
  * `REGION_D`（[daemon/region_d.c](../daemon/region_d.c)）新增 `query_faction_power()`、`adjust_faction_power()`、`query_crisis_deck()`、`trigger_crisis_from_deck()` 與 `test_mode` 隔離防護，貫徹靜態牌組／勢力定義與動態危機狀態分離。
  * `PHASE_D`（[daemon/phase_d.c](../daemon/phase_d.c)）補入 `tier2_crisis`、`crystal_quarantine`、`tier3_calibration`、`wanwu_strike` 四項事件相位、6 名三～四卷駐點與跨極關鍵 NPC 作息排程（`qiu_he`、`lei_lie`、`han_su`、`ash_warden_qi`、`stone_clinic_healer_su`、`wanwu_auditor_qi`），並為 `/d/realm/` 補入時差與法則阻尼環境風物。
  * `EVENT_MANAGER_D`、`WORLD_STATE_D` 與 `QUEST_ENGINE_D`（[daemon/event_manager.c](../daemon/event_manager.c)、[daemon/world_state_d.c](../daemon/world_state_d.c)、[daemon/quest_engine_d.c](../daemon/quest_engine_d.c)）打通 `EVENT_TIER2_CRISIS`／`EVENT_TIER3_CALIBRATION` 對區域危機牌組與勢力權重的顯式同步、寒潮跨區連動、`apply_region_effects()` 與三～四卷動態報酬倍率／任務日誌呈現，並新增 [tests/test_vol3_4_simulation.c](../tests/test_vol3_4_simulation.c) 回歸測試。

## 2026-11-27 — 補立第二紀元正典（方舟／離艦總約／洞天／三息）暨第四卷章號清理
* **新增第二紀元正典**：建立 [world/lore/second_era_ark_canon.md](../world/lore/second_era_ark_canon.md)（`v1.0`），將原分散於第三至四卷正文與 `TIER3_D` 的太古破界方舟三部編制、《離艦火種總約》第七條與沈雲妮權限、方舟九號離艦艙與灰燼石堡 487 戶起源、桃花源洞天 `12:1` 時差與 `2.5x` 重力／`3x` 舊法衰減、`K×U` 非計數器法則、三極巨構與三息微光信標規範全面正典化，並逐條標註 `CONFIRMED`／`INFERRED`／`RUMORED`／`UNKNOWN`，明確鎖定歸墟古淵與大清洗因果關係、假天／十歲象最終操縱者等第五卷未定案邊界。
* **第四卷重複章修復與文件同步**：補實第 130 章《邊緣醫棚與首例「律令排異症」》及第 160 章《三十座緩衝爐與藥煙護民》，校正 `article/04_volume4/00_intro.md` 與 `article/SUMMARY.md` 章號目錄，並同步 [README.md](../README.md) 與 `docs/mudlib_expansion_and_nine_cities_spec.md` 相對連結。

## 2026-11-22 — Phase 4 世界鮮活度 2.0 稽核與前三卷小說雙向反哺
* **World Liveness 2.0 全面稽核**：升級 `tests/quests/world_liveness_audit.py`，全面驗證 288 間房 `set_long` 括號指令 0 遺漏、`PHASE_D` 23 名排程 NPC 與 6 大樞紐互動劇本、`30` 名庶民 NPC 對話覆蓋、動態庫存與 6 維傳聞品質。
* **前三卷小說 ↔ Mudlib 雙向反哺**：核對全三卷 126 章里程時序一致性（盤木 190+260=450 里、烈礬 320 里、雲津北行 800 里），於第 2、43、84 章補入黑石村塾雜糧鋪、南關外流民矮巷施藥棚與雲津冰河碼頭苦力竹籌等凡俗市井肌理，並於 `data/canon_sync_matrix.json` 新增 `living_world_folk_layer` 納入 `novel_mud_sync_audit.py` 自動驗證。

## 2026-11-22 — Phase 3B / 3D 因果經濟持續性、庫存供需閉環、六維資訊品質與地方文化選擇
* **真實庫存、供需反哺與運輸風險**：`WORLD_STATE_D` 實作區域 `market_stocks`、定期持續性批次結算 `economic_batch_tick()`（含 `last_settled_gtime` 防重入）與 NPC 商販策略切換 `merchant_strategies`；`route_room.c` ＋ `trade_cargo.c` 實裝暴雨折損成色與封關補稅風險，飽和出貨將造成真實虧損。
* **非強制選擇與地方文化參與**：`miners_tea_shed.c` 支援明確 `decline`（拒絕賒糧且無懲罰，世界現況持續演進），`earth_shrine.c` 與 `temple_tea_fair.c` 補入「社祭／敲社鼓／茶攤聽風」文化民俗互動。
* **`RUMOR_D` 六維資訊品質與五方口徑**：實裝含 `source`、`event_id`、`credibility`、`region`、`timestamp`、`is_stale` 六欄位的 `query_cross_check_rumors()`，完成寒潮十步端對端經濟閉環測試。

## 2026-11-22 — Phase 3 因果跨區跑商、分層生活語氣與後續六縣官道宗門日常支線
* **實體貨包跨區因果套利**：新增 `/clone/item/trade_cargo.c` 與 `WORLD_STATE_D` 六大地區特產貨盤（`panmu_timber`、`liefan_alum`、`zhongshi_iron`、`qinghe_herbs`、`zhenfeng_pelt`、`blackstone_charcoal`），於六縣牙行、`peddler_corner.c`、`wine_tavern.c` 與 `exchange_hall.c` 串接 `cargo list / buy / sell` 跨區套利與同產地防刷檢核。
* **六縣／官道／宗門日常支線擴充至 24 條**：新增停工賒糧（烈礬）、搶修纜樁（青河）、冬寒送炭（黑石→盤木）、寒夜借火（南嶺林海驛）、修補車輪（青河水驛）與八荒伙房整理家書等 6 條生活支線。
* **分層生活語氣（`RUMOR_D`）**：新增 `query_tiered_folk_rumor()`，區隔農婦船夫的民俗誤解絮語與老匠跑商的結構實務判斷。

## 2026-11-22 — Phase 2B 世界運作機制（日夜季節節律、庶民動態互動、因果經濟與階層落差）
* **時間維度 × 季節節律**：`NATURE_D` 新增季節覆寫與 `PHASE_D->query_room_rhythm_line()`，全站呈現清晨／上午／午後／黃昏／夜間作息脈動；`std/route_room.c` 依季節顯示封道／積雪實警。
* **庶民作息與樞紐 NPC-to-NPC 互動**：`PHASE_D` 擴充至 23 名作息註冊角色（含 `roaming_porter` 阿福、`qinghe_herb_woman` 翠嬸與六縣／城郊勞動群體），並於青河渡口、黑石街市、南關流民矮巷、烈礬茶棚、雲津碼頭與城南酒肆實裝多節拍 NPC-to-NPC 日常互動（支援 `observe` / `旁觀` 指令與定期脈動）。
* **因果經濟與民生牌價**：`WORLD_STATE_D` 實裝五大因果事件（`landslide_rain`、`mine_shutdown`、`river_surge_sluice`、`gate_tax_lockdown`、`northern_cold_snap`），連動礦工停工聚集、`market_special_buyer.c`（含皮襖／木炭／老薑湯／糙米行情）與 `RUMOR_D->query_causal_economy_rumor()`。
* **社會階層四維度落差**：`CITY_D->query_social_tier()` 與南關矮巷（《暫住牌》、2 文通鋪、3 文菜粥）、施藥義棚（免費義診）、內城中心客棧與杏林醫館完成身分／生計／資源／流動差異化。

## 2026-11-22 — Phase 1 / Phase 2A 世界真實化與「空房歸零」擴建
* **生活空間與非主線支線擴建（254 → 288 間房、18 條平凡日常支線）**：
  * 六縣（`std/county_room.c`）與官道（`std/route_room.c`）全面具備動態風土五感、地方住民／關卡巡檢與歇腳／路況／盤查互動，並於六縣補入具名庶民生活支翼。
  * Tier 0 黑石鋪（22/22）、Tier 1 府城（75/75：含酒肆跑商、施藥義棚、魚市、染坊、四牆步道、暗渠及內外城分層五感）、四大宗門（36/36：含八荒／丹鼎／太清／天工外門雜役與功法場域五感）、Tier 2 雲津（21/21）、北荒（20/20）完成五感覆蓋與互動填實，全站 288 間房達成 **288/288 (100%) 五感覆蓋**與 **0 空房**（均由 `world_liveness_audit.py` 硬性鎖定）。
  * `RUMOR_D` 新增 `query_slice_of_life_rumor()` 平民日常流言，並新增 `tests/quests/world_liveness_audit.py` 與 `tests/test_world_liveness.c` 長駐回歸檢核。

## 2026-11-21 — 小說一至三卷修訂與 Mudlib 體驗深度對齊
* **小說正典（Vol.1–3 共 126 章）**：
  * 完成第一至三卷敘事節奏、五主角聲音辨識度、感官物質細節與第三卷終章洞天前瞻修訂。
  * 新增三卷讀者大事記與人物狀態導讀（`article/0{1,2,3}_volume{1,2,3}/00_intro.md` 與 `article/appendix/chronicle.md`）。
* **Mudlib 體驗強化（對應 `ss.md` 全數條目）**：
  1. **感官優先與偏好系統**：`std/room.c` 新增全域 `touch`/`smell`/`listen` 與五身世感官視角濾鏡；`cmds/cmd_set.c` + `std/living.c` 支援 `brief_numeric` 純感官模式與 `brief_sensory` 切換；關鍵房間及 `d/realm/peach_plateau.c` 全面實裝動態感官與第四卷三倍源質警兆。
  2. **物證出示、互相印證與污染/偽造風險**：新增 `cmds/cmd_present.c`；`CITY_D` 實作跨卷互鎖組合（包含三卷北荒/戰祖物證鏈）、未封存物證暗渠涉水自動污染（`d/city/under/canal_hub.c`）、偽造假證反噬罰則及文承敬/白先生公證封存修復。
  3. **五器共鳴多階段技術校驗**：`d/sects/taiqing/ark_portal_chamber.c` 與 `d/wastes/ark_core_chamber.c` 實作 5 座方位石台/凹龕順序校驗、誤差診斷與實體信物/隊友協同（`strict` 模式）。
  4. **傳聞扭曲、卷幕動態、資格區隔與貢獻回放**：`RUMOR_D->query_distorted_rumor()` 接入 `std/npc.c`、`square_storyteller.c`、`zhao_hunter.c`、`market_special_buyer.c`；`EVENT_MANAGER_D` 實作小說卷幕對應、多玩家貢獻度階梯結算與 `cmds/cmd_chronicle.c` 歷史回放指令；`QUEST_ENGINE_D` 結合幕次倍率與多身世組隊協同獎勵加成；府城醫館、百工爐房、專材長街與宣道正殿透過 `std/room.c` 宣告式動作規則（`add_action_rule`）實質檢定「會做 vs 有資格做」。
