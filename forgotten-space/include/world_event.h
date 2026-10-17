// include/world_event.h
// 《遺忘的世界》(THE FORGOTTEN SPACE) 全域事件型任務系統常數與巨集定義
// 注意：指標之數值邊界 (min, max)、預設值 (default) 與階段時間代價，
// 均由 /data/event_defs/*.json 資料定義唯一驅動；本標頭檔僅定義跨系統之穩定字串識別字。

#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

// ── 事件識別字 (World Event IDs) ──────────────────────────
#define EVENT_BEAST_SURGE       "beast_surge"        // 第一階段：大荒煞潮
#define EVENT_MILITARY_CRISIS   "military_crisis"    // 第二階段：黑石關軍事危機

// ── 大荒煞潮 T-Clock 階段常數 (第 19 ~ 32 章) ──────────────
#define STAGE_BEAST_T_MINUS_3   "T-3"   // 異常初顯 (第 19 章晨)
#define STAGE_BEAST_T_MINUS_2   "T-2"   // 遷徙確認 (第 20~22 章)
#define STAGE_BEAST_T_MINUS_1   "T-1"   // 大潮臨近 (第 23~26 章)
#define STAGE_BEAST_T_0         "T0"    // 主力過境 (第 27~28 章)
#define STAGE_BEAST_T_PLUS_1    "T+1"   // 殘獸清剿 (第 29~30 章)
#define STAGE_BEAST_T_PLUS_2    "T+2"   // 局勢反噬・官道衝斷 (第 31~32 章，交接扣關)

// ── 大荒煞潮 6 大核心指標穩定鍵 (數值由資料驅動) ───────────
#define METRIC_HERD_PRESSURE        "herd_pressure"         // 獸群總量與衝擊強度
#define METRIC_ROUTE_CONFIDENCE     "route_confidence"      // 聚落對獸潮主幹逃逸路徑掌握度
#define METRIC_DIVERSION_EFFECT     "diversion_effect"      // 落龍澗工程導流完成度
#define METRIC_SETTLEMENT_CAPACITY  "settlement_capacity"   // 黑石鋪物資儲備與承載極限
#define METRIC_EVIDENCE_STRENGTH    "evidence_strength"     // 獸潮非攻城乃地煞逃亡之生態物證強度
#define METRIC_CIVILIAN_TRUST       "civilian_trust"        // 聚落居民對調查與防禦措施之信任度

// ── 軍事危機 階段常數 (第 19 ~ 38 章) ─────────────────────
#define STAGE_MILITARY_STANDBY      "standby"        // 待命蟄伏 (第 19~32 章，關隘封鎖盤查，大部隊尚未開拔)
#define STAGE_MILITARY_ARRIVAL      "arrival"        // 先鋒扣關 (第 33~34 章，三千精銳抵達，後路斷絕)
#define STAGE_MILITARY_CONFRONT     "confrontation"  // 陣前對峙 (第 35~36 章，物證呈遞，隨軍分歧)
#define STAGE_MILITARY_ULTIMATUM    "ultimatum"      // 最後通牒 (第 37 章，通牒逼降，生死抉擇)
#define STAGE_MILITARY_RESOLUTION   "resolution"     // 局勢結算 (第 38 章，收斂五大結局，第一卷終章)

// ── 軍事危機 4 大核心指標穩定鍵 (數值由資料驅動) ───────────
#define METRIC_INTEL_CONFIDENCE         "intel_confidence"        // 軍方對「奉命平亂」原始情報信任度
#define METRIC_EVIDENCE_VERIFIABILITY   "evidence_verifiability"  // 第三方官員核驗抗辯物證之客觀強度
#define METRIC_ASSAULT_COST             "assault_cost"            // 軍方強攻屠村之政治與後勤成本
#define METRIC_SETTLEMENT_RESILIENCE    "settlement_resilience"   // 黑石鋪內部承受圍困對峙之韌性

// ── 軍事危機 5 大非二元結局代碼 ──────────────────────────
#define ENDING_A_FORMAL_INVESTIGATION   "ending_A" // 暫停進攻，正式調查 (低傷亡最佳路徑)
#define ENDING_B_LIMITED_BLOCKADE       "ending_B" // 有限封鎖，局部妥協 (常見社會博弈)
#define ENDING_C_DELAYED_ULTIMATUM      "ending_C" // 延遲進攻，危機未解 (對峙保底)
#define ENDING_D_LOCAL_SKIRMISH         "ending_D" // 局部衝突，有限傷亡 (實質流血)
#define ENDING_E_EVACUATION_REBUILD     "ending_E" // 疏散撤離，聚落重組 (大荒流亡)

#endif // WORLD_EVENT_H
