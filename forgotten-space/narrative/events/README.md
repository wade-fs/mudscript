# 敘事事件與系統機制映射 (Narrative Events Mapping)

本目錄記錄小說各卷各幕的核心敘事事件，及其在 MUD 引擎中由 `QUEST_ENGINE_D` (`/daemon/quest_engine_d.c`)、`MYSTERY_D` (`/daemon/mysteryd.c`)、`WORLD_STATE_D` (`/daemon/world_state_d.c`)、`PHASE_D` (`/daemon/phase_d.c`) 與 `CITY_D` (`/daemon/city_d.c`) 管理的實作映射。

* 卷二專屬事件與詳細機制規範請參見：[第二卷：金石雙壁事件記錄簿（EV-201～EV-244）](volume2_events.md)
* 卷三專屬事件與任務網規範請參見：[第三卷事件索引（EV301～EV327）](volume3_events.md) ｜ [Tier 2 任務網絡規劃](../docs/tier2_quest_network.md)
* 卷四規劃事件與對照規範（規劃中）：[第四卷事件索引（EV401～EV422）](volume4_events.md)
* 平凡日常支線（24 條 `side_*.json`）、5 大經濟因果事件與 `PHASE_D` 樞紐互動索引請參見：[凡塵生活層名冊與支線總表](../docs/living_world_folk_and_side_roster.md)

> **全書事件編號連續性說明**：第二卷采 `EV-201`–`EV-244`（對應連字號別名 `EV201`–`EV244`）、第三卷 `EV301`–`EV327`、第四卷規劃 `EV401`–`EV422`，由 `tests/quests/novel_mud_sync_audit.py` 自動檢核連續性。

---

## 第一卷：黑石破曉事件映射表（第 1～38 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 觸發動詞與房間 | 系統事件 ID (`personal_event/*`) | 機制與天命獎勵 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 1 章** | 顧玄<br>*(採藥孤兒)* | 晨曦洗滌石板，破除認知盲區，拓印逆星斷碑 | `study stone`<br>`tuoyin stone`<br>`/d/village/stream.c` | `study_ruin_stone`<br>`tuoyin_stone` | 悟性提升、獲得【殘缺星圖拓片】(`stele_rubbing.c`)、**天命 +1** |
| **第 2 章** | 林鐵生<br>*(打鐵學徒)* | 地爐千錘百鍊，粗鐵礦核碎裂，顯露不融黑鐵 | `bellows`<br>`strike ore`<br>`/d/village/forge.c` | `forge_ancient_black_iron` | 領悟「瘋魔打鐵法」、獲得【太古不融黑鐵構件】(`ancient_black_iron.c`)、**天命 +1** |
| **第 3 章** | 燕隼<br>*(獵戶之子)* | 追蹤黑熊暗紫濁血，以荒血共鳴戰神圖騰玄柱 | `trap`<br>`track`<br>`totem`<br>`/d/village/forest.c` | `commune_forest_totem` | 臂力身法淬鍊、加固防獸陷阱降低獸潮警報、**天命 +1** |
| **第 4 章** | 柳清虛<br>*(破落道童)* | 孤岩撥開老松取道化晶石，神識窺天天羅偽籠 | `meditate`<br>`search pine`<br>`stargaze`<br>`/d/village/altar.c` | `search_altar_pine`<br>`stargaze_altar` | 獲得【道化晶石殘片】(`dao_crystal.c`)、悟性+2 靈性+2、**天命 +1** |
| **第 5 章** | 沈泥<br>*(流浪乞兒)* | 貼牆偷聽官軍勒索內幕，爛泥深處扒出天門引 | `eavesdrop`<br>`search wood`<br>`/d/village/shed.c` | `eavesdrop_shed`<br>`search_shed_wood` | 洞察商道實情（定力+1）、獲得【萬物行商・天門引】(`tianmen_token.c` 休眠殘缺)、**天命 +1** |
| **第 6～12 章** | 五子匯流 | 後巷五器合契拼合太古星圖，三道啟蒙歷練與百工開山柴刀鍛造閉環 | `piece map`<br>`/d/village/back_alley.c`<br>`/d/village/forge.c` | `enc_map_fusion`<br>`wu_chain` / `li_chain` / `fa_chain`<br>`cycle_of_craft` | 完成跨身世太古星圖合契、三大道統親和度積累、獲得【重木開山刀】(`heavy_wood_blade.c`) |
| **第 13～21 章** | 五子同袍 | 北崖古礦塌方深井搜救、寒潭淬體與廢柴房智救蘇凝霜 | `chisel`<br>`/d/village/mine.c`<br>`/d/village/mine_pit.c`<br>`/d/village/shed.c` | `rescue_miners`<br>`rescue_maiden` | 救出受困礦工魯大山一行、擊敗惡霸趙四救下金石商會千金蘇凝霜、初探北崖私煉血精黑幕 |
| **第 22～31 章** | 五子同袍 | 大荒煞潮迫近：凹地驗屍、逆向獸跡、品字導障、當眾盤糧、寒針截脈、車陣守柵 | `autopsy` / `sample` / `divert` / `audit` / `acupuncture` / `fortify` / `brace` / `inspect` | `A01` / `A02` / `B02` / `C01` / `D01` / `E01` / `G01` / `F03`<br>(`EVENT_MANAGER_D`) | 完整走通大荒煞潮 8 大生存事件網，分流獸潮主力並鎖定【丙字柒號】除渣黑釜與軍需雷管鐵證 |
| **第 32～38 章** | 全員群像 | 黑石關軍營三證合契對質、查封胡百戶與趙德貴、領取通關路引啟程赴金石府城 | `/d/village/square.c`<br>`/d/routes/blackstone_pass.c` | `village_pass`<br>`F03_testimony_cross_check` | 扳倒黑石關胡百戶、獲得【金石保書路引】(`road_pass.c`)、第一卷圓滿收官 |

---

## 第二卷 第一幕：東線押解與南關限期令（第 39～46 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 物證關聯 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 39 章** | 五子同袍 | 啟程押解要犯趙德貴，青簡驛站簽署押解路籤 | `/d/village/square.c`<br>NPC: `caravan_merchant` | 任務：`v2_panmu_transport`<br>道具：`custody_ledger.c` | 承接押解差遣，確立沿途驛站防滅口警戒網絡。 |
| **第 40 章** | 顧玄 | 峽下驛查驗趙德貴脈象，察覺伏行慢性毒素脈動 | `/d/routes/panmu_post_approach.c`<br>NPC: `yamen_prison_zhaodegui` | 任務：`v2_panmu_transport` | 洞悉商會殺人滅口暗手，提前備妥解毒行針方案。 |
| **第 41 章** | 顧玄 / 燕隼 | 松崖驛要犯急性肺痙攣發作，寒針截脈奪命續息 | `/d/routes/forest_sea_post.c` | 任務：`v2_panmu_transport` | 成功壓制腐脈散劇毒，保住全案唯一活口證人。 |
| **第 42 章** | 林鐵生 / 燕隼 | 盤木天車絞盤深谷卡死，精算切應力削製雙契木榫 | `/d/counties/panmu/post_inn.c`<br>`/d/city/outer/post_depot.c` | 道具：`stress_wedge.c` | 卸解千斤崩裂應力，獲外城車馬店老王路籤認證。 |
| **第 43 章** | 沈泥 / 燕隼 | 抵達金石南關，宋算子嚴苛驗牒，72小時倒數啟動 | `/d/city/gate/gate_south.c`<br>NPC: `gate_south_taxofficer` | 任務：`v2_residency_72h`<br>道具：`residency_tally.c` | 領取【金石黃木通牒】，啟動 72 小時三日逐出倒數機制。 |
| **第 44 章** | 全員 | 府衙案牘庫公堂對質，文承敬主簿簽押移交死牢 | `/d/city/center/yamen_archive.c`<br>NPC: `center_wenchengjing` | 任務：`v2_residency_72h` | 人犯正式收監死牢，取得官署移交印信，確立司法防護。 |
| **第 45 章** | 沈泥 / 顧玄 | 金石商會總堂正面交鋒，副會長錢百川笑裡藏刀 | `/d/city/south/shanghui_hq.c`<br>NPC: `south_qianbaichuan` | 任務：`v2_residency_72h` | 頂住巨賈經濟威壓，洞悉商會「除渣黑釜」心虛之處。 |
| **第 46 章** | 五子同袍 | 南關老劉客棧分道謀劃，三路解套合法身分緩衝 | `/d/city/gate/gate_south_inn.c`<br>NPC: `gate_south_inn_laoliu` | 道具：`academy_token.c`<br>`clinic_token.c`<br>`caravan_token.c` | 兵分三路（學塾青衿/百草藥囊/車馬短褐）解除逐客危機。 |

---

## 第二卷 第二幕：五道資質考核與西水門驚瀾（第 47～57 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 物證關聯 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 47 章** | 林鐵生 | 千錘地爐坊左手反鍛五百針，莫錘授初階匠帖 | `/d/city/north/gong_forge.c`<br>NPC: `gong_mochui` | 任務：`v2_career_tier1_qualifications`<br>道具：`lic_artisan.c` | 獲得【百工初階匠帖】，取得丙字柒號坩堝拓本。 |
| **第 48 章** | 顧玄 | 杏林百草堂盲目辨毒，白先生親試濁水之毒成分 | `/d/city/center/clinic.c`<br>NPC: `center_doctor_bai` | 任務：`v2_career_tier1_qualifications`<br>道具：`lic_apothecary.c` | 獲得【杏林初階醫籍】，掌握濁水毒源配方特性。 |
| **第 49 章** | 燕隼 | 八方武館四百斤石鎖走場，硬撼趙猛三拳獲鏢師帖 | `/d/city/east/wu_hall.c`<br>NPC: `wu_bashan` | 任務：`v2_career_tier1_qualifications`<br>道具：`lic_escort_guard.c` | 獲得【八方鏢師總帖】，盤石硬功獲軍鎮鏢局認可。 |
| **第 50 章** | 柳清虛 | 摘星台心算破百年歲差題，觀測九霄濁氣暗渦 | `/d/city/west/dao_observatory.c`<br>NPC: `dao_xingyuan`<br>`dao_xuanji` | 任務：`v2_career_tier1_qualifications`<br>道具：`lic_diviner.c` | 獲得【宣道司觀象牒】，看破天地偽象暗渦。 |
| **第 51 章** | 沈泥 | 通寶當鋪審計陳年死帳，初見天星十四年沈雲妮舊案 | `/d/city/center/pawnshop.c`<br>NPC: `center_pawn_jia` | 任務：`v2_career_tier1_qualifications`<br>道具：`lic_broker.c` | 獲得【金石商行牙帖】，恪守線索邊界（`lead_only`）。 |
| **第 52 章** | 全員 | 西水門暴雨洪峰漫堤，黑道水賊刁建水惡意塞閘卡死 | `/d/city/gate/gate_west.c`<br>NPC: `gate_west_helmsman`<br>`gate_west_inspector` | 任務：`v2_west_watergate_crisis` | 觸發全城水門潰決公眾事件，水閘齒輪遭生化濁膠封死。 |
| **第 53 章** | 五子同袍 | 五子分工力挽狂瀾：融膠、精算、深潭錨定、木榫卸力 | `/d/city/gate/gate_west.c`<br>`/d/city/under/drain_gate.c`<br>NPC: `under_drain_gate_diver` | 道具：`solvent_resin.c`<br>`sluice_cable.c` | 顧玄融膠、清虛算時、燕隼錨定、鐵生卡榫、沈泥聚舟破浪！ |
| **第 54 章** | 燕隼 / 沈泥 | 千斤鑄鐵閘轟然落槽，暗箭截擊刁建水查獲商會密令 | `/d/city/gate/gate_west.c` | 任務：`v2_west_watergate_crisis` | 成功保全西水門，生擒主謀水賊，取得直接涉案令信。 |
| **第 55 章** | 全員 | 府城五方公署齊至，五道一階度牒與正式職照完備 | 各大道統正堂與公署 | 職業：5 大道途一階合法身分 | 彻底破除 72 小時居留倒數威脅，正式立足金石府城。 |
| **第 56 章** | 五子同袍 | 南關車馬小棧深夜合議，提訊趙德貴梳理六大缺口 | `/d/city/gate/gate_south_inn.c`<br>`/d/city/center/yamen_prison.c` | 任務：`v2_six_evidence_gaps`<br>道具：`evidence_six_gaps.c` | 建立標準五欄物證體系，鎖合六大物證鏈斷裂缺口。 |
| **第 57 章** | 全員 | 三十日全府時鐘自主演進定錨，六缺口歸檔案牘庫 | `/d/city/center/yamen_archive.c`<br>NPC: `center_wenchengjing` | 任務：`v2_six_evidence_gaps` | 卷宗入庫公證，五子確立第三卷深入府城地脈之行動綱領。 |

---

## 第二卷 第三幕：六縣連環・證據成鏈（第 58～67 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 物證關聯 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 58 章** | 沈泥 | 分頭啟程，請假銷假直面組織成本，東關督稅官查扣底冊 | `/d/city/gate/gate_east.c`<br>`/d/city/center/pawnshop.c` | 任務：`v2_six_county_evidence`<br>道具：通寶牙人信印 | 確立各人組織代價，取得東關出府路引與通寶牙人特等信印。 |
| **第 59 章** | 顧玄 | 馳抵青河縣直面爭水斷水黑幕，集市揭穿假藥與高利貸 | `/d/counties/qinghe/market.c`<br>`/d/routes/qinghe_barge_channel.c` | 任務：`v2_six_county_evidence` | 亮出杏林醫籍揭穿商會以陳冒新，平息藥農流血械鬥。 |
| **第 60 章** | 五人剪輯 | 匯總四線書信，打破一次性買齊幻想，說服靈植道觀放水 | `/d/counties/qinghe/post_inn.c`<br>`/d/counties/qinghe/herb_shrine.c`<br>`/d/counties/qinghe/upper_dam.c` | 道具：青河水利批函 | 以次級苦參替代方破局，十二箱救命藥草發往黑石鋪。 |
| **第 61 章** | 柳清虛 | 天風谷頂風採石，水銀渾天鏡算三息風眼採得石英核 | `/d/counties/zhenfeng/yingzui_quartz.c`<br>`/d/counties/zhenfeng/yamen.c` | 道具：`fengshi_quartz.c` | 採得極品風蝕石英核，折抵冬糧撫恤平息衛所散人火併。 |
| **第 62 章** | 燕隼 | 雪狼夜襲死守糧站，調閱五年舊檔起獲大伯走山令殘牌 | `/d/counties/zhenfeng/yamen_vault.c`<br>`/d/counties/zhenfeng/north_beacon.c` | 任務：`v2_six_county_evidence`<br>道具：`shan_token_half.c` | 查明商會五年前僱傭燕山探礦，起獲燕山箭記走山令殘牌。 |
| **第 63 章** | 林鐵生 | 烈礬地火堡深井通風排險救人，起獲特級耐火泥出貨單 | `/d/counties/liefan/dihuo_kiln.c`<br>`/d/counties/liefan/tongtuo_shaft3.c` | 任務：`v2_six_county_evidence`<br>道具：`liefan_clay_batch.c` | 救出 122 名礦工，起獲商會內堂專用印耐火泥單（`corroborative`）。 |
| **第 64 章** | 沈泥 | 踩踏濁水浮橋道金蟬脫殼避連弩，起獲毒囊交割底單 | `/d/counties/zhuoshui/heishui_pontoon.c`<br>`/d/counties/zhuoshui/heishui_waterhouse.c` | 任務：`v2_six_county_evidence`<br>道具：`relay_poison_sample.c` | 截獲商會後勤房提領六十斤地陰腐骨散底單，逼近 `conclusive`。 |
| **第 65 章** | 沈泥 | 深入暗渠見舊盟柯九算，三方互鎖證實「雲記沈雲妮」身世 | `/d/counties/zhuoshui/old_canal_entry.c`<br>`/d/counties/zhuoshui/kejiusuan_vault.c` | 任務：`v2_six_county_evidence`<br>道具：`yunji_roster.c` | 身世三階關係證實（`conclusive` on identity），得手抄名冊。 |
| **第 66 章** | 林鐵生 | 穿山寨重造雙齒棘輪絞盤救險，起獲抽減鐵木指令拓本 | `/d/counties/zhongshi/quarry_winch3.c`<br>`/d/counties/zhongshi/terrace_trench.c` | 任務：`v2_six_county_evidence`<br>道具：`zhongshi_timber_order.c` | 重造絞盤化解罷工，揭發礦難前抽減鐵木真相；太古石槨氣孔伏筆。 |
| **第 67 章** | 全員群像 | 南關小棧四線合璧，沈泥坦白身世；商會全面凍結飛錢奪權 | `/d/city/gate/gate_south_inn.c`<br>`/d/city/south/shanghui_hq.c` | 任務：`v2_six_county_evidence` 完成 | 六缺口補齊四項，沈泥坦承密室機括；錢百川凍結飛錢停職蘇凝霜。 |

---

## 第二卷 第四幕：信用凍結・三方會審（第 68～76 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 物證關聯 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 68 章** | 沈泥 | 飛錢成紙引發總號擠兌，比對底冊查明扣押九八足色官銀 | `/d/city/center/pawnshop.c`<br>NPC: `center_pawn_jia` | 任務：`v2_act4_tripartite_tribunal` (Step 1) | 勘破準備金成色破綻，粉碎假象。 |
| **第 69 章** | 顧玄 | 糧商串通停業哄抬，攜手常平倉呈遞分級保命條陳 | `/d/city/center/granary.c`<br>NPC: `granary_liubingzhong` | 任務：`v2_act4_tripartite_tribunal` (Step 2) | 以工代賑、分級配給平糶，穩住民心。 |
| **第 70 章** | 顧玄 | 瘴氣倒灌西水門，連夜配製苦參替代方撲滅疫情瓦解黑市 | `/d/city/center/clinic.c`<br>NPC: `center_doctor_bai` | 任務：`v2_act4_tripartite_tribunal` (Step 3) | 熬製苦參辟疫飲解救千人，粉碎藥商囤積。 |
| **第 71 章** | 林鐵生 | 西水門金剛砂磨毀導軌卡死渠首，螺紋頂升衝沙排險 | `/d/city/gate/gate_west.c`<br>NPC: `gong_mochui` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`miner_thumbprints.c` | 頂升閘葉反向衝沙，取得礦工血指結狀。 |
| **第 72 章** | 燕隼 | 查訪城防庫與硝火作，對質起獲軍需雷管雙聯火印存根 | `/d/city/north/gong_fireworks.c`<br>NPC: `gong_fireworks_master` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`detonator_serial_ledger.c` | 鋸齒騎縫火印咬合無誤，鎖定錢百貴。 |
| **第 73 章** | 沈泥 / 莫三 | 水情手令掩護潛入天字一號密室，起獲正底單加蓋火漆 | `/d/city/under/shang_secret.c`<br>`/d/city/center/yamen_archive.c`<br>NPC: `center_wenchengjing` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`under_canal_deed.c` | 搶出三萬斤血精交割正底單，法定保管鏈完備。 |
| **第 74 章** | 五人群像 | 南關小棧通宵復盤，定罪、政治平衡、民生止血三層籌碼 | `/d/city/gate/gate_south_inn.c` | 任務：`v2_act4_tripartite_tribunal` | 擊退刺探死士，五欄物證模型完備審計。 |
| **第 75 章** | 全員群像 | 府衙正堂三方會審，三印合符定讞，錢百川革職下獄 | `/d/city/center/yamen.c`<br>NPC: `yamen_magistrate` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`tripartite_warrant.c` | 三印合符定讞，查抄十二萬兩現銀，蘇凝霜雪冤！ |
| **第 76 章** | 五人群像 | 餘波震盪，世界狀態指數穩定於 118~124，靈台見真立心 | `/d/city/gate/gate_south_inn.c` | 任務：`v2_act4_tripartite_tribunal` 完成 | 全隊進階 Lv. 24，直面殘酷現實，叩響晉階之門。 |

---

## 第二卷 第五幕：歷史回響・晉階之門（第 77～82 章・卷二大結局）

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 物證關聯 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 77 章** | 沈泥 | 鬼市暗巷天門引共鳴，收購青銅契版，查明無標記採辦經生 | `/d/city/center/black_alley.c`<br>`/d/city/under/black_market.c`<br>NPC: `black_alley_gatekeeper`<br>`under_black_market_broker` | 任務：`v2_act5_tier2_admission`<br>道具：`bronze_treaty_plate.c` | 天門引共鳴起獲史前商盟青銅契版，查悉血精名山買家。 |
| **第 78 章** | 沈泥 | 南關小棧莫三吐露三十年清洗真相，接下太古舊約因果 | `/d/city/gate/gate_south_inn.c`<br>NPC: `gate_south_inn_laoliu` | 任務：`v2_act5_tier2_admission` | 莫三往事揭秘，沈泥立志不改沈泥之名、追查舊約。 |
| **第 79 章** | 林鐵生 / 顧玄 | 鐵生開百工格物心眼精金淬體；顧玄逆行洗髓成通靈藥體 | `/d/city/north/gong_forge.c`<br>`/d/city/center/clinic.c`<br>NPC: `gong_mochui`<br>`center_doctor_bai` | 任務：`v2_act5_tier2_admission` | 物道雙傑完成 Lv.50 肉身破障，突破凡胎極限。 |
| **第 80 章** | 燕隼 / 柳清虛 | 燕隼收束戾氣氣血脫胎；清虛實證道心斬破天羅道化心魔 | `/d/city/east/wu_plaza.c`<br>`/d/city/west/dao_quiet.c`<br>NPC: `wu_bashan`<br>`dao_xingyuan`<br>`dao_xuanji` | 任務：`v2_act5_tier2_admission` | 力法雙傑完成 Lv.50 肉身心神破障，神識法胎凝實。 |
| **第 81 章** | 五人群像 | 四維分離結算：四人獲名山考核令；沈泥獲跨州特等信印 | `/d/city/west/dao_hall.c`<br>`/d/city/gate/gate_south_inn.c`<br>NPC: `dao_xuanji`<br>`su_ningshuang` | 任務：`v2_act5_tier2_admission`<br>道具：`tier2_admission_token.c`<br>`cross_state_trade_tally.c` | 獲名山外門考核令與跨州信印；濁氣驅離機制啟動。 |
| **第 82 章** | 五人群像 | 故土家書抵達，五器合鳴指北；北關大開出關踏上名山仙途 | `/d/city/gate/gate_south_inn.c`<br>`/d/city/gate/gate_north.c`<br>NPC: `gate_north_hanqing` | 任務：`v2_act5_tier2_admission` 完成<br>道具：`ancient_relics_compass.c` | 五器共鳴星光指針直指北方名山，第二卷全卷大圓滿！ |

---

## 第三卷 第一幕：北境風雪與三山入山考（第 83～90 章・Act 1 已實裝）

> 第一幕對應 `d/wastes/north_road/`（3 房）、`d/yunjin/`（7 房）、`d/sects/`（10 房）、19 名 NPC、8 項道具、7 條任務與 `EVENT_TIER2_CRISIS`（`/data/event_defs/tier2_crisis.json`）；二至五幕詳見 [volume3_events.md](volume3_events.md)。

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 實裝道具 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 83 章** | 五人群像 | 八百里寒原行旅、黑風口避雪豹、斷崖石棚熬藥救腳夫與訪談周鐵山、陳青 | `/d/wastes/north_road/{cold_plain_entry,post_station,qing_pass}.c`<br>NPC: `mu_xue`, `zhou_tieshan`, `chen_qing` | 支線：`v3_act1_cold_plain_rescue`（`brew decoction`）<br>道具：`cold_herbal_decoction.c` | 打通鎮風關北塞北上路徑，揭開名山歲貢債務與藥田酸蝕外部代價。 |
| **第 84～85 章** | 沈泥 | 抵雲津入市公所驗契、開戶雲海票號、抗衡萬寶閣並掛牌「泥途商棧」聘邱禾、餞別四友 | `/d/yunjin/{north_road_gate,wanshan_square,public_office,exchange_hall,wanbao_pavilion,western_warehouse_street,mudway_store}.c`<br>NPC: `luo_jiucheng`, `gu_lanzhou`, `he_wanjin`, `qiu_he` | 主線：`v3_northbound_and_yunjin_arrival`、`v3_yuntu_market_charter` 前兩步<br>道具：`yunjin_trade_ledger.c` | 四維分離自立開張，建立貨單與三個月短契帳務制度。 |
| **第 86 章** | 柳清虛 | 太清立冬大考：千丈雲梯不跪而實測東北測星柱滯後千分之三息，破格入周天星律院 | `/d/sects/taiqing/{gate,outer_court,star_law_hall}.c`<br>NPC: `lu_guanlan`, `shen_zhaochen`, `song_zhiwei` | 主線：`v3_act1_taiqing_ladder`（`measure ladder`）<br>道具：`cred_taiqing_outer_token.c` | 獲太清外門玉牌，以可重複公差實錄取代順天叩拜。 |
| **第 87 章** | 燕隼 | 八荒立冬大考：黑石峽百斤重弓三箭擊殺缺耳鐵背荒狼王，黑山營雷烈認出扣弓舊習 | `/d/sects/bahuang/{gate,black_stone_gorge,black_mountain_camp}.c`<br>NPC: `yue_tingshan`, `tang_ying`, `ironback_wolf`, `lei_lie` | 主線：`v3_act1_bahuang_gorge`<br>道具：`cred_bahuang_camp_plate.c` | 獲八荒黑山營腰牌，暗繫燕山走山隊與軍方舊檔線索。 |
| **第 88 章** | 林鐵生 | 天工立冬大考：千鍛地火廊量出搬山傀儡半厘偏角與脆化麻點，熟鐵雙契復原過檢 | `/d/sects/tiangong/{gate,thousand_mechanisms_hall}.c`<br>NPC: `zhang_bailian`, `lu_zhanglao` | 主線：`v3_act1_tiangong_forge`（`repair puppet`）<br>道具：`puppet_tolerance_record.c`, `cred_tiangong_artisan_tag.c` | 獲天工閣外門匠牌與實測公差工單，紀錄內壁暗紫脆化異象。 |
| **第 89 章** | 顧玄 | 丹鼎立冬大考：百毒試藥谷察覺寒髓草共生雪線苔，溫火冷萃去火毒並封存酸泥樣本 | `/d/sects/danding/{gate,herb_garden}.c`<br>NPC: `ye_qingzhi`, `bai_henian`, `he_shou` | 主線：`v3_act1_danding_valley`（`extract moss`）<br>道具：`snowline_moss_sample.c`, `cred_danding_medical_tag.c` | 獲丹鼎百草谷藥牌，銀針澄澈無斑並留存水脈滲漏線索。 |
| **第 90 章** | 沈泥 | 冷風坡雪崩與何萬金搶馬逼宮，自掏四百靈石票賠清違約金換取三宗「朔望結算回執」暗網 | `/d/yunjin/{mudway_store,public_office,exchange_hall}.c`<br>NPC: `qiu_he`, `gu_lanzhou`, `luo_jiucheng` | 主線：`v3_yuntu_market_charter` 第三步<br>事件：`EVENT_TIER2_CRISIS` 已註冊 | 泥途商棧以實金立信，初步打通三宗底層採買合規對帳暗網。 |

---

## 第三卷 第二幕：宗門深造・偏科之影（第 91～101 章・Act 2 已實裝）

> 第二幕新增 21 間房間、14 名 NPC＋1 荒獸（並擴充複用 `mo_beggar`／`under_black_market_broker`）、8 項新道具、8 條主支線任務與 `evaluate_tier2_crisis()`。

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 實裝道具 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 91～92 章** | 柳清虛 | 藏星秘閣校出三百年「一度半」平推差異；升仙台見證 Lv.92 鶴鳴真人玉化取晶 | `/d/sects/taiqing/{hidden_archive,outer_observatory,quiet_peak,ascension_platform}.c`<br>NPC: `yu_shouzhuo`, `jian_su`, `xuan_ming` | 主線：`v3_taiqing_star_archive`<br>支線：`v3_act2_taiqing_ascension_secret`<br>道具：`tool_star_observation_plate.c`, `dao_crystal.c` | `collate archive`／`collect crystal` 揭示紙墨矛盾與玉化抽靈真相。 |
| **第 93～94 章** | 燕隼 | 長城射殺鐵甲寒犛、養息院探定心急鎮丸；鬼哭冰澗探冰起獲燕山斷箭與火藥出庫副本 | `/d/sects/bahuang/{restoration_hall,north_garrison_kitchen,great_wall_gate,north_watch,ghost_cry_gorge}.c`<br>NPC: `du_qinghe`, `qi_wushang`, `a_man`, `iron_yak` | 主線：`v3_bahuang_bloodline_watch`<br>支線：`v3_act2_bahuang_ghost_gorge`<br>道具：`yanshan_broken_arrow.c`, `bahuang_logistics_copy.c` | Lv.70 `iron_yak` 實戰、`probe ice` 與天興十九年火藥副本互鎖。 |
| **第 95 章** | 林鐵生 | 萬機地窟黑鐵齒輪共鳴十丈巨靈神機，陣圖工房破譯「推進錨機」構造並擋下晶柱試車 | `/d/sects/tiangong/{forge_yard,array_drafting_room,machinery_depths,vault_four}.c`<br>NPC: `ji_heng`, `wenjiu`, `chi_lian` | 主線：`v3_tiangong_ancient_mechanism`<br>道具：`tiangong_anchor_blueprint.c` | `inspect core`／`trace blueprint` 檢出脆化麻點並依規封存六根血精晶柱於四號庫房。 |
| **第 96～97 章** | 顧玄 | 地肺丹火窟暗隙窺見「萬山乙零四・南十三」煉血丹；廢丹崖剖白猿、醫理院互核十七份病案 | `/d/sects/danding/{earth_fire_pill_cave,discarded_pill_cliff,medical_archive}.c`<br>NPC: `tao_sheng`, `sun_wenlu` | 主線：`v3_danding_blood_pill_cases`<br>道具：`pill_reverse_dao_life.c`, `sample_discarded_pill.c` | `peek flue`／`dissect ape`／`crosscheck cases` 鎖定「三月壓抑、四月癌變、停藥七日反撲」病理邊界。 |
| **第 98～101 章** | 沈泥 / 群像 | 雲海鬼市散播稽核風聲截《私盟密帳索引》、莫三北上認「玄木」；地窖五方對帳、三元剝離晶絲與玄冥私印稽查破局 | `/d/yunjin/{mudway_store_cellar,three_sect_market,mountain_caravan_yard,ghost_market,wanbao_back_alley}.c`<br>NPC: `mo_san`, `gui_jianchou`, `gray_robed_scribe`, `a_si` | 主線：`v3_five_way_evidence_convergence`、`v3_act2_yunjin_ghost_and_sanyuan`<br>道具：`ev3_private_purchase_ledger.c`, `cyan_crystal_filament_vial.c` | `rumor audit`／`strip filament` 並啟動 `evaluate_tier2_crisis()` 推進至 `T-1` 北荒勘探局勢。 |

---

## 第三卷 第三幕：絕嶺尋蹤・萬古迷霧（第 102～111 章・Act 3 已實裝）

> 第三幕新增 `/d/wastes/` 16 間房間、8 名 NPC／荒獸與敵對頭目（`qi_shiliu`、`han_su`、`bai_yan`、`yuan_qing`、`shuangtou_dilong`、`ice_bear_king`、`private_league_envoy`、`tiger_mech_beast`）、9 項道具物證與 5 條 Act 3 任務。

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 實裝道具 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 102～103 章** | 燕隼 / 顧玄 | 黑山北關雪道會韓素領韓林特徵圖、雪橇磁偏角揭重車偽裝；永凍血原協破雙頭霜甲地龍與前哨半寸對照實驗 | `/d/wastes/{black_mountain_pass,missing_families_hall,south_approach,snow_caravan_camp,north_outpost_infirmary,frozen_blood_plain}.c`<br>NPC: `qi_shiliu`, `han_su`, `bai_yan`, `shuangtou_dilong`, `mu_xue` | 主線：`v3_north_wastes_expedition`<br>道具：`pill_herb_poultice.c` | `inspect sleighs`／`test poultice`／`throw smoke` 與 Lv.82 `shuangtou_dilong` 對戰確立染煞病例互核。 |
| **第 104～106 章** | 燕隼 / 林鐵生 / 顧玄 | 墨黑雪壁釘岩垂降黑冰斷谷驗九骸與血書名冊；戰神遺塚《沉岳引》護心鏡與冰熊王；方舟冷卻艙三息化驗 | `/d/wastes/{expedition_camp,rift_watch,black_ice_valley,old_expedition_camp,war_god_tomb,ark_foundation}.c`<br>NPC: `ice_bear_king` | 支線：`v3_act3_war_god_tomb`<br>道具：`hanlin_copper_whistle.c`, `ev3_yanshan_blood_note.c`, `ev3_expedition_roster.c`, `ev3_heart_guard_mirror.c` | `rappel cliff`／`excavate remains`／`search alcove`／`resonate totem`／`test coolant` 嚴守「燕山生死 open」與無蓋印邊界。 |
| **第 107～108 章** | 柳清虛 / 沈泥 | 八角核心圓台五器再鳴見三大先民職能光影；後勤石鋼廳室合璧九城總契與乙巳舊盟抄頁揭「沈雲妮」舊約 | `/d/wastes/{ark_core_chamber,ark_logistics_hall}.c`<br>聯動 `star_law_hall` / `machinery_depths` / `exchange_hall` / `ghost_market` | 史詩：`v3_five_relic_resonance`<br>道具：`ninety_city_treaty_copy.c` | `place relics`／`join treaty` 完成 Stage 1–3 五器再鳴與第五階段舊約核對（仍缺三宗掌門知情鏈）。 |
| **第 109～111 章** | 群像 | 鎖死東側七成總閘取鑽頭玉瓶；冰谷雪崩破敵並一箭絕殺大執事奪副執印；返關歸還銅哨、串聯三宗與偏峰定約 | `/d/wastes/{ark_cooling_breach,ice_valley_exit}.c`、`/d/sects/taiqing/quiet_peak.c`<br>NPC: `private_league_envoy`, `tiger_mech_beast`, `yuan_qing`, `jian_su` | 主線：`v3_ark_excavation_evidence`<br>事件：`v3_preserve_field_evidence`<br>道具：`ev3_drill_head.c`, `ev3_mother_liquid_vial.c`, `ev3_envoy_tally.c` | `lock valve`／`trigger avalanche` 並達成 `EV319` 與 `EVENT_TIER2_CRISIS` `T-1 → T0`（`hearing_ready`）就緒。 |

---

## 第三卷 第四幕：雲頂論道・三元鎮脈（第 112～120 章・Act 4 已實裝）

> 第四幕新增 `/d/yunjin/` 6 間會武／隔離／回收廠房間與 `/d/sects/bahuang/west_wall_breach.c`（合計 +7 房），新增 8 名 NPC／掌門／首徒兼二階極境【冰獄骨龍王】（`zixiao_zhenren`、`tiebei_shanzhu`、`xuanshu_menzhu`、`zhao_lie`、`li_qingyun`、`wang_tieniu`、`han_cang`、`ice_bone_dragon`），新增 6 項道具物證，實裝與補齊 7 條 Act 4 任務（含新增 `v3_act4_cloud_top_tournament`、`v3_act4_sanyuan_defense`）暨 `EVENT_TIER2_CRISIS` `defense_outcome` 三檔評價。

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 實裝道具 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 112～114 章** | 五人群像 | 偏峰合力剝除元青晶絲；問道天台百工試三錘破煞火魔偶、雙盲銀針檢九轉血丹、點星震敗王鐵牛並踏東北三度半息死角勝韓蒼 | `/d/sects/taiqing/quiet_peak.c`、`/d/yunjin/{tournament_craft_arena,tournament_combat_arena}.c`<br>NPC: `jian_su`, `yuan_qing`, `zhao_lie`, `li_qingyun`, `wang_tieniu`, `han_cang` | 支線：`v3_act4_cloud_top_tournament`<br>道具：`sanyuan_shengji_dan.c`, `brittle_shahuomou_shard.c`, `wang_red_pill_vial.c` | `strip yuanqing`／`strike puppet`／`test doubleblind`／`dodge thunder` 檢出比試違規暨早期晶化病象。 |
| **第 115～116 章** | 沈泥 / 群像 | 交割大廳拆穿萬寶閣百八十萬期貨挪用封七口帳箱；問道天台高台四線呈堂促使三掌門頒聯席令兼觸發鶴壽吞液、玄冥毀令 | `/d/yunjin/{exchange_hall,hearing_hall}.c`<br>NPC: `luo_jiucheng`, `gu_lanzhou`, `he_wanjin`, `zixiao_zhenren`, `tiebei_shanzhu`, `xuanshu_menzhu` | 主線：`v3_evidence_chain_hearing`<br>事件：`v3_cross_sect_evidence_audit`<br>道具：`wanbao_black_iron_box.c` | `audit wanbao` 封庫與 `EV320–EV321` 程序保管鏈實證。 |
| **第 117～119 章** | 群像 | 毒域東側搶救護箱衛士與陸觀瀾；石牌坊生石灰暨百草中和隔離霧截毒；萬機玄鐵暗門推巨靈神機撐長城西段缺口破核退骨龍王 | `/d/yunjin/{stone_arch_quarantine,crystal_poison_edge}.c`、`/d/sects/bahuang/west_wall_breach.c`<br>NPC: `lu_guanlan`, `du_qinghe`, `ice_bone_dragon` | 主線：`v3_act4_sanyuan_defense`<br>事件：`v3_crystal_quarantine_response`、`v3_north_wall_beast_surge`<br>道具：`sanyuan_isolation_mist.c` | `rescue box`／`spread lime`／`brace gate` 暨擊退 Lv.95 `ice_bone_dragon`；驗證三元有限協同。 |
| **第 120 章** | 沈泥 / 韓素 | 停採封爐、走山隊忠烈平反與「雲記」復名（高層姓氏仍缺）；開設西街無毒回收廠安置陶生窯工兼簽《雲津萬山互市協約》 | `/d/yunjin/west_street_recycling.c`、`/d/wastes/missing_families_hall.c`<br>NPC: `han_su`, `tao_sheng`, `mo_san` | 主線：`v3_postwar_reform_and_restitution`<br>道具：`yunjin_relief_treaty.c` | `open recycling` 與 `EV325` 改革落地；`evaluate_tier2_crisis()` 計入 `defense_outcome`。 |

---

## 第三卷 第五幕：百草格物與萬古星門（第 121～126 章・Act 5 已實裝）

> 第五幕新增 3 間終局與跨界節點（`/d/sects/taiqing/{sealed_observatory,ark_portal_chamber}.c`、`/d/realm/peach_plateau.c`）、`zhou_shishu.c`（太清外門周執事）、7 項破境暨託付道具物證與 2 條終局任務（`v3_act5_lvl100_trials` 暨全段實裝收官之 `v3_tier2_departure`），完整落實第三卷全五幕。

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 實裝道具 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 121～123 章** | 五人分進 | 丹鼎《三元本草祛道錄》立拒絕權、天工拒接神識立可拆卸連動台、八荒《分段輪替操典》粉青岩、太清《逆星歲差補遺》納反例、泥途更匾總號暨《萬山共治章程》破境 Lv.100 | `/d/sects/danding/medical_archive.c`、`/d/sects/tiangong/machinery_depths.c`、`/d/sects/bahuang/black_mountain_camp.c`、`/d/sects/taiqing/star_law_hall.c`、`/d/yunjin/mudway_store.c`<br>NPC: `zhou_shishu`, `sun_wenlu`, `ji_heng`, `lei_lie`, `shen_zhaochen`, `qiu_he` | 主線：`v3_act5_lvl100_trials`<br>史詩：`v3_tier2_departure` Stage 1<br>道具：`sanyuan_bencao_draft.c`, `detachable_feedback_spec.c`, `bahuang_rotation_manual.c`, `reverse_star_addendum.c`, `wanshan_charter_deed.c` | `publish bencao` / `install rig` / `compile manual` / `publish addendum` / `decentralize ledger` 不入偏科破境人間錨點。 |
| **第 124～126 章** | 五人群像 | 封存觀測室五器十倍共振召假天排斥劫雲兼揭十七先輩《祖師密錄》；總號拆權收故人家書與莫三三十年約；祖庭主傳送室五石台同步開星門墜入 Tier 3 望見三座太古巨構 | `/d/sects/taiqing/{sealed_observatory,ark_portal_chamber}.c`、`/d/yunjin/mudway_store_cellar.c`、`/d/realm/peach_plateau.c`<br>NPC: `zixiao_zhenren`, `tiebei_shanzhu`, `xuanshu_menzhu`, `song_zhiwei`, `qi_shiliu`, `mo_san`, `han_su` | 主線：`v3_act5_lvl100_trials` Step 6<br>史詩：`v3_tier2_departure` Stage 2–3<br>道具：`ancestor_secret_record.c`, `hometown_letters_bag.c` | `resonate relics` / `activate gate` / `enter gate` / `gaze horizon` 完成《第三卷・名山問道》全卷閉環。 |

---

## 六大物證缺口標準五欄對照表 (The Six Evidence Gaps Ledger)

| 編號 | 物證名稱 (`item`) | 物證型態 (`type`) | 來源鏈與取得者 (`source & chain`) | 證明力限制與當前等級 (`strength & limit`) | 當前狀態與最新進展 (`status`) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **GAP-01** | **濁水腐骨毒囊交割單** | 毒囊作坊原始出貨帳 | 沈泥於濁水黑水埗提純作坊密櫃起獲，具趙德貴代簽與商會戳記 | **`conclusive` (關鍵定罪鐵證)**<br>*與松崖驛毒樣、白先生毒理三方互鎖* | **已閉合**（Ch. 64 取得 `relay_poison_sample.c`） |
| **GAP-02** | **烈礬特級耐火泥出貨單** | 地火堡原始提領底單 | 林鐵生於烈礬三號井救險後獲老爐頭韓老調託付，蓋有金蓮環刀印 | **`corroborative` (強間接佐證)**<br>*與府城丙字柒號黑釜殘渣成分物理咬合完全吻合* | **已補齊**（Ch. 63 取得 `liefan_clay_batch.c`） |
| **GAP-03** | **鎮風關走山令與出關舊檔** | 衛所通行殘牌與公文 | 燕隼於鎮風邊防衛所地下案卷室調閱五年舊檔，起獲燕山箭記殘牌 | **`corroborative` (強間接佐證)**<br>*證實商會五年前秘密勘探北崖礦脈，雷震將軍用印作保* | **已補齊**（Ch. 62 取得 `shan_token_half.c`） |
| **GAP-04** | **重石抽減鐵木指令拓本** | 採石場機密帳簿拓本 | 林鐵生於重石穿山寨重造絞盤平息罷工後，少工頭杜小山血指畫押 | **`corroborative` (強間接佐證)**<br>*證實商會內堂於塌方前兩個月強令抽減北崖三成鐵木支護* | **已補齊**（Ch. 66 取得 `zhongshi_timber_order.c`） |
| **GAP-05** | **一號密室總堂交割正底單** | 商會地下核心地契底帳 | 藏於金石商會總堂地下「天字一號密室」外層鐵櫃，文承敬火漆封存 | **`conclusive` (關鍵定罪鐵證)**<br>*三萬斤地煞血精流水與金蓮環刀印完全吻合，法定保管鏈滴水不漏* | **已閉合**（Ch. 73 取得 `under_canal_deed.c`） |
| **GAP-06** | **軍器局雷管雙聯火印存根** | 軍械調撥雙聯存根底冊 | 城防司披甲庫與硝火作當面對質起獲，鋸齒邊緣咬合吻合 | **`conclusive` (關鍵定罪鐵證)**<br>*鋼齒鋸齒物理咬合分毫不差，雙聯騎縫火印直指錢百貴* | **已閉合**（Ch. 72 取得 `detonator_serial_ledger.c`） |
