#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("玉鐕",({"topknot"}) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","gem");
        set("unit","件");
        set("value", 100);
        set("armor_type","head");
        set("armor_prop/armor", 1);
        set("long","
        和闐玉一體成形所製成的玉鐕，是玉女派掌門所用的裝飾品。\n");
        }
         setup();
}





