inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "北鎮道");
        set ("long", @LONG
雲風鎮的北邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是防具店，南邊是一間旅店，東邊接著北鎮道。
西邊是西邊道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town02",
        "south"  : __DIR__"town14",
        "east"   : __DIR__"town09",
        "west"   : __DIR__"town07",
]));
        setup();
}
