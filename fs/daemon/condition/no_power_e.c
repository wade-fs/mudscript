#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power_e",1);
     tell_object(me , "你感覺到体內有無數的氣勁亂流,使你無法正常的使用內力\n" NOR);
     me->set_temp("no_power_e",1);
     me->apply_condition("no_power_e",duration-1);
 if (duration < 1) {
     me->delete_temp("no_power_e",1);
     return 0;
                   }
        return 1;
}
