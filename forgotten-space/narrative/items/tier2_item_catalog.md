# Tier 2 道具、材料與證物目錄（第三卷素材庫）

> 本目錄先定義小說與世界資料層的物件語義。除 `canon` 物件外，新道具均為提案。此階段不建立 LPC item 檔或任務 JSON；第二階段再映射 `/clone/item/`、資料欄位及取得條件。

## 0. 道具分類與證據原則

- `relic`：太古遺物，具歷史／機關／共鳴用途。
- `evidence`：證物，需有編號、名稱、型態、來源鏈、證明力限制與當前等級。
- `material`：材料，需記錄來源、純度、危險性、替代品及採集成本。
- `consumable`：丹藥、藥材或消耗品，需記錄劑量、療效、禁忌與副作用。
- `credential`：令牌、資格、通行印信，決定權限，不等於戰力。
- `tool`：工具與儀器，能降低測量或施工誤差，不自動賦予理解能力。

## 1. 跨卷既有太古遺物（不可擅自替換）

| ID（建議穩定鍵） | 名稱 | 持有人／關聯人 | 類型 | 已知功能 | 證據與限制 | 狀態 |
|---|---|---|---|---|---|---|
| `relic_reverse_star_rubbing` | 逆星斷碑拓片 | 柳清虛 | relic | 保存異常星象與古星位線索 | 拓片非完整碑文；不能單獨證明假天中樞位置 | canon |
| `relic_unmeltable_black_iron` | 太古不融黑鐵／黑鐵齒輪 | 林鐵生 | relic/material | 與太古機關構件同源，可能作為結構接口 | 材質同源不代表可直接啟動母機 | canon |
| `relic_war_god_totem_bone` | 太古戰神獵獸圖騰骨片 | 燕隼 | relic | 與荒古戰神遺塚產生共鳴 | 不等於血統授權或無限戰力 | canon |
| `relic_earth_sha_crystal_core` | 古礦地煞晶核殘片 | 顧玄 | relic/material | 與地煞血精及礦脈病理有關 | 不等於道化晶石；需檢測來源與成分 | canon |
| `relic_tianmen_yin` | 萬物行商・天門引 | 沈泥／莫三保管史 | relic/credential | 舊商盟信物與契約資料入口 | 不會因血脈自動認主；資料可能殘缺 | canon |
| `relic_bronze_treaty_plate` | 史前商盟青銅契版殘片 | 沈泥 | relic/evidence | 與九城商盟契約紀錄有關 | 不是天門引本體；需拼合與校驗 | canon |
| `evidence_yunji_roster_copy` | 舊商盟雲記名冊手抄底單 | 沈泥 | evidence | 證明雲記旁支及姓名關係 | 只能支持身世關係，不能單獨證明清洗主使 | canon |
| `item_dao_crystal` | 道化晶石殘片 | 柳清虛 | material/evidence | 用於研究道化晶化病理（`/clone/item/dao_crystal.c`，Ch. 92 升仙台採集重現） | 與顧玄古礦地煞晶核殘片不同物件 | canon (Act 2 實裝) |

> **五器共鳴規則待核**：原始文件在「五器」數量與沈泥持有的天門引、青銅契版之間存在口徑問題。建議把五件共鳴核心定義為五條遺物承載線，而不是把沈泥的兩件物品直接算成兩個核心槽位；最終須以第二卷第 82 章正文及物品檔裁定。不得自行用道化晶石替換顧玄的古礦地煞晶核。

## 2. Tier 2 新增信物與資格

| ID | 名稱 | 類型 | 來源／用途 | 權限限制 | 狀態 |
|---|---|---|---|---|---|
| `cred_taiqing_outer_token` | 太清玄天宮外門玉牌 | credential | 外門身分、課業與基本山門通行（`/clone/item/cred_taiqing_outer_token.c`） | 不可進藏星秘閣 | canon (Act 1 實裝) |
| `cred_bahuang_camp_plate` | 八荒黑山營腰牌 | credential | 軍營編制、輪值與補給領取（`/clone/item/cred_bahuang_camp_plate.c`） | 非軍令不得進北線關口 | canon (Act 1 實裝) |
| `cred_tiangong_artisan_tag` | 天工閣外門匠牌 | credential | 工坊工具與材料領用（`/clone/item/cred_tiangong_artisan_tag.c`） | 高危地窟需雙人批令 | canon (Act 1 實裝) |
| `cred_danding_medical_tag` | 丹鼎宗百草谷藥牌 | credential | 藥田、醫理院基礎權限（`/clone/item/cred_danding_medical_tag.c`） | 病案室需病患授權或院令 | canon (Act 1 實裝) |
| `yunjin_trade_ledger` | 泥途朔望雙聯貨單 | credential/evidence | 泥途商棧可追溯帳簿與朔望繩結暗記（`/clone/item/yunjin_trade_ledger.c`） | 公開帳與暗號分離 | canon (Act 1 實裝) |
| `cred_yunjin_trade_seal` | 雲津商埠行商印 | credential | 攤位、倉契、票號與交割 | 不等於免稅或公所席位 | proposed |
| `cred_north_expedition_pass` | 北荒聯合勘探通行牌 | credential | 進入指定勘探區 | 有效期、隊伍與路線綁定 | proposed |

## 3. 材料與危險資源

| ID | 名稱 | 類型 | 用途 | 危險／限制 | 狀態 |
|---|---|---|---|---|---|
| `mat_sha_blood_crystal` | 地煞血精晶錠 | material | 高能煉製、機關供能與延命丹原料 | 含地煞濁氣與生靈血怨；純度越高不代表越安全 | canon |
| `mat_sha_mother_liquid` | 血精母液 | material/evidence | 北荒母脈核心樣本 | 高危、可能破壞方舟冷卻／穩壓結構 | canon premise |
| `mat_star_iron` | 百煉星鐵 | material | 星律器具與精密構件 | 供應受星脈與採礦限制 | derived |
| `mat_fire_resistant_clay` | 地火耐材／烈礬耐火泥 | material | 丹爐、地火管道與鍛造窯 | 批次差異會造成爐體失效 | derived |
| `mat_frost_herb` | 雪線抗寒藥草 | material | 抗寒湯劑、凍傷處理 | 採集季節短，過量可能傷胃 | proposed |
| `mat_rift_beast_bone` | 裂谷荒獸骨材 | material | 弓材、護具與藥材 | 獸群遷徙期間不可無限制獵取 | derived |
| `mat_earth_fire_residue` | 地肺火脈沉積物 | material/evidence | 分析地火與水脈污染 | 需標示採樣點與時間 | proposed |

## 4. 丹藥、病理與耗材

| ID | 名稱 | 類型 | 用途 | 風險／敘事限制 | 狀態 |
|---|---|---|---|---|---|
| `pill_reverse_dao_life` | 逆道延命血丹殘樣／血丹 | consumable/evidence | 地肺丹火窟丙柒門縫暗紫爐灰與「萬山乙零四・南十三」批號紀錄（`/clone/item/pill_reverse_dao_life.c`） | 前三月壓抑、四月起血煞癌變，停藥七日反撲致死（Ch. 96–97） | canon (Act 2 實裝) |
| `pill_clear_mind` | 清心散 | consumable | 緩解低階神識躁動 | 不治療道化根因 | derived |
| `pill_blood_cooling` | 沸血降燥湯 | consumable | 暫時降低氣血燥火 | 需監測體溫與內臟負荷 | proposed |
| `pill_herb_poultice` | 雪線續脈膏暨雄黃煙袋 | consumable/tool | 永凍血原半寸對照消腫七成之續脈膏配三枚沸血雄黃煙（`/clone/item/pill_herb_poultice.c`） | 不可替代休養；低壓側風口倒灌會嗆肺（Ch. 103） | canon (Act 3 實裝) |
| `cold_herbal_decoction` | 野菊抗寒湯劑 | consumable | 金石野菊與防瘴草籽抗寒湯劑（`/clone/item/cold_herbal_decoction.c`） | 緩解早期凍傷與風寒失溫 | canon (Act 1 實裝) |
| `snowline_moss_sample` | 雪線苔與水垢密封管 | evidence/material | 寒髓草共生微苔與酸澀水垢樣本（`/clone/item/snowline_moss_sample.c`） | 僅屬個案對照樣本 (`lead_only`) | canon (Act 1 實裝) |
| `puppet_tolerance_record` | 傀儡軸套公差工單 | evidence/tool | 搬山傀儡半厘偏角與脆化麻點測繪（`/clone/item/puppet_tolerance_record.c`） | 含雙契榫楔工藝與脆化異常紀錄 (`lead_only`) | canon (Act 1 實裝) |
| `sample_discarded_pill` | 廢丹紫泥樣本匣 | evidence/material | 紫泥封口硬渣、試藥白猿病理圖譜與十七份匿名病案對照（`/clone/item/sample_discarded_pill.c`） | 陶生押印作證 (`corroborative`，不輕斷急鎮丸) | canon (Act 2 實裝) |
| `cyan_crystal_filament_vial` | 淡青晶絲樣本管 | evidence/material | 三元互濟手術自柳清虛太淵穴剝出之半寸晶絲（`/clone/item/cyan_crystal_filament_vial.c`） | 證實早期單根晶絲可剝離，伴指麻與短暫失憶代價（Ch. 100） | canon (Act 2 實裝) |

## 5. 工具、儀器與機關構件

| ID | 名稱 | 類型 | 用途 | 限制 | 狀態 |
|---|---|---|---|---|---|
| `tool_star_observation_plate` | 星曆觀測校驗板 | tool/evidence | 對照北境粗麻原卷與南境青檀宣紙定本一度半平推誤差（`/clone/item/tool_star_observation_plate.c`） | 僅能標定紙墨與度數誤差，不證幕後指使者（Ch. 91） | canon (Act 2 實裝) |
| `tiangong_anchor_blueprint` | 推進錨機延長線草圖 | evidence/tool | 巨靈神機斜樑受力延長線暨脆化鐵屑封樣（`/clone/item/tiangong_anchor_blueprint.c`） | 證實巨靈神機原係船體／平台推進錨機或轉向關節（Ch. 95） | canon (Act 2 實裝) |
| `tool_black_iron_caliper` | 阿鐵精鋼卡尺 | tool | 精密量測機件公差 | 量測精度受校準與操作者影響 | canon |
| `tool_rift_seismic_pin` | 裂谷地脈震針 | tool | 記錄地層震動與週期 | 只能記錄局部資料，不能定位整條母脈 | proposed |
| `tool_sample_seal_case` | 雙層封存匣 | tool/evidence container | 保存血精、藥渣與水土樣本 | 封存需雙人簽名與時間戳 | proposed |
| `machine_boring_drill_head` | 鑽山傀儡鑽頭殘件 | evidence | 追查盜掘設備來源與批次 | 只有批號與工藝特徵，未必能證明操作者 | canon premise |
| `machine_ancient_mother_core` | 太古天工母機殘骸核心 | relic/structure | 方舟機關接口與傳動構件 | 不可視為可攜帶裝備或立即可啟動物品 | canon premise |

## 6. 北荒與會武證物

| ID | 名稱 | 類型 | 來源鏈 | 證明力限制 | 初始等級 |
|---|---|---|---|---|---|
| `hanlin_copper_whistle` | 北線斥候乙十七銅哨 | evidence | 黑冰斷谷遺骸頸間配物（Ch. 104、111 交還韓素，`/clone/item/hanlin_copper_whistle.c`） | 證實韓林係奉命接應遭軍弩伏殺，非擅離職守 | `corroborative` (Act 3 實裝) |
| `ev3_yanshan_blood_note` | 燕山羊皮血書殘片 | evidence | 黑冰斷谷岩凹竹夾剝離封樣（`/clone/item/ev3_yanshan_blood_note.c`） | 殘見「山」字落款與「雷……非……」，後半腐毀缺署名蓋印（Ch. 104） | `corroborative` (Act 3 實裝) |
| `ev3_heart_guard_mirror` | 燕山精銅護心鏡 | evidence/item | 戰神遺塚暖風裂隙前血跡盡頭（`/clone/item/ev3_heart_guard_mirror.c`） | 砸凹半邊刻「燕」字；僅證曾抵裂隙邊緣，未見遺骸（Ch. 105） | `lead_only` (Act 3 實裝) |
| `ev3_drill_head` | 鑽山傀儡鑽頭殘件 | evidence | 方舟東側豁口砸鎖總閘炸飛後撿獲（`/clone/item/ev3_drill_head.c`） | 帶天工閣內造批號與四工役手印，尚需比對工坊原始領用簿（Ch. 109） | `corroborative` (Act 3 實裝) |
| `ev3_mother_liquid_vial` | 血精母液封裝玉瓶 | evidence/material | 東側冷卻豁口封蠟接液瓶（`/clone/item/ev3_mother_liquid_vial.c`） | 含冷卻生物質與水銀結晶；不直接證明高層本人親令（Ch. 106、109） | `corroborative` (Act 3 實裝) |
| `ev3_expedition_roster` | 五年前走山隊名冊殘頁 | evidence | 舊營地生牛皮箭筒夾層所得（`/clone/item/ev3_expedition_roster.c`） | 記燕山、韓林與十腳夫配額，缺頁待多方互核（Ch. 104） | `corroborative` (Act 3 實裝) |
| `ev3_envoy_tally` | 千機堂副執印暗金令牌暨密令 | evidence | 冰谷窄口斃殺私盟大執事搜獲（`/clone/item/ev3_envoy_tally.c`） | 大執事無遺言自白，赤煉本人親令須對照工坊領用簿（Ch. 110） | `corroborative` (Act 3 實裝) |
| `ninety_city_treaty_copy` | 九城總契拓錄暨舊盟抄頁 | evidence/lore | 方舟後勤石鋼廳室合璧臨摹本（`/clone/item/ninety_city_treaty_copy.c`） | 載《禁毀條例第七條》暨「雲記／玄木」及三宗代號；缺掌門知情鏈（Ch. 108） | `corroborative` (Act 3 實裝) |
| `yanshan_broken_arrow` | 燕山鷹記斷折骨箭 | evidence | 鬼哭冰澗三尺冰層探冰起獲（附染血八方舊皮甲，`/clone/item/yanshan_broken_arrow.c`） | 重斧／破甲弩斜切痕；僅證曾遭攔截未見遺骸（Ch. 94） | `lead_only` (Act 2 實裝) |
| `bahuang_logistics_copy` | 黑山軍需出庫副本 | evidence | 雷烈箭樓交付之天興十九年出庫副聯（`/clone/item/bahuang_logistics_copy.c`） | 證實三十斤千機火藥調往鬼哭冰澗，無高層親簽（Ch. 94） | `corroborative` (Act 2 實裝) |
| `ev3_private_purchase_ledger` | 北境三宗延命私盟密帳索引 | evidence | 雲海鬼市後門暗巷截自灰袍經生馬背（`/clone/item/ev3_private_purchase_ledger.c`） | 含十三府城、三代號與「玄木」轉帳代號，尚需與三宗對帳（Ch. 98） | `corroborative` (Act 2 實裝) |
| `sanyuan_shengji_dan` | 三元生機丹 | consumable | 顧玄西台丹試所煉淡青試丹（`/clone/item/sanyuan_shengji_dan.c`） | 溫和固脈、不含血煞引子，無法治癒逾五年老病灶（Ch. 113） | `canon` (Act 4 實裝) |
| `brittle_shahuomou_shard` | 煞火魔偶脆化晶柱碎片 | evidence | 東側器試台趙烈魔偶遭三錘震裂封存檢材（`/clone/item/brittle_shahuomou_shard.c`） | 證實異常暗紅晶柱致主軸脆化麻點，由魯長老火漆封證（Ch. 113） | `corroborative` (Act 4 實裝) |
| `wang_red_pill_vial` | 王鐵牛私藏暗紅丸藥瓶 | evidence | 青鋼演武場《點星》震破護心甲所得（`/clone/item/wang_red_pill_vial.c`） | 佐證比試違法服藥與急鎮丸依賴，須核來源簿冊（Ch. 114） | `corroborative` (Act 4 實裝) |
| `wanbao_black_iron_box` | 萬寶閣暗標黑鐵帳箱 | evidence | 雲津交割廳擠兌封庫後起獲貼三宗暗標箱（`/clone/item/wanbao_black_iron_box.c`） | 載明百八十萬靈石票期貨挪用暨「丹鼎丙柒／天工赤火／太清雷律」對流；缺親筆原署（Ch. 115–116） | `corroborative` (Act 4 實裝) |
| `sanyuan_isolation_mist` | 百草中和隔離霧劑 | consumable/tool | 雪線苔乾粉、苦參、甘草暨微溫礦灰調劑（`/clone/item/sanyuan_isolation_mist.c`） | 黏壓結晶孢子並阻毒域於盆地半里外；殺不死鶴壽體內毒瘤（Ch. 119） | `canon` (Act 4 實裝) |
| `yunjin_relief_treaty` | 雲津萬山臨時互市與救濟協約 | credential/lore | 沈泥聯合公所與票號起草、三大掌門聯署新約（`/clone/item/yunjin_relief_treaty.c`） | 除籍沒收何萬金家產並首設三宗與商埠共同議事席，屬制度第一步仍脆弱（Ch. 120） | `canon` (Act 4 實裝) |
| `sanyuan_bencao_draft` | 《三元本草祛道錄》初稿 | evidence/lore | 百草谷隔離區統整三十餘傷患暨白岩病例（`/clone/item/sanyuan_bencao_draft.c`） | 明列僅對皮下三寸早期減緩三至五成暨副作用、保障拒絕權；逾五年老病灶無救（Ch. 121） | `corroborative` (Act 5 實裝) |
| `detachable_feedback_spec` | 可拆卸機械力回授連動台圖紙 | tool/evidence | 林鐵生拒接神識導線設計之純機械回授圖紙（`/clone/item/detachable_feedback_spec.c`） | 留三席可拔卡榫席位，免神識綁死而誤差不超半厘（Ch. 121） | `conclusive` (Act 5 實裝) |
| `bahuang_rotation_manual` | 《黑山分段輪替操典暨八十七人安置名冊》 | lore/evidence | 燕隼偕雷烈、岳停山、杜青禾彙編軍制暨撫恤合冊（`/clone/item/bahuang_rotation_manual.c`） | 附「大伯燕山失聯案備忘頁」，取代血祭霸體兼保留右肩舊傷實情（Ch. 122） | `conclusive` (Act 5 實裝) |
| `reverse_star_addendum` | 《逆星歲差實測補遺（附反例欄）》 | lore/evidence | 柳清虛於星律院公開題寫反例推翻聲明並納入沈照塵兩組氣流反例（`/clone/item/reverse_star_addendum.c`） | 限三百年北境高寒帶校正，二十八宿幕後操縱者暨假天疆域續 `open`（Ch. 122） | `conclusive` (Act 5 實裝) |
| `wanshan_charter_deed` | 《萬山共治分權章程暨交接總錄》 | credential/evidence | 沈泥拒為土皇帝、月讓四成利拆六標段兼過萬票三方會簽（`/clone/item/wanshan_charter_deed.c`） | 三宗武力猶強，多方共治制度仍屬凡間自守anchors（Ch. 123, 125） | `conclusive` (Act 5 實裝) |
| `hometown_letters_bag` | 南方故人加急家書驛袋 | lore/keepsake | 蘇凝霜親筆、阿鐵代筆、葛半仙野菊花種三包、趙老獵口信、枯木老道乾松枝（`/clone/item/hometown_letters_bag.c`） | 確認人間後路與故友守望，無任何戰力加成（Ch. 125） | `canon` (Act 5 實裝) |
| `ancestor_secret_record` | 《三宗祖師密錄（封存抄頁）》 | lore/evidence | 封存觀測室玄鐵舊木匣記載歷代十七位 Lv.100 先賢單向遁入桃花源古陣（`/clone/item/ancestor_secret_record.c`） | 載明從無歸返證明亦無法確認門後係避難所或屠宰場（Ch. 124） | `conclusive` (Act 5 實裝) |

## 7. 道具資料欄位建議

未來建立 LPC 物件或資料 JSON 時，至少使用：

```json
{
  "id": "stable_item_id",
  "name": "顯示名稱",
  "kind": "relic|evidence|material|consumable|credential|tool",
  "tier": 2,
  "status": "canon|proposed|derived|open",
  "owner_or_holder": [],
  "origin": "來源地或製造者",
  "properties": {},
  "risks": [],
  "access_requirements": [],
  "evidence_record": {
    "evidence_id": null,
    "source_chain": [],
    "proof_level": null,
    "limitations": []
  },
  "related_events": [],
  "related_characters": [],
  "related_quests": []
}
```
