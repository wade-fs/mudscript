// /cmds/cmd_channel.c
// 頻道管理指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(HIW("\n=== 頻道訂閱狀態 ===\n"));
        string *chs = ({ "chat", "area", "guild", "team" });
        foreach (string ch in chs) {
            int open = me->is_channel_open(ch);
            write(sprintf("  %-10s : %s\n", ch, (open ? HIG("開啟") : HIR("關閉"))));
        }
        write("用法：channel <頻道ID> on/off\n");
        return 1;
    }

    string *parts = explode(arg, " ");
    if (sizeof(parts) < 2) {
        write("用法：channel <頻道ID> on/off\n");
        return 1;
    }

    string ch = parts[0];
    string status = parts[1];

    if (status == "on" || status == "開啟") {
        me->set_channel_status(ch, 1);
        write(HIG("你開啟了 " + ch + " 頻道。\n"));
    } else if (status == "off" || status == "關閉") {
        me->set_channel_status(ch, 0);
        write(HIR("你關閉了 " + ch + " 頻道。\n"));
    } else {
        write("未知狀態，請使用 on 或 off。\n");
    }

    me->save();
    return 1;
}

string help() {
    return "【頻道管理】\n" +
           "  channel            查看所有頻道的開關狀態\n" +
           "  channel <ID> on    開啟指定頻道\n" +
           "  channel <ID> off   關閉指定頻道\n";
}
