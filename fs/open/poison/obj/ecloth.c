#include <ansi.h>
inherit EQUIP;
void create()
{
	set_name("烏蠶絲衣", ({"black cloth", "cloth"}) );
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "件");
		set("long","
冥蠱教取其烏蠶所吐之絲而織成的絲衣，質輕，但卻異常堅韌。\n");
 
		set("value", 1000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10);
            }
          setup();
}   







