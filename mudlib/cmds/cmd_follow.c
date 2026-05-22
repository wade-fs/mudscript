// /cmds/cmd_follow.c
// 跟隨指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        object leader = me->query_leader();
        if (leader) {
            write("你停止跟隨 " + leader->query_name() + "。\n");
            leader->remove_follower(me);
            me->set_leader(0);
        } else {
            write("你要跟隨誰？用法：follow <ID>\n");
        }
        return 1;
    }

    object target = find_player(arg);
    if (!target) target = present(arg, environment(me));
    
    if (!target) {
        write("這裡沒有「" + arg + "」這個人。\n");
        return 1;
    }
    
    if (target == me) {
        write("你不能跟隨你自己。\n");
        return 1;
    }

    // 清除舊的跟隨
    object old_leader = me->query_leader();
    if (old_leader) old_leader->remove_follower(me);

    me->set_leader(target);
    target->add_follower(me);
    
    write("你開始跟隨 " + target->query_name() + "。\n");
    tell_object(target, me->query_name() + " 開始跟隨你。\n");

    return 1;
}

string help() {
    return "【指令】\n" +
           "  follow <ID>    跟隨指定玩家或 NPC。不帶參數則停止跟隨。\n";
}
