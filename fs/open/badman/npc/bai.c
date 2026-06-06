// bai.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("白開心", ({ "bai kai hsin", "bai", "hsin" }) );
	set("nickname", "損人不利己");
	set("class","bandit");
	set("gender", "男性");
	set("attitude","badman");
	set("age", 40);
	set("long", "你看到一個中年男子，穿著雖然像個富商紳士，神態卻像是個地痞無賴。\n你看他開心的樣子，不知道又做了什麼損人不利己的缺德事了。\n");

	set("str", 30);
	set("cor", 28);
	set("int", 30);
	set("spi", 24);
	set("cps", 25);
	set("con", 28);
	set("per", 20);
	set("combat_exp", 700000);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 10);
	set("max_gin", 1000);
	set("max_kee", 2000);
	set("max_sen", 1000);

	set_skill("badforce", 60);
	set_skill("badstrike", 80);
	set_skill("dodge", 50);
	set_skill("force", 50);
	set_skill("ghost-steps", 70);
	set_skill("move", 60);
	set_skill("parry", 40);
	set_skill("unarmed", 70);
	map_skill("force", "badforce");
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	set("functions/evil-blade/level", 25);

	set("chat_chance", 5);
	set("chat_msg", ({
	}) );
	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.evil-blade" :),
	}) );

	setup();
	add_money("gold", 10);
}
