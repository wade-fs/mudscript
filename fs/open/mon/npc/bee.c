//增加last_damage_from的判斷 by blazakira 2013/3/13

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("蜜蜂", ({ "bee" }) );
  set("race", "野獸");
  set("age", 8);
  set("long", "一隻正在採蜜的蜜蜂。\n");
  set("str", 15);
  set("cor", 25);
  set("attitude", "friendly");
  set("max_gin", 5000);
  set("max_kee", 5000);
  set("max_sen", 5000);
  set("gin", 5000);
  set("kee", 5000);
  set("sen", 5000);
  set("verbs", ({ "bite"}));
  set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
  set("combat_exp",50000);
  set_temp("apply/armor", 120);
  set_temp("apply/attack", 70);
  set_skill("dodge",100);
  set_skill("parry",100);
  setup();

//  set_heart_beat(1);
  add_money("coin",50);
}

void invocation(object who)
{
  int i,k;
  object *enemy,mob;
  mob=this_object();
  message("vision",NOR+name()+NOR + "說道：「我來囉!!讓我來幫你!!\n" + NOR,environment(),this_object() );
  enemy = who->query_enemy();
  i = sizeof(enemy);
  while(i--)
  {
    if( enemy[i] && living(enemy[i]) )
    {
      kill_ob(enemy[i]);
      if( userp(enemy[i]) )
      {
        enemy[i]->fight_ob(this_object());
      } else {
        enemy[i]->kill_ob(this_object());
      }
    }
    if( !mob->query("changed") )
    {
      k=enemy[i]->query("killgrow/bee_sparrow");
      mob->set("eff_kee",mob->query("max_kee")+k*10);
      mob->set("eff_gin",mob->query("max_gin")+k*10);
      mob->set("eff_sen",mob->query("max_sen")+k*10);
      mob->set("max_force",mob->query("max_force")+k);
      mob->set("force",mob->query("max_force")+k*100);
      mob->set("combat_exp",mob->query("combat_exp")+k*10);
      mob->set("bellicosity",mob->query("bellicosity")+k*10);
      mob->add_temp("apply/defense",(int)(k/20));
      mob->add_temp("apply/attack",(int)(k/20));
      mob->add_temp("apply/dodge",(int)(k/20));
      mob->add_temp("apply/parry",(int)(k/20));
      mob->set("changed",1);
    }
  }
  command("defend "+who->query("id"));
  set_leader(who);
}

void init()
{
  set_heart_beat(1);
}

void heart_beat()
{
  object me,who;
  me=this_object();
  if(!me || !environment()) return ;
  who = query_leader();
  if(!who)
  {
    call_out("leave",0);
    return ;
  }
  if(!who->is_fighting())
  {
    call_out("leave",0);
    return;
  }
  if(!me->is_fighting())
  {
    call_out("leave",0);
    return;
  }
  set_heart_beat(1);
  :: heart_beat();
}

void unconcious()
{
  object me=query_temp("last_damage_from");
  if( me && this_object() ) {
    me->add("killgrow/bee_sparrow",1);
    message_vision (HIB + "我可憐的朋友！$N被淡情悠的花香旋繞，悠然的消失了!!\n" + NOR, this_object());
  }
  destruct(this_object());
}

void leave()
{
  message_vision (HIB + "$N拍拍翅膀，輕快地飛走了!!\n" + NOR, this_object());
  destruct(this_object());
}
