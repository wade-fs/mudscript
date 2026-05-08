void cmd_grant_setup() {
	write("Add grant command\n");
	add_action("do_grant", "grant");
}

int do_grant(string arg) {
    string user_name;
    string path;

    object user;
	object me = this_player();

    if (!arg || sscanf(arg, "%s %s", user_name, path) != 2) {
        write("grant <user> <path>\n");
        return 1;
    }

    user = find_player(user_name);

    if (!user) {
        write("玩家不存在。\n");
        return 1;
    }

    if (!valid_grant(me, path)) {
        write("你不能授權這個目錄。\n");
        return 1;
    }

    user->add_write_path(path);

    user->save();

    write("授權完成。\n");

    return 1;
}

int valid_grant(object me, string path)
{
    if (me->query_role() == "god")
        return 1;

    return me->has_write_access(path);
}

