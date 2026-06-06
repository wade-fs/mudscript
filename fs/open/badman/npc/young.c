// vagabond.c by oda
//更新道具的路徑與顏色語法的調整 by blazakira 2010/11/8

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
  set_name("少年",({"young"}) );
  set("long","他的臉上有道從眼角到嘴角的刀疤，\n滿頭黑髮也沒梳好，只打了個結。\n");
  set("race", "人類");
  set("gender","男性");
  set("combat_exp",12345678);
  set("age",18);
  set("no_kill",1);
  set("kee",987654);
  set("max_kee",987654);
  set("force",77777);
  set("max_force",77777);
  set("force_factor",999);
  set_skill("unarmed",150);
  set_skill("badstrike",150);
  map_skill("unarmed","badstrike");
  
  setup();
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1 , ob);
  }
}

void greeting(object ob)
{
  if (ob->query("quests/karup",1))
  {
    message_vision(HIW + "少年說道﹕嗯？怎麼還不離開勒？？\n" + NOR,ob);
  }
  else {
  message_vision(HIG + "\n少年說道﹕嗯，沒事吧？還好我及時趕到，不然你就危險了。
　　　　　這邊可是惡人谷的禁地，以後還是別亂闖的好。" + HIC + "
　　　　　這是你要找的東西嗎？嘻，給你吧，以後要小心點啊。" + HIW + "
　　　　　從這邊往上爬可以爬到谷頂，別再逗留了，危險啊！\n" + NOR,ob);
  new("/autoload/badman/ste.c")->move(ob);
  ob->set("quests/karup",1);
//查不到who->query("marks/fish",1)所代表的意義 所以暫時關閉 by blazakira 2010/11/8
//  ob->set("marks/fish",1);
  }
}
