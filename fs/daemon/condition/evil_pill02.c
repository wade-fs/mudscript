#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		message_vision(HIY + "\n$N不斷的從口中吐出許\多大大小小的惡蠱蟲～～\n\n" + NOR,me);
		me->delete_temp("evil_no_enemy");
		tell_object(me,HIW + "你感覺輕鬆多了。\n" + NOR);
		return 0;
	}
	if( duration >= 3 )
	{
		if( !me->query_temp("evil_no_enemy") )
		{
			me->set_temp("evil_no_enemy",1);
			tell_object(me,HIW + "\n肚子突然一陣疼痛，吞食入腹的惡蠱卵似乎開始產生作用。\n\n" + NOR);
		}
		else
			tell_object(me,HIR + "\n陣痛不斷的從你的腹部傳至於全身，你痛的無法動彈。\n\n" + NOR);
		me->start_busy(3);
		COMBAT_D->report_status(me,1);
		me->apply_condition("evil_pill02", duration - 1);
  		return 1;
	}
	if( duration >= 1 )
	{
		tell_object(me,HIY + "\n陣痛似乎減輕了不少，可是你的身體還是無法活動自如。\n\n" + NOR);
		me->start_busy(2);
		COMBAT_D->report_status(me, 1);
		me->apply_condition("evil_pill02", duration - 1);
  		return 1;
	}
        if( duration < 1 ) 
        return 0;
return 1;
}
