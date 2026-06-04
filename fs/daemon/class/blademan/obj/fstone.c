inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR + "火之石" + NOR,({"fire-stone"}));
    set("long","一顆奇怪的石頭。\n");
    set("unit","顆");
    set("value",0);
    setup();
}
