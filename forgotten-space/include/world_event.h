// include/world_event.h
// 《遺忘的世界》(THE FORGOTTEN SPACE) 全域事件型任務系統常數與巨集定義

#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

// ── 事件識別字 (World Event IDs) ──────────────────────────
#define EVENT_BEAST_SURGE       "beast_surge"        // 第一階段：大荒煞潮
#define EVENT_MILITARY_CRISIS   "military_crisis"    // 第二階段：黑石關軍事危機

// ── 大荒煞潮 T-Clock 階段常數 ─────────────────────────────
#define STAGE_BEAST_T_MINUS_3   "T-3"   // 異常初顯 (第 19 章晨)
#define STAGE_BEAST_T_MINUS_2   "T-2"   // 遷徙確認 (第 20~22 章)
#define STAGE_BEAST_T_MINUS_1   "T-1"   // 大潮臨近 (第 23~26 章)
#define STAGE_BEAST_T_0         "T0"    // 主力過境 (第 27~28 章)
#define STAGE_BEAST_T_PLUS_1    "T+1"   // 殘獸清剿 (第 29~30 章)
#define STAGE_BEAST_T_PLUS_2    "T+2"   // 局勢反噬 (第 31~38 章)

// ── 大荒煞潮 6 大核心指標名稱 ────────────────────────────
#define METRIC_HERD_PRESSURE        "herd_pressure"         // 獸群總量與衝擊強度 (0~4)
#define METRIC_ROUTE_CONFIDENCE     "route_confidence"      // 聚落對獸潮主幹路徑的掌握度 (0~3)
#define METRIC_DIVERSION_EFFECT     "diversion_effect"      // 落龍澗階梯石陣導流工程完成度 (0~3)
#define METRIC_SETTLEMENT_CAPACITY  "settlement_capacity"   // 黑石鋪物資儲備與承載極限 (0~4)
#define METRIC_EVIDENCE_STRENGTH    "evidence_strength"     // 獸潮非攻城、乃地煞逃亡的物證強度 (0~3)
#define METRIC_CIVILIAN_TRUST       "civilian_trust"        // 聚落居民對調查與防禦措施的信任度 (0~3)

// ── 軍事危機 階段常數 ────────────────────────────────────
#define STAGE_MILITARY_STANDBY      "standby"        // 待命蟄伏
#define STAGE_MILITARY_ARRIVAL      "arrival"        // 先鋒扣關
#define STAGE_MILITARY_CONFRONT     "confrontation"  // 陣前對峙
#define STAGE_MILITARY_ULTIMATUM    "ultimatum"      // 最後通牒
#define STAGE_MILITARY_RESOLUTION   "resolution"     // 局勢結算

// ── 軍事危機 4 大核心指標名稱 ────────────────────────────
#define METRIC_INTEL_CONFIDENCE         "intel_confidence"        // 軍方對「奉命平叛」原始情報的信任度 (0~3)
#define METRIC_EVIDENCE_VERIFIABILITY   "evidence_verifiability"  // 第三方官員核驗物證之客觀強度 (0~3)
#define METRIC_ASSAULT_COST             "assault_cost"            // 軍方發動強攻屠村的政治與後勤成本 (0~3)
#define METRIC_SETTLEMENT_RESILIENCE    "settlement_resilience"   // 黑石鋪內部承受圍困對峙的韌性 (0~3)

// ── 軍事危機 5 大非二元結局代碼 ──────────────────────────
#define ENDING_A_FORMAL_INVESTIGATION   "ending_A" // 暫停進攻，正式調查
#define ENDING_B_LIMITED_BLOCKADE       "ending_B" // 有限封鎖，局部妥協
#define ENDING_C_DELAYED_ULTIMATUM      "ending_C" // 延遲進攻，危機未解
#define ENDING_D_LOCAL_SKIRMISH         "ending_D" // 局部衝突，有限傷亡
#define ENDING_E_EVACUATION_REBUILD     "ending_E" // 疏散撤離，聚落重組

#endif // WORLD_EVENT_H
