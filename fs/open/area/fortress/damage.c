#include <ansi.h>

int valid_leave(object me,string dir)
{
        if( random(100) < 30 )
        {
	        me->receive_damage("gin", (int)me->query("gin")/7 );
	        me->receive_damage("kee", (int)me->query("kee")/7 );
	        me->receive_damage("sen", (int)me->query("sen")/7 );
	        message_vision(HIR"	<<惡毒沼氣突然噴出，$N身體漸漸感到不適！！>>\n"NOR,me);
	        COMBAT_D->report_status(me);
        }
return 1;
}
