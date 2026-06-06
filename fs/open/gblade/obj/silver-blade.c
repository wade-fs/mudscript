
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("鍍銀刀", ({ "silver blade","blade" }));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把由白銀鍍造而成的刀，刀柄繫著銀綢帶，刀身隱隱泛著白光，這
是金刀門弟子相互拆練招式時所使用的兵刃。\n");
		set("value", 2000);
                set("material", "steel");
                set("wield_msg", "銀光一閃，$N從刀鞘中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插入背後的刀鞘裡。\n");
        }
	init_blade(30);

	set("ski_type1", "blade");
	set("ski_type2", "gold-blade");
	set("ski_level1", 30);
	set("ski_level2", 20);
        setup();
}

