#include <ansi.h>
// 加強毒教的 五毒 by swy
// 加強毒教的發作型態  by whatup
int poison(object me);

int update_condition(object me, int duration)
{
  int fun=me->query("five");
  if(duration==0) {
    if(poison(me))
    {
      message_vision( HIY "$N中了五毒神掌﹐毒性開始發作﹗\n" NOR,me);
      message_vision(HIW"$N中了五毒神掌﹐內力開始流失。\n" NOR,me);  


    }
    me->delete_temp("poison/five_poison");
    me->delete("five");
    return 0;   
  }
  if(userp(me))
  {
    me->receive_wound("kee",100+(fun*2));
    me->add("force",-(100+(fun*2)));
  }
  else if(me->is_fighting())
  {
    poison(me);
  }

  me->receive_wound("kee",100+(fun));
  me->add("force",-(100+(fun)));
  me->start_busy(1);
  me->apply_condition("five_poison",duration-1);
  message_vision( HIY "$N中了五毒神掌﹐毒性開始發作﹗\n" NOR,me);
  message_vision(HIW"$N中了五毒神掌﹐內力開始流失。\n" NOR,me);  
  if( duration < 1 ) return 0;
  return 1;
}
int poison(object me)
{
    if(!userp(me) && me->is_fighting()) // 非 npc 才有這種發作的機會
    {
      object *obs,user;
      int kee,force;
      kee = me->query("five"); 
      obs  = me->query_temp("poison/five_poison") ;
      if(sizeof(obs)){ // 有人灑才會中
        obs -=  ({ 0 });

        foreach(object ob in obs)
        {
          if(!me->is_fighting(ob)) continue;
  
          kee += me->query("five") * 10;
          user = ob;
        }
        if(kee > 12000) kee = 12000; // 設最大值
        me->receive_wound("kee",kee,user);
        me->add("force",-kee);

        me->start_busy(1);
        return 1;

      }
    }
    return 0;
}
