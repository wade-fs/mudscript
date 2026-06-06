// din.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("歐陽丁", ({ "oyawn din", "oyawn", "din" }) );
	set("nickname", "拼命佔便宜");
	set("gender", "男性");
	set("age", 41);
	set("long", "這個人瘦骨嶙峋，雙顴凸出，一付富商大賈的打扮，是歐陽當的巒生兄弟。\n");

	set("str", 24);
	set("cor", 24);
	set("int", 29);
	set("spi", 25);
	set("cps", 22);
	set("con", 25);
	set("per", 27);
	set("combat_exp",112);

	// set("chat_chance", 5);
	// set("chat_msg", ({
	// 	"農夫抬起頭來擦擦額頭上的汗水，又再彎下腰去努力的耕田。\n",
	// }) );
	// set("chat_chance_combat", 50);
	// set("chat_msg_combat", ({
	// 	"農夫尖叫道：救命啊！有人殺人啊！\n",
	// 	"農夫尖叫道：你要幹什麼？要錢也不用殺我吧！\n",
	// }) );

	setup();
	// carry_object(S_OBJ"t_shirt")->wear();
}

// int accept_fight(object me)
// {
// 	return notify_fail("農夫笑著對你說：這位"+RANK_D->query_respect(me)+"別開玩笑了好嗎?\n");
// }
