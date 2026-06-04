//將receive_damage補上攻擊方的參數 by blazakira 2011/7/31

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
    return notify_fail("戰鬥中才能使用無極劍氣!!!。\n");
  if(!target->is_fighting())
    return notify_fail("對方並不是在處於戰鬥之中，所以無法使用無極劍氣!!!\n");
  message_vision(HIG + "$N大喝一聲，爆出身上無極劍氣，只見無數劍芒由$N身上射出﹗\n" + NOR,me);
  message_vision(CYN + "面對突如其來的劍陣，$N眼前一愣..已遭無數劍芒貫體而過。\n" + NOR,target);
  target->receive_damage("kee",2*me->query("max_s_kee"),me);
  COMBAT_D->report_status(target);
  me->set("s_kee",0);
  me->kill_ob(target);
  return 1;
}
