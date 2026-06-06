inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "西往橋");
        set ("long", @LONG
位處在雲風鎮的西邊重要道路上的小橋，若要進入此鎮，此橋是
非經過不可的，這座橋是用石頭的材質鋪成，歷經幾千幾萬個風風雨
雨的日子仍然是如此堅固。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town07",
        "south"  : __DIR__"town19",
        "west"   : __DIR__"town38",
]));
        setup();
}
