// no_power for sinswordkee
#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power_bsword",1);
     message_vision(HIR + "幻魔血斷的後勁仍在$N身上遊蕩。\n" + NOR,me);
     me->set_temp("no_power_bsword",1);
     me->apply_condition("no_power_bsword",duration-1);
 if (duration < 1) {
     me->delete_temp("no_power_bsword",1);
     message_vision(HIW + "$N憑著一身修為，卸掉身上幻魔血斷的殺勁。\n" + NOR,me);
     return 0;
   }
        return 1;
}
