// by onion
#include <armor.h>
inherit EQUIP;
void create()
{
	set_name("綸巾", ({ "hood" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "常見的頭巾, 是書生的標準裝扮\n");
	  set("unit", "條");
          set("value", 30);
	  set("material", "cloth");
	  set("armor_type","head");
	  set("armor_prop/armor", 2);
	}
	setup();
}

