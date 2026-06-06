// bandit.c

inherit NPC;

void create()
{
	set_name("秋兒",({"fall"}));
	set("gender","女性");
	set("age",15);
	set("long",
		"他看起來一臉稚氣﹐可愛中帶著一點秀氣﹐她的名字叫秋兒。\n");
	set("combat_exp",8000);
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
