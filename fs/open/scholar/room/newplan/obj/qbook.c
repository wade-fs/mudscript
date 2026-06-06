//by sueplan 六韜奇略

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"六韜奇略"NOR, ({"sixgod-plan book","book","sixgod-plan"}));
        set("unit", "本");
        set("long", "這是黃石公收集天下名計的一本書。\n");
        set("value", 10000);
        setup();
}

