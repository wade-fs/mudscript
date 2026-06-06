#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
        set_name(MAG"美人摺扇"NOR,({"beauty fan","fan"}) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","這是一把材質特殊的扇子 ,畫滿了美女 .\n");
        set("unit","件");
        set("value",10000);
        set("material","steel");
        }
        init_stabber(75);
        set("wield_msg", "$N從懷中掏出一把美人摺扇.\n");
        set("unwield_msg", "$N將手中的美人摺扇放入懷中.\n");
        setup();
}
