// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB + "墨斗線" + NOR, ({ "line" }) );
        set("unit", "條");
        set("long", "這是工匠用來畫線的墨斗線。\n");
        set("control",1);
        set("value",10000);
	setup();
}
