// bandit.c

inherit NPC;

void create()
{
	set_name("邢尤安",({"ann"}));
	set("age",19);
	set("nickname","玲瓏仙子");
	set("long",
		"她是寒谷第四代大弟子﹐也是行宮中的總教師﹐平時負責教授第五代弟子武術及仙法。\n");
	set("combat_exp",100000);
	set("score", 60);
	set("attitude","heroism");
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("force",30);
	set_skill("magic",80);
	set_skill("dodge",80);
	setup();
	add_money("silver", 3);
	create_family("玄冰寒谷",4,"弟子");
}
