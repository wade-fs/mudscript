// tujau.c by oda

#include "../badman.h"

inherit NPC;

void create()
{
	set_name("屠嬌嬌", ({ "tu jau jau", "tu", "jau" }) );
	set("nickname", "不男不女");
	set("gender", "女性");
	set("age", 39);
	set("long", "你正在懷疑你眼前的這個人究竟是個美女還是美男子，但是你大概永遠也搞/n不清，因為屠嬌嬌的易容術堪稱天下第一，少有人能看到她的真面目。\n");

	set("str", 25);
	set("cor", 26);
	set("int", 35);
	set("spi", 25);
	set("cps", 30);
	set("con", 22);
	set("per", 35);
	set("combat_exp", 2200);

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
