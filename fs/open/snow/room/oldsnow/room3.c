#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set ("short", "雪蒼山山口");
  set ("long", @LONG
這裡就是武林一大門派「雪蒼派」的入口，，往上走即是通往雪
蒼派的道路，途中有八蒼派的道路，途中有迷宮陣，傳說只有有緣之
人方可到達雪蒼蒼派 .
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/snow/room/oldsnow/water2",
  "up" : "/open/snow/room/oldsnow/room4",
]));

  set("light_up", 1);
  set("objects",([ "/open/snow/npc/person" : 1 ]));

  setup();
}
