#include <ansi.h>
int update_condition(object me, int duration,int j)
{
mixed enemy;
enemy = all_inventory( environment(me) );
        if(duration==0) return 0;
        if(me->query_temp("crazy")) 
        {
          if( environment(me)->query("no_kill") || environment(me)->query("no_fight") ) return 0;
          message_vision(HIG"$N陷入野蠻的原始獸性之中，對四周所有活物展開瘋狂殺戮。\n" NOR,me);
          for(j=0;j < sizeof(enemy);j++)
          {       
            if (enemy[j]->is_character() && !enemy[j]->is_corpse() && enemy[j]->query("id") != "judge ice"
             && living(enemy[j]) && enemy[j]!=me) 
            {
            me->kill_ob(enemy[j]);
            enemy[j]->kill_ob(me);
            }
          }
          me->receive_curing("kee",2000);
          me->receive_curing("sen",2000);
          me->receive_curing("gin",2000);
          me->receive_heal("kee",2000);
          me->receive_heal("gin",2000);
          me->receive_heal("sen",2000);
          if(me->query("force") < 2*me->query("max_force"))
          me->set("force",2*me->query("max_force"));
        }
        me->apply_condition("crazy",duration-1);
        if( duration < 1 ) return 0;
        return 1;

}
