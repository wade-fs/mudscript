void cmd_demote_setup() {                                              
	write("Add demote command\n");
    add_action("do_demote", "demote");                                   
}                                                                    
                                                                     
int do_demote(string arg) {
    object user;
    object me = this_player();

    if (me->query_role() != "god") {
        write("只有 god 可以降級。\n");
        return 1;
    }

    if (!arg) {
        write("demote <user>\n");
        return 1;
    }

    user = find_player(arg);

    if (!user) {
        write("玩家不存在。\n");
        return 1;
    }

    if (user == me) {
        write("不能降級自己。\n");
        return 1;
    }

    user->set_role("user");

    user->remove_write_path("/");

    user->save();

    write("已降級為 user。\n");

    return 1;
}
