// mudlib/cmds/cmd_nickname.c
// 玩家改名指令模組：nickname / nick

void cmd_nickname_setup() {
    add_action("do_nickname", "nickname");
    add_action("do_nickname", "nick"); // 提供縮寫
}

int do_nickname(string arg) {
    object me = this_player();

    if (!arg || arg == "") {
        write("目前的暱稱是：" + me->query_name() + "\n");
        write("用法：nickname <新暱稱>\n");
        return 1;
    }

    // 更新暱稱
    me->set_nickname(arg);
    me->save(); // 立即存檔，確保重登不遺失

    write("您的暱稱已成功更改為：「" + arg + "」。\n");
    return 1;
}
