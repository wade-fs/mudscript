// peacock.c by roger

inherit NPC;

void create()
{
	set_name("純黑暹羅貓", ({ "black-cat","cat" }) );
	set("long",@LONG
         這是暹羅王送給五代前樓主
         的貓種, 神秘孤傲, 在樓各
         處獨來獨往.
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
	"\n 純黑暹羅貓冷冷地看著你 \n",
	}) );
		
	set("combat_exp",8000);
	setup();
	add_money("coin", 1);
}
