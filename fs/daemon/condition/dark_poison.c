#include <ansi.h>
int poison(object me);
int update_condition(object me, int duration)
{
  int fun=me->query("suck");
  if(duration==0) {
    if(poison(me))
    {
      tell_object(me,HIC "你中了深宮奇毒﹐現在毒性開始發作﹗\n" NOR);
      message("vision",HIC+me->name()+"眉心逐漸變黑﹐似乎毒性已經發作了﹗\n" NOR,environment(me),me);

    }
    me->delete("suck");
    me->delete_temp("poison/dark_poison");
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

  me->apply_condition("dark_poison",duration-1);
  tell_object(me,HIC "你中了深宮奇毒﹐現在毒性開始發作﹗\n" NOR);
  message("vision",HIC+me->name()+"眉心逐漸變黑﹐似乎毒性已經發作了﹗\n" NOR,environment(me),me);
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
    obs  = me->query_temp("poison/dark_poison") ;
    if(sizeof(obs)){ // 有人灑才會中
      obs -= ({ 0 });
      foreach(object ob in obs)
      {
        if(!me->is_fighting(ob)) continue;

        kee += me->query("suck")*10;
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
