// /cmds/cmd_p2p.c
// 星際聊天指令

#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("用法：fs <訊息>\n");
        return 1;
    }

    p2p_broadcast(arg);
    return 1;
}

string help() {
    return "【指令】\n" +
           "  fs <訊息>    在星際網路（Fantasy Space 跨服頻道）發送訊息。\n";
}
