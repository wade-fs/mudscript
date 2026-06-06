inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "道具店");
	set( "build", 12 );
        set ("long", @LONG
各式各樣的道具陳列在店中，在店中還有陳列許多新奇的東西，
都是平常鮮少見的到的，讓你的眼界大開。此間店也是雲風鎮中道具
雜貨賣的最齊全的。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town09",
]));
        set("light_up", 1);
        setup();
}
