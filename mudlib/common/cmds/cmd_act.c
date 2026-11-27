// cmds/cmd_act.c - 感官探索與房間宣告式互動指令 (Phase 2 MVVM)
// 支援：search, touch, smell, listen, act <verb> [target]

#include "/include/ansi.h"
#include "/include/config.h"

string *query_verbs()   { return ({ "search", "touch", "smell", "listen", "act" }); }
string query_category() { return "General"; }

mixed match_map_entry(mapping m, string arg) {
    if (!mapp(m) || sizeof(m) == 0) return 0;
    if (!arg || arg == "") {
        if (m["default"]) return m["default"];
        return 0;
    }
    if (m[arg]) return m[arg];
    string low = lower_case(arg);
    if (m[low]) return m[low];
    return 0;
}

int handle_sensory(object me, object room, string verb, string arg) {
    mapping data = ([]);
    string empty_msg = "你沒有發現什麼特別之處。";

    if (verb == "search") {
        if (function_exists("query_hidden_elements", room)) data = room->query_hidden_elements();
        empty_msg = "你仔細搜尋了一番，沒有發現隱藏的事物。";
    } else if (verb == "touch") {
        if (function_exists("query_touch_descs", room)) data = room->query_touch_descs();
        empty_msg = "你想觸摸什麼？";
    } else if (verb == "smell") {
        if (function_exists("query_smell_descs", room)) data = room->query_smell_descs();
        empty_msg = "空氣中沒有什麼特別的氣味。";
    } else if (verb == "listen") {
        if (function_exists("query_listen_descs", room)) data = room->query_listen_descs();
        empty_msg = "四周很安靜，聽不見特別的聲響。";
    }

    mixed matched = match_map_entry(data, arg);
    if (!matched) {
        write(empty_msg + "\n");
        return 1;
    }

    if (stringp(matched)) {
        write(matched + "\n");
        return 1;
    }
    if (mapp(matched)) {
        if (matched["text"]) {
            write(select_lang(matched["text"]) + "\n");
        } else {
            write(select_lang(matched) + "\n");
        }
        if (stringp(matched["set_flag"]) && matched["set_flag"] != "") {
            me->set_quest_flag(matched["set_flag"], 1);
        }
        if (stringp(matched["quest_event"]) && matched["quest_event"] != "") {
            object qed = find_object(QUEST_ENGINE_D);
            if (qed) qed->trigger_quest_event(me, matched["quest_event"], ([ "target": arg ? arg : "default" ]));
        }
        return 1;
    }

    write(to_string(matched) + "\n");
    return 1;
}

int main(object me, string verb, string arg) {
    object room = environment(me);
    if (!room) {
        write("你不在任何地方。\n");
        return 1;
    }

    if (verb == "act") {
        if (!arg || arg == "") {
            mapping rules = function_exists("query_action_rules", room) ? room->query_action_rules() : ([]);
            if (!mapp(rules) || sizeof(rules) == 0) {
                write("這個地方沒有可用的環境互動動作。\n");
            } else {
                write("{CYN}可用互動動作：{NOR}" + implode(keys(rules), ", ") + "\n");
            }
            return 1;
        }
        string act_verb = arg;
        string act_arg = 0;
        int sp = strsrch(arg, " ");
        if (sp != -1) {
            act_verb = trim(substr(arg, 0, sp));
            act_arg = trim(substr(arg, sp + 1, strlen(arg) - sp - 1));
        }
        if (function_exists("execute_action_rule", room)) {
            if (room->execute_action_rule(me, act_verb, act_arg)) return 1;
        }
        write("這裡無法執行「" + act_verb + "」。\n");
        return 1;
    }

    return handle_sensory(me, room, verb, arg ? trim(arg) : "");
}

string help() {
    return select_lang(([
        "en":    "【Interact】search/touch/smell/listen [target], act <action> [target]\n",
        "zh-TW": "【互動指令】search/touch/smell/listen [目標]、act <動作> [目標]\n",
        "zh-CN": "【互动指令】search/touch/smell/listen [目标]、act <动作> [目标]\n"
    ]));
}
