#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"淺藍色的槌子"NOR, ({"nolayer_hammer"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("ob_id", "nolayer_hammer");
                set("long", "淺藍色的槌子，上面有著你從未看過的圖騰。\n");
                set("unit", "隻");
                set("base_value", 1);
                set("base_unit", "隻");
                set("base_weight", 1);
                set("no_sell",1);
                set("no_sac",1);
        }
        setup();
}

