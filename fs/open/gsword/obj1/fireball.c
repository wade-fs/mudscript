#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"火法珠"NOR, ({ "fireball" }));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一顆火法珠。\n");
        set("no_drop", 1);
        set("no_auc", 1);
        set("value", 0);
        }
}
