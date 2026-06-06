// rogue.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("小流氓", ({ "rogue" }) );
	set("gender", "男性");
	set("age", 15);
	set("attitude", "badman");
	set("long", "一個整天無所事事的小流氓，看起來就不是什麼好東西。\n");
	set("combat_exp", 800);
	set_skill("parry", 5);
	set_skill("dodge", 5);
	set("max_kee", 150);

	set("chat_chance", 6);
	set("chat_msg", ({
	(: this_object(), "random_move" :),
	"小流氓拿起手中的小刀在你面前挑釁。\n",
	"小流氓瞪著你說道：看三小？再看恁爸給你死喔！\n",
	"小流氓對著你大吼：閃啦！敢擋老子的路？\n",
	}));

	setup();
	carry_object(BAD_OBJ"knife")->wield();
	add_money("silver", 5);
}
