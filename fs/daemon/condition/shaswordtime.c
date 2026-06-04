#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) me->delete_temp("shaswordtime",1);
     message_vision(HIR + "$N覺得時間一分一妙的逼近。\n" + NOR,me);
     me->apply_condition("shaswordtime",duration-1);
 if (duration < 1) {
     me->delete_temp("shaswordtime",1);
     message_vision(HIW + "李夢枕正招換$N。\n" + NOR,me);
     me->move("/open/gsword/room2/lee2.c");
     return 0;
   }
    return 1;
}
