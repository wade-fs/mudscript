// /cmds/cmd_fsflush.c
// 重新拉取遠端 Fantasy Space mudlib 的緩存

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(select_lang(([
            "en": "Usage: fsflush <mudlib_id>  — Refresh cached rooms from a remote mudlib.\n",
            "zh-TW": "用法：fsflush <mudlib_id>  — 重新拉取遠端 mudlib 的緩存。\n",
            "zh-CN": "用法：fsflush <mudlib_id>  — 重新拉取远端 mudlib 的缓存。\n"
        ])));
        return 1;
    }

    object fs_d = load_object("/secure/fs_d.c");
    if (!fs_d) {
        write("Fantasy Space 系統暫時無法使用。\n");
        return 1;
    }

    write(fs_d->do_flush(me, arg));
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  fsflush <mudlib_id>   Re-fetch all cached rooms from a remote mudlib.\n",
        "zh-TW": "【指令】\n  fsflush <mudlib_id>   重新從遠端 mudlib 拉取所有已緩存的房間。\n",
        "zh-CN": "【指令】\n  fsflush <mudlib_id>   重新从远端 mudlib 拉取所有已缓存的房间。\n"
    ]));
}
