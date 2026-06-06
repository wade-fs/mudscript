// old_buffalo.c by oda

inherit NPC;

void create()
{
	set_name("小水牛",({"young buffalo","buffalo"}) );
	set("race", "野獸");
	set("age",3);
	set("long","年幼的小水牛，因為力氣還不夠大無法犁田\n所已被飼養在這。\n");

	set("str", 14);
	set("con",13);
	set("max_gin", 100);
	set("max_kee", 100);
	set("max_sen", 100);

	set("limbs", ({ "身體", "頭部", "前腳", "後腿", "尾巴" }) );
	set("verbs",({"hoof","bite","dunt"}) );

		
	set("combat_exp",12);

	setup();
}
