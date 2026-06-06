#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
void create()
{
	// 我多加了個 id == swordsman, wade in 1/4/1996
	set_name("柳毅",({"master swordsman","master","swordsman"}));
 set("long","劍士公會三長老 ,負責在署中城接收新會員 .\n");
	set("gender","男性");
	set("guild_master",1);
	set("class","swordsman");
	set("nickname","飛音劍");
        set("combat_exp",1000000);
        set("attitude","heroism");
	set("age",43);
	set("title","劍士公會三長老");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",3000);
	set_skill("literate",40);
	set("kee",3000);
	set("max_kee",3000);
	set("max_force",3000);
	set_skill("array",70);
	set_skill("move",60);
	set_skill("force",50);
	set_skill("dodge",80);
	set_skill("parry",90);
	set_skill("sword",100);
	set("force_factor",10);
//	set_skill("hammer",20);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
	     (: command,"perform sword.swordkee" :),
	}));
	setup();
	carry_object("/open/gsword/obj/heaven-sword")->wield();
	add_money("gold",10);
}

void init()
{
	add_action("do_join","join");
}
int do_join()
	{
	if(this_player()->query("class"))
		return notify_fail("你已經加入其他工會了。\n");
	this_player()->set("class","swordsman");
	message("system",HIW "柳毅縱聲大呼 :\n
歡迎" +this_player()->name()+"加入劍士公會!!\n\n"NOR,users());
	return 1;
}
   /*
	int do_say(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又沒答應讓你挑? ");
	return 0;
	}
	if(who->query_temp("have_say")==1)
	{
	command("say 你不是挑過了?");
	return 0;
	}
	if(str=="張乘風")
        {
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say 嗯 ,你就拜我的首徒張乘風吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="張乘雲")
	{
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就拜我的次徒張乘雲吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="范松")
	{
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就拜我的三弟子范松吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="趙鶴")
	{
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就拜我的四弟子趙鶴吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="梁發")
	{
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就拜我的五弟子梁發吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="何雙雙")
	{
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子何雙雙吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="李逍遙")
	{
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就拜我的七弟子李逍遙吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	command("say 沒這人!");
	return 0;
	}
  */
