#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR + "連陽劍靈珠" + NOR, ({ "sball" }));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","開天三靈器中連陽劍劍靈之靈氣珠,似乎具有神奇之功\效。\n");
        set("no_drop", 1);
        set("no_auc", 1);
        set("value", 0);
        }
}
