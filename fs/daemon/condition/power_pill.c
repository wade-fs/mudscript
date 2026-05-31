#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==1) 
     {  
     message_vision(HIC"$N身上藍龍精元的效力已經消失!!\n"NOR,me);
     if(me->query_temp("b-pill"))
     me->add_temp("apply/force",-25);
     me->delete_temp("b-pill");
     return 0;
     }
     me->apply_condition("power_pill",duration-1);
     message_vision(HIC"藍龍精元的效力慢慢在$N身上蔓延!!\n"NOR,me);
     if( duration < 1 )
     return 0;
     return 1;
}
