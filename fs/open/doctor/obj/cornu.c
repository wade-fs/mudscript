#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(RED"獨角虎的角"NOR, ({"cornu"}));
    set("long","一隻獨角虎的角...\n");
    set_weight(25);
    set("unit","隻");
    setup();
}
