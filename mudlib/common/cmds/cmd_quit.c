// cmds/cmd_quit.c - 共用離開指令 (quit / exit)

#include "/include/ansi.h"

inherit "/std/object.c";

string *query_verbs()   { return ({ "quit", "exit" }); }
string query_category() {
    return select_lang(([ "en": "System", "zh-TW": "系統", "zh-CN": "系统" ]));
}

int main(object me, string verb, string arg) {
    if (environment(me) && function_exists("set_last_location", me)) {
        me->set_last_location(base_name(environment(me)));
    }
    if (function_exists("do_save", me)) {
        me->do_save();
    } else if (function_exists("save", me)) {
        me->save();
    }

    string uname = to_string(me->query_name());
    if (!uname || uname == "" || uname == "0") uname = to_string(me->query_short());

    write(select_lang(([
        "en":    "Saved. See you next time.\n",
        "zh-TW": "存檔完畢，下次見。\n",
        "zh-CN": "存档完毕，下次见。\n"
    ])));
    write(select_lang(([ "en": "Goodbye, ", "zh-TW": "再見，", "zh-CN": "再见，" ])) + uname + select_lang(([
        "en":    "! You fade away into light...\n",
        "zh-TW": "！你化為一道光消逝了...\n",
        "zh-CN": "！你化为一道光消逝了...\n"
    ])));
    if (environment(me)) {
        tell_room(environment(me), uname + select_lang(([
            "en":    " has left the game.\n",
            "zh-TW": " 離開了遊戲。\n",
            "zh-CN": " 离开了游戏。\n"
        ])), ({ me }));
    }

    // 互動連線嘗試轉回登入畫面，而非直接斷線
    if (interactive(me)) {
        object login_ob = clone_object("/std/login.c");
        if (login_ob && exec(login_ob, me)) {
            if (function_exists("logon", login_ob)) login_ob->logon();
            destruct(me);
            return 1;
        }
    }

    if (function_exists("cleanup_editor", me)) {
        me->cleanup_editor();
    }
    destruct(me);
    return 1;
}

string help() {
    return select_lang(([
        "en":    "【Quit Command】\n  Usage: quit or exit\n  Function: Save character data and safely log out of the game.\n",
        "zh-TW": "【離開指令】\n  用法：quit 或 exit\n  功能：儲存角色資料並安全地登出遊戲。\n",
        "zh-CN": "【离开指令】\n  用法：quit 或 exit\n  功能：储存角色资料并安全地登出游戏。\n"
    ]));
}
