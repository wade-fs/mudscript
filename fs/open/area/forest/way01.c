#include <ansi.h>
int valid_leave(object me,string dir)
{
        if( me->query("/area/forest/search") )
        {
        	if( random(100)<10 )
        	{
        		me->delete("/area/forest/search");
        		call_out("way01",1,me);
        	}
        	else
        		tell_object(me,HIY + "你一邊巡視著四周一邊走著，並沒有發現任何可疑的地方！\n" + NOR);
        }
return 1;
}

int way01()
{
	tell_object(this_player(),HIR + "你踏到一個鬆軟的土地，身體開始往下陷...\n" + NOR);
	this_player()->move("/open/area/underpass/u01");
}
