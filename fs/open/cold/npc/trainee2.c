// bandit.c

inherit NPC;

void create()
{
	set_name("穎潔",({"gere"}));
	set("gender","女性");
	set("nickname","寒霜美人");
	set("per",35);
	set("age",18);
	set("long",
		"在眾多寒谷弟子中﹐她的美貌算是最為出色的﹐因此得到「寒霜美人」之美譽。\n");
	set("combat_exp",10000);
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
