//取消心跳裡的玩家判定 與增加心跳裡環境的判斷 by blazakira 2011/8/18

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("凌方真",({"linfun jen","linfun","jen"}));
  set("long",@LONG
聚靈八傑之一，仙劍劍法使的是琳璃盡致，無與倫比，堪稱是
仙劍一絕，武功之高，當今世上已無幾人能望其項背。
LONG);
  set("gender","男性");
  set("class","swordsman");
  set("nickname",NOR"仙"NOR"凌"NOR"劍"NOR"真"NOR);
  set("title",HIC"聚靈八傑"NOR);
  set("family/family_name","仙劍派");
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

  set("force",200000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("s_kee",1000);
  set("max_s_kee",1000);
  set("sec_kee","god");

  set("max_kee",100000);
  set("max_gin",100000);
  set("max_sen",100000);

  set_skill("sword",150);
  set_skill("shasword",120);
  set_skill("sun_fire_sword",120);
  set_skill("sha-steps",120);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",250);
  set_skill("fireforce",250);
  set_skill("array",100);
  set_skill("sha-array",100);
  map_skill("array","sha-array");
  map_skill("dodge","sha-steps");
  map_skill("move","sha-steps");
  map_skill("parry","shasword");
  map_skill("sword","sun_fire_sword");
  map_skill("force","fireforce");

  set("functions/sha_kee/level",100);
  set("functions/swordkee/level",100);
  set("functions/gold-fire/level",100);
  set("functions/sunswordkee/level",110);

//  set("chat_chance_combat",50);
//  set("chat_msg_combat", ({
//    (: perform_action, "sword.sha_kee" :),
//  }));

  set("quests/sunfire",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("quest/sun_fire_sword",1);
  set("bounds", 40000);
  set("get_sha_sp", 1);
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
  carry_object("/open/magic-manor/obj/fon-sky-sword");
}

int accept_kill(object ob)
{
  object me=this_object();
  kill_ob(ob);
  me->delete_temp("usesunsword");
  me->delete_temp("is_busy");
  command("wield all");
  command("cmd god_kee");
  command("perform sun_fire_sword.sunswordkee");
  return 1;
}

void greeting(object ob)
{
  ob=this_player();
  if(ob->query_temp("know_sword"))
  {
    ob->add_temp("know_sword",1);
    message_vision(HIW"凌方真說道:「原來是師叔要你來向我借書的，但非常遺憾，
       我完全信不過你，你一定和英雄正宗串通好奪取
       秘笈的計畫了，所以現在便給我去死吧!!」\n\n"NOR,ob);
             kill_ob(ob);
    command("wield all");
    command("perform blade.fast-dest");
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
  object me=this_object();
//  int i=me->query_busy(),j=i-1;
  if(!me || !environment()) return ;

  if( !me->query_temp("weapon") )
  {
    command("wield all");
    command("wear all");
  }

  if( !me->is_fighting() && !me->query_temp("gold-fire") )
  {
    command("perform force.gold-fire");
  }
/*
  if( me->is_fighting() && me->is_busy() )
  {
    if( random(5) == random(5) )
    {
      message_vision(HIW"只見$N臉部表情一陣怪異，竟然解開了身上部份被封的穴道。\n"NOR,me);
      me->delete_busy();
      me->start_busy(j);
    }
  }
*/
  if( me->is_fighting() && !me->is_busy() )
  {
    if( !me->query_temp("usesunsword") )
    {
      map_skill("sword", "sun_fire_sword");
      command("perform sun_fire_sword.sunswordkee");
    } else {
      map_skill("sword", "shasword");
    }
  }

  if( !is_fighting() ) 
  {
    if( query("force") < 39000 )
      command( "ex 300" );
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

  if(winner->query_temp("know_sword") >= 2)
  {
    message_vision(HIW"凌方真說道:「哼!!你放心好了，真正的英雄很快就會來取你們狗命了!!」\n"NOR,winner);
    message_vision(HIR"" + winner->query("name") + "得到了虛空馭天劍奧義。\n"NOR,winner);
    obj=new("/open/capital/obj/sword_book");
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
        new("/open/sky/obj12/orange-doll")->move(environment(winner));
        message_vision(HIM"\n從凌方真的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/orange_doll",sprintf("%s(%s) 讓凌方真掉下了柳橙娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj12/orange-doll")->move(environment(winner));
        message_vision(HIM"\n從凌方真的身上掉下了一件奇怪的東西!!\n"NOR,winner,me);
        write_file("/log/sky/obj12/orange_doll",sprintf("%s(%s) 讓凌方真掉下了柳橙娃娃於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  if( random(9) == 5 )
  {
    obj=new("/open/magic-manor/obj/wood-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(12) == 7 )
  {
    obj=new("/open/magic-manor/obj/water-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(15) == 9 )
  {
    obj=new("/open/magic-manor/obj/fire-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(18) == 11 )
  {
    obj=new("/open/magic-manor/obj/golden-ball");
    obj->move(environment(winner));
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
  } else if( random(21) == 13 )
  {
    obj=new("/open/magic-manor/obj/soil-ball");
    message_vision(CYN"一顆奇怪的珠子從$N的身體裏滾了出來!!\n"NOR,me);
    obj->move(environment(winner));
  }
  ::die();
}
