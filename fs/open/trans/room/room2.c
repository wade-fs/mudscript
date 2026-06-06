#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","蜀中城驛站");
	set( "build", 218 );
    set("long",@LONG
這裡是蜀中城的驛站, 因為這裡是通往崑侖山及仙劍派的必經之路, 
所以你可以看到路上一堆道士跟劍客
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/su2",
]));

    setup();
}
