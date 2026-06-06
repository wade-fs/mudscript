
#include <ansi.h>
#include <weapon.h>

inherit AXE;
void create()
{
	set_name("斧頭",({"axe"}) );
	set_weight(4000);
	if( clonep())
		set_default_object(__FILE__);
	else{
	set("long","
一把十分鋒利的雙刃斧頭，以木頭為柄，是上山砍柴樵夫的最愛。\n");
	set("value",120);
	set("material","steel");
	set("unit","柄");
	}
	init_axe(7);
	setup();
}

 
 
