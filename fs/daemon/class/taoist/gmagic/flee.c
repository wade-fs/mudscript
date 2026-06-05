//增加出口是否存在的判斷 by blazakira 2011/9/26

#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;

void remove_flee (object me);

int conjure(object me,object target)
{
  object *enemy;
  int memove,enemymove,funlvl;
  mapping exit=environment(me)->query("exits");
  string *dirs;
  int i;
  seteuid(getuid());
  dirs=keys(exit);
  i=random(sizeof(dirs));
  if(sizeof(exit) < 1 || !exit)
    return notify_fail(HIW + "這裡無處可逃!!\n" + NOR);
  if(!exit[dirs[i]]) return notify_fail("出路被擋住了，不過多試幾次就好了!!\n");
  load_object(exit[dirs[i]]);
  if(!me->query("spells/flee/level"))
    return 0;
  if(me->query("class")!="taoist")
    return 0;
  if(!me->is_fighting())
    return notify_fail("你又沒在戰鬥，跑什麼跑？\n");
  if(me->query_temp("tt"))
    return notify_fail("你的法術尚未施完!!");
  if( me->query_skill_mapped("dodge") != "g-steps")
    return notify_fail("你沒有天道派的獨門輕功\，無法使出「隱遁」。\n");
  message_vision(HIY + "$N使出奇門遁甲之「隱遁」。\n" + NOR,me);
  funlvl = me->query("spells/flee/level");
  if( random(funlvl+100) > random(100) )
  {
    message_vision(HIW + "只見$N眨眼間已不知去向。\n" + NOR,me);
    me->move(exit[dirs[i]]);
  }
  else
  {
    message_vision(HIY + "可惜$N技術不夠純熟而失敗了。\n" + NOR,me);
    me->start_busy(1);                        
  }
  if( me->query("spells/flee/level") < 100 )
    spell_improved ("flee", random(funlvl*5)+100);
//me->start_call_out((: call_other, __FILE__, "remove_flee", me :),2);
  return 1;
}

void remove_flee (object me)
{
  me->delete_temp ("tt");
  return;
}
