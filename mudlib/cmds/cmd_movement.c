// mudlib/cmds/cmd_movement.c
// 移動指令模組：north / south / east / west / up / down / go

void cmd_movement_setup() {
    add_action("do_move", "north");
    add_action("do_move", "south");
    add_action("do_move", "east");
    add_action("do_move", "west");
    add_action("do_move", "up");
    add_action("do_move", "down");
    add_action("do_move", "go");
}

int do_move(string arg) {
    object here = environment(this_object());
    if (!here) {
        write("你不在任何地方。\n");
        return 1;
    }

    if (!arg || arg == "") {
        arg = query_verb();
    }

    if (arg == "go") {
        write("要往哪裡去？例如：go north\n");
        return 1;
    }

    return here->do_go(arg);
}
