// gather.c
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
int msk=me->query("max_s_kee",1);
if(msk > 500) msk=500;
     if(me->query("s_kee")<10)
      {
          tell_object(me,"你的靈氣不夠。\n");
          return 1;
      }
        if(me->query("class") != "marksman")
        {
         tell_object(me,"你不是射手根本無法駕御心中之火凰靈氣!!!\n");
                return 1;
        }

 if(!me->is_fighting())
  return notify_fail("火凰靈氣戰鬥中才能使用!!!。\n");
 if(!target->is_fighting())
  return notify_fail("對方並不是在處於戰鬥之中，所以無法使用火凰靈氣!!!\n");
 if(target->query_temp("phoenix")==2) {
 tell_object(me,"敵人已被火鳳靈氣纏繞，無法在動了。\n");
 return 1; }
      message_vision(
         HIC + "$N口中緩緩唸出一串真言，只見一隻火鳳凰迅速破空降下﹗\n" NOR,me);
         message_vision(  HIR "火鳳凰迅速飛向$n，並隱入$N的體內。\n" NOR,me,target);
        target->receive_damage("kee",me->query("max_atman")/5);
        target->start_busy(1);
        target->add_temp("phoenix",1);
        target->apply_condition("phoenix_out",me->query("max_s_kee")/10);
      COMBAT_D->report_status(target);
      me->add("s_kee",-10);
      me->kill_ob(target);
        return 1;
}
