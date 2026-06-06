#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        seteuid(getuid());
        set_name(HIY + "金色靈刀" + NOR,({"golden blade","blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","金極飄所使用的寶刀，金光閃閃的，令人無法直視。\n");
                set("value",1000000);
                set("sharp",9);
                set("material","blacksteel");
                set("wield_msg", "拿起$n,$N覺得有一股靈光注入了身軀。\n");
                set("unwield_msg", "$N將手中的$n小心的收起。\n");
		set("magic-manor-obj",1);
	}
        init_blade(100);

        setup();
}
