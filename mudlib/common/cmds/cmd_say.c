// cmds/cmd_say.c - 共用說話指令（支援跨服廣播）

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

string *query_verbs()   { return ({ "say", "說", "'", "\"" }); }
string query_category() { return "Communication"; }

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("說些什麼吧！\n");
        return 1;
    }

    object env = environment(me);
    if (!env) return 1;

    string player_name = to_string(me->query_name());
    if (!player_name || player_name == "" || player_name == "0") {
        player_name = to_string(me->query_short());
    }

    string local_msg = "$HIY$" + player_name + "$NOR$" + " 說道：" + arg + "\n";
    write("你說道：" + arg + "\n");
    tell_room(env, local_msg, ({ me }));

    // 若在跨服房間且世界存在 fs_d，同時廣播給遠端
    if (function_exists("query_current_mudlib", me)) {
        string current_mudlib = me->query_current_mudlib();
        if (current_mudlib && current_mudlib != "" && file_size("/secure/fs_d.c") > 0) {
            object fs_d = find_object("/secure/fs_d.c");
            if (!fs_d) fs_d = load_object("/secure/fs_d.c");
            if (fs_d && function_exists("player_remote_say", fs_d)) {
                fs_d->player_remote_say(me, arg);
            }
        }
    }

    return 1;
}

string help() {
    return "  say <訊息>   說話（在跨服房間時，遠端玩家也能聽到）\n";
}
