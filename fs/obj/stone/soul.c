#include <ansi.h>
inherit __DIR__"mixeq_stone.c";

void create()
{
        set_name("靈魂寶石", ({"soul_stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("stone_id", "soul_stone");
                set("long", "粉紅色的寶石，閃閃發亮。\n");
                set("unit", "粒");
                set("base_value", 1);
                set("base_unit", "粒");
                set("base_weight", 1);
                set("no_sell",1);
                set("no_sac",1);
        }
        set_amount(1);
        setup();
}

