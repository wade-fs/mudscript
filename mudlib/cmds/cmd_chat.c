// /cmds/cmd_chat.c
// 聊天頻道指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("用法：" + verb + " <訊息>\n");
        return 1;
    }

    string type;
    switch (verb) {
        case "chat":  type = "chat";  break;
        case "area":  type = "area";  break;
        case "gsay":  type = "guild"; break;
        case "ttell": type = "team";  break;
        default:      type = "chat";  break;
    }

    if (!me->is_channel_open(type)) {
        write("你已經關閉了這個頻道，請先開啟再發言。\n");
        return 1;
    }

    load_object("/secure/channel_d.c")->broadcast(type, me, arg, "");
    return 1;
}

int do_fchat(object me, string arg) {
    if (!arg || arg == "") {
        write("用法：fchat <頻道ID> <訊息>\n");
        return 1;
    }

    int sp = strsrch(arg, " ");
    if (sp == -1) {
        write("用法：fchat <頻道ID> <訊息>\n");
        return 1;
    }

    string cid = substr(arg, 0, sp);
    string msg = substr(arg, sp + 1, strlen(arg) - sp - 1);

    load_object("/secure/channel_d.c")->broadcast("friend", me, msg, cid);
    return 1;
}

string help() {
    return "【聊天指令】\n" +
           "  chat <訊息>    全域頻道發言\n" +
           "  area <訊息>    當前區域發言\n" +
           "  gsay <訊息>    公會頻道發言\n" +
           "  ttell <訊息>   團隊頻道發言\n" +
           "  fchat <ID> <訊息> 好友頻道發言\n";
}
