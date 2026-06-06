// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BMAG"烈酒"NOR, ({ "liqueur" }) );
        set("unit", "瓶");
        set("long", "這是紅鼻子老人釀造多年的陳年烈酒，醉人的酒香應可使美味佳餚增色不少。\n");
        set("control",1);
        set("value",10000);
        set_weight(1000);
        setup();
}
