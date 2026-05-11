// mudlib/cmds/cmd_alias.c
// 別名指令守護進程：alias / unalias

int main(object me, string arg) {
    string verb = query_verb();
    
    if (verb == "alias") {
        return do_alias(me, arg);
    }
    
    if (verb == "unalias") {
        return do_unalias(me, arg);
    }
    
    return 0;
}

int do_alias(object me, string arg) {
    mapping al = me->query_aliases(); // 向玩家取得他的別名表

    if (!arg || arg == "") {
        mixed ks = keys(al);
        if (!ks || sizeof(ks) == 0) {
            write("你沒有設定任何別名。\n");
            return 1;
        }
        write("=== 目前的別名 ===\n");
        int i;
        for (i = 0; i < sizeof(ks); i++) {
            write("  " + ks[i] + "  ->  " + al[ks[i]] + "\n");
        }
        return 1;
    }

    int sp = strsrch(arg, " ");
    if (sp < 0) {
        mixed ks2 = keys(al);
        if (member_array(arg, ks2) >= 0) {
            write("alias " + arg + "  ->  " + al[arg] + "\n");
        } else {
            write("沒有叫「" + arg + "」的別名。\n");
        }
        return 1;
    }

    string alias_name = substr(arg, 0, sp);
    string alias_cmd  = substr(arg, sp + 1, strlen(arg) - sp - 1);

    if (alias_name == "quit" || alias_name == "alias" || alias_name == "unalias") {
        write("「" + alias_name + "」是系統保留指令，無法設定為別名。\n");
        return 1;
    }

    // 呼叫玩家的介面寫入資料
    me->set_alias(alias_name, alias_cmd);
    me->save(); // 立即存檔
    write("別名設定：" + alias_name + "  ->  " + alias_cmd + "\n");
    return 1;
}

int do_unalias(object me, string arg) {
    mapping al = me->query_aliases();

    if (!arg || arg == "") {
        write("用法：unalias <別名名稱>\n");
        return 1;
    }

    mixed ks = keys(al);
    if (member_array(arg, ks) < 0) {
        write("沒有叫「" + arg + "」的別名。\n");
        return 1;
    }

    me->remove_alias(arg);
    me->save(); // 立即存檔
    write("別名「" + arg + "」已刪除。\n");
    return 1;
}

string help() {
    return "【別名指令】\n" +
           "  alias                  列出所有別名\n" +
           "  alias <名稱> <指令>    設定別名，例如：alias n north\n" +
           "  alias <名稱>           查看指定別名\n" +
           "  unalias <名稱>         刪除別名\n";
}
