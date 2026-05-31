//hellfire by funkcat
// bleeding.c
#include <combat.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{											
	if( !living(me) ) {
		message("vision", me->name() + "被地獄之業火活活燒死了!!\n",
			environment(me), me);

	} else if( duration > 6 ) {
		message("vision", me->name() + HIR"身上燃燒著詭異的黑火。\n"NOR,
			environment(me), me);
		me->receive_damage("kee",300);
		me->receive_damage("sen",300);
		me->receive_damage("gin",300);

	} else if( duration > 2 ) {
		message("vision", me->name() + "身上不斷冒出黑煙還有肌肉燃燒的臭味。\n",
			environment(me), me);
		me->receive_damage("kee",200);
		me->receive_damage("sen",200);
		me->receive_damage("gin",200);

	} else {
                tell_object(me, HIR"黑火漸漸熄滅。\n"NOR);
                message("vision", me->name() + "身上的黑色火燄漸漸熄滅。\n",
                        environment(me), me);
                me->receive_damage("kee",100);
                me->receive_damage("sen",100);
                me->receive_damage("gin",100);
	}    
	me->apply_condition("hellfire", duration - 1);
	COMBAT_D->report_status(me);
        if( duration < 1)
	 	return 0;
	return 1;
}
