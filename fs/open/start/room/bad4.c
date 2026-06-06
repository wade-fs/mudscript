// hahaer.c by oda

#include "../badman.h"

inherit NPC;

void create()
{
	set_name("哈哈兒", ({ "ha ha er", "ha", "er" }) );
	set("nickname", "笑裡藏刀笑彌陀");
	set("gender", "男性");
	set("age", 44);
	set("long", "你看到一個矮矮胖胖的圓臉胖子，臉上始終維持著一樣的\n笑容，好像不會累似的。\n");
	set("attitude", "friendly");

	set("str", 25);
	set("cor", 25);
	set("int", 30);
	set("spi", 23);
	set("cps", 21);
	set("con", 25);
	set("per", 22);
	set("combat_exp", 2100);

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
