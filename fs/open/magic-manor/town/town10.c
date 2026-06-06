inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "北鎮道");
	set( "build", 84 );
        set ("long", @LONG
雲風鎮的北邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是一間普通的民宅，南邊是一個廣場，東邊仍然
接著北鎮道。西邊也是接著北邊道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town04",
        "south"  : __DIR__"town16",
        "east"   : __DIR__"town11",
        "west"   : __DIR__"town09",
]));
        setup();
}
