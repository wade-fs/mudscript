# 邊緣荒野聚落區地圖 (`/d/realm/edge/`)

> 狀態：`peach_plateau.c` 已實裝為對接入口；其餘 5 房為第四卷第一幕、第二幕與第五幕主要活動場域規劃（Ch. 127–134、141、148–149、165–170）。

| 建議 Room ID | 顯示名稱 | 建議主要出口 | 劇情與功能規劃 |
|---|---|---|---|
| `peach_plateau`（已有） | 桃花源・荒蕪碎石高原 | `north`（未來擴充）→`ash_watch_post` | 〔已實裝〕Ch.126 初臨碎石高原與三巨構初窺（`gaze horizon`） |
| `ash_watch_post` | 灰燼石堡・守夜寨 | `south`→`peach_plateau`、`east`→`stardust_salt_flats`、`west`→`edge_clinic`、`north`→`/d/realm/taixu/white_jade_steps`、`southwest`→`/d/realm/zhanzu/bone_gate`、`northeast`→`beacon_relay` | 半埋玄武岩避風石堡（Ch.127 炊煙盡頭），設地窖密會室與可拆卸換芯暖爐點；駐點：`ash_warden_qi` |
| `stardust_salt_flats` | 荒原邊・星塵塩田與電池黑市 | `west`→`ash_watch_post`、`east`→`/d/realm/wanwu/scrap_ring` | 採集高純導流塩晶兼舊晶電池貿易據點（Ch.129、145 停工發起線） |
| `edge_clinic` | 邊緣礦棚・排異緩衝醫站 | `east`→`ash_watch_post` | 顧玄與遺民醫女`stone_clinic_healer_su`照護【律令排異症】患者兼點燃三十座緩衝爐處（Ch.130, 141, 161） |
| `beacon_relay` | 荒原高坡・跨界微光信標台 | `southwest`→`ash_watch_post` | 第五幕 Ch.165–169 耗費三百斤塩晶啟動三息微光信標、遙遞家書致雲津莫三並首聚【純淨混沌三元流】處 |
