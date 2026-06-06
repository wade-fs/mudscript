inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "東鎮道");
        set ("long", @LONG
雲風鎮的東邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是丸山鎮的鎮長住家，南邊接著東鎮道，西邊是
接著北邊道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town06",
        "south"  : __DIR__"town18",
        "west"   : __DIR__"town11",
]));
        setup();
}
