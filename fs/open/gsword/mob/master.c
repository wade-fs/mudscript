#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
void create()
{
	   set_name("鄭士欣",({"master swordsman","master"}));
set("long","他就是武林第一大宗師 :鄭士欣 .現正執掌仙劍門戶 ,仙劍雖是
近幾十年來的新派 ,但在幾任掌門苦心經營下 ,早就名列江湖第
一大派 ,仙劍武學也在幾位宗師的鑽研 ,整理下 ,構成今日名滿
天下的仙劍劍法 ,此套劍法共有八路 ,鄭士欣分別傳授一路劍法
於仙劍七俠 ,至於這第八路嘛 ...\n");
		set("gender","男性");
	set("guild_master",1);
	set("class","swordsman");
	 set("nickname","無極真人");
          set("combat_exp",1000000);
          set("attitude","heroism");
	  set("age",76);
	set("title","仙劍派第三代掌門人");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",3000);
	set_skill("literate",80);
	set("max_force",3000);
	set_skill("array",100);
	set_skill("move",80);
	set_skill("force",60);
	set_skill("dodge",90);
	set_skill("parry",100);
	set_skill("sword",120);
	set_skill("unarmed",60);
	set_skill("whip",100);
	set_skill("blade",40);
	set_skill("spells",40);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("nine-steps",80);
	map_skill("dodge","nine-steps");
	map_skill("move","nine-steps");
	set_skill("shansword",100);
	map_skill("sword","shansword");
	map_skill("parry","shansword");
	set_skill("cure",60);
	set_skill("dagger",40);
	set("force_factor",10);
	setup();
	carry_object("/open/gsword/obj/dragon-sword.c")->wield();
	carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
	add_money("gold",10);
	create_family("仙劍派",3,"掌門人");
}

void init()
{
	add_action("do_join","join");
	add_action("do_say","select");
}
  void attempt_apprentice(object ob)
{
	if(ob->query("marks/仙劍七俠")==1)
	{
	if((int)this_player()->query("combat_exp")<=100000)
	{
	command("? " +ob ->query("id"));
	command("say 你不是拜過我的弟子了?");
	command("say 以你的程度還不須我親自指導!");
	command("say 好好跟著你師父多學幾年吧!");
	return 0;
	}
	command("look "+ob->query("id"));
	command("smile");
	command("say 好,你果然是可造之才,從今後就由老夫親自指導!");
	command("recruit "+this_player()->query("id"));
	message("system",HIW"鄭士欣縱聲大笑: 
哈哈哈哈....老夫實在太高興啦!
英雄出少年 ,"+this_player()->name()+": 今後就由老夫親授於你.\n"NOR,users());
	return ;
	}
      command("hmm");
	command("say 我老啦 ,你去拜我的七個徒弟吧 !");
	command("say 你想拜(select)誰呢?");
	ob->set_temp("allow_select",1);
}
int do_join()
	{
	if(this_player()->query("class"))
		return notify_fail("你已經加入其他工會了。\n");
	this_player()->set("class","swordsman");
	message("system",HIW "鄭士欣縱聲大呼 :\n
歡迎" +this_player()->name()+"加入劍士公會!!\n\n"NOR,users());
	return 1;
}
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
