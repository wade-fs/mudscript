#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("赤血劍", ({ "blood sword", "sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把以赤金和玄鐵混合煉製的劍，是把能～削金斷玉之利器。");
                set("value",10000);
                set("material", "blacksteel");
        }
        init_sword( 50);

        set("wield_msg", "$N手中赤血劍散發出眩目的紅光～～\n");
        set("unwield_msg", "$N手中的$n的紅光緩緩退去～\n");

        setup();
}
