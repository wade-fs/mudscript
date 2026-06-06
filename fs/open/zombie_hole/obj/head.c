// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"殭屍王的頭"NOR, ({ "zombie king head","head" }) );
        set("unit", "顆");
        set("long", "這是殭屍王身上的頭。\n");
        set("no_save",1);
        set("control",1);
        set("value",10);
	setup();
}
