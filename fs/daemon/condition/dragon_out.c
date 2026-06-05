// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
				if(duration==0) return 0;
				if(!userp(me) && !me->is_fighting())
				{
								me->receive_damage("kee",2 * me->query_temp("dragon_power"));
				}
				else
				{
								me->receive_damage("kee",5 * me->query_temp("dragon_power"));
				}
				me->apply_condition("dragon_out",duration-1);
				message_vision(
												HIG + "$N青龍之氣浮現，頓時內息走岔。\n" + NOR,me);
				if( duration < 1 ) return 0;
				return 1;
}
