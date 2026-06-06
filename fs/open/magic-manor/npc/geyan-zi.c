//更改心跳裡的玩家判定為query_temp("last_damage_from") 與增加心跳裡環境的判斷 by blazakira 2011/8/18

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("寂元子",({"geyan zi","geyan","zi"}));
  set("long",@LONG
聚靈八傑之一，擅長聖火教的功夫，功力更是比當今武林神話
林宏昇更高，天驚地動第五式更是用的盧火純青，無人能擋。
LONG);
  set("gender","男性");
  set("class","prayer");
  set("nickname",HIB"天"HIC"雷"HIB"歸"HIC"劫"NOR);
  set("title",HIC"聚靈八傑"NOR);
  set("family/family_name","聖火教");
  set("combat_exp",10000000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",3000);
  set("age",40);

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);

  set("env/天驚地動",5);
  set("env/superforce","green");
  set("env/連擊","YES");

  set("force",200000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("max_kee",100000);
  set("max_gin",100000);
  set("max_sen",100000);

  set_skill("superforce", 250);
  set_skill("dodge", 120);
  set_skill("force",250);
  set_skill("move", 120);
  set_skill("literate",120);
  set_skill("parry", 120);
  set_skill("array",130);
  set_skill("fire-array",130);
  set_skill("unarmed",150);
  set_skill("canon",150);
  set_skill("shift-steps",150);
  set_skill("universe",150);
  map_skill("force","superforce");
  map_skill("dodge","shift-steps");
  map_skill("move","shift-steps");
  map_skill("parry","universe");
  map_skill("array","fire-array");
  map_skill("unarmed","universe");

  set("functions/blood/level",150);
  set("functions/tengin/level",100);
  set("functions/bluesea/level",150);
  set("functions/nine/level",150);
  set("functions/gen/level",150);
  set("functions/black/level",150);
  set("functions/goldsun/level",150);
  set("functions/ice/level",150);
  set("functions/white/level",150);
  set("functions/hwa_je/level",150);
  set("functions/purple/level",150);
  set("functions/gwe_jen/level",150);
  set("functions/green/level",150);

//  set("chat_chance_combat",50);
//  set("chat_msg_combat", ({
//    (: perform_action, "unarmed.tengin" :),
//    (: perform_action, "force.gwe_jen" :),
//    (: perform_action, "force.blood3" :),
//  }));

  set("marks/tengin",1);
  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set_temp("armor_vs_force",300);
  set_temp("no_die_soon",1);
  set_temp("rob",1); 
  set_temp("no-plan",1);
  set_temp("mount",1);
  set_temp("follow",1);
  set_temp("speed",1);
  set_temp("empty",1);
  set_temp("false",1);
  set_temp("lock-link",1);

  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense",150);

  setup();

  add_money("cash",3);
  carry_object("/open/magic-manor/obj/hwa-je-icer");
}

int accept_kill(object ob)
{
  object me=this_object();
  kill_ob(ob);
  me->delete_temp("is_busy");
  command("wield all");
  command("perform force.bluesea3");
  return 1;
}

void greeting(object ob)
{
  ob=this_player();
  if(ob->query_temp("know_fist"))
  {
    ob->add_temp("know_fist",1);
    message_vision(HIW"寂元子說道:「你想藉此瞞過英雄正宗，以便伺機將他轟下嗎!?
             好!!我可以幫助你，但是我曾答應無垢老頭誓死
             保護這本書，所以，便儘管試著擊敗我吧!!」\n\n"NOR,ob);
             kill_ob(ob);
    command("wield all");
    command("perform force.bluesea3");
  }
  if( ob->query_skill("coldpoison",1) && !wizardp(ob) )
  {
    command("say 學毒術之人，來討教幾招吧！！");
    kill_ob(ob);
    ob->start_busy(1);
  }
  set_heart_beat(1);
  return;
}

void heart_beat()
{
  object who=query_temp("last_damage_from"),me=this_object();
  int i;
  if(!me || !environment()) return ;
  i=random(100);
  
  if( !me->query_temp("weapon") )
  {
    command("wield all");
    command("wear all");
  }

  if( me->is_fighting() && !me->is_busy() )
  {
    if( !who ) return;
    if( !who->is_busy() && random(100) > 50 )
    {
      command("perform force.bluesea3");
    } else {
      if( i > 55 )
      {
        set("env/天驚地動",5);
        command("perform unarmed.tengin");
      }
      if( i < 56 && i > 10 )
      {
        set("env/天驚地動",4);
        command("perform unarmed.tengin");
      }
      if( i < 11)
      {
        command("perform force.gwe_jen");
      }
    }
  }

  if( !me->is_fighting() && !me->query_temp("hwa_je") )
  {
    command("exert hwa_je");
  }
  if( me->is_fighting() && !me->query_temp("hwa_je") )
  {
    me->delete_busy();
    command("exert hwa_je");
  }
  if( !me->query_temp("mixforce") )
  {
    me->delete_temp("is_busy");
    command("perform force.mixforce");
  }

  if( !is_fighting() ) 
  {
    if( query("force") < 39000 )
    command( "ex 270" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") )
    {
      me->receive_curing("gin",350);
      me->receive_heal("gin",350);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
      me->receive_curing("sen",350);
      me->receive_heal("sen",350);
    }
  }
//  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object me,obj,winner;
  int j;
  me=this_object();
  winner=query_temp("last_damage_from");

  if(winner->query_temp("know_fist") >= 2)
  {
    message_vision(HIW"寂元子說道:「大俠果然武功\高強，老夫心甘情願交出祕笈，望大俠早日為武林除害。」\n"NOR,winner);
    message_vision(HIR"" + winner->query("name") + "得到了無雙拳理。\n"NOR,winner);
    obj=new("/open/capital/obj/fist_book");
    obj->move(winner);
  }

  if(!winner)
  {
    ::die();
    return ;
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj12/starfruit-doll")->move(environment(winner));
        message_vision(HIM"\n從寂元子的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/starfruit_doll",sprintf("%s(%s) 讓寂元子掉下了楊桃娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj12/starfruit-doll")->move(environment(winner));
        message_vision(HIM"\n從寂元子的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/starfruit_doll",sprintf("%s(%s) 讓寂元子掉下了楊桃娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  if( random(6) == 3 )
  {
    obj=new("/open/magic-manor/obj/wood-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(9) == 5 )
  {
    obj=new("/open/magic-manor/obj/water-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(12) == 7 )
  {
    obj=new("/open/magic-manor/obj/fire-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(15) == 9 )
  {
    obj=new("/open/magic-manor/obj/soil-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(18) == 11 )
  {
    obj=new("/open/magic-manor/obj/golden-ball");
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
    obj->move(environment(winner));
  }
  ::die();
}
