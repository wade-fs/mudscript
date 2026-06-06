inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        set_name("火蜥蜴", ({ "fire lizard","fire","lizard" }) );
        set("long",
                "這是一隻棲息在火龍窟的蜥蜴﹐體積龐大但是動作極為靈活。\n");

        set("race", "野獸");
        set("age", 110);
        set("attitude", "friendly");
        set("max_gin", 40000);
        set("max_kee", 75000);
        set("max_sen", 40000);
        set("str", 80);
        set("cor", 50);
        set("spi", 70);
        set("int", 40);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
      set("family/family_name","火龍窟");
        set("bellicosity",10000);
        set("max_force",30000);
        set("force",50000);
        set_temp("apply/armor", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/attack", 180);
        set("force_factor",20);
        set("combat_exp", 9500000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
	set_skill("unarmed",150);
	set_skill("rabbit-combat",100);
	map_skill("unarmed","rabbit-combat");
        set_temp("kang-power",1);
        setup();
        carry_object("/open/common/obj/liz_meat.c");
}

void heart_beat()
{
        object me,mob,*enemy;
        int bu,i,j;
        me=this_player();
        mob=this_object();
        bu=(int)mob->query_busy();
        enemy=mob->query_enemy();
        i=sizeof(enemy);

        if( bu <= 0 ) bu=1;
        if( bu > 10 ) bu=9;

        if( mob->is_fighting() && mob->is_busy() && random(100) > 50 )
        {
          switch(random(100))
          {
          case 0..30:
      message_vision(HIR + "火蜥蜴的背部硬皮上泛起一片紅光，紅光衍生了熾熱赤焰火網!!\n" + NOR,me);
                for( j=0 ; j<i ; j++ )
            {
              if( !enemy[j] || environment(enemy[j]) != environment(mob) ) continue;
              {
                  if( random(10) > 2 )
                {
                    message_vision(HIR + "赤焰火網直奔$N" + HIR + "而去，$N" + HIR + "一時無法反應被火網困住了!!\n" + NOR,enemy[j]);
                    enemy[j]->start_busy(1);
                COMBAT_D->report_status(enemy[j]);
                        }else{
                message_vision(HIW + "$N輕輕向後翻落，已落在火網三丈之外，火網只能無功\而返。\n" + NOR,enemy[j]);
                COMBAT_D->report_status(enemy[j]);
                        }
                  }
            }
          break;

          case 31..100:
          message_vision(HIR + "火蜥蜴狂嘯一聲，發出強大的反震力，想要掙開身上所受的束搏!!\n" + NOR,this_object());
                for( j=0 ; j<i ; j++ )
            {
              if( !enemy[j] || environment(enemy[j]) != environment(mob) ) continue;
              {
                        if( random(35000) > enemy[j]->query("max_force")  )
                {
                    message_vision(HIR + "$N" + HIR + "一個躲避不及，給震的氣血翻騰，一時間氣血難以調適!!\n" + NOR,enemy[j]);
                    enemy[j]->receive_wound("kee",bu*150);
                    enemy[j]->receive_wound("gin",150);
                    enemy[j]->receive_wound("sen",150);
                COMBAT_D->report_status(enemy[j]);
                        }else{
                message_vision(HIW + "$N仗著深厚的內功\，將這道震力給完全卸了開去。\n" + NOR,enemy[j]);
                COMBAT_D->report_status(enemy[j]);
                        }
                  }
            }
          break;
          }
        }

        if( mob->query("kee") <= 0 )
        {
        mob->die();
        }
    set_heart_beat(1);
        ::heart_beat();
}

