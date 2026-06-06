#include <weapon.h>
#include <ansi.h>

inherit	UNARMED;

void create()
{
        seteuid(getuid());
        set_name(YEL + "土色靈爪" + NOR,({"soil claw","claw"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","土爆波所使用的寶爪，土光隱隱發出微微光芒，令人心神寧靜。\n");
                set("value",1000000);
                set("sharp",9);
                set("material","blacksteel");
                set("wield_msg", "拿起$n,$N覺得有一股靈光注入了身軀。\n");
                set("unwield_msg", "$N將手中的$n小心的收起。\n");
		set("magic-manor-obj",1);
	}
        init_unarmed(100);

        setup();
}
