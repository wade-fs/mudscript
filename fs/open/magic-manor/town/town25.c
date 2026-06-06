inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "西鎮道");
	set( "build", 24 );
        set ("long", @LONG
雲風鎮的西邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是西鎮道，南邊接著販肉攤，東邊是南鎮道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town19",
        "south"  : __DIR__"town31",
        "east"   : __DIR__"town26",

]));
        setup();
}
