// daemon/route_d.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 跨區道路交通與雙軌因果傳播守護進程 (Route Daemon)
// 職責：
// 1. 管理道路路網拓撲、交通時間、關卡路引檢驗、貨流容量、通阻狀態
// 2. 嚴格分離「實體交通物流 (transport)」與「因果資訊傳播 (propagation)」
// 3. 載入 /world/routes/*.json 靜態定義，動態維護通阻與氣候事件波及

#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/region.h"

inherit "/std/object.c";

// 靜態路由定義池 (nosave: 唯讀定義，不寫入存檔)
nosave mapping routes_def;

// 動態道路狀態：route_id -> ([ "blocked": 0/1, "reason": "...", "traffic_load": int, "modifier": int ])
mapping route_states;

void load_routes();
string query_save_file() { return "/data/routes/route_state"; }

void create() {
    ::create();
    routes_def = ([]);
    route_states = ([]);

    load_routes();

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    if (!route_states || !mapp(route_states)) {
        route_states = ([]);
    }
}

// 載入靜態路線定義
void load_routes() {
    string *files = get_dir(WORLD_ROUTES_DIR + "*.json");
    if (!files || !sizeof(files)) {
        // 保底清單
        files = ({
            "zhongshi_to_jinshi.json",
            "heishipu_to_jinshi.json",
            "qinghe_to_jinshi.json",
            "liefan_to_jinshi.json",
            "zhenfeng_to_jinshi.json",
            "panmu_to_jinshi.json"
        });
    }

    foreach (string f in files) {
        string path = WORLD_ROUTES_DIR + f;
        string content = read_file(path);
        if (content && content != "") {
            mixed def = json_decode(content);
            if (mapp(def) && def["route_id"]) {
                routes_def[def["route_id"]] = def;
            }
        }
    }
}

// 查詢單一路線完整定義
mapping query_route(string route_id) {
    if (!routes_def || !mapp(routes_def[route_id])) return 0;
    mapping base = copy(routes_def[route_id]);
    if (route_states && mapp(route_states[route_id])) {
        base["dynamic_state"] = copy(route_states[route_id]);
    }
    return base;
}

// 查詢所有路線定義
mapping query_all_routes() {
    return copy(routes_def);
}

// 查詢道路是否受阻
int is_route_blocked(string route_id) {
    if (!route_states || !mapp(route_states[route_id])) return 0;
    return route_states[route_id]["blocked"] ? 1 : 0;
}

// 查詢受阻原因
string query_route_block_reason(string route_id) {
    if (!is_route_blocked(route_id)) return "";
    return route_states[route_id]["reason"] ? route_states[route_id]["reason"] : "道路中斷受阻";
}

// 設定道路通阻狀態 (離散狀態轉移)
int set_route_blocked(string route_id, int blocked, string reason) {
    if (!routes_def || !mapp(routes_def[route_id])) return 0;

    if (!route_states) route_states = ([]);
    if (!mapp(route_states[route_id])) {
        route_states[route_id] = ([ "blocked": 0, "reason": "", "traffic_load": 0, "modifier": 0 ]);
    }

    route_states[route_id]["blocked"] = blocked ? 1 : 0;
    route_states[route_id]["reason"] = reason ? reason : (blocked ? "封關阻滯" : "通行正常");

    if (!getenv("MUD_TEST_MODE")) {
        save_object(query_save_file());
    }
    return 1;
}

// 查詢實體行旅耗時 (分鐘)
int query_travel_time(string route_id, string mode) {
    if (!routes_def || !mapp(routes_def[route_id])) return -1;
    if (is_route_blocked(route_id)) return -1; // 封閉無法通行

    mapping t_data = routes_def[route_id]["transport"];
    if (!mapp(t_data)) return -1;

    int base_time = t_data["travel_time_minutes"];
    if (base_time <= 0) base_time = 120;

    // 依出行模式調製時間
    if (mode == "horse" || mode == "mount") {
        base_time = (base_time * 6) / 10; // 坐騎快 40%
    } else if (mode == "heavy_wagon" || mode == "freight") {
        base_time = (base_time * 13) / 10; // 大料輜重車慢 30%
    }

    // 動態阻滯加成
    if (route_states && mapp(route_states[route_id])) {
        base_time += route_states[route_id]["modifier"];
    }

    return base_time;
}

// 查詢資訊因果傳播延遲 (分鐘)
int query_information_delay(string route_id) {
    if (!routes_def || !mapp(routes_def[route_id])) return 60;

    mapping p_data = routes_def[route_id]["propagation"];
    if (!mapp(p_data)) return 60;

    int delay = p_data["information_delay_minutes"];
    return (delay > 0) ? delay : 60;
}

// 查詢大宗貨物衝擊延遲 (分鐘)
int query_freight_delay(string route_id) {
    if (!routes_def || !mapp(routes_def[route_id])) return 180;

    mapping p_data = routes_def[route_id]["propagation"];
    if (!mapp(p_data)) return 180;

    int delay = p_data["freight_impact_delay_minutes"];
    return (delay > 0) ? delay : 180;
}

// 查詢因果權重衰減百分比 (85 代表 0.85)
int query_attenuation_pct(string route_id) {
    if (!routes_def || !mapp(routes_def[route_id])) return 80;

    mapping p_data = routes_def[route_id]["propagation"];
    if (!mapp(p_data)) return 80;

    mixed att = p_data["weight_attenuation"];
    if (intp(att)) {
        if (att <= 1) return att * 100;
        return att;
    }
    // 預設 85%
    return 85;
}

// 查詢從指定區域出發之所有路線
string *query_routes_from(string region_id) {
    string *res = ({});
    if (!routes_def) return res;

    foreach (string rid, mapping rdata in routes_def) {
        if (rdata["from"] == region_id) {
            res += ({ rid });
        }
    }
    return res;
}

// 查詢通往指定區域之所有路線
string *query_routes_to(string region_id) {
    string *res = ({});
    if (!routes_def) return res;

    foreach (string rid, mapping rdata in routes_def) {
        if (rdata["to"] == region_id) {
            res += ({ rid });
        }
    }
    return res;
}

// 重設道路狀態 (供測試隔離)
void reset_routes() {
    route_states = ([]);
    load_routes();
}
