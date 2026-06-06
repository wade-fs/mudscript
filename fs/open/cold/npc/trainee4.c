// bandit.c

inherit NPC;

void create()
{
	set_name("琴貞",({"jane"}));
	set("gender","女性");
	set("age",16);
	set("long",
		"她看起來一副深情默默的樣子﹐似乎為俗塵雜務所染﹐因而不能定下心練功\﹐而被叫來此處靜修。\n");
	set("combat_exp",2000);
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
