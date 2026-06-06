// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"黑狗血"NOR, ({ "blood" }) );
        set("unit", "癱");
        set("long", "這是黑狗身上留下來的血。\n");
        set("control",1);
        set("value",10);
	setup();
}
