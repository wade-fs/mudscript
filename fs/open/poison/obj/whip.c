// bleed_whip.c
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name(HIR "血龍鞭" NOR,({"bleed whip","whip"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","條");
          set("value",30000);
		set("material","iron");
		set("long",
	"這條鞭子上面充滿血色﹐握柄上有一隻龍頭。\n");
	}
	init_whip(80);
	setup();
}
