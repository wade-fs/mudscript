// sparrow.c by oda
// use in /open/center by powell
// re-write in /open/badman by powell

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
}
void init()
{
       object obj=this_player();
       if (obj->query("race")=="人類" && obj->query("name")!="小販") {
       call_out("gone",2);
       }
}
void gone()
{
       object who = this_player();
       message_vision("小麻雀發現$N走了過來, 便展翅飛到屋頂上。\n",who);
	destruct(this_object());
}
