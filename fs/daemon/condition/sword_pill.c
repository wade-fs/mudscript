#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==1) 
     {  
     message_vision(HIY + "$N身上黃龍精元的效力已經消失!!\n" + NOR,me);
     if(me->query_temp("y-pill")) {
     me->add_temp("apply/stabber",-50);
     me->add_temp("apply/sword",-50);
     }
     me->delete_temp("y-pill");
     return 0;
     }
     me->apply_condition("sword_pill",duration-1);
     message_vision(HIY + "黃龍精元的效力慢慢在$N身上蔓延!!\n" + NOR,me);
     if( duration < 1 )
     return 0;
     return 1;
}
