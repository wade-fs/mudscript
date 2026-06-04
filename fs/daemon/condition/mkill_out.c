#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) 
        {
	me->delete_temp("mkill");
	return 0;
        }
        if( !living(me) ) 
        {
	message("vision", me->name() + "被魔氣所帶來的恐懼感嚇死了!!\n",
	environment(me), me);
	return 0;
        }
        else 
        {        
	me->start_busy(1);
    me->add("gin",-(10*duration));
    me->add("sen",-(10*duration));
  	me->apply_condition("mkill_out",duration-1);
      	message_vision(
              	      HIM + "$N被地獄般的魔氣籠罩﹐全身神經似乎都被麻斃了！。\n" + NOR,me);
        }
        return 1;
}

