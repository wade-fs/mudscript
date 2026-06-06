// Room: /open/dancer/room/r7-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","村莊");
  set ("long", @LONG
這裡是村莊的鬧區，由於鏡月島的居民不多，因此這裡雖然號稱
是鬧區但是實際上人口並不多，比起蜀中、平南等大城要差多了。向
東可離開村莊。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/dancer/room/r7-2.c",
  "east" : "/open/dancer/room/r7-4.c",
  "south" : "/open/dancer/room/r8-3.c",
  "north" : "/open/dancer/room/r6-3.c",
]));

  set("light_up", 1);

  setup();
}
