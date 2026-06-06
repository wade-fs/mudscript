// Room: /open/dancer/room/r6-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","村莊");
  set ("long", @LONG
這裡是村莊的南部，向北你可以展開你的旅程，也可以向北回到
村莊內人煙較多之處。由於這座島上居民不多，因此這裡的人口並不
多，西邊是一棟民房。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/dancer/room/r7-3.c",
  "south" : "/open/dancer/room/r9-3.c",
  "west" : "/open/dancer/room/r8-2.c",
]));

  set("light_up", 1);

  setup();
}
