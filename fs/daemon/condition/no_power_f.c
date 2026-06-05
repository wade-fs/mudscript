#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power_f",1);
     tell_object(me , "你被身旁的龍捲氣勁所阻，因此你無法以自由使用絕招\n" + NOR);
     me->set_temp("no_power_f",1);
     me->apply_condition("no_power_f",duration-1);
 if (duration < 1) {
     me->delete_temp("no_power_f",1);
     return 0;
                   }
        return 1;
}
