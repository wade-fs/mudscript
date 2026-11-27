// daemon/region_d.c
// 《遺忘的世界》(THE FORGOTTEN SPACE) 宏觀區域、場域與遺跡模擬守護進程 (Region Daemon)
// 正典依據：/world/lore/nine_cities_canon.md
// 空間架構：/world/specifications/spatial_schema.md (v1.1)
// 職責：
// 1. 管理單一 Region / Zone / Site 之定義與層級關聯
// 2. 實裝 Lazy Evaluation 時間戳差額補償演算法 (D_{n+1} = 0.9 D_n)
// 3. 實裝指數阻尼自然回歸 (Continuous) 與離散狀態轉移 (Discrete) 雙軌自癒模型
// 4. 管理本地資源庫存 (reserves)、市場價格 (price_index) 與勢力/危機牌組
// 5. 實裝分區動態持久化 (save_region / restore_region) 與重啟時間差補償

#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/region.h"

inherit "/std/object.c";

// 靜態定義池 (唯讀，不進存檔)
nosave mapping region_defs;
nosave mapping zone_defs;
nosave mapping site_defs;

// 動態區域狀態表：region_id -> mapping
// 包含: reserves, price_index, last_eval_time, factions, active_crises
mapping region_states;

// 測試模式旗標 (若為 1，save_region 不寫入磁碟)
nosave int test_mode;

void load_regions();
void load_zones();
void load_sites();
int save_region(string region_id);
int restore_region(string region_id);
int restore_all_regions();
int get_current_gtime();
mapping evaluate_region(string region_id, int current_gtime);

void set_test_mode(int m) { test_mode = m; }
int query_test_mode() { return test_mode; }

string query_save_file(string rid) {
    return DATA_REGIONS_DIR + rid + ".json";
}

void create() {
    ::create();
    region_defs = ([]);
    zone_defs = ([]);
    site_defs = ([]);
    region_states = ([]);

    load_regions();
    load_zones();
    load_sites();

    restore_all_regions();

    // 伺服器重啟或載入後，對各區域進行時間差補算
    int now_gt = get_current_gtime();
    foreach (string rid, mapping st in region_states) {
        if (st && st["last_eval_time"] > 0 && now_gt > st["last_eval_time"]) {
            evaluate_region(rid, now_gt);
        }
    }
}

// 取得當前世界遊戲時間 (分鐘)
int get_current_gtime() {
    object nature = find_object("/secure/nature_d.c");
    if (!nature) nature = load_object("/secure/nature_d.c");
    if (nature) {
        return nature->query_game_time();
    }
    return time();
}

// 載入靜態區域設定
void load_regions() {
    string *files = get_dir(WORLD_REGIONS_DIR + "*.json");
    if (!files || !sizeof(files)) {
        files = ({
            "jinshi.json",
            "zhongshi.json",
            "heishipu.json",
            "qinghe.json",
            "liefan.json",
            "zhenfeng.json",
            "panmu.json",
            "tuogu.json",
            "zhuoshui.json",
            "yunjin.json",
            "taiqing.json",
            "bahuang.json",
            "tiangong.json",
            "danding.json",
            "wastes.json",
            "realm_edge.json",
            "realm_taixu.json",
            "realm_wanwu.json",
            "realm_zhanzu.json"
        });
    }

    foreach (string f in files) {
        string path = WORLD_REGIONS_DIR + f;
        string content = read_file(path);
        if (content && content != "") {
            mixed def = json_decode(content);
            if (mapp(def) && (def["region_id"] || def["id"])) {
                string rid = def["region_id"] ? def["region_id"] : def["id"];
                region_defs[rid] = def;

                if (!region_states[rid]) {
                    // 初始化動態狀態
                    mapping r_init = ([
                        "price_index": mapp(def["resources"]) && def["resources"]["price_index"] ? def["resources"]["price_index"] : PRICE_INDEX_BASE,
                        "reserves": mapp(def["resources"]) && mapp(def["resources"]["reserves"]) ? copy(def["resources"]["reserves"]) : ([]),
                        "factions": mapp(def["factions"]) ? copy(def["factions"]) : ([]),
                        "active_crises": ([]),
                        "last_eval_time": get_current_gtime()
                    ]);
                    region_states[rid] = r_init;
                }
            }
        }
    }
}

// 載入靜態場域 (Zone) 設定
void load_zones() {
    string *files = get_dir(WORLD_ZONES_DIR + "*.json");
    if (!files || !sizeof(files)) return;

    foreach (string f in files) {
        string path = WORLD_ZONES_DIR + f;
        string content = read_file(path);
        if (content && content != "") {
            mixed def = json_decode(content);
            if (mapp(def) && def["zone_id"]) {
                zone_defs[def["zone_id"]] = def;
            }
        }
    }
}

// 載入靜態遺跡與設施 (Site) 設定
void load_sites() {
    string *files = get_dir(WORLD_SITES_DIR + "*.json");
    if (!files || !sizeof(files)) return;

    foreach (string f in files) {
        string path = WORLD_SITES_DIR + f;
        string content = read_file(path);
        if (content && content != "") {
            mixed def = json_decode(content);
            if (mapp(def) && def["site_id"]) {
                site_defs[def["site_id"]] = def;
            }
        }
    }
}

// 惰性求值演算法 (Lazy Evaluation Engine)
// 依時間戳差額結算連續指數阻尼回歸 (D_{n+1} = 0.9 * D_n)，離散狀態保持不變
mapping evaluate_region(string region_id, int current_gtime) {
    if (!region_states || !mapp(region_states[region_id])) {
        if (region_defs && mapp(region_defs[region_id])) {
            load_regions();
        } else {
            return 0;
        }
    }

    mapping state = region_states[region_id];
    int last_time = state["last_eval_time"];
    if (last_time <= 0) {
        state["last_eval_time"] = current_gtime;
        return state;
    }

    int delta_t = current_gtime - last_time;
    if (delta_t <= 0) {
        return state; // 無時間差，直接回傳
    }

    // ── 1. 連續數值：指數阻尼自然回歸 (D_{n+1} = 0.9 * D_n) ──
    int cur_price = state["price_index"];
    int diff = cur_price - PRICE_INDEX_BASE;
    if (diff != 0) {
        int steps = delta_t / 60; // 每 60 遊戲分鐘為一個步進衰減週期
        if (steps > 50) steps = 50; // 防禦邊界

        for (int i = 0; i < steps && diff != 0; i++) {
            diff = (diff * 9) / 10;
        }
        if (abs(diff) <= 1) diff = 0;

        int new_price = PRICE_INDEX_BASE + diff;
        if (new_price < PRICE_INDEX_MIN) new_price = PRICE_INDEX_MIN;
        if (new_price > PRICE_INDEX_MAX) new_price = PRICE_INDEX_MAX;
        state["price_index"] = new_price;
    }

    // ── 2. 離散物理災情：狀態轉移模型 (State Transition Model) ──
    // 崩塌、阻斷、故障危機絕不隨時間自癒，保持原樣直至具體行動修復

    state["last_eval_time"] = current_gtime;
    return state;
}

// 查詢區域定義
mapping query_region_def(string region_id) {
    if (!region_defs || !mapp(region_defs[region_id])) return 0;
    return copy(region_defs[region_id]);
}

// 查詢所有已註冊區域
mapping query_all_regions() {
    return copy(region_defs);
}

// 查詢單一 Zone 定義
mapping query_zone(string zone_id) {
    if (!zone_defs || !mapp(zone_defs[zone_id])) return 0;
    return copy(zone_defs[zone_id]);
}

// 查詢所有 Zone 定義
mapping query_all_zones() {
    return copy(zone_defs);
}

// 查詢單一 Site 定義
mapping query_site(string site_id) {
    if (!site_defs || !mapp(site_defs[site_id])) return 0;
    return copy(site_defs[site_id]);
}

// 查詢所有 Site 定義
mapping query_all_sites() {
    return copy(site_defs);
}

// 查詢特定區域所屬之所有 Zone IDs
string *query_zones_by_region(string region_id) {
    string *res = ({});
    if (!zone_defs) return res;

    foreach (string zid, mapping zdata in zone_defs) {
        if (zdata["region_id"] == region_id) {
            res += ({ zid });
        }
    }
    return res;
}

// 查詢特定 Zone 所屬之所有 Site IDs
string *query_sites_by_zone(string zone_id) {
    string *res = ({});
    if (!site_defs) return res;

    foreach (string sid, mapping sdata in site_defs) {
        if (sdata["zone_id"] == zone_id) {
            res += ({ sid });
        }
    }
    return res;
}

// 查詢區域即時動態狀態
mapping query_region_state(string region_id) {
    int now_gt = get_current_gtime();
    return evaluate_region(region_id, now_gt);
}

// 查詢區域價格指數
int query_region_price_index(string region_id) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state) return PRICE_INDEX_BASE;
    return state["price_index"];
}

// 調整區域價格指數
int adjust_region_price(string region_id, int delta_pct) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state) return PRICE_INDEX_BASE;

    int new_p = state["price_index"] + delta_pct;
    if (new_p < PRICE_INDEX_MIN) new_p = PRICE_INDEX_MIN;
    if (new_p > PRICE_INDEX_MAX) new_p = PRICE_INDEX_MAX;
    state["price_index"] = new_p;
    if (!test_mode && !getenv("MUD_TEST_MODE")) save_region(region_id);
    return new_p;
}

// 查詢特定資源儲量
int query_region_reserves(string region_id, string resource_id) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state || !mapp(state["reserves"])) return 0;
    return state["reserves"][resource_id] ? state["reserves"][resource_id] : 0;
}

// 調整特定資源儲量
int adjust_region_reserves(string region_id, string resource_id, int delta) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state) return 0;

    if (!mapp(state["reserves"])) state["reserves"] = ([]);
    int cur = state["reserves"][resource_id] ? state["reserves"][resource_id] : 0;
    int after = cur + delta;
    if (after < 0) after = 0;
    state["reserves"][resource_id] = after;
    if (!test_mode && !getenv("MUD_TEST_MODE")) save_region(region_id);
    return after;
}

// 查詢特定危機狀態
mapping query_region_crisis(string region_id, string crisis_id) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state || !mapp(state["active_crises"])) return 0;
    return state["active_crises"][crisis_id];
}

// 觸發或設定區域危機 (離散狀態轉移)
int set_region_crisis(string region_id, string crisis_id, int active, mapping details) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state) return 0;

    if (!mapp(state["active_crises"])) state["active_crises"] = ([]);

    if (active) {
        mapping d = mapp(details) ? copy(details) : ([]);
        d["triggered_at"] = now_gt;
        state["active_crises"][crisis_id] = d;
    } else {
        map_delete(state["active_crises"], crisis_id);
    }
    if (!test_mode && !getenv("MUD_TEST_MODE")) save_region(region_id);
    return 1;
}

// 解決區域危機 (玩家行動或工程干預引發之狀態轉移)
int resolve_region_crisis(string region_id, string crisis_id, string action_taken) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state || !mapp(state["active_crises"])) return 0;

    if (!state["active_crises"][crisis_id]) return 0;

    map_delete(state["active_crises"], crisis_id);

    // 危機解除後，價格指數立即消除額外惡性溢價
    if (state["price_index"] > PRICE_INDEX_BASE) {
        state["price_index"] = PRICE_INDEX_BASE + (state["price_index"] - PRICE_INDEX_BASE) / 2;
    }
    if (!test_mode && !getenv("MUD_TEST_MODE")) save_region(region_id);
    return 1;
}

// 查詢區域勢力影響力 (0 ~ 100)
int query_faction_power(string region_id, string faction_id) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state || !mapp(state["factions"]) || !mapp(state["factions"][faction_id])) return 0;
    return state["factions"][faction_id]["power"];
}

// 調整區域勢力影響力 (0 ~ 100 鉗制)
int adjust_faction_power(string region_id, string faction_id, int delta) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state) return 0;

    if (!mapp(state["factions"])) state["factions"] = ([]);
    if (!mapp(state["factions"][faction_id])) {
        state["factions"][faction_id] = ([ "power": 0, "agenda": "emergent" ]);
    }
    int cur = state["factions"][faction_id]["power"];
    int after = cur + delta;
    if (after < 0) after = 0;
    if (after > 100) after = 100;
    state["factions"][faction_id]["power"] = after;
    if (!test_mode && !getenv("MUD_TEST_MODE")) save_region(region_id);
    return after;
}

// 查詢區域靜態危機牌組定義 (唯讀副本)
mixed *query_crisis_deck(string region_id) {
    if (!region_defs || !mapp(region_defs[region_id])) return ({});
    mixed deck = region_defs[region_id]["crisis_deck"];
    if (!pointerp(deck)) return ({});
    return copy(deck);
}

// 查詢區域當前所有活躍危機
mapping query_active_crises(string region_id) {
    int now_gt = get_current_gtime();
    mapping state = evaluate_region(region_id, now_gt);
    if (!state || !mapp(state["active_crises"])) return ([]);
    return copy(state["active_crises"]);
}

// 依危機牌組 (crisis_deck) 抽取並觸發對應危機卡
// 優先比對 trigger_metric 尚未生效的最高權重卡；若指定空字串則取最高權重未啟用卡
string trigger_crisis_from_deck(string region_id, string trigger_metric, mapping details) {
    mixed *deck = query_crisis_deck(region_id);
    if (!sizeof(deck)) return "";

    mapping active = query_active_crises(region_id);
    string best_id = "";
    int best_weight = -1;

    foreach (mixed card in deck) {
        if (!mapp(card) || !card["id"]) continue;
        string cid = card["id"];
        if (mapp(active[cid])) continue;
        if (trigger_metric && trigger_metric != "" && card["trigger_metric"] != trigger_metric) continue;
        int w = card["base_weight"] ? card["base_weight"] : 10;
        if (w > best_weight) {
            best_weight = w;
            best_id = cid;
        }
    }

    if (best_id == "" && trigger_metric && trigger_metric != "") {
        foreach (mixed card in deck) {
            if (!mapp(card) || !card["id"]) continue;
            string cid = card["id"];
            if (mapp(active[cid])) continue;
            int w = card["base_weight"] ? card["base_weight"] : 10;
            if (w > best_weight) {
                best_weight = w;
                best_id = cid;
            }
        }
    }

    if (best_id == "") return "";

    mapping d = mapp(details) ? copy(details) : ([]);
    d["source_deck"] = region_id;
    if (trigger_metric && trigger_metric != "") d["trigger_metric"] = trigger_metric;
    if (!set_region_crisis(region_id, best_id, 1, d)) return "";

    if (d["price_shock"]) {
        adjust_region_price(region_id, d["price_shock"]);
    }
    return best_id;
}

// 保存個別區域動態持久化狀態
int save_region(string region_id) {
    if (!region_states || !mapp(region_states[region_id])) return 0;

    string file = query_save_file(region_id);
    string payload = json_encode(region_states[region_id]);
    return write_file(file, payload, 1);
}

// 恢復個別區域動態持久化狀態
int restore_region(string region_id) {
    string file = query_save_file(region_id);
    if (file_size(file) <= 0) return 0;

    string content = read_file(file);
    if (!content || content == "") return 0;

    mixed data = json_decode(content);
    if (!mapp(data)) return 0;

    if (!region_states) region_states = ([]);
    region_states[region_id] = data;
    return 1;
}

// 刪除個別區域動態持久化狀態存檔 (供重置與測試清理)
int remove_save_file(string region_id) {
    string file = query_save_file(region_id);
    if (file_size(file) >= 0) {
        return rm(file);
    }
    return 1;
}

// 保存全部區域
int save_all_regions() {
    int cnt = 0;
    foreach (string rid, mapping st in region_states) {
        if (save_region(rid)) cnt++;
    }
    return cnt;
}

// 恢復全部區域
int restore_all_regions() {
    int cnt = 0;
    string *files = get_dir(DATA_REGIONS_DIR + "*.json");
    if (!files || !sizeof(files)) return 0;

    foreach (string f in files) {
        int dot = strsrch(f, ".json");
        if (dot != -1) {
            string rid = substr(f, 0, dot);
            if (restore_region(rid)) cnt++;
        }
    }
    return cnt;
}

// 重設所有區域 (供測試隔離)
void reset_regions() {
    region_states = ([]);
    load_regions();
    load_zones();
    load_sites();
}
