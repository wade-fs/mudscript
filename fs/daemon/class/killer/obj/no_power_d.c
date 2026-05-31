#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power_d",1);
     tell_object(me ,HIG"你的視線受綠光影響，因此你無法精準的使用絕招!!\n" NOR);
     me->set_temp("no_power_d",1);
     me->apply_condition("no_power_d",duration-1);
 if (duration < 1) {
     me->delete_temp("no_power_d",1);
     return 0;
                   }
        return 1;
}
