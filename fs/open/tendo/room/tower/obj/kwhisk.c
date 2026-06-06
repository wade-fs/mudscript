#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(MAG + "紫羽龍絲拂塵" + NOR,({"dragon whisk","whisk"}) );
        set_weight(1500);
        set("value",5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material","leather");
        set("wield_msg","$N從背後拔出$n握在手中。\n");
                set("unwield_msg","$N將手中的$n掛回背後。\n");
        }
        init_whip(60);
        setup();
}


