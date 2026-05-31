
inherit SKILL;


int valid_learn(object me)
{
  if(!me->query("quests/acupuncture"))
    return notify_fail("上面寫的東西你一竅不通，難以理解。\n");

  if( (me->query("potential") - me->query("learned_points")) < 5 ) 
    return notify_fail("你的潛能不到五點，無法學習這項技巧。\n");
  if(me->query_skill("acupuncture",1) > 99) 
    return notify_fail("對於這項技能的了解已經到達極限了。\n");
  me->add("potential", -5);
  return   1;
}

int valid_study(object me)
{
  if(!me->query("quests/acupuncture"))
    return notify_fail("上面寫的東西你一竅不通，難以理解。\n");

  if( (me->query("potential") - me->query("learned_points")) < 5 ) 
    return notify_fail("你的潛能不到五點，無法學習這項技巧。\n");
  if(me->query_skill("acupuncture",1) > 99) 
    return notify_fail("對於這項技能的了解已經到達極限了。\n");

  me->add("potential", -5);
  return   1;

}
