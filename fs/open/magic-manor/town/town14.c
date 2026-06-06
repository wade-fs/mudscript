inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "旅店");
        set ("long", @LONG
雲風鎮中的一間旅店，提供休息和住宿的地方，讓遠道而來的旅
客們有一個溫暖的休息地方。整間旅店看來不過數十坪大，但是卻可
以提供十餘個床位。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town08",
]));
        set("light_up", 1);
        setup();
}
