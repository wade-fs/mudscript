inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping emote;

        if( !arg ) return notify_fail("你要刪除什麼 chinese﹖\n");

        if( sscanf(arg, "-d %s", arg) ) {
                write("刪除 chinese﹕" + arg + "\n");
                CHINESE_D->remove_translate(arg);
                return 1;
        }
}

int help(object me)
{
write(@HELP

指令格式 : delchinese -d <chinese>
刪除不小心加入的chinese！

HELP
    );
    return 1;
}
