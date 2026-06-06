// bandit.c

inherit NPC;

void create()
{
	set_name("小詩",({"poet"}));
	set("gender","女性");
	set("nickname","楚楚動人");
	set("age",14);
	set("long",
		"他是寒谷一派弟子中最年輕的弟子﹐名曰小詩﹐她的資質優異﹐極得師父清雪的喜愛。\n");
	set("combat_exp",5000);
	set("score", 60);
	set("attitude","heroism");
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("force",30);
	set_skill("magic",40);
	set_skill("dodge",60);
	setup();
	add_money("silver", 3);
	create_family("玄冰寒谷",5,"弟子");
}
