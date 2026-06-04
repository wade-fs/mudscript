inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIC + "水之石" + NOR,({"water-stone"}));
    set("long","一顆奇怪的石頭。\n");
    set("unit","顆");
    set("value",0);
    setup();
}
