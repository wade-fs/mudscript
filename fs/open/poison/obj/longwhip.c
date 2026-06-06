// bleed_whip.c
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("長鞭",({ "long whip","whip"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","條");
	  set("value",500);
		set("material","iron");
		set("long",
	"這是一條普通的長鞭。\n");
	}
	init_whip(15);
	setup();
}
