#include <ansi.h>
int poison(object me);

int update_condition(object me, int duration)
{
  if(duration==0) {    
    if(poison(me))
    {
      message_vision(HIG + "$N中的蛇毒發作了！\n" + NOR,me);
    }
    me->delete_temp("poison/snake_poison");
    return 0;
  }
  me->receive_damage("kee", 30);
  me->receive_damage("sen", 30);
  me->start_busy(2);

  me->apply_condition("snake_poison", duration - 1);
  message_vision(HIG + "$N中的蛇毒發作了！\n" + NOR,me);
  if( duration < 1 ) return 0;
  return 1;
}
int poison(object me)
{
  if(!userp(me) && me->is_fighting()) // 非 npc 才有這種發作的機會
  {
    object *obs;
    int kee,force;
    kee = me->query("suck"); 
    obs  = me->query_temp("poison/snake_poison") ;
    if(sizeof(obs)){ // 有人灑才會中
      obs -= ({ 0 });
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
