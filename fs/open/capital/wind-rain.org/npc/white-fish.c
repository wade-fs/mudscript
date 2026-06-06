// peacock.c by roger

inherit NPC;

void create()
{
	set_name("白羽鱗", ({ "white-fish","fish" }) );
	set("long",@LONG
         這是前七代樓主從塞北帶回
         的稀有魚種, 正悠遊地在水
         中嬉戲著.
LONG);
	set("race","野獸");
	set("age", 2);
	set("str", 6);
	set("con", 6);
	set("max_gin", 60);
	set("max_kee", 200);
	set("max_sen", 60);

	set("limbs", ({ "嘴", "鰓", "左鰭", "右鰭", "尾鰭" }) );
        set("verbs", ({"bite"}) );
	set("chat_chance", 4);
	set("chat_msg", ({
	"\n       魚兒～～魚兒～～水中游～～\n",
	}) );
		
	set("combat_exp",6000);
	setup();
	add_money("coin", 1);
}
