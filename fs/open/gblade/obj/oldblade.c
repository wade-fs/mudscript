#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("柴刀", ({ "blade" }));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
這是一把劈柴用的柴刀，且因為老舊而帶著幾點銹斑，握在手裡感覺刀柄
即將脫落似的。
\n");
                set("value", 90);
                set("material", "iron");
                set("wield_msg", "$N笨拙地從腰間抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回腰間。\n");
        }
        init_blade(3);
        setup();
}
