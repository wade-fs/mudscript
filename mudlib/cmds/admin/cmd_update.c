// /cmds/admin/cmd_update.c
// 重新載入物件指令：update <檔名>

inherit "/std/object";

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg) {
        write("請指定要更新的檔案路徑。\n");
        return 1;
    }

    if (me->query_role() != "god") {
        write("只有管理員可以使用此指令。\n");
        return 1;
    }

    if (substr(arg, 0, 1) != "/") {
        arg = "/" + arg;
    }
    if (substr(arg, strlen(arg)-2, 2) != ".c") {
        arg = arg + ".c";
    }

    object ob = find_object(arg);
    if (ob) {
        destruct(ob);
        write(HIW("物件已從記憶體移除：") + arg + "\n");
    }

    object new_ob = load_object(arg);
    if (new_ob) {
        write(HIG("物件已重新載入成功：") + arg + "\n");
    } else {
        write(HIR("物件載入失敗！") + "\n");
    }

    return 1;
}

string help() {
    return "【管理指令】\n" +
           "  update <路徑>    重新編譯並載入指定的 LPC 檔案\n";
}
