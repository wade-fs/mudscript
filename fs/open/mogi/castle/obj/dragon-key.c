
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIC"青龍之鑰"NOR, ({ "dragonkey","key" }) );
        set("long", "一把神秘的鑰匙。\n");
        set("unit", "把");
        set_weight(800);
        set("no_drop",1);
        set("value", 0);
}
