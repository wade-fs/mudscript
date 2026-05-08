void cmd_promote_setup() {
	write("Add promote command\n");
	add_action("do_promote", "promote");
}

int do_promote(string arg) {
    object user;
	object me = this_player();

    if (me->query_role() != "god") {
        write("只有 god 可以提升權限。\n");
        return 1;
    }

    if (!arg) {
        write("promote <user>\n");
        return 1;
    }

    user = find_player(arg);

    if (!user) {
        write("玩家不存在。\n");
        return 1;
    }

    if (user == me) {
        write("不能修改自己的權限。\n");
        return 1;
    }

    user->set_role("wizard");

    user->save();

    write("已提升" + user->get_id() + "為 wizard。\n");

    return 1;
}
