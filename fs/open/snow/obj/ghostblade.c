// blade.c
#include <weapon.h>
inherit BLADE;

void create()
{
set_name("鬼影殘風刀",({"ghost blade","blade"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
     set ("unit","柄");
          set("value", 10000);
		set("material", "iron");
set("long","這是一把神兵利器『鬼影殘風刀』。\n");
          set("wield_msg", "$N裝備$n。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
          set("armor_prop/blade",10);
          init_blade(80);
	setup();
}
