
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name("耀日鑌鐵盔",({"helmet"}) );
	set_weight(5000);
	if (clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一頂以上好精鋼打造而成的頭盔，在日光的照耀下散發出耀眼的光芒。\n");
		set("armor_type","head");
		set("material","blacksteel");
		set("unit","頂");
		set("armor_prop/armor",5);
		set("value",350);
		set("armor_prop/dodge",-1);
		setup();
	}
}
