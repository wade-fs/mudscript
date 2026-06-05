// gather.c 
#include <combat.h> 
#include <ansi.h>
inherit SSERVER; 
int kee_out(object me,object target)
{
 if(!me->is_fighting())
  return notify_fail("雷虎之氣戰鬥中才能使用!!!。\n");
 if(!target->is_fighting())
  return notify_fail("對方並不是在處於戰鬥之中，所以無法使用雷虎之氣!!!\n");
        if(me->query("max_s_kee")<20)
     {
          tell_object(me,"你的靈氣修練不夠。\n");
             return 1;
     }
if(me->query("s_kee") < 20 )
{ tell_object(me,"你沒足夠的靈氣！\n");
  return 1; }
 if(target->query_temp("tiger")==1) {
 tell_object(me,"敵人已中雷虎，不能再用。\n");
 return 1; }
     message_vision(
          HIY + "$N的靈氣浮動﹐雷虎之氣騰出﹗\n" + NOR,me);
       message_vision(
          CYN + "$n被雷虎之氣纏住﹐不能動彈。\n" + NOR,me,target);
        target->start_busy(2);
        target->set_temp("tiger",1);
        target->apply_condition("tiger_out",me->query("max_s_kee")/20);
        me->kill_ob(target);
        me->set("s_kee",0);
     return 1;
 
}

