#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("鍛金刀", ({ "gold blade","blade" }));
        set_weight(9500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把由純金鍛鑄而成的刀，刀口纖薄而刀背厚實，刀柄一端繫著一束金絲
帶，通體金黃耀眼，奪目欲炫。
\n");
		set("value", 5000);
                set("material", "gold");
                set("wield_msg", "金光一閃，$N從刀鞘中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插入背後的刀鞘裡。\n");
        }
        init_blade(40);

	set("ski_type1", "blade");
	set("ski_type2", "gold-blade");
	set("ski_level1", 40);
	set("ski_level2", 30);
        setup();
}

