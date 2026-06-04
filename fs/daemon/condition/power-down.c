#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==0) 
     {  
     message_vision(HIW + "$N的力量漸漸復原, 功\力慢慢恢復!!\n" + NOR,me);
     me->delete_temp("power-down");
     return 0;
     }
     me->apply_condition("power-down",duration-1);
     message_vision(HIW + "$N的力量漸漸復原, 但是仍然無法使出全力!!\n" + NOR,me);
     me->set_temp("power-down",me->query_condition("power-down"));
     if( duration < 1 )
     return 0;
     return 1;
}

