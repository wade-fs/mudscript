#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration == 0)
                return 0;
        tell_object(me,HIB"你全身狗蝨遍佈，咬得你神智不清，遍體鱗傷！\n"NOR);
        message("vision",HIG+me->query("name")+"身受狗蝨之苦，哀號不絕，神情更加憔悴了。\n"NOR,environment(me),me);
        me->receive_wound("gin",50);
        me->receive_wound("kee",100);
        me->receive_wound("sen",50);
        me->start_busy(1);
        if( me->query("force") < 0 ) me->set("force",0);
        me->apply_condition("dog",duration-1);
        if (duration < 1)
                return 0;
        return 1;
}
