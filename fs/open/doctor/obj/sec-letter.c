#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW + "跛腳老頭的第二封信" + NOR, ({"oldman letter2","letter2"}));
    set("long","第二封跛腳老頭給華陀的信...\n");
    set_weight(10);
    set("unit","封");
    setup();
}
