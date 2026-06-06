#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("尚方寶劍", ({ "god sword", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "皇帝所配帶的寶劍，據說持此劍便有如聖上親臨。劍鞘上鑲著耀眼的寶\n"
                "石，而劍鋒則發出金黃色的劍氣。\n");
                set("value",10000);
                set("material", "gold");
        }
        init_sword(20);

        set("wield_msg", "$N「鏘」地一聲～恭請出$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n謹慎地插入～聖龍劍鞘。\n");

        setup();
}
