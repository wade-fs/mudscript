inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("一封信",({"letter"}));
    set("long","就是一封信，看什麼看。\n");
    set("unit","封");
    set("value",10000);
    setup();
}

