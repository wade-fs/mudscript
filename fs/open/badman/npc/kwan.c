// kwan.c by oda
#include <ansi.h>

#include "/open/open.h"

inherit NPC;

string do_ask();


void create()
{
	set_name("軒轅三光", ({ "hsanwen san kwan", "hsanwen", "kwan" }) );
	set("nickname", "惡賭鬼");
	set("gender", "男性");
	set("class", "bandit");
	set("attitude", "badman");
	set("age", 45);
	set("long", "他長的滿臉落腮鬍子，一雙眉毛像是兩根柏刷，眼睛卻像是個銅鈴般。\n他的眼睛只剩下一隻，左眼上罩著個黑布罩子，而他的左手也只剩下姆\n指與食指，不過卻更增加了他的慓悍兇猛之氣。\n他就是江湖上最愛賭的人，人稱「惡賭鬼」。據說他連命也敢賭，而且\n決不反悔，如果你被他碰到的話，可得小心小命不保。\n");

	set("str", 36);
	set("cor", 37);
	set("int", 26);
	set("spi", 20);
	set("cps", 29);
	set("con", 30);
	set("per", 15);
	set("combat_exp", 850000);
	set("max_force", 1300);
	set("force", 1300);
	set("force_factor", 10);
	set("max_gin", 1300);
	set("max_kee", 2300);
	set("max_sen", 1300);

	set_skill("badforce", 70);
	set_skill("badstrike", 90);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("ghost-steps", 80);
	set_skill("move", 70);
	set_skill("parry", 50);
	set_skill("unarmed", 80);
	map_skill("force", "badforce");
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	set("functions/evil-blade/level", 30);

	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.evil-blade" :),
	}));
  set("inquiry",([
    "惡人森林" : (: do_ask :),
  ]));

	setup();
	add_money("gold", 10);
}
string do_ask()
{
   object me;
  object who = this_player();
   if(who->query("class")!="bandit")
  {
  kill_ob(this_player());
    return(HIW"你是惡人谷的嗎 ?你怎麼知道這個秘密!?還不領死...!!?"NOR);
  }
  if(who->query_temp("marks/allow")!=1)
  {
    command("shake "+who->query("id"));
     command("say 去問問杜老大的意思吧 !沒有他的同意 ,我可不敢讓你進入森林 .");
   return "還是去問一下好了...";
  }
  else
  {
   command("say 想去惡人森林...?好吧 ,看在同是惡人谷的一份子 ,就讓你進去吧 .");
   tell_object(who,HIY"你忽然覺得腳下一空....哇喔..你覺得被騙了...\n"HIG"再度有了知覺時 ,只看到眼前綠茫茫一片 ,看來這裡就是惡人森林!!\n"NOR,me);
   who->move("/open/badman/room/forest01.c");
   return "就是這裡 !";
  }
}
