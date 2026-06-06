// farmer1.c by oda

#include "../start.h"
inherit NPC;

void create()
{
	set_name("農夫", ({ "Farmer", "farmer" }) );
	set("gender", "男性");
	set("age", 30);
	set("long", "你看到一個壯年男子，穿著簡單的汗衫正站在田裡努力的耕田，\n從他黝黑的皮膚，你可以想像其平日工作之辛苦。\n");
	set("attitude", "friendly");

	set("str", 25);
	set("con", 20);
	set("combat_exp", 144);

	set("chat_chance", 5);
	set("chat_msg", ({
		"農夫抬起頭來擦擦額頭上的汗水，又再彎下腰去努力的耕田。\n",
	}) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		"農夫尖叫道：救命啊！有人殺人啊！\n",
		"農夫尖叫道：你要幹什麼？要錢也不用殺我吧！\n",
	}) );

	setup();
	carry_object(S_OBJ"t_shirt")->wear();
}

int accept_fight(object me)
{
	return notify_fail("農夫笑著對你說：這位"+RANK_D->query_respect(me)+"別開玩笑了好嗎?\n");
}
