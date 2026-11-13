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

## 六大物證缺口標準五欄對照表 (The Six Evidence Gaps Ledger)

| 編號 | 物證名稱 (`item`) | 物證型態 (`type`) | 來源鏈與取得者 (`source & chain`) | 證明力限制與當前等級 (`strength & limit`) | 卷三調查目標 (`target`) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **GAP-01** | **濁水腐骨毒囊批單** | 藥市大宗採辦單據 | 顧玄自趙德貴吐血樣品化驗比對，程通四海帳單核實 | `corroborative` (補強物證)<br>*限制：僅證明毒源流向，尚未扣下批單原件* | 追查專材長街濁水暗櫃提貨人印章與交割日期。 |
| **GAP-02** | **烈礬特級灰陶票根** | 燒窯出廠特用票根 | 林鐵生自丙字柒號黑釜殘片拓印，比對耐火土配比 | `corroborative` (補強物證)<br>*限制：證明坩堝非民用，缺乏提貨出庫單號* | 調取烈礬縣駐城商棧大窯訂貨合同與特殊鋼印記號。 |
| **GAP-03** | **鎮風關轉運通牒** | 官方軍防通行公文 | 燕隼自獵戶情報網與南關巡丁口風比對 | `lead_only` (情報線索)<br>*限制：知曉繞道轉運，無具體簽發武官指紋戳記* | 取得八方鏢局往返鎮風關之重車調度簿副冊。 |
| **GAP-04** | **重石採石場底帳** | 礦坑原始提純流水帳 | 柳清虛推算地煞暗渦週期，對照當鋪賈朝奉口風 | `lead_only` (情報線索)<br>*限制：僅知有大批玄鐵與地煞外流，帳本在重石縣* | 安排重石縣採石場工頭舊帳審計或暗渠追蹤。 |
| **GAP-05** | **一號密庫總勘提單** | 商會核心庫房調用單 | 趙德貴口供指出從三號庫轉入一號庫 | `lead_only` (供詞線索)<br>*限制：口供孤證，未見一號庫實物提單與錢百川簽印* | 潛入金石商會地下暗渠與一號庫探查實物出庫帳冊。 |
| **GAP-06** | **趙德貴親供結狀** | 府衙死牢囚犯親筆供詞 | 府衙死牢夜審，文承敬主簿在場公證加蓋硃砂印 | `conclusive` (關鍵核心人證)<br>*限制：需 GAP-01~05 實物證據鏈交叉鎖死錢百川* | 保全趙德貴性命，防止商會刺客滅口，作為公堂鐵證。 |
