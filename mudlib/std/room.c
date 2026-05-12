// std/room.c - 所有房間的基底類別

#include "/include/config.h"

string  short_desc;    // 房間標題
string  long_desc;     // 房間描述
mapping exits;         // 出口表：([ "north": "/area/..." ])
mixed   item_ids;      // 房間內可互動的裝飾物描述表

// 🚀 新增空間座標 (注意：配合 Go 解析器限制，逐行宣告)
int x;
int y;
int z;

void create() {
    short_desc = "未命名的空房間";
    long_desc  = "這裡什麼都沒有，只有無盡的虛空。\n";
    exits      = ([]);
    item_ids   = ([]);
    x = 0;
    y = 0;
    z = 0;
}

// ── 座標設定與查詢 ───────────────────────────────────────
void set_coordinate(int cx, int cy, int cz) {
    x = cx;
    y = cy;
    z = cz;
}

mixed query_coordinate() {
    return ({ x, y, z });
}

// ── 設定函式 ────────────────────────────────────────────
void set_short(string s) { short_desc = s; }
void set_long(string s)  { long_desc  = s; }

void add_exit(string dir, string path) {
    exits[dir] = path;
}

void add_item(string id, string desc) {
    item_ids[id] = desc;
}

// ── 查詢函式 ────────────────────────────────────────────
string query_short() { return short_desc; }
string query_long()  { return long_desc; }
mapping query_exits(){ return exits; }

// ── 顯示房間 ────────────────────────────────────────────
void look_room() {
    write("【" + short_desc + "】\n");
    write(long_desc + "\n");

    mixed exit_dirs = keys(exits);
    if (exit_dirs) {
        // 將出口用 [ ] 包起來，讓前端可以轉化為可點擊的連結
        string *formatted_exits = ({});
        for (int i = 0; i < sizeof(exit_dirs); i++) {
            formatted_exits += ({ "[" + exit_dirs[i] + "]" });
        }
        write("出口：" + implode(formatted_exits, "  ") + "\n");
    } else {
        write("出口：（無）\n");
    }

    mixed here_inv = all_inventory(this_object());
    mixed items_in_room = ({});
    mixed livings_in_room = ({});

    int i;
    for (i = 0; i < sizeof(here_inv); i++) {
        object ob = here_inv[i];
        if (living(ob)) {
            livings_in_room = livings_in_room + ({ ob });
        } else {
            items_in_room = items_in_room + ({ ob });
        }
    }

    if (sizeof(items_in_room) > 0) {
        write("物品：");
        int j;
        for (j = 0; j < sizeof(items_in_room); j++) {
            object item = items_in_room[j];
            string item_id = item->query_key_id();
            mixed ids = item->query_id();
            if (arrayp(ids) && sizeof(ids) > 0) item_id = ids[0];
            else if (stringp(ids)) item_id = ids;
            
            write("[" + item->query_display_name() + "|look " + item_id + "]");
            if (j < sizeof(items_in_room) - 1) { write("、"); }
        }
        write("\n");
    }

    if (sizeof(livings_in_room) > 0) {
        write("這裡有：");
        int k;
        for (k = 0; k < sizeof(livings_in_room); k++) {
            object liv = livings_in_room[k];
            if (liv == this_player()) continue; // 不看自己
            
            string liv_id = "living";
            if (userp(liv)) {
                liv_id = liv->get_id() || liv->query_key_id();
            } else {
                liv_id = liv->query_key_id();
            }
            
            write("[" + liv->query_display_name() + "|look " + liv_id + "]");
            if (k < sizeof(livings_in_room) - 1) { write("、"); }
        }
        write("\n");
    }

    // 🚀 新增：發送小地圖的 JSON 資料給前端
    mapping map_data = ([
        "center_name": short_desc,
        "exits": keys(exits)
    ]);
    write(sprintf("{\"ui\": \"minimap\", \"data\": %s}", json_encode(map_data)));
}

// ── 移動指令 ────────────────────────────────────────────
void init() {
    mixed dirs = keys(exits);
    int i;
    for (i = 0; i < sizeof(dirs); i++) {
        add_action("do_go", dirs[i]);
    }
    add_action("do_go", "go");
}

int do_go(string dir) {
    mixed cmd = dir;
    if (!cmd || cmd == "") {
        cmd = query_verb();
    }

    if (!exits[cmd]) {
        write("那個方向沒有出路。\n");
        return 1;
    }

    string dest_path = exits[cmd];
    object dest = load_object(dest_path);
    if (!dest) {
        write("目的地不存在。\n");
        return 1;
    }

    object me = this_player();
    string my_name = me->query_name();

    say(my_name + " 往 " + cmd + " 方向離開了。\n");
    me->move_object(dest);
    say(my_name + " 從 " + cmd + " 方向來到了這裡。\n");
    dest->look_room();
    return 1;
}

// ── 看裝飾物 ────────────────────────────────────────────
string look_at_item(string id) {
    if (item_ids[id]) { return item_ids[id]; }
    return "";
}

void catch_tell(string msg) {}
