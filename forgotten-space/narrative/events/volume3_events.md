# 第三卷事件紀錄簿（Tier 2 Event Ledger）

> 版本：0.1（第一階段世界建設）  
> 事件 ID：`EV3xx`  
> 原則：事件是世界狀態的變化，不等同任務；任務是角色可採取的行動鏈，第二階段再建立 JSON。事件證據嚴守第二卷五欄物證鐵律。

## 0. 事件資料欄位

每筆事件應記錄：`event_id`、時間／季節、地點、參與者、觸發條件、可觀察現象、實際原因（若尚未證實則標 open）、結果、世界狀態影響、證據及證明力限制、關聯章節、關聯任務。

證據等級沿用：`lead_only` → `corroborative` → `conclusive`。不得因主角推理合理就自動升級。

## 1. 事件總表

| ID | 暫定事件名 | 區域 | 性質 | 狀態 | 預定章節範圍 |
|---|---|---|---|---|---|
| EV301 | 北境雪原行旅與淘汰者相遇 | 北境官道 | 旅途／民生 | canon (Act 1 實裝) | 83 |
| EV302 | 雲津商埠入市與保證金爭議 | 雲津 | 商業／制度 | canon (Act 1 實裝) | 84 |
| EV303 | 三山外門考核分流 | 三宗 | 入門／人物 | canon (Act 1 實裝) | 85–89 |
| EV304 | 星曆原件差異與升仙台玉化真相 | 太清宮 | 調查／知識 | canon (Act 2 實裝) | 91–92 |
| EV305 | 長城寒犛戰、急鎮丸與鬼哭冰澗 | 八荒 | 軍事／醫療／調查 | canon (Act 2 實裝) | 93–94 |
| EV306 | 萬機地窟神機共鳴與晶柱之爭 | 天工閣 | 工藝／探索 | canon (Act 2 實裝) | 95 |
| EV307 | 百草谷藥田水脈微滲對照 | 丹鼎宗 | 生態／醫療 | canon (Ch. 96 前置實裝) | 89、96 |
| EV308 | 地肺丹火血丹密會與廢丹崖剖驗 | 丹鼎宗 | 證據／病理 | canon (Act 2 實裝) | 96–97 |
| EV309 | 履約危機、鬼市截帳、三元剝離與稽查破局 | 雲津 | 商業／對帳／反撲 | canon (Ch. 90、98–101 全實裝) | 90、98–101 |
| EV310 | 北荒聯合勘探隊成行 | 八荒／北荒 | 主線／軍務 | canon (Act 3 實裝) | 102 |
| EV311 | 永凍血原雙頭霜甲地龍伏擊與醫療對照 | 北荒 | 生態／戰鬥／醫療 | canon (Act 3 實裝) | 103 |
| EV312 | 黑冰斷谷走山隊九骸與血書名冊封存 | 北荒 | 調查／燕山線 | canon (Act 3 實裝) | 104 |
| EV313 | 戰神巨石遺塚《沉岳引》與燕山護心鏡 | 北荒 | 身世／懸念 (`open`) | canon (Act 3 實裝) | 105 |
| EV314 | 方舟主引擎冷卻艙段三息化驗 | 北荒 | 太古遺跡／病理 | canon (Act 3 實裝) | 106 |
| EV315 | 八角核心圓台五器再鳴與太古光影殘篇 | 北荒 | 主線／知識 (`open`) | canon (Act 3 實裝) | 107 |
| EV316 | 後勤控台九城總契合璧與第五階段身世揭曉 | 北荒 | 商盟歷史／契約 | canon (Act 3 實裝) | 108 |
| EV317 | 東側冷卻豁口鑽山傀儡盜掘與總閘鎖七成 | 北荒 | 災害／證據 | canon (Act 3 實裝) | 109 |
| EV318 | 冰谷窄口雪崩伏擊與絕殺私盟大執事 | 北荒 | 戰鬥／政治 | canon (Act 3 實裝) | 110 |
| EV319 | 攜四組火漆證歸山、三宗串聯與偏峰試治約 | 雲津／三宗 | 證據／政治 | canon (Act 3 實裝) | 111 |
| EV320 | 雲頂三宗論道會武 | 三宗／雲津 | 公共盛會 | canon premise | 112–114 |
| EV321 | 三宗內部證詞與交易帳目交叉核對 | 三宗／雲津 | 調查／制度 | proposed | 115–116 |
| EV322 | 長老道化急變 | 三宗 | 危機／醫療 | canon premise | 117 |
| EV323 | 北荒獸潮壓迫防線 | 八荒／北荒 | 世界事件 | canon premise | 118–119 |
| EV324 | 三元互濟的有限驗證 | 北荒／三宗 | 知識／實驗 | canon premise; 可行範圍 open | 119–120 |
| EV325 | 三宗改革提案與利益反彈 | 三宗／雲津 | 政治／社會 | proposed | 120 |
| EV326 | 二階圓滿與假天排斥徵兆 | Tier 2 各區 | 修行／世界規則 | canon premise | 121–124 |
| EV327 | 北方古陣開啟與單向洞天入口 | 北荒 | 卷末轉場 | canon premise; 安全條件 open | 125–126 |

## 2. 事件詳目

### EV301：北境雪原行旅與淘汰者相遇

- **時間**：第二卷第 82 章初秋離城後（第 83 章寫實為第 6 至第 17 日雪原行旅；霜降前後翻越青石埡口）。
- **地點**：鎮風關北塞北行經北境雪原官道（`/d/wastes/north_road/cold_plain_entry.c` 黑風口雪坡 → `post_station.c` 斷崖石棚驛站 → `qing_pass.c` 青石埡口）。
- **參與者**：五位主角、穆雪（`mu_xue`）、南下車隊、八荒斷臂退門武師周鐵山（`zhou_tieshan`）、丹鼎手腕爛傷退門藥徒陳青（`chen_qing`）（註：莫三先隨陸大山南返，至第 98 章始率金石冬運隊北上）。
- **可觀察現象**：過黑風口後氣溫驟降、雪粒抽面；斷崖石棚內退門者經脈／雙手帶酸蝕創傷且背負退籍文書與歲貢債務（實裝為 `v3_act1_cold_plain_rescue`：`brew decoction` 熬野菊湯劑救凍傷腳夫並訪談周、陳）。
- **事件價值**：讓讀者看到名山制度在入門考核以外的社會成本與外部代價轉嫁；避免把「考不上」只寫成背景數字。
- **證據限制**：淘汰者的控訴是個人證言，不足以直接代表三宗整體或證明普遍故意傷害。

### EV302：雲津商埠入市與保證金爭議

- **地點**：雲津仙集 `north_road_gate.c` → `wanshan_square.c` → 萬山商埠公所（`public_office.c`）、三宗交割廳暨雲海票號（`exchange_hall.c`）、萬寶閣雲津分號（`wanbao_pavilion.c`）、西街貨棧區（`western_warehouse_street.c`）與泥途商棧（`mudway_store.c`）。
- **參與者**：沈泥（Ch. 85 餞別同伴獨守商棧）、何萬金（`he_wanjin`）、羅九秤（`luo_jiucheng`）、顧蘭舟（`gu_lanzhou`）、邱禾（`qiu_he`）。
- **觸發**：沈泥持蘇晚晴與賈朝奉聯署跨州特等通行信印申請落腳經營（Ch. 84）。
- **衝突**：信印不免除保證金、倉儲責任與雲海票號五百靈石起存／三分匯水；何萬金欲搶扣西街甲字七號倉契並以雙倍罰則試單施壓。
- **結果方向**：沈泥以六縣實物貨單與信用開張泥途商棧、以三個月短契僱用邱禾（實裝為 `v3_northbound_and_yunjin_arrival`、`v3_yuntu_market_charter`）。
- **世界規則**：三宗交割廳與雲海票號已實裝於 `/d/yunjin/exchange_hall.c`，公所常態仲裁規則依 Ch. 84「貨損自負、逾期三日扣倉」運作。

### EV303：三山外門考核分流

- **地點**：太清登天雲梯山門→周天星律院（`/d/sects/taiqing/{gate,outer_court,star_law_hall}.c`）、八荒萬鈞問心谷→黑石峽→黑山營（`/d/sects/bahuang/{gate,black_stone_gorge,black_mountain_camp}.c`）、天工閣千鍛地火廊（`/d/sects/tiangong/{gate,thousand_mechanisms_hall}.c`）、丹鼎宗百毒試藥谷暨百草谷（`/d/sects/danding/{gate,herb_garden}.c`）。
- **參與者**：
  - **柳清虛（Ch. 86）**：陸觀瀾、宋知微、沈照塵（`v3_act1_taiqing_ladder`：`measure ladder` 測出東北測星柱滯後千分之三息）。
  - **燕隼（Ch. 87）**：岳停山、唐映、雷烈（`v3_act1_bahuang_gorge`：黑石峽擊殺缺耳鐵背荒狼王）。
  - **林鐵生（Ch. 88）**：章百鍊、魯長老（`v3_act1_tiangong_forge`：`repair puppet` 量出青銅搬山傀儡軸套半厘偏角與脆化麻點）。
  - **顧玄（Ch. 89）**：葉青枝、白鶴年、鶴壽、孫聞露（`v3_act1_danding_valley`：`extract moss` 借雪線苔溫火冷萃寒髓草）。
- **事件核心**：四人分別在立冬開山大考以不服盲從的實證方法通過考核（實裝對應 4 條主線與 4 枚外門信物 `/clone/item/cred_*.c`）。
- **沈泥線**：第 85 章送別同伴後留守雲津，於第 90 章獨立面對冷風坡雪崩履約危機，並藉賠清違約金自三宗採買取得「朔望結算回執貨單」合法暗網渠道。
- **時間軸已定案**：四年一開改為三年一度，定於立冬日同日舉行（Ch. 84–89；離城至立冬開考歷約三十餘日）。

### EV304：星曆原件差異與升仙台玉化真相（第 91–92 章實裝）

- **地點**：太清周天星律院（`star_law_hall.c`）、藏星秘閣（`hidden_archive.c`）、天柱觀星台（`outer_observatory.c`）、清修偏峰（`quiet_peak.c`）、升仙台石築靈堂（`ascension_platform.c`）。
- **參與者**：柳清虛、宋知微、陸觀瀾、余守拙（`yu_shouzhuo`）、沈照塵、簡素真人（`jian_su`）、玄冥真人（`xuan_ming`）、鶴鳴真人（Lv.92 遺骸）。
- **實情與實裝**：Ch. 91 柳清虛預警四分半暴雪誤差後持限時手令入秘閣，核出三百年青檀宣紙定本將甲子冬至七十餘星宿人為順時針平推「一度半」（`v3_taiqing_star_archive`、`collate archive`、`/clone/item/tool_star_observation_plate.c`）。Ch. 92 升仙台見證 Lv.92 鶴鳴真人「坐化」實係玉化為輸送星流之人形晶像，自雪縫夾取晶屑（`v3_act2_taiqing_ascension_secret`、`collect crystal`、`/clone/item/dao_crystal.c`），並自陸觀瀾口中確認 Lv.84 病變與「暗紅丸藥」困境；簡素與玄冥真人首度現身。

### EV305：長城寒犛戰、傷兵急鎮丸與鬼哭冰澗走山血痕（第 93–94 章實裝）

- **地點**：北線長城巡防牆暨關口（`great_wall_gate.c`）、傷兵養息院（`restoration_hall.c`）、北線軍寨炊事後勤區（`north_garrison_kitchen.c`）、北荒巡哨營（`north_watch.c`）、鬼哭冰澗（`ghost_cry_gorge.c`）。
- **參與者**：燕隼、雷烈、岳停山、唐映、杜青禾（`du_qinghe`）、祁無傷（`qi_wushang`）、阿滿（`a_man`）、鐵甲寒犛（Lv.70 `iron_yak`）。
- **實情與實裝**：Ch. 93 燕隼射殺二階鐵甲寒犛而不追「白霧雪溝」，夜巡養息院目睹雷烈咳黑血吞服未標藥單之「定心急鎮丸」，與杜青禾核對病案實據（`v3_bahuang_bloodline_watch`、`inspect records`）。Ch. 94 經東側鐵包邊門隨唐映、祁無傷探冰鬼哭冰澗（注意區別於三幕北荒主遺址 `black_ice_valley`），起獲燕山鷹記斷折骨箭與八方舊甲（`v3_act2_bahuang_ghost_gorge`、`probe ice`、`/clone/item/yanshan_broken_arrow.c`），向阿滿查天興十九年失蹤名冊得韓素線索，並由雷烈箭樓自首交付三十斤千機火藥出庫副本（`/clone/item/bahuang_logistics_copy.c`）。

### EV306：萬機地窟神機共鳴與血精晶柱停機風波（第 95 章實裝）

- **地點**：天工閣地火鍛兵台（`forge_yard.c`）、萬機地窟（`machinery_depths.c`）、陣圖工房（`array_drafting_room.c`）、萬機四號庫房（`vault_four.c`）。
- **參與者**：林鐵生、魯長老、章百鍊、季衡（`ji_heng`）、聞九（`wenjiu`）、赤煉長老（`chi_lian`）。
- **實情與實裝**：林鐵生升入內門入地底二十丈萬機地窟檢修十丈【巨靈神機】，腰間不融黑鐵齒輪與三尺黑色主軸強烈磁吸共鳴（`inspect core`），並由季衡檢出銅管「脆化麻點」與三次脈衝；於陣圖工房與聞九合繪延長線證實其原為「推進錨機／轉向關節」（`trace blueprint`、`/clone/item/tiangong_anchor_blueprint.c`）。赤煉長老挾「北荒獸潮提前＋長城凍裂」動機強插六根血精晶柱遭魯長老依規封入四號庫房（`v3_tiangong_ancient_mechanism`）。

### EV307：百草谷藥田水脈微滲對照（第 89、96 章）

- **地點**：丹鼎宗百草谷（`herb_garden.c`）、上游水渠。
- **參與者**：顧玄、葉青枝。
- **實情與邊界**：Ch. 89 起發現寒髓草斑紋與雪線苔；Ch. 96 初已實地協助葉青枝查出兩處水渠礦酸微滲根源（對應 `v3_danding_blood_pill_cases` 步驟 1），隨即調入地肺丹火窟展開追查，保留不將局部微滲等同全宗投毒的邊界。

### EV308：地肺丹火血丹密會與廢丹崖剖猿核案（第 96–97 章實裝）

- **地點**：地肺丹火窟（`earth_fire_pill_cave.c`）、廢丹崖（`discarded_pill_cliff.c`）、醫理院暨病案封存室（`medical_archive.c`）。
- **參與者**：顧玄、鶴壽、白鶴年、孫聞露（`sun_wenlu`）、陶生（`tao_sheng`）、太清／天工密使。
- **實情與實裝**：Ch. 96 顧玄戴白鶴年所贈甘草口罩清灰排煙，從通風暗隙目睹鶴壽與兩名無標記密使清點「萬山乙零四・南十三」三十塊含汞缺額三成半之血精晶錠配三階荒獸心血煉成十二顆「逆道延命血丹」，括取暗紫殘灰（`peek flue`、`/clone/item/pill_reverse_dao_life.c`）；Ch. 97 由陶生（缺兩指工頭）押印交出紫泥硬渣與白猿凍屍（`dissect ape`、`/clone/item/sample_discarded_pill.c`），與孫聞露互核十七份「甲一、乙三」匿名病案（`crosscheck cases`）證實前三月假壓、第四月起「血煞癌變」且停藥七日反撲暴斃（`v3_danding_blood_pill_cases`）。

### EV309：履約危機、鬼市截帳、三元剝離與稽查破局（第 90、98–101 章實裝）

- **地點**：冷風坡、萬山商埠公所（`public_office.c`）、交割廳暨雲海票號（`exchange_hall.c`）、泥途商棧（`mudway_store.c`）、泥途地下石室（`mudway_store_cellar.c`）、三宗交易街（`three_sect_market.c`）、山道車馬行（`mountain_caravan_yard.c`）、雲海鬼市（`ghost_market.c`）、萬寶閣後門暗巷交界（`wanbao_back_alley.c`）。
- **參與者**：沈泥、莫三（`mo_san`）、邱禾、阿四（`a_si`）、何萬金、羅九秤、顧蘭舟、鬼見愁（`gui_jianchou`）、灰袍經生（`gray_robed_scribe`）、太清執法事（玄冥私印）及四位同伴。
- **已寫實與實裝情節**：
  - **Ch. 90**：冷風坡雪崩與何萬金卡馬，沈泥親搶藥草並賠四百靈石票立信，換得三宗「朔望結算回執貨單」暗網。
  - **Ch. 98**：追蹤「三萬兩千枚準備金」暗流，赴雲海鬼市向鬼見愁分檔購情報並於暗巷放風（`rumor audit`）截獲《延命私盟密帳索引》（`/clone/item/ev3_private_purchase_ledger.c`）；莫三隨冬糧車隊抵雲津，認出末頁「乙巳年舊盟未結轉帳代號：玄木」。
  - **Ch. 99–100**：地窖五方對帳劃清四大缺口（`v3_five_way_evidence_convergence`）；柳清虛左腕現「道化晶絲」，五子「三元互濟」成功剝出半寸淡青晶絲（`strip filament`、`/clone/item/cyan_crystal_filament_vial.c`、`v3_act2_yunjin_ghost_and_sanyuan`）並誠實紀錄指麻與短暫失憶邊界。
  - **Ch. 101**：何萬金聯手「玄冥」篆字私印突擊外庫並羈押夥計阿四；沈泥以雙聯副帳保上游客戶、認罰兩百靈石票卻亮跨州特等信印保阿四並警告追討炭袋賠款；深夜接獲【三宗聯合勘探隊】公文，決策搶標輜重雪橇進軍北荒（`EVENT_TIER2_CRISIS` `evaluate_tier2_crisis()` 與 `on_stage_timeout_tier2_crisis()` 已於 `daemon/event_manager.c` 實裝，支援由 `T-2` 單調推進至 `T-1`）。

### EV310–EV319：北荒聯合勘探、走山絕谷、五器九城契與冰谷歸山（第 102–111 章實裝）

- **EV310（Ch. 102｜`v3_north_wastes_expedition`）**：出【黑山長城北關雪道】（`black_mountain_pass.c`），經關外三百步【失蹤者家屬互助所】（`missing_families_hall.c`）受韓素（`han_su`）委託尋兄「北線斥候・乙十七」韓林，由首席民間嚮導祁十六（`qi_shiliu`）自【北荒南沿入口】（`south_approach.c`）帶隊，沈泥／穆雪（`mu_xue`）押二十四輛「泥」字貨橇隨軍；【雪原行腳營地】（`snow_caravan_camp.c`、`inspect sleighs`）察覺赤煉三輛厚黑布重車磁偏角異常且暗引向正北偏東深谷。
- **EV311（Ch. 103｜`v3_north_wastes_expedition`）**：入第二層【永凍血原】（`frozen_blood_plain.c`），顧玄在【北荒前哨醫所】（`north_outpost_infirmary.c`、`test poultice`）以半寸「雪線續脈膏」消腫七成折服白岩（`bai_yan`）並簽《採冰礦肺部染煞病例簿》；黃昏五子協同擊退 Lv.82【雙頭霜甲地龍】（`shuangtou_dilong`，用一枚黑背雪狼重箭、記明【沸血雄黃煙】低壓嗆肺禁忌 `/clone/item/pill_herb_poultice.c`），折兩橇與兩成乾糧、死二傷三。
- **EV312（Ch. 104｜`v3_act3_war_god_tomb`）**：夜自【墨黑雪壁垂降崖】（`rift_watch.c`、`rappel cliff`）釘岩繩降入【黑冰斷谷】（`black_ice_valley.c`、`excavate remains`），尋獲天興十九年爆破塌山現場九具遺骸暨韓林「北線斥候・乙十七」銅哨（`/clone/item/hanlin_copper_whistle.c`）；【舊勘探隊營地廢墟】（`old_expedition_camp.c`、`search alcove`）搶救箭筒名冊（`/clone/item/ev3_expedition_roster.c`）與殘留「雷……非……」及「山」字落款之羊皮血書（`/clone/item/ev3_yanshan_blood_note.c`）——法理邊界明確停在「尚無主謀署名蓋印」。
- **EV313（Ch. 105｜`v3_act3_war_god_tomb`）**：谷底【荒古戰神巨石遺塚】（`war_god_tomb.c`）按骨片觸動十二玄柱共振（`resonate totem`），燕隼悟出鎖煞輪替節律與《八荒破天弓》第一式「沉岳引」（約 Lv.80），於丈寬暖風裂隙邊五尺凍血跡盡頭拾獲砸凹精銅「燕」字護心鏡（`/clone/item/ev3_heart_guard_mirror.c`），但裂隙無骨無火故**燕山生死仍完全 `open`**；擊傷 Lv.82【北荒冰熊王】（`ice_bear_king`）咽喉後克制棄追退入暖風裂隙。
- **EV314（Ch. 106｜`v3_north_wastes_expedition`）**：下行兩里抵數百丈凍冰下方圓數十里之【方舟主引擎冷卻艙段】（`ark_foundation.c`、`test coolant`）；卡尺比對主導管與不融黑鐵及天工閣【巨靈神機】分毫同源，三息化學檢測證實「北荒血精母脈」實係破界方舟破裂冷卻穩壓管線洩漏的高能生物質與水銀結晶廢液，強採將釀北境半壁陸沉。
- **EV315（Ch. 107｜`v3_five_relic_resonance`）**：五子依序將五組信物嵌入【八角形核心圓台】（`ark_core_chamber.c`、`place relics`）東北、正北、西北、西南、正南五龕，投影顯露「二十八宿天羅結構」與人族先民「領航演算部／破陣護衛部／工程造物部」殘影，卻在大清洗爆發前炸出雪花噪點熄滅；完整歷史與現今三宗繼承大義仍維持 `open`。
- **EV316（Ch. 108｜`v3_five_relic_resonance`）**：門廊後方【後勤石鋼廳室】（`ark_logistics_hall.c`、`join treaty`）合璧青銅契版與天門引顯露《九城總約・禁毀條例第七條》，揭開沈泥原名「沈雲妮」暨九城萬物商盟總調度使負責護全九州避難火種、嚴禁交出北境安全閥圖紙之第五階段身世正典，並起獲印「雲記」暗章與「乙巳年舊盟未結轉帳：玄木」暨「丹鼎丙柒／天工赤火／太清雷律」殘頁抄本（`/clone/item/ninety_city_treaty_copy.c`）。
- **EV317（Ch. 109｜`v3_ark_excavation_evidence`）**：【東側冷卻豁口】（`ark_cooling_breach.c`、`lock valve`）赤煉強抽二十八罐母液撤走後，顧玄冰霧壓毒兼傷唇灼手、林鐵生三錘砸入黑鐵齒輪鎖死七成手動總閘（爆毀前五具鑽山傀儡），搶獲天工批號【鑽山傀儡鑽頭殘件】（`/clone/item/ev3_drill_head.c`）、【血精母液封裝玉瓶】（`/clone/item/ev3_mother_liquid_vial.c`）並救出四工役。
- **EV318（Ch. 110｜`v3_ark_excavation_evidence`）**：【冰谷窄口伏擊道】（`ice_valley_exit.c`、`trigger avalanche`）五子＋祁十六遭 Lv.88【私盟大執事】（`private_league_envoy`）、八暗衛與六具【虎煞戰鬥機關獸】（`tiger_mech_beast` Lv.84）圍堵；清虛 Lv.85 立紫微偏轉星陣偏折十六支重弩、顧玄腐金毒煙、鐵生拆閥、沈泥爆雪崩斷後路、燕隼《沉岳引》用最後一支狼牙重箭穿喉斃敵；搜獲【千機堂副執印暗金令牌暨密令底頁】（`/clone/item/ev3_envoy_tally.c`），嚴守大執事無臨終口供故仍須返閣比對原始領用簿之證據邊界。
- **EV319（Ch. 111｜`v3_preserve_field_evidence`）**：半月返抵黑山長城，五人皆穩登 **Lv.85**；親還韓素乙十七銅哨與實測名冊副本、於泥途地窖封妥四組火漆密封鐵證；並分頭串聯雷烈（備《急鎮丸依賴與死因統計簿》）、魯長老（允坐會武百工試裁判席盯材料批次）及太清苦修派【簡素真人】（`jian_su`）定下「三日後子時為【清修偏峰】Lv.73 老弟子【元青】（`yuan_qing`）穩妥剝離早期晶絲以換雲頂證詞」之實證約，同步於引擎側將 `EVENT_TIER2_CRISIS` 備妥 `T-1 → T0`（`hearing_ready`）與 `dump_status` 證物帳本檢視。
- **EV320**：三宗論道會武是公開盛會，包含技藝、武備、丹器與商埠交割展示；不應只作為主角比武舞台。
- **EV321**：各方提出帳冊、病案、軍需與器材記錄，證據互相矛盾之處要保留，讓讀者看到調查成本。
### EV320–EV325：公開會武、道化驚變、三元鎮脈與雲津新約（第 112–120 章實裝）

- **EV320（Ch. 112–114, 116｜`v3_act4_cloud_top_tournament`、`v3_evidence_chain_hearing`）**：清修偏峰五子歷一個半時辰為 Lv.73 元青剝離晶絲換【簡素真人】登雲頂作證；十年一度【雲頂三宗論道會武】於【問道天台】開幕（`tournament_craft_arena.c`、`tournament_combat_arena.c`、`hearing_hall.c`），林鐵生三錘破趙烈（`zhao_lie`）煞火魔偶封存暗紅脆化晶屑（`/clone/item/brittle_shahuomou_shard.c`）、顧玄雙盲試毒逼出李青雲（`li_qingyun`）紅血引子來源（`/clone/item/sanyuan_shengji_dan.c`）、燕隼擊敗過量服藥之王鐵牛（`wang_tieniu`，`/clone/item/wang_red_pill_vial.c`）、柳清虛踩東北三度半息避雷死角敗韓蒼（`han_cang`）；高台四線呈證觸發【紫霄真人】、【鐵背山主】、【玄樞門主】頒三宗聯席令暫停三長老職權立五方查核席，並於【鶴壽】自飲兩管母液兼【玄冥】拍碎護山主令瞬間引爆死局。
- **EV321（Ch. 115–116｜`v3_act4_cloud_top_tournament`、`v3_cross_sect_evidence_audit`）**：交割廳（`exchange_hall.c`）聯手十七債權商戶擠兌萬寶閣，揭發百八十萬靈石票偽造越冬燃料倉單炒作黑市礦藥期貨並封存後庫七口黑鐵帳箱（`/clone/item/wanbao_black_iron_box.c`），同時嚴守「缺親筆原署名印章比對」與「先查原簿後定謀逆」之程序保管鏈邊界。
- **EV322（Ch. 117｜`v3_crystal_quarantine_response`、`v3_act4_sanyuan_defense`）**：鶴壽結晶孢子與玄冥碎柱極寒毒氣交壓下沉形成半里→百丈半山毒域；【石牌坊迎風口】（`stone_arch_quarantine.c`）緊急設甲區救治三十餘名傷員，【陸觀瀾】以廢半邊經絡為代價死壓【毒域東側副陣柱】（`crystal_poison_edge.c`）三十息換柳清虛與顧玄二十息搶回護箱衛士，赤煉趁初三息掀維修井暗門潛逃（`down`→`machinery_depths`）。
- **EV323（Ch. 118–119｜`v3_north_wall_beast_surge`、`v3_act4_sanyuan_defense`）**：赤煉鑽探殘煞疊加天台主陣崩毀致鎮山陣脈斷流半數，Lv.95【冰獄骨龍王】（`ice_bone_dragon`）率上千頭二階荒獸轟垮【黑山長城西段】（`west_wall_breach.c`）三十丈城牆暨兩座弩樓，累積八十多具軍民屍骨；燕隼偕祁無傷護韓素、阿滿與家屬撤入東側排水石道，林鐵生偕魯長老等以純蒸汽熱壓推【巨靈神機】循玄鐵暗門（`machinery_depths` `north`）頂住第二道內門樑柱。
- **EV324（Ch. 119｜`v3_act4_sanyuan_defense`、`v3_crystal_quarantine_response`、`v3_north_wall_beast_surge`）**：不依賴血精之五線有限協同——沈泥萬山廣場雙倍運價急調八十餘雪橇五百腳夫分流東西道；顧玄二十口鐵鍋調制【百草中和隔離霧】（`/clone/item/sanyuan_isolation_mist.c`）配杜青禾十丈生石灰線阻毒於盆地半里外（明記殺不死鶴壽體內毒瘤）；柳清虛等撥正十二柱東三度七分立【三元鎮脈陣】壓慢骨龍三成；唐映紅旗三段輪替、燕隼藉巨靈神機右傾半息施《破核》重創骨龍左肋舊創迫退獸群（連接桿過載報廢）；鶴壽重傷鎖押丹鼎鐵室、玄冥斷臂落網。
- **EV325（Ch. 120｜`v3_postwar_reform_and_restitution`）**：聯席公告停採封爐兼平反走山隊（韓林入碑，燕山生死續 `open`）暨「雲記」三十年前除名案（高層簽署姓氏仍空白）；面對停爐致【陶生】與窯工家庭斷炊之現實反彈，重組拍賣萬寶閣空倉開設【西街無毒廢料回收廠】（`west_street_recycling.c`），並簽署《雲津萬山臨時互市與救濟協約》（`/clone/item/yunjin_relief_treaty.c`）除籍何萬金兼首立三宗商埠共同議事席（推進 `EVENT_TIER2_CRISIS` 至 `T+2`／`defense_outcome` 三檔結算）。

### EV326–EV327：百草通玄破境、假天排斥與單向開門入洞天（第 121–126 章實裝）

- **EV326（Ch. 121–124｜`v3_act5_lvl100_trials`、`v3_tier2_departure` Stage 1–2）**：五人皆以「守人與可推翻實證」無聲破入二階大圓滿（Lv.100）且保留各自身體代價與認知邊界——顧玄於隔離區保障周師叔拒絕權編定《三元本草祛道錄》（`publish bencao`、`/clone/item/sanyuan_bencao_draft.c`）、林鐵生引五十年前陸明前車之鑒拒接神識改製【可拆卸連動台】（`install rig`、`/clone/item/detachable_feedback_spec.c`）、燕隼定稿《黑山分段輪替操典》並三百步粉石（`compile manual`、`/clone/item/bahuang_rotation_manual.c`）、柳清虛題明可推翻反例聲明聯沈照塵校正《逆星歲差補遺》（`publish addendum`、`/clone/item/reverse_star_addendum.c`）、沈泥將泥途商棧更匾【萬山泥途總號】並月讓四成利立《萬山共治分權章程》（`decentralize ledger`、`/clone/item/wanshan_charter_deed.c`）；Ch. 124 五人攜五遺物登太清【封存觀測室】（`sealed_observatory.c`、`resonate relics`）觸動十倍共鳴暨二十八宿天羅排斥劫雲鎖定，紫霄、鐵背、玄樞揭封《祖師密錄》（`/clone/item/ancestor_secret_record.c`）坦白十七位先賢單向無歸實錄。
- **EV327（Ch. 125–126｜`v3_act5_lvl100_trials` Step 6、`v3_tier2_departure` Stage 3）**：最後一晝夜於萬山泥途總號拆權交割《多方交接總錄》（過萬票須邱禾／顧蘭舟／八家代表三方會簽），接收【南方故人加急家書驛袋】（`/clone/item/hometown_letters_bag.c`）與韓素手縫厚羊毛護腕，並於地窖與莫三立下「三十年看門之約」；子夜循陡峭深黑螺旋階梯下行千餘丈至三大祖庭保護之【太古破界方舟・主傳送室】（`ark_portal_chamber.c`、`activate gate`），於外陣兩刻鐘極限雷壓下依序完成正北座標鎖定、東北卡尺黑鐵鎖壓、西北血脈屏蔽、西南晶核點火、正南天門引與九城契版造冊，最後一息入星門（`enter gate`）墜入 **Tier 3【桃花源洞天・荒蕪碎石高原】**（`/d/realm/peach_plateau.c`），身後星門崩毀成煙塵，遠望【太虛神宮】、【戰祖魔殿】、【萬物主機城】三巨構開啟第四卷懸念（門後性質、燕山下落與假天操縱者俱維持 `open`）。

## 3. 第二卷正典銜接檢查

- 燕山：燕隼的大伯，第二卷已明確如此記載。
- 顧玄遺物：古礦地煞晶核殘片；不得與柳清虛的道化晶石殘片混用。
- 柳清虛遺物：逆星斷碑拓片及道化晶石殘片是不同物件。
- 林鐵生遺物：太古不融黑鐵／黑鐵齒輪系統，具體實體與零件關係須按第二卷清單統一。
- 燕隼遺物：太古戰神獵獸圖騰骨片及燕山走山令殘牌，兩者功能不同。
- 沈泥遺物：天門引、青銅契版、雲記名冊等屬不同證據／信物，不得合併成單一「商盟神器」。
