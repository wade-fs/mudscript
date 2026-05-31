#include <ansi.h>
inherit F_SPELL;
int conjure(object me, object target)
{
	
  if (!me->query("spells/manabody/level"))
     return 0;

  if ((int)me->query_temp ("manabody"))
    return notify_fail ("你已經用了雲體風身。\n");
        if(me->query("class")!="taoist")
        return 0;
if( me->is_fighting() ) me->start_busy(1);//戰鬥中busy一回..by Chan
  
  message_vision (HIW"一道氣壓旋空而起，$N正使出雲體風身之術\n\n"NOR,me);
  me->set_temp("manabody",1);
  message_vision ("$N納氣揚聲，一聲長嘯!!將自己的體力提升到了極限!!\n"NOR,me);
  me->add("max_kee",me->query_skill("magic")*10);  
  return 1;
}


