// Room: /open/dancer/room/r6-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","草原");
  set ("long", @LONG
你身處一處草原之中，你的北方是一大片森林，南方則是一條蜿
蜒的小路向南而去。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/dancer/room/r7-4.c",
  "north" : "/open/dancer/room/r5-4.c",
]));

  set("light_up", 1);

  setup();
}
