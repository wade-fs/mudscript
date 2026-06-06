
#include <ansi.h>

inherit EQUIP;

void create() 
{
	set_name("斗笠",({"hat"}) );
	set_weight(1100);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一頂以細竹枝和曬乾的竹葉編成的斗笠，既可遮陽，亦可擋雨。\n");
		set("material","plant");
		set("value",15);
		set("unit","頂");
		set("armor_type","head");
		set("armor_prop/armor",2);
		setup();
	}
}
