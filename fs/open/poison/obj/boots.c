
#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name("牛皮小靴",({"boots"}) );
	set_weight(2000);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一雙以上好牛皮製成，外層覆以毛皮的靴子，不但保暖，更能保護腳部不受
傷害。\n");
		set("unit","雙");
		set("value",170);
		set("armor_prop/armor",3);
		set("armor_prop/dodge",2);
		set("material","leather");
		set("armor_type","boots");
		setup();
	}
}
