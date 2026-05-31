#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me)
{
        string type,name,ob_name;
        object ob;
        seteuid(getuid());
        if(!me->query_temp("usesunsword")) return notify_fail("你不需要散勁。\n");
        if(me->is_fighting() ) return notify_fail("戰鬥中無法散氣。\n");
        message_vision(HIC"$N運起身上仙劍內功\...瞬間數道光芒由$N身上散出。\n"NOR,me);

        me->delete_temp("usesunsword");
        return 1;
}

int help (object me)
{
        write(@HELP
仙劍武者在戰鬥中因吸進太多連陽氣勁而產生不適時,可用天陽散勁將體內多餘的劍氣散出體外
指令格式﹕cmd delsunkee
HELP
        );
        return 1;
}
