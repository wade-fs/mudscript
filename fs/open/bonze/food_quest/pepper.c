// torch
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BRED + "家傳辣椒醬" + NOR, ({ "pepper" }) );
        set("unit", "罐");
        set("long", "這是由你母親娘家家傳秘方所製成的超辣辣椒醬。\n");
        set("control",1);
        set("value",10000);
        set_weight(2000);
        setup();
}
