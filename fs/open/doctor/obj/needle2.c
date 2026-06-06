#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("小銀針", ({ "silver needle", "needle" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "支");
        set("no_drop",1);
        set("no_give",1);
        set("no_sell",1);
        set("value", 1500);
        set("material", "silver");
                set("long", "這是一支醫生專用的銀針，如果懂得使用技巧的話，將可發揮出極大的威力。\n");
                set("wield_msg", "只見銀光一閃，$N的手中已經多了一支$n。\n");
                set("unwield_msg", "$N將手中的$n收了起來。\n");
        }
        init_stabber(20);
        setup();
}


