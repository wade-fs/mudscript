// mudlib/cmds/cmd_quit.c
// 離開指令守護進程：quit / exit

int main(object me, string arg) {
    me->save();
    write("存檔完畢，下次見。\n");
    write("再見，" + me->query_name() + "！你化為一道光消逝了...\n");
    say(me->query_name() + " 離開了遊戲。\n");
    destruct(me);
    return 1;
}

string help() {
    return "【離開指令】\n" +
           "  用法：quit 或 exit\n" +
           "  功能：儲存角色資料並安全地登出遊戲。\n";
}
