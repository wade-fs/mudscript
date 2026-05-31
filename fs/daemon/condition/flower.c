#include <ansi.h>
int update_condition(object me, int duration)
{
        if(duration==0) me->delete_temp("no_power",1);
        tell_object(me , "你只覺得全身酥軟無力，提不起力道來使出招式!!\n" NOR);
        me->set_temp("no_power",1);
        me->apply_condition("flower",duration-1);
        if (duration < 1)
        {
        me->delete_temp("no_power",1);
        return 0;
        }
        return 1;
}

