// sparrow.c by oda

inherit NPC;

void create()
{
	set_name("小麻雀", ({ "Sparrow", "sparrow" }) );
	set("race", "野獸");
	set("age", 2);
	set("long", "一隻貪吃的小麻雀，只顧著尋找食物，完全無視於稻草人的存在。\n");
	set("str", 8);
	set("con", 9);
	set("max_gin", 60);
	set("max_kee", 60);
	set("max_sen", 60);

	set("limbs", ({ "身體", "頭部", "翅膀" }) );
	set("verbs", ({ "poke", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		"小麻雀啄啄稻草人身上的稻草，完全不害怕的樣子。\n"}) );
		
	set("combat_exp",0);

	setup();
}
