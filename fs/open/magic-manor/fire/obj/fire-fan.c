#include <weapon.h>
#include <ansi.h>

inherit STABBER;

void create()
{
        seteuid(getuid());
        set_name(HIR + "火靈焰扇" + NOR,({"fire fan","fan"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","火飛笙所使用的寶扇，火光閃閃的，令人無法直視。\n");
                set("value",1000000);
                set("sharp",9);
                set("material","blacksteel");
                set("wield_msg", "拿起$n,$N覺得有一股靈光注入了身軀。\n");
                set("unwield_msg", "$N將手中的$n小心的收起。\n");
		set("magic-manor-obj",1);
        }
        init_stabber(100);

        setup();
}
