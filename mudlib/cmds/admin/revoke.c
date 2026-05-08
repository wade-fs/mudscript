int valid_revoke(object me, string path)
{
    if (me->query_role() == "god")
        return 1;

    return me->has_write_access(path);
}

int main(object me, string arg)
{
    string user_name;
    string path;

    object user;

    if (!arg || sscanf(arg, "%s %s", user_name, path) != 2) {
        write("revoke <user> <path>\n");
        return 1;
    }

    user = find_player(user_name);

    if (!user) {
        write("玩家不存在。\n");
        return 1;
    }

    if (!valid_revoke(me, path)) {
        write("你不能取消這個目錄。\n");
        return 1;
    }

    user->remove_write_path(path);

    user->save_user();

    write("權限已移除。\n");

    return 1;
}
