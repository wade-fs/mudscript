// mudlib/cmds/admin/cmd_grant.c

int main(object me, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") {
        write("權限不足。\n");
        return 1;
    }

    if (!arg || arg == "") {
        write("grant <user> <path>\n");
        return 1;
    }

    string target, path;
    int sp = strsrch(arg, " ");
    if (sp < 0) {
        write("請指定路徑。\n");
        return 1;
    }

    target = substr(arg, 0, sp);
    path = substr(arg, sp + 1, strlen(arg) - sp - 1);

    object user = find_player(target);
    if (!user) {
        write("玩家不存在。\n");
        return 1;
    }

    user->add_write_path(path);
    user->save();

    write("已授權 " + target + " 對 " + path + " 的寫入權限。\n");
    tell_object(user, "您已獲得對 " + path + " 的寫入權限。\n");
    return 1;
}
