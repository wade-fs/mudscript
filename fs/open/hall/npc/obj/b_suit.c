#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("閃綠勁裝", ({ "green suit", "suit" }) );
        set_weight(2000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("long", "此甲閃著綠芒，有著十分優良的防禦力。");

                set("material", "cloth");
                set("value", 2000);
                set("armor_prop/armor", 15);
        }
        setup();
}
