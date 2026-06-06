// Room: /open/dancer/room/r6-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","村莊");
  set ("long", @LONG
這裡是村莊的北部，你可以向北展開你的旅程，也可以向南回到
村莊內人煙較多之處。由於這座島上居民不多，因此這裡的人口並不
多。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/r5-3.c",
  "south" : "/open/dancer/room/r7-3.c",
]));

  set("light_up", 1);

  setup();
}
