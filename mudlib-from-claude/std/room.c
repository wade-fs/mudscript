// std/room.c - 所有房間的基底類別

#include "/include/config.h"

string  short_desc;    // 房間標題
string  long_desc;     // 房間描述
mapping exits;         // 出口表：([ "north": "/area/..." ])
mixed   item_ids;      // 房間內可互動的裝飾物描述表

void create() {
    short_desc = "未命名的空房間";
    long_desc  = "這裡什麼都沒有，只有無盡的虛空。\n";
    exits      = ([]);
    item_ids   = ([]);
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

    // 列出出口
    mixed exit_dirs = keys(exits);
    if (sizeof(exit_dirs) > 0) {
        write("出口：" + implode(exit_dirs, "  ") + "\n");
    } else {
        write("出口：（無）\n");
    }

    // 列出房間內的物件（玩家與道具，排除房間本身）
    mixed here_inv = all_inventory(this_object());
    mixed items_in_room = ({});
    mixed livings_in_room = ({});

    int i;
    for (i = 0; i < sizeof(here_inv); i++) {
        mixed ob = here_inv[i];
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
            write(items_in_room[j]->query_short());
            if (j < sizeof(items_in_room) - 1) { write("、"); }
        }
        write("\n");
    }

    if (sizeof(livings_in_room) > 0) {
        write("這裡有：");
        int k;
        for (k = 0; k < sizeof(livings_in_room); k++) {
            write(livings_in_room[k]->query_name());
            if (k < sizeof(livings_in_room) - 1) { write("、"); }
        }
        write("\n");
    }
}

// ── 移動指令 ────────────────────────────────────────────
void init() {
    // 為所有出口方向加上移動指令
    mixed dirs = keys(exits);
    int i;
    for (i = 0; i < sizeof(dirs); i++) {
        add_action("do_go", dirs[i]);
    }
    add_action("do_go", "go");
}

int do_go(string dir) {
    // 支援 "go north" 或直接 "north"
    mixed cmd = dir;

    // 查出口
    if (!exits[cmd]) {
        write("那個方向沒有出路。\n");
        return 1;
    }

    string dest_path = exits[cmd];
    object dest = clone_object(dest_path);
    if (!dest) {
        write("目的地不存在。\n");
        return 1;
    }

    object me = this_player();
    string my_name = me->query_name();

    say(my_name + " 往 " + cmd + " 方向離開了。\n");
    move_object(dest);
    say(my_name + " 從 " + cmd + " 方向來到了這裡。\n");
    dest->look_room();
    return 1;
}

// ── 看裝飾物 ────────────────────────────────────────────
string look_at_item(string id) {
    if (item_ids[id]) {
        return item_ids[id];
    }
    return "";
}

// catch_tell 讓房間能接收到 say 訊息（NPC AI 用）
void catch_tell(string msg) {}
