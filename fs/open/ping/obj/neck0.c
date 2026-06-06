// by onion
#include <armor.h>

inherit EQUIP;

void create()
{
        set_name("五龍翠玉環", ({ "jade amulet", "amulet" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "環狀綠翡翠上雕著五條騰雲的五爪飛龍, 神態猙獰, 雕的徐徐如生。\n");
	  set("unit", "個");
	  set("value", 2300);
          set("material", "gem");
	  set("armor_type","neck");
	  set("armor_prop/armor", 5);
          set("armor_prop/stabber", 10);
          set("armor_prop/parry", 5);
	}
	setup();
}

