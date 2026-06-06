// Room: /open/dancer/room/r3-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在樹林之中，所見之處幾乎都是樹木，但是並非十分茂盛
，四周事物仍清悉可見。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/dancer/room/r4-2.c",
  "north" : "/open/dancer/room/r2-2.c",
  "west" : "/open/dancer/room/r3-1.c",
  "east" : "/open/dancer/room/r3-3.c",
]));

  set("light_up", 1);

  setup();
}
