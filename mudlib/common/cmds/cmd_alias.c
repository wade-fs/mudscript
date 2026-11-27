// cmds/cmd_alias.c - 共用別名管理指令 (alias / unalias)

#include "/include/ansi.h"

string *query_verbs()   { return ({ "alias", "unalias" }); }
string query_category() { return "System"; }

int do_alias(object me, string arg) {
    mapping al = me->query_aliases();
    if (!mapp(al)) al = ([]);

    if (!arg || arg == "") {
        mixed ks = sort_array(keys(al), 1);
        if (!ks || sizeof(ks) == 0) {
            write(select_lang(([
                "en": "You haven't set any aliases.\n",
                "zh-TW": "你沒有設定任何別名。\n",
                "zh-CN": "你没有设定任何别名。\n"
            ])));
            return 1;
        }
        write(select_lang(([
            "en": "=== Current Aliases ===\n",
            "zh-TW": "=== 目前的別名 ===\n",
            "zh-CN": "=== 目前的别名 ===\n"
        ])));
        for (int i = 0; i < sizeof(ks); i++) {
            write("  " + ks[i] + "  ->  " + al[ks[i]] + "\n");
        }
        return 1;
    }

    int sp = strsrch(arg, " ");
    if (sp < 0) {
        if (!undefinedp(al[arg])) {
            write("alias " + arg + "  ->  " + al[arg] + "\n");
        } else {
            write(select_lang(([
                "en": "No alias named '" + arg + "'.\n",
                "zh-TW": "沒有叫「" + arg + "」的別名。\n",
                "zh-CN": "没有叫「" + arg + "」的别名。\n"
            ])));
        }
        return 1;
    }

    string alias_name = trim(substr(arg, 0, sp));
    string alias_cmd  = trim(substr(arg, sp + 1, strlen(arg) - sp - 1));

    if (alias_name == "quit" || alias_name == "alias" || alias_name == "unalias") {
        write(select_lang(([
            "en": "'" + alias_name + "' is a reserved command and cannot be set as an alias.\n",
            "zh-TW": "「" + alias_name + "」是系統保留指令，無法設定為別名。\n",
            "zh-CN": "「" + alias_name + "」是系统保留指令，无法设定为别名。\n"
        ])));
        return 1;
    }

    me->set_alias(alias_name, alias_cmd);
    me->do_save();
    write(select_lang(([
        "en": "Alias set: ", "zh-TW": "別名設定：", "zh-CN": "别名设定："
    ])) + alias_name + "  ->  " + alias_cmd + "\n");
    return 1;
}

int do_unalias(object me, string arg) {
    mapping al = me->query_aliases();
    if (!arg || arg == "") {
        write(select_lang(([
            "en": "Usage: unalias <alias name>\n",
            "zh-TW": "用法：unalias <別名名稱>\n",
            "zh-CN": "用法：unalias <别名名称>\n"
        ])));
        return 1;
    }

    arg = trim(arg);
    if (!mapp(al) || undefinedp(al[arg])) {
        write(select_lang(([
            "en": "No alias named '" + arg + "'.\n",
            "zh-TW": "沒有叫「" + arg + "」的別名。\n",
            "zh-CN": "没有叫「" + arg + "」的别名。\n"
        ])));
        return 1;
    }

    me->remove_alias(arg);
    me->do_save();
    write(select_lang(([
        "en": "Alias '" + arg + "' has been deleted.\n",
        "zh-TW": "別名「" + arg + "」已刪除。\n",
        "zh-CN": "别名「" + arg + "」已删除。\n"
    ])));
    return 1;
}

int main(object me, string verb, string arg) {
    if (verb == "unalias") return do_unalias(me, arg);
    return do_alias(me, arg);
}

string help() {
    return select_lang(([
        "en":    "【Alias】alias [name [cmd]] / unalias <name>\n",
        "zh-TW": "【別名指令】alias [名稱 [指令]] / unalias <名稱>\n",
        "zh-CN": "【别名指令】alias [名称 [指令]] / unalias <名称>\n"
    ]));
}
