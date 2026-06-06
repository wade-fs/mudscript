// one.c by oda

#include "/open/badman/badman.h"

inherit NPC;

void create()
{
	set_name("萬春流", ({ "one tsun liu", "one", "liu" }) );
	set("gender", "男性");
	set("age", 49);
	set("long", "你看到一個中年男子，身著長袍黃冠，羽衣飄飄，瀟然出塵，\n神情看來說不出的和平寧靜。\n他本來是個神醫，所以在惡人谷中的人都靠他治病。\n");
	set("attitude", "peaceful");

	set("str", 22);
	set("cor", 20);
	set("int", 33);
	set("spi", 30);
	set("cps", 32);
	set("con", 28);
	set("combat_exp", 1300);

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
