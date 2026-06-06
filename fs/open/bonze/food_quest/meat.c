// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BYEL"絞肉"NOR, ({ "meat" }) );
        set("unit", "包");
        set("long", "這是由上等肉類所製成的新鮮肉餡，沉甸甸很有份量。\n");
        set("control",1);
        set("value",10000);
        set_weight(4000);
        setup();
}
