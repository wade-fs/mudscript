// Room: /open/dancer/room/r5-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在樹林之中，所見之處幾乎都是樹木，但是並非十分茂盛
，四周事物仍清悉可見。南邊不遠處有一片綠地。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/dancer/room/r5-5.c",
  "north" : "/open/dancer/room/r4-4.c",
  "east" : "/open/dancer/room/r6-4.c",
]));

  set("light_up", 1);

  setup();
}
