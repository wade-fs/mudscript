#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==1) 
     {  
     message_vision(HIM + "$N身上毒龍精元的效力已經消失!!\n" + NOR,me);
     if(me->query_temp("p-pill")) {
     me->add_temp("apply/magic",-50);
     me->add_temp("apply/spells",-50);
     }
     me->delete_temp("p-pill",1);
     return 0;
     }
     me->apply_condition("poison_pill",duration-1);
     message_vision(HIM + "毒龍精元的效力慢慢在$N身上蔓延!!\n" + NOR,me);
     if( duration < 1 )
     return 0;
     return 1;
}
