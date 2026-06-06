// peacock.c by roger

inherit NPC;

void create()
{
	set_name("純白波斯貓 ", ({ "white-cat","cat" }) );
	set("long",@LONG
         這是三代前樓主從波斯帶回
         的貓種, 十分受到姑娘們的
         喜愛.
LONG);
	set("race","野獸");
	set("age", 2);
	set("str", 6);
	set("con", 6);
	set("max_gin", 60);
	set("max_kee", 300);
	set("max_sen", 60);

	set("limbs", ({ "嘴", "爪", "背部", "尾巴", "肚子" }) );
        set("verbs", ({"bite","claw"}) );
	set("chat_chance", 4);
	set("chat_msg", ({
	"\n 純白波斯貓打了個哈欠 \n",
	}) );
		
	set("combat_exp",8000);
	setup();
	add_money("coin", 1);
}
