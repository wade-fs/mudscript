// daemon/event_manager.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 全域事件型任務系統守護進程 (Event Manager Daemon)
// 職責：維護雙階段全域事件（大荒煞潮、黑石關軍事危機）狀態矩陣、T-Clock 時間軸、
// 單向因果數據流（任務成果 -> 變數更新 -> 狀態廣播）、客觀物證帳本與非二元結局評估器。

#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/world_event.h"

inherit "/std/object.c";

// ── 全域狀態資料結構 ──────────────────────────────────────────
// 事件字典：event_id -> mapping
// 包含 stage, metrics, facts, quest_outcomes
mapping events;

// 物證與證物帳本：evidence_id -> mapping
mapping evidence_registry;

// 全域事件歷史日誌
mixed *event_logs;

// ── 存檔設定 ──────────────────────────────────────────────────
string query_save_file() { return "/data/world_events"; }

void save_state() {
    save_object(query_save_file());
}

void load_state() {
    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
}

// ── 階段清單常數 ──────────────────────────────────────────────
string *query_valid_stages(string event_id) {
    if (event_id == EVENT_BEAST_SURGE) {
        return ({
            STAGE_BEAST_T_MINUS_3,
            STAGE_BEAST_T_MINUS_2,
            STAGE_BEAST_T_MINUS_1,
            STAGE_BEAST_T_0,
            STAGE_BEAST_T_PLUS_1,
            STAGE_BEAST_T_PLUS_2
        });
    }
    if (event_id == EVENT_MILITARY_CRISIS) {
        return ({
            STAGE_MILITARY_STANDBY,
            STAGE_MILITARY_ARRIVAL,
            STAGE_MILITARY_CONFRONT,
            STAGE_MILITARY_ULTIMATUM,
            STAGE_MILITARY_RESOLUTION
        });
    }
    return ({ });
}

// ── 階段文字描述 ──────────────────────────────────────────────
string query_stage_desc(string event_id, string stage) {
    if (event_id == EVENT_BEAST_SURGE) {
        if (stage == STAGE_BEAST_T_MINUS_3) return "T-3：異常初顯（林冠泛紅、鳥雀驚飛、北方微帶硫磺焦味）";
        if (stage == STAGE_BEAST_T_MINUS_2) return "T-2：遷徙確認（獸痕密布、食草獸群奔逃、市集糧荒初現）";
        if (stage == STAGE_BEAST_T_MINUS_1) return "T-1：大潮臨近（狂狼先頭現蹤、富商私逃撞毀、全鎮極限備戰）";
        if (stage == STAGE_BEAST_T_0)       return "T0：主力過境（大地劇烈轟鳴、落龍口石陣與阻獸煙觸發）";
        if (stage == STAGE_BEAST_T_PLUS_1)  return "T+1：殘獸清剿（主力怒折落龍澗、殘獸衝擊木柵、清點廢墟）";
        if (stage == STAGE_BEAST_T_PLUS_2)  return "T+2：局勢反噬（下泄獸群衝斷官道、信差受困、大軍扣關對峙）";
    }
    if (event_id == EVENT_MILITARY_CRISIS) {
        if (stage == STAGE_MILITARY_STANDBY)    return "待命蟄伏（黑石關守軍封鎖山道、商會暗流湧動）";
        if (stage == STAGE_MILITARY_ARRIVAL)    return "先鋒扣關（三千精銳重弩抵達、胡百戶下達搜查封鎖令）";
        if (stage == STAGE_MILITARY_CONFRONT)   return "陣前對峙（多方物證呈遞、軍需官與主帥內部立場分歧）";
        if (stage == STAGE_MILITARY_ULTIMATUM) return "最後通牒（強攻箭在弦上、雙方進入決策最後窗口）";
        if (stage == STAGE_MILITARY_RESOLUTION) return "局勢結算（多方博弈塵埃落定、依據因果走向五大現實結局）";
    }
    return "未定義階段";
}

// ── 預設值初始化 ──────────────────────────────────────────────
void init_event_defaults(string event_id) {
    if (!events) events = ([]);

    if (event_id == EVENT_BEAST_SURGE || event_id == "all") {
        events[EVENT_BEAST_SURGE] = ([
            "stage": STAGE_BEAST_T_MINUS_3,
            "metrics": ([
                METRIC_HERD_PRESSURE       : 3, // 0~4，預設 3（大荒地煞脈動強烈）
                METRIC_ROUTE_CONFIDENCE    : 0, // 0~3，預設 0（初始不知路線）
                METRIC_DIVERSION_EFFECT    : 0, // 0~3，預設 0（尚未佈設落石煙霧）
                METRIC_SETTLEMENT_CAPACITY : 4, // 0~4，預設 4（初始聚落物資結構完好）
                METRIC_EVIDENCE_STRENGTH   : 0, // 0~3，預設 0（尚未採集黃羊與逆行跡）
                METRIC_CIVILIAN_TRUST      : 2  // 0~3，預設 2（居民不安但仍願配合）
            ]),
            "facts": ([
                "autopsy_performed"       : 0,
                "sulfur_poisoning_found"  : 0,
                "flight_direction_mapped" : 0,
                "diversion_ditch_dug"     : 0,
                "cold_smoke_stock"        : 0,
                "signal_arrows_ready"     : 0,
                "merchant_fled"           : 0,
                "merchant_supplies_looted": 0,
                "canyon_road_destroyed"   : 0,
                "residual_breach_occurred": 0
            ]),
            "quest_outcomes": ([ ])
        ]);
    }

    if (event_id == EVENT_MILITARY_CRISIS || event_id == "all") {
        events[EVENT_MILITARY_CRISIS] = ([
            "stage": STAGE_MILITARY_STANDBY,
            "metrics": ([
                METRIC_INTEL_CONFIDENCE       : 3, // 0~3，預設 3（軍方深信平亂命令）
                METRIC_EVIDENCE_VERIFIABILITY : 0, // 0~3，預設 0（無第三方獨立驗證）
                METRIC_ASSAULT_COST           : 1, // 0~3，預設 1（初始道路尚可通行）
                METRIC_SETTLEMENT_RESILIENCE  : 2  // 0~3，預設 2（對峙初期聚落尚能支撐）
            ]),
            "facts": ([
                "orders_nature"           : "containment", // containment | massacre | inspection
                "witnesses_intact"        : 1,
                "blood_drawn"             : 0,
                "officer_alignment"       : ([
                    "commander"      : "cautious",
                    "hu_baihu"       : "corrupt",
                    "quartermaster"  : "anxious",
                    "inspector"      : "impartial",
                    "merchant_rep"   : "self_preservation"
                ]),
                "supplies_intercepted"    : 0,
                "mountain_path_blocked"   : 0,
                "evacuation_tunnels_open" : 0
            ]),
            "quest_outcomes": ([ ])
        ]);
    }

    if (!evidence_registry) evidence_registry = ([]);
    if (!event_logs) event_logs = ({ });
}

void reset_event(string event_id) {
    init_event_defaults(event_id);
    save_state();
}

void create() {
    ::create();
    events = ([]);
    evidence_registry = ([]);
    event_logs = ({ });

    load_state();

    if (!events[EVENT_BEAST_SURGE] || !mapp(events[EVENT_BEAST_SURGE])) {
        init_event_defaults(EVENT_BEAST_SURGE);
    }
    if (!events[EVENT_MILITARY_CRISIS] || !mapp(events[EVENT_MILITARY_CRISIS])) {
        init_event_defaults(EVENT_MILITARY_CRISIS);
    }
    if (!evidence_registry || !mapp(evidence_registry)) {
        evidence_registry = ([]);
    }
    if (!event_logs || !arrayp(event_logs)) {
        event_logs = ({ });
    }
}

// ── 日誌紀錄器 ────────────────────────────────────────────────
void log_event(string event_id, string type, string msg) {
    if (!event_logs) event_logs = ({ });
    mapping entry = ([
        "time": time(),
        "event_id": event_id,
        "type": type,
        "msg": msg
    ]);
    event_logs += ({ entry });
    if (sizeof(event_logs) > 200) {
        event_logs = event_logs[100..];
    }
}

mixed *query_event_logs(string event_id, int limit) {
    if (!event_logs) return ({ });
    if (!event_id || event_id == "") {
        if (limit > 0 && sizeof(event_logs) > limit) {
            return event_logs[sizeof(event_logs) - limit..];
        }
        return event_logs;
    }
    mixed *filtered = ({ });
    foreach (mapping e in event_logs) {
        if (e["event_id"] == event_id) {
            filtered += ({ e });
        }
    }
    if (limit > 0 && sizeof(filtered) > limit) {
        return filtered[sizeof(filtered) - limit..];
    }
    return filtered;
}

// ── 廣播世界狀態更新 ──────────────────────────────────────────
void broadcast_event_update(string event_id, string message) {
    log_event(event_id, "broadcast", message);
    object sq = find_object("/d/village/square.c");
    if (sq) {
        tell_room(sq, "\n" + HIY "【世界事件動態】" + NOR + message + "\n");
    }
}

// ── 數值邊界與鉗位器 (Metrics & Bounds Clamping) ──────────────
mapping query_metric_bounds(string event_id, string metric) {
    if (event_id == EVENT_BEAST_SURGE) {
        if (metric == METRIC_HERD_PRESSURE)       return ([ "min": 0, "max": 4 ]);
        if (metric == METRIC_ROUTE_CONFIDENCE)    return ([ "min": 0, "max": 3 ]);
        if (metric == METRIC_DIVERSION_EFFECT)    return ([ "min": 0, "max": 3 ]);
        if (metric == METRIC_SETTLEMENT_CAPACITY) return ([ "min": 0, "max": 4 ]);
        if (metric == METRIC_EVIDENCE_STRENGTH)   return ([ "min": 0, "max": 3 ]);
        if (metric == METRIC_CIVILIAN_TRUST)      return ([ "min": 0, "max": 3 ]);
    }
    if (event_id == EVENT_MILITARY_CRISIS) {
        if (metric == METRIC_INTEL_CONFIDENCE)       return ([ "min": 0, "max": 3 ]);
        if (metric == METRIC_EVIDENCE_VERIFIABILITY) return ([ "min": 0, "max": 3 ]);
        if (metric == METRIC_ASSAULT_COST)           return ([ "min": 0, "max": 3 ]);
        if (metric == METRIC_SETTLEMENT_RESILIENCE)  return ([ "min": 0, "max": 3 ]);
    }
    return ([ "min": 0, "max": 10 ]);
}

int clamp_metric(string event_id, string metric, int val) {
    mapping bounds = query_metric_bounds(event_id, metric);
    int min_v = bounds["min"];
    int max_v = bounds["max"];
    if (val < min_v) return min_v;
    if (val > max_v) return max_v;
    return val;
}

// ── 指標查詢與修改 API ────────────────────────────────────────
int query_metric(string event_id, string metric) {
    if (!events || !events[event_id] || !events[event_id]["metrics"]) return 0;
    mapping m = events[event_id]["metrics"];
    if (undefinedp(m[metric])) return 0;
    return m[metric];
}

mapping query_all_metrics(string event_id) {
    if (!events || !events[event_id] || !events[event_id]["metrics"]) return ([]);
    return events[event_id]["metrics"];
}

int set_metric(string event_id, string metric, int val) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    if (!events[event_id]["metrics"]) events[event_id]["metrics"] = ([]);

    int clamped = clamp_metric(event_id, metric, val);
    int old_v = events[event_id]["metrics"][metric];
    events[event_id]["metrics"][metric] = clamped;

    if (clamped != old_v) {
        log_event(event_id, "metric_change", sprintf("指標【%s】由 %d 變更為 %d", metric, old_v, clamped));
        save_state();
    }
    return clamped;
}

int add_metric(string event_id, string metric, int delta) {
    int cur = query_metric(event_id, metric);
    return set_metric(event_id, metric, cur + delta);
}

// ── T-Clock 時間推進器 ─────────────────────────────────────────
string query_event_stage(string event_id) {
    if (!events || !events[event_id]) return "";
    return events[event_id]["stage"];
}

int query_stage_index(string event_id) {
    string cur = query_event_stage(event_id);
    string *stages = query_valid_stages(event_id);
    return member_array(cur, stages);
}

int set_event_stage(string event_id, string new_stage) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    string *valid_stages = query_valid_stages(event_id);
    if (member_array(new_stage, valid_stages) == -1) {
        return 0; // 不合法的階段
    }

    string old_stage = events[event_id]["stage"];
    if (old_stage == new_stage) return 1;

    events[event_id]["stage"] = new_stage;
    string desc = query_stage_desc(event_id, new_stage);
    log_event(event_id, "stage_advance", sprintf("時間軸推進：%s -> %s（%s）", old_stage, new_stage, desc));

    broadcast_event_update(event_id, sprintf("天時轉移，世界局勢邁入新階段【%s】！\n%s", new_stage, desc));
    save_state();
    return 1;
}

string advance_event_stage(string event_id) {
    string *valid_stages = query_valid_stages(event_id);
    int cur_idx = query_stage_index(event_id);
    if (cur_idx < 0) cur_idx = 0;
    if (cur_idx + 1 < sizeof(valid_stages)) {
        string next_stage = valid_stages[cur_idx + 1];
        set_event_stage(event_id, next_stage);
        return next_stage;
    }
    return events[event_id]["stage"];
}

// ── 客觀事實帳本 API ──────────────────────────────────────────
void set_fact(string event_id, string key, mixed val) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    if (!events[event_id]["facts"]) events[event_id]["facts"] = ([]);

    events[event_id]["facts"][key] = val;
    log_event(event_id, "fact_set", sprintf("客觀事實更新：%s = %O", key, val));
    save_state();
}

mixed query_fact(string event_id, string key) {
    if (!events || !events[event_id] || !events[event_id]["facts"]) return 0;
    return events[event_id]["facts"][key];
}

mapping query_all_facts(string event_id) {
    if (!events || !events[event_id] || !events[event_id]["facts"]) return ([]);
    return events[event_id]["facts"];
}

// ── 物證與證物帳本 API (Evidence Ledger) ──────────────────────
int register_evidence(string ev_id, mapping data) {
    if (!ev_id || ev_id == "" || !data || !mapp(data)) return 0;
    if (!evidence_registry) evidence_registry = ([]);

    mapping item = copy(data);
    item["id"] = ev_id;
    if (!item["created_at"]) item["created_at"] = time();
    if (!item["seen_by"] || !arrayp(item["seen_by"])) item["seen_by"] = ({ });
    if (undefinedp(item["strength"])) item["strength"] = 1;
    if (undefinedp(item["verified"])) item["verified"] = 0;

    evidence_registry[ev_id] = item;
    log_event(EVENT_MILITARY_CRISIS, "evidence_registered", sprintf("登錄物證【%s】：%s（強度 %d）", ev_id, item["name"] ? item["name"] : "", item["strength"]));
    save_state();
    return 1;
}

int mark_evidence_seen(string ev_id, string actor_id) {
    if (!evidence_registry || !evidence_registry[ev_id] || !actor_id || actor_id == "") return 0;

    mapping ev = evidence_registry[ev_id];
    string *seen = ev["seen_by"];
    if (member_array(actor_id, seen) == -1) {
        seen += ({ actor_id });
        ev["seen_by"] = seen;

        log_event(EVENT_MILITARY_CRISIS, "evidence_seen", sprintf("物證【%s】已被重要角色【%s】親眼檢驗", ev_id, actor_id));

        // 如果第三方官員（如 inspector 隨軍監軍或 commander 先鋒主帥）見到，自動強化核驗強度
        if (actor_id == "commander" || actor_id == "inspector" || actor_id == "judge") {
            ev["verified"] = 1;
            add_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY, 1);
            add_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE, -1);
        }

        save_state();
        return 1;
    }
    return 0;
}

int is_evidence_seen_by(string ev_id, string actor_id) {
    if (!evidence_registry || !evidence_registry[ev_id]) return 0;
    string *seen = evidence_registry[ev_id]["seen_by"];
    if (!arrayp(seen)) return 0;
    return (member_array(actor_id, seen) != -1);
}

mapping query_evidence(string ev_id) {
    if (!evidence_registry || !evidence_registry[ev_id]) return ([]);
    return evidence_registry[ev_id];
}

mapping query_all_evidence() {
    if (!evidence_registry) return ([]);
    return evidence_registry;
}

// ── 單向數據流：任務成果結算與狀態增量寫入 ───────────────────
mapping apply_quest_outcome(string event_id, string quest_id, mapping outcome) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    if (!outcome || !mapp(outcome)) return ([]);

    mapping applied_deltas = ([]);

    // 1. 處理 deltas
    mapping deltas = outcome["deltas"];
    if (deltas && mapp(deltas)) {
        foreach (string mname, int delta in deltas) {
            int new_val = add_metric(event_id, mname, delta);
            applied_deltas[mname] = delta;
        }
    }

    // 2. 處理直接傳入的 *_delta 鍵
    foreach (string k, mixed val in outcome) {
        if (intp(val) && strlen(k) > 6 && substr(k, strlen(k) - 6, 6) == "_delta") {
            string mname = substr(k, 0, strlen(k) - 6);
            int new_val = add_metric(event_id, mname, val);
            applied_deltas[mname] = val;
        }
    }

    // 3. 處理物證登錄 (若有附帶)
    if (outcome["evidence"] && mapp(outcome["evidence"])) {
        mapping ev = outcome["evidence"];
        if (ev["id"]) {
            register_evidence(ev["id"], ev);
        }
    }

    // 4. 處理客觀事實更新 (若有附帶)
    if (outcome["facts"] && mapp(outcome["facts"])) {
        foreach (string fk, mixed fv in outcome["facts"]) {
            set_fact(event_id, fk, fv);
        }
    }

    // 5. 紀錄任務結算成果
    mapping q_record = ([
        "quest_id": quest_id,
        "status": outcome["status"] ? outcome["status"] : "success",
        "applied_deltas": applied_deltas,
        "message": outcome["message"] ? outcome["message"] : "",
        "timestamp": time()
    ]);

    if (!events[event_id]["quest_outcomes"]) events[event_id]["quest_outcomes"] = ([]);
    events[event_id]["quest_outcomes"][quest_id] = q_record;

    log_event(event_id, "quest_outcome", sprintf("任務【%s】結算完成（%s）：%s", quest_id, q_record["status"], q_record["message"]));

    if (outcome["message"] && outcome["message"] != "") {
        broadcast_event_update(event_id, outcome["message"]);
    }

    save_state();
    return q_record;
}

mapping query_quest_outcome(string event_id, string quest_id) {
    if (!events || !events[event_id] || !events[event_id]["quest_outcomes"]) return ([]);
    return events[event_id]["quest_outcomes"][quest_id];
}

mapping query_all_quest_outcomes(string event_id) {
    if (!events || !events[event_id] || !events[event_id]["quest_outcomes"]) return ([]);
    return events[event_id]["quest_outcomes"];
}

// ── 動態因果評估器：大荒煞潮 ─────────────────────────────────
mapping evaluate_beast_surge() {
    int pressure    = query_metric(EVENT_BEAST_SURGE, METRIC_HERD_PRESSURE);
    int confidence  = query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE);
    int diversion   = query_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT);
    int capacity    = query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY);
    int trust       = query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST);

    // 導流成功度評分 (0 ~ 100)
    int diversion_score = (diversion * 30) + (confidence * 15);
    if (diversion_score > 100) diversion_score = 100;

    string main_route = "village_impact"; // 預設直衝聚落
    int canyon_deflected_percent = 0;
    int canyon_road_destroyed = 0;
    string settlement_state = "devastated";

    if (diversion >= 2 && confidence >= 2) {
        main_route = "canyon";
        canyon_deflected_percent = 85 + (diversion == 3 ? 10 : 0);
        canyon_road_destroyed = 2; // 下泄獸潮衝斷金石官道！
        settlement_state = (capacity >= 2) ? "intact" : "starvation_risk";
    } else if (diversion >= 1 || confidence >= 1) {
        main_route = "partial_deflected";
        canyon_deflected_percent = 40 + diversion * 15;
        canyon_road_destroyed = 1; // 官道部分受損
        settlement_state = "partial_damage";
    } else {
        main_route = "village_impact";
        canyon_deflected_percent = 10;
        canyon_road_destroyed = 0;
        settlement_state = "devastated";
    }

    // 連動軍事危機的攻村成本 (若官道被獸潮衝毀，軍隊強攻成本巨幅增加)
    if (canyon_road_destroyed > 0) {
        set_fact(EVENT_MILITARY_CRISIS, "mountain_path_blocked", canyon_road_destroyed);
        set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 1 + canyon_road_destroyed);
    }

    mapping result = ([
        "diversion_score"            : diversion_score,
        "main_herd_route"            : main_route,
        "canyon_deflected_percent"   : canyon_deflected_percent,
        "canyon_road_destruction"    : canyon_road_destroyed,
        "settlement_state"           : settlement_state,
        "residual_risk"              : (100 - canyon_deflected_percent),
        "pressure"                   : pressure,
        "civilian_cohesion"          : trust
    ]);

    return result;
}

// ── 動態因果評估器：黑石關軍事危機 (5 大非二元結局) ──────────
mapping evaluate_military_crisis() {
    int intel_conf    = query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE);
    int verifiability = query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY);
    int assault_cost  = query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST);
    int resilience    = query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE);

    int witnesses_ok  = query_fact(EVENT_MILITARY_CRISIS, "witnesses_intact");
    int blood_drawn   = query_fact(EVENT_MILITARY_CRISIS, "blood_drawn");
    int tunnels_open  = query_fact(EVENT_MILITARY_CRISIS, "evacuation_tunnels_open");

    string ending_code = ENDING_C_DELAYED_ULTIMATUM;
    string ending_name = "延遲進攻，危機未解";
    string ending_desc = "軍方給出限期覆核期限，危機懸而未決。";

    // 結局 D：局部衝突與有限傷亡
    // 條件：已發生不可逆流血事件
    if (blood_drawn) {
        ending_code = ENDING_D_LOCAL_SKIRMISH;
        ending_name = "局部衝突，有限傷亡（代價破局）";
        ending_desc = "陣前爆發小規模流血摩擦；但流血代價反向驚動後方督撫彈劾御史，迫使主帥緊急鳴金收兵介入問責。";
    }
    // 結局 A：暫停進攻，正式調查
    // 條件：未流血 + 軍令情報信任顯著動搖 (<=1) + 客觀證據核驗度高 (>=2) + 證人存活
    else if (intel_conf <= 1 && verifiability >= 2 && witnesses_ok) {
        ending_code = ENDING_A_FORMAL_INVESTIGATION;
        ending_name = "暫停進攻，正式調查（低傷亡最佳路徑）";
        ending_desc = "隨軍監軍與中立將領正式介入，收回胡百戶兵符，成立三堂覆核公堂就地徹查礦難與走私。";
    }
    // 結局 B：有限封鎖，局部妥協
    // 條件：強攻成本過高 (>=2) 且尚未發生大規模流血
    else if (assault_cost >= 2) {
        ending_code = ENDING_B_LIMITED_BLOCKADE;
        ending_name = "有限封鎖，局部妥協（常見社會博弈結果）";
        ending_desc = "大軍因後勤糧秣斷絕且山道崩毀，放棄屠村強攻；黑石鋪交出涉案走私帳房與部分乾股名冊，換取官軍有限搜查後退兵。";
    }
    // 結局 E：疏散撤離，聚落重組
    // 條件：軍隊強攻意志不可動搖 (intel_conf >= 3)，但黑石鋪暗渠完全暢通
    else if (intel_conf >= 3 && tunnels_open) {
        ending_code = ENDING_E_EVACUATION_REBUILD;
        ending_name = "疏散撤離，聚落重組（大荒流亡）";
        ending_desc = "黑石鋪地面空村遭官軍佔領查封，但全鎮主力人口依託暗渠深山撤離，核心罪證由少年攜出走向府城。";
    }
    // 局部摩擦觸發 (無流血但內部崩潰且成本低)
    else if (intel_conf >= 2 && resilience <= 1 && assault_cost <= 1 && !tunnels_open) {
        ending_code = ENDING_D_LOCAL_SKIRMISH;
        ending_name = "局部衝突，有限傷亡（代價破局）";
        ending_desc = "陣前爆發小規模流血摩擦；但流血代價反向驚動後方督撫彈劾御史，迫使主帥緊急鳴金收兵介入問責。";
    }
    // 結局 C：延遲進攻，危機未解（保底）
    else {
        ending_code = ENDING_C_DELAYED_ULTIMATUM;
        ending_name = "延遲進攻，危機未解（時間換空間）";
        ending_desc = "雙方在寨門前僵持不下，主帥暫緩三日下達最後通牒，為黑石鋪爭取到最後的轉圜窗口。";
    }

    mapping breakdown = ([
        "ending_code"    : ending_code,
        "ending_name"    : ending_name,
        "description"    : ending_desc,
        "intel_conf"     : intel_conf,
        "verifiability"  : verifiability,
        "assault_cost"   : assault_cost,
        "resilience"     : resilience,
        "witnesses_ok"   : witnesses_ok,
        "blood_drawn"    : blood_drawn,
        "tunnels_open"   : tunnels_open
    ]);

    return breakdown;
}

// ── 狀態儀表板診斷輸出 (Dashboard Dump) ───────────────────────
string dump_status(string event_id) {
    if (!events || !events[event_id]) return "【事件守護進程】查無指定事件狀態。\n";

    string out = "\n" + HIW + "========================================================\n" + NOR;
    out += sprintf(HIG + "  《遺忘的世界》世界事件監控儀表板：%s\n" + NOR, event_id);
    out += HIW + "========================================================\n" + NOR;

    out += sprintf(CYN + "【當前階段】" + NOR + "%s (%s)\n", events[event_id]["stage"], query_stage_desc(event_id, events[event_id]["stage"]));
    out += CYN + "【指標矩陣】\n" + NOR;
    mapping m = events[event_id]["metrics"];
    if (m && mapp(m)) {
        foreach (string mk, int mv in m) {
            mapping b = query_metric_bounds(event_id, mk);
            out += sprintf("  * %-26s: %d (範圍 %d~%d)\n", mk, mv, b["min"], b["max"]);
        }
    }

    out += CYN + "【客觀事實】\n" + NOR;
    mapping f = events[event_id]["facts"];
    if (f && mapp(f)) {
        foreach (string fk, mixed fv in f) {
            out += sprintf("  * %-26s: %O\n", fk, fv);
        }
    }

    if (event_id == EVENT_MILITARY_CRISIS && evidence_registry && sizeof(evidence_registry) > 0) {
        out += CYN + "【物證帳本】\n" + NOR;
        foreach (string ek, mapping ev in evidence_registry) {
            out += sprintf("  * [%s] %s | 強度: %d | 核驗: %d | 過目者: %s\n",
                ek,
                ev["name"] ? ev["name"] : "",
                ev["strength"],
                ev["verified"],
                implode(ev["seen_by"], ", ")
            );
        }
    }

    out += HIW + "--------------------------------------------------------\n" + NOR;
    if (event_id == EVENT_BEAST_SURGE) {
        mapping eval_b = evaluate_beast_surge();
        out += sprintf(HIY + "【煞潮即時因果評估】\n" + NOR);
        out += sprintf("  導流總評分：%d%% | 主力走向：%s (下泄分流 %d%%)\n", eval_b["diversion_score"], eval_b["main_herd_route"], eval_b["canyon_deflected_percent"]);
        out += sprintf("  官道損毀級別：%d | 聚落生存態勢：%s\n", eval_b["canyon_road_destruction"], eval_b["settlement_state"]);
    }
    if (event_id == EVENT_MILITARY_CRISIS) {
        mapping eval_m = evaluate_military_crisis();
        out += sprintf(HIY + "【軍事危機即時評估】\n" + NOR);
        out += sprintf("  收斂結局代碼：%s (%s)\n", eval_m["ending_code"], eval_m["ending_name"]);
        out += sprintf("  結局說明：%s\n", eval_m["description"]);
    }

    out += HIW + "========================================================\n" + NOR;
    return out;
}
