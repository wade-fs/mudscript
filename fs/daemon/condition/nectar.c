//改錯字跟排版 by blazakira 2011/6/3

#include <ansi.h>

int update_condition(object me, int duration,int j)
{
  if(duration==0) 
  {
    message_vision(HIY + "$N身上的千年花蜜慢慢的失去效用了!!\n" + NOR,me);
    return 0;
  }
  me->apply_condition("nectar",duration-1);
  if( me->query("force") < 1000000 )
  {
    message_vision(HIY + "只見一股真氣緩緩在$N" + HIY + "周身流動散發著!!\n" + NOR,me);
    me->add("force",2000);
  }else{
    message_vision(HIY + "$N身上的千年花蜜似乎已經發揮到最大的效用了!!\n" + NOR,me);
  }
  if( duration < 1 )
    return 0;
  return 1;
}
