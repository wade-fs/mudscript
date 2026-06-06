// sparrow.c by oda

inherit NPC;

void create()
{
	set_name("雞",({"chicken"}));
	set("race", "野獸");
	set("age", 2);
	set("long","一隻到處咯咯咯﹑跑來跑去的雞。\n");
	set("str", 8);
	set("con", 9);
	set("max_gin", 60);
	set("max_kee", 60);
	set("max_sen", 60);

	set("limbs", ({ "身體", "頭部", "翅膀" }) );
	set("verbs", ({ "poke", "claw" }) );

	set("chat_chance", 3);
	set("chat_msg",({"咯咯咯！\t咯咯咯!\n"}));
		
	set("combat_exp", 0);

	setup();
}
