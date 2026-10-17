// daemon/event_manager.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 全域事件型任務系統守護進程 (Event Manager Daemon)
// 職責：
// 1. 資料驅動（Data-driven）載入事件定義 Schema，嚴格拒絕未註冊幽靈指標
// 2. 純函式化動態評估器（Pure Evaluators：無副作用、只讀衍生視圖）
// 3. 顯式跨事件因果傳播（Explicit Propagation：只在特定 T-Clock 推進節點觸發）
// 4. 事務性與冪等任務成果結算（Transactional & Idempotent Outcome Application）
// 5. 物證帳本（Evidence Ledger）：按物證強度與獨立來源種類加權，杜絕單一物證洗分
// 6. 完備因果閉環：煞潮 6 大變數全部參與實質因果計算，軍事 5 大結局消除矛盾空間
// 7. 發布/訂閱事件匯流排（Pub/Sub Event Bus）：支援任意物件監聽與測試隔離
// 8. T-Clock 單調推進（Monotonic Progression）與時間代價衰減
// 9. 乾淨重置與版本化存檔遷移（Schema Versioning & Test Mode）

#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/world_event.h"

inherit "/std/object.c";

#define EVENT_MANAGER_VERSION 1

// ── 全域狀態資料結構 ──────────────────────────────────────────
// 事件定義池：event_id -> schema mapping
mapping event_defs;

// 事件執行期狀態：event_id -> mapping
// 包含 stage, metrics, facts, applied_outcomes
mapping events;

// 物證帳本：evidence_id -> mapping
mapping evidence_registry;

// 發布/訂閱清單：event_id -> array of mapping ([ "ob": object, "func": string ])
mapping subscribers;

// 全域事件歷史日誌
mixed *event_logs;

// 測試模式旗標 (若為 1，不寫磁碟存檔)
int test_mode;

// ── 存檔設定與版本 ────────────────────────────────────────────
string query_save_file() { return "/data/world_events"; }

void set_test_mode(int mode) { test_mode = mode; }
int query_test_mode() { return test_mode; }

void save_state() {
    if (test_mode) return;
    save_object(query_save_file());
}

// ── 資料驅動定義載入 (Data-Driven Schema Loading) ────────────
mapping get_fallback_def(string event_id) {
    if (event_id == EVENT_BEAST_SURGE) {
        return ([
            "id": EVENT_BEAST_SURGE,
            "name": "大荒煞潮",
            "version": 1,
            "stages": ({
                ([ "id": STAGE_BEAST_T_MINUS_3, "name": "異常初顯", "desc": "東林鳥雀驚飛、林冠泛紅霧、北方微風帶硫磺焦味", "duration": 180, "time_cost_impact": ([ ]) ]),
                ([ "id": STAGE_BEAST_T_MINUS_2, "name": "遷徙確認", "desc": "獸痕密布、食草獸成群南奔；集市爆發米荒衝突", "duration": 240, "time_cost_impact": ([ METRIC_SETTLEMENT_CAPACITY: -1 ]) ]),
                ([ "id": STAGE_BEAST_T_MINUS_1, "name": "大潮臨近", "desc": "先頭狂狼現蹤；私逃富商車毀人亡；全鎮極限備戰", "duration": 180, "time_cost_impact": ([ METRIC_CIVILIAN_TRUST: -1 ]) ]),
                ([ "id": STAGE_BEAST_T_0,       "name": "主力過境", "desc": "大地轟鳴，狂潮抵達落龍口；阻獸煙起、鳴鏑尖嘯、落石觸發", "duration": 60, "time_cost_impact": ([ ]) ]),
                ([ "id": STAGE_BEAST_T_PLUS_1,  "name": "殘獸清剿", "desc": "主力怒折落龍澗；殘獸衝擊木柵；晨曦破曉清點廢墟", "duration": 120, "time_cost_impact": ([ ]) ]),
                ([ "id": STAGE_BEAST_T_PLUS_2,  "name": "局勢反噬", "desc": "下泄獸群衝斷官道；信差受困；大軍扣關對峙", "duration": 0, "time_cost_impact": ([ ]) ])
            }),
            "metrics": ([
                METRIC_HERD_PRESSURE       : ([ "min": 0, "max": 4, "default": 3, "desc": "獸群總量與衝擊強度" ]),
                METRIC_ROUTE_CONFIDENCE    : ([ "min": 0, "max": 3, "default": 0, "desc": "主幹逃逸路徑掌握度" ]),
                METRIC_DIVERSION_EFFECT    : ([ "min": 0, "max": 3, "default": 0, "desc": "落龍澗工程導流完成度" ]),
                METRIC_SETTLEMENT_CAPACITY : ([ "min": 0, "max": 4, "default": 4, "desc": "聚落儲備與承載極限" ]),
                METRIC_EVIDENCE_STRENGTH   : ([ "min": 0, "max": 3, "default": 0, "desc": "地煞逃亡非攻城之物證強度" ]),
                METRIC_CIVILIAN_TRUST      : ([ "min": 0, "max": 3, "default": 2, "desc": "聚落居民信任度" ])
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
            ])
        ]);
    }

    if (event_id == EVENT_MILITARY_CRISIS) {
        return ([
            "id": EVENT_MILITARY_CRISIS,
            "name": "黑石關軍事危機",
            "version": 1,
            "stages": ({
                ([ "id": STAGE_MILITARY_STANDBY,    "name": "待命蟄伏", "desc": "黑石關守軍封鎖山道、商會暗流湧動 (第 19~32 章)", "duration": 300, "time_cost_impact": ([ ]) ]),
                ([ "id": STAGE_MILITARY_ARRIVAL,    "name": "先鋒扣關", "desc": "三千精銳重弩抵達、胡百戶下達搜查封鎖令 (第 33~34 章)", "duration": 300, "time_cost_impact": ([ ]) ]),
                ([ "id": STAGE_MILITARY_CONFRONT,   "name": "陣前對峙", "desc": "多方物證呈遞、隨軍軍需官糧草告急、主帥內部立場分歧 (第 35~36 章)", "duration": 300, "time_cost_impact": ([ METRIC_SETTLEMENT_RESILIENCE: -1 ]) ]),
                ([ "id": STAGE_MILITARY_ULTIMATUM,  "name": "最後通牒", "desc": "強攻箭在弦上、軍令催逼交出名冊、最後抉擇窗口 (第 37 章)", "duration": 180, "time_cost_impact": ([ METRIC_SETTLEMENT_RESILIENCE: -1 ]) ]),
                ([ "id": STAGE_MILITARY_RESOLUTION, "name": "局勢結算", "desc": "多方博弈塵埃落定、依據客觀事實走向五大現實結局 (第 38 章)", "duration": 0, "time_cost_impact": ([ ]) ])
            }),
            "metrics": ([
                METRIC_INTEL_CONFIDENCE       : ([ "min": 0, "max": 3, "default": 3, "desc": "軍方對平叛軍令情報信任度" ]),
                METRIC_EVIDENCE_VERIFIABILITY : ([ "min": 0, "max": 3, "default": 0, "desc": "第三方官員核驗物證強度" ]),
                METRIC_ASSAULT_COST           : ([ "min": 0, "max": 3, "default": 1, "desc": "軍方強攻屠村政治與後勤成本" ]),
                METRIC_SETTLEMENT_RESILIENCE  : ([ "min": 0, "max": 3, "default": 2, "desc": "黑石鋪承受封鎖對峙之內部韌性" ])
            ]),
            "facts": ([
                "orders_nature"           : "containment",
                "witnesses_intact"        : 1,
                "blood_drawn"             : 0,
                "mountain_path_blocked"   : 0,
                "evacuation_tunnels_open" : 0,
                "supplies_intercepted"    : 0,
                "beast_evidence_propagated": 0
            ])
        ]);
    }
    return ([]);
}

void load_event_definitions() {
    if (!event_defs) event_defs = ([]);

    string *def_files = ({
        "/data/event_defs/beast_surge.json",
        "/data/event_defs/military_crisis.json"
    });

    foreach (string path in def_files) {
        string content = read_file(path);
        if (content && content != "") {
            mixed def = json_decode(content);
            if (mapp(def) && def["id"]) {
                event_defs[def["id"]] = def;
                continue;
            }
        }
        // Fallback 若檔案不存在
        if (strsrch(path, "beast_surge") != -1) {
            event_defs[EVENT_BEAST_SURGE] = get_fallback_def(EVENT_BEAST_SURGE);
        } else if (strsrch(path, "military_crisis") != -1) {
            event_defs[EVENT_MILITARY_CRISIS] = get_fallback_def(EVENT_MILITARY_CRISIS);
        }
    }
}

mapping query_event_def(string event_id) {
    if (!event_defs) load_event_definitions();
    return event_defs[event_id];
}

// ── 嚴格指標註冊驗證 ──────────────────────────────────────────
int is_valid_metric(string event_id, string metric) {
    mapping def = query_event_def(event_id);
    if (!def || !def["metrics"]) return 0;
    return !undefinedp(def["metrics"][metric]);
}

mapping query_metric_bounds(string event_id, string metric) {
    mapping def = query_event_def(event_id);
    if (!def || !def["metrics"] || undefinedp(def["metrics"][metric])) {
        return ([ ]);
    }
    return def["metrics"][metric];
}

int clamp_metric(string event_id, string metric, int val) {
    mapping bounds = query_metric_bounds(event_id, metric);
    if (!bounds || sizeof(bounds) == 0) return val;
    int min_v = bounds["min"];
    int max_v = bounds["max"];
    if (val < min_v) return min_v;
    if (val > max_v) return max_v;
    return val;
}

// ── 階段清單與描述查詢 ────────────────────────────────────────
string *query_valid_stages(string event_id) {
    mapping def = query_event_def(event_id);
    if (!def || !def["stages"]) return ({ });
    string *res = ({ });
    foreach (mapping st in def["stages"]) {
        res += ({ st["id"] });
    }
    return res;
}

string query_stage_desc(string event_id, string stage) {
    mapping def = query_event_def(event_id);
    if (!def || !def["stages"]) return "未定義事件";
    foreach (mapping st in def["stages"]) {
        if (st["id"] == stage) {
            return sprintf("%s：%s（%s）", st["id"], st["name"], st["desc"]);
        }
    }
    return "未定義階段";
}

mapping query_stage_def(string event_id, string stage) {
    mapping def = query_event_def(event_id);
    if (!def || !def["stages"]) return ([]);
    foreach (mapping st in def["stages"]) {
        if (st["id"] == stage) return st;
    }
    return ([]);
}

// ── 狀態初始化與遷移 (Migration) ──────────────────────────────
void init_event_defaults(string event_id) {
    if (!events) events = ([]);
    load_event_definitions();

    string *target_ids = (event_id == "all") ? ({ EVENT_BEAST_SURGE, EVENT_MILITARY_CRISIS }) : ({ event_id });

    foreach (string eid in target_ids) {
        mapping def = query_event_def(eid);
        if (!def) continue;

        string initial_stage = def["stages"][0]["id"];
        mapping init_metrics = ([]);
        foreach (string mk, mapping mcfg in def["metrics"]) {
            init_metrics[mk] = mcfg["default"];
        }

        mapping init_facts = copy(def["facts"]);

        events[eid] = ([
            "stage"            : initial_stage,
            "metrics"          : init_metrics,
            "facts"            : init_facts,
            "applied_outcomes" : ([ ])
        ]);
    }

    if (event_id == "all" || event_id == EVENT_MILITARY_CRISIS) {
        evidence_registry = ([]);
    }
    if (event_id == "all") {
        event_logs = ({ });
    }
}

void load_state() {
    load_event_definitions();
    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }

    // Schema Migration：對齊指標，防止舊存檔缺欄位讀成 0
    foreach (string eid in ({ EVENT_BEAST_SURGE, EVENT_MILITARY_CRISIS })) {
        if (!events || !events[eid] || !mapp(events[eid])) {
            init_event_defaults(eid);
            continue;
        }
        mapping def = query_event_def(eid);
        if (!def) continue;

        if (!events[eid]["metrics"]) events[eid]["metrics"] = ([]);
        foreach (string mk, mapping mcfg in def["metrics"]) {
            if (undefinedp(events[eid]["metrics"][mk])) {
                events[eid]["metrics"][mk] = mcfg["default"];
            }
        }
        if (!events[eid]["facts"]) events[eid]["facts"] = copy(def["facts"]);
        if (!events[eid]["applied_outcomes"]) events[eid]["applied_outcomes"] = ([]);
    }

    if (!evidence_registry || !mapp(evidence_registry)) evidence_registry = ([]);
    if (!event_logs || !arrayp(event_logs)) event_logs = ({ });
    if (!subscribers || !mapp(subscribers)) subscribers = ([]);
}

void reset_event(string event_id) {
    init_event_defaults(event_id);
    save_state();
}

void create() {
    ::create();
    event_defs = ([]);
    events = ([]);
    evidence_registry = ([]);
    subscribers = ([]);
    event_logs = ({ });
    test_mode = 0;

    load_state();
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

// ── 發布/訂閱事件匯流排 (Pub/Sub Event Bus) ───────────────────
void subscribe(string event_id, object listener, string func_name) {
    if (!listener || !func_name || func_name == "") return;
    if (!subscribers) subscribers = ([]);
    if (!subscribers[event_id]) subscribers[event_id] = ({ });

    // 避免重複訂閱
    foreach (mapping sub in subscribers[event_id]) {
        if (sub["ob"] == listener && sub["func"] == func_name) return;
    }

    subscribers[event_id] += ({ ([ "ob": listener, "func": func_name ]) });
}

void unsubscribe(string event_id, object listener) {
    if (!subscribers || !subscribers[event_id] || !listener) return;
    mixed *filtered = ({ });
    foreach (mapping sub in subscribers[event_id]) {
        if (sub["ob"] != listener && sub["ob"]) {
            filtered += ({ sub });
        }
    }
    subscribers[event_id] = filtered;
}

void broadcast_event(string event_id, string event_type, mapping payload) {
    log_event(event_id, event_type, payload["message"] ? payload["message"] : event_type);

    // 1. 通知所有訂閱者
    if (subscribers && subscribers[event_id]) {
        mixed *clean_subs = ({ });
        foreach (mapping sub in subscribers[event_id]) {
            object ob = sub["ob"];
            string fn = sub["func"];
            if (ob && !ob->is_destructed()) {
                call_other(ob, fn, event_id, event_type, payload);
                clean_subs += ({ sub });
            }
        }
        subscribers[event_id] = clean_subs;
    }

    // 2. 如果包含玩家廣播文字，且黑石鋪廣場存在，推播至房間
    if (payload["broadcast_text"] && payload["broadcast_text"] != "") {
        object sq = find_object("/d/village/square.c");
        if (sq) {
            tell_room(sq, "\n" + HIY "【世界事件動態】" + NOR + payload["broadcast_text"] + "\n");
        }
    }
}

// ── 指標查詢與修改 API (嚴格拒絕未註冊幽靈指標) ───────────────
int query_metric(string event_id, string metric) {
    if (!events || !events[event_id] || !events[event_id]["metrics"]) return -999;
    if (!is_valid_metric(event_id, metric)) return -999;
    return events[event_id]["metrics"][metric];
}

mapping query_all_metrics(string event_id) {
    if (!events || !events[event_id] || !events[event_id]["metrics"]) return ([]);
    return copy(events[event_id]["metrics"]);
}

int set_metric(string event_id, string metric, int val) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    if (!is_valid_metric(event_id, metric)) {
        write_file("/log/event_error.log", sprintf("[EVENT_ERROR] 拒絕未註冊指標：%s.%s\n", event_id, metric), 0);
        return -999; // 嚴格拒絕未註冊幽靈指標
    }

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
    if (cur == -999) return -999;
    return set_metric(event_id, metric, cur + delta);
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
    return copy(events[event_id]["facts"]);
}

// ── 物證帳本 API (按強度與來源加權，杜絕單證刷分) ────────────
int register_evidence(string ev_id, mapping data) {
    if (!ev_id || ev_id == "" || !data || !mapp(data)) return 0;
    if (!evidence_registry) evidence_registry = ([]);

    mapping item = copy(data);
    item["id"] = ev_id;
    if (!item["created_at"]) item["created_at"] = time();
    if (!item["seen_by"] || !arrayp(item["seen_by"])) item["seen_by"] = ({ });
    if (undefinedp(item["strength"])) item["strength"] = 1;
    if (!item["source_type"]) item["source_type"] = "general";
    if (undefinedp(item["verified"])) item["verified"] = 0;

    evidence_registry[ev_id] = item;
    log_event(EVENT_MILITARY_CRISIS, "evidence_registered",
              sprintf("登錄物證【%s】：%s（強度 %d，來源：%s）", ev_id, item["name"] ? item["name"] : "", item["strength"], item["source_type"]));
    save_state();
    return 1;
}

int mark_evidence_seen(string ev_id, string actor_id) {
    if (!evidence_registry || !evidence_registry[ev_id] || !actor_id || actor_id == "") return 0;

    mapping ev = evidence_registry[ev_id];
    string *seen = ev["seen_by"];
    if (member_array(actor_id, seen) != -1) {
        return 0; // 該角色已過目此物證，絕不重複刷分
    }

    seen += ({ actor_id });
    ev["seen_by"] = seen;

    log_event(EVENT_MILITARY_CRISIS, "evidence_seen", sprintf("物證【%s】已被重要角色【%s】親眼檢驗", ev_id, actor_id));

    // 只有權威官員首次過目，且該物證未被正式核驗時，才按強度加權核驗度
    if ((actor_id == "commander" || actor_id == "inspector" || actor_id == "judge") && !ev["verified"]) {
        ev["verified"] = 1;
        int strength = ev["strength"] ? ev["strength"] : 1;
        add_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY, strength);
        add_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE, -1);
    }

    save_state();
    return 1;
}

int is_evidence_seen_by(string ev_id, string actor_id) {
    if (!evidence_registry || !evidence_registry[ev_id]) return 0;
    string *seen = evidence_registry[ev_id]["seen_by"];
    if (!arrayp(seen)) return 0;
    return (member_array(actor_id, seen) != -1);
}

mapping query_evidence(string ev_id) {
    if (!evidence_registry || !evidence_registry[ev_id]) return ([]);
    return copy(evidence_registry[ev_id]);
}

mapping query_all_evidence() {
    if (!evidence_registry) return ([]);
    return copy(evidence_registry);
}

// ── 純函式化動態評估器：大荒煞潮 (Pure Evaluator) ────────────
mapping evaluate_beast_surge() {
    int pressure    = query_metric(EVENT_BEAST_SURGE, METRIC_HERD_PRESSURE);
    int confidence  = query_metric(EVENT_BEAST_SURGE, METRIC_ROUTE_CONFIDENCE);
    int diversion   = query_metric(EVENT_BEAST_SURGE, METRIC_DIVERSION_EFFECT);
    int capacity    = query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY);
    int evidence    = query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH);
    int trust       = query_metric(EVENT_BEAST_SURGE, METRIC_CIVILIAN_TRUST);

    // 1. 勘測與物證聯動：物證為勘測提供病理與生態支撐
    int effective_route_knowledge = confidence + (evidence > 0 ? 1 : 0);
    if (effective_route_knowledge > 3) effective_route_knowledge = 3;

    // 2. 導流偏折計算 (所有因果計算為純運算，無 side effect)
    int diversion_score = (diversion * 30) + (effective_route_knowledge * 15);
    if (diversion_score > 100) diversion_score = 100;

    string main_route = "village_impact";
    int canyon_deflected_percent = 10;
    int canyon_road_destroyed = 0;

    if (diversion >= 2 && effective_route_knowledge >= 2) {
        main_route = "canyon";
        canyon_deflected_percent = 80 + (diversion == 3 ? 15 : 0);
    } else if (diversion >= 1 || effective_route_knowledge >= 1) {
        main_route = "partial_deflected";
        canyon_deflected_percent = 35 + diversion * 15;
    } else {
        main_route = "village_impact";
        canyon_deflected_percent = 10;
    }

    // 3. 落龍澗下泄動能與官道衝毀計算
    int downhill_surge = pressure * canyon_deflected_percent / 50;
    if (downhill_surge >= 4) {
        canyon_road_destroyed = 2; // 徹底衝毀
    } else if (downhill_surge >= 2) {
        canyon_road_destroyed = 1; // 部分坍塌受阻
    }

    // 4. 殘餘衝擊聚落壓力與生存態勢 (HERD_PRESSURE, SETTLEMENT_CAPACITY, CIVILIAN_TRUST 閉環)
    int residual_percent = 100 - canyon_deflected_percent;
    int residual_pressure = pressure * residual_percent / 25;
    int surviving_capacity = capacity - residual_pressure;

    string settlement_state = "devastated";
    if (canyon_deflected_percent >= 80) {
        if (capacity >= 2) settlement_state = "intact";
        else settlement_state = "starvation_risk";
    } else if (surviving_capacity >= 1) {
        settlement_state = "partial_damage";
    } else {
        settlement_state = "devastated";
    }

    int civilian_panic = (trust <= 1 && residual_pressure > 0) ? 1 : 0;

    mapping result = ([
        "diversion_score"            : diversion_score,
        "main_herd_route"            : main_route,
        "canyon_deflected_percent"   : canyon_deflected_percent,
        "canyon_road_destruction"    : canyon_road_destroyed,
        "settlement_state"           : settlement_state,
        "residual_risk"              : residual_percent,
        "residual_pressure"          : residual_pressure,
        "surviving_capacity"         : surviving_capacity,
        "civilian_panic"             : civilian_panic,
        "effective_knowledge"        : effective_route_knowledge
    ]);

    return result;
}

// ── 純函式化動態評估器：黑石關軍事危機 (Pure Evaluator) ───────
mapping evaluate_military_crisis() {
    int intel_conf    = query_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE);
    int verifiability = query_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY);
    int assault_cost  = query_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST);
    int resilience    = query_metric(EVENT_MILITARY_CRISIS, METRIC_SETTLEMENT_RESILIENCE);

    int witnesses_ok  = query_fact(EVENT_MILITARY_CRISIS, "witnesses_intact");
    int blood_drawn   = query_fact(EVENT_MILITARY_CRISIS, "blood_drawn");
    int tunnels_open  = query_fact(EVENT_MILITARY_CRISIS, "evacuation_tunnels_open");

    // 統計已驗證物證的獨立來源多樣性 (Verified Source Types)
    mapping verified_sources_map = ([]);
    if (evidence_registry && sizeof(evidence_registry) > 0) {
        foreach (string ek, mapping ev in evidence_registry) {
            if (ev["verified"] && ev["source_type"]) {
                verified_sources_map[ev["source_type"]] = 1;
            }
        }
    }
    int verified_sources = sizeof(verified_sources_map);

    string ending_code = ENDING_C_DELAYED_ULTIMATUM;
    string ending_name = "延遲進攻，危機未解";
    string ending_desc = "軍方給出限期覆核期限，雙方維持陣前對峙。";

    // 結局 D：局部衝突與有限傷亡
    // 嚴格原則：只有實質發生不可逆流血事件，才允許判為局部衝突！
    if (blood_drawn) {
        ending_code = ENDING_D_LOCAL_SKIRMISH;
        ending_name = "局部衝突，有限傷亡（代價破局）";
        ending_desc = "陣前爆發小規模流血摩擦；但流血代價反向驚動後方督撫彈劾御史，迫使主帥緊急鳴金收兵介入問責。";
    }
    // 結局 A：暫停進攻，正式調查 (低傷亡最佳路徑)
    // 條件：未流血 + 情報動搖(<=1) + 核驗度高(>=3) + 獨立來源多樣(>=2) + 證人生還
    else if (intel_conf <= 1 && verifiability >= 3 && verified_sources >= 2 && witnesses_ok) {
        ending_code = ENDING_A_FORMAL_INVESTIGATION;
        ending_name = "暫停進攻，正式調查（低傷亡最佳路徑）";
        ending_desc = "多方獨立鐵證呈遞，隨軍監軍與中立將領正式介入，收回胡百戶兵符，成立三堂覆核公堂就地徹查礦難與走私。";
    }
    // 結局 B：有限封鎖，局部妥協
    // 條件：未流血 + 強攻成本過高 (>=2)
    else if (assault_cost >= 2) {
        ending_code = ENDING_B_LIMITED_BLOCKADE;
        ending_name = "有限封鎖，局部妥協（常見社會博弈結果）";
        ending_desc = "大軍因後勤糧秣斷絕且山道崩毀，放棄屠村強攻；黑石鋪交出涉案走私帳房與部分乾股名冊，換取官軍有限搜查後退兵。";
    }
    // 結局 E：疏散撤離，聚落重組
    // 條件：未流血 + 軍隊強攻意志不可動搖 (intel_conf >= 3) + 暗渠完全暢通
    else if (intel_conf >= 3 && tunnels_open) {
        ending_code = ENDING_E_EVACUATION_REBUILD;
        ending_name = "疏散撤離，聚落重組（大荒流亡）";
        ending_desc = "黑石鋪地面空村遭官軍佔領查封，但全鎮主力人口依託暗渠深山撤離，核心罪證由少年攜出走向府城。";
    }
    // 結局 C：延遲進攻，危機未解 (對峙保底)
    else {
        ending_code = ENDING_C_DELAYED_ULTIMATUM;
        ending_name = "延遲進攻，危機未解（時間換空間）";
        ending_desc = "雙方在寨門前僵持不下，主帥暫緩三日下達最後通牒，為黑石鋪爭取到最後的轉圜窗口。";
    }

    mapping breakdown = ([
        "ending_code"       : ending_code,
        "ending_name"       : ending_name,
        "description"       : ending_desc,
        "intel_conf"        : intel_conf,
        "verifiability"     : verifiability,
        "verified_sources"  : verified_sources,
        "assault_cost"      : assault_cost,
        "resilience"        : resilience,
        "witnesses_ok"      : witnesses_ok,
        "blood_drawn"       : blood_drawn,
        "tunnels_open"      : tunnels_open
    ]);

    return breakdown;
}

// ── 顯式跨事件因果傳播 (Explicit Cross-Event Propagation) ─────
// 只在特定時間推進節點 (T0 / T+2) 顯式呼叫一次，杜絕評估器側寫污染
void propagate_beast_to_military() {
    mapping eval_b = evaluate_beast_surge();
    int road_destruction = eval_b["canyon_road_destruction"];

    // 1. 下泄狂潮對官道與軍方補給線的實質衝擊
    if (road_destruction > 0) {
        set_fact(EVENT_MILITARY_CRISIS, "mountain_path_blocked", road_destruction);
        set_metric(EVENT_MILITARY_CRISIS, METRIC_ASSAULT_COST, 1 + road_destruction);

        broadcast_event(EVENT_MILITARY_CRISIS, "path_blocked", ([
            "road_destruction": road_destruction,
            "broadcast_text": "【山道劇變】落龍澗下泄萬獸狂潮徹底沖斷金石官道！黑石關官軍糧道受阻，強攻成本劇增！"
        ]));
    }

    // 2. METRIC_EVIDENCE_STRENGTH 下游傳播：
    // 煞潮期間收集到的地煞逃亡與異獸解剖病理生態物證，直接轉移至軍事危機
    int ev_strength = query_metric(EVENT_BEAST_SURGE, METRIC_EVIDENCE_STRENGTH);
    int last_propagated = query_fact(EVENT_MILITARY_CRISIS, "beast_evidence_propagated");
    if (ev_strength > last_propagated) {
        int diff = ev_strength - last_propagated;
        set_fact(EVENT_MILITARY_CRISIS, "beast_evidence_propagated", ev_strength);

        // 在物證帳本中登錄或更新生態病理物證
        register_evidence("ev_beast_ecology", ([
            "name": "地煞逃亡與異獸解剖病理卷宗",
            "strength": ev_strength,
            "source_type": "pathology_ecology",
            "verified": 1,
            "seen_by": ({ "commander", "inspector" })
        ]));

        // 實質提升軍事抗辯物證核驗度
        add_metric(EVENT_MILITARY_CRISIS, METRIC_EVIDENCE_VERIFIABILITY, diff);

        // 若生態物證強度累計達到 2 以上且之前未扣減情報信任度，直接動搖對平叛軍令的盲信
        if (ev_strength >= 2 && last_propagated < 2) {
            add_metric(EVENT_MILITARY_CRISIS, METRIC_INTEL_CONFIDENCE, -1);
        }

        broadcast_event(EVENT_MILITARY_CRISIS, "evidence_propagated", ([
            "evidence_strength": ev_strength,
            "broadcast_text": "【物證轉移】大荒煞潮生態病理卷宗已送達軍陣！異獸肺葉焦黑鐵證使先鋒主帥對平叛軍令產生動搖！"
        ]));
    }

    // 3. 兩條時間軸的耦合規則：
    // 當煞潮抵達 T+2 (第 31~32 章，局勢反噬・官道衝斷) 時，
    // 若軍事危機尚在 standby (待命蟄伏，第 19~32 章)，
    // 則自動觸發軍事時間軸前進至 arrival (先鋒扣關，第 33~34 章，三千精銳重弩抵達，後路斷絕)
    string beast_stage = query_event_stage(EVENT_BEAST_SURGE);
    string military_stage = query_event_stage(EVENT_MILITARY_CRISIS);
    if (beast_stage == STAGE_BEAST_T_PLUS_2 && military_stage == STAGE_MILITARY_STANDBY) {
        set_event_stage(EVENT_MILITARY_CRISIS, STAGE_MILITARY_ARRIVAL, 0);
        broadcast_event(EVENT_MILITARY_CRISIS, "crisis_triggered", ([
            "stage": STAGE_MILITARY_ARRIVAL,
            "broadcast_text": "【大軍壓境】大荒煞潮衝斷金石官道，三千府城先鋒鐵騎破霧扣關！黑石關軍事危機正式爆發！"
        ]));
    }
}

// ── T-Clock 單調推進與時間代價 ────────────────────────────────
string query_event_stage(string event_id) {
    if (!events || !events[event_id]) return "";
    return events[event_id]["stage"];
}

int query_stage_index(string event_id) {
    string cur = query_event_stage(event_id);
    string *stages = query_valid_stages(event_id);
    return member_array(cur, stages);
}

int set_event_stage(string event_id, string new_stage, int force) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    string *valid_stages = query_valid_stages(event_id);
    int new_idx = member_array(new_stage, valid_stages);
    if (new_idx == -1) return 0; // 不合法階段

    int cur_idx = query_stage_index(event_id);
    string old_stage = events[event_id]["stage"];
    if (old_stage == new_stage && force) return 1;

    // 單調性保護：非 force 模式下只允許嚴格向前推進 (new_idx > cur_idx)
    if (!force && new_idx <= cur_idx) {
        write_file("/log/event_error.log", sprintf("[TCLOCK_WARNING] 拒絕非單調推進：%s -> %s\n", old_stage, new_stage), 0);
        return 0;
    }

    events[event_id]["stage"] = new_stage;
    mapping st_def = query_stage_def(event_id, new_stage);

    // 觸發時間代價衰減 (Time Cost Impact)
    if (st_def["time_cost_impact"] && mapp(st_def["time_cost_impact"])) {
        foreach (string mk, int delta in st_def["time_cost_impact"]) {
            add_metric(event_id, mk, delta);
        }
    }

    // 當煞潮推進至 T0 主力過境或 T+2 官道衝斷交接時，顯式傳播下泄衝擊至軍事危機
    if (event_id == EVENT_BEAST_SURGE && (new_stage == STAGE_BEAST_T_0 || new_stage == STAGE_BEAST_T_PLUS_2)) {
        propagate_beast_to_military();
    }

    string desc = query_stage_desc(event_id, new_stage);
    log_event(event_id, "stage_advance", sprintf("時間軸推進：%s -> %s（%s）", old_stage, new_stage, desc));

    broadcast_event(event_id, "stage_advance", ([
        "old_stage": old_stage,
        "new_stage": new_stage,
        "broadcast_text": sprintf("天時轉移，世界局勢邁入新階段【%s】！\n%s", new_stage, desc)
    ]));

    save_state();
    return 1;
}

string advance_event_stage(string event_id) {
    string *valid_stages = query_valid_stages(event_id);
    int cur_idx = query_stage_index(event_id);
    if (cur_idx < 0) cur_idx = 0;
    if (cur_idx + 1 < sizeof(valid_stages)) {
        string next_stage = valid_stages[cur_idx + 1];
        set_event_stage(event_id, next_stage, 0);
        return next_stage;
    }
    return events[event_id]["stage"];
}

// ── 事務性與冪等結算 (Transactional & Idempotent Outcome) ──────
mapping apply_quest_outcome(string event_id, string quest_id, mapping outcome, string actor_id) {
    if (!events || !events[event_id]) init_event_defaults(event_id);
    if (!outcome || !mapp(outcome) || !quest_id || quest_id == "") return ([]);

    // 1. 冪等性檢驗 (Idempotency Key Check)
    string idemp_key = (actor_id && actor_id != "") ? (quest_id + "@" + actor_id) : quest_id;
    if (!events[event_id]["applied_outcomes"]) events[event_id]["applied_outcomes"] = ([]);

    if (events[event_id]["applied_outcomes"][idemp_key] && !outcome["repeatable"]) {
        // 重複提交，直接拒絕並返回歷史記錄，保護全域狀態不被重複刷分
        log_event(event_id, "idempotent_reject", sprintf("任務結算冪等拒絕：%s", idemp_key));
        return events[event_id]["applied_outcomes"][idemp_key];
    }

    // 2. 事務性預驗證 (Validation Phase)：檢查傳入的 deltas 是否全為已註冊指標
    mapping pending_deltas = ([]);

    if (outcome["deltas"] && mapp(outcome["deltas"])) {
        foreach (string mname, int delta in outcome["deltas"]) {
            if (!is_valid_metric(event_id, mname)) {
                write_file("/log/event_error.log", sprintf("[TX_ABORT] 任務 %s 傳入未註冊指標：%s\n", quest_id, mname), 0);
                return ([]); // 事務整筆中止，無任何 side effect
            }
            pending_deltas[mname] = delta;
        }
    }

    foreach (string k, mixed val in outcome) {
        if (intp(val) && strlen(k) > 6 && substr(k, strlen(k) - 6, 6) == "_delta") {
            string mname = substr(k, 0, strlen(k) - 6);
            if (!is_valid_metric(event_id, mname)) {
                write_file("/log/event_error.log", sprintf("[TX_ABORT] 任務 %s 傳入未註冊指標：%s\n", quest_id, mname), 0);
                return ([]);
            }
            pending_deltas[mname] = val;
        }
    }

    // 3. 執行階段 (Execution Phase)：一次性套用指標變更
    mapping applied_deltas = ([]);
    foreach (string mname, int delta in pending_deltas) {
        int cur = query_metric(event_id, mname);
        int clamped = clamp_metric(event_id, mname, cur + delta);
        events[event_id]["metrics"][mname] = clamped;
        applied_deltas[mname] = delta;
    }

    // 4. 處理物證登錄 (若有附帶)
    if (outcome["evidence"] && mapp(outcome["evidence"])) {
        mapping ev = outcome["evidence"];
        if (ev["id"]) {
            register_evidence(ev["id"], ev);
        }
    }

    // 5. 處理客觀事實更新 (若有附帶)
    if (outcome["facts"] && mapp(outcome["facts"])) {
        foreach (string fk, mixed fv in outcome["facts"]) {
            events[event_id]["facts"][fk] = fv;
        }
    }

    // 6. 紀錄任務結算成果 (冪等標籤)
    mapping q_record = ([
        "quest_id"       : quest_id,
        "actor_id"       : actor_id ? actor_id : "",
        "idemp_key"      : idemp_key,
        "status"         : outcome["status"] ? outcome["status"] : "success",
        "applied_deltas" : applied_deltas,
        "message"        : outcome["message"] ? outcome["message"] : "",
        "timestamp"      : time()
    ]);

    events[event_id]["applied_outcomes"][idemp_key] = q_record;

    // 7. 發布廣播與單次寫入磁碟 (Single Transaction Commit)
    broadcast_event(event_id, "quest_outcome", ([
        "quest_id"       : quest_id,
        "status"         : q_record["status"],
        "message"        : q_record["message"],
        "broadcast_text" : q_record["message"]
    ]));

    save_state();
    return q_record;
}

mapping query_applied_outcome(string event_id, string quest_id, string actor_id) {
    if (!events || !events[event_id] || !events[event_id]["applied_outcomes"]) return ([]);
    string idemp_key = (actor_id && actor_id != "") ? (quest_id + "@" + actor_id) : quest_id;
    return copy(events[event_id]["applied_outcomes"][idemp_key]);
}

mapping query_all_applied_outcomes(string event_id) {
    if (!events || !events[event_id] || !events[event_id]["applied_outcomes"]) return ([]);
    return copy(events[event_id]["applied_outcomes"]);
}

// ── 狀態儀表板診斷輸出 (純檢視，絕無 side effect) ─────────────
string dump_status(string event_id) {
    if (!events || !events[event_id]) return "【事件守護進程】查無指定事件狀態。\n";

    string out = "\n" + HIW + "========================================================\n" + NOR;
    out += sprintf(HIG + "  《遺忘的世界》世界事件監控儀表板：%s (Schema v%d)\n" + NOR, event_id, EVENT_MANAGER_VERSION);
    out += HIW + "========================================================\n" + NOR;

    out += sprintf(CYN + "【當前階段】" + NOR + "%s\n", query_stage_desc(event_id, events[event_id]["stage"]));
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
            out += sprintf("  * [%s] %s | 強度: %d | 來源: %s | 核驗: %d | 過目者: %s\n",
                ek,
                ev["name"] ? ev["name"] : "",
                ev["strength"],
                ev["source_type"] ? ev["source_type"] : "general",
                ev["verified"],
                implode(ev["seen_by"], ", ")
            );
        }
    }

    out += HIW + "--------------------------------------------------------\n" + NOR;
    if (event_id == EVENT_BEAST_SURGE) {
        mapping eval_b = evaluate_beast_surge();
        out += sprintf(HIY + "【煞潮即時衍生視圖（純只讀）】\n" + NOR);
        out += sprintf("  導流總評分：%d%% | 主力走向：%s (偏折 %d%%)\n", eval_b["diversion_score"], eval_b["main_herd_route"], eval_b["canyon_deflected_percent"]);
        out += sprintf("  預估官道破壞：%d | 聚落承載力：%d -> 殘餘 %d (%s)\n",
                       eval_b["canyon_road_destruction"], query_metric(EVENT_BEAST_SURGE, METRIC_SETTLEMENT_CAPACITY), eval_b["surviving_capacity"], eval_b["settlement_state"]);
    }
    if (event_id == EVENT_MILITARY_CRISIS) {
        mapping eval_m = evaluate_military_crisis();
        out += sprintf(HIY + "【軍事危機即時衍生視圖（純只讀）】\n" + NOR);
        out += sprintf("  收斂結局代碼：%s (%s)\n", eval_m["ending_code"], eval_m["ending_name"]);
        out += sprintf("  結局說明：%s\n", eval_m["description"]);
    }

    out += HIW + "========================================================\n" + NOR;
    return out;
}
