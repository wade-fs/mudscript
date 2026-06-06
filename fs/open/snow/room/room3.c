#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set ("short", "雪蒼山山口");
	set( "build", 98 );
  set ("long", @LONG
這裡就是武林一大門派「雪蒼派」的入口，，往上走即是通往雪
蒼派的道路，途中有八蒼派的道路，途中有迷宮陣，傳說只有有緣之
人方可到達雪蒼蒼派 .
LONG);

  set("valid_startroom", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 4 */
  "eastup" : "/open/mon/mon04.c",
  "up" : __DIR__"room4",
  "west" : __DIR__"water2",
  "down" : "/open/main/room/M21",
]));

  setup();
}
