// cmds/cmd_save.c - 共用存檔指令

#include "/include/ansi.h"

inherit "/std/object.c";

string *query_verbs()   { return ({ "save" }); }
string query_category() {
    return select_lang(([ "en": "System", "zh-TW": "系統", "zh-CN": "系统" ]));
}

int main(object me, string verb, string arg) {
    int ok = 0;
    if (function_exists("do_save", me)) {
        me->do_save();
        ok = 1;
    } else if (function_exists("save", me)) {
        ok = me->save();
    }

    if (ok) {
        write(select_lang(([
            "en":    "Data saved.\n",
            "zh-TW": "檔案儲存完畢。\n",
            "zh-CN": "文件储存完毕。\n"
        ])));
    } else {
        write(select_lang(([
            "en":    "Save failed!\n",
            "zh-TW": "儲存失敗！\n",
            "zh-CN": "储存失败！\n"
        ])));
    }
    return 1;
}

string help() {
    return select_lang(([
        "en":    "【Save Command】\n  Usage: save\n  Function: Manually save character data.\n",
        "zh-TW": "【存檔指令】\n  用法：save\n  功能：手動儲存角色資料。\n",
        "zh-CN": "【存档指令】\n  用法：save\n  功能：手动储存角色资料。\n"
    ]));
}
