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
| `item_dao_crystal` | 道化晶石殘片 | 柳清虛 | material/evidence | 用於研究道化晶化病理 | 與顧玄古礦地煞晶核殘片不同物件 | canon |

> **五器共鳴規則待核**：原始文件在「五器」數量與沈泥持有的天門引、青銅契版之間存在口徑問題。建議把五件共鳴核心定義為五條遺物承載線，而不是把沈泥的兩件物品直接算成兩個核心槽位；最終須以第二卷第 82 章正文及物品檔裁定。不得自行用道化晶石替換顧玄的古礦地煞晶核。

## 2. Tier 2 新增信物與資格

| ID | 名稱 | 類型 | 來源／用途 | 權限限制 | 狀態 |
|---|---|---|---|---|---|
| `cred_taiqing_outer_token` | 太清玄天宮外門玉牌 | credential | 外門身分、課業與基本山門通行 | 不可進藏星秘閣 | proposed |
| `cred_bahuang_camp_plate` | 八荒黑山營腰牌 | credential | 軍營編制、輪值與補給領取 | 非軍令不得進北線關口 | proposed |
| `cred_tiangong_artisan_tag` | 天工閣外門匠牌 | credential | 工坊工具與材料領用 | 高危地窟需雙人批令 | proposed |
| `cred_danding_medical_tag` | 丹鼎宗百草谷藥牌 | credential | 藥田、醫理院基礎權限 | 病案室需病患授權或院令 | proposed |
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
| `pill_reverse_dao_life` | 逆道延命血丹 | consumable/evidence | 暫時壓制部分道化／氣血症狀的禁藥 | 可能以血精為原料；短期療效不等於長期安全 | canon premise |
| `pill_clear_mind` | 清心散 | consumable | 緩解低階神識躁動 | 不治療道化根因 | derived |
| `pill_blood_cooling` | 沸血降燥湯 | consumable | 暫時降低氣血燥火 | 需監測體溫與內臟負荷 | proposed |
| `pill_herb_poultice` | 雪線續脈膏 | consumable | 凍傷與筋脈損傷輔助處理 | 不可替代醫療與休養 | proposed |
| `sample_discarded_pill` | 廢丹批次樣本 | evidence/material | 對照丹爐批次與藥渣 | 需封存、記錄封泥與保管鏈 | proposed |

## 5. 工具、儀器與機關構件

| ID | 名稱 | 類型 | 用途 | 限制 | 狀態 |
|---|---|---|---|---|---|
| `tool_star_observation_plate` | 星曆觀測校驗板 | tool | 對照原始觀測與重抄星圖 | 只能量測差異，不會自行解釋原因 | proposed |
| `tool_black_iron_caliper` | 阿鐵精鋼卡尺 | tool | 精密量測機件公差 | 量測精度受校準與操作者影響 | canon |
| `tool_rift_seismic_pin` | 裂谷地脈震針 | tool | 記錄地層震動與週期 | 只能記錄局部資料，不能定位整條母脈 | proposed |
| `tool_sample_seal_case` | 雙層封存匣 | tool/evidence container | 保存血精、藥渣與水土樣本 | 封存需雙人簽名與時間戳 | proposed |
| `machine_boring_drill_head` | 鑽山傀儡鑽頭殘件 | evidence | 追查盜掘設備來源與批次 | 只有批號與工藝特徵，未必能證明操作者 | canon premise |
| `machine_ancient_mother_core` | 太古天工母機殘骸核心 | relic/structure | 方舟機關接口與傳動構件 | 不可視為可攜帶裝備或立即可啟動物品 | canon premise |

## 6. 北荒與會武證物

| ID | 名稱 | 類型 | 來源鏈 | 證明力限制 | 初始等級 |
|---|---|---|---|---|---|
| `ev3_yanshan_blood_note` | 燕山血書 | evidence | 黑冰斷谷遺址現場採集、雙人封存 | 可證明有人留下記錄；筆跡與內容需鑑定 | lead_only |
| `ev3_yanshan_arrow_mark` | 燕山箭記骨箭 | evidence | 燕隼辨識、現場位置記錄 | 可支持身分與行動路線，不能單獨證明死亡／生還 | corroborative（鑑定後） |
| `ev3_heart_guard_mirror` | 燕山護心鏡 | evidence/item | 裂隙邊緣發現 | 只能證明物品曾在此，不證明持有人去向 | lead_only |
| `ev3_drill_head` | 內造鑽山傀儡鑽頭殘件 | evidence | 盜掘現場 | 需比對工坊批次、領用簿與命令 | corroborative（來源比對後） |
| `ev3_mother_liquid_vial` | 血精母液封裝玉瓶 | evidence/material | 北荒母脈現場 | 需檢驗封裝、採樣與污染；不直接證明高層授意 | lead_only |
| `ev3_expedition_roster` | 五年前走山隊名冊殘頁 | evidence | 舊營地遺址 | 名冊缺頁，不能證明全隊名單完整 | corroborative（多方核驗後） |
| `ev3_private_purchase_ledger` | 無標記經生採辦帳頁 | evidence | 待取得 | 須追查書手、貨主、付款來源與交割地 | lead_only |

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
