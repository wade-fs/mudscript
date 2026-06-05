// no_power for sinswordkee
#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power_sword",1);
     message_vision(HIR + "涅盤殺禪劍的後勁仍在$N身上遊蕩。\n" + NOR,me);
     me->set_temp("no_power_sword",1);
     me->apply_condition("no_power_sword",duration-1);
 if (duration < 1) {
     me->delete_temp("no_power_sword",1);
     message_vision(HIW + "$N憑著一身修為，卸掉身上涅盤殺禪劍的殺勁。\n" + NOR,me);
     return 0;
   }
        return 1;
}
