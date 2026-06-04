#include <ansi.h>
int poison(object me);
int update_condition(object me, int duration)
{
  if(duration==0) {    
    if(poison(me))
    {
      message_vision(HIR + "$N搖搖晃晃，全身火紅。\n" + NOR,me);

    }
    me->delete_temp("poison/fire_poison");
    return 0;
  }

  me->receive_wound("kee",300);
  me->apply_condition("fire_poison",duration-1);
  me->start_busy(1);
  tell_object(me,HIG + "你身上的" + HIR + "火雲邪毒" + HIG + "發作了﹗\n" + NOR);
  message_vision(HIR + "$N搖搖晃晃，全身火紅。\n" + NOR,me);

  if( duration < 1 ) return 0;
  return 1;
}
int poison(object me)
{
  if(!userp(me) && me->is_fighting()) // 非 npc 才有這種發作的機會
  {
    object *obs;
    obs  = me->query_temp("poison/fire_poison") ;
    if(sizeof(obs)){ // 有人灑才會中
        obs -=  ({ 0 });

      foreach(object ob in obs)
      {
        if(!me->is_fighting(ob)) continue;

        me->start_busy(1);
      }
      return 1;

    }
  }
  return 0;
}
