#include <ansi.h>
int i,j;

int update_condition(object me,int duration)
{
	if( duration >= 1 )
	{
		int i = (int)me->query("kee");
		int j = (int)me->query("eff_kee");

		tell_object(me,HIW + "\n虎咬之氣亂竄於眼、耳、口、鼻四靈孔!!\n" + NOR);

		if( me->query("/open/forest/clear_white_tiger") )
		{
			me->delete("/open/forest/clear_white_tiger");
			me->clear_condition("white_tiger");
			tell_object(me,HIC + "眠花催發，一股浩瀚之氣穩住虎咬的亂竄!!\n\n" + NOR);
		}
			
		else 
		{
			if( i >= j )
			{
				tell_object(me,HIW + "你霎時疼痛不已!!痛苦不堪!!\n\n" + NOR);
				me->add("kee",-j/10);
			}
			else
			{
				if ( i > j/15 )
				{
					tell_object(me,HIW + "氣力不斷的流逝...\n\n" + NOR);
					me->add("kee", -j/15);
				}
				else
				{
					tell_object(me,HIW + "你霎時全身顫抖!!汗如雨下!!生死相隔一線間!!\n\n" + NOR);
					me->set("kee",1);
				}
			}
		}
	}

		if( duration < 1 )
			return 0;
	return 1;
}
