// written by AceLan..../u/a/acelan/obj/turtle_blood 火龜血晶........97.11.11
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("火龜血晶", ({"turtle blood", "blood"}));
        set("unit", "塊");
        set("long", "這是由萬年火龜的鮮血凝結而成的火龜血晶。\n");
        set("value", 100000);
        setup();
}

