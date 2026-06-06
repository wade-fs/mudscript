//排版 與增加保護 yar的mark by blazakira 2011/10/8

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
  object ob;
  set_name("銀狼組暗殺人員",({"silver killer","killer","silver"}) );
  set("long","他在此擔任守護銀狼組的工作，自然手下功\夫不弱 \n");
  set("race", "人類");
  set("gender","男性");
  set("combat_exp",100000);
  set("age",30);
  set("title","黑牙聯的成員");
  set("class","killer");
  set("cor",30);
  set("cps",30);
  set("str",35);
  set("kee",500);
  set("max_kee",500);
  set("force",500);
  set("max_atman",500);
  set("atman",500);
  set("max_force",500);
  set("force_factor",5);
  set("bellicosity",350);
  set_skill("blackforce",35);
  set_skill("force",45);
  set_skill("dodge",55);
  set_skill("parry",55);
  map_skill("force","blackforce");
  map_skill("throwing","rain-throwing");  
  set_temp("invis",1);
  setup();
  ob=carry_object("/open/killer/obj/dag1");
  ob->wield();
  set("guard_yar",1);
}

void init()
{
  object ob;
  ::init();
  set_temp("invis",1);
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1 , ob);
  }
}

void greeting(object ob)
{
  if(!ob) return;
  if( ob->query("class") != "killer")
  {  // 檢查是否為平民，否則會害死新玩家
   if ( ob->query("class"))    
     command("cmd bak "+ob->query("id")); 
  }
}
