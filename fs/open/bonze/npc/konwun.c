//增添少林特色技能與fun by blazakira 2010/06/04
inherit NPC;
#include <ansi.h>
#include <npc.h>
#include <combat.h>
void create()
{
	set_name("空聞",({"kon wun","wun"}));
	set("title","寺門接待首座");
	set("gender","男性");
	set("class","bonze");
	set("age",55);
	set("long","空聞是少林寺空字輩的僧人，主要負責接待訪客的工作，看似溫文儒雅，其實卻是深藏不露。\n");
	set("combat_exp",5000000);
	set("cor",10);
	set("spi",35);
	set("str",50);
	set_skill("move",60);
	set_skill("dodge",50);
	set_skill("unarmed",70);
//	set_skill("longfist",100);
	set_skill("saulin-kee",100);
	set_skill("yu-steps",100);
	set_skill("parry",70);
	set_skill("force",120);
    set_skill("bonze-martial",100); //少林拳法 unarmed
	set_skill("saulinforce",120);
//	set_skill("haoforce",100);
	map_skill("force","saulinforce");
//	map_skill("force","haoforce");
	map_skill("unarmed","bonze-martial");
//	map_skill("unarmed","longfist");
	map_skill("parry","saulin-kee");
	map_skill("dodge","yu-steps");
	set("functions/bergamon/level",49);
	set("bonze/force/kingforce",1);
	set("env/force","kingforce");
	set("s_kee",700);
	set("max_s_kee",400);
	set("sec_kee","dhyana");
	set("force",10000);
	set("max_force",5000);
/*	set("max_gin",3000); //現今fs的經驗值給予的數值較原先高許多 因此暫時不調整而關閉
	set("max_kee",3000);
	set("max_sen",3000);*/
	set("chat_chance", 3);
	set("chat_msg", ({
		"空聞合十說道:少林寺已有百年以上的歷史\n",
		"空聞朗聲說道:少林弟子首重修行，練武只是強身\n",
		"空聞說道:施主是來修行的嗎?\n"}));
	setup();
	carry_object("/open/bonze/obj/boots")->wear();
}

void init()
{
	set_heart_beat(1);
	::init();
}

void greeting(object ob)
{
	ob=this_player();
	if(ob->query_temp("ask_force"))	{
		message_vision(HIW"空聞大聲道:「邪魔外道，覬覦我佛門至寶!?想要心法是吧!?
		你也不用進去了，這就給我去跟閻羅王要吧!!」\n\n"NOR,ob);
		kill_ob(ob);
	}
}

int accept_fight(object who)
{
	command("say 本寺嚴禁對外比武，還請見諒。\n");
	return 0;
}

void die()
{
	object me,obj,winner;
	me=this_object();
	winner=query_temp("last_damage_from");

	if(winner->query_temp("ask_force")) {
		message_vision(HIW"空聞說道:「......」\n"NOR,winner);
		message_vision(HIR"" + winner->query("name") + "得到了本來無一物神功\心法。\n"NOR,winner);
		obj=new("/open/capital/obj/force_book");
		obj->move(winner);
		}
	::die();
}

void heart_beat()
{
	object me=this_object();
	if( !me->is_fighting() && !me->query_temp("beg_ok") ) {
		command("perform saulinforce.bergamon");
	}
	else if( !me->is_fighting() && me->query("s_kee") < me->query("max_s_kee")/3) {
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
		command("exert reseckee");
	}
	else if( !me->is_fighting() && me->query("force") < me->query("max_force")/2) {
		command("ex 160");
		command("exert recover");
	}

	::heart_beat(); //不可放在這段if裡面 會因沒辦法判斷而失去效用
}