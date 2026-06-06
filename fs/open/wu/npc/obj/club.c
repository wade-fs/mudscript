#include <weapon.h>

inherit STAFF;

void create()
{
        set_name( "冰火風雷棍" , ({ "club"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "這是一根看起來普普通通的棍子。\n");
                set("value", 300);
                set("material", "wood");
        }
        init_staff(20);

        set("wield_msg", "只見到$N右手一晃，手上頓時出現一把$n。\n");
        set("unwield_msg", "$N吐了一口氣，將$n綁在背上。\n");

        setup();
}

