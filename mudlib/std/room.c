// std/room.c - 所有房間的基底類別

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/container.c";

string  short_desc;    // 房間標題
string  long_desc;     // 房間描述
mapping exits;         // 出口表：([ "north": "/area/..." ])
mixed   item_ids;      // 房間內可互動的裝飾物描述表

// 🚀 新增：隱藏元素 (用於 search)
mapping hidden_elements; // ([ "id": ([ "type": "exit/item", "value": "...", "msg": "..." ]) ])

// 🚀 新增空間座標 (注意：配合 Go 解析器限制，逐行宣告)
int x;
int y;
int z;
int no_combat;         // 🚀 禁止戰鬥屬性
int has_forge;         // 🚀 鍛造設施
int has_lab;           // 🚀 煉金設施
int has_bank;          // 🚀 銀行設施
int has_tavern;        // 🚀 酒館設施
int has_guild;         // 🚀 公會設施
int has_shop;          // 🚀 商店設施
int is_outdoor;        // 🚀 是否為室外

void create() {
    ::create();
    short_desc = "未命名的空房間";
    long_desc  = "這裡什麼都沒有，只有無盡的虛空。\n";
    exits      = ([]);
    item_ids   = ([]);
    hidden_elements = ([]);
    x = 0;
    y = 0;
    z = 0;
    no_combat = 0;
    has_forge = 0;
    has_lab   = 0;
    has_bank  = 0;
    has_tavern= 0;
    has_guild = 0;
    has_shop  = 0;
    is_outdoor = 1; // 預設皆為室外
}

// 判斷物件是否可以進入房間 (房間預設允許所有人進入)
int can_receive(object ob) {
    return 1;
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
void set_no_combat(int v){ no_combat = v; }
void set_has_forge(int v){ has_forge = v; }
void set_has_lab(int v)  { has_lab   = v; }
void set_has_bank(int v) { has_bank  = v; }
void set_has_tavern(int v){ has_tavern = v; }
void set_has_guild(int v){ has_guild = v; }
void set_has_shop(int v) { has_shop  = v; }
void set_is_outdoor(int v){ is_outdoor = v; }

void add_exit(string dir, string path) {
    exits[dir] = path;
}

void add_item(string id, string desc) {
    item_ids[id] = desc;
}

void add_hidden_element(string id, mapping data) {
    hidden_elements[id] = data;
}

// ── NPC 產生與重生 ─────────────────────────────────────
void spawn_npc(string file) {
    object ob = clone_object(file);
    if (ob) {
        move_object(ob, this_object());
    }
}

// ── 查詢函式 ────────────────────────────────────────────
string query_short() { return select_lang(short_desc); }
string query_long()  { return select_lang(long_desc); }
mapping query_exits(){ return exits; }
int query_no_combat(){ return no_combat; }
int query_has_forge(){ return has_forge; }
int query_has_lab()  { return has_lab; }
int query_has_bank() { return has_bank; }
int query_has_tavern(){ return has_tavern; }
int query_has_guild(){ return has_guild; }
int query_has_shop() { return has_shop; }
int query_is_outdoor(){ return is_outdoor; }

// ── 顯示房間 ────────────────────────────────────────────
void look_room(object who) {
    if (!who) who = this_player();

    // 顯示天氣與時間 (僅限室外)
    if (is_outdoor) {
        write(HIG(load_object("/secure/nature_d.c")->query_weather_string()) + "\n");
    }

    write("【" + query_short() + "】\n");
    write(query_long() + "\n");

    mixed exit_dirs = keys(exits);
    if (exit_dirs) {
        // 將出口用 [ ] 包起來，讓前端可以轉化為可點擊的連結
        string *formatted_exits = ({});
        for (int i = 0; i < sizeof(exit_dirs); i++) {
            formatted_exits += ({ "[" + exit_dirs[i] + "]" });
        }
        write(_t("exits") + "：" + implode(formatted_exits, "  ") + "\n");
    } else {
        write(_t("exits") + "：（無）\n");
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
        write(_t("inventory") + "：\n");
        int j;
        for (j = 0; j < sizeof(items_in_room); j++) {
            object item = items_in_room[j];
            string item_id = item->query_key_id();
            write("  [" + item->query_short() + "(" + item_id + ")|look " + item_id + "]\n");
        }
    }

    if (sizeof(livings_in_room) > 0) {
        write(_t("livings") + "：\n");
        int k;
        for (k = 0; k < sizeof(livings_in_room); k++) {
            object liv = livings_in_room[k];
            if (!liv || liv == who) continue; // 不看自己
            
            string liv_id = "living";
            string display_name = liv->query_name();
            
            if (!display_name || display_name == "0") display_name = "某個生物";
            
            if (userp(liv)) {
                liv_id = liv->get_id();
                // 🚀 關鍵修正：不要在 [ ] 內嵌套 [ ]，會導致前端 regex 誤判
                display_name = "(玩家) " + display_name;
            } else {
                // 從 ID 列表抓取第一個可用 ID
                mixed ids = liv->query_id();
                if (arrayp(ids) && sizeof(ids) > 0) liv_id = ids[0];
                else if (stringp(ids)) liv_id = ids;
            }
            
            if (!liv_id || liv_id == "0") liv_id = "living";
            
            // 統一輸出格式：[顯示名稱(id)|指令]
            write("  [" + display_name + "(" + liv_id + ")|look " + liv_id + "]\n");
        }
    }

    // 🚀 新增：發送小地圖的 JSON 資料給前端
    object map_d = load_object("/secure/map_d.c");
    mapping map_data = ([]);
    if (map_d) {
        map_data = map_d->get_map_json(who, 2); // 取得 5x5 的網格資料
    }
    map_data["exits"] = keys(exits); // 同時保留可用出口資訊給前端使用
    write(sprintf("{\"ui\": \"minimap\", \"data\": %s}", json_encode(map_data)));

    // 🚀 新增：發送天氣資訊給前端
    object nature_d = load_object("/secure/nature_d.c");
    mapping nature_data = ([
        "weather": nature_d->query_weather(),
        "is_day": nature_d->is_day(),
        "hour": nature_d->query_hour(),
        "season": nature_d->query_season()
    ]);
    write(sprintf("{\"ui\": \"nature\", \"data\": %s}", json_encode(nature_data)));
}

// ── 移動指令 ────────────────────────────────────────────
void init() {
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

    // 🚩 性能優化：當玩家進入房間時，喚醒房間內所有 NPC 的心跳
    if (userp(this_player())) {
        object *inv = all_inventory(this_object());
        for (i = 0; i < sizeof(inv); i++) {
            if (living(inv[i])) inv[i]->set_heart_beat(1);
        }
    }
}

// ── 移動 ───────────────────────────────────────────────
int do_go(string dir) {
    mixed cmd = dir;
    if (!cmd) {
        cmd = query_verb();
    }

    if (!exits[cmd]) {
        write(_t("no_exit_err") + "\n");
        return 1;
    }

    string dest_path = exits[cmd];
    object dest = load_object(dest_path);
    if (!dest) {
        write(_t("dest_missing_err") + "\n");
        return 1;
    }

    object me = this_player();
    string my_name = me->query_name();
    object lang_d = load_object("/secure/language_d.c");

    // 廣播離開訊息 (給原本房間的人)
    lang_d->broadcast_event(this_object(), "say_leave", ([ "$name": my_name, "$dir": cmd ]));

    if (me->move(dest, cmd)) {
        // 廣播抵達訊息 (給新房間的人)
        // 🚀 關鍵修正：抵達訊息應該顯示「反向」
        string from_dir = query_reverse_dir(cmd);
        lang_d->broadcast_event(dest, "say_arrive", ([ "$name": my_name, "$dir": from_dir ]));
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
        write("你搜了半天，什麼都沒有發現。\n");
        return 1;
    }

    mixed ks = keys(hidden_elements);
    int found = 0;
    
    foreach (string key in ks) {
        mapping data = hidden_elements[key];
        
        // 這裡可以加入機率或屬性判定
        if (random(100) < 50) { // 50% 機率搜到
            write(data["msg"] + "\n");
            
            if (data["type"] == "exit") {
                add_exit(key, data["value"]);
            } else if (data["type"] == "item") {
                object ob = clone_object(data["value"]);
                if (ob) {
                    write("你找到了一件物品：" + ob->query_short() + "\n");
                    move_object(ob, this_object());
                }
            }
            
            // 搜到後移除隱藏標記
            m_delete(hidden_elements, key);
            found = 1;
        }
    }

    if (!found) {
        write("你搜了半天，什麼都沒有發現。\n");
    }

    return 1;
}

// ── 看裝飾物 ────────────────────────────────────────────
string look_at_item(string id) {
    if (item_ids[id]) { return item_ids[id]; }
    return "";
}

void catch_tell(string msg) {}
