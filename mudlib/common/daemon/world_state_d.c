// daemon/world_state_d.c - 通用世界狀態守護進程 (World-Agnostic)
// 維護世界動態變數、危機牌組與事件匯流排
// 移除特定小說硬編碼，改以 JSON 設定注入

#include "/include/config.h"

inherit "/std/object.c";

mapping world_vars;     // 通用世界變數 (key -> value)
mapping event_bus;      // 事件匯流排 (event_id -> mapping)
mapping crisis_deck;    // 危機牌組 (crisis_id -> mapping)
int     world_time;     // 世界時間（秒）

nosave mapping event_listeners;  // event_id -> callback array (不存檔)

string query_save_file() { return "/data/world_state_d"; }

void create() {
    ::create();
    world_vars      = ([]);
    event_bus       = ([]);
    crisis_deck     = ([]);
    event_listeners = ([]);
    world_time      = 0;

    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
    if (!event_listeners) event_listeners = ([]);

    // 從 manifest.json 或世界設定檔讀取初始狀態
    load_world_config();
}

void load_world_config() {
    if (file_size("/schema/world_state.json") <= 0) return;
    string raw = read_file("/schema/world_state.json");
    if (!raw || raw == "") return;
    mixed data = json_decode(raw);
    if (!mapp(data)) return;

    // 設定初始世界變數（僅在未有存檔時）
    if (data["initial_vars"] && mapp(data["initial_vars"])) {
        mapping iv = data["initial_vars"];
        string *keys_iv = keys(iv);
        for (int i = 0; i < sizeof(keys_iv); i++) {
            string k = keys_iv[i];
            if (undefinedp(world_vars[k])) {
                world_vars[k] = iv[k];
            }
        }
    }
}

// ── 世界變數 ─────────────────────────────────────────────
mixed query_var(string key)             { return world_vars ? world_vars[key] : 0; }
void  set_var(string key, mixed val)    { if (!world_vars) world_vars = ([]); world_vars[key] = val; }
void  add_var(string key, int amount)   {
    int cur = world_vars && world_vars[key] ? world_vars[key] : 0;
    world_vars[key] = cur + amount;
}
mapping query_all_vars()                { return world_vars; }

// ── 事件匯流排 ───────────────────────────────────────────
void fire_event(string event_id, mapping data) {
    if (!event_id) return;
    if (!event_bus) event_bus = ([]);
    event_bus[event_id] = ([
        "id":        event_id,
        "data":      data,
        "timestamp": time()
    ]);

    // 通知所有監聽者
    if (event_listeners && event_listeners[event_id]) {
        mixed *listeners = event_listeners[event_id];
        for (int i = 0; i < sizeof(listeners); i++) {
            mixed cb = listeners[i];
            if (objectp(cb)) {
                cb->on_world_event(event_id, data);
            }
        }
    }
}

mapping query_event(string event_id)    { return event_bus ? event_bus[event_id] : 0; }
int query_event_active(string event_id) {
    mapping e = query_event(event_id);
    return e ? 1 : 0;
}

void register_listener(string event_id, object listener) {
    if (!event_listeners) event_listeners = ([]);
    if (!event_listeners[event_id]) event_listeners[event_id] = ({});
    event_listeners[event_id] += ({ listener });
}

// ── 危機牌組 ─────────────────────────────────────────────
void register_crisis(string crisis_id, mapping def) {
    if (!crisis_deck) crisis_deck = ([]);
    crisis_deck[crisis_id] = def;
}

mapping query_crisis(string crisis_id)  { return crisis_deck ? crisis_deck[crisis_id] : 0; }

int activate_crisis(string crisis_id, int active) {
    mapping c = query_crisis(crisis_id);
    if (!c) return 0;
    c["active"] = active;
    crisis_deck[crisis_id] = c;
    if (active) fire_event("crisis_" + crisis_id, c);
    return 1;
}

// ── 世界時間 ─────────────────────────────────────────────
int  query_world_time()     { return world_time; }
void advance_time(int secs) { world_time += secs; }

// ── 存檔 ─────────────────────────────────────────────────
void do_save() { save_object(query_save_file()); }
