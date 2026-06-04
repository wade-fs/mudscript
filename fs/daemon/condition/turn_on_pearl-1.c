#include <ansi.h>

int update_condition(object me, int duration)
{
	if(duration > 0)
	{
		if(me->query_temp("turn_on/pearl-1"))
		{
			if(random(100)<50)
			{
				me->add("combat_exp",1);
				message_vision(YEL + "圍繞在$N身旁的土靈。焚天珠發出淡淡黃光...\n" + NOR,this_player());
				tell_object(me,"(土靈。焚天珠增加了你的經驗值)\n");
				return 1;
			}
			else
				return 1;
		}
		else
			return 0;
	}
return 0;
}
