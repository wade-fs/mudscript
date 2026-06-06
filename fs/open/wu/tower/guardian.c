//guardian.c for tower ...... made by Pokai 

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("守塔老者",({"tower older","guard","older"}));
	set("gender","男性");
	set("age",65);
	set("fighter","");
	set("str",25);
        set("long","負責看守七殺塔的老人，要是你的程度太差，那他可是會趕你走的。\n");
	set("combat_exp",40000);
	
	setup();
	carry_object("/open/wu/obj/cloth.c")->wear();
}


int accept_fight(object who)
{
return notify_fail("老者笑了笑說，小朋友，我是不會想欺負你的。\n");
}

