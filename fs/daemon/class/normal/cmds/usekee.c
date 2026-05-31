// fight.c

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{
	object obj, old_target;
        seteuid(getuid());
	if(!me->is_fighting())
            return notify_fail("只有戰鬥中才能用。\n");
          if(!me->query("sec_kee"))
                return notify_fail("你的身上沒有靈氣。\n");
	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("這裡禁止戰鬥。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻擊誰﹖\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一點﹐那並不是生物。\n");


	if(wizardp(me)&&!wizardp(obj)&&wizhood(me)!="(manager)"&&wizhood(me)!="(admin)"&&wizhood(me)!="(arch)")
		return notify_fail("巫師不能對玩者使用靈氣。\n");

	if(obj==me)	return notify_fail("你不能攻擊自己。\n");
	SEC_KEE_D(me->query("sec_kee"))->kee_out(me,obj);
	return 1;
}
 
int help(object me)
{
   write(@HELP
 
指令格式﹕usekee <目標物>
 
說明﹕用這個指令可以讓你使用靈氣的戰鬥功能。
 
HELP
   );
   return 1;
}
