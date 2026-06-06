//增加心跳裡環境的判斷 by blazakira 2011/8/18

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("左靈兒",({"left linr","left","linr"}));
  set("long",@LONG
聚靈山莊之二聖，修為算的上是高手級的，要處理許多莊內的
事務，所以平日較疏於外功的修練，內功卻是比八傑還要高深
莫測。功力和右靈晉不相伯仲。
LONG);
  set("gender","女性");
  set("class","fighter");
  set("nickname",NOR+RED"昊"HIY"日"NOR+RED"烈"HIY"焰"NOR);
  set("title",HIC"聚靈火聖"NOR);
  set("family/family_name","瀧山派");
  set("combat_exp",12000000);
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

  set("env/瀧山連擊","YES");

  set("force",200000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("s_kee",1000);
  set("max_s_kee",1000);
  set("sec_kee","tiger");

  set("max_kee",120000);
  set("max_gin",120000);
  set("max_sen",120000);

  set_skill("haoforce", 350);
  set_skill("dodge", 120);
  set_skill("force",450);
  set_skill("move", 120);
  set_skill("parry", 120);
  set_skill("unarmed",200);
  set_skill("lungshan",100);
  set_skill("henma-steps",120);
  set_skill("fire-kee",120);

  map_skill("dodge","henma-steps");
  map_skill("move","henma-steps");
  map_skill("parry","fire-kee");
  map_skill("unarmed","lungshan");
  map_skill("force","haoforce");

  set("functions/kang_kee/level",100);
  set("functions/kang_power/level",100);

  set("kang-power",1);
  set("super_fire",1);
  set("fire_strike",1);
  set("quests/sunfire",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set("can_use_cloud",1);
  set_temp("fan-finger",5000);
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
  set_temp("roared",1);

  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense",150);

  setup();

  add_money("cash",2);
  carry_object("/daemon/class/fighter/figring")->wield();
  carry_object("/open/magic-manor/ghost/obj/trigram-pill")->set_amount(1);
}

int accept_kill(object who)
{
  object me=this_object();
//  who=this_player();
  kill_ob(who);
  me->delete_temp("is_busy");
  me->delete_busy();
  command("wield all");
  command("perform force.kang_kee");
  return 1;
}

void greeting(object ob)
{
//  ob=this_player();
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
  object me=this_object(),*enemy;
  int i;
  if(!me || !environment()) return ;

  enemy = me->query_enemy();
  i = random( sizeof(enemy) );
/*
  if( !me->query_temp("weapon") )
  {
    command("wield all");
    command("wear all");
  }
*/
  if( sizeof(enemy) && me->is_fighting() && me->query("s_kee") > 0 )
  {
    if( !enemy[i]->query_temp("tiger") && !enemy[i]->query_temp("dragon") )
    {
      if( random(2) == 1 )
      {
        me->set("sec_kee","tiger");
        command("cmd usekee "+enemy[i]->query("id"));
      } else {
        me->set("sec_kee","dragon");
        command("cmd usekee "+enemy[i]->query("id"));
      }
    } else {
      if( !enemy[i]->query_temp("dragon") )
      {
        me->set("sec_kee","dragon");
        command("cmd usekee "+enemy[i]->query("id"));
      }
      if( !enemy[i]->query_temp("tiger") )
      {
        me->set("sec_kee","tiger");
        command("cmd usekee "+enemy[i]->query("id"));
      }
    }
  }

  if( me->query("force_factor") < 90 )
  {
    me->set("force_factor",90);
  }

  if( !me->is_fighting() && !me->query_temp("kang-power") )
  {
    command("perform haoforce.kang_power");
  }

  if( me->query("force") < 100000 )
  {
    me->set("force",100000);
  }

  if( me->is_fighting() && !me->is_busy() )
  {
    if( random(5) == 2 )
    {
      command("perform force.kang_kee");
    }
  }

  if( me->is_busy() && me->is_fighting() )
  {
    if( 30 > random(100) )
    {
      message_vision(HIW"\n只見$N暴起所有"HIY"真氣內勁"HIW"，$N全身籠罩在一股"HIC"綻藍氣勁"HIW"中，赫然已解開身上被封的穴道。\n"NOR,this_object());
      delete_busy();
    }
  }

  if( !is_fighting() ) 
  {
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
        new("/open/sky/obj12/apple-doll")->move(environment(winner));
        message_vision(HIM"\n從左靈兒的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/apple_doll",sprintf("%s(%s) 讓左靈兒掉下了蘋果娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj12/apple-doll")->move(environment(winner));
        message_vision(HIM"\n從左靈兒的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/apple_doll",sprintf("%s(%s) 讓左靈兒掉下了蘋果娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  if( random(999) == 7 )
  {
    obj=new("/open/magic-manor/obj/sun-heart");
    obj->move(environment(winner));
    message_vision(CYN"\n一塊奇怪的物品$N的身體掉了出來!!\n"NOR,me);
  } else if( random(888) == 7 )
  {
    obj=new("/open/magic-manor/obj/sun-heart");
    obj->move(environment(winner));
    message_vision(CYN"\n一塊奇怪的物品$N的身體掉了出來!!\n"NOR,me);
  } else if( random(777) == 7 )
  {
    obj=new("/open/magic-manor/obj/sun-heart");
    obj->move(environment(winner));
    message_vision(CYN"\n一塊奇怪的物品$N的身體掉了出來!!\n"NOR,me);
  } else if( random(666) == 7 )
  {
    obj=new("/open/magic-manor/obj/sun-heart");
    obj->move(environment(winner));
    message_vision(CYN"\n一塊奇怪的物品$N的身體掉了出來!!\n"NOR,me);
  } else if( random(555) == 7 )
  {
    obj=new("/open/magic-manor/obj/sun-heart");
    message_vision(CYN"\n一塊奇怪的物品$N的身體掉了出來!!\n"NOR,me);
    obj->move(environment(winner));
  }
  ::die();
}
