// /std/room.c
#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

mapping exits = ([]);
mapping hidden_elements = ([]);

void create() {
    ::create();
    seteuid(getuid());
}

// ── 屬性設定 ─────────────────────────────────────────────
void set_short(mixed s) { set("short", s); }
void set_long(mixed s)  { set("long", s); }
void add_exit(string dir, string path) { exits[dir] = path; }
mapping query_exits() { return exits; }

void set_hidden(string key, mixed val) { hidden_elements[key] = val; }

// ── 房間介面 ─────────────────────────────────────────────

void look_room(object who) {
    if (!who) who = this_player();
    
    string output = "";
    output += sprintf("\n【%s】\n\n", query("short") || "未知地點");
    output += sprintf("%s\n\n", query("long") || "這裡什麼都沒有。");

    // 顯示出口
    string *dirs = keys(exits);
    if (sizeof(dirs) > 0) {
        output += "出口：";
        for (int i = 0; i < sizeof(dirs); i++) {
            output += sprintf("[%s]  ", dirs[i]);
        }
        output += "\n";
    } else {
        output += "這裡沒有明顯的出口。\n";
    }

    // 顯示物品
    object *inv = all_inventory(this_object());
    string items = "";
    foreach (object ob in inv) {
        if (ob == who) continue;
        if (userp(ob)) continue; // 玩家分開顯示
        items += sprintf("  [%s|look %s]\n", ob->short(), ob->get_id() || "object");
    }
    if (items != "") {
        output += "\n物品：\n" + items;
    }

    // 顯示人物
    string chars = "";
    foreach (object ob in inv) {
        if (ob == who) continue;
        if (userp(ob)) {
            chars += sprintf("  [%s(%s)|look %s]\n", ob->query_name(), ob->get_id(), ob->get_id());
        }
    }
    if (chars != "") {
        output += "\n這裡有：\n" + chars;
    }

    write(output + "\n");

    // 🚀 新增：發送小地圖資訊給 UI (JSON 格式)
    mapping map_data = ([
        "center_name": query("short"),
        "exits": dirs,
        "grid": ([]) // 預留擴充
    ]);
    
    // 呼叫 map_d 取得周邊地圖資訊
    object map_d = find_object("/secure/map_d.c");
    if (map_d) {
        mapping nearby = map_d->query_nearby_map(this_object());
        if (nearby) {
            map_data["grid"] = nearby["grid"];
            map_data["connections"] = nearby["connections"];
        }
    }
    
    write(sprintf("{\"ui\": \"minimap\", \"data\": %s}", json_encode(map_data)));

    // 🚀 新增：發送環境資訊
    object nature_d = find_object("/secure/nature_d.c");
    if (nature_d) {
        mapping nature_data = ([
            "hour": nature_d->query_hour(),
            "is_day": nature_d->query_is_day(),
            "weather": nature_d->query_weather(),
            "season": nature_d->query_season()
        ]);
        write(sprintf("{\"ui\": \"nature\", \"data\": %s}", json_encode(nature_data)));
    }
}

void init() {
    ::init();
    mixed dirs = keys(exits);
    int i;
    for (i = 0; i < sizeof(dirs); i++) {
        add_action("do_go", dirs[i]);
    }
    add_action("do_go", "go");

    add_action("do_search", "search");
    add_action("do_search", "搜尋");

    // 🚀 新增：地圖探索紀錄
    object tp = this_player();
    if (tp && userp(tp)) {
        tp->record_exploration(object_name(this_object()));
    }

    // 🚀 新增：如果是創界，通知前端
    if (query_is_lm_world()) {
        // 由 world.c 負責發送 mc_map
    }
}

// ── 輔助功能：反向方位 ──────────────────────────────────────
string query_reverse_dir(string dir) {
    switch(dir) {
        case "north": return "南方";
        case "south": return "北方";
        case "east":  return "西方";
        case "west":  return "東方";
        case "up":    return "下方";
        case "down":  return "上方";
        case "out":   return "裡面";
        case "in":    return "外面";
        default:      return "附近";
    }
}

// ── 核心動作：移動 ──────────────────────────────────────────
int do_go(string dir) {
    mixed cmd = dir;
    if (!cmd || cmd == "") {
        cmd = query_verb();
    }

    if (!exits[cmd]) {
        write(_t("no_exit_err") + "\n");
        return 1;
    }

    string dest_path = exits[cmd];
    object dest;
    
    dest = load_object(dest_path);
    
    if (!dest) {
        write(_t("dest_missing_err") + "\n");
        return 1;
    }

    object me = this_player();
    object lang_d = load_object("/secure/language_d.c");

    // 🚀 核心優化：移動前紀錄當前位置，方便目標房間查詢來源
    me->set_temp("last_location", base_name(this_object()));

    // 廣播離開訊息 (給原本房間的人)
    lang_d->broadcast_event(this_object(), "say_leave", ([ "$name": me, "$dir": cmd ]));

    if (me->move(dest, cmd)) {
        // 廣播抵達訊息 (給新房間的人)
        string from_dir = query_reverse_dir(cmd);
        lang_d->broadcast_event(dest, "say_arrive", ([ "$name": me, "$dir": from_dir ]));
        dest->look_room(me);
    } else {
        string fail_msg = _t("move_fail_err");
        fail_msg = replace_string(fail_msg, "$dir", cmd);
        write(fail_msg + "\n");
    }
    return 1;
}

// ── 互動：搜尋 ──────────────────────────────────────────
int do_search(string arg) {
    write("你開始在房間裡四處搜尋...\n");
    say(this_player()->query_name() + " 開始在房間裡四處搜尋。\n");

    if (!hidden_elements || sizeof(hidden_elements) == 0) {
        write("但是你什麼都沒有發現。\n");
        return 1;
    }

    // TODO: 實作隱藏物品發現邏輯
    write("但是你什麼都沒有發現。\n");
    return 1;
}

int query_is_lm_world() { return query("is_lm_world"); }

// 🚀 新增：垃圾回收機制 (Garbage Collection)
// 當房間內沒有人且不是本機藍圖房間時，一段時間後自動銷毀
int clean_up(int inherited_count) {
    if (inherited_count > 0) return 1;

    // 1. 如果房間內有玩家，絕對不清理
    object *inv = all_inventory(this_object());
    foreach (object ob in inv) {
        if (userp(ob)) return 1;
    }

    // 2. 如果是本機的藍圖房間，不清理 (保持世界連貫性)
    string oname = object_name(this_object());
    if (strsrch(oname, "#") == -1 && strsrch(oname, FS_CACHE_DIR) != 0) return 1;

    // 3. 閒置超過 20 分鐘 (1200秒) 則回收 (包含異世界緩存房間)
    if (query_idle(this_object()) > 1200) {
        destruct(this_object());
        return 0;
    }

    return 1;
}
