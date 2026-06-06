#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIR"火鳳羽"NOR, ({"phoenix feather","feather"}));
    set("long","一隻瀧山鎮派聖獸－赤羽火鳳的尾羽，為宇內五禽之一！\n");
    set_weight(10);
    set("vaule",50000);
    set("unit","隻");
    setup();
}

