inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "北鎮道");
	set( "build", 24 );
        set ("long", @LONG
雲風鎮的北邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是道具店，南邊是一個廣場，東邊接著北鎮道。
西邊是北邊道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town03",
        "south"  : __DIR__"town15",
        "east"   : __DIR__"town10",
        "west"   : __DIR__"town08",
]));
        setup();
}
