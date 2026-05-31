#include <ansi.h>

int update_condition(object me, int duration)
{
        if(duration==0)
        {
                me->add_temp("apply/damage",-1*me->query_temp("bellup_buf"));
                me->add_temp("apply/attack",-1*me->query_temp("bellup_buf"));
                me->add_temp("apply/dodge",-2*me->query_temp("bellup_buf"));
                me->delete("bellup");
                message_vision(
                HIC "$N身上的殺氣消失了﹐臉色也變得比較溫和。\n" NOR,me);
                return 0;
        }
        me->apply_condition("bell",duration-1);
        message_vision(
        HIR "$N殺氣騰騰﹐激起四周的氣流﹐產生一股狂風。\n" NOR,me);
        if( duration < 1 ) return 0;
        return 1;
}
