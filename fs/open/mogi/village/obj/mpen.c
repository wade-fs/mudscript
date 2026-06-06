#include <weapon.h>
#include <ansi.h>

inherit STABBER;

void create()
{
        set_name("封佛筆",({"daemon pen","pen"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value",1500);
                set("material", "steel");
                set("wield_msg", "$N從懷裡拿出一隻$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n收進懷裡。\n");
        }
        init_stabber(30);
        setup();
} 
                        
