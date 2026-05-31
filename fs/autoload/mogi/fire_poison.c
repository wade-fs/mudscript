#include <ansi.h>
int update_condition(object me, int duration)
{
        if(duration==0) return 0;
 me->receive_wound("kee",300);
	me->apply_condition("fire_poison",duration-1);
	me->start_busy(1);
	tell_object(me,HIG "你身上的" HIR "火雲邪毒" HIG "發作了﹗\n" NOR);
	message("vision",HIR+me->name()+"搖搖晃晃，全身火紅。\n"NOR,environment(me),me);
	if( duration < 1 ) return 0;
	return 1;
}
