// Room: /open/dancer/room/r1-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set( "build", 24 );
  set ("long", @LONG
你身處在密林之中，放眼望去盡是一片樹海，茂密的樹木幾乎將
陽光完全阻擋，只有些許光線由樹縫中射入。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/dancer/room/r2-2.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/wind_girl.c" : 1,
]));

  set("light_up", 0);

  setup();
}
