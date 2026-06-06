#include <ansi.h>
inherit EQUIP;


void create()
{
	set_name("蛛絲腰帶", ({"silk belt", "belt"}) );
	set_weight(200);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long", "一條由蜘蛛絲織成的腰帶,相當奇特.\n");
		set("material", "cloth");
		set("unit", "條");
		set("value", 100);
		set("armor_type", "waist");
		set("armor_prop/armor", 3);
                setup();
	}
}  
