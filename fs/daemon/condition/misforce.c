#include <ansi.h>
int update_condition(object me, int duration)
{
  if(duration < 1) {
    tell_object(me, "你亂竄的氣息漸漸被你納入經脈中了 \n");
            me->delete_temp("misforce");
    return 0;
  }
  else {
        me->receive_wound("kee",me->query("kee",1)/15 );
        me->receive_wound("gin",me->query("gin",1)/15 );
        me->receive_wound("sen",me->query("sen",1)/15 );
    me->apply_condition("misforce",duration-1);
    me->start_busy(3);
     me->set("force", 0);
    tell_object(me,HIC + "你走火入魔, 內力大減, 無法動彈, 氣息大亂。\n" + NOR);
  }
  return 1;
}
