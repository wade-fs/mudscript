#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("血斬", ({ "blood blade","blade" }));
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把滿沾血跡的斬刀，刀背因為血跡凝乾，而有層層的血塊剝落，刀刃處
卻仍然有鮮血滴落。
\n");
                set("value", 1200);
                set("material", "steel");
                set("wield_msg", "$N沾滿鮮血的雙手從背後抽出$n握在手中.\n");
                set("unwield_msg", "$N將手中的$n插回背後的刀鞘裡.\n");
        }
	init_blade(50);
        setup();
}
