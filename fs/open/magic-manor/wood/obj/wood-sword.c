#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        seteuid(getuid());
        set_name(HIG + "綠色靈劍" + NOR,({"wood sword","sword"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","木燃落所使用的寶劍，綠光閃閃奪目，令人無法直視。\n");
                set("value",1000000);
                set("sharp",9);
                set("material","blacksteel");
                set("wield_msg", "拿起$n,$N覺得有一股靈光注入了身軀。\n");
                set("unwield_msg", "$N將手中的$n小心的收起。\n");
		set("magic-manor-obj",1);
	}
        init_sword(100);

        setup();
}

