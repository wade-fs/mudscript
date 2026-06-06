#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name(HIM"五"HIB"行"HIW"箭"CYN"《"HIG"神木"CYN"》"NOR,({"element wood-arrow","arrow"}));
        set_weight(15);
		set("long","蘊藏木之力的靈箭，可克制土系內勁。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","袋");
                set("base_unit","支");
                set("material","blacksteel");
				set("attribute","wood");
        }
init_arrow(111);
set("value",0);
set_amount(300);
        setup();
}
