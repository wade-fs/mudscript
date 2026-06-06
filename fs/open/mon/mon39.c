inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "東峰道");
	set( "build", 12 );
        set ("long", @LONG
往東邊走，一是條較為平順的道路，兩旁的風景已是雪白一片，
幾乎看不到任何生物的蹤跡，淒冷的寒風更顯得路途的悲涼與大自然
的無情。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "east"    : __DIR__"mon45",
        "west"    : __DIR__"mon38",
]));
        setup();
}
