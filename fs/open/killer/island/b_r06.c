#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
西邊的門檻上掛著一個『刀叉』銅制模型版，你可以清楚的瞭解到西邊是這艘
船的餐廳，如果你肚子餓了的話，或許可以去那邊找一些東西出來吃吧，但是要小
心吃到有毒的物品。
LONG);
set("exits",([
"north":__DIR__"b_r05",
"south":__DIR__"b_r07",
"west":__DIR__"room03",
]));
setup();
}
