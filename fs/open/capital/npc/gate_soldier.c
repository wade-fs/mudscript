//守衛 made by chun,fix by funkcat, onion 重新改寫
		
#include "/open/open.h"
inherit NPC;
string do_help();
object ob=this_object();

void create()
{
	set_name("城門衛軍",({"gate soldier","soldier"}) );
	set("gender","男性");
	set("age",33);
	set("class","soldier");
	set("str",55);
	set("long","京城內位階較低的軍官﹐負責城門的守衛工作﹐一身軍服看起來帥呆了。\n");
        set("combat_exp",25000);
	
	set("max_kee",1000);
	set("chat_chance_combat", 2);
	set("chat_msg_combat",({
	"城門衛軍喝道：敢在在此搗亂..不想活了是吧!!\n",
	(: this_object(),"do_help" :),
	}) );
	set("inquiry", ([
	"thief" : "大盜? 雖然大家都在說, 可是我還是沒遇著過。  :P ",
	]));
	set_skill("blade",40);
	set_skill("parry",30);
	set_skill("dodge",20);
	set_skill("her-blade",60);
	map_skill("blade","her-blade");
        set_temp("apply/damage",50);
        set_temp("apply/dodge",50);
        set_temp("apply/attack",50);
	setup();
	carry_object(CAPITAL_OBJ"Ns_armor")->wear();
	carry_object(CAPITAL_OBJ"Ns_boots")->wear();
	carry_object(CAPITAL_OBJ"Ns_hat")->wear();
	carry_object(CAPITAL_OBJ"Ns_blade")->wield();
}

void init()
{
	object who;
	:: init();
	if(interactive(who =this_player()) && !is_fighting() )
		add_action("do_report","report");
}

int accept_fight(object who)
{
	return notify_fail("城門衛軍說：對不起，我正在執行公務。\n");
}
int accept_kill(object who)
{
	command("say 大膽"+who->query("name")+", 膽敢鬧事!!");
	who->set_temp("殺城門衛軍",1);
	return 1;
}
string do_help()
{
	object guard;
	command("say ㄜ..糟糕, 撐不住了..");
	say("城門衛軍招來他的同伴幫忙抵擋敵人。\n");
	guard=new(CAPITAL_NPC"gate_soldier");
	guard->move( environment() );
	guard->kill_ob( ob->query_enemy()[0] );
	return "城門衛軍喝道：來人啊..給我上..\n";
}
void greeting(object who)
{
	if( !is_fighting() && !who->query_temp("殺城門衛軍") ) {
	if( who->query_temp("有向城門守衛報告") || wizardp(who) ) {
		command("smile "+getuid(who) );
		command("say "+who->name()+"好, 歡迎參觀京城。 :)");
	}
       	else {
		command("stare "+getuid(who));
		command("say ㄜ！這位"+RANK_D->query_respect(who)+", 哪裡來的？報上(report)名來。");
	}
	}
}

int do_report(string arg)
{
	object who=this_player();

	if( !arg || arg != getuid(who) )
		return notify_fail("請告訴我你的id。\n");

	if( who->query_temp("有向城門守衛報告") )
	  return notify_fail("我已經知道了，你不用對我說這麼多次, 你的id是"+getuid(who)+"，對吧？\n");
	who->set_temp("有向城門守衛報告",1);
	who->delete_temp("殺京城巡邏禁衛軍");
	command("say 謝謝您的合作，現在您可以通過了。\n");
	return 1;
}
