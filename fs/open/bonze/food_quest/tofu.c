// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BWHT+HIW + "豆腐" + NOR, ({ "tofu" }) );
        set("unit", "盤");
        set("long", "這是含有高蛋白、低脂肪的養生美食佳品。\n");
        set("control",1);
        set("value",10000);
        set_weight(1000);
        setup();
}
