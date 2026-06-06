#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC + "麗玉蝶蘭晶珠" + NOR, ({ "pball" }));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","開天三靈器中麗玉蝶蘭所化之晶珠,似乎具有神奇之功\效。\n");
        set("no_drop", 1);
        set("no_auc", 1);
        set("value", 0);
        }
}    
