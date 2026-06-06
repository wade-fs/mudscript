#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("落雲槍", ({ "cloudy lance", "lance" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "槍頭隱隱透出藍光，是把不可多得的神兵利器。\n");
                set("value",10000);
                set("material", "blacksteel");
        }

        init_hammer(30);

        set("wield_msg", "$N「剎」地一聲～$n已握在手中。\n");
        set("unwield_msg", "$N將手中的$n揹到身後。\n");

        setup();
}
