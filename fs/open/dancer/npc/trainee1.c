// For the new hand of dancer ...//purple
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("稚齡少女", ({ "yanggirl" }) );
	set("title", "夜夢小築見習生");
	set("gender", "女性");
	set("long", "慕名而來，欲拜月牙兒為師，而成為舞者的見習生。\n");
	set("age",12);
	set("attitude", "heroism");
         set("kee",1000);
        set("max_kee",1000);
	set("combat_exp",2300);
	setup();
}
