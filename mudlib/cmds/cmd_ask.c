// mudlib/cmds/cmd_ask.c
// 詢問指令：ask <目標> about <話題>

#include "/include/ansi.h"

int main(object me, string arg) {
    if (!arg || arg == "") {
        write("詢問誰？用法：ask <目標> about <話題>\n");
        return 1;
    }

    string target_id, topic;
    if (sscanf(arg, "%s about %s", target_id, topic) != 2) {
        // 嘗試簡寫：ask <目標> <話題>
        if (sscanf(arg, "%s %s", target_id, topic) != 2) {
            write("詢問關於什麼？用法：ask <目標> about <話題>\n");
            return 1;
        }
    }

    object target = present(target_id, environment(me));
    if (!target) {
        write("這裡沒有「" + target_id + "」這個人。\n");
        return 1;
    }

    if (!living(target)) {
        write("你要問一尊雕像什麼嗎？\n");
        return 1;
    }

    write("你向 " + target->query_name() + " 詢問關於「" + topic + "」的事。\n");
    say(me->query_name() + " 向 " + target->query_name() + " 詢問了一些事。\n");

    // 呼叫 NPC 的回應函式
    if (!target->do_chat(me, topic)) {
        write(target->query_name() + " 只是看了看你，什麼也沒說。\n");
    }

    return 1;
}

string help() {
    return "【詢問指令】\n" +
           "  ask <目標> about <話題>    向 NPC 詢問特定的資訊\n" +
           "  ask <目標> <話題>          詢問的簡寫方式\n";
}
