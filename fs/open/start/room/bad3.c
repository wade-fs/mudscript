// lee.c by oda

#include "../badman.h"

inherit NPC;

void create()
{
	set_name("李大嘴", ({ "lee da tswei", "lee", "tswei" }) );
	set("nickname", "不吃人頭");
	set("gender", "男性");
	set("age", 40);
	set("long", "你看到一個相貌不凡的男子，但是事實上他竟是傳說中，除了\n人頭以外什麼都吃的李大嘴。\n");

	set("str", 32);
	set("cor", 29);
	set("int", 22);
	set("spi", 20);
	set("cps", 22);
	set("con", 30);
	set("per", 32);
	set("combat_exp", 2400);

	// set("chat_chance", 5);
	set("chat_msg", ({
		"農夫抬起頭來擦擦額頭上的汗水，又再彎下腰去努力的耕田。\n",
	}) );
	// set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		"農夫尖叫道：救命啊！有人殺人啊！\n",
		"農夫尖叫道：你要幹什麼？要錢也不用殺我吧！\n",
	}) );

	setup();
	// carry_object(S_OBJ"t_shirt")->wear();
}

int accept_fight(object me)
{
	return notify_fail("農夫笑著對你說：這位"+RANK_D->query_respect(me)+"別開玩笑了好嗎?\n");
}
