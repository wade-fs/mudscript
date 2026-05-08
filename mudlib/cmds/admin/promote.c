int main(object me, string arg)
{
    object user;

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

    user->save_user();

    write("已提升為 wizard。\n");

    return 1;
}
