inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG"水羚袋"NOR, ({ "water bag","bag" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "水羚特別製作的袋子，可以拿來裝袋物品。\n");
                set("value", 100000);
        }
        setup();
}

int is_container() { return 1; }
