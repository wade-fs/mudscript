#include <ansi.h>

int update_condition(object me, int duration)
{
	if(duration > 0)
	{
		if(me->query_temp("turn_on/pearl-1") && random(100)<50)
		{
			me->add("combat_exp",1);
			tell_object(me,"你藉由焚天珠增加了一些經驗。\n");
			return 1;
		}
		else
			return 0;
	}
return 1;
}
