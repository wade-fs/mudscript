#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name("魔匕",({"daemon dagger","dagger"}));
        set_weight(1000);       
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n藏入懷中。\n");
        }
        init_dagger(30);
        setup();
} 
