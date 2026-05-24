// /cmds/cmd_fsjoin.c
// 加入遠端 Fantasy Space mudlib

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(select_lang(([
            "en": "Usage: fsjoin <mudlib_id>  e.g. fsjoin \"fantasy space\"\n",
            "zh-TW": "用法：fsjoin <mudlib_id>  例如：fsjoin \"fantasy space\"\n",
            "zh-CN": "用法：fsjoin <mudlib_id>  例如：fsjoin \"fantasy space\"\n"
        ])));
        return 1;
    }

    // 🚀 特化處理：去除雙引號，並將空格轉換為點（ID 格式）
    arg = trim(arg);
    if (strlen(arg) > 2 && arg[0] == '"' && arg[strlen(arg)-1] == '"') {
        arg = substr(arg, 1, strlen(arg)-2);
    }
    arg = replace_string(arg, " ", ".");

    // 驗證 mudlib_id 格式：英文字母、數字、點，最多 64 字
    if (strlen(arg) > 64) {
        write("mudlib_id 太長（最多 64 字）。\n");
        return 1;
    }

    object fs_d = load_object("/secure/fs_d.c");
    if (!fs_d) {
        write("Fantasy Space 系統暫時無法使用。\n");
        return 1;
    }

    write(fs_d->do_join(me, arg));
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  fsjoin <mudlib_id>   Join a remote Fantasy Space mudlib.\n  e.g.  fsjoin other.mud\n",
        "zh-TW": "【指令】\n  fsjoin <mudlib_id>   加入遠端 Fantasy Space mudlib。\n  例如：fsjoin other.mud\n",
        "zh-CN": "【指令】\n  fsjoin <mudlib_id>   加入远端 Fantasy Space mudlib。\n  例如：fsjoin other.mud\n"
    ]));
}
