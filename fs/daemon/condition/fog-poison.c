#include <ansi.h>
int update_condition(object me, int duration)
{
if( duration == 0 )
return 0;
  if( duration >= 1 )
  {
     tell_object(me,HIB + "你的突然感覺到精氣不足、氣血失調、奇精八脈受創，顯然毒蛙之毒出現效應了!!\n" + NOR);
     message_vision(HIR + "$N突然倒地不起, 猛然狂吐鮮血, 奇經八脈受到阻塞, 頓時無法動彈!!\n" + NOR,me);
     me->receive_wound("gin",me->query("eff_gin")/10);
     me->receive_wound("kee",me->query("eff_kee")/10);
     me->receive_wound("sen",me->query("eff_sen")/10);
     COMBAT_D->report_status(me, 1);
     me->start_busy(1);
     me->apply_condition("fog-poison", duration - 1);
  return 1;
  }
        if( duration < 1 ) 
        return 0;
return 1;
}
