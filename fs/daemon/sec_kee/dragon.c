// gather.c
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
int msk=me->query("max_s_kee",1);
if(msk > 500) msk=500;
     if(me->query("s_kee")*5<me->query("max_s_kee"))
      {
          tell_object(me,"你的靈氣不夠。\n");
          return 1;
      }
 if(!me->is_fighting())
  return notify_fail("青龍之氣戰鬥中才能使用!!!。\n");
 if(!target->is_fighting())
  return notify_fail("對方並不是在處於戰鬥之中，所以無法使用青龍之氣!!!\n");
 if(target->query_temp("dragon")==1) {
 tell_object(me,"敵人已中青龍，不能再用。\n");
 return 1; }
      message_vision(
         HIG + "$N靈氣浮現﹐只見一條青龍從你體內衝出﹗\n" NOR,me);
         message_vision(  CYN "結果$N的青龍之氣貫穿$n的身體。\n" NOR,me,target);
target->receive_damage("kee",5*me->query("max_s_kee"));
        target->set_temp("dragon",1);
        target->apply_condition("dragon_out",me->query("max_s_kee")/10);
				target->set_temp("dragon_power",me->query("max_s_kee"));
      COMBAT_D->report_status(target);
      me->set("s_kee",0);
      me->kill_ob(target);
        return 1;
}
