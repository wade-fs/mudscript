// mudlib/cmds/cmd_quit.c
// 離開指令模組：quit / exit

void cmd_quit_setup() {
    add_action("do_quit", "quit");
    add_action("do_quit", "exit");
}

int do_quit(string arg) {
    save();
    write("存檔完畢，下次見。\n");
    write("再見，" + query_name() + "！你化為一道光消逝了...\n");
    say(query_name() + " 離開了遊戲。\n");
    destruct(this_object());
    return 1;
}
