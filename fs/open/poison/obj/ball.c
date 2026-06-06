#include <weapon.h>
#include <ansi.h>
inherit THROWING;


void create()
{
	set_name("鐵蒺藜", ({"iron ball", "ball"}) );
	if ( clonep() )
 		set_default_object(__FILE__);
	else{
		set("long", "
一鋼製的小圓球，上面佈滿了尖刺，為江湖中人常用
的暗器之一。\n");
		set("unit","些");
		set("material","steel");
		set("base_unit","顆");
		set("base_weight",50);
		set("base_value",10);
		
            }
        set_amount(10);
	init_throwing(3);
	setup();
}
