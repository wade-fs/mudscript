// sparrow.c by oda
// use in /open/center by powell

inherit NPC;

void create()
{
	set_name("小麻雀", ({ "sparrow" }) );
	set("long", "一隻貪吃的小麻雀，左腳緊緊抓著一個閃閃發光的東西，\n跳來跳去的，完全無視於危險的存在。\n");
	set("race","野獸");
	set("age", 2);
	set("str", 8);
	set("con", 9);
	set("max_gin", 60);
	set("max_kee", 60);
	set("max_sen", 60);

	set("limbs", ({ "尖嘴", "翅膀", "左腳", "右腳", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );
	set("chat_chance", 4);
	set("chat_msg", ({
		"小麻雀啄啄你身上的衣物，完全不害怕的樣子。\n",
	}) );
		
	set("combat_exp",80);
	setup();
	add_money("coin", 1);
}
