inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
        object ob;
	set_name("庭園侍從",({"man"}));
	set("long","
負責整理庭園中大小粗重工
作的長工, 他正在巡視庭園
是否有需要整修的地方.
");
	set("gender","男性");
	set("combat_exp",20000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str",30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_kee",1000);
	set_skill("unarmed",5);
	set_skill("dodge",5);
        set_skill("move",5);
/*
        set("chat_chance", 5);
	set("chat_msg", ({
	"\n庭園侍從說 : 齁齁。。。。。昨天晚上和一個小浪貨。。。:D~~\n",
        "\n庭園侍從說 : 小兄弟，知道我為什麼這麼「勇」嗎？因為我都喝「蠻牛」\n",
	}));
*/
	setup();
	add_money("silver",10);
}

