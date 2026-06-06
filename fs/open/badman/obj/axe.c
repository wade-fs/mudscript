
#include <weapon.h>

inherit AXE;
void create()
{
        set_name("鐵斧",({"axe"}) );
	set_weight(4000);
	if( clonep())
		set_default_object(__FILE__);
	else{
	set("long","
一把十分鋒利的單刃斧頭，全身以鋼鐵鑄成，拿起來十分地重。\n");
	set("value",120);
	set("material","steel");
	set("unit","柄");
	}
	init_axe(7);
	setup();
}

 
 
