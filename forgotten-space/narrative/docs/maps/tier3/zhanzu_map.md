# 戰祖魔殿地圖 (`/d/realm/zhanzu/`)

> 狀態：**Act 2–4 全 3 間實體房間已實裝 (`implemented v1.0`)**。西南赤黑焦土裂谷深處由巨獸白骨與暗紅玄鐵築成，環境帶有週期性重力脈動，係大伯燕山五年流落之地（Ch. 133、139–140、150–151、159–160）。

| Room ID | 顯示名稱 | 實裝出口 | 劇情、機制與駐點 NPC |
|---|---|---|---|
| `bone_gate` | 戰祖裂谷・玄鐵巨骨哨卡 | `northeast`→`/d/realm/edge/scorch_border`、`west`→`hunting_camp`、`south`→`arena_pit` | ✅ 已實裝（`hold gate`）：重力場交替劇烈，考驗截息卸力；Ch.159–160 燕隼與燕山以楔木斜牆零死亡引開獸潮 |
| `hunting_camp` | 戰祖外圍・狩獵奴役營 | `east`→`bone_gate` | ✅ 已實裝（`hunt beast`）：駐點：`zhanzu_packmaster_tuo`（託古）、`zhanzu_quartermaster_han`（韓石）、`yan_shan`（燕山）、`lava_bone_beast`（熔骨獸） |
| `arena_pit` | 戰祖魔殿・荒古鬥獸演武坑 | `north`→`bone_gate` | ✅ 已實裝（`unlock cage`）：深鑿地底百丈鐵柵鬥獸井（Ch.150–151 槓桿破開九齒偏心閘奪救燕山與九名礦奴） |
