inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "醉雲居");
	set( "build", 103 );
        set ("long", @LONG
簡單的一間居所，居所名稱高雅獨特，裏面更住了一位神秘的人
物，對於他的來歷，鎮上的人都不清楚，只知道他喜愛收藏寶物，而
這樣一間簡單的房子，卻不知其所收藏的寶物都藏那去了。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town28",
	]));

	set("objects", ([ /* sizeof() == 1 */
	"/open/sky/npc/seller" : 1,
	]));

        setup();
}
