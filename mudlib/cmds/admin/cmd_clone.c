// /cmds/admin/cmd_clone.c
// 複製物件指令：clone <路徑>

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") {
        return 0;
    }

    if (!arg || arg == "") {
        write("用法：clone <檔案路徑>\n");
        return 1;
    }

    // 補足路徑與後綴
    if (arg[0] != '/') arg = "/" + arg;
    
    object ob = clone_object(arg);
    if (!ob) {
        write(HIR("複製失敗：無法載入或編譯檔案 " + arg + "\n"));
        return 1;
    }

    string msg = HIG("成功複製物件：") + ob->query_short() + " (" + base_name(ob) + ")\n";
    
    // 如果是物品，嘗試移入玩家背包
    if (ob->move(me)) {
        write(msg + "物件已放入你的背包。\n");
    } else {
        // 否則放入當前房間
        ob->move(environment(me));
        write(msg + "物件已放置在地面。\n");
    }

    return 1;
}

string *query_verbs() { return ({ "clone" }); }
string query_category() { return "Admin"; }

string help() {
    return "【管理指令】\n" +
           "  clone <路徑>    複製一個物件實體。如果是物品會試著放入背包，否則放在地上。\n";
}
