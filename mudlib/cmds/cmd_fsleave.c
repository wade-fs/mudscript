// /cmds/cmd_fsleave.c
// 離開遠端 Fantasy Space mudlib，清空緩存

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        object fs_d = load_object("/secure/fs_d.c");
        if (fs_d) {
            mapping joined = fs_d->query_joined_muds();
            if (!joined || !sizeof(joined)) {
                write("你目前沒有加入任何遠端 mudlib。\n");
                return 1;
            }
            write("目前已加入的 mudlib：\n");
            foreach (string mid in keys(joined)) {
                string status = joined[mid]["status"];
                write("  " + mid + " [" + status + "]\n");
            }
            write("用法：fsleave <mudlib_id>\n");
        }
        return 1;
    }

    // 🚀 特化處理：去除雙引號，並將空格轉換為點（ID 格式）
    arg = trim(arg);
    if (strlen(arg) > 2 && arg[0] == '"' && arg[strlen(arg)-1] == '"') {
        arg = substr(arg, 1, strlen(arg)-2);
    }
    arg = replace_string(arg, " ", ".");

    object fs_d = load_object("/secure/fs_d.c");
    if (!fs_d) {
        write("Fantasy Space 系統暫時無法使用。\n");
        return 1;
    }

    write(fs_d->do_leave(me, arg));
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  fsleave <mudlib_id>   Leave a remote mudlib and clear its cache.\n",
        "zh-TW": "【指令】\n  fsleave <mudlib_id>   離開遠端 mudlib 並清空緩存。\n",
        "zh-CN": "【指令】\n  fsleave <mudlib_id>   离开远端 mudlib 并清空缓存。\n"
    ]));
}
