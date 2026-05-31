#include <ansi.h>
inherit __DIR__"mixeq_stone.c";

void create()
{
        set_name("生命寶石", ({"life_stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("stone_id", "life_stone");
                set("long", "深黑色的寶石，握著它可以清楚的感覺到一股股的熱流從寶石中傳出。\n");
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

