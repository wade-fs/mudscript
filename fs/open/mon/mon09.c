inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "古亭");
        set ("long", @LONG
這是一座六角型的亭子，紅色的亭柱，橙色的屋頂，亭中還擺放
了一張石桌，配上六張小圓椅，讓長途勞累的旅人們可以在此好好的
休息。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "east"  : __DIR__"mon07",
]));
        setup();
}

