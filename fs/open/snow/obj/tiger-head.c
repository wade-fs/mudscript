#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("獨角虎的頭", ({ "tiger-head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long","這是兇殘的獨角虎的頭.\n");
                set("value", 0);
        }
}
