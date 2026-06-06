// bleed_whip.c
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("小魔鞭", ({"whip"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","條");
		set("value", 0);
		set("no_drop",1);
		set("material","iron");
		set("long",
	"這是一條小小的鞭子，非常方便隨身攜帶以防身。\n");
	}
	init_whip(3);
	setup();
}
