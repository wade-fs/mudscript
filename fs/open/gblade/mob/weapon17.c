#include <weapon.h>

inherit STICK;

void create()
{
        set_name("羅漢棍", ({ "lohan stick","stick" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "
玄鐵鑄成，棍身長一丈又六尺，通體烏黑且帶著墨色的光澤，雖不耀眼卻
黯然內斂。
\n");
                set("value", 1000);
                set("material", "ironsteel");
                set("wield_msg", "$N將$n緊緊握在手中.\n");
                set("unwield_msg", "$N將手中的$n放下.\n");
        }
	init_stick(50);
        setup();
}
