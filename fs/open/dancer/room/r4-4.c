// Room: /open/dancer/room/r4-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在樹林之中，所見之處幾乎都是樹木，但是並非十分茂盛
，四周事物仍清悉可見。在你的西邊是條小路，而東邊則是山丘。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/dancer/room/r5-4.c",
  "north" : "/open/dancer/room/r3-4.c",
  "west" : "/open/dancer/room/r4-3.c",
]));

  set("light_up", 1);

  setup();
}
