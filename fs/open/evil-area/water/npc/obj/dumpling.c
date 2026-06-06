inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW + "水晶包" + NOR, ({ "crystal dumpling","dumpling" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "
一個包含數十種材料的精緻包子，十分的昂貴，不過卻份量十足又美味，
是邪靈界琰揚湖的特產之一。\n");
                set("unit", "籠");
                set("value", 10000);
                set("食物", ([
                        "剩" : 10,
                        "供應": 100,
                ]) );
        }
        setup();
}
