#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("青龍鱗甲", ({ "dragon armor", "armor" }) );
        set_weight(5000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "此龍甲相傳是從千年青龍妖身上拔鱗製成，穿上此甲便可刀槍不入，無\n"
                "所披靡。\n");

                set("material", "gold");
                set("value", 2000);
                set("armor_prop/armor", 15);
        }
        setup();
}
