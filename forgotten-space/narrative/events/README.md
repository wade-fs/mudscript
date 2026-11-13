# 敘事事件與系統機制映射 (Narrative Events Mapping)

本目錄記錄小說各卷各幕的核心敘事事件，及其在 MUD 引擎中由 `QUEST_ENGINE_D` (`/daemon/quest_engine_d.c`)、`MYSTERY_D` (`/daemon/mysteryd.c`)、`WORLD_STATE_D` (`/daemon/world_state_d.c`)、`PHASE_D` (`/daemon/phase_d.c`) 與 `CITY_D` (`/daemon/city_d.c`) 管理的實作映射。

* 卷二專屬事件與詳細機制規範請參見：[第二卷：金石雙壁事件記錄簿](volume2_events.md)

---

## 第一卷：黑石破曉事件映射表（第 1～38 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 觸發動詞與房間 | 系統事件 ID (`personal_event/*`) | 機制與天命獎勵 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 1 章** | 顧玄<br>*(採藥孤兒)* | 晨曦洗滌石板，破除認知盲區，拓印逆星斷碑 | `study stone`<br>`tuoyin stone`<br>`/d/village/stream.c` | `study_ruin_stone`<br>`tuoyin_stone` | 悟性提升、獲得【殘缺星圖拓片】(`stele_rubbing.c`)、**天命 +1** |
| **第 2 章** | 林鐵生<br>*(打鐵學徒)* | 地爐千錘百鍊，粗鐵礦核碎裂，顯露不融黑鐵 | `bellows`<br>`strike ore`<br>`/d/village/forge.c` | `forge_ancient_black_iron` | 領悟「瘋魔打鐵法」、獲得【太古不融黑鐵構件】(`ancient_black_iron.c`)、**天命 +1** |
| **第 3 章** | 燕隼<br>*(獵戶之子)* | 追蹤黑熊暗紫濁血，以荒血共鳴戰神圖騰玄柱 | `trap`<br>`track`<br>`totem`<br>`/d/village/forest.c` | `commune_forest_totem` | 臂力身法淬鍊、加固防獸陷阱降低獸潮警報、**天命 +1** |
| **第 4 章** | 柳清虛<br>*(破落道童)* | 孤岩撥開老松取道化晶石，神識窺天天羅偽籠 | `meditate`<br>`search pine`<br>`stargaze`<br>`/d/village/altar.c` | `search_altar_pine`<br>`stargaze_altar` | 獲得【道化晶石殘片】(`dao_crystal.c`)、悟性+2 靈性+2、**天命 +1** |
| **第 5 章** | 沈泥<br>*(流浪乞兒)* | 貼牆偷聽官軍勒索內幕，爛泥深處扒出天門引 | `eavesdrop`<br>`search wood`<br>`/d/village/shed.c` | `eavesdrop_shed`<br>`search_shed_wood` | 洞察商道實情（定力+1）、獲得【萬物行商・天門引】(`tianmen_token.c` 休眠殘缺)、**天命 +1** |

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
| **第 59 章** | 顧玄 | 馳抵青河縣直面爭水斷水黑幕，集市揭穿假藥與高利貸 | 青河縣城百草集市<br>`/d/routes/qinghe_waterway.c` | 任務：`v2_six_county_evidence` | 亮出杏林醫籍揭穿商會以陳冒新，平息藥農流血械鬥。 |
| **第 60 章** | 五人剪輯 | 匯總四線書信，打破一次性買齊幻想，說服靈植道觀放水 | 青河官驛與靈植道觀 | 道具：青河水利批函 | 以次級苦參替代方破局，十二箱救命藥草發往黑石鋪。 |
| **第 61 章** | 柳清虛 | 天風谷頂風採石，水銀渾天鏡算三息風眼採得石英核 | 鎮風縣天風谷鷹嘴崖 | 道具：`fengshi_quartz.c` | 採得極品風蝕石英核，折抵冬糧撫恤平息衛所散人火併。 |
| **第 62 章** | 燕隼 | 雪狼夜襲死守糧站，調閱五年舊檔起獲大伯走山令殘牌 | 鎮風衛所地下案卷室<br>北塞烽燧 | 任務：`v2_six_county_evidence`<br>道具：`shan_token_half.c` | 查明商會五年前僱傭燕山探礦，起獲燕山箭記走山令殘牌。 |
| **第 63 章** | 林鐵生 | 烈礬地火堡深井通風排險救人，起獲特級耐火泥出貨單 | 烈礬地火堡紅砂坳<br>三號深井 | 任務：`v2_six_county_evidence`<br>道具：`liefan_clay_batch.c` | 救出 122 名礦工，起獲商會內堂專用印耐火泥單（`corroborative`）。 |
| **第 64 章** | 沈泥 | 踩踏濁水浮橋道金蟬脫殼避連弩，起獲毒囊交割底單 | 濁水泥螺灘黑水埗<br>排石暗渠與水樓 | 任務：`v2_six_county_evidence`<br>道具：`relay_poison_sample.c` | 截獲商會後勤房提領六十斤地陰腐骨散底單，逼近 `conclusive`。 |
| **第 65 章** | 沈泥 | 深入暗渠見舊盟柯九算，三方互鎖證實「雲記沈雲妮」身世 | 濁水黑水埗廢棄暗渠<br>柯九算石室 | 任務：`v2_six_county_evidence`<br>道具：`yunji_roster.c` | 身世三階關係證實（`conclusive` on identity），得手抄名冊。 |
| **第 66 章** | 林鐵生 | 穿山寨重造雙齒棘輪絞盤救險，起獲抽減鐵木指令拓本 | 重石石碾坡穿山寨<br>`seg_city_zhongshi` | 任務：`v2_six_county_evidence`<br>道具：`zhongshi_timber_order.c` | 重造絞盤化解罷工，揭發礦難前抽減鐵木真相；太古石槨氣孔伏筆。 |
| **第 67 章** | 全員群像 | 南關小棧四線合璧，沈泥坦白身世；商會全面凍結飛錢奪權 | `/d/city/gate/gate_south_inn.c`<br>`/d/city/south/shanghui_hq.c` | 任務：`v2_six_county_evidence` 完成 | 六缺口補齊四項，沈泥坦承密室機括；錢百川凍結飛錢停職蘇凝霜。 |

---

## 第二卷 第四幕：信用凍結・三方會審（第 68～76 章）

| 章節 | 視角主角 | 核心敘事事件 | MUD 房間與 NPC 互動 | 任務鏈 / 物證關聯 | 系統機制與成果 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 68 章** | 沈泥 | 飛錢成紙引發總號擠兌，比對底冊查明扣押九八足色官銀 | `/d/city/center/pawnshop.c`<br>NPC: `center_pawn_jia` | 任務：`v2_act4_tripartite_tribunal` (Step 1) | 勘破準備金成色破綻，粉碎假象。 |
| **第 69 章** | 顧玄 | 糧商串通停業哄抬，攜手常平倉呈遞分級保命條陳 | `/d/city/north/granary.c`<br>NPC: `granary_liubingzhong` | 任務：`v2_act4_tripartite_tribunal` (Step 2) | 以工代賑、分級配給平糶，穩住民心。 |
| **第 70 章** | 顧玄 | 瘴氣倒灌西水門，連夜配製苦參替代方撲滅疫情瓦解黑市 | `/d/city/center/clinic.c`<br>NPC: `center_doctor_bai` | 任務：`v2_act4_tripartite_tribunal` (Step 3) | 熬製苦參辟疫飲解救千人，粉碎藥商囤積。 |
| **第 71 章** | 林鐵生 | 西水門金剛砂磨毀導軌卡死渠首，螺紋頂升衝沙排險 | `/d/city/gate/gate_west.c`<br>NPC: `gong_mochui` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`miner_thumbprints.c` | 頂升閘葉反向衝沙，取得礦工血指結狀。 |
| **第 72 章** | 燕隼 | 查訪城防庫與硝火作，對質起獲軍需雷管雙聯火印存根 | `/d/city/north/gong_fireworks.c`<br>NPC: `gong_fireworks_master` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`detonator_serial_ledger.c` | 鋸齒騎縫火印咬合無誤，鎖定錢百貴。 |
| **第 73 章** | 沈泥 / 莫三 | 水情手令掩護潛入天字一號密室，起獲正底單加蓋火漆 | `/d/city/south/under_canal.c`<br>NPC: `center_wenchengjing` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`under_canal_deed.c` | 搶出三萬斤血精交割正底單，法定保管鏈完備。 |
| **第 74 章** | 五人群像 | 南關小棧通宵復盤，定罪、政治平衡、民生止血三層籌碼 | `/d/city/gate/gate_south_inn.c` | 任務：`v2_act4_tripartite_tribunal` | 擊退刺探死士，五欄物證模型完備審計。 |
| **第 75 章** | 全員群像 | 府衙正堂三方會審，三印合符定讞，錢百川革職下獄 | `/d/city/center/yamen_hall.c`<br>NPC: `yamen_magistrate` | 任務：`v2_act4_tripartite_tribunal`<br>道具：`tripartite_warrant.c` | 三印合符定讞，查抄十二萬兩現銀，蘇凝霜雪冤！ |
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

## 六大物證缺口標準五欄對照表 (The Six Evidence Gaps Ledger)

| 編號 | 物證名稱 (`item`) | 物證型態 (`type`) | 來源鏈與取得者 (`source & chain`) | 證明力限制與當前等級 (`strength & limit`) | 當前狀態與最新進展 (`status`) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **GAP-01** | **濁水腐骨毒囊交割單** | 毒囊作坊原始出貨帳 | 沈泥於濁水黑水埗提純作坊密櫃起獲，具趙德貴代簽與商會戳記 | **`conclusive` (關鍵定罪鐵證)**<br>*與松崖驛毒樣、白先生毒理三方互鎖* | **已閉合**（Ch. 64 取得 `relay_poison_sample.c`） |
| **GAP-02** | **烈礬特級耐火泥出貨單** | 地火堡原始提領底單 | 林鐵生於烈礬三號井救險後獲老爐頭韓老調託付，蓋有金蓮環刀印 | **`corroborative` (強間接佐證)**<br>*與府城丙字柒號黑釜殘渣成分物理咬合完全吻合* | **已補齊**（Ch. 63 取得 `liefan_clay_batch.c`） |
| **GAP-03** | **鎮風關走山令與出關舊檔** | 衛所通行殘牌與公文 | 燕隼於鎮風邊防衛所地下案卷室調閱五年舊檔，起獲燕山箭記殘牌 | **`corroborative` (強間接佐證)**<br>*證實商會五年前秘密勘探北崖礦脈，雷震將軍用印作保* | **已補齊**（Ch. 62 取得 `shan_token_half.c`） |
| **GAP-04** | **重石抽減鐵木指令拓本** | 採石場機密帳簿拓本 | 林鐵生於重石穿山寨重造絞盤平息罷工後，少工頭杜小山血指畫押 | **`corroborative` (強間接佐證)**<br>*證實商會內堂於塌方前兩個月強令抽減北崖三成鐵木支護* | **已補齊**（Ch. 66 取得 `zhongshi_timber_order.c`） |
| **GAP-05** | **一號密室總堂交割正底單** | 商會地下核心地契底帳 | 藏於金石商會總堂地下「天字一號密室」外層鐵櫃，文承敬火漆封存 | **`conclusive` (關鍵定罪鐵證)**<br>*三萬斤地煞血精流水與金蓮環刀印完全吻合，法定保管鏈滴水不漏* | **已閉合**（Ch. 73 取得 `under_canal_deed.c`） |
| **GAP-06** | **軍器局雷管雙聯火印存根** | 軍械調撥雙聯存根底冊 | 城防司披甲庫與硝火作當面對質起獲，鋸齒邊緣咬合吻合 | **`conclusive` (關鍵定罪鐵證)**<br>*鋼齒鋸齒物理咬合分毫不差，雙聯騎縫火印直指錢百貴* | **已閉合**（Ch. 72 取得 `detonator_serial_ledger.c`） |
