#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        seteuid(getuid());
        set_name("風妖劍",({"daemon sword","sword"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",30000);
                set("material", "steel");
                set("wield_msg", "拿著$n,$N覺的渾身充滿了妖力.\n");
                set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        }
        init_sword(40);
        setup();
}
                                                                        
