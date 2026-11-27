// std/room.c - 通用房間基底類別 (World-Agnostic)
// 不含任何世界觀特定欄位，純粹的空間容器

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/container.c";

string  short_desc;         // 房間標題
string  long_desc;          // 房間描述
mapping exits;              // 出口表：([ "north": "/area/..." ])
mapping item_ids;           // 房間內可互動的裝飾物描述
mapping hidden_elements;    // 隱藏元素 (search 相關)
mapping touch_descs;        // 觸覺描述
mapping smell_descs;        // 嗅覺描述
mapping listen_descs;       // 聽覺描述
mapping action_rules;       // 宣告式動作規則表
mapping room_flags;         // 通用房間旗標
int x;
int y;
int z;
int no_combat;              // 禁止戰鬥

void create() {
    ::create();
    short_desc = "未命名的空房間";
    long_desc  = "這裡什麼都沒有，只有無盡的虛空。\n";
    exits      = ([]);
    item_ids   = ([]);
    hidden_elements = ([]);
    touch_descs = ([]);
    smell_descs = ([]);
    listen_descs = ([]);
    action_rules = ([]);
    room_flags = ([]);
    x = 0; y = 0; z = 0;
    no_combat = 0;
    max_weight = 999999;
    max_items  = 999;
}

void init() {
    add_action("cmd_go", "go");
    if (mapp(action_rules) && sizeof(action_rules) > 0) {
        string *verbs = keys(action_rules);
        for (int i = 0; i < sizeof(verbs); i++) {
            add_action("do_declarative_action", verbs[i]);
        }
    }
}

// ── 出口管理 ────────────────────────────────────────────
void set_exit(string dir, string dest)  { if (!exits) exits = ([]); exits[dir] = dest; }
void del_exit(string dir)               { if (exits) map_delete(exits, dir); }
mapping query_exits()                   { return exits ? exits : ([]); }
string  query_exit(string dir)          { return exits ? exits[dir] : 0; }

// ── 描述與屬性查詢 ──────────────────────────────────────
void set_short(mixed s)                 { short_desc = s; }
void set_long(mixed s)                  { long_desc  = s; }
mixed query_short()                     { return select_lang(short_desc); }
mixed query_long()                      { return select_lang(long_desc); }
mapping query_item_ids()                { return item_ids ? item_ids : ([]); }
mapping query_hidden_elements()         { return hidden_elements ? hidden_elements : ([]); }
mapping query_touch_descs()             { return touch_descs ? touch_descs : ([]); }
mapping query_smell_descs()             { return smell_descs ? smell_descs : ([]); }
mapping query_listen_descs()            { return listen_descs ? listen_descs : ([]); }
mapping query_action_rules()            { return action_rules ? action_rules : ([]); }
mapping query_flags()                   { return room_flags ? room_flags : ([]); }
void set_flag(string k, mixed v)        { if (!room_flags) room_flags = ([]); room_flags[k] = v; }
mixed query_flag(string k)              { return room_flags ? room_flags[k] : 0; }
int *query_coords()                     { return ({ x, y, z }); }

int query_no_combat()     { return no_combat; }
void set_no_combat(int v) { no_combat = v; }

string look_at_item(string arg) {
    if (!arg || !mapp(item_ids)) return 0;
    if (item_ids[arg]) return to_string(select_lang(item_ids[arg]));
    string low = lower_case(arg);
    if (item_ids[low]) return to_string(select_lang(item_ids[low]));
    return 0;
}

int execute_action_rule(object me, string verb, string arg) {
    if (!me || !mapp(action_rules) || !mapp(action_rules[verb])) return 0;
    mapping rule = action_rules[verb];

    string matched_target = arg ? lower_case(trim(arg)) : "";
    if (arrayp(rule["targets"]) && sizeof(rule["targets"]) > 0) {
        int matched = 0;
        for (int i = 0; i < sizeof(rule["targets"]); i++) {
            string cand = to_string(rule["targets"][i]);
            if (matched_target == lower_case(cand)) {
                matched = 1;
                break;
            }
        }
        if (!matched) {
            string umsg = rule["usage_msg"] ? select_lang(rule["usage_msg"])
                : ("請指定目標（" + implode(rule["targets"], " / ") + "）。");
            write(umsg + "\n");
            return 1;
        }
    }

    if (stringp(rule["require_flag"]) && rule["require_flag"] != "" && !me->query_quest_flag(rule["require_flag"])) {
        write((rule["fail_msg"] ? select_lang(rule["fail_msg"]) : "條件尚未滿足，無法進行此操作。") + "\n");
        return 1;
    }

    if (stringp(rule["require_item"]) && rule["require_item"] != "" && !present(rule["require_item"], me)) {
        write((rule["missing_item_msg"] ? select_lang(rule["missing_item_msg"]) : ("缺少必需物品：" + rule["require_item"])) + "\n");
        return 1;
    }

    int sp_cost = intp(rule["sp_cost"]) ? rule["sp_cost"] : 0;
    if (sp_cost > 0) {
        if (me->query_sp() < sp_cost) {
            write("{RED}你精力不足，暫時無法進行此操作。{NOR}\n");
            return 1;
        }
        me->add_sp(-sp_cost);
    }

    if (mapp(rule["sensory_msgs"]) && rule["sensory_msgs"][matched_target]) {
        write(select_lang(rule["sensory_msgs"][matched_target]) + "\n");
    } else if (rule["sensory_msg"]) {
        write(select_lang(rule["sensory_msg"]) + "\n");
    } else {
        write("你執行了「" + verb + "」。\n");
    }

    if (intp(rule["exp_gain"]) && rule["exp_gain"] > 0) {
        me->gain_exp(rule["exp_gain"]);
    }
    if (intp(rule["money_gain"]) && rule["money_gain"] != 0) {
        me->add_money(rule["money_gain"]);
    }
    if (mapp(rule["set_flags"])) {
        string *fk = keys(rule["set_flags"]);
        for (int i = 0; i < sizeof(fk); i++) {
            me->set_quest_flag(fk[i], rule["set_flags"][fk[i]]);
        }
    }
    if (mapp(rule["world_vars"])) {
        object wsd = find_object(WORLD_STATE_D);
        if (!wsd) wsd = load_object(WORLD_STATE_D);
        if (wsd) {
            string *wk = keys(rule["world_vars"]);
            for (int i = 0; i < sizeof(wk); i++) {
                mixed v = rule["world_vars"][wk[i]];
                if (intp(v)) wsd->add_var(wk[i], v);
                else if (mapp(v) && !undefinedp(v["set"])) wsd->set_var(wk[i], v["set"]);
            }
        }
    }
    if (stringp(rule["quest_event"]) && rule["quest_event"] != "") {
        object qed = find_object(QUEST_ENGINE_D);
        if (!qed) qed = load_object(QUEST_ENGINE_D);
        if (qed) qed->trigger_quest_event(me, rule["quest_event"], ([ "verb": verb, "target": matched_target ]));
    }

    object ui = find_object(UI_BRIDGE_D);
    if (ui) {
        ui->push_char_view(me);
        ui->push_quest_list(me);
    }
    return 1;
}

int do_declarative_action(string arg) {
    string verb = query_verb();
    object me = this_player();
    return execute_action_rule(me, verb, arg);
}

// ── 移動指令 ─────────────────────────────────────────────
int cmd_go(string dir) {
    if (!dir || dir == "") {
        return 0;
    }
    string dest = exits ? exits[dir] : 0;
    if (!dest) {
        write("那個方向沒有出口。\n");
        return 1;
    }
    object room = load_object(dest);
    if (!room) {
        write("無法前往那個方向（房間載入失敗）。\n");
        return 1;
    }
    object me = this_player();
    if (!me) return 0;
    string exit_msg  = to_string(me->query_short()) + " 往 " + dir + " 離開了。\n";
    string enter_msg = to_string(me->query_short()) + " 從 " + dir + " 進入了。\n";
    say(exit_msg);
    move_object(me, room);
    tell_room(room, enter_msg, ({ me }));
    me->do_look();
    me->mark_explored(base_name(room));

    object qed = find_object(QUEST_ENGINE_D);
    if (qed) qed->trigger_quest_event(me, "enter_room", ([ "room": dest ]));

    object ui = find_object(UI_BRIDGE_D);
    if (!ui) ui = load_object(UI_BRIDGE_D);
    if (ui) ui->push_room_view(me);
    return 1;
}
