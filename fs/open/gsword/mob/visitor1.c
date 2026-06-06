// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("武林遊客", ({ "visitor", "man" }) );
	set("gender", "男性" );
	set("age", 45);
	set("str", 15);
	set("cor", 45);
	set("cps", 25);
	set("int", 15);
	set("long",
		"一位帶點武藝的遊客.他正在找地方研讀密籍,\n"
		"一點也沒在意你的到來...\n" );
	set("combat_exp",578);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"武林遊客說: 這蜀山風景真不錯...\n",
		"武林遊客說: 這裡真是個練劍的好地方...\n",
	}) );
	set_skill("sword", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	setup();
	add_money("silver",6);
        carry_object("/open/gsword/obj/sword")->wield();
        carry_object("/open/gsword/obj/robe")->wear();
        carry_object("/open/gsword/obj/sword_book.c");
         	
}

