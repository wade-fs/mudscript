# 《遺忘的世界》Tier 1 NPC 清單（建物件用）

> **來源**：`docs/tier1_regional_network_and_career_spec.md` v2.1  
> **用途**：依此清單逐一建立 `/d/city/<zone>/npc/<id>.c`（路徑為建議，規範書未定義 NPC 檔案位置）

---

## 0. 讀法與來源標記

規範書只對 NPC 給了**名字、房間、職能與少數數值**，沒有六維、等級、技能與背包。為了讓你可以直接建物件，本清單補了建議值，並用欄位區分：

| 標記 | 意義 |
| :--- | :--- |
| **規範書** | 規範書原文有寫（名字、房間、功能、稅則、任務步驟、數字） |
| **建議** | 規範書沒寫，由本清單補上（原型、等級、屬性、`id`）；你可以整批改 |
| **待命名** | 規範書只給職稱，沒有名字，需要你取名 |

**命名規則**

- `id`：`<房間名>_<拼音>`；任務 JSON 已經用到的 5 個 id **維持原樣**（見第 7 節）。
- 房間路徑沿用規範書 4.3 的房間 ID（`/d/city/<zone>/<room>`）。
- 無名 NPC 的 `id` 用英文職稱，之後取名後再改。

**屬性代號**：用世界設定集與 `mudlib_lpc_mapping.md` 的 `str/con/int/spi/dex/per`，三柱用 `kee/sen/sp`。
（已裁定：正典統一為 `kee/sen/sp`；`qi→kee`、`jing→sp`、`shen→sen` 僅為相容別名，見第 9 節。）

---

## 1. NPC 物件欄位規格

沿用規範書 5.1 的 `mapping` 風格，欄位可直接對應你 LPC 的 `set()`。範例是**韓清**：

```c
mapping npc_data = ([
    "id"         : "gate_north_hanqing",
    "name"       : "韓清",
    "title"      : "城門典吏",
    "home_room"  : "/d/city/gate/gate_north",
    "archetype"  : "A",                  // 見第 2 節
    "level"      : 18,                   // 建議值
    "class"      : "mortal",             // dao_initiate / wu_initiate / gong_initiate / mortal
    "attr"       : ([ "str":3, "con":4, "int":9, "spi":5, "dex":4, "per":10 ]),
    "faction"    : "yamen",              // yamen / dao / wu / gong / shanghui / jianghu / folk
    "roles"      : ({ "gatekeeper", "tax", "info" }),
    "rules"      : ([ "tax_commoner":2, "tax_no_papers":10, "exempt":"six_county_pass" ]),
    "topics"     : ({ "外荒情報", "軍械盤查", "逃民" }),
    "quest_hooks": ({ }),
    "inventory"  : ({ }),
    "schedule"   : "day",                // day / night / 24h / patrol
    "hostile"    : 0,
]);
```

**欄位說明**

| 欄位 | 說明 |
| :--- | :--- |
| `roles` | 功能旗標：`gatekeeper` `tax` `guard` `patrol` `shop` `trainer` `quest_giver` `quest_target` `info` `service` `broker` `hostile` |
| `rules` | 規範書給的數值規則（稅額、清濁氣點數、日限次數、緩衝天數等） |
| `topics` | 可 `ask` 的話題關鍵字（我依規範書職能列出，對白需你自寫） |
| `quest_hooks` | 掛到哪個任務、哪一步（第 7 節） |
| `schedule` | 規範書只有「日夜換班」「夜間」等零星描述，其餘為建議 |

---

## 2. 屬性原型（建議）

以 **Lv.20、總點 38** 為基準（假設總點＝18＋等級，與 Tier 0 主角總點 18 對齊）。其他等級請依比例縮放。三柱公式依你的 `std/living.c`（`kee≈str+con`、`sen≈spi+int`、`sp≈dex+per`）。

| 原型 | 代表 | str | con | int | spi | dex | per |
| :--- | :--- | :-: | :-: | :-: | :-: | :-: | :-: |
| **A 文吏** | 典吏、主簿、書吏、驛丞 | 3 | 4 | 10 | 6 | 4 | 11 |
| **B 衛士** | 城防衛士、武卒、隊正、獄頭 | 9 | 9 | 3 | 3 | 7 | 7 |
| **C 武師** | 教頭、總教頭、捕頭、都尉 | 11 | 10 | 3 | 3 | 6 | 5 |
| **D 弓手** | 瞭望長、弓兵教頭、鏢客 | 6 | 6 | 3 | 3 | 10 | 10 |
| **E 匠人** | 各工坊匠首、把頭 | 9 | 9 | 6 | 3 | 6 | 5 |
| **F 藥師** | 醫館館主、藥坊管事 | 3 | 5 | 9 | 6 | 6 | 9 |
| **G 法道** | 玄機真人、星淵、經生、道童 | 2 | 4 | 11 | 12 | 3 | 6 |
| **H 商賈** | 掌櫃、會首、大朝奉、採辦 | 3 | 4 | 12 | 3 | 5 | 11 |
| **I 市井** | 牙子、走私客、暗線 | 5 | 5 | 8 | 3 | 9 | 8 |
| **J 平民** | 農人、老人、小二、馬伕 | 6 | 7 | 7 | 5 | 6 | 7 |
| **K 苦力** | 腳夫、庫頭、把頭（體力活） | 11 | 11 | 3 | 3 | 5 | 5 |
| **L 刺客** | 潛行、水賊、黑披風 | 5 | 5 | 5 | 3 | 12 | 8 |

---

## 3. 具名 NPC（29 位，規範書有名字）

欄位：`原型/Lv` 為**建議**；「房間」「功能與規則」為**規範書**。

### 3.1 城門與城牆（`gate/` `wall/`）

| id | 名稱・稱謂 | 房間 | 原型/Lv | 功能與規則 |
| :--- | :--- | :--- | :--- | :--- |
| `gate_north_hanqing` | 韓清・城門典吏 | `gate/gate_north` | A / 18 | 正式官道門戶，審查外荒情報，嚴查軍械與逃民。北關稅則：良民 2 文茶湯錢（持六縣路引免徵），無文牒流民 10 文工本費；嚴查大荒走私獸皮、未註冊火器 |
| `gate_south_inn_laoliu` | 老劉・棧主 | `gate/gate_south_inn` | J / 10 | 黑石鋪逃難鄉民第一落腳點，可打探城內雜工門路 |
| `gate_inn_laopi` | 老皮・店小二 | `gate/gate_inn` | J / 8 | 北方商旅歇宿處，打探極北雪原與荒原風向（情報型） |
| `wall_tower_n_yanmu` | 嚴目・瞭望長 | `wall/wall_tower_n` | D / 22 | 北城望荒箭樓，專司警戒北山煞潮動向（可接 `WORLD_STATE_D` 煞潮播報） |

### 3.2 府衙、學塾、民生（`center/`）

| id | 名稱・稱謂 | 房間 | 原型/Lv | 功能與規則 |
| :--- | :--- | :--- | :--- | :--- |
| `yamen_zhou` | 周捕頭・捕快總管 | `center/yamen` | C / **15**（規範書 4.6） | 府衙大案懸賞；凡胎私鬥由巡街遊徼與衙役以鎖鏈鐵尺制伏，罰金 500 文至拘留 1 遊戲日 |
| `yamen_archive_wenchengjing` | 文承敬・案牘主簿 | `center/yamen_archive` | A / 20 | 查閱數十年舊案、戶籍底單、身世線索；2.2 節寫他正暗中核查舊案底單。**沈泥身世線重要交涉 NPC** |
| `yamen_prison_tieliaozhang` | 鐵鐐張・獄頭 | `center/yamen_prison` | B / 25 | 關押重犯、探監、祕密審訊；趙德貴、胡百戶收押處 |
| `granary_liubingzhong` | 劉秉忠・常平倉大使 | `center/granary` | A / 25 | 官方戰略糧儲、災荒平糶平抑物價；物價衝到 250% 上限時觸發平糶；開倉糧價乘數 0.7～0.9 |
| `academy_lufuzi` | 陸夫子・學塾塾師 | `center/academy` | A / 20 | 緩衝路徑 A：簽抄書償債券，夜間抄五卷《道藏初訓》→【學塾白鹿青衿】，合法期 **+14 天** |
| `post_station_maqianli` | 馬千里・驛丞 | `center/post_station` | A / 15 | 官方加急送信委託；官府快馬府城至六縣 36～48 時辰 |
| `inn_main_qianbuhuan` | 錢不換・大掌櫃 | `center/inn_main` | H / 20 | 金石大客棧；**金石商會眼線**；接待外埠客商與修士 |
| `clinic_baixiansheng` | 白先生・館主 | `center/clinic` | F / 28 | 緩衝路徑 C：試藥童→【杏林藥囊腰牌】，合法期 **+10 天**；賣【清心散】（一次清 20 點濁氣、日限 3 服）；顧玄可掛單會診 |
| `pawnshop_jiachaofeng` | 賈朝奉（賈富春，外號「賽半仙」）・老掌櫃 | `center/pawnshop` | H / 30 | 通寶當鋪總號：典當、收購黑貨、地下情報樞紐；與六縣當鋪分號人脈連鎖（模式 C）；沈泥持牙印掛名 |

### 3.3 宣道司（`west/`，法）

| id | 名稱・稱謂 | 房間 | 原型/Lv | 功能與規則 |
| :--- | :--- | :--- | :--- | :--- |
| `dao_hall_xuanji` | 玄機真人・宣道司道官 | `west/dao_hall` | G / 45 | 法道受牒、頒發大乾度牒、講授周虛微茫之理；轉職考核最後一步（辯證問題「假天道化」） |
| `dao_observatory_xingyuan` | 星淵・觀星師 | `west/dao_observatory` | G / 35 | 天候測繪、星圖推演、引導微茫靈機試煉；轉職第一步發【渾天黃銅鏡】 |

### 3.4 八方武館（`east/`，力）

| id | 名稱・稱謂 | 房間 | 原型/Lv | 功能與規則 |
| :--- | :--- | :--- | :--- | :--- |
| `wu_hall_bashan` | 霸山・武館總教頭 | `east/wu_hall` | C / 50 | 力道受牒，頒發外門黑鐵腰牌；轉職最後一步：敬茶立誓、簽生死狀 |
| `wu_arena_zhaomeng` | 趙猛（綽號「鐵臂」）・教頭 | `east/wu_arena` | C / 35 | 門徒切磋、承受鐵砂拳試煉；轉職第二步：以「鐵砂崩拳」連擊 3 次考驗 |
| `wu_arena_duanhundao` | 厲無咎（「斷魂刀」）・裁判 | `east/wu_arena` | C / 40 | 主持私鬥仲裁與生死擂台（已補定本名「厲無咎」，前邊軍刀客） |

### 3.5 百工總會（`north/`，物）

| id | 名稱・稱謂 | 房間 | 原型/Lv | 功能與規則 |
| :--- | :--- | :--- | :--- | :--- |
| `gong_gate_tiechigong` | 鐵尺公・行會知事 | `north/gong_gate` | A / 25 | 百工學徒登記、材料資質考核 |
| `gong_hall_ouyang` | 歐陽大師・匠首 | `north/gong_hall` | E / 50 | 物道受牒、頒發百工正式匠籍；轉職最後一步：審定圖紙、領【天工烏木尺】 |
| `gong_forge_mochui` | 莫錘・鍛造大師 | `north/gong_forge` | E / 40 | 高階合金冶煉、重型靈兵鍛造；原料：烈礬赤銅＋重石重玄粗生鐵錠；轉職第二步使用其重鍛錘 |
| `gong_wood_luchangsheng` | 魯長生・大木作把頭 | `north/gong_wood` | E / 30 | 車輦軸承、吊車絞盤、機關飛爪；原料：盤木鐵力木、冷杉 |
| `gong_stone_hanlaodiao` | 韓老雕・老石匠 | `north/gong_stone` | E / 30 | 磨石碾輪、城防巨石、地宮石槨雕鑿；原料：重石重玄石、青石 |
| `gong_leather_wenniangzi` | 溫娘子・鞣皮名匠（女） | `north/gong_leather` | E / 28 | 戰鬥硬甲、馬具、密封革囊；原料：盤木生筋＋鎮風獸皮 |
| `gong_alchemy_sunxiansheng` | 孫先生・藥坊管事 | `north/gong_alchemy` | F / 25 | 官制金創藥、解毒散劑、偏方萃取；原料：青河洗靈草＋濁水毒囊 |

### 3.6 漕運、近郊、商會

| id | 名稱・稱謂 | 房間 | 原型/Lv | 功能與規則 |
| :--- | :--- | :--- | :--- | :--- |
| `south_canal_caotiemao` | 曹鐵錨・碼頭水行把頭 | `south/canal` | K / 25 | 青河平底漕船卸載、糧油大宗轉運；順流 2.5～3 天、逆流約 5 天 |
| `outer_farmland_w_zhaodingtian` | 趙定田（人稱趙大叔）・老農 | `outer/farmland_w` | J / 8 | 春耕、秋穫季節事件觸發地；可接「幫農」「治水」日常 |
| `outer_post_depot_laowang` | 老王・馬伕 | `outer/post_depot` | J / 8 | 外城大車馬店，牲口棚與草料堆垛場 |
| `shanghui_hq_qianbaichuan` | 錢百川・副會長 | `south/shanghui_hq` | H / 45 | 金石商會總堂：拍賣大廳、行商總帳、巨賈密議室；執事掌天字一號密室入口；第一卷黑石鋪地煞精錠與內造坩堝走私線明面收貨保護傘 |

---

## 4. 功能型 NPC（已全數賦予正典姓名與獨立防撞 ID）

實裝路徑統一置於 `/clone/npc/<id>.c`（城防精銳衛士共用 `/clone/npc/city_gate_guard.c`）。標 ★ 的在規範書有額外規則。

### 4.1 城門與城牆

| id | 正典姓名・職稱 | 房間 | 原型/Lv | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| `city_gate_guard` | 城門披甲衛士 | `gate/gate_*`, `east/wu_gate` | B / 20 | 通用城門與轅門披甲衛士 |
| `gate_south_taxofficer` ★ | 宋算子・南關稅吏 | `gate/gate_south` | A / 12 | 重車按木石毛重徵 50～100 文；黑石鋪逃難鄉民憑舊戶籍免入城稅；嚴查木材夾層私藏硝石、私鹽 |
| `gate_south_runner` | 刁小七・流民牙子 | `gate/gate_south_inn` | I / 8 | 介紹城內雜工門路與三日通牒緩衝路徑 |
| `south_yard_material_foreman` | 石大柱・堆棧把頭 | `south/yard_material` | K / 15 | 石木毛料過磅初切、兼轄驗材 |
| `gate_east_taxchief` ★ | 褚嚴・東關督稅官 | `gate/gate_east` | A / 22 | 硫礬、赤銅加徵 5%「地火危險稅」；生銅扣繳一成官鑄留底；嚴查高濃度地煞血精晶錠 |
| `gate_west_helmsman` ★ | 江平波・西水門守舵官 | `gate/gate_west` | A / 20 | 貨物價值 1/20 輕稅；藥品進口享平糶補貼 |
| `gate_west_inspector` ★ | 盧緝私・水關緝私吏 | `gate/gate_west` | A / 15 | 登船開箱，查禁違禁劇毒與落龍口腐濁泥 |
| `gate_plaza_deputy` | 雷震・巡防副將 | `gate/gate_plaza` | C / 30 | 可接協防與押送物證任務 |
| `gate_warehouse_assessor` | 金算盤・商會驗貨掌櫃 | `gate/gate_warehouse` | H / 18 | 官商共管大貨棧，走私扣押貨箱是任務線索 |
| `wall_tower_s_archerymaster` | 百步楊・弓兵教頭 | `wall/wall_tower_s` | D / 25 | 映翠箭樓弓防與床弩督管 |
| `wall_tower_e_beaconchief` | 耿烽・烽火長 | `wall/wall_tower_e` | B / 20 | 三座常備狼煙烽燧 |
| `wall_tower_w_navalofficer` | 水連環・水軍哨官 | `wall/wall_tower_w` | B / 20 | 水門重鐵柵吊索絞盤 |
| `moat_angler` | 獨釣叟・釣魚蓑翁 | `wall/moat` | J / 5 | 護城河畔，知曉暗渠排水柵門潛渡傳聞 |

### 4.2 府衙、士人、民生（`center/` `west/`）

| id | 正典姓名・職稱 | 房間 | 原型/Lv | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| `yamen_magistrate` | 秦正明・金石府尹 | `center/yamen` | A / 35 | 與公會、商盟、士紳共治 |
| `square_storyteller` | 瞎子陳・說書盲叟 | `center/square` | J / 10 | 講古，傳聞型 |
| `square_watchman` | 李遊徼・巡街遊徼 | `center/square` | B / 12 | 與衙役一起處置凡胎私鬥 |
| `bank_chief` ★ | 沈萬通・錢莊大朝奉 | `center/bank` | H / 25 | 需一階合法身分方能開戶；別名 `bank chaofeng` 與當鋪賈朝奉分流 |
| `black_alley_gatekeeper` ★ | 疤臉刀・守門疤臉漢 | `center/black_alley` | I / 22 | 需出示特定信物或暗號 |
| `dao_tong` ★ | 清風・司香道童 | `west/dao_quiet` | G / 8 | 靜坐一個時辰清 50 點濁氣，收 50 文（ID 含 `dao_quiet_incense`） |

### 4.3 漕運、糧市、近郊（`south/` `outer/`）

| id | 正典姓名・職稱 | 房間 | 原型/Lv | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| `south_grain_guildhead` | 米萬倉・糧行會首 | `south/grain_market` | H / 22 | 直連青河產區，掌全府米價行情 |
| `south_warehouse_grain_scale` | 方平斗・斗秤官 | `south/warehouse_grain` | A / 12 | 官監糧倉過磅校準 |
| `outer_irrigation_engineer` | 河伯孫・治水工丞 | `outer/irrigation` | E / 22 | 水位調節直接影響城內水路與濁氣 |
| `outer_graveyard_keeper` | 守塚老瞎子・守塚瘸瞎老漢 | `outer/graveyard` | J / 12 | 死亡後魂魄甦醒處；可採夜煞藥材、調查暗殺現場 |

### 4.4 百工、商會、鏢局（`north/` `south/`）

| id | 正典姓名・職稱 | 房間 | 原型/Lv | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| `gong_fireworks_master` | 焦烈・火藥督造官 | `north/gong_fireworks` | E / 30 | 硝火作（官禁），戒備森嚴；原料烈礬硝石、硫磺 |
| `gong_registry_clerk` | 方矩・司匠簿吏 | `north/gong_registry` | A / 18 | 晉升匠師、核銷各縣原料調撥批件 |
| `shanghui_hq_steward` | 錢算子・商會執事 | `south/shanghui_hq` | H / 30 | 內藏天字一號密室入口 |
| `market_special_buyer` | 程通四海・六縣專材總採辦 | `south/market_special` | H / 18 | 統籌青河藥、烈礬銅砂、盤木木符、鎮風弓石、濁水金毒、重石鐵石採辦（相容六縣採辦 ID） |
| `caravan_yard_manager` | 蘇忠・蘇氏舊部大掌櫃 | `south/caravan_yard` | H / 28 | 長途商隊組隊、招募鏢師；**蘇凝霜駐都城代表**，可核驗蘇氏信印 |
| `caravan_yard_biaotou` ★ | 駱鎮遠・總鏢頭 | `south/caravan_yard` | C / 28 | 緩衝路徑 B：簽苦力契據搬運大木大石，日支 10 文粗食→【車馬行短褐腰牌】，合法期 **+7 天** |
| `warehouse_shang_chief` | 丁鐵鎖・商會大庫庫頭 | `south/warehouse_shang` | K / 20 | 走私密箱暗藏處（新建房間 `/d/city/south/warehouse_shang.c`） |

### 4.5 軍鎮（`east/`）

| id | 正典姓名・職稱 | 房間 | 原型/Lv | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| `wu_gate_squadleader` | 陳鐵甲・值役隊正 | `east/wu_gate` | B / 20 | 鹿砦盤查、募兵告示、力道考核第一關引導 |
| `wu_plaza_colonel` | 岳千軍・操練都尉 | `east/wu_plaza` | C / 30 | 百人對拆演武、兼督角牴摔角（ID 含 `wu_plaza_wrestling`） |
| `wu_hall_enforcer` | 鐵面雷・執法教頭 | `east/wu_hall` | C / 35 | 掌館規戒律，傳授磐石破浪功、軍中披甲術、破風射石術 |
| `wu_armory_quartermaster` | 武守備・司庫典軍 | `east/wu_armory` | B / 20 | 軍備管制與重弓板甲保養（ID 含 `wu_armory_sharpener`） |
| `wu_barracks_veteran` | 石老兵・輪休老兵 | `east/wu_barracks` | B / 15 | 閒談型，提供邊防與北荒舊聞 |

### 4.6 城下暗渠（`under/`，法網盲區）

| id | 正典姓名・職稱 | 房間 | 原型/Lv | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| `under_black_market_broker` | 鬼見愁・黑市牙商 | `under/black_market` | I / 25 | 違禁毒藥、無印生銅、黑貨銷贓 |
| `under_canal_hub_ferryman` | 擺渡盲叟・暗河擺渡人 | `under/canal_hub` | J / 25 | 掌暗河黑木扁舟與暗渠走私航道 |
| `under_drain_gate_diver` | 翻江鼠・潛水賊 | `under/drain_gate` | L / 22 | 可涉水潛渡至外城護城河盲區（已打通 `drain_gate` ↔ `wall/moat`） |

> `under/shang_secret`（天字一號密室）規範書沒有列 NPC，只寫開啟條件：需【天門引】與沈氏血親交叉驗證。`under/ruins_hall` 只有怪物（陰煞地蟲），不列入。

---

## 5. 縣城與分舵 NPC（規範書只有職能，沒有名字）

規範書 4.5 準則 3 要求縣城分舵也能頒發一階轉職，所以至少要有下列人物。

| id | 職稱 | 所在 | 原型/Lv | 規範書依據 |
| :--- | :--- | :--- | :--- | :--- |
| `county_qinghe_dao_master` | 定神靈植道觀觀主 | 青河縣城郊 | G / 30 | 具備法道初階弟子註冊與借法觀象轉職認證資格 |
| `county_liefan_refractory_manager` | 耐火料採辦分舵管事 | 烈礬縣 | H / 25 | 百工總會分舵，銅材與耐火料採辦 |
| `county_panmu_woodshed_examiner` | 木作工棚機巧考核官 | 盤木縣 | E / 30 | 物道機巧初階認證 |
| `county_panmu_hunter_boss` | 受僱獵戶鏢客頭 | 盤木縣 | D / 25 | 八方武館常年僱傭，護送林道木材 |
| `county_zhenfeng_branch_examiner` | 武館邊關分舵考核官 | 鎮風縣 | C / 35 | 軍陣重弓考核認證 |
| `county_zhenfeng_garrison_commander` | 邊防衛所守將 | 鎮風縣 | B / 35 | 抵禦外荒兇獸；風蝕石英採擷任務的守軍方 |
| `county_zhuoshui_gold_boss` | 淘金幫頭目 | 濁水縣 | I / 28 | 「處理淘金幫與官差的衝突」（模式 B 示例） |
| `county_zhongshi_quarry_foreman` | 採石場工頭 | 重石縣 | E / 22 | 模式 C 示例：某掌櫃的子侄，求助修復絞盤 |
| `county_<縣名>_pawn_manager` ×6 | 通寶當鋪分號掌櫃 | 六縣各一 | H / 22 | 與賈半仙人脈連鎖；持信印可喚醒暗線 |

十二個新手村（蘆花渡、百草坪、紅砂坳、地火堡、青松塢、倒影澗、鷹嘴崖、碎冰堡、泥螺灘、黑水埗、石碾坡、穿山寨）的 NPC，規範書**完全沒有列**，這份清單不涵蓋。

---

## 6. 前卷既有角色在 Tier 1 的落點（已全數裁定並實裝）

| 角色 | 規範書怎麼寫 | 最終裁定與實裝狀態 |
| :--- | :--- | :--- |
| **趙德貴**（前商會二掌櫃） | 府死牢「收押處」 | 已實裝 `/clone/npc/yamen_prison_zhaodegui.c`，收押於 `center/yamen_prison.c`（`quest_target` / `info`，可追問三號暗庫、丙字柒號與錢百川線索） |
| **胡百戶**（前黑石關城防百戶） | 府死牢「收押處」；2.2 節寫他倒台後黑石關換新暫代巡檢 | 已實裝 `/clone/npc/yamen_prison_hubaihu.c`，收押於 `center/yamen_prison.c`（`quest_target` / `info`，可追問黑石關軍械放行與城防勾結內幕） |
| **蘇凝霜**（商會大小姐） | 3.3 節：其「信印」可喚醒各城人脈 | 本體維持於 Tier 0 黑石鋪 `d/village/shed.c`（避免多玩家同時在線時新舊手分身衝突）；都城端由蘇氏舊部大掌櫃**蘇忠**（`/clone/npc/caravan_yard_manager.c`）駐守 `south/caravan_yard.c` 作為蘇凝霜信印接應代表 |
| **莫三 / 阿鐵** | 3.3 節：其私信、工具記號可喚醒人脈；2.2 節說莫三仍在後巷打探 | 留駐黑石鋪（`d/village/alley.c`、`d/village/smithy.c`），都城端可憑其工具記號與百工鍛造大師莫錘（莫三堂叔）交涉 |

---

## 7. 轉職任務的 NPC 掛鉤（id 必須與規範書 6.x JSON 一致）

| NPC id | 任務 | 步驟 | `action` |
| :--- | :--- | :--- | :--- |
| `dao_observatory_xingyuan` | `tier1_dao_initiation` | step 1 領【渾天黃銅鏡】 | `talk` |
| `dao_hall_xuanji` | `tier1_dao_initiation` | step 3 審閱風向圖、辯證問答 | `dialogue_choice` |
| `wu_arena_zhaomeng` | `tier1_wu_initiation` | step 2 抗三記鐵砂崩拳（3 rounds） | `survive_combat` |
| `wu_hall_bashan` | `tier1_wu_initiation` | step 3 敬茶立誓、簽生死狀 | `pledge` |
| `gong_hall_ouyang` | `tier1_gong_initiation` | step 3 送呈圖紙、領天工烏木尺 | `submit_craft` |

**一階獎勵**：三條任務皆給 `exp 1200` 與 `class_grant`；物品分別是 `/clone/book/dao_basic_manual.c`、`/clone/armour/wu_iron_belt.c`、`/clone/tool/gong_ebony_ruler.c`。

**各道統教官可教的技能（Skill Lv.31 起，規範書 5.2～5.4）**

- 玄機真人 / 星淵：`dao_tuna` `dao_jiefa` `dao_observing` `dao_fuling` `dao_fuzhen` `dao_fudun` `dao_jinglei`
- 霸山 / 趙猛 / 執法教頭：`wu_cuigu` `wu_fuhu` `wu_kaishan` `wu_qixue` `wu_panshi` `wu_pijia` `wu_gong_sheshi` `wu_gong_yingshi`
- 歐陽大師 / 莫錘 / 孫先生 / 魯長生：`gong_analysis` `gong_qiaojin` `gong_yingli` `gong_cuihuo` `gong_xingzhen` `gong_fengdu` `gong_jiguan` `gong_feizhua`

（誰教哪一支，規範書沒指定，以上是依職能的建議分配。）

---

## 8. 三日通牒緩衝路徑與發放 NPC

| 路徑 | NPC | 取得物 | 延長 |
| :--- | :--- | :--- | :--- |
| A 抄書工 | `academy_lufuzi` | 【學塾白鹿青衿】 | +14 天 |
| B 車馬腳力 | `caravan_yard_biaotou` | 【車馬行短褐腰牌】 | +7 天 |
| C 試藥童 | `clinic_baixiansheng` | 【杏林藥囊腰牌】 | +10 天 |

---

## 9. 已裁定事項與仍待確認

### 9.1 已裁定（依你提供的裁定結果，已同步到本清單）

1. **三柱變數**：正典統一 `kee`（str+con）、`sen`（spi+int）、`sp`（dex+per）。規範書 5.1/5.3/5.4 已改；`living.c` 保留 `qi→kee`、`jing→sp`、`shen→sen` 相容別名。**NPC 物件一律只寫 `kee/sen/sp`，不要用別名。**
2. **房間 ID**：以 4.3 為準（`/d/city/gate/gate_west`、`/d/city/south/canal`）；`gate_water`、`canal_dock` 只是敘事稱呼。
3. **`/d/city/west/dao_roof`** 為正典房間，宣道司共 5 間：`dao_gate`、`dao_hall`、`dao_observatory`、`dao_quiet`、`dao_roof`。規範書沒給 `dao_gate`、`dao_roof` 的 NPC；`dao_roof` 是任務考核點，不需要 NPC。
4. **同名防撞**：「稱謂專有化＋全名優先＋特有外號 ID 分流」，禁止用單字百家姓（`zhao`、`mo`、`jia`、`ge`）當 `set_id`。

### 9.2 本清單中受影響的 NPC 與 `set_id`（最終裁定版）

| NPC | 正式名 | `set_id`（已裁定並消除二次衝突） | 玩家 ask 推薦別名 |
| :--- | :--- | :--- | :--- |
| `wu_arena_zhaomeng` | 趙猛 | `"wu_arena_zhaomeng"` `"zhao meng"` `"zhaomeng"` `"arena instructor"` `"趙猛"` `"鐵臂"` `"趙教頭"` | `ask zhaomeng` / `ask 趙猛` |
| `outer_farmland_w_zhaodingtian` | 趙定田（趙大叔） | `"outer_farmland_w_zhaodingtian"` `"farmer zhao"` `"zhao dingtian"` `"dingtian"` `"趙定田"` `"趙大叔"` | `ask dingtian` / `ask 趙大叔` |
| `gong_forge_mochui` | 莫錘 | `"gong_forge_mochui"` `"mochui"` `"mo chui"` `"blacksmith"` `"莫錘"` `"莫大師"` `"鍛造大師"` | `ask mochui` / `ask blacksmith` |
| `pawnshop_jiachaofeng` | 賈朝奉（賈富春） | `"pawnshop_jiachaofeng"` `"jia chaofeng"` `"pawn_jia"` `"pawnbroker"` `"jia fuchun"` `"pawn chaofeng"` `"賈朝奉"` `"賈富春"` `"賽半仙"` `"當鋪朝奉"` | `ask jia chaofeng` / `ask pawnbroker` |
| `yamen_prison_zhaodegui` | 趙德貴 | `"yamen_prison_zhaodegui"` `"zhao degui"` `"degui"` `"steward zhao"` `"趙德貴"` `"趙管事"` | `ask degui` / `ask 趙德貴` |

### 9.3 二次別名衝突處置（已全數解決）

- **`"大師"` 分流**：莫錘移除裸 `"大師"`，改用 `"莫大師"`、`"鍛造大師"`；歐陽大師使用 `"歐陽大師"`、`"匠首"`，徹底避免 `ask 大師` 混淆。
- **`"chaofeng"` / `"朝奉"` 分流**：當鋪賈富春使用 `"jia chaofeng"`、`"pawn chaofeng"`、`"當鋪朝奉"`；錢莊大朝奉命名為**沈萬通**，使用 `"bank_chief"`、`"shen wantong"`、`"bank chaofeng"`、`"錢莊朝奉"`，均不使用裸 `"chaofeng"`。
- **`"blacksmith"` 專有化**：`"blacksmith"` 僅保留給百工千錘地爐坊莫錘；軍鎮披甲兵器庫的武守備使用 `"quartermaster"`、`"sharpener"`。
- **`"instructor"` 分流**：移除裸 `"instructor"`，依職能分流為趙猛 `"arena instructor"`、岳千軍 `"wrestling instructor"`、鐵面雷 `"enforcer instructor"`。
- **其餘同姓防撞**：魯長生（`lu changsheng`）／魯大山（`lu dashan`）、錢不換（`qian buhuan`）／錢百川（`qian baichuan`）、韓清（`han qing`）／韓老雕（`han laodiao`）均嚴禁使用單字拼音（`lu`、`qian`、`han`），一律採用全名拼音與規範清單 ID。
- **既有實裝檔名與規範 ID 雙向相容**：既有檔案保留原路徑（如 `center_pawn_jia.c`），但在 `set_id()` 陣列首項均補入本清單之標準 ID（如 `"pawnshop_jiachaofeng"`），新檔案則直接以 `/clone/npc/<清單id>.c` 命名，確保任務腳本與玩家指令雙向無縫運作。

### 9.4 規範書遺留問題最終裁定（已全數落實）

1. **分區歸屬統一**：`shanghui_hq`、`market_special`、`caravan_yard`、`warehouse_shang` 四處商貿節點統一歸入 `/d/city/south/`（商貿與漕運分區），並已補建第 45 間都城房間 `/d/city/south/warehouse_shang.c`（北連 `caravan_yard.c`），同時打通 `south/shanghui_hq.c` ↔ `under/shang_secret.c` 密道。
2. **錢不換與錢百川之關係**：裁定為**金石錢氏同族堂兄弟**。錢不換作為堂兄錢百川安插在內城「金石大客棧」的明面掌櫃與情報眼線，替商會監看入城外埠巨賈、修士與可疑逃民。
3. **第一卷黑石鋪收貨端懸念**：裁定第一卷黑石鋪私自熔鑄之「高濃度地煞血精晶錠」與【金石內造・丙字柒號】坩堝，其都城端明面收貨保護傘即為**金石商會副會長錢百川**（經由商會三號大庫 `warehouse_shang` 與天字一號密室 `shang_secret` 暗中轉運，背後更牽連都城高層軍工與假天道化利益鏈）。
4. **「斷魂刀」本名**：裁定本名為**厲無咎**（前鎮風邊軍刀客，因早年邊關死鬥斷去左手一指、刀法狠辣不留活口而得號「斷魂刀」，退役後受霸山之邀擔任八方武館生死擂台總裁判）。
5. **等級與六維公式**：已於 `/std/npc.c` 實裝 `setup_archetype(string arch, int lv)`，嚴格依照第 2 節 12 原型（A～L）與等級縮放比例 `(18 + lv) / 38` 自動推算六維與 `kee/sen/sp` 三柱上限。
