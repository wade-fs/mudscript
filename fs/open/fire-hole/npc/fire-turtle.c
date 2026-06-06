//增加撿拾道具的功能 為了稍微減輕系統負擔 by blazakira 2010/10/20
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("火龜", ({ "fire turtle","fire","turtle" }) );
        set("long",
                "這是一隻棲息在火龍窟的火龜﹐身體外面有一層極為堅固的外殼所保護。\n");
        set("race", "野獸");
        set("age", 990);
        set("attitude", "friendly");
        set("max_gin", 20000);
        set("max_kee", 33000);
        set("max_sen", 20000);
        set("str", 90);
        set("cor", 50);
        set("spi", 50);
        set("int", 50);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("bellicosity",10000);
        set("max_force",35000);
        set("force",50000);
      set("family/family_name","火龍窟");
        set_temp("apply/armor", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set("force_factor",40);
        set("combat_exp", 9500000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
	set_skill("unarmed",150);
	set_skill("rabbit-combat",100);
	map_skill("unarmed","rabbit-combat");
        set_temp("kang-power",1);
        set_temp("hardshell",1);
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
    message_vision(HIC"$N以很遺憾的心情將"+inv[i]->query("name")+HIC"("+inv[i]->query("id")+HIC")歸入塵土風逝。\n"NOR,ob);
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
          message_vision(HIR"火龜的背殼裂紋上泛起一片紅光，紅光衍生了熾熱赤焰火網!!\n"NOR,this_object());
            for( j=0 ; j<i ; j++ )
            {
              if( !enemy[j] || environment(enemy[j]) != environment(mob) ) continue;
              {
                if( random(10) > 2 )
                {
                message_vision(HIR"赤焰火網直奔$N"HIR"而去，$N"HIR"一時無法反應被火網困住了!!\n"NOR,enemy[j]);
                enemy[j]->start_busy(1);
                COMBAT_D->report_status(enemy[j]);
                }else{
                message_vision(HIW"$N輕輕向後翻落，已落在火網三丈之外，火網只能無功\而返。\n"NOR,enemy[j]);
                COMBAT_D->report_status(enemy[j]);
                }
              }
            }
          break;

          case 31..100:
          message_vision(HIR"火龜狂嘯一聲，發出強大的反震力，想要掙開身上所受的束搏!!\n"NOR,this_object());
            for( j=0 ; j<i ; j++ )
            {
              if( !enemy[j] || environment(enemy[j]) != environment(mob) ) continue;
              {
                if( random(35000) > enemy[j]->query("max_force")  )
                {
                message_vision(HIR"$N"HIR"一個躲避不及，給震的氣血翻騰，一時間氣血難以調適!!\n"NOR,enemy[j]);
                enemy[j]->receive_wound("kee",bu*150);
                enemy[j]->receive_wound("gin",150);
                enemy[j]->receive_wound("sen",150);
                COMBAT_D->report_status(enemy[j]);
                }else{
                message_vision(HIW"$N仗著深厚的內功\，將這道震力給完全卸了開去。\n"NOR,enemy[j]);
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

void die()
{
        object winner = query_temp("last_damage_from");
        string name = winner->query("name");

        if(!winner)
        {
        ::die();
        return ;
        }
        if( !present( "fire-turtle shield", winner ) )
        {
          if( random(49) == 7 && userp(winner) )
          {
          log_file("open-area/get_shield", sprintf("%s(%s) 得到火龜殼盾於 %s\n",name,winner->query("id"), ctime(time()) ));
          new("/autoload/open-area/turtle-shield.c")->move(winner);
          message_vision(HIR"火龜臨死的一個掙扎，甩出了一塊盾甲砸向了$N!!\n"NOR,winner);
          }
        }
        :: die();
}

