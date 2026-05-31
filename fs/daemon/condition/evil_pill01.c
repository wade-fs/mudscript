#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		message_vision(HIY"\n$N不斷的從口中吐出許\多大大小小的骨蠱蟲～～\n\n"NOR,me);
		me->delete_temp("evil_no_damage");
		tell_object(me,HIW"你感覺舒服多了。\n"NOR);
		return 0;
	}
	if( duration >= 3 )
	{
		if( !me->query_temp("evil_no_damage") )
		{
			me->set_temp("evil_no_damage",1);
			tell_object(me,HIW"\n肚子突然一陣疼痛，吞食入腹的骨蠱蛹似乎開始產生作用。\n\n"NOR);
		}
		else
			tell_object(me,HIR"\n陣痛不斷的從你的腹部傳至於全身，你不斷的冒著冷汗。\n\n"NOR);
		me->receive_damage("gin",200);
		me->receive_damage("kee",200);
		me->receive_damage("sen",200);
		COMBAT_D->report_status(me,1);
		me->apply_condition("evil_pill01", duration - 1);
  		return 1;
	}
	if( duration >= 1 )
	{
		tell_object(me,HIY"\n陣痛似乎減輕了不少，你的臉色也漸漸地和緩了點。\n\n"NOR);
		me->receive_damage("gin",100);
		me->receive_damage("kee",100);
		me->receive_damage("sen",100);
		COMBAT_D->report_status(me, 1);
		me->apply_condition("evil_pill01", duration - 1);
  		return 1;
	}
        if( duration < 1 ) 
        return 0;
return 1;
}
