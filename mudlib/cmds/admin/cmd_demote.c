// mudlib/cmds/admin/cmd_demote.c

int main(object me, string arg) {
    if (me->query_role() != "god") {
        write("只有 god 可以降低權限。\n");
        return 1;
    }

    if (!arg || arg == "") {
        write("demote <user>\n");
        return 1;
    }

    object user = find_player(arg);
    if (!user) {
        write("玩家不存在。\n");
        return 1;
    }

    if (user == me) {
        write("不能修改自己的權限。\n");
        return 1;
    }

    user->set_role("user");
    user->save();

    write("已將 " + user->get_id() + " 降級為 user。\n");
    tell_object(user, "您的權限已被降級為 user。\n");
    return 1;
}
