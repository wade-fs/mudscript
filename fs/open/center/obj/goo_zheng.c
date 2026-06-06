// torch
#include <weapon.h>

inherit STABBER;

void create()
{
        set_name("古箏", ({ "goo-zheng", "goo", "zheng" }) );
        set_weight(300);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "只");
          set("long", "一只烏黑的古箏, 可見其價值匪淺, 不過也只有懂音律的人才識貨。\n");
          set("value", 30);
          set("material", "檜木");
          set("wield_msg", "$N笨拙的拿起$n。\n");
          set("unwield_msg", "$N胖的一聲放下手中的$n。\n");
        }
        init_stabber(10);
        setup();
}
