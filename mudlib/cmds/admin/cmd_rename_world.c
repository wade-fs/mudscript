// /cmds/admin/cmd_rename_world.c
// 管理指令：為全域 MUD 重新命名

#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god") {
        return 0;
    }

    if (!arg || arg == "") {
        write("用法：rename_world <mudlib_id> <mudlib_name>\n");
        write("範例：\n");
        write("  rename_world fantasy.space \"Fantasy Space\"\n");
        write("  rename_world my.mud MyMud\n");
        return 1;
    }

    string gid, gname;
    // 優先處理帶引號的情況
    if (sscanf(arg, "%s \"%s\"", gid, gname) == 2) {
        // 移除結尾可能存在的引號
        if (strlen(gname) > 0 && gname[strlen(gname)-1..strlen(gname)-1] == "\"") {
            gname = gname[0..strlen(gname)-2];
        }
    } else if (sscanf(arg, "%s %s", gid, gname) != 2) {
        write("語法錯誤！用法：rename_world <mudlib_id> <mudlib_name>\n");
        return 1;
    }

    object system_d = load_object("/secure/system_d");
    if (system_d) {
        system_d->set_mudlib_name(gname, gid);
        write(HIG("✅ 全域 MUD 重新命名成功：") + "\n");
        write("   ID  : " + gid + "\n");
        write("   名稱: " + gname + "\n");
        return 1;
    }

    write(RED("❌ 錯誤：無法載入 system_d。\n"));
    return 1;
}

string *query_verbs() { return ({ "rename_world" }); }
string query_category() { return "Admin"; }

string help() {
    return "【管理指令：rename_world】\n\n" +
           "此指令僅限 God 使用，用於修改全域 MUD 的識別 ID 與顯示名稱。\n\n" +
           "語法：\n" +
           "  rename_world <mudlib_id> <mudlib_name>\n\n" +
           "範例：\n" +
           "  rename_world fantasy.space \"Fantasy Space\"\n" +
           "  rename_world test.mud TestMUD\n\n" +
           "注意：如果名稱中包含空白，請務必使用雙引號 \"\" 括起來。\n";
}
