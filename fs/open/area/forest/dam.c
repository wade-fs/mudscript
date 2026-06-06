#include <ansi.h>

int valid_leave(object me,string dir)
{
int i=10;
	if( random(i) < 7 )
	{
	me->receive_damage("gin", (int)me->query("gin")/7 );
	me->receive_damage("kee", (int)me->query("kee")/7 );
	me->receive_damage("sen", (int)me->query("sen")/7 );
	}
return 1;
}
