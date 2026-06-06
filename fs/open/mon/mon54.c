inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "山谷小徑");
        set ("long", @LONG
小小的一條路，是通往三峰當中的天池所必經的小徑，慢慢的往
前走去，你只覺得四周草木的生機旺盛了起來，似乎是受到了天池的
影響所致。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "southdown"   : __DIR__"mon55",
        "northup"     : __DIR__"mon38",
]));
        setup();
}
