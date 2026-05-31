//風變化 by frequency
//將receive_damage的攻擊參數全部補上攻擊方之參數 by blazakira 2011/5/10

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

  message_vision(HIY"$N喃喃唸道：

          『"HIW"汝等寄生紅塵，漂流於生死海中，不觀自心，
            病發迷途，我今以無上道法，渡汝過於彼岸。"HIY"』
                
      "HIW"ζ"HIY+BRED"魔界金典"NOR""HIW"ζ奧義《"HIR"血穴神通"HIW"》"HIM"爆發
      
  "HIG"$N四周浮現數百個鮮紅的"HIR"血池漩渦，\n
  "HIG"所有接觸到血池的物體皆瞬間灰飛湮滅。\n\n"NOR,me);

  for(i=0;i<j;i++)
  {
    if(userp(enemy[i]))
    {
      enemy[i]->receive_wound("gin",enemy[i]->query("max_gin")/9,me);
      enemy[i]->receive_wound("kee",enemy[i]->query("max_kee")/5,me);
      enemy[i]->receive_wound("sen",enemy[i]->query("max_sen")/9,me);
      COMBAT_D->report_status(enemy[i]);
    }else
    {
      enemy[i]->receive_wound("kee",enemy[i]->query("max_kee"),me);
    }
  }

  return 1;
}
