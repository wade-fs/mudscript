//baby.c by chun

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("嬰兒",({"baby"}));
	set("long","一個不到兩歲的小寶寶，超大音量的哭聲似乎代表\n著來到這世界的喜悅。\n");
	set("str",1);
	set("con",1);
	set("cor",1);
	set("int",1);
	set("max_kee",5);
	set("max_gin",5);
	set("max_sen",5);
	set("age",1);
	set("combat_exp",32);
	setup();
}

