//made by smirk
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("掃帚",({"broom","broom"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long","這是一支用來掃地的掃帚，堅固可靠。\n");
                set("value",100);
                set("material", "wood");
                set("wield_msg", "$N用力地把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n隨手放在身後。\n");
        }
        init_blade(4);
        setup();
}
