# 敘事事件與系統機制映射 (Narrative Events Mapping)

本目錄記錄小說各章節的核心敘事事件，及其在 MUD 引擎中由 `MYSTERY_D` (`/daemon/mysteryd.c`) 與 `WORLD_STATE_D` (`/daemon/world_state_d.c`) 管理的實作映射。

---

## 第一卷：黑石破曉事件映射表

| 章節 | 視角主角 | 核心敘事事件 | MUD 觸發動詞與房間 | 系統事件 ID (`personal_event/*`) | 機制與天命獎勵 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **第 1 章** | 顧玄<br>*(採藥孤兒)* | 晨曦洗滌石板，破除認知盲區，拓印逆星斷碑 | `study stone`<br>`tuoyin stone`<br>`/d/village/stream.c` | `study_ruin_stone`<br>`tuoyin_stone` | 悟性提升、獲得【殘缺星圖拓片】(`stele_rubbing.c`)、**天命 +1** |
| **第 2 章** | 林鐵生<br>*(打鐵學徒)* | 地爐千錘百鍊，粗鐵礦核碎裂，顯露不融黑鐵 | `bellows`<br>`strike ore`<br>`/d/village/forge.c` | `forge_ancient_black_iron` | 領悟「瘋魔打鐵法」、獲得【太古不融黑鐵構件】(`ancient_black_iron.c`)、**天命 +1** |
| **第 3 章** | 燕隼<br>*(獵戶之子)* | 追蹤黑熊暗紫濁血，以荒血共鳴戰神圖騰玄柱 | `trap`<br>`track`<br>`totem`<br>`/d/village/forest.c` | `commune_forest_totem` | 臂力身法淬鍊、加固防獸陷阱降低獸潮警報、**天命 +1** |
| **第 4 章** | 柳清虛<br>*(破落道童)* | 孤岩撥開老松取道化晶石，神識窺天天羅偽籠 | `meditate`<br>`search pine`<br>`stargaze`<br>`/d/village/altar.c` | `search_altar_pine`<br>`stargaze_altar` | 獲得【道化晶石殘片】(`dao_crystal.c`)、悟性+2 靈性+2、**天命 +1** |
| **第 5 章** | 沈泥<br>*(流浪乞兒)* | 貼牆偷聽官軍勒索內幕，爛泥深處扒出天門引 | `eavesdrop`<br>`search wood`<br>`/d/village/shed.c` | `eavesdrop_shed`<br>`search_shed_wood` | 洞察商道實情（定力+1）、獲得【萬物行商・天門引】(`tianmen_token.c` 休眠殘缺)、**天命 +1** |

---

## 世界級與區域級事件連動 (World State Events)

* **北崖地質裂變**：昨夜落石使初始穩定度降至 65%，採礦震動會進一步降低穩定度，歸零則觸發巨石塌方，需全村協力搬運搶修 (`clear`)。
* **商道封鎖與勒索真相**：官方宣稱天災山體滑坡，實為城防軍強索三成乾股；商隊入駐後大掌櫃開市收購粗礦、柴刀與藥草。
* **東林地煞與獸群躁動**：地煞濃度影響黑熊暗紫濁血活性；獵戶巡視修復陷阱 (`trap`) 能壓制獸潮躁動度。
