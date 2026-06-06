#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("碧玉釵",({"girl-topknot","topknot"}) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","gem");
        set("unit","件");
        set("value", 10000);
        set("armor_type","head");
        set("armor_prop/armor", 4);
        set("long","
西域翠玉製成，是女性的裝飾品同時也是防護用具。\n");
        }
         setup();
}





