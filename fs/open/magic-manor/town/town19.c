inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "西鎮道");
	set( "build", 12 );
        set ("long", @LONG
雲風鎮的西邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是西往橋，南邊接著西鎮道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town13",
        "south"  : __DIR__"town25",

]));
        setup();
}
