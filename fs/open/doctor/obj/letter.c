#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"跛腳老頭的信"NOR, ({"oldman letter","letter"}));
    set("long","一封跛腳老頭給華陀的信...\n");
    set_weight(10);
    set("unit","封");
    setup();
}
