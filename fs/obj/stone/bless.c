#include <ansi.h>
inherit __DIR__"mixeq_stone.c";

void create()
{
        set_name("祝福寶石", ({"bless_stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("stone_id", "bless_stone");
                set("long", "水藍色的寶石，看來似乎擁有無窮的魔力。\n");
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

