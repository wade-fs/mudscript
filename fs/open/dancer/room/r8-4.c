// Room: /open/dancer/room/r8-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在密林之中，放眼望去盡是一片樹海，茂密的樹木幾乎將
陽光完全阻擋，只有些許光線由樹縫中射入。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r8-5.c",
]));

  set("light_up", 0);

  setup();
}
