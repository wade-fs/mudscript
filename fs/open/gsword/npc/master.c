#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
void create()
{
	set_name("鄭士欣",({"master teng","teng","master"}));
set("long","他就是武林第一大宗師 :鄭士欣 .現正執掌仙劍門戶 .
同時身為劍士公會總會長 .近十餘年來 ,因仙劍七俠已
能獨當一面 ,分擔派內事務 .而公會事務也由三長老柳
毅全權負責 ,鄭士欣每天除了至藏經閣精研武學外 ,就
是在此接見外賓 .\n");
		set("gender","男性");
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
       set_skill("shasword",100);
      set_skill("shaforce",100);
      set_skill("sha-steps",80);
	set("max_force",3000);
	set_skill("array",100);
	set_skill("move",80);
	set_skill("force",60);
	set_skill("dodge",90);
	set_skill("parry",100);
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
	set_skill("sword",120);
        map_skill("force","shaforce");
        map_skill("sword","shasword");
	set_skill("unarmed",60);
	set_skill("whip",100);
	set_skill("blade",40);
	set_skill("spells",40);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("shasword",100);
	map_skill("sword","shasword");
	map_skill("parry","shasword");
	set_skill("cure",60);
	set_skill("dagger",40);
	set("force_factor",10);
	set("chat_chance_combat",50);
	set("chat_msg_combat",({
	(:exert_function,"swordkee":)
	}));
	setup();
	carry_object("/open/gsword/obj/dragon-sword.c")->wield();
	carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
	add_money("gold",10);
	create_family("仙劍派",3,"掌門人");
}

void init()
{
     /*
	add_action("do_join","join");
    */
	add_action("do_select","select");
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
	int do_select(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又沒答應讓你挑? ");
	return 1;
	}
	if(who->query_temp("have_say")==1)
	{
	message_vision(sprintf(HIC"$N說道﹕"+str+"\n"NOR),who);
	command("say 你不是挑過了?");
	return 1;
	}
	if(str=="張乘風" ||  str == "chen fon" || str == "fon")
        {
	 message_vision(HIC"$N說道﹕張乘風\n"NOR,who);
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say 嗯 ,你就拜我的首徒張乘風吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "張乘雲" || str == "chen un" || str == "un")
	{
	message_vision(HIC"$N說道﹕張乘雲\n"NOR,who);
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就拜我的次徒張乘雲吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "范松" || str == "fan son" || str == "son")
	{
	message_vision(HIC"$N說道﹕范松\n"NOR,who);
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就拜我的三弟子范松吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "趙鶴" || str == "san hu" || str == "hu")
	{
	message_vision(HIC"$N說道﹕趙鶴\n"NOR,who);
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就拜我的四弟子趙鶴吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "梁發" || str == "lian fa" || str == "fa")
	{
	message_vision(HIC"$N說道﹕梁發\n"NOR,who);
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就拜我的五弟子梁發吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "何雙雙" || str == "cute girl" || str == "girl")
	{
	message_vision(HIC"$N說道﹕何雙雙\n",who);
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子何雙雙吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "李逍遙" || str == "shou_yau" || str == "yau")
	{
	message_vision(HIC"$N說道﹕李逍遙\n"NOR,who);
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就拜我的七弟子李逍遙吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	command("say 沒這人!");
	return 1;
	}
