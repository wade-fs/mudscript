// no_power for godsub
#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("no_power_godsub",1);
     message_vision(HIR"$N利用身上劍聖之氣，淡化分身歸竅所造成的影響。\n"NOR,me);
     me->set_temp("no_power_godsub",1);
     me->add("kee",-200);
     me->add("force",-300);
     me->apply_condition("no_power_godsub",duration-1);
 if (duration < 1) {
     me->delete_temp("no_power_godsub",1);
     message_vision(HIW"$N運起渾身無極劍氣，完全消除分身歸竅的負荷。\n"NOR,me);
     return 0;
   }
        return 1;
}
