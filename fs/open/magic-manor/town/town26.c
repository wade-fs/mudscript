inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "南鎮道");
	set( "build", 30 );
        set ("long", @LONG
雲風鎮的南邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是雲風商店，南邊接著水果攤，東邊是南鎮道。
西邊則是西鎮道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town20",
        "south"  : __DIR__"town32",
        "east"   : __DIR__"town27",
        "west"   : __DIR__"town25",

]));
        setup();
}
