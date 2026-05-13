// mudlib/cmds/cmd_nickname.c
// 玩家改名指令守護進程：nickname / nick

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("目前的暱稱是：" + me->query_name() + "\n");
        write("用法：nickname <新暱稱>\n");
        return 1;
    }

    // 更新暱稱
    me->set_name(arg);
    me->save(); // 立即存檔，確保重登不遺失

    write("您的暱稱已成功更改為：「" + arg + "」。\n");
    return 1;
}
