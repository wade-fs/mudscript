#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string about_key();
void create()
{
        set_name("勾魂使",({"envoy"}));
        set("gender","男性");
        set("class","poisoner");
	set("combat_exp",10000);
        set("age",26);
	set("long","魔教七大使之一，協助執法長老處理教中刑罰之事。\n");
        set("str", 44);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
        set("force",450);
        set("max_force",450);
        set("inquiry",([
        "鑰匙"   : (: about_key :),
        "石牢"   : "這是魔教囚禁犯教規之處，我掌管一般牢房之鑰，其他我是不會說的。",
        "趙青雲" : "這...你去問問我們長老吧。",
        ]));
        set_skill("unarmed",10);
        set_skill("parry",10);
        set_skill("dodge",20);
        set_skill("whip",15);
        set_skill("force",10);
        set_skill("poisonforce",15);
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
  if(me->query_temp("have_get_red"))
        return "我不是已經給你一把鑰匙了。";
  if(me->query_temp("poison_help") != 3)
        return "哦! 現在我身上並沒有鑰匙，你要鑰匙做啥! ";
  me->set_temp("can_get_red",1);
  command("say 我懷疑你是假傳教令，否則教主怎會將教令傳於你。");
  return "要鑰匙可以，先跟我比一場，讓我相信你的實力再說。";
}
int accept_fight(object me)
{
  object key;
  if(me->query_temp("can_get_red")) {
        me->delete_temp("can_get_red");
	me->set_temp("have_get_red",1);
        key = new(POISON_OBJ"red_key");
        key->move(me);
        command("smile");
        command("say 果然是英雄出少年，你有這般的勇氣，難怪教主會信賴你。");
	command("say 好! 好! 這把鑰匙我就教給你了。");
	return notify_fail("");
       }
  return 1;
}
