#include <ansi.h>
int poison(object me);
int update_condition(object me, int duration)
{
  int fun=me->query("suck");
  if(duration==0) {
    if(poison(me))
    {
      tell_object(me, HIG "你中的" HIR "火玫瑰毒" HIG "發作了﹗\n" NOR );
      message_vision("$N身上浮現出玫瑰花紋，渾身通紅。\n"NOR,me);

    }
    me->delete("suck");
    me->delete_temp("poison/rose_poison");
    return 0; 
  }
  if(userp(me))
  {
    me->receive_wound("kee",50+(fun*5));
    me->receive_wound("sen",50+(fun*2));

    me->start_busy(1);
  }
  else{
    poison(me);
  }
  me->receive_wound("kee",50+fun);
  me->receive_wound("sen",50+fun);

  me->start_busy(1);
  me->apply_condition("rose_poison", duration - 1);
  tell_object(me, HIG "你中的" HIR "火玫瑰毒" HIG "發作了﹗\n" NOR );
  message_vision("$N身上浮現出玫瑰花紋，渾身通紅。\n"NOR,me);
  if( duration < 1 ) return 0;
  return 1;
}
int poison(object me)
{
  if(!userp(me) && me->is_fighting()) // 非 npc 才有這種發作的機會
  {
    object *obs,user;
    int kee,force;
    kee = me->query("suck"); 
    obs  = me->query_temp("poison/rose_poison") ;
    if(sizeof(obs)){ // 有人灑才會中
       obs -=  ({ 0 });

      foreach(object ob in obs)
      {
        if(!me->is_fighting(ob)) continue;

        kee += me->query("suck")*5;
        user = ob;
      }
      if(kee > 12000) kee = 12000; // 設最大值
      me->receive_wound("kee",kee,user);
      me->receive_wound("sen",kee*10/15);
      me->start_busy(1);
      return 1;

    }
  }
  return 0;
}
