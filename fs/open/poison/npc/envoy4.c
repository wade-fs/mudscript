#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string about_key();
void create()
{
        set_name("索魄使",({"envoy"}));
        set("gender","男性");
        set("class","poisoner");
	set("combat_exp",10000);
        set("age",26);
	set("long","魔教七大使之一，協助執法長老執行教中弟子犯錯之刑罰。\n");
        set("str", 44);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
	set("kee",450);
	set("eff_kee",450);
	set("max_kee",450);
        set("force",450);
        set("max_force",450);
        set("inquiry",([
        "鑰匙"   : (: about_key :),
        "石牢"   : "這是魔教囚禁犯教規之處，我掌管重犯牢房之鑰，其他我是不會說的。",
        "趙青雲" : "這...你去問問我們長老吧。",
        ]));
        set_skill("unarmed",10);
        set_skill("parry",10);
        set_skill("dodge",20);
        set_skill("whip",15);
        set_skill("force",10);
	set_skill("poisonforce",40);
        set_skill("poison",16);
	set_skill("coldpoison",40);
        set_skill("nine-steps",30);
        map_skill("dodge","nine-steps");
        map_skill("force","poisonforce");
	map_skill("poison","coldpoison");
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
                (: perform_action,"poison.faint" :)
        }));
        setup();
        carry_object("/obj/poison/faint_poison")->set_amount(20);
}

string about_key()
{
  object me = this_player();
  if(me->query_temp("have_get_blue"))
        return "我不是已經給你一把鑰匙了。";
  me->set_temp("can_get_blue",1);
  command("hehe");
  command("say 想要鑰匙可以，先跟我比試比試再說。");
  return "有本事的話，鑰匙我就雙手奉上。";
}
int accept_fight(object me)
{
  if(this_object()->is_fighting())
        return notify_fail("你沒看到我正在忙嗎?\n");
  if(me->query_temp("can_get_blue")) {
        me->delete_temp("can_get_blue");
	this_object()->set("fight_turn",10);
        command("grin");
        command("來吧，使出你的看家本領讓我看看。");
        remove_call_out("fighting1");
        call_out("fighting1",1,me);
        return 1;
      }
  return 1;
}
void fighting1(object me)
{
  object ob = this_object();
  int turn = ob->query("fight_turn") -1;
  if(!turn && ob->is_fighting()) {
	ob->remove_all_killer();
	 message_vision("突然使者盪開$N的攻擊，收手回躍三步。\n",me);
	remove_call_out("fighting1");
        remove_call_out("won");
        call_out("won",1,me);
        }
  if(ob->is_fighting() && me->is_fighting()) {
          ob->set("fight_turn",turn);
	  set("kee",450);
	  set("eff_kee",450);
	  set("max_kee",450);
          remove_call_out("fighting1");
          call_out("fighting1",1,me);
         }
/*
  else  if(!me->query_temp("have_get_blue"))
          command("say 哈! 哈! "+me->query("name")+"是如此肉腳，竟也敢向我拿鑰匙。");
*/
}

void won(object me)
{
  object key = new(POISON_OBJ"blue_key");
  me->set_temp("have_get_blue",1);
  key->move(me);
  command("smile");
  command("say 你果然有兩三步，這鑰匙我就交給你了。");
}
