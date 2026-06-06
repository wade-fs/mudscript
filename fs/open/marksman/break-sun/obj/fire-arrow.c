#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name(HIM + "五" + HIB + "行" + HIW + "箭" + CYN + "《" + HIR + "焰靈" + CYN + "》" + NOR,({"element fire-arrow","arrow"}));
        set_weight(15);
		set("long","蘊藏火之力的靈箭，可克制金系內勁。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","袋");
                set("base_unit","支");
                set("material","blacksteel");
				set("attribute","fire");
        }
init_arrow(111);
set("value",0);
set_amount(300);
        setup();
}
