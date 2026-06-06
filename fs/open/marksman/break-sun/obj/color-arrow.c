#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name(HIR + "彩" + HIC + "靈" + HIW + "箭" + NOR,({"color-arrow","arrow"}));
        set_weight(15);
		set("long","蘊藏五行之力的靈箭。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","袋");
                set("base_unit","支");
				set("attribute","all");
set("material","blacksteel");
        }
init_arrow(111);
set("value",0);
set_amount(300);
        setup();
}
