# Tier 3 地圖集索引（第四卷・桃花源異界洞天）

> **現狀說明**：起點 `/d/realm/peach_plateau.c`（**桃花源洞天・荒蕪碎石高原**）已於第三卷第五幕 Ch. 126 完成 Mudlib 實裝並通過 `test_v3_act5.c` 驗證；以下各區地圖為第四卷（Ch. 127–170）拓撲規劃藍圖（`plan v1.0`），供後續章節寫作與 `/d/realm/` 擴充實裝依序對齊。

| 文件 | 範圍 | 核心設計焦點 |
|---|---|---|
| [world_map.md](world_map.md) | Tier 3 宏觀總圖 | 碎石高原 → 邊緣石堡（`/d/realm/edge/`）→ 三極巨構（太虛／戰祖／萬物）→ 預留 Tier 4【歸墟古淵】 |
| [edge_map.md](edge_map.md) | `/d/realm/edge/` | 灰燼石堡（Ch.127 炊煙）、星塵塩田、邊緣緩衝診所與雙向微光信標站 |
| [taixu_map.md](taixu_map.md) | `/d/realm/taixu/` | 正北白玉升空階座、三百年天羅校準偏殿與靜謐晶核庫 |
| [zhanzu_map.md](zhanzu_map.md) | `/d/realm/zhanzu/` | 西南玄鐵巨骨哨卡、獵奴外營（燕山所在）與荒古鬥獸演武坑 |
| [wanwu_map.md](wanwu_map.md) | `/d/realm/wanwu/` | 正東青金外環回收場、九號離艦救生艙登錄廳、匯流井與九城離線總節點 |

## 設計約束

1. 嚴禁從 `/d/realm/peach_plateau.c` 直接跳傳三大巨構核心；所有動線必須經邊緣自治聚落與外圍關卡（驗配給牌／工會試工牌／鹽隊護照）。
2. 每條連接道路皆須註明環境代價（重力井脈動、幾何風壓、晶塵腐蝕與電池消耗）。
3. `peach_plateau.c` 保持無靜態返還凡間出口（遵守 Ch. 126 單向古陣崩毀正典）；雙向通訊僅於第五幕透過 `beacon_relay` 限制開啟。
