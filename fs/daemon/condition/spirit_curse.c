// spirit_curse by blazakira 2011/1/14

#include <ansi.h>

int update_condition(object me, int duration)
{
  int k;
  if(duration==0) return 0;
  me->apply_condition("spirit_curse",10);
  k=5;
  if(me->query_temp("curse/resist")==1) k=7; //值等於3時 已經算解除 所以不列入
  else if(me->query_temp("curse/resist")==2) k=10;
  if( me->query_temp("spirit_curse") ) {
//varargs int receive_wound(string type, int damage, object who) //object who作為傳入參數 用在last_damage_from
    me->start_busy(random(3)+2);
//    me->receive_damage("gin", (int)(me->query("max_gin")/k),me );
    me->receive_wound ("gin", (int)(me->query("max_gin")/k),me );
//    me->receive_damage("kee", (int)(me->query("max_kee")/k),me );
    me->receive_wound ("kee", (int)(me->query("max_kee")/k),me );
//    me->receive_damage("sen", (int)(me->query("max_sen")/k),me );
    me->receive_wound ("sen", (int)(me->query("max_sen")/k),me );
    tell_object(me,"你受到了" + HIR + "惡靈纏身" + NOR + "頓時心神不寧導致內息紊亂，導致吐了一口鮮血。\n" + NOR);
    message("vision",HIR+me->name()+"受到" + HIR + "惡靈纏身" + NOR + "以至於內息走岔受到了不小的內傷。\n" + NOR,environment(me),me);
    COMBAT_D->report_status(me);
  }
  if( duration < 1 ) return 0;
  return 1;
}
