inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "東來橋");
        set ("long", @LONG
位處在雲風鎮的東邊重要道路上的小橋，若要進入此鎮，此橋是
非經過不可的，這座橋是用石頭的材質鋪成，歷經幾千幾萬個風風雨
雨的日子仍然是如此堅固無比。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"      : __DIR__"town18",
        "south"      : __DIR__"town30",
        "east"       : __DIR__"town39",
]));
        setup();
}
