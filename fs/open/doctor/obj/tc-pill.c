#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY"藥丸"NOR, ({"tiger_cornu-pill"}));
    set("long","一顆由獨角虎的角與百年榕樹根合製而成的藥丸...\n");
    set_weight(5);
    set("unit","顆");
    setup();
}
