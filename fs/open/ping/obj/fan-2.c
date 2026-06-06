// made by ccat
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("精鋼鐵扇",({"steal fan","fan"}) );
        set_weight(25000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long",".\n");
        set("unit","件");
        set("value", 500);
	set("material","iron");
	}
        init_stabber(20);
        set("wield_msg", "$N從懷中掏出一把鐵扇.\n");
        set("unwield_msg", "$N將手中的鐵扇放入懷中.\n");
        setup();
}
