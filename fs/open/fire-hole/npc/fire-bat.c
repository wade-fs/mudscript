//增加撿拾道具的功能 為了稍微減輕系統負擔 by blazakira 2010/10/20
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("火蝙蝠", ({ "bat" }) );
        set("long",
                "這是一隻棲息在火龍窟的火蝙蝠﹐身型瘦小但是抗火性高。\n");

        set("race", "野獸");
        set("age", 210);
        set("attitude", "friendly");
        set("max_gin", 40000);
        set("max_kee", 51000);
        set("max_sen", 30000);
        set("str", 80);
        set("cor", 50);
        set("spi", 70);
        set("int", 40);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 130);
      set("family/family_name","火龍窟");
        set("bellicosity",10000);
        set("max_force",30000);
        set("force",50000);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set("force_factor",20);
        set("combat_exp", 8700000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
	set_skill("unarmed",150);
	set_skill("rabbit-combat",100);
	map_skill("unarmed","rabbit-combat");
        set_temp("kang-power",1);
        setup();
}

void init()
{
  set_heart_beat(1);
  call_out("greeting", 1, this_player());
}

void greeting()
{
//基本上是針對純喫茶 小拉大龍棕 喚雲扇等 生活物資
  object *inv,ob;
  int i;
  ob=this_object();
  inv=all_inventory(environment(ob));
  for(i=0;i<sizeof(inv);i++){
    if(!inv[i]) continue;
    if(!inv[i]->query("食物") && !inv[i]->query("液體") && inv[i]->query("id") != "cloud fan") continue; //需注意該房間是否固定場景的物件
    message_vision(HIC + "$N以很遺憾的心情將"+inv[i]->query("name")+HIC + "("+inv[i]->query("id")+HIC + ")歸入塵土風逝。\n" + NOR,ob);
    destruct(inv[i]);
  }
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
          message_vision(HIR + "火蝙蝠的雙爪上泛起一片紅光，紅光衍生了熾熱赤焰火網!!\n" + NOR,me);
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
          message_vision(HIR + "火蝙蝠狂嘯一聲，發出強大的音波，音波如嘶聲裂地一般!!\n" + NOR,me);
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
                message_vision(HIW + "$N仗著深厚的內功\，將這道震波給完全卸了開去。\n" + NOR,enemy[j]);
                COMBAT_D->report_status(enemy[j]);
                        }
                  }
            }
          break;
          }
        }

        if( mob->query("kee") <= 0 )
        {
          set_heart_beat(0);
          mob->die();
        }

        ::heart_beat();
}

