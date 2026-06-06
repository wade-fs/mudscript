#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","平南城驛站");
	set( "build", 114 );
    set("long",@LONG
這裡是平南城的驛站, 因為附近有段王府, 瀧山派兩大門派在此,
所以此地武林人士眾多
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/ping/room/road5",
]));

    setup();
}
