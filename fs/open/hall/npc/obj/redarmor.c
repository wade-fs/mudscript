#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("碧雪魔甲", ({ "snow armor", "armor" }) );
        set_weight(5000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "此甲相傳是從千年寒冰精煉而成，有著相當的防禦力。");

                set("material", "iron");
                set("value", 2000);
                set("armor_prop/armor", 10);
        }
        setup();
}
