inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("風之葉",({"wind leaf","leaf"}));
	set("long","千年樹妖-舞風揚身上取下的一片葉子。\n");
	set("unit","片");
	set("value",100000);
	set("magic-manor",3);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
