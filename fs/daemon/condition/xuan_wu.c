#include <ansi.h>
int i;

int update_condition(object me,int duration)
{
	if( duration >= 1 )
	{
		tell_object(me,HIB"\n丹田氣如龜息!!漸緩待滯...\n"NOR);

		if( me->query("/open/forest/clear_xuan_wu") )
		{
			me->delete("/open/forest/clear_xuan_wu");
			me->clear_condition("xuan_wu");
			tell_object(me,HIC"魄殼之術產生效用，一股真氣直抵丹田，衝破龜息!!\n\n"NOR);
		}

		else 
		{
			tell_object(me,HIB"你意識漸漸失去，身體不受控制...\n\n"NOR);
			i = random(3)+1;
			me->start_busy(i);
		}
	}

		if( duration < 1 )
			return 0;
	return 1;
}
