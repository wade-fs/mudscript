//增加死亡時 玩家已不存在時的判斷 與昏迷時不予攻擊的判斷 by blazakira 2011/3/19

inherit NPC;
#include "/open/open.h"
#include <ansi.h>

void create()
{
  set_name("土爆波", ({ "soil king","soil","king" }) );
  set("long","土靈塔的鎮塔之王，能力比小土妖和土靈獸不知強上幾倍。\n");
  set("title",YEL + "(土色靈氣)" + NOR + "土靈塔王" + NOR);
  set("gender","男性");
  set("class","bandit");
  set("family/family_name","惡人谷");
  set("age", 60);
  set("str", 35);
  set("cor", 35);
  set("spi", 35);
  set("int", 35);

  set("combat_exp",8000000);
  set("bellicosity",10000);
  set("max_gin", 80000);
  set("max_kee", 80000);
  set("max_sen", 80000);
  set("max_force", 20000);
  set("force",200000);
  set("max_atman",50000);
  set("max_mana",50000);
  set("atman",50000);
  set("mana",50000);
  set("force_factor",20);
  set("attitude","aggressive");

  set_skill("dodge",120);
  set_skill("sword",120);
  set_skill("ghost-steps",120);
  set_skill("force", 120);
  set_skill("badforce",120);
  set_skill("move", 120);
  set_skill("parry",120);
  set_skill("unarmed",120);
  set_skill("badstrike",120);

  map_skill("unarmed", "badstrike");
  map_skill("parry", "badstrike");
  map_skill("force", "badforce");
  map_skill("dodge", "ghost-steps");
  map_skill("move", "ghost-steps");

  set("functions/evil-blade/level",100);
  set("functions/badroar/level",100);

  set("chat_chance_combat", 45);
  set("chat_msg_combat", ({
    (: perform_action, "unarmed.evil-blade" :),
    (: perform_action, "unarmed.badroar" :),
  }) );

  set("quests/badroar",1);
  set("marks/kar",1);
  set("soil-monster",1);

  set_temp("apply/armor", 150);
  set_temp("apply/defense", 250);

  setup();

  add_money("cash",3);
  carry_object("/open/magic-manor/soil/obj/soil-claw")->wield();
}

void heart_beat()
{
  object mob,me,obj;
  mixed enemy;
  int i,j=0,k=random(2);
  mob = this_object();
  me = this_player();
  if(!mob||!environment(mob)) return;
  enemy = all_inventory( environment(mob) );
  i = sizeof(enemy);

  if( !mob->is_fighting() || mob->is_fighting() )
  {
    for (j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      {
       if(!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
          && living(enemy[j]) && !enemy[j]->query("soil-monster") ) 
         mob->kill_ob(enemy[j]);
      }
    }
  }

  if(random(10) > 6 && mob->is_fighting() )
  {
    message_vision(HIM + "雷厲風行，驚天動地，橫掃萬物於須臾，$N感念深刻聚力一指瞬間擊出

      " + HIW + "----===≡◎ 土爆雷霆式 ◎≡===----
     " + NOR+BLU + "  『" + HIB + "土假虎威．地雷震" + NOR+BLU + "』\n\n" + NOR,mob);

    for (j=0 ; j < i ; j++)
    {
      if( !enemy[j]) continue;
      {
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && !enemy[j]->query("soil-monster") )
        {
          if( !enemy[j]->query_temp("magic-manor/wood-shield") )
          {
            message_vision(YEL + "$N" + YEL + "只感呼吸困難，行走不便，只能任由飛沙走石在身上無情的鞭打!!\n" + NOR,(enemy[j]));
            enemy[j]->receive_wound("kee",600);
            enemy[j]->start_busy(1);
            COMBAT_D->report_status(enemy[j]);
          }else{
            message_vision(HIG + "$N" + HIG + "身上的木靈之氣緩和了部份的飛沙走石衝擊!!\n" + NOR,(enemy[j]));
            enemy[j]->receive_wound("kee",300);
            enemy[j]->start_busy(k);
            COMBAT_D->report_status(enemy[j]);
          }
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
  int j;
  if(userp(me) && me->query_temp("not_robot") > time() )
  {
    if ( me->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj12/pineapple-doll")->move(environment(me));
        message_vision(HIM + "\n從土爆波的身上掉下了一件奇怪的東西!!\n" + NOR,me,me);
        write_file("/log/sky/obj12/pineapple_doll",sprintf("%s(%s) 讓土爆波掉下了鳳梨娃娃於 %s\n",
        me->name(1),me->query("id"),ctime(time())));
      }
    }else{
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {      
        new("/open/sky/obj12/pineapple-doll")->move(environment(me));
        message_vision(HIM + "\n從土爆波的身上掉下了一件奇怪的東西!!\n" + NOR,me,me);
        write_file("/log/sky/obj12/pineapple_doll",sprintf("%s(%s) 讓土爆波掉下了鳳梨娃娃於 %s\n",
        me->name(1),me->query("id"),ctime(time())));
      }
    }
  }

  if( !me->query_temp("magic-manor/soilmagic") )
  {
    message_vision(YEL + "土爆波死後的靈魂忽然化為一道土色靈光，灌入了$N" + YEL + "的身體之中!!\n" + NOR,me);
    me->set_temp("magic-manor/soilmagic",1);
    if( !me->query("magic-manor/kill-soil") )
    {
      me->set("magic-manor/kill-soil",1);
    }else{
      me->add("magic-manor/kill-soil",1);
    }
  }else{
    if( !me->query("magic-manor/kill-soil") )
    {
      me->set("magic-manor/kill-soil",1);
    }else{
      me->add("magic-manor/kill-soil",1);
    }
  }
  if( me )
    me->delete_temp("magic-manor/breaksoil",1);
  message_vision("\n\n塔身因為土靈王的滅亡而慢慢的出現了一些裂痕.....\n",me);

  :: die();
}
