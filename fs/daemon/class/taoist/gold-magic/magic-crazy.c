//跳神通 by frequency
#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int conjure (object me)
{
  int i=0,j;
  object *enemy,room;
  room = environment(me);
  enemy=me->query_enemy(room);
  j=sizeof(enemy);
 
  if(!me->is_fighting() )
    return notify_fail("這法術只能在戰鬥中使用!!\n");
  if(!enemy)
    return notify_fail("你目前沒有戰鬥對手!!\n");

  message_vision(HIB"
  $N"HIG"使出"HIY+BRED"魔界金典"NOR""HIB"中的"HIW"『"HIC"跳神通"HIW"』，
  陰神出竅，迅速射入$n的天靈，$n感覺到自己的身體逐漸不受控制
  漸漸開始向身旁胡亂揮舞了。\n"NOR,me,enemy[i]);

  for(i=0;i<j;i++)
  {
    if(random(100)>75)  enemy[i]->apply_condition("mess",random(2)+1);
  }

  return 1;
}
