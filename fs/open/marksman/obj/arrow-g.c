#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
  set_name(HIR"鎮魂箭"NOR,({"god arrow","arrow"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","袋");
                set("base_unit","支");
set("material","steel");
set("value",0);

        }
  init_arrow(99);
  set_amount(999999);
        setup();
}
