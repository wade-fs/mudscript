// cmds/cmd_talk.c - 通用 NPC 對話與狀態機互動指令

#include "/include/ansi.h"

string *query_verbs()   { return ({ "talk", "ask" }); }
string query_category() { return "General"; }

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("你想和誰對話？（用法：talk <NPC> [話題]）\n");
        return 1;
    }

    object room = environment(me);
    if (!room) return 1;

    string target_id = arg;
    string topic = "default";
    int sp_idx = strsrch(arg, " ");
    if (sp_idx != -1) {
        target_id = substr(arg, 0, sp_idx);
        topic = trim(substr(arg, sp_idx + 1, strlen(arg) - sp_idx - 1));
        if (topic == "") topic = "default";
    }

    object target = present(target_id, room);
    if (!target) target = present(lower_case(target_id), room);
    if (!target || !living(target)) {
        write("這裡沒有「" + target_id + "」。\n");
        return 1;
    }

    if (function_exists("talk_to", target)) {
        string reply = target->talk_to(me, topic);
        write(reply + "\n");
        object ui = find_object("/daemon/ui_bridge_d.c");
        if (ui) {
            ui->push_room_view(me);
            ui->push_quest_list(me);
            ui->push_char_view(me);
        }
        return 1;
    }

    if (function_exists("query_dialogue", target)) {
        mixed reply = target->query_dialogue(topic);
        if (reply) {
            write(to_string(select_lang(reply)) + "\n");
            return 1;
        }
    }

    write(to_string(target->query_name()) + " 似乎沒有什麼話想對你說。\n");
    return 1;
}
