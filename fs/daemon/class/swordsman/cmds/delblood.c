#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me)
{
        string type,name,ob_name;
        object ob;
        seteuid(getuid());
        if(!me->query_temp("strike")) return notify_fail("你不需要散勁。\n");
        if(me->is_fighting() ) return notify_fail("戰鬥中無法散氣。\n");
        message_vision(HIC"$N運起身上血魔氣勁...瞬間數道血光由$N身上散出。\n"NOR,me);
        me->delete_temp("strike");
        return 1;
}

int help (object me)
{
        write(@HELP
血魔傳人在戰鬥中因使出血魔奧義而產生不適時,可用散勁將體內多餘的血氣散出體外
指令格式﹕cmd delblood
HELP
        );
        return 1;
}
