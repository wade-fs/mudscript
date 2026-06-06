
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
	set_name("煙管",({"pipe"}) );
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","
吸煙時所用的煙管，亦可勉強用來當武器使用。\n");
	set("material","iron");
	set("value", 10);
	set("unit","根");
	}
	init_stick(1);
	setup();
}

