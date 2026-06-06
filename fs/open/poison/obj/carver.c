
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
void create()
{
	set_name("菜刀",({"carver"}) );
	set_weight(1500);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一把背厚刃薄的菜刀，最適合婦人下廚時使用了，有些潑婦甚至喜歡拿它來
砍她老公:P\n");
		set("material","iron");
		set("value",70);
		set("unit","把");
	}
	init_blade(3);
	setup();
}

