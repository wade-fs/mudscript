//雷變化 by frequency
//將receive_damage的攻擊參數全部補上攻擊方之參數 by blazakira 2011/5/10

#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int conjure (object me)
{
  int i=0,j,killair;
  object *enemy,room;
  room = environment(me);
  enemy=me->query_enemy(room);
  j=sizeof(enemy);
 
  if(!me->is_fighting() )
    return notify_fail("這法術只能在戰鬥中使用!!\n");
  if(!enemy)
    return notify_fail("你目前沒有戰鬥對手!!\n");

  message_vision(HIM + "
$N魔焰高漲，狂吼：『給我雷!!』

" + HIW + "ζ" + HIY+BRED + "魔界金典" + NOR + "" + HIW + "ζ" + HIC + "天地神通" + HIW + "之《" + HIY + "雷變化" + HIW + "》" + HIM + "
                    
天啊!!$N竟憑空拉扯出一道道巨大的閃電，朝著$n所在處劈了下來!!
" + HIW + "迅雷不及掩耳，$n即使下意識閃躲，背部還是被劈個正著。\n" + NOR,me,enemy[i]);

  for(i=0;i<j;i++)
  {
    killair=enemy[i]->query("bellicosity");
    enemy[i]->set("bellicosity",killair*9/10);
    enemy[i]->receive_damage("kee",1000,me);
    enemy[i]->apply_condition("hellthunder",random(5));
    enemy[i]->apply_condition("skyfire",random(5));
    COMBAT_D->report_status(enemy[i]);
  }

  return 1;
}
