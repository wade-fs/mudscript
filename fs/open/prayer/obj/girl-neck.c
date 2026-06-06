#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("聖女頸飾",({"girl-lace","lace"}) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","gem");
        set("unit","件");
        set("value", 10000);
        set("armor_type","neck");
        set("armor_prop/armor", 4);
        set("long","
西域翠玉製成，是女性的頸部裝飾品同時也是防護頸部的防具。\n");
        }
         setup();
}





