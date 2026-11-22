# Tier 2 地圖集索引

> 本地圖集是小說空間與 Mudlib 房間拓撲的共同設計來源。第三卷共 **77 間 Tier 2 房間**（及 `/d/realm/peach_plateau.c` 1 房）皆已完成 LPC 實裝並通過 BFS 連通及雙向可逆審計（另僅保留 `bahuang/blood_body_camp`、`broken_army_bow_fort` 與 `taiqing/thunder_talisman_hall` 為選用擴充 `draft`）。

| 文件 | 範圍 | 主要內容 |
|---|---|---|
| [world_map.md](world_map.md) | Tier 2 宏觀總圖 | 金石北關、北境官道、雲津、三山、北荒 |
| [taiqing_map.md](taiqing_map.md) | 太清玄天宮 | 山門、外門、星律院、雷符殿、藏星秘閣 |
| [bahuang_map.md](bahuang_map.md) | 八荒武山 | 山門、訓練營、養息院、長城與北荒哨站 |
| [tiangong_map.md](tiangong_map.md) | 天工閣 | 千機院、地火鍛兵台、萬機地窟、陣圖工房 |
| [danding_map.md](danding_map.md) | 丹鼎宗 | 百草谷、醫理院、地肺丹火窟、廢丹崖 |
| [yunjin_map.md](yunjin_map.md) | 雲津仙集 | 商埠公所、泥途商棧、票號、交割廳、鬼市 |
| [wastes_map.md](wastes_map.md) | 北荒裂谷 | 南沿防線、勘探營地、黑冰斷谷、北方陣基 |

## 地圖資料規範

每個房間至少記錄：`room_id`、顯示名稱、區域、出入口、地形／環境、可進入條件、常駐 NPC、關聯事件、危險與備註。地圖連線要分清楚：一般道路、季節道路、單向落差、需權限通行、劇情暫時封閉。

**驗收狀態**：`Act 1–5 implemented & verified`（含 Phase 1–4 生活圈擴建）。已完成 `/d/wastes/`(20)、`/d/yunjin/`(21)、`/d/sects/`(36) 與 `/d/realm/peach_plateau.c`(1) 之實作與 `test_v3_act1.c`～`test_v3_act5.c`、`world_liveness_audit.py` 及全圖 BFS 可達性暨雙向門徑驗證。
