// spring.c by oda

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration==0 ) return 0;
        if( !living(me) ) {
                message("vision", me->name()+"似乎受不了慾火焚身的煎熬，精盡而亡了。\n", environment(me), me);
        } else if( duration > 5 ) {
                tell_object(me, HIG + "你覺得全身燥熱無比，慾火難耐。\n" + NOR);
                message("vision", me->name()+"看起來似乎坐立難安，極度飢渴的樣子。\n", environment(me), me);
		me->receive_damage("gin",20);
		if( (int)me->query("water")==0 ) {
			tell_object(me, "你感到口乾舌燥，最好趕快喝水。\n");
		}
		if( (int)me->query("water")>=50 )
			me->add("water", -50);
		else
			me->set("water", 0);
	} else if( duration > 0 ) {
                tell_object(me, HIG + "你仍覺得口渴無比，不過慾火似乎漸漸消退了。\n" + NOR);
                message("vision", me->name()+"全身青筋浮現，滿頭大汗。\n",
                        environment(me), me);
		me->receive_damage("gin", 10);
		if( (int)me->query("water")==0 ) {
			tell_object(me, "你感到口乾舌燥，最好趕快喝水。\n");
		}
		if( (int)me->query("water")>=30 )
			me->add("water", -30);
		else
			me->set("water", 0);
        }
        me->apply_condition("spring", duration-1);
        if( duration < 0)
                return 0;
        return 1;
}
