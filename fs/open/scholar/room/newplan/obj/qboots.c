//by sueplan 解謎boots

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG + "青色小鞋" + NOR, ({"small boots","boots","small"}));
        set("unit","隻");
        set("long", "這是黃石公掉的鞋子。\n");
        set("value", 10000);
        set("no_sell",1);
        setup();
}

