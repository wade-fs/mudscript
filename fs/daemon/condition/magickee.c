#include <ansi.h>

int update_condition(object me, int duration)
{
        if(duration==0)
        {
        message_vision(
        HIR + "纏繞的靈光漸漸散去，$N似乎看起來好多了!!\n" + NOR,me);
        return 0;
        }
        me->apply_condition("magickee",duration-1);
        message_vision(HIY + "$N被數道靈光所纏繞掙脫不開，正痛苦的不能自己!!\n" + NOR,me);
        me->start_busy(1);
        me->receive_wound("sen",10);
        me->receive_wound("kee",10);
        me->receive_wound("gin",10);
        if( duration < 1 ) return 0;
        return 1;
}

