inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "北鎮道");
	set( "build", 96 );
        set ("long", @LONG
雲風鎮的北邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是于風的住家，南邊是翠柳的住家，東邊是東鎮
道。西邊是接著北邊道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town05",
        "south"  : __DIR__"town17",
        "east"   : __DIR__"town12",
        "west"   : __DIR__"town10",
]));
        setup();
}
