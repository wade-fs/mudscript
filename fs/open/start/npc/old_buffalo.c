// old_buffalo.c by oda

inherit NPC;

void create()
{
	set_name("老水牛", ({ "Old buffalo", "buffalo" }) );
	set("race", "野獸");
	set("age", 20);
	set("long", "一隻年邁的老水牛，因為不用工作而在田裡閒晃著。\n");

	set("str", 17);
	set("con", 15);
	set("max_gin", 120);
	set("max_kee", 110);
	set("max_sen", 100);

	set("limbs", ({ "身體", "頭部", "前腳", "後腿", "尾巴" }) );
	set("verbs", ({ "hoof", "bite", "dunt" }) );

	set("chat_chance", 12);
	set("random_move",2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"老水牛抬起頭來看看你，接著又低下頭繼續吃草去了，一副懶得理你的樣子。\n"}) );
		
	set("combat_exp", 32);

	setup();
}
