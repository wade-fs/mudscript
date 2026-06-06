// bandit.c

inherit NPC;

void create()
{
	set_name("完顏秀",({"show"}));
	set("gender","女性");
	set("age",17);
	set("long",
		"他是由東北前來此處拜師學藝的異族人﹐名曰「完顏秀」。\n");
	set("combat_exp",6000);
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
