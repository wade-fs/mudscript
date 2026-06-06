#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(HIY + "流星鞭" + NOR,({"star whip","whip"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
          	set("value",100);
                set("material","iron");
                set("rigidity",50);
                set("long",
        "一條隨處可見的鞭子，不過鞭身上，多了些刺人的荊棘。\n");
        }
        init_whip(50);
        setup();
}
