#include <ansi.h>

int update_condition(object me, int duration)
{
    if(duration==0)
    {
     message_vision(
     HIC "雷電之氣"+HIW"漸漸從$N體內散出，$N感覺通體舒暢。\n" NOR,me);
     return 0;
    }
    me->apply_condition("thunder",duration-1);
    message_vision(
    HIC "雷電之氣"+HIY"在$N體內發作，沿著$N的筋脈亂竄，使$N遭受一次又一次的"+HIC"電擊。\n" NOR,me);
    me->start_busy(1);
    me->receive_wound("kee",75);
    me->receive_wound("gin",30);
    me->receive_wound("sen",20);
    if( duration < 1 ) return 0;
    return 1;
}

