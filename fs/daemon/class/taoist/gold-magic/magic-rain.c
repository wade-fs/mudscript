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

  message_vision(HIR"
$n被前一個變化所造成的重大損傷還沒回復，
$N又施展了魔界金典的深奧招數，『雨～給我下!!』
$n只見落下點點雨滴，卻沒想到是殺招降臨的前奏...

"HIW"ζ"HIY+BRED"魔界金典"NOR""HIW"ζ"HIC"天地神通"HIW"之《"HIB"雨變化"HIW"》"HIR"

                  終於，天地變異，無數隕石朝著仍一頭霧水的$n墜下，
                  隕石當場活生生將$n壓下，巨石碎片飛濺，大地震動...
                  煙硝散去後，只遺留下一個深邃窟窿...\n"NOR,me,enemy[i]);

  for(i=0;i<j;i++)
  {
    enemy[i]->receive_damage("gin",(enemy[i]->query("max_atman"))/6,me);
    enemy[i]->receive_damage("kee",(enemy[i]->query("max_force"))/7,me);
    enemy[i]->receive_damage("sen",(enemy[i]->query("max_mana"))/6,me);
    COMBAT_D->report_status(enemy[i]);
  }

  return 1;
}
