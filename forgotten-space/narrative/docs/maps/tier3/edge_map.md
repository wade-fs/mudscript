# 邊緣荒野聚落區地圖 (`/d/realm/edge/`)

> 狀態：**Act 1 區段（6 房）已實裝並通過 BFS 連通與 World Liveness 2.0 檢核**；`beacon_relay` 預定於 Act 5（Ch.165–170）實裝。

| Room ID | 顯示名稱 | 出口連接（雙向對稱） | 劇情與功能（Act 1 已落地／後續預留） |
|---|---|---|---|
| `/d/realm/peach_plateau` | 桃花源・荒蕪碎石高原 | `north`→`edge/basalt_ridge` | 〔已實裝〕Ch.126 初臨碎石高原與三巨構遠眺（`gaze horizon`） |
| `/d/realm/edge/basalt_ridge` | 灰燼邊緣・玄武岩風道 | `south`→`peach_plateau`、`north`→`ash_watch_post`、`southwest`→`scorch_border` | 〔已實裝〕Ch.127, 131 夜測幾何張力與頻率夜飄（`measure vector` 解鎖 `law` `K/U`）；遊蕩灰甲砂蜥 |
| `/d/realm/edge/ash_watch_post` | 灰燼石堡・守夜寨 | `south`→`basalt_ridge`、`east`→`stardust_salt_flats`、`west`→`edge_clinic` | 〔已實裝〕Ch.127, 128, 132, 134 熄燈避檢（`douse lamps`）、阻尼實測（`test damping`）、改鑄換芯暖爐（`forge stove` 解鎖 `craft` `K/U`）；駐點：`ash_warden_qi` |
| `/d/realm/edge/stardust_salt_flats` | 荒原邊・星塵鹽田與殘晶黑市 | `west`→`ash_watch_post` | 〔已實裝〕Ch.129 揭露預扣三成戰備折抵與九號補給營鐵牌（`audit market` 寫入 `commerce` `K`）；駐點：`salt_market_broker` |
| `/d/realm/edge/edge_clinic` | 邊緣礦棚・排異緩衝醫站 | `east`→`ash_watch_post` | 〔已實裝〕Ch.130 診斷【律令排異症】與苦苔冷敷（`diagnose patient`）；駐點：`stone_clinic_healer_su` |
| `/d/realm/edge/scorch_border` | 赤黑焦土・西南獵界邊坡 | `northeast`→`basalt_ridge` | 〔已實裝〕Ch.133 拓印燕山左撇鷹記與心核加徵情報（`rub mark` 寫入 `force` `K`）；駐點：`bastion_young_hunter` |
| `beacon_relay`（規劃） | 荒原高坡・跨界微光信標台 | 預定 `northeast` 接 `ash_watch_post` | 第五幕 Ch.165–169 耗費三百斤鹽晶儲柱啟動三息微光信標、遙遞家書致雲津莫三並首聚三元雛流處 |
