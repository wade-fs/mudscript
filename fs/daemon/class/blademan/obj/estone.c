inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(YEL + "土之石" + NOR,({"earth-stone"}));
    set("long","一顆奇怪的石頭。\n");
    set("unit","顆");
    set("value",0);
    setup();
}
