#include <ansi.h>
inherit __DIR__"mixeq_stone.c";

void create()
{
        set_name("幸運寶石", ({"lucky_stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("stone_id", "lucky_stone");
                set("long", "罕見的金黃色寶石，能得到它真是天大的幸運。\n");
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

