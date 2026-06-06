//增加die() 裡 last_damage_from 存在與否的判定 by blazakira 2013/7/24

inherit NPC;
#include "/open/open.h"
#include <ansi.h>

void create()
{
  object ob;
  set_name("火靈獸", ({ "fire beast","fire","beast" }) );
  set("long","出沒於火靈塔中的妖物，擅長使用強烈火焰攻擊。\n");
  set("title",HIR"(紅色靈氣)"NOR);
  set("age", 60);
  set("max_gin", 30000);
  set("max_kee", 30000);
  set("max_sen", 30000);
  set("max_force", 15000);
  set("force",15000);
  set("max_atman",30000);
  set("max_mana",30000);
  set("atman",30000);
  set("mana",30000);
  set("force_factor",15);
  set("attitude","aggressive");
  set("str", 35);
  set("cor", 35);
  set("spi", 35);
  set("int", 35);
  set_temp("apply/armor", 150);
  set_temp("apply/defense", 150);
  set_temp("apply/damage", 80);
  set_temp("apply/attack", 80);
  set("bellicosity",10000);
  set_skill("unarmed",150);
  set_skill("hell-evil",150);
  set_skill("mogi-steps",150);
  set_skill("move",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("force",150);
  map_skill("dodge","mogi-steps");
  map_skill("move","mogi-steps");
  map_skill("parry","hell-evil");
  map_skill("unarmed","hell-evil");

  set("combat_exp", 5000000);
  set("fire-monster",1);
  setup();
}

void heart_beat()
{
  object mob,me,obj;
  mixed enemy;
  int i,j=0;
  mob = this_object();
  me = this_player();
  if(!mob||!environment(mob)) return;
  enemy = all_inventory( environment(mob) );
  i=sizeof(enemy);

  if( !mob->is_fighting() || mob->is_fighting() )
  {
    for (j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if(!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
        && living(enemy[j]) && !enemy[j]->query("gold-monster") ) 
        mob->kill_ob(enemy[j]);
    }
  }

  if( random(10) < 6 && mob->is_fighting() )
  {
    message_vision(HIR"$N身上的紅色靈氣和火靈塔相互感應，火捲漫天，數不清的火焰向所有在場的人攻去!!\n"NOR,mob);
    for (j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
        && !enemy[j]->query("fire-monster") )
      {
        if( !enemy[j]->query_temp("magic-manor/water-shield") )
        {
          message_vision(HIR"$N"HIR"只感渾身灼熱，還不時傳出陣陣燒焦的臭味!!\n"NOR,(enemy[j]));
          enemy[j]->receive_wound("kee",450);
          COMBAT_D->report_status(enemy[j]);
        } else {
          message_vision(HIC"$N"HIC"身上的水靈之氣緩和了部份的火焰衝擊!!\n"NOR,(enemy[j]));
          enemy[j]->receive_wound("kee",220);
          COMBAT_D->report_status(enemy[j]);
        }
      }
    }
  }   
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object me=query_temp("last_damage_from");
  if(me && me->query_temp("magic-manor/kill-fire06") <= 20)
  {
    me->add_temp("magic-manor/kill-fire06",1);
  }
  :: die();
}
