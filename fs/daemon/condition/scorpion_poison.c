#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration< 1) 
     {  
     message_vision(YEL"$N身上的蠍毒狀況慢慢減緩了。\n"NOR,me);
     me->delete_temp("no_roar");
     return 0;
     }
     me->set_temp("no_roar",1);
     me->apply_condition("scorpion_poison",duration-1);
     message_vision(YEL"蠍毒在$N身上發作了，讓$N一句話也說不出來。\n"NOR,me);
     if( duration < 1 )
     return 0;
     return 1;
}
