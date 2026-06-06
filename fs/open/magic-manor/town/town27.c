inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "南鎮道");
        set ("long", @LONG
雲風鎮的南邊道路，道路的兩旁邊種滿了各式花花草草，讓你走
在此路上覺得格外愉快，鎮上的居民也是很親切，看見了你還不時的
向你打招呼，往北邊是廣場，南邊接著蔬菜攤，東邊是南鎮道。西邊
則是南鎮道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town21",
        "south"  : __DIR__"town33",
        "east"   : __DIR__"town28",
        "west"   : __DIR__"town26",

]));
        setup();
}
