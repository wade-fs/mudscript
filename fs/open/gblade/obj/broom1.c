#include <weapon.h>

inherit STICK;

void create()
{
        set_name("掃帚", ({ "broom" }));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把滿沾塵埃的掃帚，是長工用來清掃內院用的。
\n");
                set("value", 95);
                set("material", "wood");
                set("wield_msg", "$N遲疑了一下，將一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n放下。\n");
        }
        init_stick(1);
        setup();
}
