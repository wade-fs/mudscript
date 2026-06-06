#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("不拘劍", ({ "wide sword","sword" }));
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把沈重的劍，劍刃寬而厚實，上面還帶著斑斑殷紅的血跡。\n");
                set("value", 1500);
                set("material", "ironsteel");
                set("wield_msg", "$N從劍鞘中抽出$n握在手中.\n");
                set("unwield_msg", "$N將手中的$n插回劍鞘.\n");
        }
	init_sword(60);
        setup();
}
