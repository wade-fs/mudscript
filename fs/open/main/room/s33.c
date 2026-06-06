// Room: /open/main/room/s33.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 12 );
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/marksman/room/room2-1",
  "north" : __DIR__"L23",
  "east" : __DIR__"s34",
]));
  set("outdoors", "/open/main");
}
