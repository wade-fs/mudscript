
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("鑲銅刀", ({ "bronze blade","blade" }));
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把由青銅鑲造而成的刀，刀柄處繫著黃色緞帶，是金刀門入門弟子初學
刀法所用的兵刃。\n");
set("value",400);
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "黃光一閃，$N從刀鞘中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插入背後的刀鞘裡。\n");
        }
	init_blade(18);

	set("ski_type1", "blade");
	set("ski_level1", 10);
        setup();
}

