#include <ansi.h>

int update_condition(object me, int duration)
{
     if(duration==0) return 0;
        me->set("force_factor",0);
        me->apply_condition("enforce_poison", duration - 1);
        tell_object(me, HIG "你中的" HIB "十香軟筋散" HIG "發作了﹗\n" NOR );
        message("vision",HIB+me->name()+"全身虛虛浮浮，看來使不上力。\n"NOR,environment(me),me);
        if( duration < 1 ) return 0;
        return 1;
}

