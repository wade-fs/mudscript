//vendor.c
//增加暱稱等特色 by blazakira 2011/10/12

#include "/open/open.h"
inherit F_VENDOR;

void create()
{
  set_name("凌雲村小販",({"vendor"}));
  set("gender", "男性" );
  set("nickname","傳家好茶");
  set("age", 27);
  set("long", @LONG
四處設攤賣些小東西的人,你可以列出(list)他賣些什麼...
LONG
  );
  set("combat_exp",576);
  set("ann_die",1);
  set("attitude", "friendly");
  set("score",10000000);
  set_skill("dodge", 40);
  set_skill("hammer", 20);
  set_skill("parry", 30);
  set("vendor_goods", ({
    "/obj/example/besttea",
    "/obj/example/dumpling",
    "/obj/example/chicken_leg",
    "/open/zombie_hole/obj/line.c"
  }) );
  setup();
  add_money("coin",35);
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(4) ) {
    case 0:
      say("小販靠近你小聲的說: 這位"+RANK_D->query_respect(ob)+"來買些東西吧!\n");
      break;
    case 1:
      say("小販嘶聲么\喝道: "+RANK_D->query_respect(ob)+"過來看看嗎!?\n");
      break;
    case 2:
      say("小販大聲招呼道: 端陽節已經過完了，"+RANK_D->query_respect( ob )+"來看點別的吧？\n");
      break;
    case 3:
      say("小販在你耳邊悄悄地說: 嘿，"
        +RANK_D -> query_respect( ob )
        +"，這兒可是有賣以我祖傳秘方特製的凍頂烏龍茶，別的地方絕對買不到喔！\n");
      break;
  }
}
