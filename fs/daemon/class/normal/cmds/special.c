// special.c

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{
	object obj, old_target;
        seteuid(getuid());
          if(!me->query("sec_kee"))
                return notify_fail("你的身上沒有靈氣。\n");
	SEC_KEE_D(me->query("sec_kee"))->kee_spe(me);
	return 1;
}
 
int help(object me)
{
    write(@HELP
 
指令格式﹕special
 
說明﹕這個指令讓你可以使用靈氣的特殊功能。
 
HELP
);
     return 1;
}
