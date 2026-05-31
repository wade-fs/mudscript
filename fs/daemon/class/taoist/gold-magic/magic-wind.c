//風變化 by frequency
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
    
  message_vision(HIW"
  $N大喝：『風～給我風!!』

    "HIW"ζ"HIY+BRED"魔界金典"NOR""HIW"ζ"HIC"天地神通"HIW"之《"HIG"風變化"HIW"》

  $N不但藉由風勢掙脫$n的束縛，更趁勢捲起一股巨大的氣流，
  "HIM"$n的重心被颶風吹得東倒西歪，完全無法維持基本武學架式。\n"NOR,me,enemy[i]);

  for(i=0;i<j;i++)
  {
                enemy[i]->map_skill("dodge",0);
                enemy[i]->map_skill("parry",0);
                enemy[i]->map_skill("move",0);
                enemy[i]->map_skill("blade",0);
                enemy[i]->map_skill("unarmed",0);
                enemy[i]->map_skill("sword",0);
                enemy[i]->map_skill("dagger",0);
                enemy[i]->map_skill("stabber",0);
                enemy[i]->map_skill("staff",0);
                enemy[i]->map_skill("archery",0);
                enemy[i]->map_skill("whip",0);
                enemy[i]->map_skill("throwing",0);
                enemy[i]->start_busy(1);
                //me->delete_busy();
                COMBAT_D->report_status(enemy[i]);
  }

  return 1;
}
