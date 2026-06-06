//vendor.c
//調整greeting(object ob)裡的判斷順位 以避開錯問產生 by blazakira 2011/5/1
//增加暱稱等特色 by blazakira 2011/10/12

#include "/open/open.h"
inherit F_VENDOR;

void create()
{
  set_name("平南城小販",({"vendor"}));
  set("gender", "男性" );
  set("nickname","專賣西域神器");
  set("age", 27);
  set("long", @LONG
四處設攤賣些小東西的人,你可以列出(list)他賣些什麼...
LONG
  );
  set("combat_exp",800);
  set("ann_die",1);
  set("attitude", "friendly");
  set_skill("dodge", 25);
  set_skill("hammer", 17);
  set_skill("parry", 27);
  set("vendor_goods", ({
    COMMON_OBJ"bandage",
    COMMON_OBJ"pill",
    COMMON_OBJ"pill1",
    COMMON_OBJ"plaster",
    PING_OBJ"cloud",
    CAPITAL_OBJ"tea",
    "/obj/example/wineskin",
    "/obj/example/dumpling",
    "/obj/example/chicken_leg",
  }) );
  setup();
  carry_object("/obj/example/chicken_leg")->wield();
  carry_object("/open/gsword/obj/robe")->wear();
  add_money("coin",35);
}

void greeting(object ob)
{
  int gender,per;
  gender = 0;
  if( !ob || environment(ob) != environment() ) return;
  per = ob->query_per();
  if( ob->query("gender") == "女性")
    gender = 1;
  switch( random(3) ) {
    case 0:
      if( per < 18 && gender)
        say("小販靠近你小聲的說: 唉！"+ob->name(1)+"，也\\許\妳該去一下媚登峰！\n");
      say("小販靠近你小聲的說: 這位"+RANK_D->query_respect(ob)+"來買些東西吧！\n");
      break;
    case 1:
      if( per > 22 )
        say("小販嘶聲么\喝道: "+ob->name(1)+"長的好像電影明星喔！\n");
      say("小販嘶聲么\喝道: "+RANK_D->query_respect(ob)+"，西域神器喚雲扇，很有用喔！過來看看嗎!?\n");
      break;
    case 2:
      if( per < 15)
        say("小販小聲的說: "+ob->name(1)+"，請具備一點公德心好嗎？人長的"+"醜就不要上街嚇人。\n");
      else if( per > 26 && gender)
        say("小販讚嘆道: 哇！大美女"+ob->name(1)+"，妳可真是天仙下凡呀!!\n");
      say("小販高聲喊道: 跳樓大拍賣，"+RANK_D->query_respect(ob)+"要的話，我可以算便宜一點喔！\n");
      break;
  }
}
