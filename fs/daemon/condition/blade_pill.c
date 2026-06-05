#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==1) 
     {  
     message_vision(HIG + "$N身上綠龍精元的效力已經消失!!\n" + NOR,me);
     if(me->query_temp("g-pill"))
       me->add_temp("apply/blade",-50);
     me->delete_temp("g-pill");
     return 0;
     }
     me->apply_condition("blade_pill",duration-1);
     message_vision(HIG + "綠龍精元的效力慢慢在$N身上蔓延!!\n" + NOR,me);
     if( duration < 1 )
     return 0;
     return 1;
}
