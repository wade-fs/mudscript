#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIG + "蛇型項鍊" + NOR , ({"snake gem","gem"}));
     set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "條");
            set("value", 100000);
            set("material","steel");

            set("armor_prop/force",5);
            set("armor_prop/armor",10);
            set("long","蛇寨三寨主最喜愛的項鍊，由於煉製特殊，所以頗具防禦能力。\n");
        }
            setup();
}
