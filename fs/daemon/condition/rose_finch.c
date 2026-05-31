#include <ansi.h>
int i,j;

int update_condition(object me,int duration)
{
	if( duration >= 1 )
	{
		int i = (int)me->query("force");
		int j = (int)me->query("max_force");

		tell_object(me,HIR"\n雀焰封住你的大穴氣脈!!\n"NOR);

		if( me->query("/open/forest/clear_rose_finch") )
		{
			me->delete("/open/forest/clear_rose_finch");
			me->clear_condition("rose_finch");
			tell_object(me,HIC"體內玉泉水逆經脈而行，將雀焰所封住的氣脈都打通了!!\n\n"NOR);
		}
			
		else 
		{
			if( i >= j )
			{
				tell_object(me,HIR"你霎時真氣受損!氣力漸耗!\n\n"NOR);
				me->add("force",-j/2);
			}
			else
			{
				if ( i > j/10 )
				{
					tell_object(me,HIR"真氣運行遭受阻礙。\n\n"NOR);
					me->add("force", -j/10);
				}
				else
				{
					tell_object(me,HIR"真氣已經被全數耗盡!!\n\n"NOR);
					me->set("force",1);
				}
			}
		}
	}

		if( duration < 1 )
			return 0;
	return 1;
}
