inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIW "心之石" NOR,({"heart-stone"}));
    set("long","一顆奇怪的石頭。\n");
    set("unit","顆");
    set("value",0);
    setup();
}
