inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIW"方平的人頭" NOR,({"pin-head"}));
    set("long","人頭啦。\n");
    set("unit","粒");
    set("value",10000);
    set("no_drop",1);
    set("no_auc",1);
    setup();
}


