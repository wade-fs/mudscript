// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("燕翎刀", ({ "swallow blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("unit", "柄");
	  set("value", 1000);
	  set("material", "iron");
	  set("long", "燕翎刀  又名金背大環刀, 刀背厚, 刀頭闊, 刀勢重, 刀背上貫以五只銅環,"+
	  " 揮動時環刀相擊, 酷似燕鳴, 而刀身半片燕羽, 故名「燕翎刀」。 \n");
	}
        init_blade(50);
	setup();
}
