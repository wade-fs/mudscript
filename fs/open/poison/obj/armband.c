#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name("蛇皮護臂", ({"snake armband","armband"}) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long", "
這是一個由蛇皮硝製成的護臂，邊緣還用銅片交織緊密地結合。\n");
		set("unit", "副");
		set("value", 1000);
		set("material", "leather");
		set("armor_prop/armor",7);
		set("armor_type","armbands");
		set("armor_prop/dodge", 5);

		}
		setup();
}
