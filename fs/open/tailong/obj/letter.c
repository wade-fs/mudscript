#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("給慕容復的信", ({"letter" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一封段譽要給慕容復的信。\n");
                set("unit", "封");
                set("base_value", 1);
                set("base_unit", "封");
                set("base_weight", 1);
                set("no_sell",1);
                set("no_sac",1);
                set("handwriting",1);
        }
        setup();
}

